// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationYaw = false;
	AutoPossessAI = EAutoPossessAI::Disabled;
	AutoPossessPlayer = EAutoReceiveInput::Player0;
	AutoReceiveInput = EAutoReceiveInput::Player0;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));

	SpringArmComp->SetupAttachment(GetMesh());
	Camera->AttachToComponent(SpringArmComp, FAttachmentTransformRules::KeepRelativeTransform);
	SpringArmComp->bUsePawnControlRotation = true;
	SpringArmComp->bEnableCameraLag = true;
	SpringArmComp->TargetArmLength = 300.0f;
	SpringArmComp->bInheritPitch = false;
	SpringArmComp->bInheritRoll = false;
	SpringArmComp->bInheritYaw = false;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	EnableInput(PlayerController);
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "Character input enabled");
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	GEngine->AddOnScreenDebugMessage(-1, 0, FColor::Red, "Character input enabled");
}

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

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}