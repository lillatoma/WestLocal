// Fill out your copyright notice in the Description page of Project Settings.


#include "WPlayer.h"

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

int AWPlayer::GetTotalExtraWorkPoints() const
{
	return CharacterSkills.ExtraWorkPoints + ClothesSkills.ExtraWorkPoints + SetSkills.ExtraWorkPoints + BuffSkills.ExtraWorkPoints;
}

WSkillSet AWPlayer::GetTotalSkills() const
{
	WSkillSet Total;
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

	return Total;
}

// Called when the game starts or when spawned
void AWPlayer::BeginPlay()
{
	Super::BeginPlay();
	
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

