// Copyright Dragon Sword Entertainment 2018

#include "UA_Ability.h"


// Sets default values
AUA_Ability::AUA_Ability()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AUA_Ability::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUA_Ability::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AUA_Ability::Activate()
{
	// TODO: Add cast timers
	CastInternal();
}


void AUA_Ability::CastInternal()
{
	Cast();
}

void AUA_Ability::Cast_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("Cast function called"));
}

