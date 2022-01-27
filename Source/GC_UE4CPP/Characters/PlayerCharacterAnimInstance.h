// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PlayerCharacterAnimInstance.generated.h"

class APlayerCharacter;

UCLASS(transient, Blueprintable, hideCategories=AnimInstance, BlueprintType)
class /*GC_UE4CPP_API*/ UPlayerCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UPlayerCharacterAnimInstance(const FObjectInitializer& ObjectInitializer);

	APlayerCharacter* Player;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsPickingUpPuttingDown;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsCarrying;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed;

	UFUNCTION(BlueprintCallable)
	void PickUpOrPutDown();

public:
	virtual void NativeInitializeAnimation() override;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
};
