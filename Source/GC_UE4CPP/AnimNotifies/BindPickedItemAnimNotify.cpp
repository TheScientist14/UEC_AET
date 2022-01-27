// Fill out your copyright notice in the Description page of Project Settings.

#include "BindPickedItemAnimNotify.h"
#include "../Picker.h"

void UBindPickedItemAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation){
	if (MeshComp && MeshComp->GetOwner()) {
		IPicker* Picker = Cast<IPicker>(MeshComp->GetOwner());
		if (Picker) {
			Picker->BindPickedUpActor();
		}
	}
}