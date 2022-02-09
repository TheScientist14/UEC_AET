// Fill out your copyright notice in the Description page of Project Settings.


#include "GC_UE4CPP/AI/BehaviourTree/Tasks/BTTask_EndGame.h"

#include "EnvironmentQuery/Tests/EnvQueryTest_Distance.h"
#include "GC_UE4CPP/AI/EnemyController.h"
#include "GC_UE4CPP/AI/GoblinCharacter.h"
#include "GC_UE4CPP/Game/MainGameMode.h"
#include "Kismet/GameplayStatics.h"

UBTTask_EndGame::UBTTask_EndGame(FObjectInitializer const& object_initialize)
{
	NodeName = "End Game";
}

EBTNodeResult::Type UBTTask_EndGame::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AGoblinCharacter* const GoblinCharacter = Cast<AGoblinCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	AEnemyController* EnemyAI = Cast<AEnemyController>(OwnerComp.GetAIOwner());
	if (GoblinCharacter->GetDistanceTo(UGameplayStatics::GetPlayerCharacter(this, 0)) <= Distance)
	{
		Cast<AMainGameMode>(GetWorld()->GetAuthGameMode())->EndGameDefeat();
	}

	return EBTNodeResult::Succeeded;
}