// Copyright Dragon Sword Entertainment 2018

#include "Ability.h"

float AAbility::GetRange() { return Range.CurrentValue; }

// Sets default values
AAbility::AAbility()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetReplicates(true);
	SetReplicateMovement(true);
}

// Called when the game starts or when spawned
void AAbility::BeginPlay()
{
	Super::BeginPlay();
	Range.Init(Range.BaseValue);
}

// Called every frame
void AAbility::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAbility::Activate()
{
	UE_LOG(LogTemp, Warning, TEXT("Ability Activate Called."));
	// TODO: Check if ability can be cast

	if (AbilityAimType == EAbilityAimTypes::AAT_INSTANT)
	{
		CastInternal();
	}

	// TODO: Add cast timers
}

void AAbility::CastInternal()
{
	Cast();
}

void AAbility::Cast_Implementation()
{
	// Overriden Blueprint function
}

