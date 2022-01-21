// Fill out your copyright notice in the Description page of Project Settings.

#include "ProceduralRoom.h"

#include "AITypes.h"

// Sets default values
AProceduralRoom::AProceduralRoom()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	SetRootComponent(StaticMesh);
}

// Called when the game starts or when spawned
void AProceduralRoom::BeginPlay()
{
	Super::BeginPlay();
	//SpawnCrate(CrateClass);
	FloorHalfSize = (FloorSize % 2 == 0) ? FloorSize / 2 : FloorSize / 2 + 1;
	SpawnFloor(FloorClass);
	SpawnCrates(CrateClump, CrateClumpSize, ChanceOfCrateClump, SpawnHeight);
	SpawnCrates(CrateClass, CrateSize, ChanceOfSmallCrate, SpawnHeight);
	
	
	UE_LOG(LogTemp, Warning, TEXT("testing"));
}

// Called every frame
void AProceduralRoom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AProceduralRoom::SpawnCrate(UClass* CrateToSpawn)
{
	GetWorld()->SpawnActor<AActor>(CrateToSpawn, FVector(0,0,50), FRotator(0.f));
}

void AProceduralRoom::SpawnFloor(UClass* Floor)
{
	UE_LOG(LogTemp, Warning, TEXT("testing 1 : %d"), FloorHalfSize);

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
				angle = 360;
				break;
			default:
				break;
			}


			if (i == -FloorHalfSize || i == FloorHalfSize)
			{
				if (i == -FloorHalfSize)
				{
					SpawnWall(i, j, -100, 0, 100, 90);
					SpawnWall(i, j, -100, 0, 300, 90);
				}
				else
				{
					SpawnWall(i, j, +100, 0, 100, 90);
					SpawnWall(i, j, +100, 0, 300, 90);
				}
			}
			if (j == -FloorHalfSize || j == FloorHalfSize)
			{
				if (j == -FloorHalfSize)
				{
					SpawnWall(i, j, 0, -100, 100, 0);
					SpawnWall(i, j, 0, -100, 300, 0);
				}
				else
				{
					SpawnWall(i, j, 0, +100, 100, 0);
					SpawnWall(i, j, 0, +100, 300, 0);
				}
			}

			// make this in an other for to scale the room size to le box size to have nife fiting, ratio 140:200
			// change the Max of the range to change the spawn rate

			//spawn : air, 2 high, 1 high, barrel spawn all at random and then spawn the 10 barrels if collision
			//with actors then destroy actor and place the barrel

			// if (i != -FloorHalfSize || i != FloorHalfSize || j != -FloorHalfSize || j != FloorHalfSize)
			// {
			// 	int randSpawn = FMath::RandRange(0, 10);
			// 	switch (randSpawn)
			// 	{
			// 	case 1:
			// 		GetWorld()->SpawnActor<AActor>(CrateClass, FVector(i * 140, j * 140, 0),
			// 		                               FRotator(0.f));
			// 		break;
			// 	default:
			// 		break;
			// 	}
			// }

			GetWorld()->SpawnActor<AActor>(Floor, FVector(i * TileableFloorSize, j * TileableFloorSize, 0),
			                               FRotator(0, angle, 0));
		}
	}
}

void AProceduralRoom::SpawnWall(int I, int J, int IOffset, int JOffset, int height, int Rotation)
{
	GetWorld()->SpawnActor<AActor>(
		WallClass, FVector(I * TileableFloorSize + IOffset, J * TileableFloorSize + JOffset, height),
		FRotator(0, Rotation, 0));
}

void AProceduralRoom::SpawnCrates(UClass* CrateToSpawn, int ActorSize, int SpawnChance, float Height)
{
	float Ratio = TileableFloorSize / ActorSize;

	int Size = FloorSize * Ratio;

	int HalfSpawnSize = (Size % 2 == 0) ? Size / 2 : Size / 2 + 1;

	for (int i = -HalfSpawnSize + 1; i < HalfSpawnSize; ++i)
	{
		for (int j = -HalfSpawnSize  + 1; j < HalfSpawnSize; ++j)
		{

			int ChanceOfSpawn = FMath::RandRange(0,100);
			int Rotation = FMath::RandRange(0,360);
			
			if (ChanceOfSpawn <= SpawnChance)
			{
				FActorSpawnParameters SpawnInfo;
				SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::DontSpawnIfColliding;
				GetWorld()->SpawnActor<AActor>(CrateToSpawn, FVector(i * ActorSize, j * ActorSize, Height), FRotator(0,Rotation,0),SpawnInfo);
			}
			
		}
	}
}
