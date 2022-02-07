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

void APickableItem::OnInteract(AActor* Caller)
{
	if (IsCurrentlyPickable) {
		UPickUpAbilityComponent* PickUpAbilityComponent = Caller->FindComponentByClass<UPickUpAbilityComponent>();
		if (PickUpAbilityComponent) {
			//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "Picked up");
			LifterPickUpAbility = PickUpAbilityComponent;
			SetOnGroundPhysics(false);
			IsCurrentlyPickable = !LifterPickUpAbility->PickUpActor(this);
			// on success
			if (!IsCurrentlyPickable) {
				TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypeFilter;
				ObjectTypeFilter.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Visibility));
				TArray<AActor*> IgnoreActors;
				IgnoreActors.Init(this, 1);
				TArray<AActor*> OverlappedActors;
				UKismetSystemLibrary::SphereOverlapActors(this, GetActorLocation(), AcceptableRadius, ObjectTypeFilter, nullptr, IgnoreActors, OverlappedActors);
				bool ContinueSearching = true;
				int i = 0;
				while (i < OverlappedActors.Num() && ContinueSearching) {
					//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Orange, OverlappedActors[i]->GetName());
					ASpot* Spot = Cast<ASpot>(OverlappedActors[i]);
					if (Spot) {
						if ((GetActorLocation() - Spot->GetFoodSpotTransform().GetLocation()).SizeSquared() < 2500) { // getting squared size is faster
							//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Orange, "-1");
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
			//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Yellow, "Pickable item has been interacted and ask lifter to be put down");
			LifterPickUpAbility->PutDownPickedUpActor();
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

FTransform APickableItem::OnPutDown() {
	//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "Put down");
	IsCurrentlyPickable = true;
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypeFilter;
	ObjectTypeFilter.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Visibility));
	TArray<AActor*> IgnoreActors;
	IgnoreActors.Init(this, 1);
	TArray<AActor*> OverlappedActors;
	UKismetSystemLibrary::SphereOverlapActors(this, GetActorLocation(), AcceptableRadius, ObjectTypeFilter, nullptr, IgnoreActors, OverlappedActors);
	bool HasFoundLocation = false;
	int i = 0;
	SetOnGroundPhysics(true);
	while (i < OverlappedActors.Num() && !HasFoundLocation) {
		//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Orange, OverlappedActors[i]->GetName());
		AFoodChest* Chest = Cast<AFoodChest>(OverlappedActors[i]);
		if (Chest) {
			FTransform TmpT = Chest->GetActorTransform();
			return FTransform::FTransform(TmpT.Rotator(), TmpT.GetLocation(), GetActorScale());
		}
		else {
			//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Orange, "Not a chest");
			ASpot* Spot = Cast<ASpot>(OverlappedActors[i]);
			if (Spot) {
				Spot->SetSpotOccupied();
				FTransform TmpT = Spot->GetFoodSpotTransform();
				//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Black, "Transform" + TmpT.ToString());
				return FTransform::FTransform(TmpT.GetRotation(), TmpT.GetLocation(), GetActorScale());
			}
			else {
				//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Orange, "neither a spot");
				i++;
			}
		}
	}
	return FTransform::FTransform(FRotator::MakeFromEuler(FVector(0, 0, GetActorRotation().Euler().Z)), GetActorLocation(), GetActorScale());
}

void APickableItem::SetOnGroundPhysics(bool IsOnGround) {
	//SetActorTickEnabled(IsOnGround);
	StaticMesh->SetSimulatePhysics(IsOnGround);
	StaticMesh->SetCollisionEnabled(IsOnGround ? ECollisionEnabled::QueryAndPhysics : ECollisionEnabled::NoCollision);
	//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, IsOnGround?"true":"false");
}