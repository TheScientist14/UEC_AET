// Fill out your copyright notice in the Description page of Project Settings.


#include "Torch.h"
#include "Components/PointLightComponent.h"

// Sets default values
ATorch::ATorch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Torch mesh");
	PointLightComponent = CreateDefaultSubobject<UPointLightComponent>("Point light");

	SetRootComponent(StaticMeshComponent);
	PointLightComponent->SetupAttachment(RootComponent);

}

