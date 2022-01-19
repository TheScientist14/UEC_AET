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
	//Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	//SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));

	//SpringArmComp->SetupAttachment(GetMesh());
	//Camera->AttachToComponent(SpringArmComp, FAttachmentTransformRules::KeepRelativeTransform);
	//SpringArmComp->bUsePawnControlRotation = true;
	//SpringArmComp->bEnableCameraLag = true;
	//SpringArmComp->TargetArmLength = 300.0f;

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	EnableInput(PlayerController);
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorWorldOffset(MovementDir * DeltaTime);
}

void APlayerCharacter::Move(FVector Dir) {
	if (!Dir.IsZero()) {
		SetActorRotation(FQuat::MakeFromEuler(Dir));
		MovementDir = GetActorForwardVector()* Dir.Size() * Speed;
	}
}

void APlayerCharacter::Interact() {
	// find food, set it up as child
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}



