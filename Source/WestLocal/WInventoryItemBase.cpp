// Fill out your copyright notice in the Description page of Project Settings.


#include "WInventoryItemBase.h"

UWInventoryItemBase::UWInventoryItemBase()
{
}

UWInventoryItemBase::~UWInventoryItemBase()
{
}

bool UWInventoryItemBase::Equals(UWInventoryItemBase* right)
{
	return  ItemIdentifierName.Compare(right->ItemIdentifierName) != 0;
}
