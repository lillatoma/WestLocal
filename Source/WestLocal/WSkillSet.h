// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

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

	ExtraWorkPoints
};



/**
 * 
 */
class WESTLOCAL_API WSkillSet
{
public:
	WSkillSet();
	~WSkillSet();

#pragma region Attributes

	int Strength = 0;
	int Mobility = 0;
	int Dexterity = 0;
	int Charisma = 0;

#pragma endregion

#pragma region Strength

	int Construction = 0;
	int Vigor = 0;
	int Toughness = 0;
	int Stamina = 0;
	int HealthPoints = 0;

#pragma endregion

#pragma region Mobility

	int Riding = 0;
	int Reflex = 0;
	int Dodging = 0;
	int Hiding = 0;
	int Swimming = 0;
	
#pragma endregion

#pragma region Dexterity

	int Aiming = 0;
	int Shooting = 0;
	int Trapping = 0;
	int FineMotorSkills = 0;
	int Repairing = 0;

#pragma endregion

#pragma region Charisma

	int Leadership = 0;
	int Tactic = 0;
	int Trading = 0;
	int AnimalInstinct = 0;
	int Appearance = 0;

#pragma endregion

#pragma region Bonus

	float FindingChance = 1.0f;
	float Luck = 1.0f;
	float MoneyPercentage = 1.0f;
	float XPPercentage = 1.0f;
	float Speed;

	int ExtraWorkPoints;
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
#pragma endregion


};
