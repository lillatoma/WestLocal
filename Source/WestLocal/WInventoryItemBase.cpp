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
	//this->OriginalItemIdentifierName = OtherItem->OriginalItemIdentifierName;
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

	float Devalue = 1.0f + 0.1f * Upgraded.ItemLevel;
	float Upvalue = 1.0f + 0.1f * (Upgraded.ItemLevel + 1);

	float Multiplier = Upvalue / Devalue;

	for (int i = 0; i < Upgraded.FixedAttributes.Num(); i++)
	{


		Upgraded.FixedAttributes[i].FloatValue *= Multiplier;
		Upgraded.FixedAttributes[i].IntValue *= Multiplier;
	}
	for (int i = 0; i < Upgraded.LeveledAttributes.Num(); i++)
	{
		Upgraded.LeveledAttributes[i].FloatValue *= Multiplier;
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

FWSkillSet FWInventoryItemBase::CalculateSkills(int PlayerLevel) const
{
	FWSkillSet SkillSet;

	for (int i = 0; i < FixedAttributes.Num(); i++)
	{
		switch (FixedAttributes[i].FixedSkill)
		{
		case WSkillNames::Strength:
			SkillSet.Strength+= FixedAttributes[i].IntValue;
			break;
		case WSkillNames::Mobility:
			SkillSet.Mobility += FixedAttributes[i].IntValue;
			break;
		case WSkillNames::Dexterity:
			SkillSet.Dexterity += FixedAttributes[i].IntValue;
			break;
		case WSkillNames::Charisma:
			SkillSet.Charisma += FixedAttributes[i].IntValue;
			break;

		case WSkillNames::Construction:
			SkillSet.Construction += FixedAttributes[i].IntValue;
			break;
		case WSkillNames::Vigor:
			SkillSet.Vigor += FixedAttributes[i].IntValue;
			break;
		case WSkillNames::Toughness:
			SkillSet.Toughness += FixedAttributes[i].IntValue;
			break;
		case WSkillNames::Stamina:
			SkillSet.Stamina += FixedAttributes[i].IntValue;
			break;
		case WSkillNames::HealthPoints:
			SkillSet.HealthPoints += FixedAttributes[i].IntValue;
			break;

		case WSkillNames::Riding:
			SkillSet.Riding += FixedAttributes[i].IntValue;
			break;
		case WSkillNames::Reflex:
			SkillSet.Reflex += FixedAttributes[i].IntValue;
			break;
		case WSkillNames::Dodging:
			SkillSet.Dodging += FixedAttributes[i].IntValue;
			break;
		case WSkillNames::Hiding:
			SkillSet.Hiding += FixedAttributes[i].IntValue;
			break;
		case WSkillNames::Swimming:
			SkillSet.Swimming += FixedAttributes[i].IntValue;
			break;

		case WSkillNames::Aiming:
			SkillSet.Aiming += FixedAttributes[i].IntValue;
			break;
		case WSkillNames::Shooting:
			SkillSet.Shooting += FixedAttributes[i].IntValue;
			break;
		case WSkillNames::Trapping:
			SkillSet.Trapping += FixedAttributes[i].IntValue;
			break;
		case WSkillNames::FineMotorSkills:
			SkillSet.FineMotorSkills += FixedAttributes[i].IntValue;
			break;
		case WSkillNames::Repairing:
			SkillSet.Repairing += FixedAttributes[i].IntValue;
			break;

		case WSkillNames::Leadership:
			SkillSet.Leadership += FixedAttributes[i].IntValue;
			break;
		case WSkillNames::Tactic:
			SkillSet.Tactic += FixedAttributes[i].IntValue;
			break;
		case WSkillNames::Trading:
			SkillSet.Trading += FixedAttributes[i].IntValue;
			break;
		case WSkillNames::AnimalInstinct:
			SkillSet.AnimalInstinct += FixedAttributes[i].IntValue;
			break;
		case WSkillNames::Appearance:
			SkillSet.Appearance += FixedAttributes[i].IntValue;
			break;

		case WSkillNames::FindingChance:
			SkillSet.FindingChance += FixedAttributes[i].FloatValue;
			break;
		case WSkillNames::MoneyPercentage:
			SkillSet.MoneyPercentage+= FixedAttributes[i].FloatValue;
			break;
		case WSkillNames::XPPercentage:
			SkillSet.XPPercentage += FixedAttributes[i].FloatValue;
			break;
		case WSkillNames::Luck:
			SkillSet.Luck += FixedAttributes[i].FloatValue;
			break;
		case WSkillNames::Speed:
			SkillSet.Speed += FixedAttributes[i].FloatValue;
			break;

		case WSkillNames::ExtraWorkPoints:
			SkillSet.ExtraWorkPoints += FixedAttributes[i].IntValue;
			break;

		case WSkillNames::DamageMin:
			SkillSet.DamageMin += FixedAttributes[i].IntValue;
			break;
		case WSkillNames::DamageMax:
			SkillSet.DamageMax += FixedAttributes[i].IntValue;
			break;
		case WSkillNames::FortDamageMin:
			SkillSet.FortDamageMin += FixedAttributes[i].IntValue;
			break;
		case WSkillNames::FortDamageMax:
			SkillSet.FortDamageMax += FixedAttributes[i].IntValue;
			break;
		}
	}
	for (int i = 0; i < LeveledAttributes.Num(); i++)
	{
		switch (LeveledAttributes[i].LeveledSkill)
		{
		case WSkillNames::Strength:
			SkillSet.Strength += FMath::CeilToInt(LeveledAttributes[i].FloatValue * PlayerLevel);
			break;
		case WSkillNames::Mobility:
			SkillSet.Mobility += FMath::CeilToInt(LeveledAttributes[i].FloatValue * PlayerLevel);
			break;
		case WSkillNames::Dexterity:
			SkillSet.Dexterity += FMath::CeilToInt(LeveledAttributes[i].FloatValue * PlayerLevel);
			break;
		case WSkillNames::Charisma:
			SkillSet.Charisma += FMath::CeilToInt(LeveledAttributes[i].FloatValue * PlayerLevel);
			break;

		case WSkillNames::Construction:
			SkillSet.Construction += FMath::CeilToInt(LeveledAttributes[i].FloatValue * PlayerLevel);
			break;
		case WSkillNames::Vigor:
			SkillSet.Vigor += FMath::CeilToInt(LeveledAttributes[i].FloatValue * PlayerLevel);
			break;
		case WSkillNames::Toughness:
			SkillSet.Toughness += FMath::CeilToInt(LeveledAttributes[i].FloatValue * PlayerLevel);
			break;
		case WSkillNames::Stamina:
			SkillSet.Stamina += FMath::CeilToInt(LeveledAttributes[i].FloatValue * PlayerLevel);
			break;
		case WSkillNames::HealthPoints:
			SkillSet.HealthPoints += FMath::CeilToInt(LeveledAttributes[i].FloatValue * PlayerLevel);
			break;

		case WSkillNames::Riding:
			SkillSet.Riding += FMath::CeilToInt(LeveledAttributes[i].FloatValue * PlayerLevel);
			break;
		case WSkillNames::Reflex:
			SkillSet.Reflex += FMath::CeilToInt(LeveledAttributes[i].FloatValue * PlayerLevel);
			break;
		case WSkillNames::Dodging:
			SkillSet.Dodging += FMath::CeilToInt(LeveledAttributes[i].FloatValue * PlayerLevel);
			break;
		case WSkillNames::Hiding:
			SkillSet.Hiding += FMath::CeilToInt(LeveledAttributes[i].FloatValue * PlayerLevel);
			break;
		case WSkillNames::Swimming:
			SkillSet.Swimming += FMath::CeilToInt(LeveledAttributes[i].FloatValue * PlayerLevel);
			break;

		case WSkillNames::Aiming:
			SkillSet.Aiming += FMath::CeilToInt(LeveledAttributes[i].FloatValue * PlayerLevel);
			break;
		case WSkillNames::Shooting:
			SkillSet.Shooting += FMath::CeilToInt(LeveledAttributes[i].FloatValue * PlayerLevel);
			break;
		case WSkillNames::Trapping:
			SkillSet.Trapping += FMath::CeilToInt(LeveledAttributes[i].FloatValue * PlayerLevel);
			break;
		case WSkillNames::FineMotorSkills:
			SkillSet.FineMotorSkills += FMath::CeilToInt(LeveledAttributes[i].FloatValue * PlayerLevel);
			break;
		case WSkillNames::Repairing:
			SkillSet.Repairing += FMath::CeilToInt(LeveledAttributes[i].FloatValue * PlayerLevel);
			break;

		case WSkillNames::Leadership:
			SkillSet.Leadership += FMath::CeilToInt(LeveledAttributes[i].FloatValue * PlayerLevel);
			break;
		case WSkillNames::Tactic:
			SkillSet.Tactic += FMath::CeilToInt(LeveledAttributes[i].FloatValue * PlayerLevel);
			break;
		case WSkillNames::Trading:
			SkillSet.Trading += FMath::CeilToInt(LeveledAttributes[i].FloatValue * PlayerLevel);
			break;
		case WSkillNames::AnimalInstinct:
			SkillSet.AnimalInstinct += FMath::CeilToInt(LeveledAttributes[i].FloatValue * PlayerLevel);
			break;
		case WSkillNames::Appearance:
			SkillSet.Appearance += FMath::CeilToInt(LeveledAttributes[i].FloatValue * PlayerLevel);
			break;

		case WSkillNames::FindingChance:
			SkillSet.FindingChance += LeveledAttributes[i].FloatValue * PlayerLevel;
			break;
		case WSkillNames::MoneyPercentage:
			SkillSet.MoneyPercentage += LeveledAttributes[i].FloatValue * PlayerLevel;
			break;
		case WSkillNames::XPPercentage:
			SkillSet.XPPercentage += LeveledAttributes[i].FloatValue * PlayerLevel;
			break;
		case WSkillNames::Luck:
			SkillSet.Luck += LeveledAttributes[i].FloatValue * PlayerLevel;
			break;
		case WSkillNames::Speed:
			SkillSet.Speed += LeveledAttributes[i].FloatValue * PlayerLevel;
			break;

		case WSkillNames::ExtraWorkPoints:
			SkillSet.ExtraWorkPoints += FMath::CeilToInt(LeveledAttributes[i].FloatValue * PlayerLevel);
			break;

		case WSkillNames::DamageMin:
			SkillSet.DamageMin += FMath::CeilToInt(LeveledAttributes[i].FloatValue * PlayerLevel);
			break;
		case WSkillNames::DamageMax:
			SkillSet.DamageMax += FMath::CeilToInt(LeveledAttributes[i].FloatValue * PlayerLevel);
			break;
		case WSkillNames::FortDamageMin:
			SkillSet.FortDamageMin += FMath::CeilToInt(LeveledAttributes[i].FloatValue * PlayerLevel);
			break;
		case WSkillNames::FortDamageMax:
			SkillSet.FortDamageMax += FMath::CeilToInt(LeveledAttributes[i].FloatValue * PlayerLevel);
			break;
		}
	}

	return SkillSet;
}

FString FWInventoryItemBase::GetItemName() const
{
	if (ItemLevel <= 0)
		return ItemName;
	else
		return ItemName + " (Level " + FString::FromInt(ItemLevel) + ")";
}
