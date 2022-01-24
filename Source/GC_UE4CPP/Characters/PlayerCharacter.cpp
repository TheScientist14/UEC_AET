// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GC_UE4CPP/PlayerCharacterAnimInstance.h"

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

AActor* APlayerCharacter::GetPickedUpActor()
{
	return PickedUpActor;
}

// Inputs

void APlayerCharacter::Interact() {
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "Interacted");

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

// Called to bind functionality to input
//void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
//	Super::SetupPlayerInputComponent(PlayerInputComponent);
//
//	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &APlayerCharacter::Interact);
//	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
//	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);
//	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
//	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
//	PlayerInputComponent->BindAxis("Zoom", this, &APlayerCharacter::ZoomIn);
//	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "Inputs set up");
//}