// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyController.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API AEnemyController : public AAIController
{
	GENERATED_BODY()

public:
	AEnemyController(FObjectInitializer const& object_initializer = FObjectInitializer::Get());
	void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;

private:
	class UNavigationSystemV1* NavArea;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="AI", meta= (AllowPrivateAccess = "true"))
	UBehaviorTree* BehaviourTree;
	
};