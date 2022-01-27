// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_GetEQSPointScore.h"

#include "AIC_Enemy_EQS.h"
#include "Goblin.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "EnvironmentQuery/EnvQueryManager.h"
#include "EnvironmentQuery/Contexts/EnvQueryContext_Querier.h"
#include "Sections/MovieScene3DTransformSection.h"

UBTT_GetEQSPointScore::UBTT_GetEQSPointScore(FObjectInitializer const& object_initialize)
{
	NodeName = TEXT("Move to point location if Score is >= Score Threshold");
	
}

EBTNodeResult::Type UBTT_GetEQSPointScore::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	
	EnemyAI = Cast<AAIC_Enemy_EQS>(OwnerComp.GetAIOwner());
	
	RunQuery();
	if( Score >= ScoreThreshold)
	{
		EnemyAI->GetBlackboardComponent()->SetValueAsBool("SeesPlayer", true);
		EnemyAI->MoveToLocation(MoveLocation, 100,true, true, true, true, nullptr, false );
	}
	else
	{
		EnemyAI->GetBlackboardComponent()->SetValueAsBool("SeesPlayer", false);
	}
	
	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}

void UBTT_GetEQSPointScore::RunQuery()
{
	
	FEnvQueryRequest HidingSpotQueryRequest = FEnvQueryRequest(FindHidingSpotEQS, EnemyAI);
	
	HidingSpotQueryRequest.Execute(EEnvQueryRunMode::AllMatching, this, &UBTT_GetEQSPointScore::HandleQueryResult);
	MoveTemp(HidingSpotQueryRequest);
}

void UBTT_GetEQSPointScore::HandleQueryResult(TSharedPtr<FEnvQueryResult> result)
{
	Score = result->GetItemScore(0);
	MoveLocation = result->GetItemAsLocation(0);

	EnemyAI->GetBlackboardComponent()->SetValueAsFloat("EQS_Score",Score);
	
}
