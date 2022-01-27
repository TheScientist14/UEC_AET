// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_PuttingDownFood.h"

#include "AIC_Enemy.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "blackboard_keys.h"

UBTT_PuttingDownFood::UBTT_PuttingDownFood(FObjectInitializer const& object_initialize)
{
	NodeName = TEXT("PuttingDownFood");
}

EBTNodeResult::Type UBTT_PuttingDownFood::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//Move to init 
	auto const cont = Cast<AGoblin>(OwnerComp.GetAIOwner()->GetPawn());
	cont->Spot->SpawnFood(cont->Food);
	cont->DestroyFood();
	
	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}