// Fill out your copyright notice in the Description page of Project Settings.


#include "GoblinDoor.h"

#include "Components/SphereComponent.h"

#include "GC_UE4CPP/AI/GoblinCharacter.h"

// Sets default values
AGoblinDoor::AGoblinDoor()
{
	PrimaryActorTick.bCanEverTick = true;
	GoblinDetector = CreateDefaultSubobject<USphereComponent>(TEXT("Goblin observer"));
	GoblinDetector->SetupAttachment(RootComponent);
}

void AGoblinDoor::BeginPlay() {
	Super::BeginPlay();
	// Add overlap events
	GoblinDetector->OnComponentBeginOverlap.AddDynamic(this, &AGoblinDoor::OnGoblinApproaching);
	GoblinDetector->OnComponentEndOverlap.AddDynamic(this, &AGoblinDoor::OnGoblinLeaving);
}

void AGoblinDoor::OnGoblinApproaching(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	// Opens the door
	
	if (Cast<AGoblinCharacter>(OtherActor)) {
		if(!CloseGoblins.Contains(OtherActor)){
			if(CloseGoblins.Num() == 0){
				Open();
			}
			CloseGoblins.Add(OtherActor);
		}
	}
}

void AGoblinDoor::OnGoblinLeaving(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
	// Closes the door

	if (CloseGoblins.Remove(OtherActor)) {
		if (CloseGoblins.Num() == 0) {
			Close();
		}
	}
}

// overriding the auto closing
void AGoblinDoor::OnOpened() {
}