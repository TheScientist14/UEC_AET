// Fill out your copyright notice in the Description page of Project Settings.


#include "GC_UE4CPP/AI/BehaviourTree/Tasks/BTTask_MoveToRandomPoint.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GC_UE4CPP/AI/EnemyController.h"
#include "GC_UE4CPP/AI/GoblinCharacter.h"
#include "GC_UE4CPP/Game/MainGameMode.h"
#include "GC_UE4CPP/MapItems/Spot.h"


UBTTask_MoveToRandomPoint::UBTTask_MoveToRandomPoint(FObjectInitializer const& object_initialize)
{
	NodeName = "MoveToRandomPoint";

	NavSystem = UNavigationSystemV1::GetCurrent(GetWorld());
}

EBTNodeResult::Type UBTTask_MoveToRandomPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//Move to init 
	auto const cont = Cast<AGoblinCharacter>(OwnerComp.GetAIOwner()->GetPawn());

	AEnemyController* EnemyAI = Cast<AEnemyController>(OwnerComp.GetAIOwner());

	if(EnemyAI)
	{
		NavSystem->GetRandomPoint(RandomPoint);
		EnemyAI->GetBlackboardComponent()->SetValueAsVector("RandomPoint", RandomPoint.Location);
		return EBTNodeResult::Succeeded;
	}
	
	return EBTNodeResult::Failed;
}
