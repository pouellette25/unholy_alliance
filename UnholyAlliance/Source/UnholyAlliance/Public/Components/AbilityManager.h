// Copyright Dragon Sword Entertainment 2018

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AbilityManager.generated.h"

class AUA_Ability;

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
		void ActivateAbility(AUA_Ability* Ability);
		
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Abilities")
		TArray<TSubclassOf<AUA_Ability>> AbilityClasses;

private:
	TArray<AUA_Ability*> ActiveAbilities;
};
