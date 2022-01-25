// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "Characters/PlayerCharacter.h"
#include "PickableItem.h"

// Sets default values
APickableItem::APickableItem()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("StaticMesh"));
}

void APickableItem::OnInteract()
{
	GEngine->AddOnScreenDebugMessage(1, 5, FColor::Red, "Picked up");

	Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0))->PickUpActor(this);
}