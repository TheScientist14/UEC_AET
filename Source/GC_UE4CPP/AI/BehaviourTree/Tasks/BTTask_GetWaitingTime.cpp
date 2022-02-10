// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_GetWaitingTime.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "GC_UE4CPP/AI/EnemyController.h"
#include "GC_UE4CPP/AI/GoblinCharacter.h"
#include "GC_UE4CPP/MapItems/GoblinCounter.h"

UBTTask_GetWaitingTime::UBTTask_GetWaitingTime(FObjectInitializer const& object_initialize)
{
	NodeName = "Get Waiting Time";
}

EBTNodeResult::Type UBTTask_GetWaitingTime::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AEnemyController* EnemyAI = Cast<AEnemyController>(OwnerComp.GetAIOwner());


	if (EnemyAI)
	{
		AGoblinCharacter* GoblinCharacter = Cast<AGoblinCharacter>(EnemyAI->GetPawn());

		if(GoblinCharacter && GoblinCharacter->GoblinCounter && GoblinCharacter->GoblinCounter->GetNbGoblinsNotInSpawn() == 0)
		{
			EnemyAI->GetBlackboardComponent()->SetValueAsFloat("WaitingTime", 0);
		}
		else
		{
			EnemyAI->GetBlackboardComponent()->SetValueAsFloat("WaitingTime", FMath::RandRange(0, 5));
		}
		
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}
