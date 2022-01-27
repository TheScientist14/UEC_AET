// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickableItem.h"
#include "GameFramework/Actor.h"
#include "Spot.generated.h"

UCLASS()
class GC_UE4CPP_API ASpot : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpot();

	void SpawnFood(UClass* PrmFood);

protected:

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMesh;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* FoodSpot;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> FoodClass;
	
	UPROPERTY(VisibleAnywhere)
	AActor* FoodOnSpot;

	UPROPERTY(VisibleAnywhere)
	bool Occupied=false;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	bool HasFood();

	void SetSpotOccupied();
	void SetSpotFree();

};
