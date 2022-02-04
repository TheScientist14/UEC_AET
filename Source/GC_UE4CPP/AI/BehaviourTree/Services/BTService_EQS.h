// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "EnvironmentQuery/EnvQueryManager.h"
#include "BTService_EQS.generated.h"

struct CustomFBTEQSServiceMemory
{
	/** Query request ID */
	int32 RequestID;
};

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

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	virtual void OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual uint16 GetInstanceMemorySize() const override { return sizeof(CustomFBTEQSServiceMemory); }
	virtual void CleanupMemory(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, EBTMemoryClear::Type CleanupType) const override;
	virtual void InitializeMemory(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, EBTMemoryInit::Type InitType) const override;
	virtual void OnCeaseRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	void RunQuery(uint8* NodeMemory);

private:
	float Score;
	FVector MoveLocation;
	UPROPERTY()
	class AEnemyController* EnemyAI;

	
	FEnvQueryRequest QueryRequest;
};


