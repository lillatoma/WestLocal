// Fill out your copyright notice in the Description page of Project Settings.


#include "WQuest.h"
#include "WPlayer.h"
#include "GI_WestGameInstance.h"
#include "WGameData.h"

FWQuest::FWQuest()
{
}

FWQuest::~FWQuest()
{
}

bool FWQuest::Is(FWQuest Quest)
{
	return QuestName.Compare(Quest.QuestName) == 0;
}

bool FWQuest::Is(FString OtherQuestName)
{
	return QuestName.Compare(OtherQuestName) == 0;
}

bool FWQuest::IsVisible(class AWPlayer* Player)
{
	for (int i = 0; i < Player->FinishedQuests.Num(); i++)
		if (Is(Player->FinishedQuests[i]))
			return false;

	for (int i = 0; i < VisibilityRequirements.Num(); i++)
	{

		if (VisibilityRequirements[i].LevelsReached > Player->Level)
			return false;

		if (VisibilityRequirements[i].QuestFinished.Len() > 0)
		{
			bool bQuestFinished = false;
			for (int j = 0; j < Player->FinishedQuests.Num(); j++)
			{
				if (VisibilityRequirements[i].QuestFinished.Compare(Player->FinishedQuests[j]) == 0)
					bQuestFinished = true;

			}
			if (!bQuestFinished)
				return false;
		}

		if (VisibilityRequirements[i].HasItem.Len() > 0)
		{
			if (Player->Inventory->HasItem(VisibilityRequirements[i].HasItem) < VisibilityRequirements[i].HasItemCount)
				return false;
		}

		if (VisibilityRequirements[i].WearsItem.Len() > 0)
		{
			if (!Player->WearsItem(VisibilityRequirements[i].WearsItem))
				return false;
		}

		if (VisibilityRequirements[i].HasMoney > Player->Money + Player->Bank)
			return false;
	}
	return true;

}

bool FWQuest::IsCompleteable(class AWPlayer* Player)
{
	if (!Player->IsQuestAccepted(*this))
		return false;

	for (int i = 0; i < FinishRequirements.Num(); i++)
	{

		if (FinishRequirements[i].LevelsReached > Player->Level)
			return false;

		if (FinishRequirements[i].QuestFinished.Len() > 0)
		{
			bool bQuestFinished = false;
			for (int j = 0; j < Player->FinishedQuestlines.Num(); j++)
			{
				if (FinishRequirements[i].QuestFinished.Compare(Player->FinishedQuests[j]) == 0)
					bQuestFinished = true;

			}
			if (!bQuestFinished)
				return false;
		}

		if (FinishRequirements[i].HasItem.Len() > 0)
		{
			if (Player->Inventory->HasItem(FinishRequirements[i].HasItem) < FinishRequirements[i].HasItemCount)
				return false;
		}

		if (FinishRequirements[i].WearsItem.Len() > 0)
		{
			if (!Player->WearsItem(FinishRequirements[i].WearsItem))
				return false;
		}

		if (FinishRequirements[i].NeedsItem.Len() > 0)
		{
			if (Player->Inventory->HasItem(FinishRequirements[i].NeedsItem) < FinishRequirements[i].NeedsItemCount)
				return false;
		}

		if (FinishRequirements[i].WorkedJob.Len() > 0)
		{
			if (FinishRequirements[i].AmountsWorkedNeeded > 0 && FinishRequirements[i].AmountsWorkedNeeded > FinishRequirements[i].AmountsWorked)
				return false;
			if (FinishRequirements[i].TimeWorkedNeeded > 0 && FinishRequirements[i].TimeWorkedNeeded > FinishRequirements[i].TimeWorked)
				return false;
		}

		if (FinishRequirements[i].HasMoney > Player->Money + Player->Bank)
			return false;
	}
	return true;
}

void FWQuest::CompleteQuest(AWPlayer* Player)
{
	if (!IsCompleteable(Player))
		return;
	
	for (int i = 0; i < FinishRequirements.Num(); i++)
	{
		if (FinishRequirements[i].NeedsItem.Len() > 0)
		{
			Player->Inventory->RemoveItem(FinishRequirements[i].NeedsItem, FinishRequirements[i].NeedsItemCount);
		}
		if (FinishRequirements[i].HasMoney > 0)
			Player->GainMoney(-FinishRequirements[i].HasMoney);
	}
	
	for (int i = 0; i < FinishRewards.Num(); i++)
	{
		if (FinishRewards[i].ItemIdentifier.Len() > 0)
		{
			FWInventoryItemBase Item = Player->GetTheGameInstance()->GameData->FindItemByIdentifier(FinishRewards[i].ItemIdentifier);
			Player->Inventory->AddItem(&Item, FinishRewards[i].ItemCount);
		}
		Player->GainMoney(FinishRewards[i].Money);
		Player->GainXP(FinishRewards[i].XP);
		Player->GainAttributePoints(FinishRewards[i].AttributePoints);
		Player->GainSkillPoints(FinishRewards[i].SkillPoints);

		if (FinishRewards[i].PointsOnSpecified > 0)
		{
			if (IsSkillPoint(FinishRewards[i].Skill))
				Player->GainSpecifiedSkillPoints(FinishRewards[i].PointsOnSpecified, FinishRewards[i].Skill);
			else if (IsAttributePoint(FinishRewards[i].Skill))
				Player->GainSpecifiedAttributePoints(FinishRewards[i].PointsOnSpecified, FinishRewards[i].Skill);
		}
	}

	
}
