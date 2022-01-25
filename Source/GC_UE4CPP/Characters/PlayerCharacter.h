// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class GC_UE4CPP_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

	APlayerController* PlayerController;

	UPROPERTY(VisibleAnywhere)
	class USphereComponent* InteractSphere;

	UPROPERTY(EditAnywhere, Category="PlayerCharacter|Camera zoom")
	float MinArmLength = 100;

	UPROPERTY(EditAnywhere, Category="PlayerCharacter|Camera zoom")
	float MaxArmLength = 500;

	UPROPERTY(EditAnywhere, Category="PlayerCharacter|Camera zoom")
	float ArmLengthStep = 100;

	UPROPERTY(EditAnywhere, Category="PlayerCharacter|Camera zoom")
	float ZoomThresholdLimit = 1;

	UPROPERTY(EditAnywhere, Category="PlayerCharacter|Interaction")
	float InteractRange = 100;

	TArray<class IInteractable*> InteractableInRange;

	float ZoomThreshold = 0;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComp;

	class APickableItem* PickedUpActor = 0;

	UFUNCTION()
	APickableItem* GetPickedUpActor();

	// returns success
	UFUNCTION()
	bool PickUpActor(APickableItem* ActorToPickUp);

	UFUNCTION()
	void Interact();

	UFUNCTION()
	void ZoomIn(float DeltaZoom);

	UFUNCTION()
	void MoveForward(float DeltaX);

	UFUNCTION()
	void MoveRight(float DeltaY);

	UFUNCTION()
	void RegisterInteractable(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void UnregisterInteractable(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void PutDownPickedUpActor();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
