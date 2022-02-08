// Fill out your copyright notice in the Description page of Project Settings.

#include "PickableItem.h"
#include "Kismet/GameplayStatics.h"
#include "GC_UE4CPP/Characters/PickUpAbilityComponent.h"
#include "GC_UE4CPP/MapItems/FoodChest.h"
#include "GC_UE4CPP/MapItems/Spot.h"

// Sets default values
APickableItem::APickableItem()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//SetActorTickEnabled(false);

	AcceptableRadius = 100;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("StaticMesh"));
	RootComponent = StaticMesh;
	StaticMesh->SetEnableGravity(true);
	StaticMesh->SetSimulatePhysics(false);
	StaticMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	RightHandAnchor = CreateDefaultSubobject<USceneComponent>(FName("Right hand anchor"));
	LeftHandAnchor = CreateDefaultSubobject<USceneComponent>(FName("Left hand anchor"));

	RightHandAnchor->SetupAttachment(RootComponent);
	LeftHandAnchor->SetupAttachment(RootComponent);
}

// picks it up if caller is able to
// if has already been picked up, puts it down
void APickableItem::OnInteract(AActor* Caller)
{
	if (IsCurrentlyPickable) {
		UPickUpAbilityComponent* PickUpAbilityComponent = Caller->FindComponentByClass<UPickUpAbilityComponent>();
		if (PickUpAbilityComponent) {
			LifterPickUpAbility = PickUpAbilityComponent;
			SetOnGroundPhysics(false);
			IsCurrentlyPickable = !LifterPickUpAbility->PickUpActor(this);
			// on success
			if (!IsCurrentlyPickable) {
				// searching for spot to update
				TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypeFilter;
				ObjectTypeFilter.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Visibility));
				TArray<AActor*> IgnoreActors;
				IgnoreActors.Init(this, 1);
				TArray<AActor*> OverlappedActors;
				UKismetSystemLibrary::SphereOverlapActors(this, GetActorLocation(), AcceptableRadius, ObjectTypeFilter, nullptr, IgnoreActors, OverlappedActors);
				bool ContinueSearching = true;
				int i = 0;
				while (i < OverlappedActors.Num() && ContinueSearching) {
					ASpot* Spot = Cast<ASpot>(OverlappedActors[i]);
					if (Spot) {
						if ((GetActorLocation() - Spot->GetFoodSpotTransform().GetLocation()).SizeSquared() < 2500) { // getting squared size is faster
							Spot->SetSpotFree();
							ContinueSearching = false;
						}
					}
					if (ContinueSearching) {
						i++;
					}
				}
			}
			else {
				SetOnGroundPhysics(true);
			}
		}
	}
	else if (LifterPickUpAbility) {
		if (Caller == (AActor*)(LifterPickUpAbility->GetOwner())) {
			LifterPickUpAbility->PutDownPickedUpActor();
		}
	}
}

void APickableItem::SetIsCurrentlyPickable(bool Setter)
{
	IsCurrentlyPickable = Setter;
}

void APickableItem::SetLifterPickUpAbility(UPickUpAbilityComponent* Setter)
{
	LifterPickUpAbility = Setter;
}

void APickableItem::OverridePutDownTransform(FTransform Target) {
	IsPutDownTargetOverriden = true;
	PutDownOverrideTarget = Target;
}

FTransform APickableItem::GetRightHandAnchor() {
	return FTransform::FTransform(RightHandAnchor->GetRelativeRotation(), -RightHandAnchor->GetRelativeLocation());
}

FTransform APickableItem::OnPutDown() {
	IsCurrentlyPickable = true;
	SetOnGroundPhysics(true);
	if (IsPutDownTargetOverriden) {
		IsPutDownTargetOverriden = false;
		PutDownOverrideTarget.SetScale3D(GetActorScale());
		return PutDownOverrideTarget;
	}
	else {
		TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypeFilter;
		ObjectTypeFilter.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Visibility));
		TArray<AActor*> IgnoreActors;
		IgnoreActors.Init(this, 1);
		TArray<AActor*> OverlappedActors;
		UKismetSystemLibrary::SphereOverlapActors(this, GetActorLocation(), AcceptableRadius, ObjectTypeFilter, nullptr, IgnoreActors, OverlappedActors);
		bool HasFoundLocation = false;
		int i = 0;
		while (i < OverlappedActors.Num() && !HasFoundLocation) {
			AFoodChest* Chest = Cast<AFoodChest>(OverlappedActors[i]);
			if (Chest) {
				FTransform TmpT = Chest->GetActorTransform();
				return FTransform::FTransform(TmpT.Rotator(), TmpT.GetLocation(), GetActorScale());
			}
			else {
				ASpot* Spot = Cast<ASpot>(OverlappedActors[i]);
				if (Spot) {
					Spot->SetSpotOccupied();
					FTransform TmpT = Spot->GetFoodSpotTransform();
					return FTransform::FTransform(TmpT.GetRotation(), TmpT.GetLocation(), GetActorScale());
				}
				else {
					i++;
				}
			}
		}
		return FTransform::FTransform(FRotator::MakeFromEuler(FVector(0, 0, GetActorRotation().Euler().Z)), GetActorLocation(), GetActorScale());
	}
}

void APickableItem::SetOnGroundPhysics(bool IsOnGround) {
	StaticMesh->SetSimulatePhysics(IsOnGround);
	StaticMesh->SetCollisionEnabled(IsOnGround ? ECollisionEnabled::QueryAndPhysics : ECollisionEnabled::NoCollision);
}