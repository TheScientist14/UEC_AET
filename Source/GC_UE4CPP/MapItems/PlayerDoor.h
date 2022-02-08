// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GC_UE4CPP/MapItems/DoorBase.h"
#include "GC_UE4CPP/Interfaces/Interactable.h"
#include "PlayerDoor.generated.h"

class UBoxComponent;

UCLASS()
class GC_UE4CPP_API APlayerDoor : public ADoorBase, public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayerDoor();

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* InteractionReceiver;

public:	

	virtual void OnInteract(AActor* Caller) override;

};
