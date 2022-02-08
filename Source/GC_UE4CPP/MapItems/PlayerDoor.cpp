// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerDoor.h"
#include "Components/BoxComponent.h"

// Sets default values
APlayerDoor::APlayerDoor()
{
	InteractionReceiver = CreateDefaultSubobject<UBoxComponent>(TEXT("Overlap listener"));
	InteractionReceiver->SetCollisionProfileName("OverlapAllDynamic");
	InteractionReceiver->SetupAttachment(DoorMesh);
}

void APlayerDoor::OnInteract(AActor* Caller) {
	Open();
}

