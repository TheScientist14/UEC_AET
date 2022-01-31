// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GC_UE4CPP/Characters/PlayerCharacter.h"
#include "GC_UE4CPP/Interfaces/Interactable.h"
#include "FoodChest.generated.h"

UCLASS()
class GC_UE4CPP_API AFoodChest : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFoodChest();
	UPROPERTY()
	class AMainGameMode* GameMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mesh")
	UStaticMeshComponent* MeshChest;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mesh")
	UStaticMeshComponent* MeshLid;

private:

	UPROPERTY()
	APlayerCharacter* Player;
	
	FDelegateHandle DelegateHandle;	
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void OnInteract(AActor* Caller) override;

	UFUNCTION()
	void DestroyFood(class APickableItem* PrmItem);
};
