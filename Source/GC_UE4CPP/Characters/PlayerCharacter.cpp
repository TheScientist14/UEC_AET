// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "../PickableItem.h"
#include "../Interactable.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
	
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComp->SetupAttachment(RootComponent);
	SpringArmComp->TargetArmLength = 300.0f;
	SpringArmComp->bUsePawnControlRotation = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;

	InteractSphere = CreateDefaultSubobject<USphereComponent>(TEXT("InteractSphere"));
	InteractSphere->SetupAttachment(RootComponent);
	InteractSphere->SetSphereRadius(InteractRange);
	InteractSphere->SetCollisionProfileName(TEXT("OverlapAll"));
	InteractSphere->OnComponentBeginOverlap.AddDynamic(this, &APlayerCharacter::RegisterInteractable);
	InteractSphere->OnComponentEndOverlap.AddDynamic(this, &APlayerCharacter::UnregisterInteractable);

	InteractableInRange.Reserve(10); // pretty unlikely to have more than 10 interactable actors in range
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

APickableItem* APlayerCharacter::GetPickedUpActor()
{
	return PickedUpActor;
}

// Inputs

void APlayerCharacter::Interact() {
	if (PickedUpActor == nullptr) {
		if (InteractableInRange.Num() > 0) {
			InteractableInRange[0]->OnInteract();
			InteractableInRange.RemoveAt(0);
		}
	}
	else {
		PutDownPickedUpActor();
	}
}

void APlayerCharacter::ZoomIn(float DeltaZoom) {
	ZoomThreshold += DeltaZoom;
	if (abs(ZoomThreshold) >= ZoomThresholdLimit) {
		SpringArmComp->TargetArmLength = FMath::Clamp(ArmLengthStep * -FMath::Sign(ZoomThreshold) + SpringArmComp->TargetArmLength, MinArmLength, MaxArmLength);
		ZoomThreshold = 0;
	}
}

void APlayerCharacter::MoveForward(float DeltaX) {
	FVector forward = Camera->GetForwardVector();
	forward.Z = 0;
	AddMovementInput(forward.GetSafeNormal(), DeltaX);
}

void APlayerCharacter::MoveRight(float DeltaY) {
	AddMovementInput(Camera->GetRightVector(), DeltaY);
}

void APlayerCharacter::RegisterInteractable(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	IInteractable* InteractableActor = Cast<IInteractable>(OtherActor);
	if (InteractableActor) {
		InteractableInRange.Add(InteractableActor);
	}
}

void APlayerCharacter::UnregisterInteractable(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
	IInteractable* InteractableActor = Cast<IInteractable>(OtherActor);
	if (InteractableActor) {
		InteractableInRange.Remove(InteractableActor);
	}
}

bool APlayerCharacter::PickUpActor(APickableItem* ActorToPickUp) {
	if (ActorToPickUp == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("Can’t pick up null"))
		return false;
	}
	if (!PickedUpActor) {
		PickedUpActor = ActorToPickUp;
		PickedUpActor->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);
		GEngine->AddOnScreenDebugMessage(1, 5, FColor::Red, "Attached");
		return true;
	}
	else {
		return false;
	}
}

void APlayerCharacter::PutDownPickedUpActor() {
	GEngine->AddOnScreenDebugMessage(1, 5, FColor::Red, "Dettached");
	PickedUpActor->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	PickedUpActor = nullptr;
}