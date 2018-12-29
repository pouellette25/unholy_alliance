// Copyright Dragon Sword Entertainment 2018

#include "EnemyCharacter.h"

float AEnemyCharacter::GetAggroRange() { return AggroRange.GetCurrentValue(); }

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	AggroRange.Init(AggroRange.BaseValue);
}