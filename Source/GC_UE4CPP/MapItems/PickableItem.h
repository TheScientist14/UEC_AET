// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GC_UE4CPP/Interfaces/Interactable.h"
#include "PickableItem.generated.h"

class UPickUpAbilityComponent;

UCLASS()
class GC_UE4CPP_API APickableItem: public AActor, public IInteractable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APickableItem();

	// returns where the right hand should carry the item
	FTransform GetRightHandAnchor();

	// returns where the left hand should carry the item
	FTransform GetLeftHandAnchor();

	// called by Picker when Item has been put down
	// returns where the item would like to be put down
	FTransform OnPutDown();

protected:

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere)
	USceneComponent* RightHandAnchor;

	UPROPERTY(EditAnywhere)
	USceneComponent* LeftHandAnchor;

	UPROPERTY(EditAnywhere)
	UPickUpAbilityComponent* LifterPickUpAbility;

	UPROPERTY(EditAnywhere)
	float AcceptableRadius;

	UPROPERTY(VisibleAnywhere)
	bool IsCurrentlyPickable = true;

public:

	virtual void OnInteract(AActor* Caller) override;
	void SetIsCurrentlyPickable(bool Setter);
	void SetLifterPickUpAbility(UPickUpAbilityComponent* Setter);
	void SetOnGroundPhysics(bool IsMovable);

};
