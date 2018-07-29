// Copyright Dragon Sword Entertainment 2018

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Structs/UpgradeableParameter.h"
#include "PlayerStats.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class UNHOLYALLIANCE_API UPlayerStats : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "UpgradeableParameters")
		FUpgradeableParameter Health;
	
};
