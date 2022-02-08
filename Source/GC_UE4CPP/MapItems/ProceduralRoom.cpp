// Fill out your copyright notice in the Description page of Project Settings.

#include "ProceduralRoom.h"

#include <ppltasks.h>

#include "AITypes.h"
#include "Spot.h"
#include "GC_UE4CPP/Game/MainGameMode.h"
#include "GC_UE4CPP/Game/MainGameState.h"

// Sets default values
AProceduralRoom::AProceduralRoom()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	InstancedStaticMeshComponentFloor = CreateDefaultSubobject<UInstancedStaticMeshComponent>(
		TEXT("Instanced Floor Static Mesh"));
	SetRootComponent(InstancedStaticMeshComponentFloor);

	InstancedStaticMeshComponentFloor->SetMobility(EComponentMobility::Static);
	InstancedStaticMeshComponentFloor->SetCollisionProfileName("BlockAll");


	InstancedStaticMeshComponentWall = CreateDefaultSubobject<UInstancedStaticMeshComponent>(
		TEXT("Instanced Wall Static Mesh"));

	InstancedStaticMeshComponentWall->SetMobility(EComponentMobility::Static);
	InstancedStaticMeshComponentWall->SetCollisionProfileName("BlockAll");

	//InstancedStaticMeshComponentWall->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::DontSpawnIfColliding;
}

// Called when the game starts or when spawned
void AProceduralRoom::BeginPlay()
{
	Super::BeginPlay();
	FloorHalfSize = (FloorSize % 2 == 0) ? FloorSize / 2 : FloorSize / 2 + 1;
	HalfTile = TileableFloorAndWallSize / 2;
	Cast<AMainGameMode>(GetWorld()->GetAuthGameMode())->GameModeBeginPlayFinished.AddUObject(
		this, &AProceduralRoom::Spawn);
}

// Called every frame
void AProceduralRoom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AProceduralRoom::Spawn()
{
	SpawnFloor();
	SpawnBarrels(Barrel, Food);
	SpawnCrates(CrateClump2, CrateClumpSize, ChanceOfCrateClump, SpawnHeight, 90);
	SpawnCrates(CrateClump, CrateClumpSize, ChanceOfCrateClump, SpawnHeight, 0);
	SpawnCrates(CrateClass, CrateSize, ChanceOfSmallCrate, SpawnHeight, 0);
}

void AProceduralRoom::SpawnFloor()
{
	for (int i = -FloorHalfSize; i <= FloorHalfSize; i++)
	{
		for (int j = -FloorHalfSize; j <= FloorHalfSize; j++)
		{
			int RandNum = FMath::RandRange(0, 3);
			int angle = 0;
			switch (RandNum)
			{
			case 1:
				angle = 90;
				break;
			case 2:
				angle = 180;
				break;
			case 3:
				angle = 270;
				break;
			default:
				break;
			}

			if (i == -FloorHalfSize || i == FloorHalfSize)
			{
				if (i == -FloorHalfSize)
				{
					SpawnWall(i, j, -HalfTile, 0, HalfTile, 90);
					SpawnWall(i, j, -HalfTile, 0, HalfTile * 3, 90);
				}
				else
				{
					SpawnWall(i, j, +HalfTile, 0, HalfTile, 90);
					SpawnWall(i, j, +HalfTile, 0, HalfTile * 3, 90);
				}
			}
			if (j == -FloorHalfSize || j == FloorHalfSize)
			{
				if (i != 0 && i != 1)
				{
					if (j == -FloorHalfSize)
					{
						SpawnWall(i, j, 0, -HalfTile, HalfTile, 0);
						SpawnWall(i, j, 0, -HalfTile, HalfTile * 3, 0);
					}
					else
					{
						SpawnWall(i, j, 0, +HalfTile, HalfTile, 0);
						SpawnWall(i, j, 0, +HalfTile, HalfTile * 3, 0);
					}
				}
			}
			InstancedStaticMeshComponentFloor->AddInstance(FTransform(FRotator(0, angle, 0),
			                                                          FVector(i * TileableFloorAndWallSize,
			                                                                  j * TileableFloorAndWallSize, 0)));
		}
	}
}

