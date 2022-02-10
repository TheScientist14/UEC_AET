// Fill out your copyright notice in the Description page of Project Settings.


#include "GoblinCharacter.h"
#include "EnemyController.h"
#include "GC_UE4CPP/Game/MainGameState.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SpotLightComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GC_UE4CPP/Characters/PickUpAbilityComponent.h"
#include "GC_UE4CPP/Characters/PlayerCharacter.h"
#include "GC_UE4CPP/Game/MainGameMode.h"
#include "GC_UE4CPP/MapItems/PickableItem.h"
#include "GC_UE4CPP/MapItems/Spot.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AGoblinCharacter::AGoblinCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	PickUpAbilityComponent = CreateDefaultSubobject<UPickUpAbilityComponent>(TEXT("PickUpBehaviour"));
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	SpotLightVision = CreateDefaultSubobject<USpotLightComponent>("Point light vision cone");
	SpotLightVision->SetupAttachment(RootComponent);
	
}



// Called when the game starts or when spawned
void AGoblinCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	FoodOnHand = nullptr;

	AMainGameMode* GameMode = Cast<AMainGameMode>(UGameplayStatics::GetGameMode(this));
	GameMode->GameModeBeginPlayFinished.AddUObject(this, &AGoblinCharacter::InitBlackboard);
	GameState = Cast<AMainGameState>(GetWorld()->GetGameState());
	GameMode->OnGameFinished.AddUObject(this, &AGoblinCharacter::OnGameEnded);

	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AGoblinCharacter::OnGoblinCollision);
	
}

// Called every frame
void AGoblinCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGoblinCharacter::OnGoblinCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	if(Cast<APlayerCharacter>(OtherActor))
	{
		AMainGameMode* MainGameMode = Cast<AMainGameMode>(UGameplayStatics::GetGameMode(this));
		if(MainGameMode)
		{
			MainGameMode->EndGameDefeat();
		}
	}
	
}

// Called to bind functionality to input
void AGoblinCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AGoblinCharacter::GetNextSpot()
{
	AMainGameMode* MainGameMode = Cast<AMainGameMode>(GetWorld()->GetAuthGameMode());
	if(IsValid(MainGameMode))
	{

		ASpot* Temp = MainGameMode->GetRandomSpot();
		if(IsValid(Temp))
		{
			Spot = Temp;
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to Get spot"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to cast "));
	}
	
	
}

void AGoblinCharacter::InteractFood()
{
	if (IsValid(FoodOnHand))
	{
		FoodOnHand->OnInteract(this);
	}
}

void AGoblinCharacter::SpawnFood(UClass* PrmFood)
{
	if (FoodOnHand)
	{
		FoodOnHand = nullptr;
	}
	FoodOnHand = GetWorld()->SpawnActor<APickableItem>(PrmFood, GetActorLocation(), GetActorRotation(), SpawnInfo);
	FoodOnHand->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale,
		"RightHandSocket");
	FTransform OffsetTarget = FoodOnHand->GetRightHandAnchor();
	FoodOnHand->SetActorRelativeLocation(-OffsetTarget.GetLocation());
	FoodOnHand->SetActorRelativeRotation(OffsetTarget.GetRotation());
	FoodOnHand->SetIsCurrentlyPickable(false);
	FoodOnHand->SetOnGroundPhysics(false);
	PickUpAbilityComponent->PickedUpActor = FoodOnHand;
	FoodOnHand->SetLifterPickUpAbility(PickUpAbilityComponent);
	FoodOnHand->SetOwner(this);
	GetCharacterMovement()->MaxWalkSpeed /= 2;
}

void AGoblinCharacter::PutDownFood()
{
	if(FoodOnHand != nullptr)
	{
		FoodOnHand->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
		FoodOnHand->SetIsCurrentlyPickable(true);
		FoodOnHand->SetOnGroundPhysics(true);
		PickUpAbilityComponent->PickedUpActor = nullptr;
		FoodOnHand->SetLifterPickUpAbility(nullptr);
		GetCharacterMovement()->MaxWalkSpeed *= 2;
	} 
}

void AGoblinCharacter::OnGameEnded(bool HasGameEnded, bool HasWon)
{
	GetController()->UnPossess();
}

void AGoblinCharacter::InitBlackboard() {
	AEnemyController* Controller = Cast<AEnemyController>(GetController());
	if (Controller) {
		Controller->GetBlackboardComponent()->SetValueAsVector("Spawn", GetActorLocation());
		Controller->GetBlackboardComponent()->SetValueAsBool("Wait", Wait);
		Controller->GetBlackboardComponent()->SetValueAsBool("NeedFood", true);
	}
}
