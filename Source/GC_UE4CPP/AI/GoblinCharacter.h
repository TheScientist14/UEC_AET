// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NavigationSystem.h"
#include "GC_UE4CPP/MapItems/Food.h"
#include "GameFramework/Character.h"
#include "GoblinCharacter.generated.h"

UCLASS()
class GC_UE4CPP_API AGoblinCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGoblinCharacter();
	
	UPROPERTY(EditAnywhere)
	class ASpot* Spot;
	
	UPROPERTY(EditAnywhere)
	FVector Spawn;
	
	UPROPERTY(EditAnywhere)
	class ASpawner* Spawner;
	
	UPROPERTY(EditAnywhere)
	bool Wait;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> Food;
	
	AActor* FoodOnHand;

	void DestroyFood();

protected:
	UPROPERTY(EditAnywhere)
	USkeletalMeshSocket* Hand;
	
	class AMainGameState* GameState;
	
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
