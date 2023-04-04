// Fill out your copyright notice in the Description page of Project Settings.


#include "WPlayer.h"
#include "WSkillSet.h"
#include "GI_WestGameInstance.h"
#include "WGameData.h"
#include "UWGameUI.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AWPlayer::AWPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

int AWPlayer::GetTotalStrength() const
{
	return CharacterSkills.Strength + ClothesSkills.Strength + SetSkills.Strength + BuffSkills.Strength;
}

int AWPlayer::GetTotalMobility() const
{
	return CharacterSkills.Mobility + ClothesSkills.Mobility + SetSkills.Mobility + BuffSkills.Mobility;
}

int AWPlayer::GetTotalDexterity() const
{
	return CharacterSkills.Dexterity + ClothesSkills.Dexterity + SetSkills.Dexterity + BuffSkills.Dexterity;
}

int AWPlayer::GetTotalCharisma() const
{
	return CharacterSkills.Charisma + ClothesSkills.Charisma + SetSkills.Charisma + BuffSkills.Charisma;
}

int AWPlayer::GetTotalConstruction() const
{
	return CharacterSkills.Construction + ClothesSkills.Construction + SetSkills.Construction + BuffSkills.Construction + GetTotalStrength();
}

int AWPlayer::GetTotalVigor() const
{
	return CharacterSkills.Vigor + ClothesSkills.Vigor + SetSkills.Vigor + BuffSkills.Vigor + GetTotalStrength();
}

int AWPlayer::GetTotalToughness() const
{
	return CharacterSkills.Toughness + ClothesSkills.Toughness + SetSkills.Toughness + BuffSkills.Toughness + GetTotalStrength();
}

int AWPlayer::GetTotalStamina() const
{
	return CharacterSkills.Stamina + ClothesSkills.Stamina + SetSkills.Stamina + BuffSkills.Stamina + GetTotalStrength();
}

int AWPlayer::GetTotalHealthPoints() const
{
	return CharacterSkills.HealthPoints + ClothesSkills.HealthPoints + SetSkills.HealthPoints + BuffSkills.HealthPoints + GetTotalStrength();
}

int AWPlayer::GetTotalRiding() const
{
	return CharacterSkills.Riding + ClothesSkills.Riding + SetSkills.Riding + BuffSkills.Riding + GetTotalMobility();
}

int AWPlayer::GetTotalReflex() const
{
	return CharacterSkills.Reflex + ClothesSkills.Reflex + SetSkills.Reflex + BuffSkills.Reflex + GetTotalMobility();
}

int AWPlayer::GetTotalDodging() const
{
	return CharacterSkills.Dodging + ClothesSkills.Dodging + SetSkills.Dodging + BuffSkills.Dodging + GetTotalMobility();
}

int AWPlayer::GetTotalHiding() const
{
	return CharacterSkills.Hiding + ClothesSkills.Hiding + SetSkills.Hiding + BuffSkills.Hiding + GetTotalMobility();
}

int AWPlayer::GetTotalSwimming() const
{
	return CharacterSkills.Swimming + ClothesSkills.Swimming + SetSkills.Swimming + BuffSkills.Swimming + GetTotalMobility();
}

int AWPlayer::GetTotalAiming() const
{
	return CharacterSkills.Aiming + ClothesSkills.Aiming + SetSkills.Aiming + BuffSkills.Aiming + GetTotalDexterity();
}

int AWPlayer::GetTotalShooting() const
{
	return CharacterSkills.Shooting + ClothesSkills.Shooting + SetSkills.Shooting + BuffSkills.Shooting + GetTotalDexterity();
}

int AWPlayer::GetTotalTrapping() const
{
	return CharacterSkills.Trapping + ClothesSkills.Trapping + SetSkills.Trapping + BuffSkills.Trapping + GetTotalDexterity();
}

int AWPlayer::GetTotalFineMotorSkills() const
{
	return CharacterSkills.FineMotorSkills + ClothesSkills.FineMotorSkills + SetSkills.FineMotorSkills + BuffSkills.FineMotorSkills + GetTotalDexterity();
}

int AWPlayer::GetTotalRepairing() const
{
	return CharacterSkills.Repairing + ClothesSkills.Repairing + SetSkills.Repairing + BuffSkills.Repairing + GetTotalDexterity();
}

int AWPlayer::GetTotalLeadership() const
{
	return CharacterSkills.Leadership + ClothesSkills.Leadership + SetSkills.Leadership + BuffSkills.Leadership + GetTotalCharisma();
}

int AWPlayer::GetTotalTactic() const
{
	return CharacterSkills.Tactic + ClothesSkills.Tactic + SetSkills.Tactic + BuffSkills.Tactic + GetTotalCharisma();
}

int AWPlayer::GetTotalTrading() const
{
	return CharacterSkills.Trading + ClothesSkills.Trading + SetSkills.Trading + BuffSkills.Trading + GetTotalCharisma();
}

int AWPlayer::GetTotalAnimalInstinct() const
{
	return CharacterSkills.AnimalInstinct + ClothesSkills.AnimalInstinct + SetSkills.AnimalInstinct + BuffSkills.AnimalInstinct + GetTotalCharisma();
}

int AWPlayer::GetTotalAppearance() const
{
	return CharacterSkills.Appearance + ClothesSkills.Appearance + SetSkills.Appearance + BuffSkills.Appearance + GetTotalCharisma();
}

float AWPlayer::GetTotalFindingChance() const
{
	return CharacterSkills.FindingChance * ClothesSkills.FindingChance * SetSkills.FindingChance * BuffSkills.FindingChance;
}

float AWPlayer::GetTotalLuck() const
{
	return CharacterSkills.Luck * ClothesSkills.Luck * SetSkills.Luck * BuffSkills.Luck;
}

float AWPlayer::GetTotalMoneyPercentage() const
{
	return CharacterSkills.MoneyPercentage * ClothesSkills.MoneyPercentage * SetSkills.MoneyPercentage * BuffSkills.MoneyPercentage;
}

float AWPlayer::GetTotalXPPercentage() const
{
	return CharacterSkills.XPPercentage * ClothesSkills.XPPercentage * SetSkills.XPPercentage * BuffSkills.XPPercentage;
}

float AWPlayer::GetTotalSpeed() const
{
	float BaseSpeed = (1.0f + 0.01f * GetTotalRiding());
	float Multiplier = (CharacterSkills.Speed * ClothesSkills.Speed * SetSkills.Speed * BuffSkills.Speed);
	return BaseSpeed * Multiplier;
}

int AWPlayer::GetTotalOf(WSkillNames Skill) const
{
	switch (Skill)
	{
	case WSkillNames::Strength:
			return GetTotalStrength();
			break;
	case WSkillNames::Dexterity:
		return GetTotalDexterity();
		break;
	case WSkillNames::Mobility:
		return GetTotalMobility();
		break;
	case WSkillNames::Charisma:
		return GetTotalCharisma();
		break;

	case WSkillNames::Construction:
		return GetTotalConstruction();
		break;
	case WSkillNames::Vigor:
		return GetTotalVigor();
		break;
	case WSkillNames::Toughness:
		return GetTotalToughness();
		break;
	case WSkillNames::Stamina:
		return GetTotalStamina();
		break;
	case WSkillNames::HealthPoints:
		return GetTotalHealthPoints();
		break;
	case WSkillNames::Riding:
		return GetTotalRiding();
		break;
	case WSkillNames::Reflex:
		return GetTotalReflex();
		break;
	case WSkillNames::Dodging:
		return GetTotalDodging();
		break;
	case WSkillNames::Hiding:
		return GetTotalHiding();
		break;
	case WSkillNames::Swimming:
		return GetTotalSwimming();
		break;
	case WSkillNames::Aiming:
		return GetTotalAiming();
		break;
	case WSkillNames::Shooting:
		return GetTotalShooting();
		break;
	case WSkillNames::Trapping:
		return GetTotalTrapping();
		break;
	case WSkillNames::FineMotorSkills:
		return GetTotalFineMotorSkills();
		break;
	case WSkillNames::Repairing:
		return GetTotalRepairing();
		break;
	case WSkillNames::Leadership:
		return GetTotalLeadership();
		break;
	case WSkillNames::Tactic:
		return GetTotalTactic();
		break;
	case WSkillNames::Trading:
		return GetTotalTrading();
		break;
	case WSkillNames::AnimalInstinct:
		return GetTotalAnimalInstinct();
		break;
	case WSkillNames::Appearance:
		return GetTotalAppearance();
		break;

	}
	return 0;
}

int AWPlayer::GetTotalExtraWorkPoints() const
{
	return CharacterSkills.ExtraWorkPoints + ClothesSkills.ExtraWorkPoints + SetSkills.ExtraWorkPoints + BuffSkills.ExtraWorkPoints;
}

int AWPlayer::GetTotalDamageMin() const
{
	return CharacterSkills.DamageMin + ClothesSkills.DamageMin + SetSkills.DamageMin + BuffSkills.DamageMin;
}

int AWPlayer::GetTotalDamageMax() const
{
	return CharacterSkills.DamageMax + ClothesSkills.DamageMax + SetSkills.DamageMax + BuffSkills.DamageMax;
}

int AWPlayer::GetTotalFortDamageMin() const
{
	return CharacterSkills.FortDamageMin + ClothesSkills.FortDamageMin + SetSkills.FortDamageMin + BuffSkills.FortDamageMin;
}

int AWPlayer::GetTotalFortDamageMax() const
{
	return CharacterSkills.FortDamageMax + ClothesSkills.FortDamageMax + SetSkills.FortDamageMax + BuffSkills.FortDamageMax;
}

FWSkillSet AWPlayer::GetTotalSkills() const
{
	FWSkillSet Total;
	Total.Strength = GetTotalStrength();
	Total.Mobility = GetTotalMobility();
	Total.Dexterity = GetTotalDexterity();
	Total.Charisma= GetTotalCharisma();

	Total.Construction = GetTotalConstruction();
	Total.Vigor = GetTotalVigor();
	Total.Toughness = GetTotalToughness();
	Total.Stamina = GetTotalStamina();
	Total.HealthPoints = GetTotalHealthPoints();

	Total.Riding = GetTotalRiding();
	Total.Reflex = GetTotalReflex();
	Total.Dodging = GetTotalDodging();
	Total.Hiding = GetTotalHiding();
	Total.Swimming = GetTotalSwimming();

	Total.Aiming = GetTotalAiming();
	Total.Shooting = GetTotalShooting();
	Total.Trapping = GetTotalTrapping();
	Total.FineMotorSkills = GetTotalFineMotorSkills();
	Total.Repairing = GetTotalRepairing();

	Total.Leadership = GetTotalLeadership();
	Total.Tactic = GetTotalTactic();
	Total.Trading = GetTotalTrading();
	Total.Appearance = GetTotalAppearance();
	Total.AnimalInstinct = GetTotalAnimalInstinct();

	Total.MoneyPercentage = GetTotalMoneyPercentage();
	Total.XPPercentage = GetTotalXPPercentage();
	Total.Luck = GetTotalLuck();
	Total.FindingChance = GetTotalFindingChance();
	Total.Speed = GetTotalSpeed();

	Total.ExtraWorkPoints = GetTotalExtraWorkPoints();

	Total.DamageMin = GetTotalDamageMin();
	Total.DamageMax = GetTotalDamageMax();
	Total.FortDamageMin = GetTotalFortDamageMin();
	Total.FortDamageMax = GetTotalFortDamageMax();

	return Total;
}

