// Fill out your copyright notice in the Description page of Project Settings.


#include "UnbindPickedItemAnimNotify.h"
#include "../Picker.h"

void UUnbindPickedItemAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) {
	if (MeshComp && MeshComp->GetOwner()) {
		IPicker* Picker = Cast<IPicker>(MeshComp->GetOwner());
		if (Picker) {
			Picker->UnbindPickedUpActor();
		}
	}
}