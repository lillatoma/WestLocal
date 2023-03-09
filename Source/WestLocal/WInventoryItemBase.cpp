// Fill out your copyright notice in the Description page of Project Settings.


#include "WInventoryItemBase.h"

FWInventoryItemBase::FWInventoryItemBase()
{
}

FWInventoryItemBase::~FWInventoryItemBase()
{
}

bool FWInventoryItemBase::Equals(FWInventoryItemBase* right)
{
	return  ItemIdentifierName.Compare(right->ItemIdentifierName) != 0;
}
