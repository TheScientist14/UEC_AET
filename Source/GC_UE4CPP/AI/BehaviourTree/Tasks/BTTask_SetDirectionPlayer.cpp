// Fill out your copyright notice in the Description page of Project Settings.


#include "GC_UE4CPP/AI/BehaviourTree/Tasks/BTTask_SetDirectionPlayer.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Character.h"
#include "GC_UE4CPP/AI/EnemyController.h"
#include "Kismet/GameplayStatics.h"

UBTTask_SetDirectionPlayer::UBTTask_SetDirectionPlayer(FObjectInitializer const& object_initialize)
{
	NodeName = "Set Direction Player";
}

EBTNodeResult::Type UBTTask_SetDirectionPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{	
	AEnemyController* EnemyAI = Cast<AEnemyController>(OwnerComp.GetAIOwner());

	
	
	FVector Direction = UGameplayStatics::GetPlayerCharacter(this, 0)->GetActorForwardVector();
	Direction *= 5;
	
	if(EnemyAI)
	{
		EnemyAI->GetBlackboardComponent()->SetValueAsVector(BlackboardKey.SelectedKeyName, Direction);
	}
	
	return Super::ExecuteTask(OwnerComp, NodeMemory);

}
