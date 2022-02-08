// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUpAbilityComponent.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/KismetSystemLibrary.h"

#include "GC_UE4CPP/MapItems/PickableItem.h"

// Sets default values for this component's properties
UPickUpAbilityComponent::UPickUpAbilityComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

// Called when the game starts
void UPickUpAbilityComponent::BeginPlay()
{
	Super::BeginPlay();

	ACharacter* Owner = GetOwner<ACharacter>();
	CharacterMovement = Owner->GetCharacterMovement();
	Mesh = Owner->GetMesh();
}

APickableItem* UPickUpAbilityComponent::GetPickedUpActor()
{
	return PickedUpActor;
}

bool UPickUpAbilityComponent::IsPickingUpOrPuttingDown()
{
	return bIsPickingUpOrPuttingDown;
}

bool UPickUpAbilityComponent::PickUpActor(APickableItem* ActorToPickUp)
{
	if (ActorToPickUp == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Can't pick up null"));
		return false;
	}
	if (!PickedUpActor && !TempPickedActor)
	{
		bIsPickingUpOrPuttingDown = true;
		TempPickedActor = ActorToPickUp;
		CharacterMovement->SetMovementMode(EMovementMode::MOVE_None);
		return true;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Trying to pick up when you already are lifting something"));
		return false;
	}
}

void UPickUpAbilityComponent::PutDownPickedUpActor()
{
	bIsPickingUpOrPuttingDown = true;
	CharacterMovement->SetMovementMode(EMovementMode::MOVE_None);
}

/*
 * Anim notifies handlers
 */

void UPickUpAbilityComponent::BindPickedUpActor()
{
	if (TempPickedActor)
	{
		PickedUpActor = TempPickedActor;
		TempPickedActor = nullptr;
		PickedUpActor->AttachToComponent(Mesh, FAttachmentTransformRules::SnapToTargetNotIncludingScale, "RightHandSocket");
		// offset to properly handle mesh position
		FTransform OffsetTarget = PickedUpActor->GetRightHandAnchor();
		PickedUpActor->SetActorRelativeLocation(-OffsetTarget.GetLocation());
		PickedUpActor->SetActorRelativeRotation(OffsetTarget.GetRotation());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No actor to bind"));
	}
}

void UPickUpAbilityComponent::OnHasPickedUp()
{
	CharacterMovement->SetMovementMode(EMovementMode::MOVE_Walking);
	bIsPickingUpOrPuttingDown = false;
	CharacterMovement->MaxWalkSpeed /= 2;
}

void UPickUpAbilityComponent::UnbindPickedUpActor()
{
	if (PickedUpActor)
	{
		PickedUpActor->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
		PickedUpActor->SetActorTransform(PickedUpActor->OnPutDown(), false, nullptr, ETeleportType::ResetPhysics);
		OnPutDown.Broadcast(PickedUpActor);
		PickedUpActor = nullptr;
	}
}

void UPickUpAbilityComponent::OnHasPutDown()
{
	CharacterMovement->SetMovementMode(EMovementMode::MOVE_Walking);
	bIsPickingUpOrPuttingDown = false;
	CharacterMovement->MaxWalkSpeed *= 2;
}

