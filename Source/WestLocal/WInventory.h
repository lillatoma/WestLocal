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
	TArray<FWInventoryItemBase*> Items;

	void AddItem(FWInventoryItemBase* Item, int Count);

	void RemoveItem(int Index, int Count);
	void RemoveItem(FString Identifier,int Count);
	void RemoveItem(FWInventoryItemBase Item, int Count);

	void RemoveItemFully(int Index);
	void RemoveItemFully(FString Identifier);
	void RemoveItemFully(FWInventoryItemBase Item);

	void ClearInventory();

	void TransferItem(UWInventory* OtherInventory, int Index, int Count);
	void TransferItem(UWInventory* OtherInventory, FString Identifier, int Count);
	void TransferItem(UWInventory* OtherInventory, FWInventoryItemBase Item,int Count);

	void TransferAllItemOfType(UWInventory* OtherInventory, int Index);
	void TransferAllItemOfType(UWInventory* OtherInventory, FString Identifier);
	void TransferAllItemOfType(UWInventory* OtherInventory, FWInventoryItemBase Item);

	void TransferInventory(UWInventory* OtherInventory);

	int HasItem(FString Identifier);


	int GetSize() const;

};



