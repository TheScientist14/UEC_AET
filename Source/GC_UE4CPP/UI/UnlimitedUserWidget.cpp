// Fill out your copyright notice in the Description page of Project Settings.


#include "UnlimitedUserWidget.h"

#include <string>

#include "Components/TextBlock.h"
#include "GC_UE4CPP/Game/MainGameMode.h"
#include "Kismet/GameplayStatics.h"

void UUnlimitedUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	AMainGameMode* MainGameMode = Cast<AMainGameMode>(UGameplayStatics::GetGameMode(this));

	if(MainGameMode)
	{
		MainGameMode->OnStashedFoodUpdate.AddUObject(this, &UUnlimitedUserWidget::UpdateScore);
		UE_LOG(LogTemp, Error, TEXT("Delegate bound"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Error delegate"));
		TextBlock->SetText(FText::FromString(TEXT("Error")));
	}

	
	
}

void UUnlimitedUserWidget::UpdateScore(int NbFood, int NbMaxFood)
{
	UE_LOG(LogTemp,Warning,TEXT("update food"))
	TextBlock->SetText(FText::FromString(FString::Printf(TEXT("%d"),NbFood)));
	
}
