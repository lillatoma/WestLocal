// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WSkillSet.h"
#include "WJob.h"
#include "WJobPlace.h"
#include "Blueprint/UserWidget.h"
#include "UWGameUI.generated.h"

/**
 * 
 */
UCLASS()
class WESTLOCAL_API UUWGameUI : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
		void SpendSkillPoint(WSkillNames Skill);

	UFUNCTION(BlueprintCallable)
		void SpendAttributePoint(WSkillNames Skill);

	UFUNCTION(BlueprintCallable)
		FString UpdateSkillText(WSkillNames Skill);

	UFUNCTION(BlueprintCallable)
		FString UpdateUnspentSkillText();

	UFUNCTION(BlueprintCallable)
		FString UpdateUnspentAttributesText();

	UFUNCTION(BlueprintCallable)
		class UGI_WestGameInstance* FindGameInstance();

#pragma region Jobs

	UFUNCTION(BlueprintCallable)
		void PreviousJobPlace();

	UFUNCTION(BlueprintCallable)
		void NextJobPlace();

	UFUNCTION(BlueprintCallable)
		int GetCurrentJobPlaceJobCount();

	UFUNCTION(BlueprintCallable)
		void SetJob(int index);

	UFUNCTION(BlueprintCallable)
		bool ShouldShowJobPanelOnRight();

	UFUNCTION(BlueprintCallable)
		FWJobPlace GetCurrentJobPlace();

	UFUNCTION(BlueprintCallable)
		FString GetCurrentJobPlaceName();

	UFUNCTION(BlueprintCallable)
		FString GetJobNameForID(int ID);

	UFUNCTION(BlueprintCallable)
		FWJob GetCurrentJob();

	UFUNCTION(BlueprintCallable)
		bool IsJobWorkable();

	UFUNCTION(BlueprintCallable)
		int GetCurrentJobProductCount();

	UFUNCTION(BlueprintCallable)
		FString GetSmallCash();

	UFUNCTION(BlueprintCallable)
		FString GetSmallXP();

	UFUNCTION(BlueprintCallable)
		FString GetSmallLuck();

	UFUNCTION(BlueprintCallable)
		FString GetSmallProductName(int id);

	UFUNCTION(BlueprintCallable)
		FString GetSmallProductPercent(int id);

	UFUNCTION(BlueprintCallable)
		FString GetMidCash();

	UFUNCTION(BlueprintCallable)
		FString GetMidXP();

	UFUNCTION(BlueprintCallable)
		FString GetMidLuck();

	UFUNCTION(BlueprintCallable)
		FString GetMidProductName(int id);

	UFUNCTION(BlueprintCallable)
		FString GetMidProductPercent(int id);

	UFUNCTION(BlueprintCallable)
		FString GetLongCash();

	UFUNCTION(BlueprintCallable)
		FString GetLongXP();

	UFUNCTION(BlueprintCallable)
		FString GetLongLuck();

	UFUNCTION(BlueprintCallable)
		FString GetLongProductName(int id);

	UFUNCTION(BlueprintCallable)
		FString GetLongProductPercent(int id);

	UFUNCTION(BlueprintCallable)
		bool IsCurrentJobValid();

#pragma endregion

#pragma region Inventory
	UFUNCTION(BlueprintCallable)
		FString GetEquippedItemName(EInvSlot ISlot);
	UFUNCTION(BlueprintCallable)
		bool IsItemEquippedInSlot(EInvSlot ISlot);
	UFUNCTION(BlueprintCallable)
		void TryUnequipItem(EInvSlot ISlot);

	UFUNCTION(BlueprintCallable)
		bool IsItemAtIndex(int SubIdx);

	UFUNCTION(BlueprintCallable)
		FString GetItemNameAtIndex(int SubIdx);

	UFUNCTION(BlueprintCallable)
		FString GetItemCountAtIndex(int SubIdx);

	UFUNCTION(BlueprintCallable)
		void TryEquipItem(int SubIdx);

	UFUNCTION(BlueprintCallable)
		void NextInventoryPage();

	UFUNCTION(BlueprintCallable)
		void PreviousInventoryPage();


#pragma endregion


	void SetPlayer(class AWPlayer* P);


private:
	UPROPERTY()
		class AWPlayer* Player;

	UPROPERTY(EditAnywhere)
		class UGI_WestGameInstance* Instance;

	UPROPERTY(EditAnywhere)
		int JobPlaceIndex = 0;

	UPROPERTY(EditAnywhere)
		int JobIndex = -1;

	UPROPERTY(EditAnywhere)
		int InvFirstItemIndex = 0;
	
};
