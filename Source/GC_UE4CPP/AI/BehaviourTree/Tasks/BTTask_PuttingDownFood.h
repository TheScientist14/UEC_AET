// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_MoveTo.h"
#include "BTTask_PuttingDownFood.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class GC_UE4CPP_API UBTTask_PuttingDownFood : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTTask_PuttingDownFood(FObjectInitializer const& object_initialize);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
	
};
