// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WSkillSet.generated.h"

UENUM(BlueprintType)
enum class WSkillNames : uint8
{
	Strength,
	Mobility,
	Dexterity,
	Charisma,
	
	Construction,
	Vigor,
	Toughness,
	Stamina,
	HealthPoints,
	
	Riding,
	Reflex,
	Dodging,
	Hiding,
	Swimming,
	
	Aiming,
	Shooting,
	Trapping,
	FineMotorSkills,
	Repairing,
	
	Leadership,
	Tactic,
	Trading,
	AnimalInstinct,
	Appearance,

	FindingChance,
	Luck,
	XPPercentage,
	MoneyPercentage,
	Speed,

	ExtraWorkPoints,

	DamageMin,
	DamageMax,
	FortDamageMin,
	FortDamageMax
};

static bool IsStrengthSkill(WSkillNames Skill)
{
	return Skill == WSkillNames::Construction
		|| Skill == WSkillNames::Vigor
		|| Skill == WSkillNames::Toughness
		|| Skill == WSkillNames::Stamina
		|| Skill == WSkillNames::HealthPoints;
}
static bool IsMobilitySkill(WSkillNames Skill)
{
	return Skill == WSkillNames::Riding
		|| Skill == WSkillNames::Reflex
		|| Skill == WSkillNames::Dodging
		|| Skill == WSkillNames::Hiding
		|| Skill == WSkillNames::Swimming;
}
static bool IsDexteritySkill(WSkillNames Skill)
{
	return Skill == WSkillNames::Aiming
		|| Skill == WSkillNames::Shooting
		|| Skill == WSkillNames::Trapping
		|| Skill == WSkillNames::FineMotorSkills
		|| Skill == WSkillNames::Repairing;
}
static bool IsCharismaSkill(WSkillNames Skill)
{
	return Skill == WSkillNames::Leadership
		|| Skill == WSkillNames::Tactic
		|| Skill == WSkillNames::Trading
		|| Skill == WSkillNames::AnimalInstinct
		|| Skill == WSkillNames::Appearance;
}

static bool IsSkillPoint(WSkillNames Skill)
{
	return Skill == WSkillNames::Strength
		|| Skill == WSkillNames::Mobility
		|| Skill == WSkillNames::Dexterity
		|| Skill == WSkillNames::Charisma;
}

static bool IsAttributePoint(WSkillNames Skill)
{
	return IsStrengthSkill(Skill)
		|| IsMobilitySkill(Skill)
		|| IsDexteritySkill(Skill)
		|| IsCharismaSkill(Skill);		
}


/**
 * 
 */
USTRUCT(Blueprintable)
struct WESTLOCAL_API FWSkillSet
{
	GENERATED_BODY()
public:
	FWSkillSet();
	~FWSkillSet();

#pragma region Attributes
	UPROPERTY(VisibleAnywhere)
		int Strength = 0;
	UPROPERTY(VisibleAnywhere)
		int Mobility = 0;
	UPROPERTY(VisibleAnywhere)
		int Dexterity = 0;
	UPROPERTY(VisibleAnywhere)
		int Charisma = 0;


#pragma endregion

#pragma region Strength
	UPROPERTY(VisibleAnywhere)
		int Construction = 0;
	UPROPERTY(VisibleAnywhere)
		int Vigor = 0;
	UPROPERTY(VisibleAnywhere)
		int Toughness = 0;
	UPROPERTY(VisibleAnywhere)
		int Stamina = 0;
	UPROPERTY(VisibleAnywhere)
		int HealthPoints = 0;

#pragma endregion

#pragma region Mobility

	UPROPERTY(VisibleAnywhere)
		int Riding = 0;
	UPROPERTY(VisibleAnywhere)
		int Reflex = 0;
	UPROPERTY(VisibleAnywhere)
		int Dodging = 0;
	UPROPERTY(VisibleAnywhere)
		int Hiding = 0;
	UPROPERTY(VisibleAnywhere)
		int Swimming = 0;
	
#pragma endregion

#pragma region Dexterity
	UPROPERTY(VisibleAnywhere)
		int Aiming = 0;
	UPROPERTY(VisibleAnywhere)
		int Shooting = 0;
	UPROPERTY(VisibleAnywhere)
		int Trapping = 0;
	UPROPERTY(VisibleAnywhere)
		int FineMotorSkills = 0;
	UPROPERTY(VisibleAnywhere)
		int Repairing = 0;

#pragma endregion

#pragma region Charisma
	UPROPERTY(VisibleAnywhere)
		int Leadership = 0;
	UPROPERTY(VisibleAnywhere)
		int Tactic = 0;
	UPROPERTY(VisibleAnywhere)
		int Trading = 0;
	UPROPERTY(VisibleAnywhere)
		int AnimalInstinct = 0;
	UPROPERTY(VisibleAnywhere)
		int Appearance = 0;

#pragma endregion

#pragma region Bonus

	UPROPERTY(VisibleAnywhere)
		float FindingChance = 1.0f;
	UPROPERTY(VisibleAnywhere)
		float Luck = 1.0f;
	UPROPERTY(VisibleAnywhere)
		float MoneyPercentage = 1.0f;
	UPROPERTY(VisibleAnywhere)
		float XPPercentage = 1.0f;
	UPROPERTY(VisibleAnywhere)
		float Speed;

	UPROPERTY(VisibleAnywhere)
		int ExtraWorkPoints = 0;

	UPROPERTY(VisibleAnywhere)
		int DamageMin = 0;
	UPROPERTY(VisibleAnywhere)
		int DamageMax = 0;

	UPROPERTY(VisibleAnywhere)
		int FortDamageMin = 0;
	UPROPERTY(VisibleAnywhere)
		int FortDamageMax = 0;

#pragma endregion



};

//This one is a level-scalable skillset
class WESTLOCAL_API WFSkillSet
{
public:
	WFSkillSet();
	~WFSkillSet();

#pragma region Attributes

	float Strength = 0;
	float Mobility = 0;
	float Dexterity = 0;
	float Charisma = 0;

#pragma endregion

#pragma region Strength

	float Construction = 0;
	float Vigor = 0;
	float Toughness = 0;
	float Stamina = 0;
	float HealthPoints = 0;

#pragma endregion

#pragma region Mobility

	float Riding = 0;
	float Reflex = 0;
	float Dodging = 0;
	float Hiding = 0;
	float Swimming = 0;

#pragma endregion

#pragma region Dexterity

	float Aiming = 0;
	float Shooting = 0;
	float Trapping = 0;
	float FineMotorSkills = 0;
	float Repairing = 0;

#pragma endregion

#pragma region Charisma

	float Leadership = 0;
	float Tactic = 0;
	float Trading = 0;
	float AnimalInstinct = 0;
	float Appearance = 0;

#pragma endregion

#pragma region Bonus

	float FindingChance = 0.0f;
	float Luck = 0.0f;
	float MoneyPercentage = 0.0f;
	float XPPercentage = 0.0f;
	float Speed = 0.0f;

	float ExtraWorkPoints = 0.0f;

	float DamageMin = 0.0f;
	float DamageMax = 0.0f;
	float FortDamageMin = 0.0f;
	float FortDamageMax = 0.0f;
#pragma endregion



};
