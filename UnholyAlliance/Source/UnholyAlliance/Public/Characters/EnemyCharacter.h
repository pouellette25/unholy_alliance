// Copyright Dragon Sword Entertainment 2018

#pragma once

#include "CoreMinimal.h"
#include "Characters/UnholyAllianceCharacterBase.h"
#include "Structs/UpgradeableParameter.h"
#include "EnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class UNHOLYALLIANCE_API AEnemyCharacter : public AUnholyAllianceCharacterBase
{
	GENERATED_BODY()
	
	
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		FUpgradeableParameter AggroRange;

public:

	UFUNCTION(BlueprintCallable, Category = "Stats")
		float GetAggroRange();	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
