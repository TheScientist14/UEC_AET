// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickableItem.h"
#include "GameFramework/Actor.h"
#include "ProceduralRoom.generated.h"

UCLASS()
class GC_UE4CPP_API AProceduralRoom : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProceduralRoom();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Room)
	UStaticMeshComponent* StaticMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Room|SmallCrate")
	TSubclassOf<AActor> CrateClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Room|Floor")
	TSubclassOf<AActor> FloorClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Room)
	TSubclassOf<AActor> WallClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Room|Floor")
	int FloorSize = 12;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Room|SmallCrate")
	int CrateSize = 150;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Room|Floor")
	float TileableFloorSize = 200;

	UPROPERTY()
	int HalfTile;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Room|SmallCrate")
	float ChanceOfSmallCrate = 20;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Room|CrateClump")
	TSubclassOf<AActor> CrateClump;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Room|CrateClump")
    TSubclassOf<AActor> CrateClump2;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Room")
	TSubclassOf<APickableItem> Food;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Room|CrateClump")
	int CrateClumpSize = 420;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Room|CrateClump")
	float ChanceOfCrateClump = 30;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Room")
	float SpawnHeight = 13;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Room|Barrels")
	TSubclassOf<class ASpot> Barrel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Room|Barrels")
	int NumberOfBarrels = 10;
 
	void SpawnFloor(UClass* Floor);

	void SpawnWall(int I, int J, int IOffset, int JOffset, int height, int Rotation);

	void SpawnCrates(UClass* CrateToSpawn, int ActorSize, int SpawnChance, float SpawnHeight, int Rotation);

	void SpawnBarrels(UClass* PrmBarrel, UClass* PrmFood);
	
private:

	UPROPERTY()
	int FloorHalfSize;

	FActorSpawnParameters SpawnInfo;
	
};