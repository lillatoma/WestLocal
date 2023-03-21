// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WSkillSet.h"

#include "WItemAttribute.generated.h"
/**
 * 
 */
USTRUCT(Blueprintable)
struct WESTLOCAL_API FWItemAttribute
{
	GENERATED_BODY()
public:
	FWItemAttribute();
	~FWItemAttribute();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		WSkillNames FixedSkill;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int IntValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float FloatValue;
};
USTRUCT(Blueprintable)
struct WESTLOCAL_API FWLeveledItemAttribute
{
	GENERATED_BODY()
public:
	FWLeveledItemAttribute();
	~FWLeveledItemAttribute();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		WSkillNames LeveledSkill;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float FloatValue;

};

USTRUCT(Blueprintable)
struct WESTLOCAL_API FWCombinedAttributeList
{
	GENERATED_BODY()
public:
	FWCombinedAttributeList();
	~FWCombinedAttributeList();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FWItemAttribute> FixedAttributes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FWLeveledItemAttribute> LeveledAttributes;

	void AddTogether(FWCombinedAttributeList B);
};