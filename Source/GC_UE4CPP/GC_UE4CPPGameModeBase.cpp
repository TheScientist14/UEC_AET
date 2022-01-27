// Copyright Epic Games, Inc. All Rights Reserved.


#include "GC_UE4CPPGameModeBase.h"

void AGC_UE4CPPGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	GameState = Cast<AGC_UE4CPPGameState>(GetWorld()->GetGameState());
}

ASpot* AGC_UE4CPPGameModeBase::GetRandomSpot()
{
	return GameState->Spots[FMath::RandRange(0, GameState->Spots.Num() - 1)];
}
