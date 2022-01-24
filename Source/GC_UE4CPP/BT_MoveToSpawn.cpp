// Fill out your copyright notice in the Description page of Project Settings.


#include "BT_MoveToSpawn.h"

#include "AIController.h"
#include "AI_Enemie.h"
#include "Goblin.h"
#include "BehaviorTree/BlackboardComponent.h"

UBT_MoveToSpawn::UBT_MoveToSpawn(FObjectInitializer const& object_initialize)
{
	NodeName = TEXT("ReturnToSpawn");
}

EBTNodeResult::Type UBT_MoveToSpawn::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto const cont = Cast<AGoblin>(OwnerComp.GetAIOwner()->GetPawn());

	AAI_Enemie* EnemyAI = Cast<AAI_Enemie>(OwnerComp.GetAIOwner());

	GEngine->AddOnScreenDebugMessage(1, 5.0f, FColor::Black, TEXT("Before if "));
	if(EnemyAI)
	{
		GEngine->AddOnScreenDebugMessage(1, 5.0f, FColor::Black, TEXT("GoToRandomSpot"));

		EnemyAI->get_blackboard()->SetValueAsVector("Spot", cont->Spawn->GetActorLocation());
	}

	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}
