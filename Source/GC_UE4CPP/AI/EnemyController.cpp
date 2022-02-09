// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyController.h"


#include "GoblinCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"


AEnemyController::AEnemyController(FObjectInitializer const& object_initializer)
{
}

void AEnemyController::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemyController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	RunBehaviorTree(BehaviourTree);

	AGoblinCharacter* GoblinCharacter = Cast<AGoblinCharacter>(InPawn);

	if (GoblinCharacter)
	{
		if (GetBlackboardComponent())
		{
			GetBlackboardComponent()->SetValueAsVector("Spawn", InPawn->GetActorLocation());
			GetBlackboardComponent()->SetValueAsBool("Wait", GoblinCharacter->Wait);
			GetBlackboardComponent()->SetValueAsBool("NeedFood", true);
		}
	}
}