int AWPlayer::GetLevel() const
{
	return Level;
}

void AWPlayer::GainXP(int GainAmount)
{
	XPToNextLevel += GainAmount;
	LevelUp();
}

void AWPlayer::GainMoney(int GainAmount)
{
	Money += GainAmount;
	UpdateUI();
}

bool AWPlayer::CanPayMoney(int PayAmount)
{
	if (Money + Bank >= PayAmount)
	{
		return true;
	}
	else return false;
}

bool AWPlayer::PayMoney(int PayAmount)
{
	if (Money + Bank >= PayAmount)
	{
		if (Money >= PayAmount)
			Money -= PayAmount;
		else
		{
			PayAmount -= Money;
			Money = 0;
			Bank -= PayAmount;
		}
		UpdateUI();
		return true;
	}
	else return false;
}

void AWPlayer::GainAttributePoints(int GainAmount)
{
	UnspentAttributePoints += GainAmount;
	UpdateUI();
}

void AWPlayer::GainSkillPoints(int GainAmount)
{
	UnspentSkillPoints += GainAmount;
	UpdateUI();
}

void AWPlayer::GainSpecifiedSkillPoints(int GainAmount, WSkillNames Skill)
{
	GainSkillPoints(GainAmount);

	for (int i = 0; i < GainAmount; i++)
		SpendSkillPoint(Skill);
}

void AWPlayer::GainSpecifiedAttributePoints(int GainAmount, WSkillNames Skill)
{
	GainAttributePoints(GainAmount);

	for (int i = 0; i < GainAmount; i++)
		SpendAttributePoint(Skill);
}

bool AWPlayer::EligibleForNextLevel() const
{
	int NextLevelXP = GameInstance->GameData->LevelRequirements[Level - 1];
	return XPToNextLevel >= NextLevelXP;
}

void AWPlayer::LevelUp()
{
	if (!EligibleForNextLevel())
		return;
	XPToNextLevel -= GameInstance->GameData->LevelRequirements[Level - 1];
	Level++;
	UnspentSkillPoints++;
	UnspentAttributePoints += 3;

	if (AutoSpendSkills)
		AutoSpendSkillsFunc();

	CalculateClothesSkillSet();
	CalculateSetSkillSet();
	GetTotalSkills();
}

void AWPlayer::SpendSkillPoint(WSkillNames Skill)
{
	if (Skill != WSkillNames::Strength && Skill != WSkillNames::Mobility
		&& Skill != WSkillNames::Dexterity && Skill != WSkillNames::Charisma)
		return;
	if (UnspentSkillPoints > 0)
	{
		switch (Skill)
		{
		case WSkillNames::Strength:
			CharacterSkills.Strength++;
			break;
		case WSkillNames::Mobility:
			CharacterSkills.Mobility++;
			break;
		case WSkillNames::Dexterity:
			CharacterSkills.Dexterity++;
			break;
		case WSkillNames::Charisma:
			CharacterSkills.Charisma++;
			break;
		}
		UnspentSkillPoints--;
	}
}

void AWPlayer::SpendAttributePoint(WSkillNames Skill)
{
	if (Skill < WSkillNames::Construction || Skill > WSkillNames::Appearance)
		return;
	if (UnspentAttributePoints > 0)
	{
		switch (Skill)
		{
		case WSkillNames::Construction:
			CharacterSkills.Construction++;
			break;
		case WSkillNames::Vigor:
			CharacterSkills.Vigor++;
			break;
		case WSkillNames::Stamina:
			CharacterSkills.Construction++;
			break;
		case WSkillNames::Toughness:
			CharacterSkills.Toughness++;
			break;
		case WSkillNames::HealthPoints:
			CharacterSkills.HealthPoints++;
			break;
		case WSkillNames::Riding:
			CharacterSkills.Riding++;
			break;
		case WSkillNames::Reflex:
			CharacterSkills.Reflex++;
			break;
		case WSkillNames::Dodging:
			CharacterSkills.Dodging++;
			break;
		case WSkillNames::Hiding:
			CharacterSkills.Hiding++;
			break;
		case WSkillNames::Swimming:
			CharacterSkills.Swimming++;
			break;
		case WSkillNames::Aiming:
			CharacterSkills.Aiming++;
			break;
		case WSkillNames::Shooting:
			CharacterSkills.Shooting++;
			break;
		case WSkillNames::Trapping:
			CharacterSkills.Trapping++;
			break;
		case WSkillNames::FineMotorSkills:
			CharacterSkills.FineMotorSkills++;
			break;
		case WSkillNames::Repairing:
			CharacterSkills.Repairing++;
			break;
		case WSkillNames::Leadership:
			CharacterSkills.Leadership++;
			break;
		case WSkillNames::Tactic:
			CharacterSkills.Tactic++;
			break;
		case WSkillNames::Trading:
			CharacterSkills.Trading++;
			break;
		case WSkillNames::AnimalInstinct:
			CharacterSkills.AnimalInstinct++;
			break;
		case WSkillNames::Appearance:
			CharacterSkills.Appearance++;
			break;
		}
		UnspentAttributePoints--;
	}
}

void AWPlayer::AutoSpendSkillsFunc()
{
	while (UnspentSkillPoints > 0)
	{
		WSkillNames Skill = (WSkillNames)FMath::RandRange(0, 3);
		SpendSkillPoint(Skill);
	}
	while (UnspentAttributePoints > 0)
	{
		WSkillNames Skill = (WSkillNames)FMath::RandRange(4, 23);
		SpendAttributePoint(Skill);
	}
}

void AWPlayer::WorkJob(FWJob Job, EWorkLength Length)
{

	TotalSkills = GetTotalSkills();
	WJobReport Report = Job.SimulateJob(TotalSkills, Length, this);
	//if (Length == EWorkLength::Short)
	//	Report = Job.SimulateSmallJob(TotalSkills , this);
	//else 	if (Length == EWorkLength::Medium)
	//	Report = Job.SimulateMediumJob(TotalSkills , this);
	//else
	//	Report = Job.SimulateLargeJob(TotalSkills, this);



	GainXP(Report.XPGained);
	GainMoney(Report.CashGained);

	//TODO: Questing
	for (int i = 0; i < Report.Rewards.Num(); i++)
		Inventory->AddItem(&Report.Rewards[i], Report.Rewards[i].Count);


	GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Black, FString::Printf(TEXT("")));
	for (int i = 0; i < Report.Rewards.Num(); i++)
	{
		GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Green, FString::Printf(TEXT("Reward Item: %s ($%d)"), *Report.Rewards[i].ItemName, Report.Rewards[i].Price));
	}
	GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Black, FString::Printf(TEXT("Luck Potential: %d"), Report.LuckPotential));
	GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Black, FString::Printf(TEXT("Money: %d"), Report.CashGained));
	GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Black, FString::Printf(TEXT("XP: %d"), Report.XPGained));
	GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Black, FString::Printf(TEXT("Workpoints Added: %d (%d|%d)"), Job.CalculateLaborPoints(TotalSkills), Job.MinDifficulty, Job.MinDifficulty * 3 + 10));
	GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Black, FString::Printf(TEXT("Job worked: %s"), *Job.JobName));

	EvaluateJobForQuests(Job, Length);

	UpdateUI();
}

void AWPlayer::UpdateUI()
{
	if (!UI)
		return;
	int NextLevelXP = GameInstance->GameData->LevelRequirements[Level - 1];
	UI->SetUIWithPlayerData(Level, XPToNextLevel, NextLevelXP, Money);
}

bool AWPlayer::WearsItem(FString ItemIdentifier)
{
	TArray<FWInventoryItemBase*> SlottedItems = GetSlottedItems();

	for (int i = 0; i < SlottedItems.Num(); i++)
	{
		if (SlottedItems[i]->Is(ItemIdentifier))
			return true;
	}

	return false;
}

TArray<FWQuest> AWPlayer::GetAllQuests()
{
	TArray<FWQuest> AllQuests;

	TArray<FWQuestline> Questlines = GameInstance->GameData->Questlines;

	for (int i = 0; i < Questlines.Num(); i++)
	{
		if (!Questlines[i].IsVisible(this))
			continue;
		for (int j = 0; j < Questlines[i].Quests.Num(); j++)
		{
			if (!Questlines[i].Quests[j].IsVisible(this))
				continue;

			if (IsQuestAccepted(Questlines[i].Quests[j]))
			{
				AllQuests.Add(AcceptedQuests[GetQuestAcceptedIndex(Questlines[i].Quests[j])]);
			}
			else AllQuests.Add(Questlines[i].Quests[j]);
		}
	}


	return AllQuests;
}

bool AWPlayer::IsQuestFinished(FString QuestName)
{
	for (int i = 0; i < FinishedQuests.Num(); i++)
	{
		if (FinishedQuests[i].Compare(QuestName) == 0)
			return true;
	}
	return false;
}

bool AWPlayer::IsQuestAccepted(FWQuest Quest)
{
	for (int i = 0; i < AcceptedQuests.Num(); i++)
		if (AcceptedQuests[i].Is(Quest))
			return true;
	return false;
}

int AWPlayer::GetQuestAcceptedIndex(FWQuest Quest)
{
	for (int i = 0; i < AcceptedQuests.Num(); i++)
		if (AcceptedQuests[i].Is(Quest))
			return i;
	return -1;
}

void AWPlayer::EvaluateJobForQuests(FWJob Job, EWorkLength Length)
{
	int Num = AcceptedQuests.Num();
	for (int i = 0; i < Num; i++)
	{
		for(int j = 0; j < AcceptedQuests[i].FinishRequirements.Num(); j++)
			if (Job.JobName.Compare(AcceptedQuests[i].FinishRequirements[j].WorkedJob) == 0)
			{
				AcceptedQuests[i].FinishRequirements[j].AmountsWorked++;
				if (Length == EWorkLength::Short)
					AcceptedQuests[i].FinishRequirements[j].TimeWorked += 15;
				else if (Length == EWorkLength::Medium)
					AcceptedQuests[i].FinishRequirements[j].TimeWorked += 600;
				if (Length == EWorkLength::Long)
					AcceptedQuests[i].FinishRequirements[j].TimeWorked += 3600;

			}
	}
}

void AWPlayer::AddQuestToWatchList(FWQuest Quest)
{
	AcceptedQuests.Add(Quest);
}

void AWPlayer::FinishQuest(FString Quest)
{
	for (int i = 0; i < AcceptedQuests.Num(); i++)
	{
		if (AcceptedQuests[i].QuestName.Compare(Quest) == 0)
		{
			if (!AcceptedQuests[i].IsCompleteable(this))
				continue;


			if (AcceptedQuests[i].FinishesQuestline.Len() > 0)
				FinishQuestline(AcceptedQuests[i].FinishesQuestline);

			AcceptedQuests[i].CompleteQuest(this);

			AcceptedQuests.RemoveAt(i);
			FinishedQuests.Add(Quest);
			break;
		}
	}
	
}

