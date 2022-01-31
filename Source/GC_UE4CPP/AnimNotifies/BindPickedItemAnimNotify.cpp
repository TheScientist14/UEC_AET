// Fill out your copyright notice in the Description page of Project Settings.

#include "BindPickedItemAnimNotify.h"
#include "GC_UE4CPP/Characters/PickUpAbilityComponent.h"

void UBindPickedItemAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation){
	if (MeshComp && MeshComp->GetOwner()) {
		UPickUpAbilityComponent* LifterPickUpAbility = MeshComp->GetOwner()->FindComponentByClass<UPickUpAbilityComponent>();
		if (LifterPickUpAbility) {
			LifterPickUpAbility->BindPickedUpActor();
		}
	}
}
