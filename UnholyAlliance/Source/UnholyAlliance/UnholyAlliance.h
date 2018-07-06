// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#define EnumToString(EnumClassName, EnumValue) GetEnumValueAsString(FString(TEXT(#EnumClassName)), (EnumValue))

template<typename TEnum>
static FORCEINLINE FString GetEnumValueAsString(const FString& Name, TEnum Value)
{
	const UEnum* enumPtr = FindObject<UEnum>(ANY_PACKAGE, *Name, true);
	if (!enumPtr)
	{
		return FString("Invalid");
	}
	return enumPtr->GetNameByValue((int64)Value).ToString();
}

UENUM(BlueprintType)
enum class EAbilityAimTypes : uint8
{
	AAT_FREE,
	AAT_FIXED,
	AAT_MOVEMENT_BASED,
	AAT_ACTORTARGET,
	AAT_FIXEDCONE,
	AAT_FIXEDSQUARE,
	AAT_INSTANT,
	AAT_NONE
};

UENUM(BlueprintType)
enum class EAbilityKeyTypes : uint8
{
	Ability_1,
	Ability_2,
	Ability_3,
	Ability_4,
};