void AWPlayer::FinishQuestline(FString Quest)
{
	FinishedQuestlines.Add(Quest);

	FWQuestline Questline = GameInstance->GameData->FindQuestline(Quest);

	if (Questline.Repeatable)
	{
		for (int i = 0; i < Questline.Quests.Num(); i++)
		{
			for (int j = FinishedQuests.Num() - 1; j >= 0; j--)
			{
				if (FinishedQuests[j].Compare(Questline.Quests[i].QuestName) == 0)
					FinishedQuests.RemoveAt(j);
			}
		}
	}
}

UGI_WestGameInstance* AWPlayer::GetTheGameInstance() const
{
	return GameInstance;
}

template <EInvSlot S>
inline static bool SortPredicateSlot(FWInventoryItemBase* ItemA, FWInventoryItemBase* ItemB)
{
	if ((ItemA->Slot == S && ItemB->Slot != S) || (ItemA->Slot != S && ItemB->Slot == S))
		return true;
	return false;

}

void AWPlayer::SortInventoryForSlot(EInvSlot Slot)
{
	switch (Slot)
	{
	case EInvSlot::Hat:
		Algo::Sort(Inventory->Items, SortPredicateSlot<EInvSlot::Hat>);
		break;
	case EInvSlot::Neck:
		Algo::Sort(Inventory->Items, SortPredicateSlot<EInvSlot::Neck>);
		break;
	case EInvSlot::Body:
		Algo::Sort(Inventory->Items, SortPredicateSlot<EInvSlot::Body>);
		break;
	case EInvSlot::LeftHand:
		Algo::Sort(Inventory->Items, SortPredicateSlot<EInvSlot::LeftHand>);
		break;
	case EInvSlot::RightHand:
		Algo::Sort(Inventory->Items, SortPredicateSlot<EInvSlot::RightHand>);
		break;
	case EInvSlot::Belt:
		Algo::Sort(Inventory->Items, SortPredicateSlot<EInvSlot::Belt>);
		break;
	case EInvSlot::Pants:
		Algo::Sort(Inventory->Items, SortPredicateSlot<EInvSlot::Pants>);
		break;
	case EInvSlot::Shoes:
		Algo::Sort(Inventory->Items, SortPredicateSlot<EInvSlot::Shoes>);
		break;
	case EInvSlot::Horse:
		Algo::Sort(Inventory->Items, SortPredicateSlot<EInvSlot::Horse>);
		break;
	case EInvSlot::Product:
		Algo::Sort(Inventory->Items, SortPredicateSlot<EInvSlot::Product>);
		break;
	}
}

inline static bool SortPredicateUpgradable(FWInventoryItemBase* ItemA, FWInventoryItemBase* ItemB)
{
	if ((ItemA->Upgradable && !ItemB->Upgradable) || (!ItemA->Upgradable && ItemB->Upgradable))
		return true;
	return false;
}


void AWPlayer::SortInventoryForUpgradable()
{
	Algo::Sort(Inventory->Items, SortPredicateUpgradable);
}

void AWPlayer::SortInventoryForPrice()
{
	Algo::SortBy(Inventory->Items, &FWInventoryItemBase::Price, TGreater<>());
}

inline static bool SortPredicateSets(FWInventoryItemBase* ItemA, FWInventoryItemBase* ItemB)
{
	if ((ItemA->IsPartOfSet() && !ItemB->IsPartOfSet()) || (!ItemA->IsPartOfSet() && ItemB->IsPartOfSet()))
		return true;
	if (ItemA->IsPartOfSet() && ItemB->IsPartOfSet())
	{
		return ItemA->SetIndex < ItemB->SetIndex;
	}
	return false;
}

void AWPlayer::SortInventoryForSets()
{
	Algo::Sort(Inventory->Items, SortPredicateSets);
}

void AWPlayer::TryAskForNewShopPage()
{
	if (CanPayMoney(GameInstance->PageRefreshCost))
	{
		PayMoney(GameInstance->PageRefreshCost);

		GameInstance->RefreshShopItems(Level);
	}
}

void AWPlayer::TryBuyShopItemInSlot(EInvSlot Slot)
{
	switch (Slot)
	{
	case EInvSlot::Hat:
		if (CanPayMoney(GameInstance->ShopPrices[0]))
		{
			PayMoney(GameInstance->ShopPrices[0]);
			Inventory->AddItem(&GameInstance->ShopItems[0], 1);
			GameInstance->RefreshShopItemForSlot(Level, Slot);
		}
		break;
	case EInvSlot::Neck:
		if (CanPayMoney(GameInstance->ShopPrices[1]))
		{
			PayMoney(GameInstance->ShopPrices[1]);
			Inventory->AddItem(&GameInstance->ShopItems[1], 1);
			GameInstance->RefreshShopItemForSlot(Level, Slot);
		}
		break;
	case EInvSlot::Body:
		if (CanPayMoney(GameInstance->ShopPrices[2]))
		{
			PayMoney(GameInstance->ShopPrices[2]);
			Inventory->AddItem(&GameInstance->ShopItems[2], 1);
			GameInstance->RefreshShopItemForSlot(Level, Slot);
		}
		break;
	case EInvSlot::LeftHand:
		if (CanPayMoney(GameInstance->ShopPrices[3]))
		{
			PayMoney(GameInstance->ShopPrices[3]);
			Inventory->AddItem(&GameInstance->ShopItems[3], 1);
			GameInstance->RefreshShopItemForSlot(Level, Slot);
		}
		break;
	case EInvSlot::RightHand:
		if (CanPayMoney(GameInstance->ShopPrices[4]))
		{
			PayMoney(GameInstance->ShopPrices[4]);
			Inventory->AddItem(&GameInstance->ShopItems[4], 1);
			GameInstance->RefreshShopItemForSlot(Level, Slot);
		}
		break;
	case EInvSlot::Belt:
		if (CanPayMoney(GameInstance->ShopPrices[5]))
		{
			PayMoney(GameInstance->ShopPrices[5]);
			Inventory->AddItem(&GameInstance->ShopItems[5], 1);
			GameInstance->RefreshShopItemForSlot(Level, Slot);
		}
		break;
	case EInvSlot::Pants:
		if (CanPayMoney(GameInstance->ShopPrices[6]))
		{
			PayMoney(GameInstance->ShopPrices[6]);
			Inventory->AddItem(&GameInstance->ShopItems[6], 1);
			GameInstance->RefreshShopItemForSlot(Level, Slot);
		}
		break;
	case EInvSlot::Shoes:
		if (CanPayMoney(GameInstance->ShopPrices[7]))
		{
			PayMoney(GameInstance->ShopPrices[7]);
			Inventory->AddItem(&GameInstance->ShopItems[7], 1);
			GameInstance->RefreshShopItemForSlot(Level, Slot);
		}
		break;
	case EInvSlot::Horse:
		if (CanPayMoney(GameInstance->ShopPrices[8]))
		{
			PayMoney(GameInstance->ShopPrices[8]);
			Inventory->AddItem(&GameInstance->ShopItems[8], 1);
			GameInstance->RefreshShopItemForSlot(Level, Slot);
		}
		break;
	case EInvSlot::Product:
		if (CanPayMoney(GameInstance->ShopPrices[9]))
		{
			PayMoney(GameInstance->ShopPrices[9]);
			Inventory->AddItem(&GameInstance->ShopItems[9], 1);
			GameInstance->RefreshShopItemForSlot(Level, Slot);
		}
		break;
	}

}

void AWPlayer::StopCursor()
{
	APlayerController* PlayerControllerRef = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	PlayerControllerRef->SetShowMouseCursor(true);
}

// Called when the game starts or when spawned
void AWPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	GameInstance = Cast<UGI_WestGameInstance>(GetGameInstance());

	APlayerController* PlayerControllerRef = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	PlayerControllerRef->SetShowMouseCursor(true);
	FTimerHandle UnusedHandle;
	GetWorld()->GetTimerManager().SetTimer(UnusedHandle, this, &AWPlayer::StopCursor, 0.01f, false);

	Inventory = NewObject<UWInventory>();
	UpdateUI();
}

// Called every frame
void AWPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AWPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

TArray<EInvSlot> AWPlayer::GetAllSlots() const
{
	TArray<EInvSlot> R;

	R.Add(EInvSlot::Hat);
	R.Add(EInvSlot::Neck);
	R.Add(EInvSlot::Body);
	R.Add(EInvSlot::LeftHand);
	R.Add(EInvSlot::RightHand);
	R.Add(EInvSlot::Belt);
	R.Add(EInvSlot::Pants);
	R.Add(EInvSlot::Shoes);
	R.Add(EInvSlot::Horse);
	R.Add(EInvSlot::Product);

	return R;
}

void AWPlayer::TakeOffHat()
{
	if (!Hat)
		return;
	GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Red, FString::Printf(TEXT("OFF: %s"), *Hat->ItemName));
	Inventory->AddItem(Hat, 1);
	delete Hat;
	Hat = nullptr;

	CalculateClothesSkillSet();
	CalculateSetSkillSet();
}

void AWPlayer::TakeOffNeck()
{
	if (!Neck)
		return;
	GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Red, FString::Printf(TEXT("OFF: %s"), *Neck->ItemName));
	Inventory->AddItem(Neck, 1);
	delete Neck;
	Neck = nullptr;

	CalculateClothesSkillSet();
	CalculateSetSkillSet();
}

void AWPlayer::TakeOffBody()
{
	if (!Body)
		return;
	GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Red, FString::Printf(TEXT("OFF: %s"), *Body->ItemName));
	Inventory->AddItem(Body, 1);
	delete Body;
	Body = nullptr;

	CalculateClothesSkillSet();
	CalculateSetSkillSet();
}

void AWPlayer::TakeOffLeftHand()
{
	if (!LeftHand)
		return;
	GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Red, FString::Printf(TEXT("OFF: %s"), *LeftHand->ItemName));
	Inventory->AddItem(LeftHand, 1);
	delete LeftHand;
	LeftHand = nullptr;

	CalculateClothesSkillSet();
	CalculateSetSkillSet();
}

void AWPlayer::TakeOffRightHand()
{
	if (!RightHand)
		return;
	GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Red, FString::Printf(TEXT("OFF: %s"), *RightHand->ItemName));
	Inventory->AddItem(RightHand, 1);
	delete RightHand;
	RightHand = nullptr;

	CalculateClothesSkillSet();
	CalculateSetSkillSet();
}

void AWPlayer::TakeOffBelt()
{
	if (!Belt)
		return;
	GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Red, FString::Printf(TEXT("OFF: %s"), *Belt->ItemName));
	Inventory->AddItem(Belt, 1);
	delete Belt;
	Belt = nullptr;

	CalculateClothesSkillSet();
	CalculateSetSkillSet();
}

