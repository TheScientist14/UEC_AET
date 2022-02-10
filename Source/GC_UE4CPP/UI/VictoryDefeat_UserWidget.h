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
	UTextBlock* TextScore;

	UPROPERTY(meta = (BindWidget))
	class UHorizontalBox* ScoreContainer;

	UPROPERTY(meta = (BindWidget))
	class UButton* ButtonRestart;
	UPROPERTY(meta = (BindWidget))
	UButton* ButtonMenu;
	UPROPERTY(meta = (BindWidget))
	UButton* ButtonQuit;

	class AMainGameMode* GameMode;
	void SetUI(bool PrmIsGameFinished, bool PrmIsGameWon);

	UFUNCTION()
	void ReloadLevel();
	UFUNCTION()
	void MainMenu();
	UFUNCTION()
	void Quit();


protected:
	virtual void NativeConstruct() override;
	virtual void NativeOnInitialized() override;
};
