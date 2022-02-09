// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPlayerController.h"

#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"

#include "PlayerCharacter.h"

// Sets default values
AMainPlayerController::AMainPlayerController()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AMainPlayerController::BeginPlay() {
    Super::BeginPlay();

	HUDWidget = CreateWidget(this, ProgressionBarClass);
	HUDWidget->AddToViewport();
	HUDWidget->SetVisibility(ESlateVisibility::Visible);
}

void AMainPlayerController::OnPossess(APawn* aPawn) {
	Super::OnPossess(aPawn);
	PlayerCharacter = Cast<APlayerCharacter>(aPawn);

	InputComponent->BindAction("Interact", IE_Pressed, PlayerCharacter, &APlayerCharacter::Interact);
	InputComponent->BindAction("Pause", IE_Pressed, PlayerCharacter, &APlayerCharacter::Pause);
	InputComponent->BindAxis("MoveForward", PlayerCharacter, &APlayerCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", PlayerCharacter, &APlayerCharacter::MoveRight);
	InputComponent->BindAxis("Turn", PlayerCharacter, &APawn::AddControllerYawInput);
	InputComponent->BindAxis("LookUp", PlayerCharacter, &APawn::AddControllerPitchInput);
	InputComponent->BindAxis("Zoom", PlayerCharacter, &APlayerCharacter::ZoomIn);
}
