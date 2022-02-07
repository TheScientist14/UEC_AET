// Fill out your copyright notice in the Description page of Project Settings.


#include "GC_UE4CPP/AI/BehaviourTree/Tasks/BTTask_DontNeedFood.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "GC_UE4CPP/AI/EnemyController.h"
#include "GC_UE4CPP/AI/GoblinCharacter.h"
#include "GC_UE4CPP/Game/MainGameMode.h"
#include "Kismet/GameplayStatics.h"

UBTTask_DontNeedFood::UBTTask_DontNeedFood(FObjectInitializer const& object_initialize)
{
	NodeName = "DontNeedFood";
}

EBTNodeResult::Type UBTTask_DontNeedFood::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AEnemyController* EnemyAI = Cast<AEnemyController>(OwnerComp.GetAIOwner());
	if(EnemyAI)
	{
		EnemyAI->GetBlackboardComponent()->SetValueAsBool("NeedFood", Cast<AMainGameMode>(GetWorld()->GetAuthGameMode())->NeedsFood());
	}

	return EBTNodeResult::Succeeded;
}