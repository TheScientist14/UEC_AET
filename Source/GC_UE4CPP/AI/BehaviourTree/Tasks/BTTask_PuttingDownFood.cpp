// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_PuttingDownFood.h"


#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "blackboard_keys.h"
#include "GC_UE4CPP/AI/EnemyController.h"
#include "GC_UE4CPP/AI/GoblinCharacter.h"
#include "GC_UE4CPP/Game/MainGameMode.h"
#include "GC_UE4CPP/MapItems/Spot.h"


UBTTask_PuttingDownFood::UBTTask_PuttingDownFood(FObjectInitializer const& object_initialize)
{
	NodeName = TEXT("PuttingDownFood");
}

EBTNodeResult::Type UBTTask_PuttingDownFood::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//Move to init 
	auto const cont = Cast<AGoblinCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	AEnemyController* EnemyAI = Cast<AEnemyController>(OwnerComp.GetAIOwner());
	if(EnemyAI)
	{
		if (!OnSpot)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("PuttingDownFood !OnSpot"));
			Cast<AEnemyController>(cont->GetController())->GetBlackboardComponent()->SetValueAsVector("FoodPosition", cont->GetTransform().GetLocation());
		} else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("PuttingDownFood OnSpot"));
			
			cont->Spot = nullptr;
			Cast<AEnemyController>(cont->GetController())->GetBlackboardComponent()->ClearValue("FoodPosition");
		}
		cont->InteractFood();
		Cast<AEnemyController>(cont->GetController())->GetBlackboardComponent()->SetValueAsBool("HasFood", false);

		EnemyAI->GetBlackboardComponent()->ClearValue("Spot");
		cont->Spot = nullptr;
	}
	return EBTNodeResult::Succeeded;
}