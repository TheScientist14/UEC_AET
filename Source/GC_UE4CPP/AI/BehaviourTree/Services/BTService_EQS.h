// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_EQS.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API UBTService_EQS : public UBTService_BlackboardBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EQS")
	class UEnvQuery* FindHidingSpotEQS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="EQS")
	float ScoreThreshold = 0.94;


	UBTService_EQS(const FObjectInitializer& ObjectInitializer);
	
	void HandleQueryResult(TSharedPtr<struct FEnvQueryResult> result);

	void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	void RunQuery();

private:
	float Score;
	FVector MoveLocation;
	UPROPERTY()
	class AEnemyController* EnemyAI;
	
	
};
