// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyController.h"

#include "GoblinCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

AEnemyController::AEnemyController(FObjectInitializer const& object_initializer)
{
	static ConstructorHelpers::FObjectFinder<UBehaviorTree> obj(TEXT("BehaviorTree'/Game/Blueprints/Characters/AI/BT_Goblin.BT_Goblin'"));
	if (obj.Succeeded())
	{
		BehaviourTree = obj.Object;	
	}
}

void AEnemyController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Error, TEXT("BeginPlay AIC"));
	
	RunBehaviorTree(BehaviourTree);
}

void AEnemyController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	AGoblinCharacter* Goblin = Cast<AGoblinCharacter>(InPawn);

	GEngine->AddOnScreenDebugMessage(1, 5.0f, FColor::Blue, "Spawn init blackboard before if");
	UE_LOG(LogTemp, Error, TEXT("Spawn init blackboard before if"));
	if (Blackboard)
	{
		GEngine->AddOnScreenDebugMessage(1, 5.0f, FColor::Blue, "Spawn init blackboard");
		UE_LOG(LogTemp, Error, TEXT("Spawn init blackboard"));
		Blackboard->SetValueAsVector("Spawn", Goblin->Spawn);
	}
}
