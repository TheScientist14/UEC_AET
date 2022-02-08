// Fill out your copyright notice in the Description page of Project Settings.


#include "SitDownAbilityComponent.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values for this component's properties
USitDownAbilityComponent::USitDownAbilityComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	IsSitDown = false;
}

// Called when the game starts
void USitDownAbilityComponent::BeginPlay()
{
	Super::BeginPlay();

	ACharacter* Owner = GetOwner<ACharacter>();
	CharacterMovement = Owner->GetCharacterMovement();
	SpringArm = Owner->FindComponentByClass<USpringArmComponent>();
}

void USitDownAbilityComponent::SitDown(AActor* Chair) {
	if (!IsSitDown) {
		IsSitDown = true;
		CharacterMovement->SetMovementMode(EMovementMode::MOVE_None);
		if (SpringArm) {
			SpringArm->bUsePawnControlRotation = false;
			// facing chair
			FVector Euler = Chair->GetActorRotation().Euler();
			Euler.Z += 180;
			SpringArm->SetWorldRotation(FRotator::MakeFromEuler(Euler));
		}
	}
}

void USitDownAbilityComponent::StandUp() {
	if (IsSitDown) {
		IsSitDown = false;
	}
}

void USitDownAbilityComponent::OnStandUp() {
	CharacterMovement->SetMovementMode(EMovementMode::MOVE_Walking);
	if (SpringArm) {
		SpringArm->bUsePawnControlRotation = true;
	}
}