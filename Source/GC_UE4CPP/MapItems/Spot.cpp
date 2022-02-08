// Fill out your copyright notice in the Description page of Project Settings.


#include "Spot.h"
#include "Kismet/GameplayStatics.h"
#include "GC_UE4CPP/Game/MainGameMode.h"

// Sets default values
ASpot::ASpot()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("StaticMesh"));
	SetRootComponent(StaticMesh);

	FoodEmplacement = CreateDefaultSubobject<USceneComponent>(FName("FoodEmplacement"));
	FoodEmplacement->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void ASpot::BeginPlay()
{
	Super::BeginPlay();
	GameMode = Cast<AMainGameMode>(UGameplayStatics::GetGameMode(this));
}

// Called every frame
void ASpot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool ASpot::HasFood()
{
	return Occupied;
}

void ASpot::SetSpotOccupied()
{
	if (!Occupied)
	{
		Occupied = true;
		GameMode->AddFood();
	}
}

void ASpot::SetSpotFree()
{
	if (Occupied)
	{
		Occupied = false;
		GameMode->RemoveFood();
	}
}

FTransform ASpot::GetFoodSpotTransform()
{
	return FoodEmplacement->GetComponentTransform();
}
