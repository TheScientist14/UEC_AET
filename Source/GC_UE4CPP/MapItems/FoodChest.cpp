// Fill out your copyright notice in the Description page of Project Settings.


#include "FoodChest.h"

#include "GC_UE4CPP/Characters/PlayerCharacter.h"
#include "GC_UE4CPP/Game/MainGameMode.h"

// Sets default values
AFoodChest::AFoodChest()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	MeshChest = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Chest Body"));
	SetRootComponent(MeshChest);

	MeshLid = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Chest Lid"));

	MeshLid->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void AFoodChest::BeginPlay()
{
	Super::BeginPlay();

	GameMode = Cast<AMainGameMode>(GetWorld()->GetAuthGameMode());
}

// Called every frame
void AFoodChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFoodChest::OnInteract(AActor* Caller)
{
	GameMode->AddStashedFood();
	APlayerCharacter* Player = Cast<APlayerCharacter>(Caller);

	if (Player)
	{
		Player->PutDownPickedUpActor();
	}
}
