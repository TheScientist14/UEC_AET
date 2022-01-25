// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerCharacter.h"

// Sets default values
AMyPlayerController::AMyPlayerController()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AMyPlayerController::BeginPlay() {
    Super::BeginPlay();
}

void AMyPlayerController::OnPossess(APawn* aPawn) {
	Super::OnPossess(aPawn);
	PlayerCharacter = Cast<APlayerCharacter>(aPawn);

	InputComponent->BindAction("Interact", IE_Pressed, PlayerCharacter, &APlayerCharacter::Interact);
	InputComponent->BindAxis("MoveForward", PlayerCharacter, &APlayerCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", PlayerCharacter, &APlayerCharacter::MoveRight);
	InputComponent->BindAxis("Turn", PlayerCharacter, &APawn::AddControllerYawInput);
	InputComponent->BindAxis("LookUp", PlayerCharacter, &APawn::AddControllerPitchInput);
	InputComponent->BindAxis("Zoom", PlayerCharacter, &APlayerCharacter::ZoomIn);
}
