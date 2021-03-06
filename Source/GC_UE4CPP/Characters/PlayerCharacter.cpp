// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

#include "MainPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "PickUpAbilityComponent.h"
#include "SitDownAbilityComponent.h"
#include "Blueprint/UserWidget.h"
#include "GC_UE4CPP/Interfaces/Interactable.h"
#include "GC_UE4CPP/Game/MainGameMode.h"
#include "GC_UE4CPP/MapItems/PickableItem.h"

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

	PickUpAbilityComponent = CreateDefaultSubobject<UPickUpAbilityComponent>(TEXT("PickUpBehaviour"));
	SitDownAbilityComponent = CreateDefaultSubobject<USitDownAbilityComponent>(TEXT("SitDownBehaviour"));
	
}

void APlayerCharacter::BeginPlay() {
	Super::BeginPlay();

	AMainGameMode* GameMode = Cast<AMainGameMode>(UGameplayStatics::GetGameMode(this));
	GameMode->OnGameFinished.AddUObject(this, &APlayerCharacter::OnGameEnded);

	PlayerController = Cast<APlayerController>(GetController());
}

//
// Inputs
//

void APlayerCharacter::ZoomIn(float DeltaZoom)
{
	ZoomThreshold += DeltaZoom;
	if (abs(ZoomThreshold) >= ZoomThresholdLimit)
	{
		SpringArmComp->TargetArmLength = FMath::Clamp(
			ArmLengthStep * -FMath::Sign(ZoomThreshold) + SpringArmComp->TargetArmLength, MinArmLength, MaxArmLength);
		ZoomThreshold = 0;
	}
}

void APlayerCharacter::MoveForward(float DeltaX)
{
	FVector forward = Camera->GetForwardVector();
	forward.Z = 0;
	AddMovementInput(forward.GetSafeNormal(), DeltaX);
}

void APlayerCharacter::MoveRight(float DeltaY)
{
	AddMovementInput(Camera->GetRightVector(), DeltaY);
}

// try to interact with the first interactable found
// with a sphere overlap
// interact with picked up item if nothing to interact with
void APlayerCharacter::Interact()
{
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypeFilter;
	ObjectTypeFilter.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Visibility));
	TArray<AActor*> IgnoreActors;
	IgnoreActors.Init(this, 1);
	TArray<AActor*> OverlappedActors;
	UKismetSystemLibrary::SphereOverlapActors(this, GetActorLocation(), InteractRange, ObjectTypeFilter, nullptr, IgnoreActors, OverlappedActors);
	bool HasInteracted = false;
	int i = 0;
	while(i < OverlappedActors.Num() && !HasInteracted) {
		IInteractable* Interactable = Cast<IInteractable>(OverlappedActors[i]);
		if (Interactable) {
			Interactable->OnInteract(this);
			HasInteracted = true;
		}
		else {
			i++;
		}
	}
	if (!HasInteracted && PickUpAbilityComponent->GetPickedUpActor()) {
		PickUpAbilityComponent->GetPickedUpActor()->OnInteract(this);
	}
}

void APlayerCharacter::Pause()
{
	if(PauseMenu)
	{
		widget = CreateWidget(PlayerController, PauseMenu);
		widget->AddToViewport();
		widget->SetVisibility(ESlateVisibility::Visible);
	}
	PlayerController->bShowMouseCursor = true;
	PlayerController->SetInputMode(FInputModeUIOnly());
	
	
}

// Game ended event handler
void APlayerCharacter::OnGameEnded(bool HasGameEnded, bool HasWon) {
	GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_None);
	GetCharacterMovement()->Velocity = FVector::ZeroVector;
}