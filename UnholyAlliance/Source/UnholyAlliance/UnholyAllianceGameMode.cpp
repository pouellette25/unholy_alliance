// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "UnholyAllianceGameMode.h"
#include "UnholyAllianceCharacter.h"
#include "HttpService.h"
#include "UObject/ConstructorHelpers.h"

AUnholyAllianceGameMode::AUnholyAllianceGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AUnholyAllianceGameMode::StartPlay()
{
	Super::StartPlay();

	//EAbilityAimTypes AimType = EAbilityAimTypes::AAT_INSTANT;

	//UE_LOG(LogTemp, Warning, TEXT("Aim Type: %s"), *EnumToString(EAbilityAimTypes, AimType));

	GetHttpData();
	GetHttpData();
}

void AUnholyAllianceGameMode::GetHttpData()
{
	auto HttpService = &UHttpService::GetInstance();

	if (HttpService)
	{
		HttpService->Get(HttpService->GetUrl);
	}
}