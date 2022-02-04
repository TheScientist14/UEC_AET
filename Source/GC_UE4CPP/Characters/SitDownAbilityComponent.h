// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SitDownAbilityComponent.generated.h"

class UCharacterMovementComponent;
class USpringArmComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GC_UE4CPP_API USitDownAbilityComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USitDownAbilityComponent();

	UPROPERTY(VisibleAnywhere)
	bool IsSitDown;

	UCharacterMovementComponent* CharacterMovement;
	USpringArmComponent* SpringArm;

	UFUNCTION()
	void SitDown(AActor* Chair);

	UFUNCTION()
	void StandUp();

	UFUNCTION()
	void OnStandUp();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
};
