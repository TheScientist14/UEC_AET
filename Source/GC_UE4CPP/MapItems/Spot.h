// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spot.generated.h"

class AMainGameMode;

UCLASS()
class GC_UE4CPP_API ASpot : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpot();

protected:

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMesh;
	
	UPROPERTY(EditAnywhere)
	USceneComponent* FoodEmplacement;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> FoodClass;
	
	UPROPERTY(VisibleAnywhere)
	AActor* FoodOnSpot;

	AMainGameMode* GameMode;

	UPROPERTY(VisibleAnywhere)
	bool Occupied=false;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:		

	bool HasFood();

	FTransform GetFoodSpotTransform();

	void SetSpotOccupied();
	void SetSpotFree();

};
