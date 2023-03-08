// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "WSkillSet.h"
#include "WPlayer.generated.h"

UCLASS()
class WESTLOCAL_API AWPlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AWPlayer();

	WSkillSet CharacterSkills;
	WSkillSet ClothesSkills;
	WSkillSet SetSkills;
	WSkillSet BuffSkills;

	virtual int GetTotalStrength() const;
	virtual int GetTotalMobility() const;
	virtual int GetTotalDexterity() const;
	virtual int GetTotalCharisma() const;

	virtual int GetTotalConstruction() const;
	virtual int GetTotalVigor() const;
	virtual int GetTotalToughness() const;
	virtual int GetTotalStamina() const;
	virtual int GetTotalHealthPoints() const;

	virtual int GetTotalRiding() const;
	virtual int GetTotalReflex() const;
	virtual int GetTotalDodging() const;
	virtual int GetTotalHiding() const;
	virtual int GetTotalSwimming() const;

	virtual int GetTotalAiming() const;
	virtual int GetTotalShooting() const;
	virtual int GetTotalTrapping() const;
	virtual int GetTotalFineMotorSkills() const;
	virtual int GetTotalRepairing() const;
	
	virtual int GetTotalLeadership() const;
	virtual int GetTotalTactic() const;
	virtual int GetTotalTrading() const;
	virtual int GetTotalAnimalInstinct() const;
	virtual int GetTotalAppearance() const;

	virtual int GetTotalFindingChance() const;
	virtual int GetTotalLuck() const;
	virtual int GetTotalMoneyPercentage() const;
	virtual int GetTotalXPPercentage() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
