// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WSkillSet.h"
#include "WQuest.generated.h"


USTRUCT(Blueprintable)
struct WESTLOCAL_API FWQuestRequirement
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString QuestFinished;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString HasItem;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int HasItemCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString NeedsItem;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int NeedsItemCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString WearsItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString WorkedJob;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int TimeWorkedNeeded;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int AmountsWorkedNeeded;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int TimeWorked;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int AmountsWorked;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int LevelsReached;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int HasMoney;
};


USTRUCT(Blueprintable)
struct WESTLOCAL_API FWQuestReward
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ItemIdentifier;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Count;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Money;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int XP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int AttributePoints;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int SkillPoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		WSkillNames Skill;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Points;

};

/**
 * 
 */
USTRUCT(Blueprintable)
struct WESTLOCAL_API FWQuest
{
	GENERATED_BODY()
public:
	FWQuest();
	~FWQuest();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString QuestName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FWQuestRequirement> VisibilityRequirements;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FWQuestRequirement> FinishRequirements;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FWQuestReward> FinishRewards;

};
