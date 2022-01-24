// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Spawner.h"
#include "Spot.h"
#include "GameFramework/Character.h"
#include "Goblin.generated.h"

UCLASS()
class GC_UE4CPP_API AGoblin : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGoblin();
	
	UPROPERTY(EditAnywhere)
	ASpot* Spot;
	
	UPROPERTY(EditAnywhere)
	FVector Spawn;
	
	UPROPERTY(EditAnywhere)
	ASpawner* Spawner;

protected:

	UPROPERTY(EditAnywhere)
	AActor* Food;
	
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void CallSpawner();
};
