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
    GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, PlayerCharacter->GetName());
}

void AMyPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

}

