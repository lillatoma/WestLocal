// Fill out your copyright notice in the Description page of Project Settings.


#include "WJob.h"
#include "GI_WestGameInstance.h"
#include "Kismet/GameplayStatics.h"

FWJob::FWJob()
{
}

FWJob::~FWJob()
{
}

FWJobReward::FWJobReward()
{
}

FWJobReward::~FWJobReward()
{
}

bool FWJob::IsJobWorkable(int Level, int LaborPoints)
{
	return Level >= MinLevel || LaborPoints >= MinDifficulty;
}

int FWJob::CalculateCash(int LaborPoints, float Modifier)
{
	int ReturnCash = 0;
	if (LaborPoints <= MinDifficulty)
		ReturnCash = 1.f * LaborPoints / MinDifficulty * Cash;
	else if (LaborPoints <= 3 * MinDifficulty + 10)
		ReturnCash = Cash + (1.f * (LaborPoints - MinDifficulty) / (2.f * MinDifficulty + 10)) * Cash;
	else
	{
		int LP = LaborPoints - 3 * MinDifficulty - 10;
		float Multiplier = 2.f;
		float MultiplierAdd = 0.5f;
		while (LP > 2 * MinDifficulty + 10)
		{
			Multiplier += MultiplierAdd;
			MultiplierAdd *= 0.5f;
			LP -= 2 * MinDifficulty + 10;
		}
		Multiplier += MultiplierAdd * (1.f * LP / (2 * MinDifficulty + 10));
		ReturnCash = Cash * Multiplier;
	}
	return ReturnCash * Modifier;
}

int FWJob::CalculateXP(int LaborPoints, float Modifier)
{
	int ReturnXP = XP;
	if (LaborPoints <= MinDifficulty)
		ReturnXP = 1.f * LaborPoints / MinDifficulty * XP;
	return ReturnXP * Modifier;
}

int FWJob::CalculateLuck(int LaborPoints, float Modifier)
{
	int ReturnLuck = 0;
	if (LaborPoints <= MinDifficulty)
		ReturnLuck = 1.f * LaborPoints / MinDifficulty * Luck;
	else if (LaborPoints <= 3 * MinDifficulty + 10)
		ReturnLuck = Luck + (1.f * (LaborPoints - MinDifficulty) / (2.f * MinDifficulty + 10)) * Luck;
	else
	{
		int LP = LaborPoints - 3 * MinDifficulty - 10;
		float Multiplier = 2.f;
		float MultiplierAdd = 0.5f;
		while (LP > 2 * MinDifficulty + 10)
		{
			Multiplier += MultiplierAdd;
			MultiplierAdd *= 0.5f;
			LP -= 2 * MinDifficulty + 10;
		}
		Multiplier += MultiplierAdd * (1.f * LP / (2 * MinDifficulty + 10));
		ReturnLuck = Luck * Multiplier;
	}
	return ReturnLuck * Modifier;
}

float FWJob::CalculateFindingChance(int Index, int LaborPoints, float Modifier)
{
	float ReturnFindingChance = XP;
	if (LaborPoints <= MinDifficulty)
		ReturnFindingChance = 1.f * LaborPoints / MinDifficulty * Rewards[Index].Percentage;
	else if (LaborPoints < MinDifficulty * 3 + 10)
		ReturnFindingChance = Rewards[Index].Percentage;
	else
		ReturnFindingChance = 1.5f * Rewards[Index].Percentage;
	return ReturnFindingChance * Modifier;
}

int FWJob::CalculateCash(int LaborPoints, float Modifier, EWorkLength Length)
{
	if(Length == EWorkLength::Short)
		return CalculateCash(LaborPoints,Modifier) * 0.1f;
	else if (Length == EWorkLength::Medium)
		return CalculateCash(LaborPoints, Modifier) * 0.47f;
	else return CalculateCash(LaborPoints, Modifier);
}

int FWJob::CalculateXP(int LaborPoints, float Modifier, EWorkLength Length)
{
	if (Length == EWorkLength::Short)
		return CalculateXP(LaborPoints, Modifier) * 0.1f;
	else if (Length == EWorkLength::Medium)
		return CalculateXP(LaborPoints, Modifier) * 0.47f;
	else return CalculateXP(LaborPoints, Modifier);

}

int FWJob::CalculateLuck(int LaborPoints, float Modifier, EWorkLength Length)
{
	return CalculateLuck(LaborPoints, Modifier);
}

