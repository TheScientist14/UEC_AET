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
	NodeName = "Pick Up Food";
}

EBTNodeResult::Type UBTTask_PickUpFood::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//Move to init 
	AGoblinCharacter* const GoblinCharacter = Cast<AGoblinCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	GoblinCharacter->InteractFood();

	Cast<AEnemyController>(GoblinCharacter->GetController())->GetBlackboardComponent()->ClearValue(BlackboardKey.SelectedKeyName);
	
	return EBTNodeResult::Succeeded;
}