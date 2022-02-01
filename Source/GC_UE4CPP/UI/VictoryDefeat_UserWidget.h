// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "VictoryDefeat_UserWidget.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API UVictoryDefeat_UserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Text;

	UPROPERTY(meta = (BindWidget))
	class UButton* ButtonRestart;

	void SetUI(bool PrmIsGameFinished, bool PrmIsGameWon);

	UFUNCTION()
	void ReloadLevel();

	FDelegateHandle temp;

protected:
	virtual void NativeConstruct() override;
	virtual void NativeOnInitialized() override;
};
