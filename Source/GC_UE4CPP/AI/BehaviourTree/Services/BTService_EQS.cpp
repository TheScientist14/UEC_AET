// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_EQS.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Services/BTService_RunEQS.h"
#include "EnvironmentQuery/EnvQueryManager.h"
#include "GC_UE4CPP/AI/EnemyController.h"

UBTService_EQS::UBTService_EQS(const FObjectInitializer& ObjectInitializer)
{
	NodeName = TEXT("Custom EQS Query");
	bNotifyBecomeRelevant = true;
	bNotifyCeaseRelevant = true;
	bCreateNodeInstance = true;
}

void UBTService_EQS::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::OnBecomeRelevant(OwnerComp, NodeMemory);
	UE_LOG(LogTemp, Warning, TEXT("Testing for Cast<AEnemyController>"))
	EnemyAI = Cast<AEnemyController>(OwnerComp.GetAIOwner());
	QueryRequest = FEnvQueryRequest(FindHidingSpotEQS, EnemyAI);
}

void UBTService_EQS::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	if (EnemyAI)
	{
		RunQuery(NodeMemory);
		UE_LOG(LogTemp, Warning, TEXT("Testing for if (EnemyAI)"))
		if(Score == 1)
		{
			UE_LOG(LogTemp, Warning, TEXT("Testing for player vision true"))
			EnemyAI->GetBlackboardComponent()->SetValueAsBool("SeesPlayer", true);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Testing for player vision false"))
			EnemyAI->GetBlackboardComponent()->SetValueAsBool("SeesPlayer", false);
		}

		if (EnemyAI->GetBlackboardComponent()->GetValueAsBool("SeesPlayer"))
		{
			UE_LOG(LogTemp, Warning, TEXT("Testing for Position update"))
			
			EnemyAI->GetBlackboardComponent()->SetValueAsVector("PLayerPosition", MoveLocation);
		}		
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("EnemyAI cast failed"))
	}
}

void UBTService_EQS::RunQuery(uint8* NodeMemory)
{
	CustomFBTEQSServiceMemory* MyMemory = CastInstanceNodeMemory<CustomFBTEQSServiceMemory>(NodeMemory);

	// Trigger new query only if the previous one has already finished
	if (MyMemory->RequestID == INDEX_NONE)
	{
		MyMemory->RequestID = QueryRequest.Execute(EEnvQueryRunMode::AllMatching, this, &UBTService_EQS::HandleQueryResult);
	}
	
}

void UBTService_EQS::InitializeMemory(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, EBTMemoryInit::Type InitType) const
{
	FBTEQSServiceMemory* MyMemory = CastInstanceNodeMemory<FBTEQSServiceMemory>(NodeMemory);
	check(MyMemory);
	MyMemory->RequestID = INDEX_NONE;
}

void UBTService_EQS::OnCeaseRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	FBTEQSServiceMemory* MyMemory = CastInstanceNodeMemory<FBTEQSServiceMemory>(NodeMemory);
	check(MyMemory);

	if (MyMemory->RequestID != INDEX_NONE)
	{
		UWorld* World = OwnerComp.GetWorld();
		if (World)
		{
			// make EQS abort that query
			UEnvQueryManager* EQSManager = UEnvQueryManager::GetCurrent(World);
			check(EQSManager);
			EQSManager->AbortQuery(MyMemory->RequestID);
		}

		MyMemory->RequestID = INDEX_NONE;
	}
	
	Super::OnCeaseRelevant(OwnerComp, NodeMemory);
}

void UBTService_EQS::CleanupMemory(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, EBTMemoryClear::Type CleanupType) const
{
	const CustomFBTEQSServiceMemory* MyMemory = CastInstanceNodeMemory<CustomFBTEQSServiceMemory>(NodeMemory);
	check(MyMemory);
	ensure(MyMemory->RequestID == INDEX_NONE);
}

void UBTService_EQS::HandleQueryResult(TSharedPtr<FEnvQueryResult> result)
{
	if (result->IsAborted())
	{
		return;
	}

	AActor* MyOwner = Cast<AActor>(result->Owner.Get());
	if (APawn* PawnOwner = Cast<APawn>(MyOwner))
	{
		MyOwner = PawnOwner->GetController();
	}
	
	UBehaviorTreeComponent* BTComp = MyOwner ? MyOwner->FindComponentByClass<UBehaviorTreeComponent>() : NULL;
	if (!BTComp)
	{
		UE_LOG(LogBehaviorTree, Warning, TEXT("Unable to find behavior tree to notify about finished query from %s!"), *GetNameSafe(MyOwner));
		return;
	}
	
	FBTEQSServiceMemory* MyMemory = CastInstanceNodeMemory<FBTEQSServiceMemory>(BTComp->GetNodeMemory(this, BTComp->FindInstanceContainingNode(this)));
	check(MyMemory);
	ensure(MyMemory->RequestID != INDEX_NONE);
	
	Score = result->GetItemScore(0);
	MoveLocation = result->GetItemAsLocation(0);
	
	MyMemory->RequestID = INDEX_NONE;
}
