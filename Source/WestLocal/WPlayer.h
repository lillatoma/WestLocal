// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "WSkillSet.h"
#include "WInventory.h"
#include "WJob.h"
#include "WSet.h"
#include "WPlayer.generated.h"

UCLASS()
class WESTLOCAL_API AWPlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AWPlayer();

#pragma region Skills
public:
	UPROPERTY(VisibleAnywhere)
		FWSkillSet CharacterSkills;
	UPROPERTY(VisibleAnywhere)
		FWSkillSet ClothesSkills;
	UPROPERTY(VisibleAnywhere)
		FWSkillSet SetSkills;
	UPROPERTY(VisibleAnywhere)
		FWSkillSet BuffSkills;
	UPROPERTY(VisibleAnywhere)
		FWSkillSet TotalSkills;

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

	virtual float GetTotalFindingChance() const;
	virtual float GetTotalLuck() const;
	virtual float GetTotalMoneyPercentage() const;
	virtual float GetTotalXPPercentage() const;
	virtual float GetTotalSpeed() const;

	virtual int GetTotalOf(WSkillNames Skill) const;

	virtual int GetTotalExtraWorkPoints() const;
	virtual int GetTotalDamageMin() const;
	virtual int GetTotalDamageMax() const;
	virtual int GetTotalFortDamageMin() const;
	virtual int GetTotalFortDamageMax() const;


#pragma endregion

public:
	UPROPERTY(VisibleAnywhere)
	UWInventory* Inventory;

	FWInventoryItemBase* Hat;
	FWInventoryItemBase* Neck;
	FWInventoryItemBase* Body;
	FWInventoryItemBase* LeftHand;
	FWInventoryItemBase* RightHand;
	FWInventoryItemBase* Belt;
	FWInventoryItemBase* Pants;
	FWInventoryItemBase* Shoes;
	FWInventoryItemBase* Horse;
	FWInventoryItemBase* Product;

	virtual TArray<EInvSlot> GetAllSlots() const;

	virtual void TakeOffHat();
	virtual void TakeOffNeck();
	virtual void TakeOffBody();
	virtual void TakeOffLeftHand();
	virtual void TakeOffRightHand();
	virtual void TakeOffBelt();
	virtual void TakeOffPants();
	virtual void TakeOffShoes();
	virtual void TakeOffHorse();
	virtual void TakeOffProduct();

	virtual void TakeOffAll();

	virtual void TakeOnHat(int Index);
	virtual void TakeOnNeck(int Index);
	virtual void TakeOnBody(int Index);
	virtual void TakeOnLeftHand(int Index);
	virtual void TakeOnRightHand(int Index);
	virtual void TakeOnBelt(int Index);
	virtual void TakeOnPants(int Index);
	virtual void TakeOnShoes(int Index);
	virtual void TakeOnHorse(int Index);
	virtual void TakeOnProduct(int Index);

	virtual void TakeOn(int Index);

	virtual bool HasItemInSlot(EInvSlot Slot);
	virtual FWInventoryItemBase* GetItemInSlot(EInvSlot Slot);
	virtual TArray<FWInventoryItemBase*> GetSlottedItems();

	virtual TArray<int> GetAllItemsForSlot(EInvSlot Slot);

	virtual bool IsSetItemInSlot(FWSet Set,EInvSlot Slot);
	virtual int FindItemCountForSet(FWSet Set);
	virtual int FindItemCountForSet(FWSet Set, TArray<EInvSlot> RemainingSlots);
	virtual int RateSetForJob(FWJob Job, FWSet Set, int Count);

	virtual int CalculateSetLossFromTakeOff(FWJob Job, TArray<int> TakeOns, int Index);
	virtual int CalculateSetLossFromTakeOff(FWJob Job, FWSet Set, int CountFrom);
	virtual int CalculateSetGainFromTakeOn(FWJob Job, TArray<int> TakeOns, int Index);
	virtual int CalculateSetGainFromTakeOn(FWJob Job, FWSet Set, int CountFrom);
	virtual TArray<FWSet> FindAllSetsFromInventory();


	virtual int RateSingularItemForJob(FWJob Job, int Index);
	virtual int RateSingularItemForJob(FWJob Job, FWInventoryItemBase Item);
	virtual int FindBestSetSlotItemForJob(FWJob Job, FWSet Set, EInvSlot Slot);
	virtual int FindBestSlotItemForJobNonPut(FWJob Job, EInvSlot Slot);
	virtual void FindBestSlotItemForJob(FWJob Job, EInvSlot Slot);
	virtual TArray<int> FindBestSetForJob(FWJob Job, TArray<EInvSlot> RemainingSlots);
	virtual void FindBestInventoryForJobSetted(FWJob Job);
	
	virtual void FindBestInventoryForJob(FWJob Job);

	virtual void EmptyClothesSkillSet();
	virtual void CalculateClothingForSkillSet(EInvSlot Slot);
	virtual void CalculateClothesSkillSet();
	virtual void EmptySetSkillSet();
	virtual void CalculateSetForSkillSet(FString SetName);
	virtual void CalculateSetSkillSet();



	FWSkillSet GetTotalSkills() const;

	int Level = 1;
	int Money = 0;
	int Bank = 0;
	int XPToNextLevel = 0;
	int UnspentSkillPoints = 0;
	int UnspentAttributePoints = 0;
	virtual int GetLevel() const;
	virtual bool EligibleForNextLevel() const;
	virtual void LevelUp();
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool AutoSpendSkills = false;
	UFUNCTION(BlueprintCallable)
		virtual void SpendSkillPoint(WSkillNames Skill);
	UFUNCTION(BlueprintCallable)
		virtual void SpendAttributePoint(WSkillNames Skill);
	virtual void AutoSpendSkillsFunc();

	UFUNCTION(BlueprintCallable)
		virtual void WorkJob(FWJob Job, EWorkLength Length);

	UPROPERTY()
		class UUWGameUI* UI;

	virtual void UpdateUI();

protected:

	void StopCursor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
		class UGI_WestGameInstance* GameInstance;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
