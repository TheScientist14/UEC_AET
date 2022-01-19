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
    PlayerCharacter = (APlayerCharacter*)UGameplayStatics::GetPlayerCharacter(this, 0);
    
}

void AMyPlayerController::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);

    FVector Tmp = FVector::FVector(ForwardDelta, RightDelta, 0);
    if (Tmp.SizeSquared() >= 1) {
        PlayerCharacter->Move(Tmp.GetSafeNormal());
    }
    else {
        PlayerCharacter->Move(Tmp);
    }
}

void AMyPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    InputComponent->BindAction("Interact", IE_Pressed, this, &AMyPlayerController::Interact);
    InputComponent->BindAxis("MoveForward", this, &AMyPlayerController::MoveForward);
    InputComponent->BindAxis("MoveRight", this, &AMyPlayerController::MoveRight);
    InputComponent->BindAxis("Turn", PlayerCharacter, &APawn::AddControllerYawInput);
    InputComponent->BindAxis("LookUp", PlayerCharacter, &APawn::AddControllerPitchInput);
}

void AMyPlayerController::Interact() {
    PlayerCharacter->Interact();
}

void AMyPlayerController::MoveForward(float DeltaX) {
    ForwardDelta = DeltaX;
}

void AMyPlayerController::MoveRight(float DeltaY) {
    RightDelta = DeltaY;
}