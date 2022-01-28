// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GC_UE4CPP/Interfaces/Interactable.h"
#include "Food.generated.h"

UCLASS()
class GC_UE4CPP_API AFood: public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFood();

protected:

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMesh;

public:

	virtual void OnInteract(AActor* Caller) override;

};
