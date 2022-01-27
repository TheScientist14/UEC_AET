// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PlayerCharacterAnimInstance.generated.h"

UCLASS(transient, Blueprintable, hideCategories=AnimInstance, BlueprintType)
class /*GC_UE4CPP_API*/ UPlayerCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UPlayerCharacterAnimInstance(const FObjectInitializer& ObjectInitializer);

	UPROPERTY()
	class APlayerCharacter* Player;

	class IPicker* PlayerPicker;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsPickingUpPuttingDown;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class APickableItem* PickedItem;

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
