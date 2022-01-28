// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_EQSRequest.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API UBTT_GetEQSPointScore : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EQS")
	class UEnvQuery* FindHidingSpotEQS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="EQS")
	float ScoreThreshold = 0.94;

	UBTT_GetEQSPointScore(FObjectInitializer const& object_initialize);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
	void RunQuery();
	void HandleQueryResult(TSharedPtr<struct FEnvQueryResult> result);

private:
	float Score;
	FVector MoveLocation;
	UPROPERTY()
	class AEnemyController* EnemyAI;
};
