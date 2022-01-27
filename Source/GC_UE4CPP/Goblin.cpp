// Fill out your copyright notice in the Description page of Project Settings.


#include "Goblin.h"

#include "AIC_Enemy.h"
#include "Food.h"
#include "GC_UE4CPPGameModeBase.h"
#include "Spawner.h"
#include "GC_UE4CPP/GC_UE4CPPGameState.h"
#include "Spot.h"
#include "Chaos/GeometryParticlesfwd.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AGoblin::AGoblin()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	InteractSphere = CreateDefaultSubobject<USphereComponent>(TEXT("InteractSphere"));
	InteractSphere->SetupAttachment(RootComponent);
	InteractSphere->SetSphereRadius(InteractRange);
	InteractSphere->SetCollisionProfileName(TEXT("OverlapAll"));

	InteractSphere->OnComponentBeginOverlap.AddDynamic(this, &AGoblin::OnComponentEnter);

}

// Called when the game starts or when spawned
void AGoblin::BeginPlay()
{
	Super::BeginPlay();
	
	GameState = Cast<AGC_UE4CPPGameState>(GetWorld()->GetGameState());
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
	FVector HandLocation;
	FRotator HandRotator;
	
	GetMesh()->GetSocketWorldLocationAndRotation("Fist_R_endSocket", HandLocation, HandRotator);
	
	FoodOnHand = GetWorld()->SpawnActor<AActor>(PrmFood, HandLocation, HandRotator);
	FoodOnHand->AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale, "Fist_R_endSocket");
}

void AGoblin::DestroyFood()
{
	if(FoodOnHand)
	{
		FoodOnHand->Destroy();
	}
}

void AGoblin::OnComponentEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	ASpot* SpotInRange = Cast<ASpot>(OtherActor);
	
	GEngine->AddOnScreenDebugMessage(1, 5.0f, FColor::Black, TEXT("SpawnFood Goblin code"));

	if (SpotInRange)
	{
		SpotInRange->SpawnFood(Food);		
	}
}