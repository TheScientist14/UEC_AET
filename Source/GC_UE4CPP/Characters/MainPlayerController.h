// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayerController.generated.h"

class APlayerCharacter;

UCLASS()
class GC_UE4CPP_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	AMainPlayerController();

	APlayerCharacter* PlayerCharacter;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> ProgressionBarClass;

	UPROPERTY()
	UUserWidget* HUDWidget;

	virtual void BeginPlay() override;
	
	virtual void OnPossess(APawn* aPawn) override;

};
