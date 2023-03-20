// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WInventoryItemBase.h"
#include "WSkillSet.h"
#include "WJob.generated.h"


UENUM(BlueprintType)
enum class EWorkLength :uint8
{
	Short,
	Medium,
	Long
};

USTRUCT(Blueprintable)
struct WESTLOCAL_API FWJobReward
{
	GENERATED_BODY()
public:
	FWJobReward();
	~FWJobReward();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString IdentifierName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Percentage;
};

struct WJobReport
{
	int WorkLength;
	int CashGained;
	int XPGained;
	int LuckPotential;
	int Damage;
	TArray<FWInventoryItemBase> Rewards;
};


/**
 * 
 */
USTRUCT(Blueprintable)
struct WESTLOCAL_API FWJob
{
	GENERATED_BODY()
public:
	FWJob();
	~FWJob();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString JobName;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		WSkillNames NeededAttribute1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		WSkillNames NeededAttribute2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		WSkillNames NeededAttribute3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		WSkillNames NeededAttribute4;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		WSkillNames NeededAttribute5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int MinLevel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int MinDifficulty;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Cash;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int XP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Luck;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float DamageChance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Damage;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FWJobReward> Rewards;
	
	bool IsJobWorkable(int Level, int LaborPoints);

	int CalculateCash(int LaborPoints, float Modifier);
	int CalculateXP(int LaborPoints, float Modifier);
	int CalculateLuck(int LaborPoints, float Modifier);
	float CalculateFindingChance(int Index, int LaborPoints, float Modifier);
	int CalculateCash(int LaborPoints, float Modifier, EWorkLength Length);
	int CalculateXP(int LaborPoints, float Modifier, EWorkLength Length);
	int CalculateLuck(int LaborPoints, float Modifier, EWorkLength Length);
	float CalculateFindingChance(int Index, int LaborPoints, float Modifier, EWorkLength Length);

	float CalculateDamageChance(int LaborPoints);
	int CalculateDamage(int LaborPoints);

	bool FindsItem(int WorkLength);
	int CalculateSmallLaborPoints(FWSkillSet Skills, WSkillNames Skill);
	int CalculateLaborPoints(FWSkillSet Skills);

	WJobReport SimulateSmallJob(FWSkillSet Skills, const UObject* WorldContext);
	WJobReport SimulateMediumJob(FWSkillSet Skills, const UObject* WorldContext);
	WJobReport SimulateLargeJob(FWSkillSet Skills, const UObject* WorldContext);

	WJobReport SimulateJob(FWSkillSet Skills, EWorkLength Length, const UObject* WorldContext);

};
