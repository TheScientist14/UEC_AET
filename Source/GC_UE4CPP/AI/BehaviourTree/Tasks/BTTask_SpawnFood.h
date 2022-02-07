// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_SpawnFood.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API UBTTask_SpawnFood : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

	UBTTask_SpawnFood(FObjectInitializer const& object_initialize);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
};
