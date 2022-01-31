// Fill out your copyright notice in the Description page of Project Settings.


#include "GC_UE4CPP/AI/GoblinCharacterAnimInstance.h"

#include "GoblinCharacter.h"


UGoblinCharacterAnimInstance::UGoblinCharacterAnimInstance(const FObjectInitializer& ObjectInitializer)
{
}

void UGoblinCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	Goblin = Cast<AGoblinCharacter>(GetOwningActor());
}

void UGoblinCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (Goblin) {
		Speed = Goblin->GetVelocity().Size();
	}
}

void UGoblinCharacterAnimInstance::NativeUninitializeAnimation() {
	Super::NativeUninitializeAnimation();
	Goblin = nullptr;
}