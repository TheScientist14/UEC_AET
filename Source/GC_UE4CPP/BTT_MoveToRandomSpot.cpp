// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_MoveToRandomSpot.h"

#include "AI_Enemy.h"
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

	AAI_Enemy* EnemyAI = Cast<AAI_Enemy>(OwnerComp.GetAIOwner());

	if(EnemyAI)
	{
		GEngine->AddOnScreenDebugMessage(1, 5.0f, FColor::Black, TEXT("GoToRandomSpot"));
		GEngine->AddOnScreenDebugMessage(1, 5.0f, FColor::Black, cont->GetName());
		EnemyAI->GetBlackboardComponent()->SetValueAsVector("Spot", cont->Spot->GetActorLocation());
	} else
	{
		GEngine->AddOnScreenDebugMessage(1, 5.0f, FColor::Black, TEXT("cast failed"));
	}

	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}