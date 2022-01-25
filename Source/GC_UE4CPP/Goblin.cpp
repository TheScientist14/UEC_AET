// Fill out your copyright notice in the Description page of Project Settings.


#include "Goblin.h"

#include "GC_UE4CPPGameModeBase.h"
#include "Spawner.h"
#include "GC_UE4CPP/GC_UE4CPPGameState.h"
#include "Spot.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AGoblin::AGoblin()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGoblin::BeginPlay()
{
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(1, 5.0f, FColor::Black, TEXT("BeginPlay Goblin"));
	GameState = Cast<AGC_UE4CPPGameState>(GetWorld()->GetGameState());
	Spot = GameState->Spots[FMath::RandRange(0, GameState->Spots.Num() - 1)]->GetActorLocation();
	Spawn = GameState->SpawnEnemy;
}

// Called every frame
void AGoblin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AGoblin::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AGoblin::GetNextSpot()
{
	Spot = Cast<AGC_UE4CPPGameModeBase>(GetWorld()->GetAuthGameMode())->GetRandomSpot();
}