// Copyright Epic Games, Inc. All Rights Reserved.


#include "MainGameMode.h"

#include "MainGameState.h"
#include "Blueprint/UserWidget.h"
#include "GC_UE4CPP/MapItems/Spot.h"
#include "Kismet/GameplayStatics.h"
#include "GC_UE4CPP/UI/VictoryDefeat_UserWidget.h"

void AMainGameMode::BeginPlay()
{
	//casts and Broadcast the GameModeBeginPlayFinished event
	Super::BeginPlay();
	MainGameState = Cast<AMainGameState>(GetWorld()->GetGameState());
	if (!MainGameState)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to cast GetGameState() to AMainGameState"))
	}
	Player = Cast<APlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	GameModeBeginPlayFinished.Broadcast();
}

ASpot* AMainGameMode::GetRandomSpot()
{
	//returns a random ASpot* that hasn't got any food on it 
	ASpot* SpotReturn;
	do
	{
		SpotReturn = MainGameState->Spots[FMath::RandRange(0, MainGameState->Spots.Num() - 1)];
	}
	while (SpotReturn->HasFood());
#if WITH_EDITOR
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red,
	                                 FString::Printf(TEXT("SetSpotOccuped %s"), *SpotReturn->GetName()));
#endif

	SpotReturn->SetSpotOccupied();
	return SpotReturn;
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
#if WITH_EDITOR
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, FString::Printf(TEXT("%d"), GetFoodOnLevel()));
#endif
}

void AMainGameMode::RemoveFood()
{
	MainGameState->FoodOnLevel--;
#if WITH_EDITOR
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, FString::Printf(TEXT("%d"), GetFoodOnLevel()));
#endif
}

void AMainGameMode::AddStashedFood()
{
	//Adds food to the stached food counter and broadcasts OnStashedFoodUpdate event
	MainGameState->StashedFood++;
	OnStashedFoodUpdate.Broadcast(MainGameState->StashedFood, MainGameState->MaxStashedFood);

	if (MainGameState->StashedFood >= MainGameState->MaxStashedFood && !MainGameState->IsUnlimited)
	{
		UE_LOG(LogTemp, Warning, TEXT("Testing for win condition"));
		EndGameVictory();
	}
}

void AMainGameMode::EndGameDefeat()
{
	//Ends the game and generates the end UI 
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
	//Generates the en UI 
	if (VD_UI)
	{
		Widget = CreateWidget(Player, VD_UI);

		if (Widget)
		{
			Widget->AddToViewport();
			OnGameFinished.Broadcast(MainGameState->IsGameEnded, MainGameState->IsWon);
			Widget->SetVisibility(ESlateVisibility::Visible);
			if (Player)
			{
				Player->SetInputMode(FInputModeUIOnly());
				Player->bShowMouseCursor = true;
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("Failed to cast GetPlayerController() to APlayerController"))
			}
		}
	}
}

bool AMainGameMode::NeedsFood()
{
	//returns if there is enough food on the level
	if (GetFoodOnLevel() < GetMaxFoodOnLevel())
	{
		return true;
	}
	return false;
}
