// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_DestroyActor.h"

#include "AIController.h"
#include "Goblin.h"

UBTT_DestroyActor::UBTT_DestroyActor(FObjectInitializer const& object_initialize)
{
	NodeName = TEXT("DestroyActor");
}

EBTNodeResult::Type UBTT_DestroyActor::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AGoblin* Goblin = Cast<AGoblin>(OwnerComp.GetAIOwner()->GetPawn());
	
	Goblin->Destroy();
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}
