// Fill out your copyright notice in the Description page of Project Settings.


#include "VictoryDefeat_UserWidget.h"

#include "Components/Button.h"
#include "Components/HorizontalBox.h"
#include "Components/TextBlock.h"
#include "GC_UE4CPP/Game/MainGameMode.h"
#include "GC_UE4CPP/Game/MainGameState.h"
#include "Kismet/GameplayStatics.h"


void UVictoryDefeat_UserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	// Events for the button in the UI
	if (ButtonRestart)
	{
		ButtonRestart->OnClicked.AddUniqueDynamic(this, &UVictoryDefeat_UserWidget::ReloadLevel);
	}
	if (ButtonMenu)
	{
		ButtonMenu->OnClicked.AddUniqueDynamic(this, &UVictoryDefeat_UserWidget::MainMenu);
	}
	if (ButtonQuit)
	{
		ButtonQuit->OnClicked.AddUniqueDynamic(this, &UVictoryDefeat_UserWidget::Quit);
	}
}

void UVictoryDefeat_UserWidget::NativeOnInitialized()
{
	// Add listener for OnGameFinished event
	GameMode = Cast<AMainGameMode>(UGameplayStatics::GetGameMode(this));
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

	if(GameMode->MainGameState->IsUnlimited)
	{
		TextScore->SetText(FText::FromString(FString::Printf(TEXT("%d"),GameMode->MainGameState->StashedFood)));
	}
	else
	{
		ScoreContainer->SetVisibility(ESlateVisibility::Hidden);	
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

void UVictoryDefeat_UserWidget::MainMenu()
{
	// Reloads the MainMenu level, sets the mouse for game use and hides the cursor
	UGameplayStatics::OpenLevel(this, FName("MainMenu"), false);
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

void UVictoryDefeat_UserWidget::Quit()
{
	APlayerController* Player = Cast<APlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	// Quit for editor and game 
#if WITH_EDITOR
	UKismetSystemLibrary::QuitEditor();
#endif
	
	UKismetSystemLibrary::QuitGame(this, Player, EQuitPreference::Quit,
								   false);

}