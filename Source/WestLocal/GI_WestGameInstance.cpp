// Fill out your copyright notice in the Description page of Project Settings.


#include "GI_WestGameInstance.h"

void UGI_WestGameInstance::PregenerateShopItems()
{
	for(int i = 0; i < 10; i++)
		ShopItems.Add(FWInventoryItemBase());

	RefreshShopItemForSlotSetted(GameData->ItemSets[FMath::RandRange(0, GameData->ItemSets.Num() - 1)], EInvSlot::Hat);
	RefreshShopItemForSlotSetted(GameData->ItemSets[FMath::RandRange(0, GameData->ItemSets.Num() - 1)], EInvSlot::Neck);
	RefreshShopItemForSlotSetted(GameData->ItemSets[FMath::RandRange(0, GameData->ItemSets.Num() - 1)], EInvSlot::Body);
	RefreshShopItemForSlotSetted(GameData->ItemSets[FMath::RandRange(0, GameData->ItemSets.Num() - 1)], EInvSlot::LeftHand);
	RefreshShopItemForSlotSetted(GameData->ItemSets[FMath::RandRange(0, GameData->ItemSets.Num() - 1)], EInvSlot::RightHand);
	RefreshShopItemForSlotSetted(GameData->ItemSets[FMath::RandRange(0, GameData->ItemSets.Num() - 1)], EInvSlot::Belt);
	RefreshShopItemForSlotSetted(GameData->ItemSets[FMath::RandRange(0, GameData->ItemSets.Num() - 1)], EInvSlot::Pants);
	RefreshShopItemForSlotSetted(GameData->ItemSets[FMath::RandRange(0, GameData->ItemSets.Num() - 1)], EInvSlot::Shoes);
	RefreshShopItemForSlotSetted(GameData->ItemSets[FMath::RandRange(0, GameData->ItemSets.Num() - 1)], EInvSlot::Horse);
	RefreshShopItemForSlotSetted(GameData->ItemSets[FMath::RandRange(0, GameData->ItemSets.Num() - 1)], EInvSlot::Product);
}

void UGI_WestGameInstance::RefreshShopItems(int CurrentLevel)
{
	float F = FMath::RandRange(0.f, 1.f);
	if (F < SetAppearanceChance)
		RefreshShopItemsWithSetItems();
	else {
		RefreshShopItemForSlot(CurrentLevel, EInvSlot::Hat);
		RefreshShopItemForSlot(CurrentLevel, EInvSlot::Neck);
		RefreshShopItemForSlot(CurrentLevel, EInvSlot::Body);
		RefreshShopItemForSlot(CurrentLevel, EInvSlot::LeftHand);
		RefreshShopItemForSlot(CurrentLevel, EInvSlot::RightHand);
		RefreshShopItemForSlot(CurrentLevel, EInvSlot::Belt);
		RefreshShopItemForSlot(CurrentLevel, EInvSlot::Pants);
		RefreshShopItemForSlot(CurrentLevel, EInvSlot::Shoes);
		RefreshShopItemForSlot(CurrentLevel, EInvSlot::Horse);
		RefreshShopItemForSlot(CurrentLevel, EInvSlot::Product);
	}
}

