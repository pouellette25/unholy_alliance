// Copyright Dragon Sword Entertainment 2018

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "Structs/UpgradeableParameter.h"
#include "UA_PlayerState.generated.h"

/**
 * 
 */
UCLASS()
class UNHOLYALLIANCE_API AUA_PlayerState : public APlayerState
{
	GENERATED_BODY()	
	
public:
	UFUNCTION(BlueprintCallable, Category = "Stats")
		float GetHealth();
	void SetHealth(float newHealth);

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

protected:

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Replicated, Category = "UpgradeableParameters")
		FUpgradeableParameter Health;
	
};
