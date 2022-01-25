// Fill out your copyright notice in the Description page of Project Settings.


#include "AIC_Enemy.h"

#include "Goblin.h"
#include "Kismet/GameplayStatics.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"

AAIC_Enemy::AAIC_Enemy(FObjectInitializer const& object_initializer)
{
	static ConstructorHelpers::FObjectFinder<UBehaviorTree> obj(TEXT("BehaviorTree'/Game/Blueprints/Characters/AI/BT_Goblin.BT_Goblin'"));

	if (obj.Succeeded())
	{
		BehaviourTree = obj.Object;	
	}
}

void AAIC_Enemy::BeginPlay()
{
	Super::BeginPlay();
	
	RunBehaviorTree(BehaviourTree);
}

void AAIC_Enemy::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	AGoblin* Goblin = Cast<AGoblin>(InPawn);

	if (Blackboard)
	{
		Blackboard->SetValueAsVector("Spawn", Goblin->Spawn);
	}
}