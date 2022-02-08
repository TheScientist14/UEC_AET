// Fill out your copyright notice in the Description page of Project Settings.


#include "GC_UE4CPP/AI/BehaviourTree/Tasks/BTTask_SetBoolValue.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "GC_UE4CPP/AI/EnemyController.h"

UBTTask_SetBoolValue::UBTTask_SetBoolValue(FObjectInitializer const& object_initialize)
{
	NodeName = "Change bool value";
}

EBTNodeResult::Type UBTTask_SetBoolValue::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	AEnemyController* EnemyAI = Cast<AEnemyController>(OwnerComp.GetAIOwner());
	
	
	if(EnemyAI)
	{
		EnemyAI->GetBlackboardComponent()->SetValueAsBool(BlackboardKey.SelectedKeyName, Value);
	}

	
	return EBTNodeResult::Succeeded;
}
