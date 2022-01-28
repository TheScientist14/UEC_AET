// Fill out your copyright notice in the Description page of Project Settings.

#include "BindPickedItemAnimNotify.h"
#include "GC_UE4CPP/Interfaces/Lifter.h"

void UBindPickedItemAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation){
	if (MeshComp && MeshComp->GetOwner()) {
		ILifter* Picker = Cast<ILifter>(MeshComp->GetOwner());
		if (Picker) {
			Picker->BindPickedUpActor();
		}
	}
}
