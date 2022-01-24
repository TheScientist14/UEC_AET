// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_MoveToRandomSpot.h"

#include "AI_Enemie.h"
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

	AAI_Enemie* EnemyAI = Cast<AAI_Enemie>(OwnerComp.GetAIOwner());

	GEngine->AddOnScreenDebugMessage(1, 5.0f, FColor::Black, TEXT("Before if "));
	if(EnemyAI)
	{
		GEngine->AddOnScreenDebugMessage(1, 5.0f, FColor::Black, TEXT("GoToRandomSpot"));
		cont->Spots.EmplaceAt()
		EnemyAI->get_blackboard()->SetValueAsVector("Spot", cont->Spots[FMath::RandRange(0, cont->Spots.Max())]->GetActorLocation());
	}

	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}
