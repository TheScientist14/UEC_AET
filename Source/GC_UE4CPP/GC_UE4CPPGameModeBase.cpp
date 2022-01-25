// Copyright Epic Games, Inc. All Rights Reserved.


#include "GC_UE4CPPGameModeBase.h"

FVector AGC_UE4CPPGameModeBase::GetRandomSpot()
{
	return GameState->Spots[FMath::RandRange(0, GameState->Spots.Num() - 1)]->GetActorLocation();
}
