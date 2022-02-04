// Fill out your copyright notice in the Description page of Project Settings.


#include "Chair.h"

//#include 

#include "GC_UE4CPP/Characters/SitDownAbilityComponent.h"

// Sets default values
AChair::AChair()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ChairStaticMesh"));
	StaticMesh->SetupAttachment(RootComponent);

	PlayerTransform = CreateDefaultSubobject<USceneComponent>(TEXT("PlayerTransform"));
	PlayerTransform->SetupAttachment(StaticMesh);
}

void AChair::OnInteract(AActor* Caller) {
	if (!Caller) {
		UE_LOG(LogTemp, Error, TEXT("nullptr can’t use a chair"));
		return;
	}
	USitDownAbilityComponent* SitDownAbility = Caller->FindComponentByClass<USitDownAbilityComponent>();
	if (SitDownAbility) {
		if (SitDownAbility->IsSitDown) {
			SitDownAbility->StandUp();
		}
		else {
			SitDownAbility->GetOwner()->SetActorLocation(PlayerTransform->GetComponentLocation());
			SitDownAbility->GetOwner()->SetActorRotation(PlayerTransform->GetComponentRotation());
			SitDownAbility->SitDown(this);
		}
	}
}

FTransform AChair::GetPreAnimationPlayerTransform() {
	return PlayerTransform->GetComponentTransform();
}

