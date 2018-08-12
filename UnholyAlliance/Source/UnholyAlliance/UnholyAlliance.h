// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"

#define COLLISION_PROJECTILE	ECC_GameTraceChannel1

//// General Logging
DECLARE_LOG_CATEGORY_EXTERN(UA, Log, All)
//
//// Game Mode Logging
//DECLARE_LOG_CATEGORY_EXTERN(OL_Game, Log, All)
//
//// Menu Logging
//DECLARE_LOG_CATEGORY_EXTERN(OL_Menu, Log, All)
//
//// HUD Logging
//DECLARE_LOG_CATEGORY_EXTERN(OL_HUD, Log, All)

#define ISDEDICATED (GEngine->GetNetMode(GetWorld()) == NM_DedicatedServer)
#define ISLISTEN (GEngine->GetNetMode(GetWorld()) == NM_ListenServer)
#define ISSTANDALONE (GEngine->GetNetMode(GetWorld()) == NM_Standalone)
#define ISCLIENT (GEngine->GetNetMode(GetWorld()) == NM_Client)

#define NETMODE_WORLD (((GEngine == NULL) || (GetWorld() == NULL)) ? TEXT("") \
	: ISCLIENT ? TEXT("[Client] ") \
	: ISLISTEN ? TEXT("[ListenServer] ") \
	: ISDEDICATED ? TEXT("[DedicatedServer] ") \
	: TEXT("[Standalone] "))

#if _MSC_VER
#define FUNC_NAME    TEXT(__FUNCTION__)
#else // FIXME - GCC?
#define FUNC_NAME    TEXT(__func__)
#endif

#define TRACE(CategoryName, Format, ...) \
{\
	SET_WARN_COLOR(COLOR_CYAN); \
	FString Msg = FString::Printf(TEXT(Format), ##__VA_ARGS__); \
	UE_LOG(CategoryName, Warning, TEXT("%s%s() : %s"), NETMODE_WORLD, FUNC_NAME, *Msg); \
	CLEAR_WARN_COLOR(); \
}

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
