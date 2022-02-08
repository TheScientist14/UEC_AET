// Fill out your copyright notice in the Description page of Project Settings.


#include "FoodChest.h"
#include "PickableItem.h"
#include "GC_UE4CPP/Characters/PlayerCharacter.h"
#include "GC_UE4CPP/Characters/PickUpAbilityComponent.h"
#include "GC_UE4CPP/Game/MainGameMode.h"

// Sets default values
AFoodChest::AFoodChest()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	MeshChest = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Chest Body"));
	SetRootComponent(MeshChest);

	Pivot = CreateDefaultSubobject<USceneComponent>(TEXT("Chest Lid Pivot"));
	Pivot->SetupAttachment(RootComponent);

	MeshLid = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Chest Lid"));
	MeshLid->SetupAttachment(Pivot);
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

	if (OpenTimer > 0) {
		Pivot->SetRelativeRotation(FRotator::MakeFromEuler(FVector::BackwardVector * OpenedAngle * ((TimeToOpen - OpenTimer) / TimeToOpen)));
		OpenTimer -= DeltaTime;
		if (OpenTimer <= 0) {
			PlayClosingAnimation();
		}
	}
	if (CloseTimer > 0) {
		Pivot->SetRelativeRotation(FRotator::MakeFromEuler(FVector::BackwardVector * OpenedAngle * (CloseTimer / TimeToOpen)));
		CloseTimer -= DeltaTime;
		if (CloseTimer <= 0) {
			Pivot->SetRelativeRotation(FRotator::ZeroRotator);
		}
	}
}

void AFoodChest::OnInteract(AActor* Caller)
{
	
	Player = Cast<APlayerCharacter>(Caller);

	if (Player && Player->PickUpAbilityComponent->GetPickedUpActor())
	{
		APickableItem* Item = Player->PickUpAbilityComponent->GetPickedUpActor();
		Player->PickUpAbilityComponent->PutDownPickedUpActor();

		DelegateHandle = Player->PickUpAbilityComponent->OnPutDown.AddUObject(this, &AFoodChest::DestroyFood);
		WaitToClose = true;
		PlayOpeningAnimation();
		
		UE_LOG(LogTemp, Warning, TEXT("Interacted with chest"));
	}
}

void AFoodChest::DestroyFood(APickableItem* PrmItem)
{
	PrmItem->Destroy();
	GameMode->AddStashedFood();
	Player->PickUpAbilityComponent->OnPutDown.Remove(DelegateHandle);
	WaitToClose = false;
	if (OpenTimer <= 0) {
		PlayClosingAnimation();
	}
}

void AFoodChest::PlayOpeningAnimation() {
	if (OpenTimer <= 0) {
		OpenTimer = TimeToOpen;
		if (CloseTimer > 0) {
			OpenTimer -= CloseTimer;
		}
		CloseTimer = 0;
		Pivot->SetRelativeRotation(FRotator::MakeFromEuler(FVector::BackwardVector * OpenedAngle * ((TimeToOpen - OpenTimer) / TimeToOpen)));
	}
}

void AFoodChest::PlayClosingAnimation() {
	if (!WaitToClose && CloseTimer <= 0) {
		CloseTimer = TimeToOpen;
		if (OpenTimer > 0) {
			CloseTimer -= OpenTimer;
		}
		OpenTimer = 0;
		Pivot->SetRelativeRotation(FRotator::MakeFromEuler(FVector::BackwardVector * OpenedAngle * (CloseTimer / TimeToOpen)));
	}
}