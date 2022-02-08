// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GC_UE4CPP/MapItems/DoorBase.h"
#include "GoblinDoor.generated.h"

class USphereComponent;
class AGoblinCharacter;

UCLASS()
class GC_UE4CPP_API AGoblinDoor : public ADoorBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGoblinDoor();

	UPROPERTY(VisibleAnywhere)
	USphereComponent* GoblinDetector;

	UFUNCTION()
	void OnGoblinApproaching(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnGoblinLeaving(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	virtual void OnOpened() override;

protected:
	virtual void BeginPlay() override;
	
	TSet<AActor*> CloseGoblins;
};
