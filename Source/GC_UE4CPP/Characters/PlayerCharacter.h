// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GC_UE4CPP/Interfaces/Lifter.h"
#include "GC_UE4CPP/MapItems/PickableItem.h"
#include "PlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class GC_UE4CPP_API APlayerCharacter : public ACharacter, public ILifter
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

	class APickableItem* PickedUpActor = nullptr;

	class APickableItem* TempPickedActor = nullptr;

	bool bIsPickingUpOrPuttingDown = false;

	UFUNCTION()
	virtual bool IsPickingUpOrPuttingDown() override;

	UFUNCTION()
	APickableItem* GetPickedUpActor();

	// returns success
	UFUNCTION()
	virtual bool PickUpActor(APickableItem* ActorToPickUp) override;

	UFUNCTION()
	virtual void BindPickedUpActor() override;

	UFUNCTION()
	virtual void OnHasPickedUp() override;

	UFUNCTION()
	virtual void PutDownPickedUpActor() override;

	UFUNCTION()
	virtual void UnbindPickedUpActor() override;

	UFUNCTION()
	virtual void OnHasPutDown() override;

	DECLARE_MULTICAST_DELEGATE_OneParam(FActorPutDownSignature, APickableItem*);
	FActorPutDownSignature OnPutDown;

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

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
