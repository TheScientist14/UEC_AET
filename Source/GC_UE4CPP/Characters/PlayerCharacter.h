// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UPickUpAbilityComponent;

UCLASS()
class GC_UE4CPP_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

	APlayerController* PlayerController;

	UPROPERTY(EditAnywhere, Category = "PlayerCharacter|Interaction")
	float InteractRange = 100;

	UPROPERTY(EditAnywhere, Category="PlayerCharacter|Camera zoom")
	float MinArmLength = 100;

	UPROPERTY(EditAnywhere, Category="PlayerCharacter|Camera zoom")
	float MaxArmLength = 500;

	UPROPERTY(EditAnywhere, Category="PlayerCharacter|Camera zoom")
	float ArmLengthStep = 100;

	UPROPERTY(EditAnywhere, Category="PlayerCharacter|Camera zoom")
	float ZoomThresholdLimit = 1;

	UPROPERTY(EditAnywhere)
	UPickUpAbilityComponent* PickUpAbilityComponent;

	float ZoomThreshold = 0;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComp;

	UFUNCTION()
	void Interact();

	UFUNCTION()
	void ZoomIn(float DeltaZoom);

	UFUNCTION()
	void MoveForward(float DeltaX);

	UFUNCTION()
	void MoveRight(float DeltaY);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
