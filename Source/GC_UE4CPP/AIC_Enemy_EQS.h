// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnvironmentQuery/EnvQuery.h"
#include "AIC_Enemy_EQS.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API AAIC_Enemy_EQS : public AAIController
{
	GENERATED_BODY()
public:
	AAIC_Enemy_EQS(FObjectInitializer const& object_initializer = FObjectInitializer::Get());

	class UBlackboardComponent* get_blackboard() const;
	
	void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;
	
	UPROPERTY(EditAnywhere, Category = "AI")
	UEnvQuery *FindHidingSpotEQS;

	void RunQuery();
	void HandleQueryResult(TSharedPtr<FEnvQueryResult> result);

private:
	class UNavigationSystemV1* NavArea;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="AI", meta= (AllowPrivateAccess = "true"))
	UBehaviorTree* BehaviourTree;
	
};
