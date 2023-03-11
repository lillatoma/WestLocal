// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WItemAttribute.h"
#include "WInventoryItemBase.h"

#include "WSet.generated.h"


/**
 * 
 */
USTRUCT(Blueprintable)
struct WESTLOCAL_API FWSet
{
	GENERATED_BODY()
public:
	FWSet();
	~FWSet();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString SetName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FWCombinedAttributeList OneMemberBonuses;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FWCombinedAttributeList TwoMemberBonuses;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FWCombinedAttributeList ThreeMemberBonuses;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FWCombinedAttributeList FourMemberBonuses;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FWCombinedAttributeList FiveMemberBonuses;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FWCombinedAttributeList SixMemberBonuses;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FWCombinedAttributeList SevenMemberBonuses;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FWCombinedAttributeList EightMemberBonuses;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FWCombinedAttributeList NineMemberBonuses;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FWCombinedAttributeList TenMemberBonuses;

	FWCombinedAttributeList AddTogether(FWCombinedAttributeList A, FWCombinedAttributeList B) const;

	FWCombinedAttributeList CalculateBonuses(int ItemCount) const;

	TArray<int> GetSetItemIndexesFromInventory(class UWInventory* Inventory) const;
};
