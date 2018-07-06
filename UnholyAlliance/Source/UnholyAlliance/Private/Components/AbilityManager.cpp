// Copyright Dragon Sword Entertainment 2018

#include "AbilityManager.h"
#include "AbilitySystem/Ability.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UAbilityManager::UAbilityManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAbilityManager::BeginPlay()
{
	Super::BeginPlay();

	if (AbilityMappings.Num() > 0)
	{
		for (auto AbilityMap : AbilityMappings)
		{
			auto AbilityObject = AbilityMap.Value->GetDefaultObject();
			auto AbilityClass = AbilityObject->GetClass();

			auto Owner = GetOwner();

			UE_LOG(LogTemp, Warning, TEXT("Owner = %s"), *Owner->GetName());

			const FVector Location = Owner->GetActorLocation();
			const FRotator Rotation = Owner->GetActorRotation();

			auto Ability = GetWorld()->SpawnActor(AbilityClass, &Location, &Rotation);

			if (!ensure(Ability)) { return; }

			Abilities.Add(AbilityMap.Key, Cast<AAbility>(Ability));
		}
	}
}


// Called every frame
void UAbilityManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAbilityManager::ActivateAbility(EAbilityKeyTypes KeyType)
{
	if (Abilities.Num() > 0)
	{
		auto AbilityToActivate = Abilities[KeyType];

		if (!ensure(AbilityToActivate)) { return; }

		AbilityToActivate->Activate();
	}
}

