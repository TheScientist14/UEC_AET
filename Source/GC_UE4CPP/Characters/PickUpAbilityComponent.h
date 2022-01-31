// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PickUpAbilityComponent.generated.h"

class UCharacterMovementComponent;
class USkeletalMeshComponent;
class APickableItem;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GC_UE4CPP_API UPickUpAbilityComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPickUpAbilityComponent();

	UCharacterMovementComponent* CharacterMovement;
	USkeletalMeshComponent* Mesh;

	APickableItem* PickedUpActor = nullptr;
	APickableItem* TempPickedActor = nullptr;
	bool bIsPickingUpOrPuttingDown = false;

	UFUNCTION()
	bool IsPickingUpOrPuttingDown();

	UFUNCTION()
	APickableItem* GetPickedUpActor();

	// returns success
	UFUNCTION()
	bool PickUpActor(APickableItem* ActorToPickUp);

	UFUNCTION()
	void BindPickedUpActor();

	UFUNCTION()
	void OnHasPickedUp();

	UFUNCTION()
	void PutDownPickedUpActor();

	UFUNCTION()
	void UnbindPickedUpActor();

	UFUNCTION()
	void OnHasPutDown();

	DECLARE_MULTICAST_DELEGATE_OneParam(FActorPutDownSignature, APickableItem*);
	FActorPutDownSignature OnPutDown;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
		
};
