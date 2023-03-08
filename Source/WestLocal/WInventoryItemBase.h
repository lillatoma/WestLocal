// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WInventoryItemBase.generated.h"

UENUM(BlueprintType)
enum class EInvSlot : uint8
{
	None,
	Hat,
	Neck,
	Body,
	LeftHand,
	RightHand,
	Belt,
	Pants,
	Shoes,
	Horse,
	Product
};

/**
 * 
 */
UCLASS()
class WESTLOCAL_API UWInventoryItemBase : public UObject
{
	GENERATED_BODY()
public:
	UWInventoryItemBase();
	~UWInventoryItemBase();

	bool Consumable;

	FString ItemIdentifierName;
	FString ItemName;
	FString ItemDescription;

	EInvSlot Slot = EInvSlot::None;

	unsigned int Count;

	bool Equals(UWInventoryItemBase* right);
};
