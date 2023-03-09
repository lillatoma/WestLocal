// Fill out your copyright notice in the Description page of Project Settings.


#include "WItem.h"

FWItem::FWItem()
{
}

FWItem::~FWItem()
{
}

bool FWItem::Equals(FWItem* right)
{
	return  ItemIdentifierName.Compare(right->ItemIdentifierName) != 0;
}
