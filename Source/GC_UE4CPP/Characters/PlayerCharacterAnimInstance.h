// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PlayerCharacterAnimInstance.generated.h"

class UPickUpAbilityComponent;
class APickableItem;
class ACharacter;

UCLASS(transient, Blueprintable, hideCategories=AnimInstance, BlueprintType)
class /*GC_UE4CPP_API*/ UPlayerCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UPlayerCharacterAnimInstance(const FObjectInitializer& ObjectInitializer);

	UPROPERTY()
	ACharacter* Player;

	UPROPERTY()
	UPickUpAbilityComponent* PickUpAbilityComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsPickingUpPuttingDown;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	APickableItem* PickedItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTransform LeftHandTarget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool HasWon = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool HasLost = false;

public:
	virtual void NativeInitializeAnimation() override;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	virtual void NativeUninitializeAnimation() override;
};
