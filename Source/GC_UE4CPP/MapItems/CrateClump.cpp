// Fill out your copyright notice in the Description page of Project Settings.


#include "CrateClump.h"

// Sets default values
ACrateClump::ACrateClump()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(StaticMesh);

	StaticMesh1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh1"));
	StaticMesh2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh2"));
	StaticMesh3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh3"));
	StaticMesh4 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh4"));
	StaticMesh5 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh5"));

	StaticMesh1->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	StaticMesh2->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	StaticMesh3->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	StaticMesh4->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	StaticMesh5->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void ACrateClump::BeginPlay()
{
	Super::BeginPlay();
}