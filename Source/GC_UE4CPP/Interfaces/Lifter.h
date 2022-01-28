// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Lifter.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class ULifter : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GC_UE4CPP_API ILifter
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	// returns the item the Picker is carrying (or will carry when picking up)
	// null if no item is carried
	UFUNCTION()
	virtual class APickableItem* GetPickedUpActor() = 0;

	// returns true if the animation of picking up or putting down should begin
	// the right animation will start at the first tick it becomes true
	// should be reset on pick up and on put down
	UFUNCTION()
	virtual bool IsPickingUpOrPuttingDown() = 0;

	// returns success
	// called by PickableItem on interaction
	UFUNCTION()
	virtual bool PickUpActor(APickableItem* ActorToPickUp) = 0;

	// called by anim notify of picking up animation
	UFUNCTION()
	virtual void BindPickedUpActor() = 0;

	// called by anim notify at the end of the animation
	UFUNCTION()
	virtual void OnHasPickedUp() = 0;

	UFUNCTION()
	virtual void PutDownPickedUpActor() = 0;

	// called by anim notify of putting down animation
	UFUNCTION()
	virtual void UnbindPickedUpActor() = 0;

	// called by anim notify at the end of the animation
	UFUNCTION()
	virtual void OnHasPutDown() = 0;
};
