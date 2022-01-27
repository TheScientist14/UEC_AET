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

protected:

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMesh;

public:

	virtual void OnInteract() override;

};
