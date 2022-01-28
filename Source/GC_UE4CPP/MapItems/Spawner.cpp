// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GC_UE4CPP/Game/MainGameState.h"

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
	GEngine->AddOnScreenDebugMessage(1, 5.0f, FColor::Black, TEXT("BeginPlay Spawner"));
	Cast<AMainGameState>(GetWorld()->GetGameState())->SpawnEnemy = GetActorLocation();
}

// Called every frame
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}