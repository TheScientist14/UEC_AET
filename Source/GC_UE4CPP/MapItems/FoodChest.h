// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GC_UE4CPP/Interfaces/Interactable.h"
#include "FoodChest.generated.h"

class AMainGameMode;
class UStaticMeshComponent;
class USceneComponent;
class UPickUpAbilityComponent;
class APickableItem;

UCLASS()
class GC_UE4CPP_API AFoodChest : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFoodChest();
	UPROPERTY()
	AMainGameMode* GameMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mesh")
	UStaticMeshComponent* MeshChest;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mesh")
	UStaticMeshComponent* MeshLid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* Pivot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TimeToOpen = 0.3f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float OpenedAngle = 100;

private:

	UPROPERTY()
	UPickUpAbilityComponent* PickUpAbilityComponent;
	
	FDelegateHandle DelegateHandle;	

	float OpenTimer = 0;
	float CloseTimer = 0;
	bool WaitToClose = false;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void OnInteract(AActor* Caller) override;

	UFUNCTION()
	void DestroyFood(APickableItem* PrmItem);

	UFUNCTION()
	void PlayOpeningAnimation();

	UFUNCTION()
	void PlayClosingAnimation();
};
