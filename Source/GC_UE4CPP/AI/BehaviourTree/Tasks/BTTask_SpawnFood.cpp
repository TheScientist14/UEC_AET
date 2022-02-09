// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_SpawnFood.h"
#include "GC_UE4CPP/AI/BehaviourTree/Tasks/BTTask_SpawnFood.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "GC_UE4CPP/AI/EnemyController.h"
#include "GC_UE4CPP/AI/GoblinCharacter.h"
#include "GC_UE4CPP/Game/MainGameMode.h"

UBTTask_SpawnFood::UBTTask_SpawnFood(FObjectInitializer const& object_initialize)
{
	NodeName = "Spawn Food";
}

EBTNodeResult::Type UBTTask_SpawnFood::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("SpawnFood"));
	//Move to init 
	AGoblinCharacter* const Goblin = Cast<AGoblinCharacter>(OwnerComp.GetAIOwner()->GetPawn());

	if(Goblin)
	{
		Goblin->SpawnFood(Goblin->Food);
		return EBTNodeResult::Succeeded;
	}
	
	return EBTNodeResult::Failed;
}