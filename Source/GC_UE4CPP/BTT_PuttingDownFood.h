// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Goblin.h"
#include "BehaviorTree/Tasks/BTTask_MoveTo.h"
#include "UObject/UObjectGlobals.h"
#include "BTT_PuttingDownFood.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class GC_UE4CPP_API UBTT_PuttingDownFood : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTT_PuttingDownFood(FObjectInitializer const& object_initialize);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
	
};
