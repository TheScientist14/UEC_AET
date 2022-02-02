// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterAnimInstance.h"
#include "PlayerCharacter.h"
#include "GC_UE4CPP/Characters/PickUpAbilityComponent.h"
#include "GC_UE4CPP/Game/MainGameMode.h"
#include "Kismet/GameplayStatics.h"

UPlayerCharacterAnimInstance::UPlayerCharacterAnimInstance(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	//set any default values for your variables here
	IsPickingUpPuttingDown = false;
	Speed = 0;
	HasGameEnded = false;
	HasWon = false;
}

void UPlayerCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	Player = Cast<ACharacter>(GetOwningActor());
	PickUpAbilityComponent = GetOwningActor()->FindComponentByClass<UPickUpAbilityComponent>();
	AMainGameMode* GameMode = Cast<AMainGameMode>(UGameplayStatics::GetGameMode(this));
	if (GameMode) {
		GameMode->OnGameFinished.AddUObject(this, &UPlayerCharacterAnimInstance::PlayAfterGameAnimation);
	}
}

void UPlayerCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (PickUpAbilityComponent) {
		PickedItem = PickUpAbilityComponent->GetPickedUpActor();
		IsPickingUpPuttingDown = PickUpAbilityComponent->IsPickingUpOrPuttingDown();
	}
	if (Player) {
		Speed = Player->GetVelocity().Size();
	}
}

void UPlayerCharacterAnimInstance::NativeUninitializeAnimation() {
	Super::NativeUninitializeAnimation();
	Player = nullptr;
	PickUpAbilityComponent = nullptr;
}

void UPlayerCharacterAnimInstance::PlayAfterGameAnimation(bool HasGameFinished, bool HasPlayerWon) {
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "Play");
	HasGameEnded = HasGameFinished;
	HasWon = HasPlayerWon;
}