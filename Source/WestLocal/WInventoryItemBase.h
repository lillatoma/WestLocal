// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WSkillSet.h"
#include "UObject/NoExportTypes.h"
#include "WItemAttribute.h"
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
USTRUCT(Blueprintable)
struct WESTLOCAL_API FWInventoryItemBase
{
	GENERATED_BODY()
public:
	FWInventoryItemBase();
	~FWInventoryItemBase();

	int SetIndex = -1;
	
	///FString OriginalItemIdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ItemIdentifierName;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ItemName;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ItemDescription;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int MinLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EInvSlot Slot = EInvSlot::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FWItemAttribute> FixedAttributes;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FWLeveledItemAttribute> LeveledAttributes;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Sellable;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Upgradable;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Consumable;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Count;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Price;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int ItemLevel = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString SetName;

	void MakeEqual(FWInventoryItemBase* OtherItem);

	bool IsUpgradable();

	FWInventoryItemBase GetUpgradedVersion();

	bool Equals(FWInventoryItemBase* right) const;

	bool Is(FString Name) const;

	bool IsPartOfSet() const;

	bool IsPartOfSet(FString OtherSet) const;

	bool IsAuctionable() const;

	FWSkillSet CalculateSkills(int PlayerLevel) const;

	FString GetItemName() const;
};
