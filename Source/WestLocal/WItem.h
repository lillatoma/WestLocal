// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WItemAttribute.h"
#include "WItem.generated.h"



/**
 * 
 */
USTRUCT(Blueprintable)
struct WESTLOCAL_API FWItem
{
	GENERATED_BODY()
public:
	FWItem();
	~FWItem();

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ItemIdentifierName;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ItemName;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ItemDescription;
	
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


	bool Equals(FWItem* right);
};
