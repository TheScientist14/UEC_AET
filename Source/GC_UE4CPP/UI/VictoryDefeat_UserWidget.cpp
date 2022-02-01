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

	if (ButtonRestart)
	{
		UE_LOG(LogTemp, Warning, TEXT("Testing for ButtonRestart"));

		ButtonRestart->OnClicked.AddUniqueDynamic(this, &UVictoryDefeat_UserWidget::ReloadLevel);
	}
}

void UVictoryDefeat_UserWidget::NativeOnInitialized()
{
	AMainGameMode* GameMode = Cast<AMainGameMode>(UGameplayStatics::GetGameMode(this));
	temp = GameMode->OnGameFinished.AddUObject(this, &UVictoryDefeat_UserWidget::SetUI);
}

void UVictoryDefeat_UserWidget::SetUI(bool PrmIsGameFinished, bool PrmIsGameWon)
{	
	if (PrmIsGameWon)
	{

		UE_LOG(LogTemp, Warning, TEXT("Testing for won game"));
		
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
	UE_LOG(LogTemp, Warning, TEXT("Testing for Reload Level"));
	UGameplayStatics::OpenLevel(this, FName(GetWorld()->GetName()), false);
	APlayerController* Player = Cast<APlayerController>(UGameplayStatics::GetPlayerController(GetWorld(),0));
	Player->bShowMouseCursor = false;
	Player->SetInputMode(FInputModeGameOnly());
}
