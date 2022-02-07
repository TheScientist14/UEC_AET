// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUpAbilityComponent.h"
#include "GC_UE4CPP/MapItems/PickableItem.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/KismetSystemLibrary.h"

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
		UE_LOG(LogTemp, Error, TEXT("Can't pick up null"))
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
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "Trying to pick up when you already are lifting something");
		return false;
	}
}

void UPickUpAbilityComponent::BindPickedUpActor()
{
	if (TempPickedActor)
	{
		PickedUpActor = TempPickedActor;
		TempPickedActor = nullptr;
		PickedUpActor->AttachToComponent(Mesh, FAttachmentTransformRules::SnapToTargetNotIncludingScale,
			"RightHandSocket");
		/*PickedUpActor->SetActorRelativeLocation(this->GetMesh()->GetSocketLocation("Right_Hand"));*/
		//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "Attached");
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Cyan, "No actor to bind");
	}
}

void UPickUpAbilityComponent::OnHasPickedUp()
{
	CharacterMovement->SetMovementMode(EMovementMode::MOVE_Walking);
	bIsPickingUpOrPuttingDown = false;
	CharacterMovement->MaxWalkSpeed /= 2;
}

void UPickUpAbilityComponent::PutDownPickedUpActor()
{
	bIsPickingUpOrPuttingDown = true;
	CharacterMovement->SetMovementMode(EMovementMode::MOVE_None);
	// TODO : IK to wanted location
}

void UPickUpAbilityComponent::UnbindPickedUpActor()
{
	if (PickedUpActor)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "Dettaching");
		//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, PickedUpActor->GetActorLocation().ToString());
		PickedUpActor->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
		//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, PickedUpActor->GetActorLocation().ToString());
		PickedUpActor->SetActorTransform(PickedUpActor->OnPutDown(), false, nullptr, ETeleportType::ResetPhysics);
		//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, PickedUpActor->GetActorLocation().ToString());
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

