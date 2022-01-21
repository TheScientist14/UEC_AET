// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Spot.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "AI_Enemie.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API AAI_Enemie : public AAIController
{
	GENERATED_BODY()

public:
	AAI_Enemie(FObjectInitializer const& object_initializer = FObjectInitializer::Get());

	class UBlackboardComponent* get_blackboard() const;
	
	void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;

private:

	class AGoblin* Goblin;

	class UNavigationSystemV1* NavArea;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="AI", meta= (AllowPrivateAccess = "true"))
	class UBehaviorTree* BehaviourTree;
	
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="AI", meta= (AllowPrivateAccess = "true"))
	class UBehaviorTreeComponent* BehaviourTreeComp;
	
	UPROPERTY(EditAnywhere)
	class UBlackboardComponent* BlackboardComponent;
	

	
};
