// Fill out your copyright notice in the Description page of Project Settings.


#include "GoblinCharacter.h"
#include "EnemyController.h"
#include "GC_UE4CPP/Game/MainGameState.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GC_UE4CPP/Characters/PickUpAbilityComponent.h"
#include "GC_UE4CPP/Game/MainGameMode.h"
#include "GC_UE4CPP/MapItems/PickableItem.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AGoblinCharacter::AGoblinCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	PickUpAbilityComponent = CreateDefaultSubobject<UPickUpAbilityComponent>(TEXT("PickUpBehaviour"));
}

// Called when the game starts or when spawned
void AGoblinCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	GameState = Cast<AMainGameState>(GetWorld()->GetGameState());
	Cast<AEnemyController>(GetController())->GetBlackboardComponent()->SetValueAsVector("Spawn", GetActorLocation());
	Cast<AEnemyController>(GetController())->GetBlackboardComponent()->SetValueAsBool("Wait", Wait);
	Cast<AEnemyController>(GetController())->GetBlackboardComponent()->SetValueAsBool("NeedFood", true);

}

// Called every frame
void AGoblinCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AGoblinCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AGoblinCharacter::GetNextSpot()
{
	Spot = Cast<AMainGameMode>(GetWorld()->GetAuthGameMode())->GetRandomSpot();
}

void AGoblinCharacter::PickUpFood(UClass* PrmFood)
{
	if (FoodOnHand == nullptr)
	{
		FoodOnHand = GetWorld()->SpawnActor<APickableItem>(PrmFood, FVector(0), FRotator(0));
		FoodOnHand->OnInteract(this);
		/*FoodOnHand->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale,
			"RightHandSocket");*/
	}
}

void AGoblinCharacter::PutDownFood()
{
	if(FoodOnHand)
	{
		FoodOnHand->OnInteract(this);
		FoodOnHand = nullptr;
	} 
}
