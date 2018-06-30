// Copyright Dragon Sword Entertainment 2018

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UnholyAlliance.h"
#include "UA_Ability.generated.h"

UCLASS()
class UNHOLYALLIANCE_API AUA_Ability : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUA_Ability();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Ability")
		EAbilityAimTypes AbilityAimType;

	/* Blueprint function that is called when the cast time is complete*/
	UFUNCTION(BlueprintNativeEvent, Category = "Ability")
		void Cast();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Activate();
	
private:
	void CastInternal();
};
