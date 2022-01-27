// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerEnvQueryContext.h"

#include "AIC_Enemy_EQS.h"
#include "Characters/PlayerCharacter.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_Actor.h"
#include "Kismet/GameplayStatics.h"

void UPlayerEnvQueryContext::ProvideContext(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& ContextData) const
{
	Super::ProvideContext(QueryInstance, ContextData);
 
	//Get the Owner of this Query and cast it to an actor
	//Then, get the actor's controller and cast to it our AIController
	//This code works for our case but avoid that many casts and one-liners in cpp.
	//AAIC_Enemy_EQS* AICon = Cast<AAIC_Enemy_EQS>((Cast<AActor>((QueryInstance.Owner).Get())->GetInstigatorController()));
 
	//if (AICon && AICon->GetPlayer())
	//{
		//Set the context SeeingPawn to the provided context data
		UEnvQueryItemType_Actor::SetContextHelper(ContextData, UGameplayStatics::GetPlayerCharacter(QueryInstance.Owner.Get(), 0));

	//UGameplayStatics::GetPlayerPawn(Cast<AActor>((QueryInstance.Owner).Get())->GetInstigatorController(), 0)
	//}
}
