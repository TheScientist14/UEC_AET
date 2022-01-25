// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterAnimInstance.h"
#include "PlayerCharacter.h"

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
	Player = (APlayerCharacter*)GetOwningActor();
}

void UPlayerCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (Player) {
		Speed = Player->GetVelocity().Size();
		IsCarrying = (bool)(Player->GetPickedUpActor());
	}
}

void UPlayerCharacterAnimInstance::PickUpOrPutDown() {

}