void AWPlayer::TakeOffPants()
{
	if (!Pants)
		return;
	GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Red, FString::Printf(TEXT("OFF: %s"), *Pants->ItemName));
	Inventory->AddItem(Pants, 1);
	delete Pants;
	Pants = nullptr;

	CalculateClothesSkillSet();
	CalculateSetSkillSet();
}

void AWPlayer::TakeOffShoes()
{
	if (!Shoes)
		return;
	GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Red, FString::Printf(TEXT("OFF: %s"), *Shoes->ItemName));
	Inventory->AddItem(Shoes, 1);
	delete Shoes;
	Shoes = nullptr;

	CalculateClothesSkillSet();
	CalculateSetSkillSet();
}

void AWPlayer::TakeOffHorse()
{
	if (!Horse)
		return;
	GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Red, FString::Printf(TEXT("OFF: %s"), *Horse->ItemName));
	Inventory->AddItem(Horse, 1);
	delete Horse;
	Horse = nullptr;

	CalculateClothesSkillSet();
	CalculateSetSkillSet();
}

void AWPlayer::TakeOffProduct()
{
	if (!Product)
		return;
	GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Red, FString::Printf(TEXT("OFF: %s"), *Product->ItemName));
	Inventory->AddItem(Product, 1);
	delete Product;
	Product = nullptr;

	CalculateClothesSkillSet();
	CalculateSetSkillSet();
}

void AWPlayer::TakeOffAll()
{
	TakeOffHat();
	TakeOffNeck();
	TakeOffBody();
	TakeOffLeftHand();
	TakeOffRightHand();
	TakeOffBelt();
	TakeOffPants();
	TakeOffShoes();
	TakeOffHorse();
	TakeOffProduct();
}

void AWPlayer::TakeOnHat(int Index)
{
	if (Inventory->Items[Index]->Slot != EInvSlot::Hat)
		return;
	if (Hat)
	{
		GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Red, FString::Printf(TEXT("OFF: %s"), *Hat->ItemName));
		Inventory->AddItem(Hat,1);
		Hat->MakeEqual(Inventory->Items[Index]);
		Inventory->RemoveItem(Index, 1);
	}
	else
	{
		Hat = new FWInventoryItemBase();
		Hat->MakeEqual(Inventory->Items[Index]);
		Inventory->RemoveItem(Index, 1);
	}
	GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Green, FString::Printf(TEXT("ON: %s"), *Hat->ItemName));
	CalculateClothesSkillSet();
	CalculateSetSkillSet();
}

void AWPlayer::TakeOnNeck(int Index)
{
	if (Inventory->Items[Index]->Slot != EInvSlot::Neck)
		return;
	if (Neck)
	{
		GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Red, FString::Printf(TEXT("OFF: %s"), *Neck->ItemName));
		Inventory->AddItem(Neck, 1);
		Neck->MakeEqual(Inventory->Items[Index]);
		Inventory->RemoveItem(Index, 1);
	}
	else
	{
		Neck = new FWInventoryItemBase();
		Neck->MakeEqual(Inventory->Items[Index]);
		Inventory->RemoveItem(Index, 1);
	}
	GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Green, FString::Printf(TEXT("ON: %s"), *Neck->ItemName));
	CalculateClothesSkillSet();
	CalculateSetSkillSet();
}

void AWPlayer::TakeOnBody(int Index)
{
	if (Inventory->Items[Index]->Slot != EInvSlot::Body)
		return;
	if (Body)
	{
		GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Red, FString::Printf(TEXT("OFF: %s"), *Body->ItemName));
		Inventory->AddItem(Body, 1);
		Body->MakeEqual(Inventory->Items[Index]);
		Inventory->RemoveItem(Index, 1);
	}
	else
	{
		Body = new FWInventoryItemBase();
		Body->MakeEqual(Inventory->Items[Index]);
		Inventory->RemoveItem(Index, 1);
	}
	GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Green, FString::Printf(TEXT("ON: %s"), *Body->ItemName));
	CalculateClothesSkillSet();
	CalculateSetSkillSet();
}

void AWPlayer::TakeOnLeftHand(int Index)
{
	if (Inventory->Items[Index]->Slot != EInvSlot::LeftHand)
		return;
	if (LeftHand)
	{
		GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Red, FString::Printf(TEXT("OFF: %s"), *LeftHand->ItemName));
		Inventory->AddItem(LeftHand, 1);
		LeftHand->MakeEqual(Inventory->Items[Index]);
		Inventory->RemoveItem(Index, 1);
	}
	else
	{
		LeftHand = new FWInventoryItemBase();
		LeftHand->MakeEqual(Inventory->Items[Index]);
		Inventory->RemoveItem(Index, 1);
	}
	GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Green, FString::Printf(TEXT("ON: %s"), *LeftHand->ItemName));
	CalculateClothesSkillSet();
	CalculateSetSkillSet();
}

void AWPlayer::TakeOnRightHand(int Index)
{
	if (Inventory->Items[Index]->Slot != EInvSlot::RightHand)
		return;
	if (RightHand)
	{
		GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Red, FString::Printf(TEXT("OFF: %s"), *RightHand->ItemName));
		Inventory->AddItem(RightHand, 1);
		RightHand->MakeEqual(Inventory->Items[Index]);
		Inventory->RemoveItem(Index, 1);
	}
	else
	{
		RightHand = new FWInventoryItemBase();
		RightHand->MakeEqual(Inventory->Items[Index]);
		Inventory->RemoveItem(Index, 1);
	}
	GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Green, FString::Printf(TEXT("ON: %s"), *RightHand->ItemName));
	CalculateClothesSkillSet();
	CalculateSetSkillSet();
}

void AWPlayer::TakeOnBelt(int Index)
{
	if (Inventory->Items[Index]->Slot != EInvSlot::Belt)
		return;
	if (Belt)
	{
		GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Red, FString::Printf(TEXT("OFF: %s"), *Belt->ItemName));
		Inventory->AddItem(Belt, 1);
		Belt->MakeEqual(Inventory->Items[Index]);
		Inventory->RemoveItem(Index, 1);
	}
	else
	{
		Belt = new FWInventoryItemBase();
		Belt->MakeEqual(Inventory->Items[Index]);
		Inventory->RemoveItem(Index, 1);
	}
	GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Green, FString::Printf(TEXT("ON: %s"), *Belt->ItemName));
	CalculateClothesSkillSet();
	CalculateSetSkillSet();
}

void AWPlayer::TakeOnPants(int Index)
{
	if (Inventory->Items[Index]->Slot != EInvSlot::Pants)
		return;
	if (Pants)
	{
		GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Red, FString::Printf(TEXT("OFF: %s"), *Pants->ItemName));
		Inventory->AddItem(Pants, 1);
		Pants->MakeEqual(Inventory->Items[Index]);
		Inventory->RemoveItem(Index, 1);
	}
	else
	{
		Pants = new FWInventoryItemBase();
		Pants->MakeEqual(Inventory->Items[Index]);
		Inventory->RemoveItem(Index, 1);
	}
	GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Green, FString::Printf(TEXT("ON: %s"), *Pants->ItemName));
	CalculateClothesSkillSet();
	CalculateSetSkillSet();
}

void AWPlayer::TakeOnShoes(int Index)
{
	if (Inventory->Items[Index]->Slot != EInvSlot::Shoes)
		return;
	if (Shoes)
	{
		GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Red, FString::Printf(TEXT("OFF: %s"), *Shoes->ItemName));
		Inventory->AddItem(Shoes, 1);
		Shoes->MakeEqual(Inventory->Items[Index]);
		Inventory->RemoveItem(Index, 1);
	}
	else
	{
		Shoes = new FWInventoryItemBase();
		Shoes->MakeEqual(Inventory->Items[Index]);
		Inventory->RemoveItem(Index, 1);
	}
	GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Green, FString::Printf(TEXT("ON: %s"), *Shoes->ItemName));
	CalculateClothesSkillSet();
	CalculateSetSkillSet();
}

void AWPlayer::TakeOnHorse(int Index)
{
	if (Inventory->Items[Index]->Slot != EInvSlot::Horse)
		return;
	if (Horse)
	{
		GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Red, FString::Printf(TEXT("OFF: %s"), *Horse->ItemName));
		Inventory->AddItem(Horse, 1);
		Horse->MakeEqual(Inventory->Items[Index]);
		Inventory->RemoveItem(Index, 1);
	}
	else
	{
		Horse = new FWInventoryItemBase();
		Horse->MakeEqual(Inventory->Items[Index]);
		Inventory->RemoveItem(Index, 1);
	}
	GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Green, FString::Printf(TEXT("ON: %s"), *Horse->ItemName));
	CalculateClothesSkillSet();
	CalculateSetSkillSet();
}

void AWPlayer::TakeOnProduct(int Index)
{
	if (Inventory->Items[Index]->Slot != EInvSlot::Product)
		return;
	if (Product)
	{
		GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Red, FString::Printf(TEXT("OFF: %s"), *Product->ItemName));
		Inventory->AddItem(Product, 1);
		Product->MakeEqual(Inventory->Items[Index]);
		Inventory->RemoveItem(Index, 1);
	}
	else
	{
		Product = new FWInventoryItemBase();
		Product->MakeEqual(Inventory->Items[Index]);
		Inventory->RemoveItem(Index, 1);
	}
	GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Green, FString::Printf(TEXT("ON: %s"), *Product->ItemName));
	CalculateClothesSkillSet();
	CalculateSetSkillSet();
}

void AWPlayer::TakeOn(int Index)
{
	if (Index < 0 || Index >= Inventory->GetSize())
		return;


	switch (Inventory->Items[Index]->Slot)
	{
	case EInvSlot::Hat:
		TakeOnHat(Index);
		break;
	case EInvSlot::Neck:
		TakeOnNeck(Index);
		break;
	case EInvSlot::Body:
		TakeOnBody(Index);
		break;
	case EInvSlot::LeftHand:
		TakeOnLeftHand(Index);
		break;
	case EInvSlot::RightHand:
		TakeOnRightHand(Index);
		break;
	case EInvSlot::Belt:
		TakeOnBelt(Index);
		break;
	case EInvSlot::Pants:
		TakeOnPants(Index);
		break;
	case EInvSlot::Shoes:
		TakeOnShoes(Index);
		break;
	case EInvSlot::Horse:
		TakeOnHorse(Index);
		break;
	case EInvSlot::Product:
		TakeOnProduct(Index);
		break;
	}
	return;
}

bool AWPlayer::HasItemInSlot(EInvSlot Slot)
{
	switch (Slot)
	{
	case EInvSlot::Hat:
		return Hat != nullptr;
	case EInvSlot::Neck:
			return Neck != nullptr;
		case EInvSlot::Body:
			return Body != nullptr;
		case EInvSlot::LeftHand:
			return LeftHand != nullptr;
		case EInvSlot::RightHand:
			return RightHand != nullptr;
		case EInvSlot::Belt:
			return Belt != nullptr;
		case EInvSlot::Pants:
			return Pants != nullptr;
		case EInvSlot::Shoes:
			return Shoes != nullptr;
	case EInvSlot::Horse:
		return Horse != nullptr;
	case EInvSlot::Product:
		return Product != nullptr;
	}
	return true;
}

