// Fill out your copyright notice in the Description page of Project Settings.


#include "GC_UE4CPP/AI/BehaviourTree/Tasks/BTTask_StopWaiting.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "GC_UE4CPP/AI/EnemyController.h"
#include "GC_UE4CPP/AI/GoblinCharacter.h"

UBTTask_StopWaiting::UBTTask_StopWaiting(FObjectInitializer const& object_initialize)
{
	NodeName = "Stop Waiting";
}

EBTNodeResult::Type UBTTask_StopWaiting::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AGoblinCharacter* const GoblinCharacter = Cast<AGoblinCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	AEnemyController* EnemyAI = Cast<AEnemyController>(OwnerComp.GetAIOwner());

	if(EnemyAI)
	{	
		EnemyAI->GetBlackboardComponent()->SetValueAsBool("Wait", false);
		GoblinCharacter->Wait = false;
		return EBTNodeResult::Succeeded;
	}
	
	return EBTNodeResult::Failed;
}
