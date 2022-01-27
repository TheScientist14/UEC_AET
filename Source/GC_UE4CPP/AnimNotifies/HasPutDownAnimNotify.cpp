// Fill out your copyright notice in the Description page of Project Settings.


#include "HasPutDownAnimNotify.h"
#include "../Picker.h"

void UHasPutDownAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) {
	if (MeshComp && MeshComp->GetOwner()) {
		IPicker* Picker = Cast<IPicker>(MeshComp->GetOwner());
		if (Picker) {
			Picker->OnHasPutDown();
		}
	}
}