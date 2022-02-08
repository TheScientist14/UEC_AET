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
	UE_LOG(LogTemp, Error, TEXT("BeginPlay AIC"));
}

void AEnemyController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	RunBehaviorTree(BehaviourTree);
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "If BehaviorTree");
	UE_LOG(LogTemp, Error, TEXT("If BehaviorTree"));

	AGoblinCharacter* GoblinCharacter = Cast<AGoblinCharacter>(InPawn);

	if (GoblinCharacter)
	{
		if (GetBlackboardComponent())
		{
			GetBlackboardComponent()->SetValueAsVector("Spawn", InPawn->GetActorLocation());
			GetBlackboardComponent()->SetValueAsBool("Wait", GoblinCharacter->Wait);
			GetBlackboardComponent()->SetValueAsBool("NeedFood", true);
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "If BB");
			UE_LOG(LogTemp, Error, TEXT("If BB"));
		}
	}
}
