// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Food.h"
#include "GC_UE4CPPGameState.h"
#include "PickableItem.h"
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
	FVector Spot;
	
	UPROPERTY(EditAnywhere)
	FVector Spawn;
	
	UPROPERTY(EditAnywhere)
	class ASpawner* Spawner;
	
	UPROPERTY(EditAnywhere)
	bool Wait;

protected:

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> Food;

	UPROPERTY(EditAnywhere)
	USkeletalMeshSocket const* Hand;

	AGC_UE4CPPGameState* GameState;
	FAttachmentTransformRules* Rules;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void GetNextSpot();

	void SpawnFood(UClass* PrmFood);
};
