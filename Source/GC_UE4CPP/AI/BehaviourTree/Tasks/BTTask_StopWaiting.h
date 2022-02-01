// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_StopWaiting.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API UBTTask_StopWaiting : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	UBTTask_StopWaiting(FObjectInitializer const& object_initialize);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
	
};
