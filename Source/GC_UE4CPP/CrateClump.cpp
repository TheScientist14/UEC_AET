// Fill out your copyright notice in the Description page of Project Settings.


#include "CrateClump.h"

// Sets default values
ACrateClump::ACrateClump()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(StaticMesh);

	StaticMesh1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh1"));
	StaticMesh2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh2"));
	StaticMesh3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh3"));
	StaticMesh4 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh4"));
	StaticMesh5 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh5"));

	StaticMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	StaticMesh1->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	StaticMesh2->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	StaticMesh3->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	StaticMesh4->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	StaticMesh5->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void ACrateClump::BeginPlay()
{
	Super::BeginPlay();
	// StaticMesh->OnComponentHit.AddDynamic(this, &ACrateClump::DestroyHitActor);
	// StaticMesh1->OnComponentHit.AddDynamic(this, &ACrateClump::DestroyHitActor);
	// StaticMesh2->OnComponentHit.AddDynamic(this, &ACrateClump::DestroyHitActor);
	// StaticMesh3->OnComponentHit.AddDynamic(this, &ACrateClump::DestroyHitActor);
	// StaticMesh4->OnComponentHit.AddDynamic(this, &ACrateClump::DestroyHitActor);
	// StaticMesh5->OnComponentHit.AddDynamic(this, &ACrateClump::DestroyHitActor);
	UE_LOG(LogTemp, Warning, TEXT("testlol"));
}

// Called every frame
void ACrateClump::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// void ACrateClump::DestroyHitActor(UPrimitiveComponent* HitComponent, AActor* OtherActor,
//                                          UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
// {
// 	HitComponent->DestroyComponent();
// 	UE_LOG(LogTemp, Warning, TEXT("test"));
// }


