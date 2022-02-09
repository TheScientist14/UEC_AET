// Fill out your copyright notice in the Description page of Project Settings.


#include "CrateClump.h"

// Sets default values
ACrateClump::ACrateClump()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	SetRootComponent(SceneRootComponent);

	StaticMesh1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh1"));
	StaticMesh2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh2"));
	StaticMesh3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh3"));
	StaticMesh4 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh4"));
	StaticMesh5 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh5"));
	StaticMesh6 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh6"));

	LightBlocker1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LightBlocker1"));
	LightBlocker2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LightBlocker2"));
	LightBlocker3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LightBlocker3"));
	LightBlocker4 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LightBlocker4"));
	LightBlocker5 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LightBlocker5"));
	LightBlocker6 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LightBlocker6"));

	TArray<UStaticMeshComponent*> Meshes = { StaticMesh1, StaticMesh2, StaticMesh3, StaticMesh4, StaticMesh5, StaticMesh6 };
	TArray<UStaticMeshComponent*> LightBlockers = { LightBlocker1, LightBlocker2, LightBlocker3, LightBlocker4, LightBlocker5, LightBlocker6 };

	for (int i = 0; i < Meshes.Num(); i++)
	{
		Meshes[i]->SetupAttachment(RootComponent);
		LightBlockers[i]->SetupAttachment(Meshes[i]);
		LightBlockers[i]->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		LightBlockers[i]->bHiddenInGame = true;
		LightBlockers[i]->bCastHiddenShadow = true;
	}
	
}

// Called when the game starts or when spawned
void ACrateClump::BeginPlay()
{
	Super::BeginPlay();
}