// Fill out your copyright notice in the Description page of Project Settings.

#include "Food.h"

// Sets default values
AFood::AFood()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("StaticMesh"));
	SetRootComponent(StaticMesh);
}

void AFood::OnInteract()
{

	GEngine->AddOnScreenDebugMessage(1, 5, FColor::Red, "Picked up");
}