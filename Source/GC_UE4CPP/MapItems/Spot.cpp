// Fill out your copyright notice in the Description page of Project Settings.


#include "Spot.h"

// Sets default values
ASpot::ASpot()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("StaticMesh"));
	SetRootComponent(StaticMesh);
	FoodSpot = CreateDefaultSubobject<UStaticMeshComponent>(FName("FoodSpot"));
	FoodSpot->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void ASpot::BeginPlay()
{
	Super::BeginPlay();
	
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
	Occupied = true;
}

void ASpot::SetSpotFree()
{
	Occupied = false;
}

FTransform ASpot::GetFoodSpotTransform() {
	return FoodSpot->GetComponentTransform();
}
