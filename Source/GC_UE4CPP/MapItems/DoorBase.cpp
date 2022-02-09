// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorBase.h"

// Sets default values
ADoorBase::ADoorBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DoorPivot = CreateDefaultSubobject<USceneComponent>(TEXT("Door Pivot"));
	SetRootComponent(DoorPivot);

	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door Mesh"));
	DoorMesh->SetupAttachment(DoorPivot);

	DoorLightBlocker = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Light blocker"));
	DoorLightBlocker->SetupAttachment(DoorMesh);
	DoorLightBlocker->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	DoorLightBlocker->bHiddenInGame = true;
	DoorLightBlocker->bCastHiddenShadow = true;
}

// Called when the game starts or when spawned
void ADoorBase::BeginPlay()
{
	Super::BeginPlay();

	InitEuler = DoorMesh->GetRelativeRotation().Euler();
}

// Called every frame
void ADoorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (OpenTimer > 0) {
		DoorPivot->SetRelativeRotation(FRotator::MakeFromEuler(InitEuler + FVector::UpVector * OpeningAngle * ((TimeToOpen - OpenTimer) / TimeToOpen)));
		OpenTimer -= DeltaTime;
		if (OpenTimer <= 0) {
			OnOpened();
		}
	}
	if (CloseTimer > 0) {
		DoorPivot->SetRelativeRotation(FRotator::MakeFromEuler(InitEuler + FVector::UpVector * OpeningAngle * (CloseTimer / TimeToOpen)));
		CloseTimer -= DeltaTime;
		if (CloseTimer <= 0) {
			OnClosed();
		}
	}
}

void ADoorBase::Open() {
	if (OpenTimer <= 0) {
		DoorMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		OpenTimer = TimeToOpen;
		if (CloseTimer > 0) {
			OpenTimer -= CloseTimer;
		}
		CloseTimer = 0;
		DoorPivot->SetRelativeRotation(FRotator::MakeFromEuler(InitEuler + FVector::UpVector * OpeningAngle * ((TimeToOpen - OpenTimer) / TimeToOpen)));
	}
}

void ADoorBase::Close() {
	if (CloseTimer <= 0) {
		CloseTimer = TimeToOpen;
		if (OpenTimer > 0) {
			CloseTimer -= OpenTimer;
		}
		OpenTimer = 0;
		DoorPivot->SetRelativeRotation(FRotator::MakeFromEuler(InitEuler + FVector::UpVector * OpeningAngle * (CloseTimer / TimeToOpen)));
	}
}

void ADoorBase::OnOpened() {
	Close();
}

void ADoorBase::OnClosed() {
	DoorPivot->SetRelativeRotation(FRotator::MakeFromEuler(InitEuler));
	DoorMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
}

