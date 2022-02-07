// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MainGameState.h"
#include "GameFramework/GameModeBase.h"
#include "GC_UE4CPP/UI/VictoryDefeat_UserWidget.h"
#include "MainGameMode.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API AMainGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	ASpot* GetRandomSpot();
	int GetFoodOnLevel();
	int GetMaxFoodOnLevel();
	void AddFood();
	void RemoveFood();
	void AddStashedFood();
	void EndGameDefeat();
	void EndGameVictory();
	void EndUI();
	bool NeedsFood();

	UPROPERTY(EditAnywhere, Category="Classes")
	TSubclassOf<UVictoryDefeat_UserWidget> VD_UI;

	UPROPERTY()
	UUserWidget* Widget;
	
	DECLARE_MULTICAST_DELEGATE_TwoParams(FStashedFoodUpdateSignature, int, int)
	FStashedFoodUpdateSignature OnStashedFoodUpdate;

	DECLARE_MULTICAST_DELEGATE_TwoParams(FGameFinishedSignature, bool, bool);
	FGameFinishedSignature OnGameFinished;

	DECLARE_MULTICAST_DELEGATE(FGameModeBeginPlayFinished);
	FGameModeBeginPlayFinished GameModeBeginPlayFinished;
	
private:
	
	UPROPERTY()
	AMainGameState* MainGameState;
	
	UPROPERTY()
	APlayerController* Player;
};
