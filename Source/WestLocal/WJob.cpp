// Fill out your copyright notice in the Description page of Project Settings.


#include "WJob.h"

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
		ReturnCash = Cash + (1.f * (LaborPoints - MinDifficulty) / (2.f * MinDifficulty)) * Cash;
	else
	{
		int LP = LaborPoints - 3 * MinDifficulty;
		float Multiplier = 2.f;
		float MultiplierAdd = 0.5f;
		while (LP > 2 * MinDifficulty)
		{
			Multiplier += MultiplierAdd;
			MultiplierAdd *= 0.5f;
			LP -= 2 * MinDifficulty;
		}
		Multiplier += MultiplierAdd * (1.f * LP / 2 * MinDifficulty);
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
		ReturnLuck = Luck + (1.f * (LaborPoints - MinDifficulty) / (2.f * MinDifficulty)) * Luck;
	else
	{
		int LP = LaborPoints - 3 * MinDifficulty;
		float Multiplier = 2.f;
		float MultiplierAdd = 0.5f;
		while (LP > 2 * MinDifficulty)
		{
			Multiplier += MultiplierAdd;
			MultiplierAdd *= 0.5f;
			LP -= 2 * MinDifficulty;
		}
		Multiplier += MultiplierAdd * (1.f * LP / 2 * MinDifficulty);
		ReturnLuck = Luck * Multiplier;
	}
	return ReturnLuck * Modifier;
}

int FWJob::CalculateDamageChance(int LaborPoints)
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
