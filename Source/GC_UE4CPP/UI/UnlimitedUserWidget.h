// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UnlimitedUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API UUnlimitedUserWidget : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TextBlock;	

	UFUNCTION()
	void UpdateScore(int NbFood, int NbMaxFood);
	
};
