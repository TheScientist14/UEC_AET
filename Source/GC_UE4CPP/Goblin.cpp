// Fill out your copyright notice in the Description page of Project Settings.


#include "Goblin.h"
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

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("StaticMesh"));

	
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
