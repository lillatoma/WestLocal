// Fill out your copyright notice in the Description page of Project Settings.


#include "WInventory.h"

void UWInventory::AddItem(FWInventoryItemBase* Item, int Count)
{
	for (int i = 0; i < Items.Num(); i++)
	{
		if (Items[i]->Equals(Item))
		{
			Items[i]->Count += Count;
			return;
		}
	}
	{
		FWInventoryItemBase* NewItem = new FWInventoryItemBase();
		NewItem->MakeEqual(Item);
		

		Items.Add(NewItem);
		Items.Last()->Count = Count;
	}

}

void UWInventory::RemoveItem(int Index, int Count)
{
	if (Index >= Items.Num() || Index < 0)
		return;

	Items[Index]->Count -= Count;
	if (Items[Index]->Count <= 0)
	{
		Items.RemoveAt(Index);
	}
}

void UWInventory::RemoveItem(FString Identifier, int Count)
{
	for (int i = 0; i < Items.Num(); i++)
	{
		if (!Items[i]->ItemIdentifierName.Compare(Identifier))
		{
			Items[i]->Count -= Count;
			if (Items[i]->Count <= 0)
			{
				Items.RemoveAt(i);
			}
			return;
		}
	}
}

void UWInventory::RemoveItem(FWInventoryItemBase Item, int Count)
{
	for (int i = 0; i < Items.Num(); i++)
	{
		if (Items[i]->Equals(&Item))
		{
			Items[i]->Count -= Count;
			if (Items[i]->Count <= 0)
			{
				Items.RemoveAt(i);
			}
			return;
		}
	}
}

void UWInventory::RemoveItemFully(int Index)
{
	if (Index >= Items.Num() || Index < 0)
		return;

	Items.RemoveAt(Index);
}

void UWInventory::RemoveItemFully(FString Identifier)
{
	for (int i = 0; i < Items.Num(); i++)
	{
		if (!Items[i]->ItemIdentifierName.Compare(Identifier))
		{
			Items.RemoveAt(i);
			return;
		}
	}
}

void UWInventory::RemoveItemFully(FWInventoryItemBase Item)
{
	for (int i = 0; i < Items.Num(); i++)
	{
		if (Items[i]->Equals(&Item))
		{
			Items.RemoveAt(i);
			return;
		}
	}
}

void UWInventory::ClearInventory()
{
	for (int i = Items.Num() - 1; i >= 0; i--)
	{
		Items.RemoveAt(i);
	}
}

void UWInventory::TransferItem(UWInventory* OtherInventory, int Index, int Count)
{
	if (Index < 0 || Index >= Items.Num())
		return;

	if (Count > Items[Index]->Count)
		Count = Items[Index]->Count;

	OtherInventory->AddItem(Items[Index], Count);
	RemoveItem(Index, Count);
}

void UWInventory::TransferItem(UWInventory* OtherInventory, FString Identifier, int Count)
{
	for (int i = 0; i < Items.Num(); i++)
	{
		if (!Items[i]->ItemIdentifierName.Compare(Identifier))
		{
			if (Count > Items[i]->Count)
				Count = Items[i]->Count;

			OtherInventory->AddItem(Items[i], Count);
			RemoveItem(i, Count);
			return;
		}
	}
}

void UWInventory::TransferItem(UWInventory* OtherInventory, FWInventoryItemBase Item, int Count)
{
	for (int i = 0; i < Items.Num(); i++)
	{
		if (Items[i]->Equals(&Item))
		{
			if (Count > Items[i]->Count)
				Count = Items[i]->Count;

			OtherInventory->AddItem(Items[i], Count);
			RemoveItem(i, Count);
			return;
		}
	}
}

void UWInventory::TransferAllItemOfType(UWInventory* OtherInventory, int Index)
{
	if (Index < 0 || Index >= Items.Num())
		return;

	OtherInventory->AddItem(Items[Index], Items[Index]->Count);
	RemoveItemFully(Index);
}

void UWInventory::TransferAllItemOfType(UWInventory* OtherInventory, FString Identifier)
{
	for (int i = 0; i < Items.Num(); i++)
	{
		if (!Items[i]->ItemIdentifierName.Compare(Identifier))
		{

			OtherInventory->AddItem(Items[i], Items[i]->Count);
			RemoveItemFully(i);
			return;
		}
	}
}

void UWInventory::TransferAllItemOfType(UWInventory* OtherInventory, FWInventoryItemBase Item)
{
	for (int i = 0; i < Items.Num(); i++)
	{
		if (Items[i]->Equals(&Item))
		{

			OtherInventory->AddItem(Items[i], Items[i]->Count);
			RemoveItemFully(i);
			return;
		}
	}
}

void UWInventory::TransferInventory(UWInventory* OtherInventory)
{
	for (int i = Items.Num() - 1; i >= 0; i--)
		TransferAllItemOfType(OtherInventory, i);
}

int UWInventory::HasItem(FString Identifier)
{
	int Num = Items.Num();
	for (int i = 0; i < Num; i++)
	{
		if (Items[i]->Is(Identifier))
			return Items[i]->Count;
	}
	return 0;
}

int UWInventory::GetSize() const
{
	return Items.Num();
}