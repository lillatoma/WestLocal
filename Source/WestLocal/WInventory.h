// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WInventoryItemBase.h"
#include "UObject/NoExportTypes.h"
#include "WInventory.generated.h"

/**
 * 
 */
UCLASS()
class WESTLOCAL_API UWInventory : public UObject
{
	GENERATED_BODY()
	
public:
	TArray<UWInventoryItemBase*> Items;

	void AddItem(UWInventoryItemBase* Item, unsigned int Count);

	void RemoveItem(int Index, unsigned int Count);
	void RemoveItem(FString Identifier, unsigned int Count);
	void RemoveItem(UWInventoryItemBase Item, unsigned int Count);

	void RemoveItemFully(int Index);
	void RemoveItemFully(FString Identifier);
	void RemoveItemFully(UWInventoryItemBase Item);

	void ClearInventory();

	void TransferItem(UWInventory* OtherInventory, int Index, unsigned int Count);
	void TransferItem(UWInventory* OtherInventory, FString Identifier, unsigned int Count);
	void TransferItem(UWInventory* OtherInventory, UWInventoryItemBase Item, unsigned int Count);

	void TransferAllItemOfType(UWInventory* OtherInventory, int Index);
	void TransferAllItemOfType(UWInventory* OtherInventory, FString Identifier);
	void TransferAllItemOfType(UWInventory* OtherInventory, UWInventoryItemBase Item);

	void TransferInventory(UWInventory* OtherInventory);

	int GetSize() const;

};



