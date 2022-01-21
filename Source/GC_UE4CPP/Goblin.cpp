// Fill out your copyright notice in the Description page of Project Settings.


#include "Goblin.h"

#include "Spot.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AGoblin::AGoblin()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGoblin::BeginPlay()
{
	Super::BeginPlay();

	/*TSubclassOf<ASpot> SpotClass;
	UGameplayStatics::GetAllActorsOfClass(this, SpotClass, Spots);
	*/

	GEngine->AddOnScreenDebugMessage(1, 5.0f, FColor::Blue, Spots[0]->GetName());
}

// Called every frame
void AGoblin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGoblin::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

