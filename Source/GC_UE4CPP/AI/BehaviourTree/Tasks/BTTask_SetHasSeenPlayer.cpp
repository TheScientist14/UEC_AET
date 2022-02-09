// Fill out your copyright notice in the Description page of Project Settings.


#include "GC_UE4CPP/AI/BehaviourTree/Tasks/BTTask_SetHasSeenPlayer.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "GC_UE4CPP/AI/EnemyController.h"

UBTTask_SetHasSeenPlayer::UBTTask_SetHasSeenPlayer(FObjectInitializer const& object_initialize)
{
	NodeName = "Set Has Seen Player";
}

EBTNodeResult::Type UBTTask_SetHasSeenPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AEnemyController* EnemyAI = Cast<AEnemyController>(OwnerComp.GetAIOwner());
	if(EnemyAI)
	{
		if (EnemyAI->GetBlackboardComponent()->GetValueAsBool("HasSeenPlayer"))
		{
			EnemyAI->GetBlackboardComponent()->SetValueAsBool("HasSeenPlayer", false);
		} else
		{
			EnemyAI->GetBlackboardComponent()->SetValueAsBool("HasSeenPlayer", true);
		}
	}
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}