float FWJob::CalculateFindingChance(int Index, int LaborPoints, float Modifier, EWorkLength Length)
{
	if (Length == EWorkLength::Short)
	{
		float Chance = CalculateFindingChance(Index, LaborPoints, Modifier) / 210.f;
		if (Chance < 0.02f)
			Chance = 0.02f;
		return Chance;
	}
	else if (Length == EWorkLength::Medium)
	{
		float Chance = CalculateFindingChance(Index, LaborPoints, Modifier) / 6.f;
		if (Chance < 0.02f)
			Chance = 0.02f;
		return Chance;
	}
	else return CalculateFindingChance(Index, LaborPoints, Modifier);
}

float FWJob::CalculateDamageChance(int LaborPoints)
{
	return 0;
}

int FWJob::CalculateDamage(int LaborPoints)
{
	return 0;
}

bool FWJob::FindsItem(int WorkLength)
{
	double R = FMath::RandRange(0.0, 1.0);

	return (R < 0.04 * WorkLength);

}

int FWJob::CalculateSmallLaborPoints(WSkillSet Skills, WSkillNames Skill)
{
	switch (Skill)
	{
	case WSkillNames::Construction:
		return Skills.Construction;
	case WSkillNames::Vigor:
		return Skills.Vigor;
	case WSkillNames::Toughness:
		return Skills.Toughness;
	case WSkillNames::Stamina:
		return Skills.Stamina;
	case WSkillNames::HealthPoints:
		return Skills.HealthPoints;

	case WSkillNames::Hiding:
		return Skills.Hiding;
	case WSkillNames::Reflex:
		return Skills.Reflex;
	case WSkillNames::Dodging:
		return Skills.Dodging;
	case WSkillNames::Riding:
		return Skills.Riding;
	case WSkillNames::Swimming:
		return Skills.Swimming;

	case WSkillNames::Aiming:
		return Skills.Aiming;
	case WSkillNames::Shooting:
		return Skills.Shooting;
	case WSkillNames::Trapping:
		return Skills.Trapping;
	case WSkillNames::FineMotorSkills:
		return Skills.FineMotorSkills;
	case WSkillNames::Repairing:
		return Skills.Repairing;

	case WSkillNames::Appearance:
		return Skills.Appearance;
	case WSkillNames::Leadership:
		return Skills.Leadership;
	case WSkillNames::Tactic:
		return Skills.Tactic;
	case WSkillNames::Trading:
		return Skills.Trading;
	case WSkillNames::AnimalInstinct:
		return Skills.AnimalInstinct;

	default:
		return 0;
	}
}

int FWJob::CalculateLaborPoints(WSkillSet Skills)
{
	int LaborPoints = 0;
	LaborPoints += CalculateSmallLaborPoints(Skills, NeededAttribute1);
	LaborPoints += CalculateSmallLaborPoints(Skills, NeededAttribute2);
	LaborPoints += CalculateSmallLaborPoints(Skills, NeededAttribute3);
	LaborPoints += CalculateSmallLaborPoints(Skills, NeededAttribute4);
	LaborPoints += CalculateSmallLaborPoints(Skills, NeededAttribute5);
	LaborPoints += Skills.ExtraWorkPoints;
	return LaborPoints;
}

WJobReport FWJob::SimulateSmallJob(WSkillSet Skills, const UObject* WorldContext)
{
	WJobReport Report;

	int LaborPoints = CalculateLaborPoints(Skills);

	int CashE = CalculateCash(LaborPoints, Skills.MoneyPercentage) * 0.1f;
	int XPE = CalculateXP(LaborPoints, Skills.XPPercentage) * 0.1f;
	int LuckE = CalculateLuck(LaborPoints, Skills.XPPercentage);

	TArray<float> FindingChances;
	for (int i = 0; i < Rewards.Num(); i++)
		FindingChances.Add(CalculateFindingChance(i, LaborPoints, Skills.FindingChance) / 210.f);

	for (int i = 0; i < FindingChances.Num(); i++)
		if (FindingChances[i] < 0.02f)
			FindingChances[i] = 0.02f;

	float DamageChanceE = CalculateDamageChance(LaborPoints);
	int DamageE = 0;
	if (FMath::RandRange(0.0, 1.0) < DamageChanceE)
		DamageE = CalculateDamage(LaborPoints);

	bool FoundItem = FindsItem(1);

	Report.CashGained = CashE;
	Report.XPGained = XPE;
	Report.WorkLength = 1;
	Report.Damage = DamageE;

	UGI_WestGameInstance* Instance = Cast<UGI_WestGameInstance>(UGameplayStatics::GetGameInstance(WorldContext));

	for (int i = 0; i < FindingChances.Num(); i++)
	{
		while (FindingChances[i] > 1.f)
		{
			Report.Rewards.Add(Instance->GameData->FindItemByIdentifier(Rewards[i].IdentifierName));
			FindingChances[i] -= 1.f;
		}
		if (FMath::RandRange(0.0, 1.0) < FindingChances[i])
			Report.Rewards.Add(Instance->GameData->FindItemByIdentifier(Rewards[i].IdentifierName));
	}

	if (FoundItem)
	{
		Report.Rewards.Add(Instance->GameData->FindItemInPriceRange(Luck / 3, Luck));
	}

	return Report;
}

