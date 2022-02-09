// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_GetRandomSpot.h"


#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "blackboard_keys.h"
#include "GC_UE4CPP/AI/EnemyController.h"
#include "GC_UE4CPP/AI/GoblinCharacter.h"
#include "GC_UE4CPP/Game/MainGameMode.h"
#include "GC_UE4CPP/MapItems/Spot.h"


UBTTask_GetRandomSpot::UBTTask_GetRandomSpot(FObjectInitializer const& object_initialize)
{
	NodeName = TEXT("GetRandomSpot");
}

EBTNodeResult::Type UBTTask_GetRandomSpot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("FindRandomSpot"));
	//Move to init 
	auto const Goblin = Cast<AGoblinCharacter>(OwnerComp.GetAIOwner()->GetPawn());

	AEnemyController* EnemyAI = Cast<AEnemyController>(OwnerComp.GetAIOwner());
	AMainGameMode* GameMode = Cast<AMainGameMode>(GetWorld()->GetAuthGameMode());

	if (EnemyAI)
	{
		Goblin->GetNextSpot();
		EnemyAI->GetBlackboardComponent()->SetValueAsVector("Spot", Goblin->Spot->GetActorLocation());
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
