// Copyright Dragon Sword Entertainment 2018

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Structs/UpgradeableParameter.h"
#include "Structs/TakeHitInfo.h"
#include "UnholyAllianceCharacterBase.generated.h"

UCLASS()
class UNHOLYALLIANCE_API AUnholyAllianceCharacterBase : public ACharacter
{
	GENERATED_BODY()

private:

	bool bIsDying;
	void SetRagdollPhysics();
	bool CanDie(float KillingDamage, FDamageEvent const& DamageEvent, AController* Killer, AActor* DamageCauser) const;
	void OnDeath(float KillingDamage, struct FDamageEvent const& DamageEvent, class APawn* PawnInstigator, class AActor* DamageCauser);
	void ReplicateHit(float Damage, struct FDamageEvent const& DamageEvent, class APawn* PawnInstigator, class AActor* DamageCauser, bool bKilled);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Replicate where this pawn was last hit and damaged */
	UPROPERTY(Transient, ReplicatedUsing = OnRep_LastTakeHitInfo)
		FTakeHitInfo LastTakeHitInfo;

	/** play hit or death on client */
	UFUNCTION()
		void OnRep_LastTakeHitInfo();

	/** Time at which point the last take hit info for the actor times out and won't be replicated; Used to stop join-in-progress effects all over the screen */
	float LastTakeHitTimeTimeout;

	UPROPERTY(EditDefaultsOnly, ReplicatedUsing = OnRep_Health, Category = "Stats")
		FUpgradeableParameter Health;

	UFUNCTION()
		void OnRep_Health();

	UFUNCTION(BlueprintImplementableEvent)
		void OnHealthChanged();

	bool Die(float KillingDamage, struct FDamageEvent const& DamageEvent, class AController* Killer, class AActor* DamageCauser);

public:	
	// Sets default values for this character's properties
	AUnholyAllianceCharacterBase();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Stats")
		float GetHealth();

	UFUNCTION(BlueprintCallable, Category = "Stats")
		float GetMaxHealth();
	
	/** Take damage, handle death */
	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser) override;

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const;
};
