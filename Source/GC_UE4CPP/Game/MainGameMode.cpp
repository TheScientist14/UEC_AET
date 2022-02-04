// Copyright Epic Games, Inc. All Rights Reserved.


#include "MainGameMode.h"

#include "Blueprint/UserWidget.h"
#include "GC_UE4CPP/MapItems/Spot.h"
#include "Kismet/GameplayStatics.h"

void AMainGameMode::BeginPlay()
{
	Super::BeginPlay();
	MainGameState = Cast<AMainGameState>(GetWorld()->GetGameState());
	Player = Cast<APlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
}

ASpot* AMainGameMode::GetRandomSpot()
{
	if (MainGameState->FoodOnLevel < GetMaxFoodOnLevel())
	{
		ASpot* SpotReturn = MainGameState->Spots[FMath::RandRange(0, MainGameState->Spots.Num() - 1)];
		while (SpotReturn->HasFood())
		{
			SpotReturn = MainGameState->Spots[FMath::RandRange(0, MainGameState->Spots.Num() - 1)];
		}
		return SpotReturn;
	}
	return nullptr;
}

int AMainGameMode::GetFoodOnLevel()
{
	return MainGameState->FoodOnLevel;
}

int AMainGameMode::GetMaxFoodOnLevel()
{
	return MainGameState->Spots.Num() / 2;
}

void AMainGameMode::AddFood()
{
	MainGameState->FoodOnLevel++;
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, FString::Printf(TEXT("%d"), GetFoodOnLevel()));
}

void AMainGameMode::RemoveFood()
{
	MainGameState->FoodOnLevel--;
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, FString::Printf(TEXT("%d"), GetFoodOnLevel()));
}

void AMainGameMode::AddStashedFood()
{
	MainGameState->StashedFood++;
	OnStashedFoodUpdate.Broadcast(MainGameState->StashedFood, MainGameState->MaxStashedFood);

	if (MainGameState->StashedFood == MainGameState->MaxStashedFood)
	{
		UE_LOG(LogTemp, Warning, TEXT("Testing for win condition"));
		EndGameVictory();
	}
}

void AMainGameMode::EndGameDefeat()
{
	MainGameState->IsGameEnded = true;
	EndUI();
}

void AMainGameMode::EndGameVictory()
{
	MainGameState->IsWon = true;
	MainGameState->IsGameEnded = true;
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
			OnGameFinished.Broadcast(MainGameState->IsGameEnded, MainGameState->IsWon);
			Widget->SetVisibility(ESlateVisibility::Visible);
			Player->SetInputMode(FInputModeUIOnly());
			Player->bShowMouseCursor = true;
		}
	}
}
