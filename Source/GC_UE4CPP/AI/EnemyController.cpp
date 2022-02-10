// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyController.h"


#include "GoblinCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GC_UE4CPP/MapItems/ProceduralRoom.h"

AEnemyController::AEnemyController(FObjectInitializer const& object_initializer)
{
}

void AEnemyController::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemyController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	
	GoblinCharacter = Cast<AGoblinCharacter>(InPawn);
	if(GoblinCharacter && GoblinCharacter->ProceduralRoom)
	{
		GoblinCharacter->ProceduralRoom->RoomHasGenerated.AddUObject(this, &AEnemyController::StartAI);
	}
}

void AEnemyController::StartAI(){
	RunBehaviorTree(BehaviourTree);
	
	if (GoblinCharacter)
	{
		if (GetBlackboardComponent())
		{
			GetBlackboardComponent()->SetValueAsObject("Player", UGameplayStatics::GetPlayerCharacter(this, 0));
			GetBlackboardComponent()->SetValueAsVector("Spawn", GoblinCharacter->GetActorLocation());
			GetBlackboardComponent()->SetValueAsBool("Wait", GoblinCharacter->Wait);
			GetBlackboardComponent()->SetValueAsBool("NeedFood", true);
		}
	}
}
