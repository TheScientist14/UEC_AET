// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CrateClump.generated.h"

UCLASS()
class GC_UE4CPP_API ACrateClump : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACrateClump();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* SceneRootComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh1;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh2;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh3;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh4;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh6;
	
	// blocks the red cone light of goblins
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* LightBlocker1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* LightBlocker2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* LightBlocker3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* LightBlocker4;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* LightBlocker5;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* LightBlocker6;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
};
