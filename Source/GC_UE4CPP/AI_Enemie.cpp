// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_Enemie.h"

#include "Goblin.h"
#include "Kismet/GameplayStatics.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"

AAI_Enemie::AAI_Enemie(FObjectInitializer const& object_initializer)
{
	static ConstructorHelpers::FObjectFinder<UBehaviorTree> obj(TEXT("BehaviorTree'/Game/Blueprints/Characters/AI/BT_Goblin.BT_Goblin'"));

	if (obj.Succeeded())
	{
		BehaviourTree = obj.Object;	
	}
	BehaviourTreeComp = object_initializer.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("BehaviourTree"));
	BlackboardComponent = object_initializer.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("Blackboard"));
}

void AAI_Enemie::BeginPlay()
{
	Super::BeginPlay();

	GEngine->AddOnScreenDebugMessage(1, 5.0f, FColor::Black, TEXT("BeginPlay"));
	UE_LOG(LogTemp, Error, TEXT("BeginPlay AI_Enemie"));
	
	RunBehaviorTree(BehaviourTree);

	BehaviourTreeComp->StartTree(*BehaviourTree);
}

void AAI_Enemie::OnPossess(APawn* InPawn)
{
	GEngine->AddOnScreenDebugMessage(1, 5.0f, FColor::Black, TEXT("OnPossess"));
	UE_LOG(LogTemp, Error, TEXT("OnPossess"));
	Super::OnPossess(InPawn);

	if (BlackboardComponent)
	{
		UE_LOG(LogTemp, Error, TEXT("if "));
		BlackboardComponent->InitializeBlackboard(*BehaviourTree->BlackboardAsset);
	}
}

UBlackboardComponent* AAI_Enemie::get_blackboard() const
{
	return BlackboardComponent;
}