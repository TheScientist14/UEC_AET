// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API UMainMenuUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget))
	class UButton* ButtonPlay;

	UPROPERTY(meta = (BindWidget))
	UButton* ButtonQuit;

protected:
	virtual void NativeConstruct() override;

	UFUNCTION()
	void Play();
	UFUNCTION()
	void Quit();

private:
	UPROPERTY()
	APlayerController* Player;
};
