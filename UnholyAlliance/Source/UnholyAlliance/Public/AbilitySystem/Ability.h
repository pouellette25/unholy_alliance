// Copyright Dragon Sword Entertainment 2018

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UnholyAlliance.h"
#include "Structs/UpgradeableParameter.h"
#include "Ability.generated.h"

UCLASS()
class UNHOLYALLIANCE_API AAbility : public AActor
{
	GENERATED_BODY()
	
private: 
	void CastInternal();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintNativeEvent, Category = "Ability")
		void Cast();

	UPROPERTY(EditDefaultsOnly, Category = "Ability")
		EAbilityAimTypes AbilityAimType;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "UpgradeableParameters")
		FUpgradeableParameter BaseDamage;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "UpgradeableParameters")
		FUpgradeableParameter CooldownTime;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "UpgradeableParameters")
		FUpgradeableParameter Range;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "UpgradeableParameters")
		FUpgradeableParameter CastTime;

public:	
	// Sets default values for this actor's properties
	AAbility();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Activate();
};
