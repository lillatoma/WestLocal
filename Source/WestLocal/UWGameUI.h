// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WSkillSet.h"
#include "WJob.h"
#include "WJobPlace.h"
#include "WQuestline.h"
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
		void GetBestPossibleEquipment();

	UFUNCTION(BlueprintCallable)
		void GetBestPossibleEquipmentSetted();

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

	UFUNCTION(BlueprintCallable)
		void TryWorkJob(EWorkLength Length);

#pragma endregion

#pragma region Inventory
	UFUNCTION(BlueprintCallable)
		FString GetEquippedItemName(EInvSlot ISlot);
	UFUNCTION(BlueprintCallable)
		bool IsItemEquippedInSlot(EInvSlot ISlot);
	UFUNCTION(BlueprintCallable)
		void TryUnequipItem(EInvSlot ISlot);


	UFUNCTION(BlueprintCallable)
		void MakePageValid();

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

#pragma region ItemDesc

	UFUNCTION(BlueprintCallable)
		bool ShouldShowItemDescription(int SubIdx);

	UFUNCTION(BlueprintCallable)
		bool ShouldShowItemDescriptionSlot(EInvSlot ISlot);

	UFUNCTION(BlueprintCallable)
		FString GetItemDescriptionName(int SubIdx);

	UFUNCTION(BlueprintCallable)
		FString GetItemDescriptionNameSlot(EInvSlot ISlot);

	UFUNCTION(BlueprintCallable)
		FString GetItemDescriptionBuffs(int SubIdx);

	UFUNCTION(BlueprintCallable)
		FString GetItemDescriptionBuffsSlot(EInvSlot ISlot);

	UFUNCTION(BlueprintCallable)
		FString GetItemDescriptionLevelReq(int SubIdx);

	UFUNCTION(BlueprintCallable)
		FString GetItemDescriptionLevelReqSlot(EInvSlot ISlot);

	UFUNCTION(BlueprintCallable)
		FString GetItemDescriptionPrice(int SubIdx);

	UFUNCTION(BlueprintCallable)
		FString GetItemDescriptionPriceSlot(EInvSlot ISlot);

#pragma endregion

#pragma region JobDesc

	UFUNCTION(BlueprintCallable)
		bool ShouldShowJobDescription(int JPIndex);

	UFUNCTION(BlueprintCallable)
		FString GetJobDescriptionName(int JPIndex);
	
	UFUNCTION(BlueprintCallable)
		bool IsJobDescriptionWorkable(int JPIndex);

	FString GetJobDescriptionSkillName(WSkillNames SkillName);

	int GetJobDescriptionSkillValue(WSkillNames SkillName, FWSkillSet Skills);

	UFUNCTION(BlueprintCallable)
		FString GetJobDescriptionLaborPoints(int JPIndex);

	UFUNCTION(BlueprintCallable)
		FString GetJobDescriptionLevelReq(int JPIndex);

#pragma endregion

#pragma region QuestsPage

	UFUNCTION(BlueprintCallable)
		TArray<FWQuest> GetAllPossibleQuests();

	UFUNCTION(BlueprintCallable)
		void OnQuestsPageOpen();


	UFUNCTION(BlueprintCallable)
		void PreviousQuestPage(TArray<FWQuest> Quests);

	UFUNCTION(BlueprintCallable)
		void NextQuestPage(TArray<FWQuest> Quests);
	
	UFUNCTION(BlueprintCallable)
		bool IsQuestVisibleAtIndex(TArray<FWQuest> Quests, int SubIdx);

	UFUNCTION(BlueprintCallable)
		FString GetQuestNameAtIndex(TArray<FWQuest> Quests, int SubIdx);

	UFUNCTION(BlueprintCallable)
		void SelectQuestAtIndex(TArray<FWQuest> Quests, int SubIdx);

	UFUNCTION(BlueprintCallable)
		bool ShouldShowQuestPanelOnRight(TArray<FWQuest> Quests);

	UFUNCTION(BlueprintCallable)
		FString GetCurrentQuestName(TArray<FWQuest> Quests);

	UFUNCTION(BlueprintCallable)
		FString GetCurrentQuestFinishRequirements(TArray<FWQuest> Quests);

	UFUNCTION(BlueprintCallable)
		FString GetCurrentQuestFinishRewards(TArray<FWQuest> Quests);

	UFUNCTION(BlueprintCallable)
		bool IsSelectedQuestAcceptable(TArray<FWQuest> Quests);

	UFUNCTION(BlueprintCallable)
		bool IsSelectedQuestFinishable(TArray<FWQuest> Quests);

	UFUNCTION(BlueprintCallable)
		bool TryAcceptQuest(TArray<FWQuest> Quests);

	UFUNCTION(BlueprintCallable)
		bool TryFinishQuest(TArray<FWQuest> Quests);

#pragma endregion

#pragma region Shop

	UFUNCTION(BlueprintCallable)
		void TryRefreshShopItems();

	UFUNCTION(BlueprintCallable)
		void TryBuyShopItem(EInvSlot ISlot);

	UFUNCTION(BlueprintCallable)
		FString GetNameOfShopItem(EInvSlot ISlot);

	UFUNCTION(BlueprintCallable)
		FString GetPriceOfShopItem(EInvSlot ISlot);

	UFUNCTION(BlueprintCallable)
		FString GetShopItemDescriptionName(EInvSlot ISlot);

	UFUNCTION(BlueprintCallable)
		FString GetShopItemDescriptionBuffs(EInvSlot ISlot);

	UFUNCTION(BlueprintCallable)
		FString GetShopItemDescriptionPrice(EInvSlot ISlot);

	UFUNCTION(BlueprintCallable)
		FString GetShopItemDescriptionMinLevel(EInvSlot ISlot);

#pragma endregion


	void SetPlayer(class AWPlayer* P);

	UFUNCTION(BlueprintImplementableEvent)
		void SetUIWithPlayerData(int Level, int XP, int XP_Next, int Cash);

	UFUNCTION(BlueprintCallable)
		int GetJobIndex();




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

	UPROPERTY(EditAnywhere)
		int QuestFirstIndex = 0;
	

	UPROPERTY(EditAnywhere)
		int CurrentQuestIndex = -1;

};
