// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIC_Enemy.h"
#include "Goblin.h"
#include "AIC_Enemy_EQS.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "Components/InputKeySelector.h"
#include "EnvironmentQuery/EnvQuery.h"
#include "BTT_GetEQSPointScore.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API UBTT_GetEQSPointScore : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EQS")
	UEnvQuery *FindHidingSpotEQS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="EQS")
	float ScoreThreshold = 0.94;
	
	UBTT_GetEQSPointScore(FObjectInitializer const& object_initialize);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
	void RunQuery();
	void HandleQueryResult(TSharedPtr<FEnvQueryResult> result);

private:
	float Score;
	FVector MoveLocation;
	AAIC_Enemy* EnemyAI;
	
};
