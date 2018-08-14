// Copyright Dragon Sword Entertainment 2018

#include "UA_PlayerState.h"
#include "UnrealNetwork.h"

float AUA_PlayerState::GetHealth() { return Health.CurrentValue; }

void AUA_PlayerState::SetHealth(float newHealth)
{
	Health.CurrentValue = newHealth;
}

void AUA_PlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION(AUA_PlayerState, Health, COND_OwnerOnly);
}


