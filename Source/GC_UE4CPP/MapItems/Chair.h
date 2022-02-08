// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GC_UE4CPP/Interfaces/Interactable.h"
#include "Chair.generated.h"

class UStaticMeshComponent;
class USceneComponent;

UCLASS()
class GC_UE4CPP_API AChair : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChair();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* PlayerTransform;

	UPROPERTY(EditAnywhere)
	float WaitingTimeToWin = 60;

	FTransform GetPreAnimationPlayerTransform();

protected:

	float SitTimer;

public:

	virtual void Tick(float DeltaTime) override;

	virtual void OnInteract(AActor* Caller) override;
};
