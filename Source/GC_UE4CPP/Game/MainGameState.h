// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MainGameState.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class GC_UE4CPP_API AMainGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere)
	TArray<class ASpot*> Spots;
	
	UPROPERTY(EditAnywhere)
	FVector SpawnEnemy;

	UPROPERTY(VisibleAnywhere)
	int FoodOnLevel = 0;
	int MaxFoodOnLevel = 5;

	int StashedFood = 0;
	int MaxStashedFood = 5;
	
	void AddSpotToArray(ASpot* PrmSpot);

};