FWInventoryItemBase* AWPlayer::GetItemInSlot(EInvSlot Slot)
{
	switch (Slot)
	{
	case EInvSlot::Hat:
		return Hat;
	case EInvSlot::Neck:
			return Neck;
		case EInvSlot::Body:
			return Body;
		case EInvSlot::LeftHand:
			return LeftHand;
		case EInvSlot::RightHand:
			return RightHand;
		case EInvSlot::Belt:
			return Belt;
		case EInvSlot::Pants:
			return Pants;
		case EInvSlot::Shoes:
			return Shoes;
		case EInvSlot::Horse:
			return Horse;
		case EInvSlot::Product:
			return Product;
	}
	return nullptr;
}

TArray<FWInventoryItemBase*> AWPlayer::GetSlottedItems()
{
	TArray<FWInventoryItemBase*> Items;

	FWInventoryItemBase* Item;
	Item = GetItemInSlot(EInvSlot::Hat);
	if (Item)
		Items.Add(Item);

	Item = GetItemInSlot(EInvSlot::Neck);
	if (Item)
		Items.Add(Item);

	Item = GetItemInSlot(EInvSlot::Body);
	if (Item)
		Items.Add(Item);

	Item = GetItemInSlot(EInvSlot::LeftHand);
	if (Item)
		Items.Add(Item);

	Item = GetItemInSlot(EInvSlot::RightHand);
	if (Item)
		Items.Add(Item);

	Item = GetItemInSlot(EInvSlot::Belt);
	if (Item)
		Items.Add(Item);

	Item = GetItemInSlot(EInvSlot::Pants);
	if (Item)
		Items.Add(Item);

	Item = GetItemInSlot(EInvSlot::Shoes);
	if (Item)
		Items.Add(Item);

	Item = GetItemInSlot(EInvSlot::Horse);
	if (Item)
		Items.Add(Item);

	Item = GetItemInSlot(EInvSlot::Product);
	if (Item)
		Items.Add(Item);

	return Items;
}

TArray<int> AWPlayer::GetAllItemsForSlot(EInvSlot Slot)
{
	TArray<int> Ret;
	int Length = Inventory->GetSize();
	for (int i = 0; i < Length; i++)
	{
		if (Inventory->Items[i]->Slot == Slot)
			Ret.Add(i);
	}
	return Ret;
}

bool AWPlayer::IsSetItemInSlot(FWSet Set,EInvSlot Slot)
{
	TArray<int> Items = GetAllItemsForSlot(Slot);

	for (int i = 0; i < Items.Num(); i++)
	{
		if (Level >= Inventory->Items[Items[i]]->MinLevel && Inventory->Items[Items[i]]->IsPartOfSet(Set.SetName))
			return true;
	}
	return false;
}

int AWPlayer::FindItemCountForSet(FWSet Set)
{
	bool bHat = false, bNeck = false, bBody = false, bLeft = false, bRight = false, bBelt = false, bPants = false, bShoes = false, bHorse = false, bProduct = false;

	bHat = IsSetItemInSlot(Set, EInvSlot::Hat);
	bNeck = IsSetItemInSlot(Set, EInvSlot::Neck);
	bBody = IsSetItemInSlot(Set, EInvSlot::Body);
	bLeft = IsSetItemInSlot(Set, EInvSlot::LeftHand);
	bRight = IsSetItemInSlot(Set, EInvSlot::RightHand);
	bBelt = IsSetItemInSlot(Set, EInvSlot::Belt);
	bPants = IsSetItemInSlot(Set, EInvSlot::Pants);
	bShoes = IsSetItemInSlot(Set, EInvSlot::Shoes);
	bHorse = IsSetItemInSlot(Set, EInvSlot::Horse);
	bProduct = IsSetItemInSlot(Set, EInvSlot::Product);

	int Count = 0;
	if (bHat) Count++;
	if (bNeck) Count++;
	if (bBody) Count++;
	if (bLeft) Count++;
	if (bRight) Count++;
	if (bBelt) Count++;
	if (bPants) Count++;
	if (bShoes) Count++;
	if (bHorse) Count++;
	if (bProduct) Count++;

	return Count;
}

int AWPlayer::FindItemCountForSet(FWSet Set, TArray<EInvSlot> RemainingSlots)
{
	int Count = 0;

	for (int i = 0; i < RemainingSlots.Num(); i++)
	{
		if (IsSetItemInSlot(Set, RemainingSlots[i]))
			Count++;
	}
	return Count;
}

int AWPlayer::RateSetForJob(FWJob Job, FWSet Set, int Count)
{
	FWCombinedAttributeList Item = Set.CalculateBonuses(Count);

	int Rating = 0;
	for (int i = 0; i < Item.FixedAttributes.Num(); i++)
	{
		if (Item.FixedAttributes[i].FixedSkill == Job.NeededAttribute1)
			Rating += Item.FixedAttributes[i].IntValue;
		if (Item.FixedAttributes[i].FixedSkill == Job.NeededAttribute2)
			Rating += Item.FixedAttributes[i].IntValue;
		if (Item.FixedAttributes[i].FixedSkill == Job.NeededAttribute3)
			Rating += Item.FixedAttributes[i].IntValue;
		if (Item.FixedAttributes[i].FixedSkill == Job.NeededAttribute4)
			Rating += Item.FixedAttributes[i].IntValue;
		if (Item.FixedAttributes[i].FixedSkill == Job.NeededAttribute5)
			Rating += Item.FixedAttributes[i].IntValue;

		if ((Item.FixedAttributes[i].FixedSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute1))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute2))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute3))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute4))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute5)))
			Rating += Item.FixedAttributes[i].IntValue;

		if ((Item.FixedAttributes[i].FixedSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute1))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute2))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute3))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute4))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute5)))
			Rating += Item.FixedAttributes[i].IntValue;

		if ((Item.FixedAttributes[i].FixedSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute1))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute2))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute3))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute4))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute5)))
			Rating += Item.FixedAttributes[i].IntValue;

		if ((Item.FixedAttributes[i].FixedSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute1))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute2))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute3))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute4))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute5)))
			Rating += Item.FixedAttributes[i].IntValue;

		if (Item.FixedAttributes[i].FixedSkill == WSkillNames::ExtraWorkPoints)
			Rating += Item.FixedAttributes[i].IntValue;
	}
	for (int i = 0; i < Item.LeveledAttributes.Num(); i++)
	{
		if (Item.LeveledAttributes[i].LeveledSkill == Job.NeededAttribute1)
			Rating += FMath::CeilToInt32(Item.LeveledAttributes[i].FloatValue * Level);
		if (Item.LeveledAttributes[i].LeveledSkill == Job.NeededAttribute2)
			Rating += FMath::CeilToInt32(Item.LeveledAttributes[i].FloatValue * Level);
		if (Item.LeveledAttributes[i].LeveledSkill == Job.NeededAttribute3)
			Rating += FMath::CeilToInt32(Item.LeveledAttributes[i].FloatValue * Level);
		if (Item.LeveledAttributes[i].LeveledSkill == Job.NeededAttribute4)
			Rating += FMath::CeilToInt32(Item.LeveledAttributes[i].FloatValue * Level);
		if (Item.LeveledAttributes[i].LeveledSkill == Job.NeededAttribute5)
			Rating += FMath::CeilToInt32(Item.LeveledAttributes[i].FloatValue * Level);
		if (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::ExtraWorkPoints)
			Rating += FMath::CeilToInt32(Item.LeveledAttributes[i].FloatValue * Level);

		if ((Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute1))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute2))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute3))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute4))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute5)))
			Rating += FMath::CeilToInt32(Item.LeveledAttributes[i].FloatValue * Level);

		if ((Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute1))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute2))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute3))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute4))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute5)))
			Rating += FMath::CeilToInt32(Item.LeveledAttributes[i].FloatValue * Level);

		if ((Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute1))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute2))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute3))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute4))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute5)))
			Rating += FMath::CeilToInt32(Item.LeveledAttributes[i].FloatValue * Level);

		if ((Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute1))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute2))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute3))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute4))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute5)))
			Rating += FMath::CeilToInt32(Item.LeveledAttributes[i].FloatValue * Level);


	}

	GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Black, FString::Printf(TEXT("Set %s (%d) is %d good for %s"), *Set.SetName, Count, Rating, *Job.JobName));

	return Rating;
}

int AWPlayer::CalculateSetLossFromTakeOff(FWJob Job, TArray<int> TakeOns, int Index)
{
	int Lose = 0;

	if (Index == -1 || TakeOns[Index] == -1 || !Inventory->Items[TakeOns[Index]]->IsPartOfSet());
	else
	{

		int Count = 0;

		for (int i = 0; i < TakeOns.Num(); i++)
		{
			if (TakeOns[i] >= 0 && Inventory->Items[TakeOns[i]]->SetName.Compare(Inventory->Items[TakeOns[Index]]->SetName) == 0)
				Count++;
		}

		FWSet Set = GameInstance->GameData->FindSet(Inventory->Items[TakeOns[Index]]->SetName);

		Lose = CalculateSetLossFromTakeOff(Job, Set, Count);
	}


	return Lose;
}

int AWPlayer::CalculateSetLossFromTakeOff(FWJob Job, FWSet Set, int CountFrom)
{
	return RateSetForJob(Job, Set, CountFrom) - RateSetForJob(Job, Set, CountFrom - 1);
}

int AWPlayer::CalculateSetGainFromTakeOn(FWJob Job, TArray<int> TakeOns, int Index)
{
	int Gain = 0;

	if (Index == -1 || !Inventory->Items[Index]->IsPartOfSet());
	else
	{

		int Count = 0;

		for (int i = 0; i < TakeOns.Num(); i++)
		{
			if (TakeOns[i] >= 0 && Inventory->Items[TakeOns[i]]->SetName.Compare(Inventory->Items[Index]->SetName) == 0)
				Count++;
		}

		FWSet Set = GameInstance->GameData->FindSet(Inventory->Items[Index]->SetName);

		Gain = CalculateSetGainFromTakeOn(Job, Set, Count);
	}


	return Gain;
}

int AWPlayer::CalculateSetGainFromTakeOn(FWJob Job, FWSet Set, int CountFrom)
{
	return RateSetForJob(Job, Set, CountFrom + 1) - RateSetForJob(Job, Set, CountFrom);
}

TArray<FWSet> AWPlayer::FindAllSetsFromInventory()
{
	TArray<FString> Strings;

	int Num = Inventory->Items.Num();
	for (int i = 0; i < Num; i++)
	{
		if (Inventory->Items[i]->IsPartOfSet())
		{
			bool bFound = false;

			for (int j = 0; j < Strings.Num(); j++)
			{
				if (Inventory->Items[i]->SetName.Compare(Strings[j]) == 0)
				{
					bFound = true;
					break;
				}
			}
			if (!bFound)
				Strings.Add(Inventory->Items[i]->SetName);

		}
	}

	TArray<FWSet> Sets;

	for (int i = 0; i < Strings.Num(); i++)
		Sets.Add(GameInstance->GameData->FindSet(Strings[i]));

	return Sets;
}

