// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHUD.h"
#include "Components/ProgressBar.h"
#include "Kismet/GameplayStatics.h"
#include "GC_UE4CPP/Game/MainGameMode.h"

void UPlayerHUD::NativeOnInitialized() {
	AMainGameMode* GameMode = Cast<AMainGameMode>(UGameplayStatics::GetGameMode(this));
	GameMode->OnStashedFoodUpdate.AddUObject(this, &UPlayerHUD::UpdateProgressBar);
}

void UPlayerHUD::UpdateProgressBar(int UpdatedStashedFoodCount, int MaxStashedFoodCount) {
	ProgressBarWidget->SetPercent(FMath::Clamp<float>((float)UpdatedStashedFoodCount / (float)MaxStashedFoodCount, 0, 1));
}