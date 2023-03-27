// Fill out your copyright notice in the Description page of Project Settings.


#include "WGameData.h"

FWInventoryItemBase UWGameData::FindItemByIdentifier(FString Identifier)
{
    for (int i = 0; i < Hats.Num(); i++)
    {
        if (Hats[i].Is(Identifier))
            return Hats[i];
    }
    for (int i = 0; i < Necks.Num(); i++)
    {
        if (Necks[i].Is(Identifier))
            return Necks[i];
    }
    for (int i = 0; i < Clothes.Num(); i++)
    {
        if (Clothes[i].Is(Identifier))
            return Clothes[i];
    }
    for (int i = 0; i < Shoes.Num(); i++)
    {
        if (Shoes[i].Is(Identifier))
            return Shoes[i];
    }
    for (int i = 0; i < Trousers.Num(); i++)
    {
        if (Trousers[i].Is(Identifier))
            return Trousers[i];
    }
    for (int i = 0; i < Belts.Num(); i++)
    {
        if (Belts[i].Is(Identifier))
            return Belts[i];
    }
    for (int i = 0; i < LeftHand.Num(); i++)
    {
        if (LeftHand[i].Is(Identifier))
            return LeftHand[i];
    }
    for (int i = 0; i < RightHand.Num(); i++)
    {
        if (RightHand[i].Is(Identifier))
            return RightHand[i];
    }
    for (int i = 0; i < Animals.Num(); i++)
    {
        if (Animals[i].Is(Identifier))
            return Animals[i];
    }
    for (int i = 0; i < Products.Num(); i++)
    {
        if (Products[i].Is(Identifier))
            return Products[i];
    }

    return FWInventoryItemBase();

}

FWInventoryItemBase UWGameData::FindItemInPriceRange(int Min, int Max)
{
    TArray<FWInventoryItemBase> FoundItems;

    for (int i = 0; i < Hats.Num(); i++)
    {
        if (Hats[i].Price >= Min && Hats[i].Price <= Max)
            FoundItems.Add(Hats[i]);
    }
    for (int i = 0; i < Necks.Num(); i++)
    {
        if (Necks[i].Price >= Min && Necks[i].Price <= Max)
            FoundItems.Add(Necks[i]);
    }
    for (int i = 0; i < Clothes.Num(); i++)
    {
        if (Clothes[i].Price >= Min && Clothes[i].Price <= Max)
            FoundItems.Add(Clothes[i]);
    }
    for (int i = 0; i < Shoes.Num(); i++)
    {
        if (Shoes[i].Price >= Min && Shoes[i].Price <= Max)
            FoundItems.Add(Shoes[i]);
    }
    for (int i = 0; i < Trousers.Num(); i++)
    {
        if (Trousers[i].Price >= Min && Trousers[i].Price <= Max)
            FoundItems.Add(Trousers[i]);
    }
    for (int i = 0; i < Belts.Num(); i++)
    {
        if (Belts[i].Price >= Min && Belts[i].Price <= Max)
            FoundItems.Add(Belts[i]);
    }
    for (int i = 0; i < LeftHand.Num(); i++)
    {
        if (LeftHand[i].Price >= Min && LeftHand[i].Price <= Max)
            FoundItems.Add(LeftHand[i]);
    }
    for (int i = 0; i < RightHand.Num(); i++)
    {
        if (RightHand[i].Price >= Min && RightHand[i].Price <= Max)
            FoundItems.Add(RightHand[i]);
    }
    for (int i = 0; i < Animals.Num(); i++)
    {
        if (Animals[i].Price >= Min && Animals[i].Price <= Max)
            FoundItems.Add(Animals[i]);
    }
    for (int i = 0; i < Products.Num(); i++)
    {
        if (Products[i].Price >= Min && Products[i].Price <= Max)
            FoundItems.Add(Products[i]);
    }

    if (FoundItems.Num() > 0)
    {
        int ID = FMath::RandRange(0, FoundItems.Num() - 1);

        return FoundItems[ID];
    }
    else return FindItemInPriceRange(0.9 * Min, 1.1 * Max);
}

FWSet UWGameData::FindSet(FString Set)
{
    for (int i = 0; i < ItemSets.Num(); i++)
        if (ItemSets[i].SetName.Compare(Set) == 0)
            return ItemSets[i];
    
    return FWSet();

}

FWQuestline UWGameData::FindQuestline(FString Name)
{
    for (int i = 0; i < Questlines.Num(); i++)
        if (Questlines[i].Name.Compare(Name) == 0)
            return Questlines[i];

    return FWQuestline();
}

FWQuest UWGameData::FindQuest(FString Name)
{
    for (int i = 0; i < Questlines.Num(); i++)
    {
        for (int j = 0; j < Questlines[i].Quests.Num(); i++)
            if (Questlines[i].Quests[j].QuestName.Compare(Name) == 0)
                return Questlines[i].Quests[j];
    }
    return FWQuest();
}
