// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuUserWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UMainMenuUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	// Events for each button in the UI
	if (ButtonPlay)
	{
		ButtonPlay->OnClicked.AddUniqueDynamic(this, &UMainMenuUserWidget::Play);
	}
	if (ButtonQuit)
	{
		ButtonQuit->OnClicked.AddUniqueDynamic(this, &UMainMenuUserWidget::Quit);
	}


	// Setting the cursor for UI use and also making it visible 
	Player = Cast<APlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if(Player)
	{
		Player->bShowMouseCursor = true;
		Player->SetInputMode(FInputModeUIOnly());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to cast GetPlayerController() to APlayerController"))
	}
	
}

void UMainMenuUserWidget::Play()
{
	// Setting the input for game use and opening levelElvyn
	Player->SetInputMode(FInputModeGameOnly());
	UGameplayStatics::OpenLevel(this, FName("LevelElvyn"), false);
}

void UMainMenuUserWidget::Quit()
{
	// Quit for editor and game 
#if WITH_EDITOR
	UKismetSystemLibrary::QuitEditor();
#endif
	UKismetSystemLibrary::QuitGame(this, Player, EQuitPreference::Quit,false);

}
