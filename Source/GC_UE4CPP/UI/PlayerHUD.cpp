// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHUD.h"
#include "Components/ProgressBar.h"
#include "Kismet/GameplayStatics.h"
#include "GC_UE4CPP/Game/MainGameMode.h"

void UPlayerHUD::NativeOnInitialized() {

	// Add listener for OnStashedFoodUpdate event
	AMainGameMode* GameMode = Cast<AMainGameMode>(UGameplayStatics::GetGameMode(this));
	if(GameMode)
	{
		GameMode->OnStashedFoodUpdate.AddUObject(this, &UPlayerHUD::UpdateProgressBar);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to cast GetGameMode() to AMainGameMode"))
	}
}

void UPlayerHUD::UpdateProgressBar(int UpdatedStashedFoodCount, int MaxStashedFoodCount) {

	// Sets the appropriate percentage in the UI
	ProgressBarWidget->SetPercent(FMath::Clamp<float>((float)UpdatedStashedFoodCount / (float)MaxStashedFoodCount, 0, 1));
}