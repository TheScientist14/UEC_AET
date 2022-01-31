// Copyright Epic Games, Inc. All Rights Reserved.


#include "MainGameMode.h"

#include "GC_UE4CPP/MapItems/Spot.h"

void AMainGameMode::BeginPlay()
{
	Super::BeginPlay();
	GameState = Cast<AMainGameState>(GetWorld()->GetGameState());
}

ASpot* AMainGameMode::GetRandomSpot()
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

int AMainGameMode::GetFoodOnLevel()
{
	return GameState->FoodOnLevel;
}

int AMainGameMode::GetMaxFoodOnLevel()
{
	return GameState->Spots.Num()/2;
}

void AMainGameMode::AddFood()
{
	GameState->FoodOnLevel++;
}

void AMainGameMode::RemoveFood()
{
	GameState->FoodOnLevel--;
}

void AMainGameMode::AddStashedFood()
{
	GameState->StashedFood++;
	OnStashedFoodUpdate.Broadcast(GameState->StashedFood, GameState->MaxStashedFood);
}

