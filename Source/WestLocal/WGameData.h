// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WInventoryItemBase.h"
#include "Engine/DataAsset.h"
#include "WGameData.generated.h"

/**
 * 
 */
UCLASS()
class WESTLOCAL_API UWGameData : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
		int SomeNum;
	UPROPERTY(EditAnywhere)
		TArray<int> SomeArray;
	UPROPERTY(EditAnywhere)
		TArray<FWInventoryItemBase> Items;
};
