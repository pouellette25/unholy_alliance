// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UnholyAllianceGameMode.generated.h"

UCLASS(minimalapi)
class AUnholyAllianceGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:
	virtual void StartPlay() override;

public:
	AUnholyAllianceGameMode();

	void GetHttpData();
};



