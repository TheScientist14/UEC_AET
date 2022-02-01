// Copyright Epic Games, Inc. All Rights Reserved.


#include "MainGameMode.h"

#include "Blueprint/UserWidget.h"
#include "GC_UE4CPP/MapItems/Spot.h"
#include "Kismet/GameplayStatics.h"

void AMainGameMode::BeginPlay()
{
	Super::BeginPlay();
	GameState = Cast<AMainGameState>(GetWorld()->GetGameState());
	Player = Cast<APlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
}

ASpot* AMainGameMode::GetRandomSpot()
{
	if (GameState->FoodOnLevel < GetMaxFoodOnLevel())
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
	return GameState->Spots.Num() / 2;
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

	if (GameState->StashedFood == GameState->MaxStashedFood)
	{
		UE_LOG(LogTemp, Warning, TEXT("Testing for win condition"));
		EndGameVictory();
	}
}

void AMainGameMode::EndGameDefeat()
{
	GameState->IsGameEnded = true;
	EndUI();
}

void AMainGameMode::EndGameVictory()
{
	GameState->IsWon = false;
	GameState->IsGameEnded = true;
	EndUI();
}

void AMainGameMode::EndUI()
{
	if (VD_UI)
	{
		Widget = CreateWidget(Player, VD_UI);

		if (Widget)
		{
			Widget->AddToViewport();
			OnGameFinished.Broadcast(GameState->IsGameEnded, GameState->IsWon);
			Widget->SetVisibility(ESlateVisibility::Visible);
			Player->SetInputMode(FInputModeUIOnly());
			Player->bShowMouseCursor = true;
		}
	}
}
