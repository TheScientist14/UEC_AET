// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
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
	class ASpot* GetRandomSpot();
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
	TSubclassOf<class UVictoryDefeat_UserWidget> VD_UI; //VictoryDefeat_UI

	UPROPERTY()
	UUserWidget* Widget;
	
	DECLARE_MULTICAST_DELEGATE_TwoParams(FStashedFoodUpdateSignature, int, int)
	FStashedFoodUpdateSignature OnStashedFoodUpdate;

	DECLARE_MULTICAST_DELEGATE_TwoParams(FGameFinishedSignature, bool, bool);
	FGameFinishedSignature OnGameFinished;

	DECLARE_MULTICAST_DELEGATE(FGameModeBeginPlayFinished);
	FGameModeBeginPlayFinished GameModeBeginPlayFinished;

	UPROPERTY(EditAnywhere)
	bool Unlimited;
	
private:
	
	UPROPERTY()
	class AMainGameState* MainGameState;
	
	UPROPERTY()
	APlayerController* Player;
};
