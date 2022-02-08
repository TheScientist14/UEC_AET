// Fill out your copyright notice in the Description page of Project Settings.


#include "GC_UE4CPP/AI/BehaviourTree/Tasks/BTTask_SetHasSeenPlayer.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "GC_UE4CPP/AI/EnemyController.h"

UBTTask_SetHasSeenPlayer::UBTTask_SetHasSeenPlayer(FObjectInitializer const& object_initialize)
{
	NodeName="SetHasSeenPlayer";
}

EBTNodeResult::Type UBTTask_SetHasSeenPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AEnemyController* EnemyAI = Cast<AEnemyController>(OwnerComp.GetAIOwner());
	if(EnemyAI)
	{
		if (EnemyAI->GetBlackboardComponent()->GetValueAsBool("HasSeenPlayer"))
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("HasSeenPlayer false"));
			EnemyAI->GetBlackboardComponent()->SetValueAsBool("HasSeenPlayer", false);
		} else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("HasSeenPlayer true"));
			EnemyAI->GetBlackboardComponent()->SetValueAsBool("HasSeenPlayer", true);
		}
	}
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}
