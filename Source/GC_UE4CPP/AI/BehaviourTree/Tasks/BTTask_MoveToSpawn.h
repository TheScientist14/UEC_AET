// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_MoveToSpawn.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class GC_UE4CPP_API UBTT_MoveToSpawn : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UBTT_MoveToSpawn(FObjectInitializer const& object_initialize);
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
