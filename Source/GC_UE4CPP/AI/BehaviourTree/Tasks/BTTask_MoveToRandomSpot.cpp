// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_MoveToRandomSpot.h"


#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "blackboard_keys.h"
#include "GC_UE4CPP/AI/EnemyController.h"
#include "GC_UE4CPP/AI/GoblinCharacter.h"
#include "GC_UE4CPP/Game/MainGameMode.h"
#include "GC_UE4CPP/MapItems/Spot.h"


UBTTask_MoveToRandomSpot::UBTTask_MoveToRandomSpot(FObjectInitializer const& object_initialize)
{
	NodeName = TEXT("FindRandomSpot");
}

EBTNodeResult::Type UBTTask_MoveToRandomSpot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//Move to init 
	auto const cont = Cast<AGoblinCharacter>(OwnerComp.GetAIOwner()->GetPawn());

	AEnemyController* EnemyAI = Cast<AEnemyController>(OwnerComp.GetAIOwner());

	if(EnemyAI)
	{
		if (Cast<AMainGameMode>(GetWorld()->GetAuthGameMode())->GetFoodOnLevel() < Cast<AMainGameMode>(GetWorld()->GetAuthGameMode())->GetMaxFoodOnLevel())
		{
			cont->GetNextSpot();
			cont->PickUpFood(cont->Food);
			cont->Spot->SetSpotOccupied();
			EnemyAI->GetBlackboardComponent()->SetValueAsVector("Spot", cont->Spot->GetActorLocation());
		} else
		{
			EnemyAI->GetBlackboardComponent()->SetValueAsBool("Wait", true);
		}
	}
	
	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}