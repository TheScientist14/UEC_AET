// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Spot.h"
#include "GameFramework/GameStateBase.h"
#include "GC_UE4CPPGameState.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class GC_UE4CPP_API AGC_UE4CPPGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	TArray<ASpot*> Spots;
	
	UPROPERTY(EditAnywhere)
	FVector SpawnEnemy;
	
	void AddSpotToArray(ASpot* PrmSpot);
};
