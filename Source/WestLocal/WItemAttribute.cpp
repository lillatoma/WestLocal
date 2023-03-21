// Fill out your copyright notice in the Description page of Project Settings.


#include "WItemAttribute.h"

FWItemAttribute::FWItemAttribute()
{
}

FWItemAttribute::~FWItemAttribute()
{
}


FWLeveledItemAttribute::FWLeveledItemAttribute()
{
}

FWLeveledItemAttribute::~FWLeveledItemAttribute()
{
}



FWCombinedAttributeList::FWCombinedAttributeList()
{
}

FWCombinedAttributeList::~FWCombinedAttributeList()
{
}

void FWCombinedAttributeList::AddTogether(FWCombinedAttributeList B)
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Black, FString::Printf(TEXT("B has %d %d"), B.FixedAttributes.Num(), B.LeveledAttributes.Num()));
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Black, FString::Printf(TEXT("This has %d %d"), FixedAttributes.Num(), LeveledAttributes.Num()));


	for (int i = 0; i < B.LeveledAttributes.Num(); i++)
	{
		int FoundAttributeID = -1;
		for (int j = 0; j < this->LeveledAttributes.Num(); j++)
		{
			if (this->LeveledAttributes[j].LeveledSkill == B.LeveledAttributes[i].LeveledSkill)
			{
				this->LeveledAttributes[j].FloatValue += B.LeveledAttributes[i].FloatValue;
				FoundAttributeID = j;
				break;
			}
		}
		if (FoundAttributeID == -1)
			this->LeveledAttributes.Add(B.LeveledAttributes[i]);
	}

	for (int i = 0; i < B.FixedAttributes.Num(); i++)
	{
		int FoundAttributeID = -1;
		for (int j = 0; j < this->FixedAttributes.Num(); j++)
		{
			if (this->FixedAttributes[j].FixedSkill == B.FixedAttributes[i].FixedSkill)
			{
				this->FixedAttributes[j].FloatValue += B.FixedAttributes[i].FloatValue;
				this->FixedAttributes[j].IntValue += B.FixedAttributes[i].IntValue;
				FoundAttributeID = j;
				break;
			}
		}
		if (FoundAttributeID == -1)
			this->FixedAttributes.Add(B.FixedAttributes[i]);
	}
}
