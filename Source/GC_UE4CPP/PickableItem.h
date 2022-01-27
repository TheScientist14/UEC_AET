// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "PickableItem.generated.h"

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

	// returns where the item would like to be put down
	FTransform GetPutDownTransform();

	// called by Picker when Item has been put down
	void OnPutDown();

protected:

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere)
	class USceneComponent* RightHandAnchor;

	UPROPERTY(EditAnywhere)
	USceneComponent* LeftHandAnchor;

	UPROPERTY(VisibleAnywhere)
	bool IsCurrentlyPickable = true;

public:

	virtual void OnInteract(AActor* Caller) override;

};
