// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_Wait.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIC_Enemy.h"
#include "Goblin.h"

UBTT_Wait::UBTT_Wait(FObjectInitializer const& object_initialize)
{
	NodeName = TEXT("WaitActor");
}

EBTNodeResult::Type UBTT_Wait::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIC_Enemy* EnemyAI = Cast<AAIC_Enemy>(OwnerComp.GetAIOwner());
	
	EnemyAI->GetBlackboardComponent()->SetValueAsBool("Wait", true);
	Cast<AGoblin>(EnemyAI->GetPawn())->Wait = true;
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}