int AWPlayer::RateSingularItemForJob(FWJob Job, int Index)
{
	if (Index < 0 || Index >= Inventory->GetSize())
		return 0;

	int Rating = 0;
	for (int i = 0; i < Inventory->Items[Index]->FixedAttributes.Num(); i++)
	{
		if (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == Job.NeededAttribute1)
			Rating += Inventory->Items[Index]->FixedAttributes[i].IntValue;
		if (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == Job.NeededAttribute2)
			Rating += Inventory->Items[Index]->FixedAttributes[i].IntValue;
		if (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == Job.NeededAttribute3)
			Rating += Inventory->Items[Index]->FixedAttributes[i].IntValue;
		if (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == Job.NeededAttribute4)
			Rating += Inventory->Items[Index]->FixedAttributes[i].IntValue;
		if (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == Job.NeededAttribute5)
			Rating += Inventory->Items[Index]->FixedAttributes[i].IntValue;

		if ((Inventory->Items[Index]->FixedAttributes[i].FixedSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute1))
			|| (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute2))
			|| (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute3))
			|| (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute4))
			|| (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute5)))
			Rating += Inventory->Items[Index]->FixedAttributes[i].IntValue;

		if ((Inventory->Items[Index]->FixedAttributes[i].FixedSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute1))
			|| (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute2))
			|| (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute3))
			|| (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute4))
			|| (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute5)))
			Rating += Inventory->Items[Index]->FixedAttributes[i].IntValue;

		if ((Inventory->Items[Index]->FixedAttributes[i].FixedSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute1))
			|| (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute2))
			|| (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute3))
			|| (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute4))
			|| (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute5)))
			Rating += Inventory->Items[Index]->FixedAttributes[i].IntValue;

		if ((Inventory->Items[Index]->FixedAttributes[i].FixedSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute1))
			|| (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute2))
			|| (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute3))
			|| (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute4))
			|| (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute5)))
			Rating += Inventory->Items[Index]->FixedAttributes[i].IntValue;


		if (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == WSkillNames::ExtraWorkPoints)
			Rating += Inventory->Items[Index]->FixedAttributes[i].IntValue;
	}
	for (int i = 0; i < Inventory->Items[Index]->LeveledAttributes.Num(); i++)
	{
		if (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == Job.NeededAttribute1)
			Rating += FMath::CeilToInt32(Inventory->Items[Index]->LeveledAttributes[i].FloatValue * Level);
		if (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == Job.NeededAttribute2)
			Rating += FMath::CeilToInt32(Inventory->Items[Index]->LeveledAttributes[i].FloatValue * Level);
		if (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == Job.NeededAttribute3)
			Rating += FMath::CeilToInt32(Inventory->Items[Index]->LeveledAttributes[i].FloatValue * Level);
		if (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == Job.NeededAttribute4)
			Rating += FMath::CeilToInt32(Inventory->Items[Index]->LeveledAttributes[i].FloatValue * Level);
		if (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == Job.NeededAttribute5)
			Rating += FMath::CeilToInt32(Inventory->Items[Index]->LeveledAttributes[i].FloatValue * Level);
		if (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == WSkillNames::ExtraWorkPoints)
			Rating += FMath::CeilToInt32(Inventory->Items[Index]->LeveledAttributes[i].FloatValue * Level);

		if ((Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute1))
			|| (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute2))
			|| (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute3))
			|| (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute4))
			|| (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute5)))
			Rating += FMath::CeilToInt32(Inventory->Items[Index]->LeveledAttributes[i].FloatValue * Level);

		if ((Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute1))
			|| (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute2))
			|| (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute3))
			|| (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute4))
			|| (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute5)))
			Rating += FMath::CeilToInt32(Inventory->Items[Index]->LeveledAttributes[i].FloatValue * Level);

		if ((Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute1))
			|| (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute2))
			|| (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute3))
			|| (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute4))
			|| (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute5)))
			Rating += FMath::CeilToInt32(Inventory->Items[Index]->LeveledAttributes[i].FloatValue * Level);

		if ((Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute1))
			|| (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute2))
			|| (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute3))
			|| (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute4))
			|| (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute5)))
			Rating += FMath::CeilToInt32(Inventory->Items[Index]->LeveledAttributes[i].FloatValue * Level);

	}
	return Rating;
}

int AWPlayer::RateSingularItemForJob(FWJob Job,FWInventoryItemBase Item)
{
	int Rating = 0;
	for (int i = 0; i < Item.FixedAttributes.Num(); i++)
	{
		if (Item.FixedAttributes[i].FixedSkill == Job.NeededAttribute1)
			Rating += Item.FixedAttributes[i].IntValue;
		if (Item.FixedAttributes[i].FixedSkill == Job.NeededAttribute2)
			Rating += Item.FixedAttributes[i].IntValue;
		if (Item.FixedAttributes[i].FixedSkill == Job.NeededAttribute3)
			Rating += Item.FixedAttributes[i].IntValue;
		if (Item.FixedAttributes[i].FixedSkill == Job.NeededAttribute4)
			Rating += Item.FixedAttributes[i].IntValue;
		if (Item.FixedAttributes[i].FixedSkill == Job.NeededAttribute5)
			Rating += Item.FixedAttributes[i].IntValue;

		if ((Item.FixedAttributes[i].FixedSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute1))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute2))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute3))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute4))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute5)))
			Rating += Item.FixedAttributes[i].IntValue;

		if ((Item.FixedAttributes[i].FixedSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute1))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute2))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute3))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute4))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute5)))
			Rating += Item.FixedAttributes[i].IntValue;

		if ((Item.FixedAttributes[i].FixedSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute1))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute2))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute3))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute4))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute5)))
			Rating += Item.FixedAttributes[i].IntValue;

		if ((Item.FixedAttributes[i].FixedSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute1))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute2))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute3))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute4))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute5)))
			Rating += Item.FixedAttributes[i].IntValue;

		if (Item.FixedAttributes[i].FixedSkill == WSkillNames::ExtraWorkPoints)
			Rating += Item.FixedAttributes[i].IntValue;
	}
	for (int i = 0; i < Item.LeveledAttributes.Num(); i++)
	{
		if (Item.LeveledAttributes[i].LeveledSkill == Job.NeededAttribute1)
			Rating += FMath::CeilToInt32(Item.LeveledAttributes[i].FloatValue * Level);
		if (Item.LeveledAttributes[i].LeveledSkill == Job.NeededAttribute2)
			Rating += FMath::CeilToInt32(Item.LeveledAttributes[i].FloatValue * Level);
		if (Item.LeveledAttributes[i].LeveledSkill == Job.NeededAttribute3)
			Rating += FMath::CeilToInt32(Item.LeveledAttributes[i].FloatValue * Level);
		if (Item.LeveledAttributes[i].LeveledSkill == Job.NeededAttribute4)
			Rating += FMath::CeilToInt32(Item.LeveledAttributes[i].FloatValue * Level);
		if (Item.LeveledAttributes[i].LeveledSkill == Job.NeededAttribute5)
			Rating += FMath::CeilToInt32(Item.LeveledAttributes[i].FloatValue * Level);
		if (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::ExtraWorkPoints)
			Rating += FMath::CeilToInt32(Item.LeveledAttributes[i].FloatValue * Level);

		if ((Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute1))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute2))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute3))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute4))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute5)))
			Rating += FMath::CeilToInt32(Item.LeveledAttributes[i].FloatValue * Level);

		if ((Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute1))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute2))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute3))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute4))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute5)))
			Rating += FMath::CeilToInt32(Item.LeveledAttributes[i].FloatValue * Level);

		if ((Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute1))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute2))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute3))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute4))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute5)))
			Rating += FMath::CeilToInt32(Item.LeveledAttributes[i].FloatValue * Level);

		if ((Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute1))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute2))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute3))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute4))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute5)))
			Rating += FMath::CeilToInt32(Item.LeveledAttributes[i].FloatValue * Level);


	}
	return Rating;
}

int AWPlayer::FindBestSetSlotItemForJob(FWJob Job, FWSet Set, EInvSlot Slot)
{
	TArray<int> SlotItems = GetAllItemsForSlot(Slot);



	if (SlotItems.Num() > 0)
	{
		FWInventoryItemBase* SlottedItem = GetItemInSlot(Slot);

		int BestIndex = -1;
		int BestRating = 0;

		if (SlottedItem)
			BestRating = RateSingularItemForJob(Job, *SlottedItem);

		for (int i = 0; i < SlotItems.Num(); i++)
		{
			if (Inventory->Items[SlotItems[i]]->MinLevel > Level || !Inventory->Items[SlotItems[i]]->IsPartOfSet(Set.SetName))
				continue;
			int Rating = RateSingularItemForJob(Job, SlotItems[i]);
			if (Rating > BestRating)
			{
				BestRating = Rating;
				BestIndex = SlotItems[i];
			}
		}

		return BestIndex;

	}

	return -1;
}

int AWPlayer::FindBestSlotItemForJobNonPut(FWJob Job, EInvSlot Slot)
{
	TArray<int> SlotItems = GetAllItemsForSlot(Slot);
	if (SlotItems.Num() > 0)
	{
		FWInventoryItemBase* SlottedItem = GetItemInSlot(Slot);

		int BestIndex = -1;
		int BestRating = 0;

		if (SlottedItem)
			BestRating = RateSingularItemForJob(Job, *SlottedItem);

		for (int i = 0; i < SlotItems.Num(); i++)
		{
			if (Inventory->Items[SlotItems[i]]->MinLevel > Level)
				continue;
			int Rating = RateSingularItemForJob(Job, SlotItems[i]);
			if (Rating > BestRating)
			{
				BestRating = Rating;
				BestIndex = SlotItems[i];
			}
		}

		return BestIndex;

	}

	return -1;
}

void AWPlayer::FindBestSlotItemForJob(FWJob Job, EInvSlot Slot)
{
	TArray<int> SlotItems = GetAllItemsForSlot(Slot);
	if (SlotItems.Num() > 0)
	{
		FWInventoryItemBase* SlottedItem = GetItemInSlot(Slot);
		
		int BestIndex = -1;
		int BestRating = 0;

		if(SlottedItem)
			BestRating = RateSingularItemForJob(Job, *SlottedItem);

		for (int i = 0; i < SlotItems.Num(); i++)
		{
			if (Inventory->Items[SlotItems[i]]->MinLevel > Level)
				continue;
			int Rating = RateSingularItemForJob(Job, SlotItems[i]);
			if (Rating > BestRating)
			{
				BestRating = Rating;
				BestIndex = SlotItems[i];
			}
		}

		if (BestIndex != -1)
		{
			TakeOn(BestIndex);
		}

	}
}


