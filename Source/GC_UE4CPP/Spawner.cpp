// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner.h"

#include "Goblin.h"
#include "BehaviorTree/BlackboardComponent.h"

// Sets default values
ASpawner::ASpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	Spawn(AI);
	Spawn(AI);
}

// Called every frame
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawner::AddBarrelToArray(ASpot* PrmSpot)
{
	Barrels.Add(PrmSpot);
}

void ASpawner::Spawn(UClass* PrmAI)
{
	AGoblin* Goblin = Cast<AGoblin>(GetWorld()->SpawnActor<AGoblin>(PrmAI, GetActorLocation(), GetActorRotation(), SpawnInfo));
	
	if(Goblin)
	{
		Goblin->Spot = GetRandomSpot();
		Goblin->Spawn = GetActorLocation();
		Goblin->Spawner = this;
	}
}

ASpot* ASpawner::GetRandomSpot()
{
	return Barrels[FMath::RandRange(0, Barrels.Num() - 1)];
}

