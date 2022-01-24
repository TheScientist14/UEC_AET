// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Spot.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

UCLASS()
class GC_UE4CPP_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=AI)
	TSubclassOf<AActor> AI;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=AI)
	TArray<ASpot*> Barrels;
	
	UPROPERTY(EditAnywhere, Category=AI)
	UBlackboardData* BlackboardGoblin;
	
	FActorSpawnParameters SpawnInfo;

	void AddBarrelToArray(ASpot* PrmSpot);
	
	void Spawn(UClass* PrmAI);

	ASpot* GetRandomSpot();
};
