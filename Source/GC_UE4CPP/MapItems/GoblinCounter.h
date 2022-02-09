// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GoblinCounter.generated.h"

UCLASS()
class GC_UE4CPP_API AGoblinCounter : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGoblinCounter();

	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* BoxComponent; 

	UFUNCTION()
	void OnGoblinApproaching(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnGoblinLeaving(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex); 

	int GetNbGoblinsNotInSpawn();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	TSet<class AGoblinCharacter*> GoblinsNotInSpawn;

};
