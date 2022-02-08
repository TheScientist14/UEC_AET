// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DoorBase.generated.h"

UCLASS()
class GC_UE4CPP_API ADoorBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoorBase();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* DoorMesh;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* DoorPivot;

	UPROPERTY(EditAnywhere)
	float OpeningAngle = 100;

	UPROPERTY(EditAnywhere)
	float TimeToOpen = 1;

	UFUNCTION()
	void Open();

	UFUNCTION()
	void Close();

	UFUNCTION()
	virtual void OnOpened();

	UFUNCTION()
	virtual void OnClosed();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	float OpenTimer;
	float CloseTimer;

	FVector InitEuler;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
