// Fill out your copyright notice in the Description page of Project Settings.


#include "WQuestline.h"
#include "WPlayer.h"

FWQuestline::FWQuestline()
{
}

FWQuestline::~FWQuestline()
{
}

bool FWQuestline::IsVisible(AWPlayer* Player)
{
	for (int i = 0; i < Player->FinishedQuestlines.Num(); i++)
	{
		if (!Repeatable && Player->FinishedQuestlines[i].Compare(Name) == 0)
			return false;
	}


	for (int i = 0; i < Requirements.Num(); i++)
	{

		if (Requirements[i].LevelsReached > Player->Level)
			return false;

		if (Requirements[i].QuestFinished.Len() > 0)
		{
			bool bQuestLineFinished = false;
			for (int j = 0; j < Player->FinishedQuestlines.Num(); j++)
			{
				if (Requirements[i].QuestFinished.Compare(Player->FinishedQuestlines[j]) == 0)
					bQuestLineFinished = true;

			}
			if (!bQuestLineFinished)
				return false;
		}

		if (Requirements[i].HasItem.Len() > 0)
		{
			if (Player->Inventory->HasItem(Requirements[i].HasItem) < Requirements[i].HasItemCount)
				return false;
		}

		if (Requirements[i].WearsItem.Len() > 0)
		{
			if (!Player->WearsItem(Requirements[i].WearsItem))
				return false;
		}

		if (Requirements[i].HasMoney > Player->Money + Player->Bank)
			return false;
	}
	return true;
}