WJobReport FWJob::SimulateMediumJob(WSkillSet Skills, const UObject* WorldContext)
{
	WJobReport Report;

	int LaborPoints = CalculateLaborPoints(Skills);

	int CashE = CalculateCash(LaborPoints, Skills.MoneyPercentage) * 0.47f;
	int XPE = CalculateXP(LaborPoints, Skills.XPPercentage) * 0.47f;
	int LuckE = CalculateLuck(LaborPoints, Skills.XPPercentage);

	TArray<float> FindingChances;
	for (int i = 0; i < Rewards.Num(); i++)
		FindingChances.Add(CalculateFindingChance(i, LaborPoints, Skills.FindingChance) * 0.1667f);

	for (int i = 0; i < FindingChances.Num(); i++)
		if (FindingChances[i] < 0.02f)
			FindingChances[i] = 0.02f;

	float DamageChanceE = CalculateDamageChance(LaborPoints);
	int DamageE = 0;
	if (FMath::RandRange(0.0, 1.0) < DamageChanceE)
		DamageE = CalculateDamage(LaborPoints);

	bool FoundItem = FindsItem(5);

	Report.CashGained = CashE;
	Report.XPGained = XPE;
	Report.WorkLength = 5;
	Report.Damage = DamageE;

	UGI_WestGameInstance* Instance = Cast<UGI_WestGameInstance>(UGameplayStatics::GetGameInstance(WorldContext));

	for (int i = 0; i < FindingChances.Num(); i++)
	{
		while (FindingChances[i] > 1.f)
		{
			Report.Rewards.Add(Instance->GameData->FindItemByIdentifier(Rewards[i].IdentifierName));
			FindingChances[i] -= 1.f;
		}
		if (FMath::RandRange(0.0, 1.0) < FindingChances[i])
			Report.Rewards.Add(Instance->GameData->FindItemByIdentifier(Rewards[i].IdentifierName));
	}

	if (FoundItem)
	{
		Report.Rewards.Add(Instance->GameData->FindItemInPriceRange(Luck / 3, Luck));
	}

	return Report;
}

WJobReport FWJob::SimulateLargeJob(WSkillSet Skills, const UObject* WorldContext)
{
	WJobReport Report;

	int LaborPoints = CalculateLaborPoints(Skills);

	int CashE = CalculateCash(LaborPoints, Skills.MoneyPercentage);
	int XPE = CalculateXP(LaborPoints, Skills.XPPercentage);
	int LuckE = CalculateLuck(LaborPoints, Skills.XPPercentage);

	TArray<float> FindingChances;
	for (int i = 0; i < Rewards.Num(); i++)
		FindingChances.Add(CalculateFindingChance(i, LaborPoints, Skills.FindingChance));

	for (int i = 0; i < FindingChances.Num(); i++)
		if (FindingChances[i] < 0.02f)
			FindingChances[i] = 0.02f;

	float DmgChance = CalculateDamageChance(LaborPoints);
	int Dmg = 0;
	if (FMath::RandRange(0.0, 1.0) < DmgChance)
		Dmg = CalculateDamage(LaborPoints);

	bool FoundItem = FindsItem(12);

	Report.CashGained = CashE;
	Report.XPGained = XPE;
	Report.WorkLength = 12;
	Report.Damage = Damage;

	UGI_WestGameInstance* Instance = Cast<UGI_WestGameInstance>(UGameplayStatics::GetGameInstance(WorldContext));
	
	for (int i = 0; i < FindingChances.Num(); i++)
	{
		while (FindingChances[i] > 1.f)
		{
			Report.Rewards.Add(Instance->GameData->FindItemByIdentifier(Rewards[i].IdentifierName));
			FindingChances[i] -= 1.f;
		}
		if(FMath::RandRange(0.0,1.0) < FindingChances[i])
			Report.Rewards.Add(Instance->GameData->FindItemByIdentifier(Rewards[i].IdentifierName));
	}
	
	if (FoundItem)
	{
		Report.Rewards.Add(Instance->GameData->FindItemInPriceRange(Luck/3,Luck));
	}

	return Report;
}
