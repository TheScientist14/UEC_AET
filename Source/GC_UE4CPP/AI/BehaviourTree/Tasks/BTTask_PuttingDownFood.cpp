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
	cont->Spot->SpawnFood(cont->Food);
	cont->DestroyFood();
	Cast<AMainGameMode>(GetWorld()->GetAuthGameMode())->AddFood();
	if(Cast<AMainGameState>(GetWorld()->GetGameState())->FoodOnLevel == Cast<AMainGameMode>(GetWorld()->GetAuthGameMode())->GetMaxFoodOnLevel())
	{
		Cast<AEnemyController>(cont->GetController())->GetBlackboardComponent()->SetValueAsBool("NeedFood", false);
	}
	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}