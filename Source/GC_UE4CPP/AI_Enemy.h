// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Spot.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "AI_Enemy.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API AAI_Enemy : public AAIController
{
	GENERATED_BODY()

public:
	AAI_Enemy(FObjectInitializer const& object_initializer = FObjectInitializer::Get());

	class UBlackboardComponent* get_blackboard() const;
	
	void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;

private:
	class UNavigationSystemV1* NavArea;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="AI", meta= (AllowPrivateAccess = "true"))
	UBehaviorTree* BehaviourTree;
	
};
