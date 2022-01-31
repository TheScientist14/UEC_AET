// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterAnimInstance.h"
#include "PlayerCharacter.h"
#include "GC_UE4CPP/Characters/PickUpAbilityComponent.h"

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
	Player = Cast<ACharacter>(GetOwningActor());
	PickUpAbilityComponent = GetOwningActor()->FindComponentByClass<UPickUpAbilityComponent>();
}

void UPlayerCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (PickUpAbilityComponent) {
		Speed = Player->GetVelocity().Size();
		PickedItem = PickUpAbilityComponent->GetPickedUpActor();
		IsPickingUpPuttingDown = PickUpAbilityComponent->IsPickingUpOrPuttingDown();
	}
}

void UPlayerCharacterAnimInstance::NativeUninitializeAnimation() {
	Super::NativeUninitializeAnimation();
	Player = nullptr;
	PickUpAbilityComponent = nullptr;
}