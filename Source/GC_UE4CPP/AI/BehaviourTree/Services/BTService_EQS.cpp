// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_EQS.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "EnvironmentQuery/EnvQueryManager.h"
#include "GC_UE4CPP/AI/EnemyController.h"

UBTService_EQS::UBTService_EQS(const FObjectInitializer& ObjectInitializer)
{
	NodeName = TEXT("Custom EQS Query");
}

void UBTService_EQS::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	if (EnemyAI != OwnerComp.GetAIOwner())
	{
		EnemyAI = Cast<AEnemyController>(OwnerComp.GetAIOwner());
	}

	if (EnemyAI)
	{
		
		RunQuery();
		if (Score >= ScoreThreshold)
		{
			EnemyAI->GetBlackboardComponent()->SetValueAsBool("SeesPlayer", true);
			EnemyAI->GetBlackboardComponent()->SetValueAsVector("EQS_Score", MoveLocation);
		}
		else
		{
			EnemyAI->GetBlackboardComponent()->SetValueAsBool("SeesPlayer", false);
		}
	}
}

void UBTService_EQS::RunQuery()
{
	FEnvQueryRequest HidingSpotQueryRequest = FEnvQueryRequest(FindHidingSpotEQS, EnemyAI);

	HidingSpotQueryRequest.Execute(EEnvQueryRunMode::AllMatching, this, &UBTService_EQS::HandleQueryResult);
	MoveTemp(HidingSpotQueryRequest);
}

void UBTService_EQS::HandleQueryResult(TSharedPtr<FEnvQueryResult> result)
{
	Score = result->GetItemScore(0);
	MoveLocation = result->GetItemAsLocation(0);
}