// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuUserWidget.h"
#include "Components/Button.h"
#include "GC_UE4CPP/Game/MainGameMode.h"
#include "Kismet/GameplayStatics.h"

void UMainMenuUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (ButtonPlay)
	{
		ButtonPlay->OnClicked.AddUniqueDynamic(this, &UMainMenuUserWidget::Play);
	}
	if (ButtonQuit)
	{
		ButtonQuit->OnClicked.AddUniqueDynamic(this, &UMainMenuUserWidget::Quit);
	}
	Player = Cast<APlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	Player->bShowMouseCursor = true;
	Player->SetInputMode(FInputModeUIOnly());
}

void UMainMenuUserWidget::Play()
{
	Player->SetInputMode(FInputModeGameOnly());
	UGameplayStatics::OpenLevel(this, FName("LevelElvyn"), false);
}

void UMainMenuUserWidget::Quit()
{
	UE_LOG(LogTemp, Warning, TEXT("Testing Quit"))

#if WITH_EDITOR
	UKismetSystemLibrary::QuitEditor();
#else
UKismetSystemLibrary::QuitGame(this, Player, EQuitPreference::Quit,
	                               false);
#endif


	//FGenericPlatformMisc::RequestExit(false);
}
