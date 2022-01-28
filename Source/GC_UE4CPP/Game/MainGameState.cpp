// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameState.h"

void AMainGameState::BeginPlay()
{
	Super::BeginPlay();
}

void AMainGameState::AddSpotToArray(ASpot* PrmSpot)
{
	Spots.Add(PrmSpot);
}