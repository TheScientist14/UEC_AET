// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterAnimInstance.h"

#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

#include "GC_UE4CPP/Characters/PickUpAbilityComponent.h"
#include "GC_UE4CPP/Characters/SitDownAbilityComponent.h"
#include "GC_UE4CPP/Game/MainGameMode.h"

UCharacterAnimInstance::UCharacterAnimInstance(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	//set any default values for your variables here
	IsPickingUpPuttingDown = false;
	Speed = 0;
	HasGameEnded = false;
	HasWon = false;
}

void UCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	Character = Cast<ACharacter>(GetOwningActor());
	PickUpAbilityComponent = GetOwningActor()->FindComponentByClass<UPickUpAbilityComponent>();
	SitDownAbilityComponent = GetOwningActor()->FindComponentByClass<USitDownAbilityComponent>();
	AMainGameMode* GameMode = Cast<AMainGameMode>(UGameplayStatics::GetGameMode(this));
	if (GameMode) {
		GameMode->OnGameFinished.AddUObject(this, &UCharacterAnimInstance::PlayAfterGameAnimation);
	}
}

void UCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (PickUpAbilityComponent) {
		PickedItem = PickUpAbilityComponent->GetPickedUpActor();
		IsPickingUpPuttingDown = PickUpAbilityComponent->IsPickingUpOrPuttingDown();
	}
	if (SitDownAbilityComponent) {
		IsSitDown = SitDownAbilityComponent->IsSitDown;
	}
	if (Character) {
		Speed = Character->GetVelocity().Size();
	}
}

void UCharacterAnimInstance::NativeUninitializeAnimation() {
	Super::NativeUninitializeAnimation();
	Character = nullptr;
	PickUpAbilityComponent = nullptr;
}

void UCharacterAnimInstance::PlayAfterGameAnimation(bool HasGameFinished, bool HasPlayerWon) {
	HasGameEnded = HasGameFinished;
	HasWon = HasPlayerWon;
}