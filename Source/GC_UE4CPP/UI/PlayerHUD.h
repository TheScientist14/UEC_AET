// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerHUD.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API UPlayerHUD : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(meta = (BindWidget))
	class UProgressBar* ProgressBarWidget;

	UFUNCTION()
	void UpdateProgressBar(int UpdatedStashedFoodCount, int MaxStashedFoodCount);

protected:

	virtual void NativeOnInitialized() override;
};
