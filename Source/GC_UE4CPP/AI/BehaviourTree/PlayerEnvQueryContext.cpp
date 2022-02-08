// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerEnvQueryContext.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_Actor.h"
#include "GC_UE4CPP/Characters/PlayerCharacter.h"
#include "Kismet/GameplayStatics.h"

void UPlayerEnvQueryContext::ProvideContext(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& ContextData) const
{
	Super::ProvideContext(QueryInstance, ContextData);

	ACharacter* temp = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

	if (temp)
	{
		// I don't understand why cast is needed ¯\_(ツ)_/¯
		UEnvQueryItemType_Actor::SetContextHelper(ContextData, temp);
	}
	
}
