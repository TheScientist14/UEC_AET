// Fill out your copyright notice in the Description page of Project Settings.


#include "Goblin.h"

#include "AIC_Enemy.h"
#include "Food.h"
#include "GC_UE4CPPGameModeBase.h"
#include "Spawner.h"
#include "GC_UE4CPP/GC_UE4CPPGameState.h"
#include "Spot.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AGoblin::AGoblin()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGoblin::BeginPlay()
{
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(1, 5.0f, FColor::Black, TEXT("BeginPlay Goblin"));
	GameState = Cast<AGC_UE4CPPGameState>(GetWorld()->GetGameState());
	GetNextSpot();
	Cast<AAIC_Enemy>(GetController())->GetBlackboardComponent()->SetValueAsVector("Spawn", GetActorLocation());
	Cast<AAIC_Enemy>(GetController())->GetBlackboardComponent()->SetValueAsBool("Wait", Wait);
		
	SpawnFood(Food);
}

// Called every frame
void AGoblin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AGoblin::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AGoblin::GetNextSpot()
{
	Spot = Cast<AGC_UE4CPPGameModeBase>(GetWorld()->GetAuthGameMode())->GetRandomSpot();
}

void AGoblin::SpawnFood(UClass* PrmFood)
{
	AFood* FoodOnHand = Cast<AFood>(GetWorld()->SpawnActor<AActor>(PrmFood, FVector(0.f), FRotator(0.f)));

	//FoodOnHand->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform, "Fist_R_endSocket");
}