// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "WGameData.h"
#include "GI_WestGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class WESTLOCAL_API UGI_WestGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		UWGameData* GameData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int PageRefreshCost = 2000;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int LevelAddOnCurrentLevel = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float SetAppearanceChance = 0.1f;

	UPROPERTY(VisibleAnywhere)
		TArray<FWInventoryItemBase> ShopItems;

	UPROPERTY(VisibleAnywhere)
		TArray<int> ShopPrices;

	void PregenerateShopItems();

	void RefreshShopItems(int CurrentLevel);

	void RefreshShopItemForSlot(int CurrentLevel, EInvSlot Slot);

	void RefreshShopItemsWithSetItems();

	void RefreshShopItemForSlotSetted(FWSet Set, EInvSlot Slot);
};