void UGI_WestGameInstance::RefreshShopItemForSlot(int CurrentLevel, EInvSlot Slot)
{
	FWInventoryItemBase Item = GameData->FindItemWithMaxLevelForSlot(CurrentLevel + LevelAddOnCurrentLevel, Slot);

	float PriceMultiplier = FMath::RandRange(1.0f, 8.f);

	switch (Slot)
	{
	case EInvSlot::Hat:
		ShopItems[0] = Item;
		ShopPrices[0] = Item.Price * PriceMultiplier;
		break;
	case EInvSlot::Neck:
		ShopItems[1] = Item;
		ShopPrices[1] = Item.Price * PriceMultiplier;
		break;
	case EInvSlot::Body:
		ShopItems[2] = Item;
		ShopPrices[2] = Item.Price * PriceMultiplier;
		break;
	case EInvSlot::LeftHand:
		ShopItems[3] = Item;
		ShopPrices[3] = Item.Price * PriceMultiplier;
		break;
	case EInvSlot::RightHand:
		ShopItems[4] = Item;
		ShopPrices[4] = Item.Price * PriceMultiplier;
		break;
	case EInvSlot::Belt:
		ShopItems[5] = Item;
		ShopPrices[5] = Item.Price * PriceMultiplier;
		break;
	case EInvSlot::Pants:
		ShopItems[6] = Item;
		ShopPrices[6] = Item.Price * PriceMultiplier;
		break;
	case EInvSlot::Shoes:
		ShopItems[7] = Item;
		ShopPrices[7] = Item.Price * PriceMultiplier;
		break;
	case EInvSlot::Horse:
		ShopItems[8] = Item;
		ShopPrices[8] = Item.Price * PriceMultiplier;
		break;
	case EInvSlot::Product:
		ShopItems[9] = Item;
		ShopPrices[9] = Item.Price * PriceMultiplier;
		break;
	}
}

void UGI_WestGameInstance::RefreshShopItemsWithSetItems()
{
	FWSet Set = GameData->ItemSets[FMath::RandRange(0, GameData->ItemSets.Num() - 1)];

	RefreshShopItemForSlotSetted(Set, EInvSlot::Hat);
	RefreshShopItemForSlotSetted(Set, EInvSlot::Neck);
	RefreshShopItemForSlotSetted(Set, EInvSlot::Body);
	RefreshShopItemForSlotSetted(Set, EInvSlot::LeftHand);
	RefreshShopItemForSlotSetted(Set, EInvSlot::RightHand);
	RefreshShopItemForSlotSetted(Set, EInvSlot::Belt);
	RefreshShopItemForSlotSetted(Set, EInvSlot::Pants);
	RefreshShopItemForSlotSetted(Set, EInvSlot::Shoes);
	RefreshShopItemForSlotSetted(Set, EInvSlot::Horse);
	RefreshShopItemForSlotSetted(Set, EInvSlot::Product);
}

void UGI_WestGameInstance::RefreshShopItemForSlotSetted(FWSet Set, EInvSlot Slot)
{

	if (!GameData->IsThereSetItemForSlot(Set, Slot))
	{
		RefreshShopItemForSlot(25, Slot);
		return;
	}

	FWInventoryItemBase Item = GameData->FindSetItemForSlot(Set, Slot);

	float PriceMultiplier = FMath::RandRange(1.0f, 8.f);

	switch (Slot)
	{
	case EInvSlot::Hat:
		ShopItems[0] = Item;
		ShopPrices[0] = Item.Price * PriceMultiplier;
		break;
	case EInvSlot::Neck:
		ShopItems[1] = Item;
		ShopPrices[1] = Item.Price * PriceMultiplier;
		break;
	case EInvSlot::Body:
		ShopItems[2] = Item;
		ShopPrices[2] = Item.Price * PriceMultiplier;
		break;
	case EInvSlot::LeftHand:
		ShopItems[3] = Item;
		ShopPrices[3] = Item.Price * PriceMultiplier;
		break;
	case EInvSlot::RightHand:
		ShopItems[4] = Item;
		ShopPrices[4] = Item.Price * PriceMultiplier;
		break;
	case EInvSlot::Belt:
		ShopItems[5] = Item;
		ShopPrices[5] = Item.Price * PriceMultiplier;
		break;
	case EInvSlot::Pants:
		ShopItems[6] = Item;
		ShopPrices[6] = Item.Price * PriceMultiplier;
		break;
	case EInvSlot::Shoes:
		ShopItems[7] = Item;
		ShopPrices[7] = Item.Price * PriceMultiplier;
		break;
	case EInvSlot::Horse:
		ShopItems[8] = Item;
		ShopPrices[8] = Item.Price * PriceMultiplier;
		break;
	case EInvSlot::Product:
		ShopItems[9] = Item;
		ShopPrices[9] = Item.Price * PriceMultiplier;
		break;
	}

}
