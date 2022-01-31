// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NavigationSystem.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_MoveToRandomPoint.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API UBTTask_MoveToRandomPoint : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTTask_MoveToRandomPoint(FObjectInitializer const& object_initialize);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);

	UNavigationSystemV1* NavSystem;
	FNavLocation RandomPoint;
};
