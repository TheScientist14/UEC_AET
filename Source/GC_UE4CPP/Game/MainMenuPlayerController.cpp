// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuPlayerController.h"
#include "Blueprint/UserWidget.h"

void AMainMenuPlayerController::BeginPlay()
{
	//creates and add the main menu UI 
	Super::BeginPlay();

	UUserWidget* UserWidget = CreateWidget(this, MainMenuClass);

	if(UserWidget)
	{
		UserWidget->AddToViewport();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to CreateWidget() for the Main menu, No Main menu is created."))
	}
	
	
	
}