void AProceduralRoom::SpawnWall(int I, int J, int IOffset, int JOffset, int height, int Rotation)
{
	InstancedStaticMeshComponentWall->AddInstance(FTransform(FRotator(0, Rotation, 0),
	                                                         FVector(I * TileableFloorAndWallSize + IOffset,
	                                                                 J * TileableFloorAndWallSize + JOffset, height)));
}

void AProceduralRoom::SpawnCrates(UClass* CrateToSpawn, int ActorSize, int SpawnChance, float Height, int Rotation)
{
	float Ratio = TileableFloorAndWallSize / ActorSize;

	int Size = FloorSize * Ratio;

	int HalfSpawnSize = (Size % 2 == 0) ? Size / 2 : Size / 2 + 1;

	for (int i = -HalfSpawnSize + 1; i < HalfSpawnSize; ++i)
	{
		for (int j = -HalfSpawnSize + 1; j < HalfSpawnSize; ++j)
		{
			int ChanceOfSpawn = FMath::RandRange(0, 100);
			//int Rotation = FMath::RandRange(0, 360); 

			if (ChanceOfSpawn <= SpawnChance)
			{
				AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(CrateToSpawn,
				                                                      FVector(i * ActorSize, j * ActorSize, Height),
				                                                      FRotator(0, Rotation, 0), SpawnInfo);
				if (SpawnedActor)
				{
					SpawnedActor->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
				}
			}
		}
	}
}

void AProceduralRoom::SpawnBarrels(UClass* PrmBarrel, UClass* PrmFood)
{
	int XSpawn;
	int YSpawn;
	int Rotation;

	ASpot* ABarrel = nullptr;
	while (!ABarrel)
	{
		XSpawn = FMath::RandRange(-FloorHalfSize, FloorHalfSize);
		YSpawn = FMath::RandRange(-FloorHalfSize, FloorHalfSize);
		
		Rotation = FMath::RandRange(0, 360);
		ABarrel = GetWorld()->SpawnActor<ASpot>(
			PrmBarrel, FVector(XSpawn * TileableFloorAndWallSize, YSpawn * TileableFloorAndWallSize, SpawnHeight),
			FRotator(0, Rotation, 0), SpawnInfo);

		UE_LOG(LogTemp, Error, TEXT("barrel with food try spawn"))
	}

	if (ABarrel)
	{
		UE_LOG(LogTemp, Error, TEXT("barrel with food spawned"))
		ABarrel->SetSpotOccupied();
		GetWorld()->SpawnActor<APickableItem>(
			PrmFood, ABarrel->GetFoodSpotTransform().GetLocation(), ABarrel->GetFoodSpotTransform().Rotator());
	}


	Cast<AMainGameState>(GetWorld()->GetGameState())->AddSpotToArray(ABarrel);

	for (int i = 0; i < NumberOfBarrels - 1; ++i)
	{
		Rotation = FMath::RandRange(0, 360);
		XSpawn = FMath::RandRange(-FloorHalfSize, FloorHalfSize);
		YSpawn = FMath::RandRange(-FloorHalfSize, FloorHalfSize);


		ABarrel = GetWorld()->SpawnActor<ASpot>(
			PrmBarrel, FVector(XSpawn * TileableFloorAndWallSize, YSpawn * TileableFloorAndWallSize, SpawnHeight),
			FRotator(0, Rotation, 0), SpawnInfo);

		if (!ABarrel)
		{
			i--;
		}
		else
		{
			Cast<AMainGameState>(GetWorld()->GetGameState())->AddSpotToArray(ABarrel);
		}
	}

	GEngine->AddOnScreenDebugMessage(1, 5.0f, FColor::Blue, TEXT("Spawn Barrels"));
}
