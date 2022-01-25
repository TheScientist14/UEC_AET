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
	GEngine->AddOnScreenDebugMessage(1, 5.0f, FColor::Black, TEXT("BeginPlay Spawner"));
	Cast<AGC_UE4CPPGameState>(GetWorld()->GetGameState())->SpawnEnemy = GetActorLocation();
}

// Called every frame
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}