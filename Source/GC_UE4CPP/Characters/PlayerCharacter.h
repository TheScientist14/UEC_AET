// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UPickUpAbilityComponent;
class USitDownAbilityComponent;
class UPauseMenuUserWidget;

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

	UUserWidget* widget;

	UPROPERTY(EditAnywhere,Category = "PlayerCharacter|UI")
	TSubclassOf<UUserWidget> PauseMenu;

	UPROPERTY(VisibleAnywhere)
	UPickUpAbilityComponent* PickUpAbilityComponent;

	UPROPERTY(VisibleAnywhere)
	USitDownAbilityComponent* SitDownAbilityComponent;

	float ZoomThreshold = 0;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComp;

	UFUNCTION()
	void Interact();

	UFUNCTION()
	void Pause();

	UFUNCTION()
	void ZoomIn(float DeltaZoom);

	UFUNCTION()
	void MoveForward(float DeltaX);

	UFUNCTION()
	void MoveRight(float DeltaY);

	UFUNCTION()
	void OnGameEnded(bool HasGameEnded, bool HasWon);

protected:

	virtual void BeginPlay() override;
};
