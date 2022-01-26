// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_MoveToRandomSpot.h"

#include "AIC_Enemy.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "blackboard_keys.h"

UBTT_MoveToRandomSpot::UBTT_MoveToRandomSpot(FObjectInitializer const& object_initialize)
{
	NodeName = TEXT("FindRandomSpot");
}

EBTNodeResult::Type UBTT_MoveToRandomSpot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//Move to init 
	auto const cont = Cast<AGoblin>(OwnerComp.GetAIOwner()->GetPawn());

	AAIC_Enemy* EnemyAI = Cast<AAIC_Enemy>(OwnerComp.GetAIOwner());

	if(EnemyAI)
	{
		EnemyAI->GetBlackboardComponent()->SetValueAsVector("Spot", cont->Spot);
		cont->GetNextSpot();
	}
	
	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}