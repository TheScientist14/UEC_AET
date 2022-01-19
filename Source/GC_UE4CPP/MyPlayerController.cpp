// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerCharacter.h"

// Sets default values
AMyPlayerController::AMyPlayerController()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AMyPlayerController::BeginPlay() {
    PlayerCharacter = (APlayerCharacter*)UGameplayStatics::GetPlayerCharacter(this, 0);
    GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "Controller initilized");
}

void AMyPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    InputComponent->BindAction("Interact", IE_Pressed, PlayerCharacter, &APlayerCharacter::Interact);
    InputComponent->BindAxis("MoveForward", this, &AMyPlayerController::MoveForward);
    InputComponent->BindAxis("MoveRight", this, &AMyPlayerController::MoveRight);
    InputComponent->BindAxis("Turn", PlayerCharacter, &APawn::AddControllerYawInput);
    InputComponent->BindAxis("LookUp", PlayerCharacter, &APawn::AddControllerPitchInput);
    InputComponent->BindAxis("Zoom", PlayerCharacter, &APlayerCharacter::ZoomIn);
    GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "Inputs set up");
}

void AMyPlayerController::MoveForward(float DeltaX) {
    PlayerCharacter->AddMovementInput(FVector::ForwardVector, DeltaX);
}

void AMyPlayerController::MoveRight(float DeltaY) {
    PlayerCharacter->AddMovementInput(FVector::RightVector, DeltaY);
}