// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NavigationSystem.h"
#include "GameFramework/Character.h"
#include "GoblinCharacter.generated.h"

UCLASS()
class GC_UE4CPP_API AGoblinCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGoblinCharacter();

	UPROPERTY(EditAnywhere)
	class ASpot* Spot;

	UPROPERTY(EditAnywhere)
	FVector Spawn;

	UPROPERTY(EditAnywhere)
	bool Wait;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class APickableItem> Food;

	UPROPERTY(EditAnywhere)
	class UPickUpAbilityComponent* PickUpAbilityComponent;

	APickableItem* FoodOnHand;

	UPROPERTY(EditAnywhere)
	class AGoblinCounter* GoblinCounter;

	UPROPERTY(EditAnywhere)
	class AProceduralRoom* ProceduralRoom;

	UPROPERTY(EditAnywhere)
	class USpotLightComponent* SpotLightVision;

	UFUNCTION()
	void OnGoblinCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	

protected:
	UPROPERTY(EditAnywhere)
	USkeletalMeshSocket* Hand;

	class AMainGameState* GameState;
	FActorSpawnParameters SpawnInfo;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void GetNextSpot();

	void InteractFood();
	void SpawnFood(UClass* PrmFood);

	void PutDownFood();

	UFUNCTION()
	void OnGameEnded(bool HasGameEnded, bool HasWon);

	UFUNCTION()
	void InitBlackboard();

};
