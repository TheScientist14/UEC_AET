// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_PickUpFood.h"


#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "blackboard_keys.h"
#include "GC_UE4CPP/AI/EnemyController.h"
#include "GC_UE4CPP/AI/GoblinCharacter.h"
#include "GC_UE4CPP/Game/MainGameMode.h"
#include "GC_UE4CPP/MapItems/Spot.h"


UBTTask_PickUpFood::UBTTask_PickUpFood(FObjectInitializer const& object_initialize)
{
	NodeName = TEXT("PickUpFood");
}

EBTNodeResult::Type UBTTask_PickUpFood::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//Move to init 
	auto const cont = Cast<AGoblinCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	cont->PickUpFood(cont->Food);
	Cast<AEnemyController>(cont->GetController())->GetBlackboardComponent()->SetValueAsBool("HasFood", true);
	
	return EBTNodeResult::Succeeded;
}