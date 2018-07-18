#pragma once

#include "CoreMinimal.h"
#include "UpgradeableParameter.generated.h"

UENUM()
enum class EUpgradeTypes : uint8
{
	// CurrentValue += (Scalar * CurrentValue)
	AddPercentOfMax,
	// CurrentValue += (Scalar * BaseValue)
	AddPercentOfBase,
	// CurrentValue += Scalar
	AddFixedValue,
	// CurrentValue *= Scalar
	Multiply,
	// CurrentValue /= Scalar
	Divide,
	// CurrentValue = BaseValue
	None
};

USTRUCT(Blueprintable, Category = "UpgradeableParameter")
struct FUpgradeableParameter
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UpgradeableParameter")
		float BaseValue;

	UPROPERTY(EditDefaultsOnly, Category = "UpgradeableParameter")
		float Scalar;

	UPROPERTY(EditDefaultsOnly, Category = "UpgradeableParameter")
		EUpgradeTypes UpgradeType;

	UPROPERTY(EditDefaultsOnly, Category = "UpgradeableParameter")
		int32 LevelFrequency;

	UPROPERTY(BlueprintReadWrite, Category = "UpgradeableParameter")
		float CurrentValue;

	//UPROPERTY(BlueprintReadOnly, Category = "UpgradeableParameter")
	//	float MaxValue;

public:
	FUpgradeableParameter() : BaseValue(0), Scalar(0), UpgradeType(EUpgradeTypes::None), LevelFrequency(1), CurrentValue(0) {}

	FUpgradeableParameter(float baseValue, float scalar, EUpgradeTypes upgradeType, int32 levelFrequency, float currentValue)
	{
		BaseValue = baseValue;
		Scalar = scalar;
		UpgradeType = upgradeType;
		LevelFrequency = levelFrequency;
		CurrentValue = currentValue;
	}

	void Upgrade(int32 level)
	{
		if (level == 1)
		{
			CurrentValue = BaseValue;
		}
		else if (LevelFrequency == 0 || (LevelFrequency > 0 && (level % LevelFrequency == 0)))
		{
			switch (UpgradeType)
			{
			case EUpgradeTypes::AddPercentOfMax:
				CurrentValue += FMath::FloorToInt(Scalar * CurrentValue);
				break;
			case EUpgradeTypes::AddPercentOfBase:
				CurrentValue += FMath::FloorToInt(Scalar * BaseValue);
				break;
			case EUpgradeTypes::AddFixedValue:
				CurrentValue += Scalar;
				break;
			case EUpgradeTypes::Multiply:
				CurrentValue = FMath::FloorToInt(CurrentValue * Scalar);
				break;
			case EUpgradeTypes::Divide:
				if (Scalar != 0)
				{
					CurrentValue = FMath::FloorToInt(CurrentValue / Scalar);
				}
				break;
			case EUpgradeTypes::None:
				CurrentValue = BaseValue;
				break;

			default:
				break;
			}
		}
	}
};