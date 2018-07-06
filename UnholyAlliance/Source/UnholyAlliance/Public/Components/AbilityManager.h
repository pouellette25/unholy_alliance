// Copyright Dragon Sword Entertainment 2018

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UnholyAlliance.h"
#include "AbilityManager.generated.h"

class AAbility;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNHOLYALLIANCE_API UAbilityManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAbilityManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Abilities")
		void ActivateAbility(EAbilityKeyTypes KeyType);
		
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Abilities")
		TMap<EAbilityKeyTypes, TSubclassOf<AAbility>> AbilityMappings;

private:
	TMap<EAbilityKeyTypes, AAbility*> Abilities;
};
