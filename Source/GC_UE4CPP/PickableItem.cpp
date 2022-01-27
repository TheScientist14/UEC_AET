// Fill out your copyright notice in the Description page of Project Settings.

#include "PickableItem.h"
#include "Kismet/GameplayStatics.h"
#include "Characters/PlayerCharacter.h"
#include "Picker.h"

// Sets default values
APickableItem::APickableItem()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("StaticMesh"));
	RootComponent = StaticMesh;

	RightHandAnchor = CreateDefaultSubobject<USceneComponent>(FName("Right hand anchor"));
	LeftHandAnchor = CreateDefaultSubobject<USceneComponent>(FName("Left hand anchor"));

	RightHandAnchor->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	LeftHandAnchor->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

void APickableItem::OnInteract(AActor* Caller)
{
	if (IsCurrentlyPickable) {
		IPicker* Picker = Cast<IPicker>(Caller);
		if (Picker) {
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "Picked up");
			IsCurrentlyPickable = !Picker->PickUpActor(this);;
		}
	}
}

FTransform APickableItem::GetRightHandAnchor() {
	FVector Euler = RightHandAnchor->GetRelativeRotation().Euler();
	FRotator Rotator = FRotator::MakeFromEuler(-Euler);
	return FTransform::FTransform(Rotator, -RightHandAnchor->GetRelativeLocation() / GetActorRelativeScale3D());
}

FTransform APickableItem::GetLeftHandAnchor() {
	FVector Euler = LeftHandAnchor->GetRelativeRotation().Euler();
	FRotator Rotator = FRotator::MakeFromEuler(-Euler);
	return FTransform::FTransform(Rotator, -LeftHandAnchor->GetRelativeLocation());
}

void APickableItem::OnPutDown() {
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "Put down");
	IsCurrentlyPickable = true;
}

FTransform APickableItem::GetPutDownTransform() {
	return GetActorTransform();
}