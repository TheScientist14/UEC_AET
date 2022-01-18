// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AI_Enemie.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API AAI_Enemie : public AAIController
{
	GENERATED_BODY()

public:
	void BeginPlay() override;

private:
	UPROPERTY()
	TArray<AActor*> Points;

	UFUNCTION()
	void GoToRandomPoints();
};
