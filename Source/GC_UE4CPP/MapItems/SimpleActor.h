// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SimpleActor.generated.h"

UCLASS()
class GC_UE4CPP_API ASimpleActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASimpleActor();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh;

	// blocks the red cone light of goblins
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* LightBlocker;
};
