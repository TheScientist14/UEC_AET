// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PickUpAbilityComponent.generated.h"

class UCharacterMovementComponent;
class USkeletalMeshComponent;
class APickableItem;

/*
 * This component need animations on owner to properly
 * work as it relies on anim notifies
 */

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

	UPROPERTY(EditAnywhere)
	UClass* Testing;

	UFUNCTION()
	bool IsPickingUpOrPuttingDown();

	UFUNCTION()
	APickableItem* GetPickedUpActor();

	// returns success
	UFUNCTION()
	bool PickUpActor(APickableItem* ActorToPickUp);

	UFUNCTION()
	void PutDownPickedUpActor();

	// Anim notifies handlers

	UFUNCTION()
	void BindPickedUpActor();

	UFUNCTION()
	void OnHasPickedUp();

	UFUNCTION()
	void UnbindPickedUpActor();

	UFUNCTION()
	void OnHasPutDown();


	// Event fired when picked up acotr has been unbound
	DECLARE_MULTICAST_DELEGATE_OneParam(FActorPutDownSignature, APickableItem*);
	FActorPutDownSignature OnPutDown;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
		
};
