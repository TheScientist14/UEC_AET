// Fill out your copyright notice in the Description page of Project Settings.


#include "VictoryDefeat_UserWidget.h"

#include <functional>

#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "GC_UE4CPP/Game/MainGameMode.h"
#include "Kismet/GameplayStatics.h"


void UVictoryDefeat_UserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	// Events for the button in the UI
	if (ButtonRestart)
	{
		ButtonRestart->OnClicked.AddUniqueDynamic(this, &UVictoryDefeat_UserWidget::ReloadLevel);
	}
}

void UVictoryDefeat_UserWidget::NativeOnInitialized()
{
	// Add listener for OnGameFinished event
	AMainGameMode* GameMode = Cast<AMainGameMode>(UGameplayStatics::GetGameMode(this));
	if(GameMode)
	{
		GameMode->OnGameFinished.AddUObject(this, &UVictoryDefeat_UserWidget::SetUI);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to cast GetGameMode() to AMainGameMode"))
	}
}

void UVictoryDefeat_UserWidget::SetUI(bool PrmIsGameFinished, bool PrmIsGameWon)
{
	// Sets the appropriate text and color;
	if (PrmIsGameWon)
	{		
		Text->SetText(FText::FromString(TEXT("VICTORY !")));
		Text->SetColorAndOpacity(FSlateColor(FLinearColor(0, 255, 0)));
	}
	else
	{
		Text->SetText(FText::FromString(TEXT("DEFEAT :/")));
		Text->SetColorAndOpacity(FSlateColor(FLinearColor(255, 0, 0)));
	}
}

void UVictoryDefeat_UserWidget::ReloadLevel()
{
	// Reloads the current level, sets the mouse for game use and hides the cursor
	UGameplayStatics::OpenLevel(this, FName(GetWorld()->GetName()), false);
	APlayerController* Player = UGameplayStatics::GetPlayerController(GetWorld(),0);
	if(Player)
	{
		Player->bShowMouseCursor = false;
		Player->SetInputMode(FInputModeGameOnly());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to GetPlayerController()"))
	}
}
