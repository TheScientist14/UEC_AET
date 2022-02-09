// Fill out your copyright notice in the Description page of Project Settings.


#include "PauseMenuUserWidget.h"

#include "Components/Button.h"
#include "GC_UE4CPP/Characters/MainPlayerController.h"
#include "Kismet/GameplayStatics.h"

void UPauseMenuUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	if (ButtonMenu)
	{
		ButtonMenu->OnClicked.AddUniqueDynamic(this, &UPauseMenuUserWidget::MainMenu);
	}
	if(ButtonResume)
	{
		ButtonResume->OnClicked.AddUniqueDynamic(this, &UPauseMenuUserWidget::Resume);
	}
	if(ButtonRestart)
	{
		ButtonRestart->OnClicked.AddUniqueDynamic(this, &UPauseMenuUserWidget::ReloadLevel);
	}
	if(ButtonQuit)
	{
		ButtonQuit->OnClicked.AddUniqueDynamic(this, &UPauseMenuUserWidget::Quit);
	}

	UGameplayStatics::SetGamePaused(this, true);
	
}

void UPauseMenuUserWidget::MainMenu()
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

void UPauseMenuUserWidget::Resume()
{
	UE_LOG(LogTemp, Warning, TEXT("game resumed"));
	UGameplayStatics::SetGamePaused(this, false);
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(),0);
	PlayerController->bShowMouseCursor = false;
	PlayerController->SetInputMode(FInputModeGameOnly());

	SetVisibility(ESlateVisibility::Hidden);
}

void UPauseMenuUserWidget::ReloadLevel()
{
	// Reloads the current level, sets the mouse for game use and hides the cursor
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
	UGameplayStatics::OpenLevel(this, FName(GetWorld()->GetName()), false);
}

void UPauseMenuUserWidget::Quit()
{
	APlayerController* Player = Cast<APlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	// Quit for editor and game
#if WITH_EDITOR
	UKismetSystemLibrary::QuitEditor();
#endif
#if WITH_ENGINE
	UKismetSystemLibrary::QuitGame(this, Player, EQuitPreference::Quit,
								   false);
#endif
	

}
