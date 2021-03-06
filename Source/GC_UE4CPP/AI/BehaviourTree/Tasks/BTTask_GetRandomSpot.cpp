// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_GetRandomSpot.h"


#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "blackboard_keys.h"
#include "GC_UE4CPP/AI/EnemyController.h"
#include "GC_UE4CPP/AI/GoblinCharacter.h"
#include "GC_UE4CPP/Game/MainGameMode.h"
#include "GC_UE4CPP/Game/MainGameState.h"
#include "GC_UE4CPP/MapItems/Spot.h"


UBTTask_GetRandomSpot::UBTTask_GetRandomSpot(FObjectInitializer const& object_initialize)
{
	NodeName = "Get Random Spot";
}

EBTNodeResult::Type UBTTask_GetRandomSpot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//Move to init 
	AGoblinCharacter* const Goblin = Cast<AGoblinCharacter>(OwnerComp.GetAIOwner()->GetPawn());

	AEnemyController* EnemyAI = Cast<AEnemyController>(OwnerComp.GetAIOwner());
	AMainGameMode* GameMode = Cast<AMainGameMode>(GetWorld()->GetAuthGameMode());

	if (EnemyAI)
	{
		UE_LOG(LogTemp, Error, TEXT("%d"), GameMode->MainGameState->Spots.Num())
		Goblin->GetNextSpot();
		EnemyAI->GetBlackboardComponent()->SetValueAsVector("Spot", Goblin->Spot->GetActorLocation());
		
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