TArray<int> AWPlayer::FindBestSetForJob(FWJob Job, TArray<EInvSlot> RemainingSlots)
{
	TArray<int> R;

	TArray<FWSet> Sets = FindAllSetsFromInventory();

	int BestRating = 0;
	int BestIndex = -1;

	for (int i = 0; i < Sets.Num(); i++)
	{
		int Count = FindItemCountForSet(Sets[i],RemainingSlots);
		int Rating = RateSetForJob(Job, Sets[i], Count);

		if (Rating > BestRating)
		{
			BestRating = Rating;
			BestIndex = i;
		}
	}

	if (BestIndex == -1)
	{
		for(int i = 0; i < 10; i++)
			R.Add(-1);
	}
	else
	{
		if (RemainingSlots.Find(EInvSlot::Hat) != INDEX_NONE)
			R.Add(FindBestSetSlotItemForJob(Job, Sets[BestIndex], EInvSlot::Hat));
		else R.Add(-1);
		if (RemainingSlots.Find(EInvSlot::Neck) != INDEX_NONE)
			R.Add(FindBestSetSlotItemForJob(Job, Sets[BestIndex], EInvSlot::Neck));
		else R.Add(-1);
		if (RemainingSlots.Find(EInvSlot::Body) != INDEX_NONE)
			R.Add(FindBestSetSlotItemForJob(Job, Sets[BestIndex], EInvSlot::Body));
		else R.Add(-1);
		if (RemainingSlots.Find(EInvSlot::LeftHand) != INDEX_NONE)
			R.Add(FindBestSetSlotItemForJob(Job, Sets[BestIndex], EInvSlot::LeftHand));
		else R.Add(-1);
		if (RemainingSlots.Find(EInvSlot::RightHand) != INDEX_NONE)
			R.Add(FindBestSetSlotItemForJob(Job, Sets[BestIndex], EInvSlot::RightHand));
		else R.Add(-1);
		if (RemainingSlots.Find(EInvSlot::Belt) != INDEX_NONE)
			R.Add(FindBestSetSlotItemForJob(Job, Sets[BestIndex], EInvSlot::Belt));
		else R.Add(-1);
		if (RemainingSlots.Find(EInvSlot::Pants) != INDEX_NONE)
			R.Add(FindBestSetSlotItemForJob(Job, Sets[BestIndex], EInvSlot::Pants));
		else R.Add(-1);
		if (RemainingSlots.Find(EInvSlot::Shoes) != INDEX_NONE)
			R.Add(FindBestSetSlotItemForJob(Job, Sets[BestIndex], EInvSlot::Shoes));
		else R.Add(-1);
		if (RemainingSlots.Find(EInvSlot::Horse) != INDEX_NONE)
			R.Add(FindBestSetSlotItemForJob(Job, Sets[BestIndex], EInvSlot::Horse));
		else R.Add(-1);
		if (RemainingSlots.Find(EInvSlot::Product) != INDEX_NONE)
			R.Add(FindBestSetSlotItemForJob(Job, Sets[BestIndex], EInvSlot::Product));
		else R.Add(-1);

		if (R[0] != -1)
			RemainingSlots.Remove(EInvSlot::Hat);
		if (R[1] != -1)
			RemainingSlots.Remove(EInvSlot::Neck);
		if (R[2] != -1)
			RemainingSlots.Remove(EInvSlot::Body);
		if (R[3] != -1)
			RemainingSlots.Remove(EInvSlot::LeftHand);
		if (R[4] != -1)
			RemainingSlots.Remove(EInvSlot::RightHand);
		if (R[5] != -1)
			RemainingSlots.Remove(EInvSlot::Belt);
		if (R[6] != -1)
			RemainingSlots.Remove(EInvSlot::Pants);
		if (R[7] != -1)
			RemainingSlots.Remove(EInvSlot::Shoes);
		if (R[8] != -1)
			RemainingSlots.Remove(EInvSlot::Horse);
		if (R[9] != -1)
			RemainingSlots.Remove(EInvSlot::Product);

		TArray<int> Merger = FindBestSetForJob(Job, RemainingSlots);

		for (int i = 0; i < Merger.Num(); i++)
		{
			if (Merger[i] != -1)
				R[i] = Merger[i];
		}
	}

	return R;
}



