// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PauseMenuUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API UPauseMenuUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:

	UPROPERTY(meta = (BindWidget))
	class UButton* ButtonMenu;
	
	UPROPERTY(meta = (BindWidget))
	UButton* ButtonResume;

	UPROPERTY(meta = (BindWidget))
	UButton* ButtonRestart;

	UPROPERTY(meta = (BindWidget))
	UButton* ButtonQuit;
	
	virtual void NativeConstruct() override;

	UFUNCTION()
	void MainMenu();
	UFUNCTION()
	void Resume();
	UFUNCTION()
	void ReloadLevel();
	UFUNCTION()
	void Quit();
};
