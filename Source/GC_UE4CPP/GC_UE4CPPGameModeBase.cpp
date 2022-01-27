// Copyright Epic Games, Inc. All Rights Reserved.


#include "GC_UE4CPPGameModeBase.h"

void AGC_UE4CPPGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	GameState = Cast<AGC_UE4CPPGameState>(GetWorld()->GetGameState());
}

ASpot* AGC_UE4CPPGameModeBase::GetRandomSpot()
{
	if(GameState->FoodOnLevel < GetMaxFoodOnLevel())
	{		
		ASpot* SpotReturn = GameState->Spots[FMath::RandRange(0, GameState->Spots.Num() - 1)];
		while (SpotReturn->HasFood())
		{
			SpotReturn = GameState->Spots[FMath::RandRange(0, GameState->Spots.Num() - 1)];
		}
		return SpotReturn;
	}
	return nullptr;
}

int AGC_UE4CPPGameModeBase::GetFoodOnLevel()
{
	return GameState->FoodOnLevel;
}

int AGC_UE4CPPGameModeBase::GetMaxFoodOnLevel()
{
	return GameState->Spots.Num();
}

void AGC_UE4CPPGameModeBase::AddFood()
{
	GameState->FoodOnLevel++;
	if (GameState->FoodOnLevel==11)
	{
		UE_LOG(LogTemp, Warning, TEXT("FoodNb = 11"));
	}
}

void AGC_UE4CPPGameModeBase::RemoveFood()
{
	GameState->FoodOnLevel--;
}

