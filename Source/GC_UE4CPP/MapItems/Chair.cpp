// Fill out your copyright notice in the Description page of Project Settings.


#include "Chair.h"

#include "Kismet/GameplayStatics.h"

#include "GC_UE4CPP/Characters/SitDownAbilityComponent.h"
#include "GC_UE4CPP/Game/MainGameMode.h"

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

void AChair::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	
	if (SitTimer > 0) {
		SitTimer -= DeltaTime;
		if (SitTimer <= 0) {
			AMainGameMode* GameMode = Cast<AMainGameMode>(UGameplayStatics::GetGameMode(this));
			if (GameMode) {
				GameMode->EndGameVictory();
			}
			else {
				UE_LOG(LogTemp, Error, TEXT("Chair couldn’t end game : cast game mode to MainGameMode failed"));
			}
		}
	}
}

void AChair::OnInteract(AActor* Caller) {
	if (!Caller) {
		UE_LOG(LogTemp, Warning, TEXT("nullptr can’t use a chair"));
		return;
	}
	USitDownAbilityComponent* SitDownAbility = Caller->FindComponentByClass<USitDownAbilityComponent>();
	if (SitDownAbility) {
		if (SitDownAbility->IsSitDown) {
			SitDownAbility->StandUp();
			SitTimer = -1;
		}
		else {
			SitDownAbility->GetOwner()->SetActorLocation(PlayerTransform->GetComponentLocation());
			SitDownAbility->GetOwner()->SetActorRotation(PlayerTransform->GetComponentRotation());
			SitDownAbility->SitDown(this);
			SitTimer = WaitingTimeToWin;
		}
	}
}

FTransform AChair::GetPreAnimationPlayerTransform() {
	return PlayerTransform->GetComponentTransform();
}

