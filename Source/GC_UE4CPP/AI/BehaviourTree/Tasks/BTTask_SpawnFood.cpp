// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_SpawnFood.h"
#include "GC_UE4CPP/AI/BehaviourTree/Tasks/BTTask_SpawnFood.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "GC_UE4CPP/AI/EnemyController.h"
#include "GC_UE4CPP/AI/GoblinCharacter.h"
#include "GC_UE4CPP/Game/MainGameMode.h"

UBTTask_SpawnFood::UBTTask_SpawnFood(FObjectInitializer const& object_initialize)
{
	NodeName = TEXT("SpawnFood");
}

EBTNodeResult::Type UBTTask_SpawnFood::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("SpawnFood"));
	//Move to init 
	auto const Goblin = Cast<AGoblinCharacter>(OwnerComp.GetAIOwner()->GetPawn());

	AEnemyController* EnemyAI = Cast<AEnemyController>(OwnerComp.GetAIOwner());
	AMainGameMode* GameMode = Cast<AMainGameMode>(GetWorld()->GetAuthGameMode());

	if(EnemyAI)
	{
		Goblin->SpawnFood(Goblin->Food);
		EnemyAI->GetBlackboardComponent()->SetValueAsBool("HasFood", true);
		return EBTNodeResult::Succeeded;
	}
	
	return EBTNodeResult::Failed;
}