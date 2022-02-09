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
	NodeName = "Putting Down Food";
}

EBTNodeResult::Type UBTTask_PuttingDownFood::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//Move to init 
	AGoblinCharacter* const GoblinCharacter = Cast<AGoblinCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	AEnemyController* EnemyAI = Cast<AEnemyController>(OwnerComp.GetAIOwner());
	if (EnemyAI)
	{
		if (!OnSpot)
		{
			GoblinCharacter->PutDownFood();
			EnemyAI->GetBlackboardComponent()->SetValueAsVector("FoodPosition", GoblinCharacter->GetTransform().GetLocation());
		}
		else
		{
			GoblinCharacter->FoodOnHand->OverridePutDownTransform(GoblinCharacter->Spot->GetFoodSpotTransform());
			GoblinCharacter->Spot = nullptr;
			GoblinCharacter->InteractFood();
			
		}
	}
	return EBTNodeResult::Succeeded;
}
