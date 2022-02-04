// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CharacterAnimInstance.generated.h"

class UPickUpAbilityComponent;
class USitDownAbilityComponent;
class APickableItem;
class ACharacter;

UCLASS(transient, Blueprintable, hideCategories=AnimInstance, BlueprintType)
class GC_UE4CPP_API UCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UCharacterAnimInstance(const FObjectInitializer& ObjectInitializer);

	ACharacter* Character;
	UPickUpAbilityComponent* PickUpAbilityComponent;
	USitDownAbilityComponent* SitDownAbilityComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsSitDown;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsPickingUpPuttingDown;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	APickableItem* PickedItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool HasGameEnded;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool HasWon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTransform LeftHandTarget;

	UFUNCTION()
	void PlayAfterGameAnimation(bool HasGameFinished, bool HasPlayerWon);

public:
	virtual void NativeInitializeAnimation() override;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	virtual void NativeUninitializeAnimation() override;
};
