// Fill out your copyright notice in the Description page of Project Settings.


#include "AIC_Enemy_EQS.h"
#include "Goblin.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "EnvironmentQuery/EnvQueryManager.h"

AAIC_Enemy_EQS::AAIC_Enemy_EQS(FObjectInitializer const& object_initializer)
{
	static ConstructorHelpers::FObjectFinder<UBehaviorTree> obj(
		TEXT("BehaviorTree'/Game/Blueprints/Characters/AI/BT_Goblin_EQS.BT_Goblin_EQS'"));

	if (obj.Succeeded())
	{
		BehaviourTree = obj.Object;
	}
}

void AAIC_Enemy_EQS::BeginPlay()
{
	Super::BeginPlay();

	RunBehaviorTree(BehaviourTree);
}

void AAIC_Enemy_EQS::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	AGoblin* Goblin = Cast<AGoblin>(InPawn);

	if (Blackboard)
	{
		Blackboard->SetValueAsVector("Spawn", Goblin->Spawn);
	}
}