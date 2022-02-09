// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleActor.h"

// Sets default values
ASimpleActor::ASimpleActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	SetRootComponent(StaticMesh);

	LightBlocker = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LightBlocker"));
	LightBlocker->SetupAttachment(StaticMesh);
	LightBlocker->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	LightBlocker->bHiddenInGame = true;
	LightBlocker->bCastHiddenShadow = true;
}

