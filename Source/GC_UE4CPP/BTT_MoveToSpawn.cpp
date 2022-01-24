// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_MoveToSpawn.h"

#include "AIController.h"
#include "AI_Enemy.h"
#include "Goblin.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTT_MoveToSpawn::UBTT_MoveToSpawn(FObjectInitializer const& object_initialize)
{
	NodeName = TEXT("ReturnToSpawn");
}

EBTNodeResult::Type UBTT_MoveToSpawn::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto const cont = Cast<AGoblin>(OwnerComp.GetAIOwner()->GetPawn());

	AAI_Enemy* EnemyAI = Cast<AAI_Enemy>(OwnerComp.GetAIOwner());

	if(EnemyAI)
	{
		EnemyAI->GetBlackboardComponent()->SetValueAsVector("Spawn", cont->Spawn);
	}

	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}
