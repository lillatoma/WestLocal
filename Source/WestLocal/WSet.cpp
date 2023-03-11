// Fill out your copyright notice in the Description page of Project Settings.


#include "WSet.h"
#include "WInventory.h"
#include "WInventoryItemBase.h"

FWSet::FWSet()
{
}

FWSet::~FWSet()
{
}

FWCombinedAttributeList FWSet::AddTogether(FWCombinedAttributeList A, FWCombinedAttributeList B) const
{
	for (int i = 0; i < B.LeveledAttributes.Num(); i++)
	{
		int FoundAttributeID = -1;
		for (int j = 0; j < A.LeveledAttributes.Num(); j++)
		{
			if (A.LeveledAttributes[j].LeveledSkill == B.LeveledAttributes[i].LeveledSkill)
			{
				A.LeveledAttributes[j].FloatValue += B.LeveledAttributes[i].FloatValue;
				FoundAttributeID = j;
				break;
			}
			if (FoundAttributeID == -1)
				A.LeveledAttributes.Add(B.LeveledAttributes[i]);
		}
	}

	for (int i = 0; i < B.FixedAttributes.Num(); i++)
	{
		int FoundAttributeID = -1;
		for (int j = 0; j < A.FixedAttributes.Num(); j++)
		{
			if (A.FixedAttributes[j].FixedSkill == B.FixedAttributes[i].FixedSkill)
			{
				A.FixedAttributes[j].FloatValue += B.FixedAttributes[i].FloatValue;
				A.FixedAttributes[j].IntValue += B.FixedAttributes[i].IntValue;
				FoundAttributeID = j;
				break;
			}
			if (FoundAttributeID == -1)
				A.FixedAttributes.Add(B.FixedAttributes[i]);
		}
	}
	return A;
}

FWCombinedAttributeList FWSet::CalculateBonuses(int ItemCount) const
{
	FWCombinedAttributeList Bonuses;

	if (ItemCount >= 1)
		Bonuses = AddTogether(Bonuses, OneMemberBonuses);
	if (ItemCount >= 2)
		Bonuses = AddTogether(Bonuses, TwoMemberBonuses);
	if (ItemCount >= 3)
		Bonuses = AddTogether(Bonuses, ThreeMemberBonuses);
	if (ItemCount >= 4)
		Bonuses = AddTogether(Bonuses, FourMemberBonuses);
	if (ItemCount >= 5)
		Bonuses = AddTogether(Bonuses, FiveMemberBonuses);
	if (ItemCount >= 6)
		Bonuses = AddTogether(Bonuses, SixMemberBonuses);
	if (ItemCount >= 7)
		Bonuses = AddTogether(Bonuses, SevenMemberBonuses);
	if (ItemCount >= 8)
		Bonuses = AddTogether(Bonuses, EightMemberBonuses);
	if (ItemCount >= 9)
		Bonuses = AddTogether(Bonuses, NineMemberBonuses);
	if (ItemCount >= 10)
		Bonuses = AddTogether(Bonuses, TenMemberBonuses);

	return Bonuses;

}

TArray<int> FWSet::GetSetItemIndexesFromInventory(UWInventory* Inventory) const
{
	TArray<int> SetItemIndexes;

	int Size = Inventory->GetSize();
	for (int i = 0; i < Size; i++)
	{
		if (Inventory->Items[i]->IsPartOfSet()
			&& Inventory->Items[i]->SetName.Compare(SetName) == 0)
		{
			SetItemIndexes.Add(i);
		}
	}

	return SetItemIndexes;

}
