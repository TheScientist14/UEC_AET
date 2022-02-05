// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_MoveToSpawn.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GC_UE4CPP/AI/EnemyController.h"
#include "GC_UE4CPP/AI/GoblinCharacter.h"

UBTT_MoveToSpawn::UBTT_MoveToSpawn(FObjectInitializer const& object_initialize)
{
	NodeName = TEXT("ReturnToSpawn");
}

EBTNodeResult::Type UBTT_MoveToSpawn::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto const cont = Cast<AGoblinCharacter>(OwnerComp.GetAIOwner()->GetPawn());

	AEnemyController* EnemyAI = Cast<AEnemyController>(OwnerComp.GetAIOwner());

	if(EnemyAI)
	{
		EnemyAI->GetBlackboardComponent()->SetValueAsVector("Spawn", cont->Spawn);
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
