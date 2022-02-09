// Fill out your copyright notice in the Description page of Project Settings.


#include "GoblinCounter.h"

#include "Chaos/GeometryParticlesfwd.h"
#include "Components/BoxComponent.h"
#include "GC_UE4CPP/AI/GoblinCharacter.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AGoblinCounter::AGoblinCounter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>("Goblin Detector");

	SetRootComponent(BoxComponent);
	
}

// Called when the game starts or when spawned
void AGoblinCounter::BeginPlay()
{
	Super::BeginPlay();
	
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AGoblinCounter::OnGoblinApproaching);	
	BoxComponent->OnComponentEndOverlap.AddDynamic(this, &AGoblinCounter::OnGoblinLeaving);	
	
}

void AGoblinCounter::OnGoblinApproaching(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AGoblinCharacter* GoblinCharacter = Cast<AGoblinCharacter>(OtherActor);
	if(GoblinCharacter)
	{
		GoblinsNotInSpawn.Remove(GoblinCharacter);
	}
}

void AGoblinCounter::OnGoblinLeaving(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	AGoblinCharacter* GoblinCharacter = Cast<AGoblinCharacter>(OtherActor);
	if(GoblinCharacter)
	{
		GoblinsNotInSpawn.Add(GoblinCharacter);
	}
}

int AGoblinCounter::GetNbGoblinsNotInSpawn()
{

	return GoblinsNotInSpawn.Num();
	
}

