// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NavigationSystem.h"
#include "GC_UE4CPP/MapItems/PickableItem.h"
#include "GameFramework/Character.h"
#include "GC_UE4CPP/Characters/PickUpAbilityComponent.h"
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
	bool Wait;

	UPROPERTY(EditAnywhere)
	TSubclassOf<APickableItem> Food;

	UPROPERTY(EditAnywhere)
	UPickUpAbilityComponent* PickUpAbilityComponent;

	APickableItem* FoodOnHand;

protected:
	UPROPERTY(EditAnywhere)
	USkeletalMeshSocket* Hand;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void GetNextSpot();

	void PickUpFood(UClass* PrmFood);

	void PutDownFood();
};
