// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

class APlayerCharacter;

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	AMyPlayerController();

	float ForwardDelta = 0;
	float RightDelta = 0;
	APlayerCharacter* PlayerCharacter;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	
	virtual void SetupInputComponent() override;

	UFUNCTION()
	void Interact();

	UFUNCTION()
	void MoveForward(float DeltaX);

	UFUNCTION()
	void MoveRight(float DeltaY);
};
