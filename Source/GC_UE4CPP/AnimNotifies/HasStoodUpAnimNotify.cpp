// Fill out your copyright notice in the Description page of Project Settings.


#include "HasStoodUpAnimNotify.h"

#include "GC_UE4CPP/Characters/SitDownAbilityComponent.h"

void UHasStoodUpAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) {
	if (MeshComp && MeshComp->GetOwner()) {
		USitDownAbilityComponent* SitDownAbility = MeshComp->GetOwner()->FindComponentByClass<USitDownAbilityComponent>();
		if (SitDownAbility) {
			SitDownAbility->OnStandUp();
		}
	}
}