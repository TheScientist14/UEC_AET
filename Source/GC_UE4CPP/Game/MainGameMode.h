// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MainGameState.h"
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
	ASpot* GetRandomSpot();
	int GetFoodOnLevel();
	int GetMaxFoodOnLevel();
	void AddFood();
	void RemoveFood();

private:
	AMainGameState* GameState;
};
