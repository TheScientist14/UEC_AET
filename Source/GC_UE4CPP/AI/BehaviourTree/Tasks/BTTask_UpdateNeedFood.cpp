// Fill out your copyright notice in the Description page of Project Settings.


#include "GC_UE4CPP/AI/BehaviourTree/Tasks/BTTask_UpdateNeedFood.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "GC_UE4CPP/AI/EnemyController.h"
#include "GC_UE4CPP/Game/MainGameMode.h"

UBTTask_UpdateNeedFood::UBTTask_UpdateNeedFood(FObjectInitializer const& object_initialize)
{
	NodeName = "UpdateNeedFood";
}

EBTNodeResult::Type UBTTask_UpdateNeedFood::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AEnemyController* EnemyAI = Cast<AEnemyController>(OwnerComp.GetAIOwner());
	if(EnemyAI)
	{
		EnemyAI->GetBlackboardComponent()->SetValueAsBool("NeedFood", Cast<AMainGameMode>(GetWorld()->GetAuthGameMode())->NeedsFood());
	}

	return EBTNodeResult::Succeeded;
}