void AWPlayer::FindBestInventoryForJobSetted(FWJob Job)
{
	TakeOffAll();

	TArray<EInvSlot> Slots = GetAllSlots();

	TArray<int> TakeOns = FindBestSetForJob(Job, Slots);

	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Black, FString::Printf(TEXT("Set Idx: %d %d %d %d %d  %d %d %d %d %d"),
		TakeOns[0], TakeOns[1], TakeOns[2], TakeOns[3], TakeOns[4], TakeOns[5], TakeOns[6], TakeOns[7], TakeOns[8], TakeOns[9]));


	for (int i = 0; i < Slots.Num(); i++)
	{
		if (TakeOns[i] == -1)
		{
			int BestIndex = FindBestSlotItemForJobNonPut(Job, Slots[i]);
			int BestIndexRating = RateSingularItemForJob(Job, BestIndex);
			if (BestIndexRating > 0)
				TakeOns[i] = BestIndex;
		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Black, FString::Printf(TEXT("NonSetFill Idx: %d %d %d %d %d  %d %d %d %d %d"),
		TakeOns[0], TakeOns[1], TakeOns[2], TakeOns[3], TakeOns[4], TakeOns[5], TakeOns[6], TakeOns[7], TakeOns[8], TakeOns[9]));

	for (int i = 0; i < Slots.Num(); i++)
	{
		if (TakeOns[i] == -1)
		{
			int BestIndex = FindBestSlotItemForJobNonPut(Job, Slots[i]);
			int BestIndexRating = RateSingularItemForJob(Job, BestIndex);
			if(BestIndexRating > 0)
				TakeOns[i] = BestIndex;
		}
		else
		{
			int BestIndex = FindBestSlotItemForJobNonPut(Job, Slots[i]);
			int BestIndexRating = RateSingularItemForJob(Job, BestIndex);
			int CurrentRating = RateSingularItemForJob(Job, TakeOns[i]);
			int SetBonusLose = CalculateSetLossFromTakeOff(Job, TakeOns, i);
			int SetBonusGain = CalculateSetGainFromTakeOn(Job, TakeOns, BestIndex);
			if (BestIndexRating + SetBonusGain > CurrentRating + SetBonusLose)
				TakeOns[i] = BestIndex;
		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Black, FString::Printf(TEXT("Final Idx: %d %d %d %d %d  %d %d %d %d %d"),
		TakeOns[0], TakeOns[1], TakeOns[2], TakeOns[3], TakeOns[4], TakeOns[5], TakeOns[6], TakeOns[7], TakeOns[8], TakeOns[9]));

	while (TakeOns.Num() > 0)
	{
		int LargestIndex = 0;
		int LargestValue = TakeOns[0];

		for (int i = 0; i < TakeOns.Num(); i++)
		{
			if (TakeOns[i] > LargestValue)
			{
				LargestIndex = i;
				LargestValue = TakeOns[i];
			}
		}

		if (LargestValue >= 0)
		{
			TakeOn(TakeOns[LargestIndex]);
			TakeOns.RemoveAt(LargestIndex);
		}
		else
			TakeOns.RemoveAt(LargestIndex);

	}
}

void AWPlayer::FindBestInventoryForJob(FWJob Job)
{
	FindBestSlotItemForJob(Job, EInvSlot::Hat);
	FindBestSlotItemForJob(Job, EInvSlot::Neck);
	FindBestSlotItemForJob(Job, EInvSlot::Body);
	FindBestSlotItemForJob(Job, EInvSlot::LeftHand);
	FindBestSlotItemForJob(Job, EInvSlot::RightHand);
	FindBestSlotItemForJob(Job, EInvSlot::Belt);
	FindBestSlotItemForJob(Job, EInvSlot::Pants);
	FindBestSlotItemForJob(Job, EInvSlot::Shoes);
	FindBestSlotItemForJob(Job, EInvSlot::Horse);
	FindBestSlotItemForJob(Job, EInvSlot::Product);
}

void AWPlayer::EmptyClothesSkillSet()
{
	ClothesSkills = FWSkillSet();
}

void AWPlayer::CalculateClothingForSkillSet(EInvSlot Slot)
{
	FWInventoryItemBase* SlottedItem = GetItemInSlot(Slot);

	if (SlottedItem)
	{

		for (int i = 0; i < SlottedItem->FixedAttributes.Num(); i++)
		{
			switch (SlottedItem->FixedAttributes[i].FixedSkill)
			{
			case WSkillNames::Strength:
				ClothesSkills.Strength += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Mobility:
				ClothesSkills.Mobility += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Dexterity:
				ClothesSkills.Dexterity += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Charisma:
				ClothesSkills.Charisma += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Construction:
				ClothesSkills.Construction += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Vigor:
				ClothesSkills.Vigor += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Toughness:
				ClothesSkills.Toughness += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Stamina:
				ClothesSkills.Stamina += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::HealthPoints:
				ClothesSkills.HealthPoints += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Riding:
				ClothesSkills.Riding += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Reflex:
				ClothesSkills.Reflex += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Dodging:
				ClothesSkills.Dodging += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Hiding:
				ClothesSkills.Hiding += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Swimming:
				ClothesSkills.Swimming += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Aiming:
				ClothesSkills.Aiming += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Shooting:
				ClothesSkills.Shooting += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Trapping:
				ClothesSkills.Trapping += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::FineMotorSkills:
				ClothesSkills.FineMotorSkills += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Repairing:
				ClothesSkills.Repairing += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Leadership:
				ClothesSkills.Leadership += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Tactic:
				ClothesSkills.Tactic += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Trading:
				ClothesSkills.Trading += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::AnimalInstinct:
				ClothesSkills.AnimalInstinct += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Appearance:
				ClothesSkills.Appearance += SlottedItem->FixedAttributes[i].IntValue;
				break;

			case WSkillNames::XPPercentage:
				ClothesSkills.XPPercentage += SlottedItem->FixedAttributes[i].FloatValue;
				break;
			case WSkillNames::MoneyPercentage:
				ClothesSkills.MoneyPercentage += SlottedItem->FixedAttributes[i].FloatValue;
				break;
			case WSkillNames::FindingChance:
				ClothesSkills.FindingChance += SlottedItem->FixedAttributes[i].FloatValue;
				break;
			case WSkillNames::Luck:
				ClothesSkills.Luck += SlottedItem->FixedAttributes[i].FloatValue;
				break;
			case WSkillNames::Speed:
				ClothesSkills.Speed += SlottedItem->FixedAttributes[i].FloatValue;
				break;

			case WSkillNames::ExtraWorkPoints:
				ClothesSkills.ExtraWorkPoints += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::DamageMin:
				ClothesSkills.DamageMin += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::DamageMax:
				ClothesSkills.DamageMax += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::FortDamageMin:
				ClothesSkills.FortDamageMin += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::FortDamageMax:
				ClothesSkills.FortDamageMax += SlottedItem->FixedAttributes[i].IntValue;
				break;
			}
		}

		for (int i = 0; i < SlottedItem->LeveledAttributes.Num(); i++)
		{
			switch (SlottedItem->LeveledAttributes[i].LeveledSkill)
			{
			case WSkillNames::Strength:
				ClothesSkills.Strength += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Mobility:
				ClothesSkills.Mobility += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Dexterity:
				ClothesSkills.Dexterity += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Charisma:
				ClothesSkills.Charisma += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Construction:
				ClothesSkills.Construction += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Vigor:
				ClothesSkills.Vigor += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Toughness:
				ClothesSkills.Toughness += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Stamina:
				ClothesSkills.Stamina += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::HealthPoints:
				ClothesSkills.HealthPoints += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Riding:
				ClothesSkills.Riding += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Reflex:
				ClothesSkills.Reflex += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Dodging:
				ClothesSkills.Dodging += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Hiding:
				ClothesSkills.Hiding += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Swimming:
				ClothesSkills.Swimming += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Aiming:
				ClothesSkills.Aiming += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Shooting:
				ClothesSkills.Shooting += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Trapping:
				ClothesSkills.Trapping += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::FineMotorSkills:
				ClothesSkills.FineMotorSkills += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Repairing:
				ClothesSkills.Repairing += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Leadership:
				ClothesSkills.Leadership += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Tactic:
				ClothesSkills.Tactic += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Trading:
				ClothesSkills.Trading += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::AnimalInstinct:
				ClothesSkills.AnimalInstinct += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Appearance:
				ClothesSkills.Appearance += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;

			case WSkillNames::XPPercentage:
				ClothesSkills.XPPercentage += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::MoneyPercentage:
				ClothesSkills.MoneyPercentage += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::FindingChance:
				ClothesSkills.FindingChance += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Luck:
				ClothesSkills.Luck += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Speed:
				ClothesSkills.Speed += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;

			case WSkillNames::ExtraWorkPoints:
				ClothesSkills.ExtraWorkPoints += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::DamageMin:
				ClothesSkills.DamageMin += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::DamageMax:
				ClothesSkills.DamageMax += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::FortDamageMin:
				ClothesSkills.FortDamageMin += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::FortDamageMax:
				ClothesSkills.FortDamageMax += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;

			}
		}
	}
}

void AWPlayer::CalculateClothesSkillSet()
{
	EmptyClothesSkillSet();

	CalculateClothingForSkillSet(EInvSlot::Hat);
	CalculateClothingForSkillSet(EInvSlot::Neck);
	CalculateClothingForSkillSet(EInvSlot::Body);
	CalculateClothingForSkillSet(EInvSlot::LeftHand);
	CalculateClothingForSkillSet(EInvSlot::RightHand);
	CalculateClothingForSkillSet(EInvSlot::Belt);
	CalculateClothingForSkillSet(EInvSlot::Pants);
	CalculateClothingForSkillSet(EInvSlot::Shoes);
	CalculateClothingForSkillSet(EInvSlot::Horse);
	CalculateClothingForSkillSet(EInvSlot::Product);
}

void AWPlayer::EmptySetSkillSet()
{
	SetSkills = FWSkillSet();
}

void AWPlayer::CalculateSetForSkillSet(FString SetName)
{


	int ItemsFound = 0;
	if (GetItemInSlot(EInvSlot::Hat) && GetItemInSlot(EInvSlot::Hat)->IsPartOfSet(SetName)) ItemsFound++;
	if (GetItemInSlot(EInvSlot::Neck) && GetItemInSlot(EInvSlot::Neck)->IsPartOfSet(SetName)) ItemsFound++;
	if (GetItemInSlot(EInvSlot::Body) && GetItemInSlot(EInvSlot::Body)->IsPartOfSet(SetName)) ItemsFound++;
	if (GetItemInSlot(EInvSlot::LeftHand) && GetItemInSlot(EInvSlot::LeftHand)->IsPartOfSet(SetName)) ItemsFound++;
	if (GetItemInSlot(EInvSlot::RightHand) && GetItemInSlot(EInvSlot::RightHand)->IsPartOfSet(SetName)) ItemsFound++;
	if (GetItemInSlot(EInvSlot::Belt) && GetItemInSlot(EInvSlot::Belt)->IsPartOfSet(SetName)) ItemsFound++;
	if (GetItemInSlot(EInvSlot::Pants) && GetItemInSlot(EInvSlot::Pants)->IsPartOfSet(SetName)) ItemsFound++;
	if (GetItemInSlot(EInvSlot::Shoes) && GetItemInSlot(EInvSlot::Shoes)->IsPartOfSet(SetName)) ItemsFound++;
	if (GetItemInSlot(EInvSlot::Horse) && GetItemInSlot(EInvSlot::Horse)->IsPartOfSet(SetName)) ItemsFound++;
	if (GetItemInSlot(EInvSlot::Product) && GetItemInSlot(EInvSlot::Product)->IsPartOfSet(SetName)) ItemsFound++;




	if (ItemsFound > 0)
	{
		FWSet Set = GameInstance->GameData->FindSet(SetName);
		//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Black, FString::Printf(TEXT("Calculating for: %s (%d)"), *Set.SetName, ItemsFound));

		FWCombinedAttributeList Attributes = Set.CalculateBonuses(ItemsFound);

		FWCombinedAttributeList* SlottedItem = &Attributes;

		//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Black, FString::Printf(TEXT("Fixed attributes: %d Leveled: %d"), SlottedItem->FixedAttributes.Num(), SlottedItem->LeveledAttributes.Num()));

		for (int i = 0; i < SlottedItem->FixedAttributes.Num(); i++)
		{
			switch (SlottedItem->FixedAttributes[i].FixedSkill)
			{
			case WSkillNames::Strength:
				SetSkills.Strength += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Mobility:
				SetSkills.Mobility += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Dexterity:
				SetSkills.Dexterity += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Charisma:
				SetSkills.Charisma += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Construction:
				SetSkills.Construction += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Vigor:
				SetSkills.Vigor += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Toughness:
				SetSkills.Toughness += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Stamina:
				SetSkills.Stamina += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::HealthPoints:
				SetSkills.HealthPoints += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Riding:
				SetSkills.Riding += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Reflex:
				SetSkills.Reflex += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Dodging:
				SetSkills.Dodging += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Hiding:
				SetSkills.Hiding += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Swimming:
				SetSkills.Swimming += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Aiming:
				SetSkills.Aiming += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Shooting:
				SetSkills.Shooting += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Trapping:
				SetSkills.Trapping += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::FineMotorSkills:
				SetSkills.FineMotorSkills += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Repairing:
				SetSkills.Repairing += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Leadership:
				SetSkills.Leadership += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Tactic:
				SetSkills.Tactic += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Trading:
				SetSkills.Trading += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::AnimalInstinct:
				SetSkills.AnimalInstinct += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Appearance:
				SetSkills.Appearance += SlottedItem->FixedAttributes[i].IntValue;
				break;

			case WSkillNames::XPPercentage:
				SetSkills.XPPercentage += SlottedItem->FixedAttributes[i].FloatValue;
				break;
			case WSkillNames::MoneyPercentage:
				SetSkills.MoneyPercentage += SlottedItem->FixedAttributes[i].FloatValue;
				break;
			case WSkillNames::FindingChance:
				SetSkills.FindingChance += SlottedItem->FixedAttributes[i].FloatValue;
				break;
			case WSkillNames::Luck:
				SetSkills.Luck += SlottedItem->FixedAttributes[i].FloatValue;
				break;
			case WSkillNames::Speed:
				SetSkills.Speed += SlottedItem->FixedAttributes[i].FloatValue;
				break;

			case WSkillNames::ExtraWorkPoints:
				SetSkills.ExtraWorkPoints += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::DamageMin:
				SetSkills.DamageMin += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::DamageMax:
				SetSkills.DamageMax += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::FortDamageMin:
				SetSkills.FortDamageMin += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::FortDamageMax:
				SetSkills.FortDamageMax += SlottedItem->FixedAttributes[i].IntValue;
				break;
			}
		}

		for (int i = 0; i < SlottedItem->LeveledAttributes.Num(); i++)
		{
			switch (SlottedItem->LeveledAttributes[i].LeveledSkill)
			{
			case WSkillNames::Strength:
				SetSkills.Strength += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Mobility:
				SetSkills.Mobility += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Dexterity:
				SetSkills.Dexterity += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Charisma:
				SetSkills.Charisma += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Construction:
				SetSkills.Construction += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Vigor:
				SetSkills.Vigor += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Toughness:
				SetSkills.Toughness += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Stamina:
				SetSkills.Stamina += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::HealthPoints:
				SetSkills.HealthPoints += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Riding:
				SetSkills.Riding += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Reflex:
				SetSkills.Reflex += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Dodging:
				SetSkills.Dodging += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Hiding:
				SetSkills.Hiding += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Swimming:
				SetSkills.Swimming += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Aiming:
				SetSkills.Aiming += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Shooting:
				SetSkills.Shooting += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Trapping:
				SetSkills.Trapping += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::FineMotorSkills:
				SetSkills.FineMotorSkills += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Repairing:
				SetSkills.Repairing += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Leadership:
				SetSkills.Leadership += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Tactic:
				SetSkills.Tactic += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Trading:
				SetSkills.Trading += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::AnimalInstinct:
				SetSkills.AnimalInstinct += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Appearance:
				SetSkills.Appearance += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;

			case WSkillNames::XPPercentage:
				SetSkills.XPPercentage += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::MoneyPercentage:
				SetSkills.MoneyPercentage += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::FindingChance:
				SetSkills.FindingChance += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Luck:
				SetSkills.Luck += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Speed:
				SetSkills.Speed += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;

			case WSkillNames::ExtraWorkPoints:
				SetSkills.ExtraWorkPoints += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::DamageMin:
				SetSkills.DamageMin += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::DamageMax:
				SetSkills.DamageMax += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::FortDamageMin:
				SetSkills.FortDamageMin += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::FortDamageMax:
				SetSkills.FortDamageMax += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			}
		}
	}
}

void AWPlayer::CalculateSetSkillSet()
{
	EmptySetSkillSet();
	TArray<FString> AddedSets;

	TArray<FWInventoryItemBase*> Items = GetSlottedItems();


	int ICount = Items.Num();

	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Black, FString::Printf(TEXT("Slotted Items: %d"), ICount));

	for (int i = 0; i < ICount; i++)
	{
		if (Items[i]->IsPartOfSet())
		{
			bool bFound = false;
			for(int j = 0; j < AddedSets.Num(); j++)
				if (Items[i]->SetName.Compare(AddedSets[j]) == 0)
				{
					bFound = true;
					break;
				}

			if (!bFound)
			{
				AddedSets.Add(Items[i]->SetName);
				CalculateSetForSkillSet(Items[i]->SetName);
			}
		}
	}
}
