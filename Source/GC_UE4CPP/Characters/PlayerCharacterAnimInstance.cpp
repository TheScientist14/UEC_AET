// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterAnimInstance.h"
#include "PlayerCharacter.h"
#include "GC_UE4CPP/Interfaces/Lifter.h"

UPlayerCharacterAnimInstance::UPlayerCharacterAnimInstance(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	//set any default values for your variables here
	//IsPickingUpPuttingDown = false;
	//Speed = 0;
}

void UPlayerCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	Player = Cast<APlayerCharacter>(GetOwningActor());
	PlayerPicker = Cast<ILifter>(Player);
}

void UPlayerCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (Player) {
		Speed = Player->GetVelocity().Size();
		PickedItem = PlayerPicker->GetPickedUpActor();
		IsPickingUpPuttingDown = PlayerPicker->IsPickingUpOrPuttingDown();
	}
}

void UPlayerCharacterAnimInstance::NativeUninitializeAnimation() {
	Super::NativeUninitializeAnimation();
	Player = nullptr;
}