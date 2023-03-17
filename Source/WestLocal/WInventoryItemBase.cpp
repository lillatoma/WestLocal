// Fill out your copyright notice in the Description page of Project Settings.


#include "WInventoryItemBase.h"

FWInventoryItemBase::FWInventoryItemBase()
{
}

FWInventoryItemBase::~FWInventoryItemBase()
{
}

void FWInventoryItemBase::MakeEqual(FWInventoryItemBase* OtherItem)
{
	this->Consumable = OtherItem->Consumable;
	this->Count = OtherItem->Count;
	this->FixedAttributes.Empty();
	this->LeveledAttributes.Empty();
	for (int i = 0; i < OtherItem->FixedAttributes.Num(); i++)
		this->FixedAttributes.Add(OtherItem->FixedAttributes[i]);
	for (int i = 0; i < OtherItem->LeveledAttributes.Num(); i++)
		this->LeveledAttributes.Add(OtherItem->LeveledAttributes[i]);
	this->ItemDescription = OtherItem->ItemDescription;
	this->ItemIdentifierName = OtherItem->ItemIdentifierName;
	this->ItemLevel = OtherItem->ItemLevel;
	this->ItemName = OtherItem->ItemName;
	this->MinLevel = OtherItem->MinLevel;
	this->Price = OtherItem->Price;
	this->Sellable = OtherItem->Sellable;
	this->SetName = OtherItem->SetName;
	this->Slot = OtherItem->Slot;
	this->Upgradable = OtherItem->Upgradable;
		 

}

bool FWInventoryItemBase::IsUpgradable()
{
	return Upgradable && Count >= 3 && ItemLevel < 8;
}

FWInventoryItemBase FWInventoryItemBase::GetUpgradedVersion()
{
	FWInventoryItemBase Upgraded;
	Upgraded.MakeEqual(this);

	for (int i = 0; i < Upgraded.FixedAttributes.Num(); i++)
	{
		Upgraded.FixedAttributes[i].FloatValue *= 1.1f;
		Upgraded.FixedAttributes[i].IntValue *= 1.1f;
	}
	for (int i = 0; i < Upgraded.LeveledAttributes.Num(); i++)
	{
		Upgraded.LeveledAttributes[i].FloatValue *= 1.1f;
	}
	Upgraded.ItemLevel++;
	Upgraded.Price *= 3;

	Upgraded.ItemIdentifierName += "U";

	return Upgraded;
}

bool FWInventoryItemBase::Equals(FWInventoryItemBase* right) const
{
	return  ItemIdentifierName.Compare(right->ItemIdentifierName) == 0;
}

bool FWInventoryItemBase::Is(FString Name) const 
{
	return ItemIdentifierName.Compare(Name) == 0;
}

bool FWInventoryItemBase::IsPartOfSet() const
{
	return SetName.Len() > 1;
}

bool FWInventoryItemBase::IsPartOfSet(FString OtherSet) const
{
	return SetName.Compare(OtherSet) == 0;
}

bool FWInventoryItemBase::IsAuctionable() const
{
	return Sellable && ItemLevel == 0;
}
