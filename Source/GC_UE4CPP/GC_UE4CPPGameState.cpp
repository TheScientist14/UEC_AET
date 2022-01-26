// Fill out your copyright notice in the Description page of Project Settings.


#include "GC_UE4CPPGameState.h"

void AGC_UE4CPPGameState::BeginPlay()
{
	Super::BeginPlay();
}

void AGC_UE4CPPGameState::AddSpotToArray(ASpot* PrmSpot)
{
	Spots.Add(PrmSpot);
}
