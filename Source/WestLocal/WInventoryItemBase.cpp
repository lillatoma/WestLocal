// Fill out your copyright notice in the Description page of Project Settings.


#include "WInventoryItemBase.h"

FWInventoryItemBase::FWInventoryItemBase()
{
}

FWInventoryItemBase::~FWInventoryItemBase()
{
}

bool FWInventoryItemBase::Equals(FWInventoryItemBase* right) const
{
	return  ItemIdentifierName.Compare(right->ItemIdentifierName) == 0;
}

bool FWInventoryItemBase::Is(FString Name) const 
{
	return ItemIdentifierName.Compare(Name) != 0;
}

bool FWInventoryItemBase::IsPartOfSet() const
{
	return SetName.Len() > 1;
}

bool FWInventoryItemBase::IsAuctionable() const
{
	return Sellable && ItemLevel == 0;
}
