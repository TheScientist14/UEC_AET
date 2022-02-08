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
	GoblinDetector->OnComponentBeginOverlap.AddDynamic(this, &AGoblinDoor::OnGoblinApproaching);
	GoblinDetector->OnComponentEndOverlap.AddDynamic(this, &AGoblinDoor::OnGoblinLeaving);
}

void AGoblinDoor::OnGoblinApproaching(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	if (Cast<AGoblinCharacter>(OtherActor)) {
		//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::White, "Goblin door need to open");
		if(!CloseGoblins.Contains(OtherActor)){
			if(CloseGoblins.Num() == 0){
				Open();
			}
			CloseGoblins.Add(OtherActor);
		}
	}
}

void AGoblinDoor::OnGoblinLeaving(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
	if (CloseGoblins.Remove(OtherActor)) {
		if (CloseGoblins.Num() == 0) {
			Close();
		}
	}
}

void AGoblinDoor::OnOpened() {
}