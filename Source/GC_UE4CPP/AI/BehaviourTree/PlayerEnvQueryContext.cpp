// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerEnvQueryContext.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_Actor.h"
#include "Kismet/GameplayStatics.h"

void UPlayerEnvQueryContext::ProvideContext(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& ContextData) const
{
	Super::ProvideContext(QueryInstance, ContextData);

    // I don't understand why cast is needed ¯\_(ツ)_/¯
	UEnvQueryItemType_Actor::SetContextHelper(ContextData,
	                                          (AActor*)UGameplayStatics::GetPlayerCharacter(
		                                          QueryInstance.Owner.Get(), 0));
}
