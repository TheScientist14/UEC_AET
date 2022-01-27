// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_MoveToRandomSpot.h"

#include "AIC_Enemy.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "blackboard_keys.h"
#include "GC_UE4CPPGameModeBase.h"

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
		if (Cast<AGC_UE4CPPGameModeBase>(GetWorld()->GetAuthGameMode())->GetFoodOnLevel() < Cast<AGC_UE4CPPGameModeBase>(GetWorld()->GetAuthGameMode())->GetMaxFoodOnLevel())
		{
			cont->GetNextSpot();
			cont->SpawnFood(cont->Food);
			EnemyAI->GetBlackboardComponent()->SetValueAsVector("Spot", cont->Spot->GetActorLocation());
		} else
		{
			EnemyAI->GetBlackboardComponent()->SetValueAsBool("Wait", true);
		}
	}
	
	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}