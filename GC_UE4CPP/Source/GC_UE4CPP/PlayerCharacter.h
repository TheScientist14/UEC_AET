// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

//class USpringArmComponent;
//class UCameraComponent;

UCLASS()
class GC_UE4CPP_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

	APlayerController* PlayerController;

	UPROPERTY(EditAnywhere)
	float Speed = 300;

	/*UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* SpringArmComp;*/

	FVector MovementDir = FVector::ZeroVector;

	UFUNCTION()
	void Move(FVector dir);

	UFUNCTION()
	void Interact();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
