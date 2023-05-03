// Fill out your copyright notice in the Description page of Project Settings.


#include "WGameData.h"

FWJob UWGameData::FindJob(FString JobName)
{
    for(int i = 0; i < JobPlaces.Num(); i++)
        for (int j = 0; j < JobPlaces[i].Jobs.Num(); j++)
        {
            if (JobPlaces[i].Jobs[j].Is(JobName))
                return JobPlaces[i].Jobs[j];
        }


    return FWJob();
}

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

FWInventoryItemBase UWGameData::FindItemWithMaxLevel(int Max)
{
    TArray<FWInventoryItemBase> FoundItems;

    for (int i = 0; i < Hats.Num(); i++)
    {
        if (Hats[i].MinLevel <= Max)
            FoundItems.Add(Hats[i]);
    }
    for (int i = 0; i < Necks.Num(); i++)
    {
        if (Necks[i].MinLevel <= Max)
            FoundItems.Add(Necks[i]);
    }
    for (int i = 0; i < Clothes.Num(); i++)
    {
        if (Clothes[i].MinLevel <= Max)
            FoundItems.Add(Clothes[i]);
    }
    for (int i = 0; i < Shoes.Num(); i++)
    {
        if (Shoes[i].MinLevel <= Max)
            FoundItems.Add(Shoes[i]);
    }
    for (int i = 0; i < Trousers.Num(); i++)
    {
        if (Trousers[i].MinLevel <= Max)
            FoundItems.Add(Trousers[i]);
    }
    for (int i = 0; i < Belts.Num(); i++)
    {
        if (Belts[i].MinLevel <= Max)
            FoundItems.Add(Belts[i]);
    }
    for (int i = 0; i < LeftHand.Num(); i++)
    {
        if (LeftHand[i].MinLevel <= Max)
            FoundItems.Add(LeftHand[i]);
    }
    for (int i = 0; i < RightHand.Num(); i++)
    {
        if (RightHand[i].MinLevel <= Max)
            FoundItems.Add(RightHand[i]);
    }
    for (int i = 0; i < Animals.Num(); i++)
    {
        if (Animals[i].MinLevel <= Max)
            FoundItems.Add(Animals[i]);
    }
    for (int i = 0; i < Products.Num(); i++)
    {
        if (Products[i].MinLevel <= Max)
            FoundItems.Add(Products[i]);
    }

    if (FoundItems.Num() > 0)
    {
        int ID = FMath::RandRange(0, FoundItems.Num() - 1);

        return FoundItems[ID];
    }
    else return FindItemWithMaxLevel(Max + 5);
}

FWInventoryItemBase UWGameData::FindItemWithMaxLevelForSlot(int Max, EInvSlot Slot)
{
    TArray<FWInventoryItemBase> FoundItems;

    switch (Slot)
    {
    case EInvSlot::Hat:
        for (int i = 0; i < Hats.Num(); i++)
        {
            if (Hats[i].MinLevel <= Max)
                FoundItems.Add(Hats[i]);
        }
        break;
    case EInvSlot::Neck:
        for (int i = 0; i < Necks.Num(); i++)
        {
            if (Necks[i].MinLevel <= Max)
                FoundItems.Add(Necks[i]);
        }
        break;
    case EInvSlot::Body:
        for (int i = 0; i < Clothes.Num(); i++)
        {
            if (Clothes[i].MinLevel <= Max)
                FoundItems.Add(Clothes[i]);
        }
        break;
    case EInvSlot::Shoes:
        for (int i = 0; i < Shoes.Num(); i++)
        {
            if (Shoes[i].MinLevel <= Max)
                FoundItems.Add(Shoes[i]);
        }
        break;
    case EInvSlot::Pants:
        for (int i = 0; i < Trousers.Num(); i++)
        {
            if (Trousers[i].MinLevel <= Max)
                FoundItems.Add(Trousers[i]);
        }
        break;
    case EInvSlot::Belt:
        for (int i = 0; i < Belts.Num(); i++)
        {
            if (Belts[i].MinLevel <= Max)
                FoundItems.Add(Belts[i]);
        }
        break;
    case EInvSlot::LeftHand:
        for (int i = 0; i < LeftHand.Num(); i++)
        {
            if (LeftHand[i].MinLevel <= Max)
                FoundItems.Add(LeftHand[i]);
        }
        break;
    case EInvSlot::RightHand:
        for (int i = 0; i < RightHand.Num(); i++)
        {
            if (RightHand[i].MinLevel <= Max)
                FoundItems.Add(RightHand[i]);
        }
        break;
    case EInvSlot::Horse:
        for (int i = 0; i < Animals.Num(); i++)
        {
            if (Animals[i].MinLevel <= Max)
                FoundItems.Add(Animals[i]);
        }
        break;
    case EInvSlot::Product:
        for (int i = 0; i < Products.Num(); i++)
        {
            if (Products[i].MinLevel <= Max)
                FoundItems.Add(Products[i]);
        }
        break;
    }
    if (FoundItems.Num() > 0)
    {
        int ID = -1;

        do {
            ID = FMath::RandRange(0, FoundItems.Num() - 1);
            
        } while (ID == -1 || FoundItems[ID].Price <= 0);
       
        return FoundItems[ID];
    }
    else return FindItemWithMaxLevelForSlot(Max + 5,Slot);
}

bool UWGameData::IsThereSetItemForSlot(FWSet Set, EInvSlot Slot)
{
    TArray<FWInventoryItemBase> FoundItems;

    switch (Slot)
    {
    case EInvSlot::Hat:
        for (int i = 0; i < Hats.Num(); i++)
            if (Hats[i].IsPartOfSet(Set.SetName))
                FoundItems.Add(Hats[i]);
        break;
    case EInvSlot::Neck:
        for (int i = 0; i < Necks.Num(); i++)
            if (Necks[i].IsPartOfSet(Set.SetName))
                FoundItems.Add(Necks[i]);
        break;
    case EInvSlot::Body:
        for (int i = 0; i < Clothes.Num(); i++)
            if (Clothes[i].IsPartOfSet(Set.SetName))
                FoundItems.Add(Clothes[i]);
        break;
    case EInvSlot::LeftHand:
        for (int i = 0; i < LeftHand.Num(); i++)
            if (LeftHand[i].IsPartOfSet(Set.SetName))
                FoundItems.Add(LeftHand[i]);
        break;
    case EInvSlot::RightHand:
        for (int i = 0; i < RightHand.Num(); i++)
            if (RightHand[i].IsPartOfSet(Set.SetName))
                FoundItems.Add(RightHand[i]);
        break;
    case EInvSlot::Belt:
        for (int i = 0; i < Belts.Num(); i++)
            if (Belts[i].IsPartOfSet(Set.SetName))
                FoundItems.Add(Belts[i]);
        break;
    case EInvSlot::Pants:
        for (int i = 0; i < Trousers.Num(); i++)
            if (Trousers[i].IsPartOfSet(Set.SetName))
                FoundItems.Add(Trousers[i]);
        break;
    case EInvSlot::Shoes:
        for (int i = 0; i < Shoes.Num(); i++)
            if (Shoes[i].IsPartOfSet(Set.SetName))
                FoundItems.Add(Shoes[i]);
        break;
    case EInvSlot::Product:
        for (int i = 0; i < Products.Num(); i++)
            if (Products[i].IsPartOfSet(Set.SetName))
                FoundItems.Add(Products[i]);
        break;
    case EInvSlot::Horse:
        for (int i = 0; i < Animals.Num(); i++)
            if (Animals[i].IsPartOfSet(Set.SetName))
                FoundItems.Add(Animals[i]);
        break;
    }
    return FoundItems.Num() > 0;
}

FWInventoryItemBase UWGameData::FindSetItemForSlot(FWSet Set,EInvSlot Slot)
{
    TArray<FWInventoryItemBase> FoundItems;

    switch (Slot)
    {
    case EInvSlot::Hat:
        for (int i = 0; i < Hats.Num(); i++)
            if (Hats[i].IsPartOfSet(Set.SetName))
                FoundItems.Add(Hats[i]);
        break;
    case EInvSlot::Neck:
        for (int i = 0; i < Necks.Num(); i++)
            if (Necks[i].IsPartOfSet(Set.SetName))
                FoundItems.Add(Necks[i]);
        break;
    case EInvSlot::Body:
        for (int i = 0; i < Clothes.Num(); i++)
            if (Clothes[i].IsPartOfSet(Set.SetName))
                FoundItems.Add(Clothes[i]);
        break;
    case EInvSlot::LeftHand:
        for (int i = 0; i < LeftHand.Num(); i++)
            if (LeftHand[i].IsPartOfSet(Set.SetName))
                FoundItems.Add(LeftHand[i]);
        break;
    case EInvSlot::RightHand:
        for (int i = 0; i < RightHand.Num(); i++)
            if (RightHand[i].IsPartOfSet(Set.SetName))
                FoundItems.Add(RightHand[i]);
        break;
    case EInvSlot::Belt:
        for (int i = 0; i < Belts.Num(); i++)
            if (Belts[i].IsPartOfSet(Set.SetName))
                FoundItems.Add(Belts[i]);
        break;
    case EInvSlot::Pants:
        for (int i = 0; i < Trousers.Num(); i++)
            if (Trousers[i].IsPartOfSet(Set.SetName))
                FoundItems.Add(Trousers[i]);
        break;
    case EInvSlot::Shoes:
        for (int i = 0; i < Shoes.Num(); i++)
            if (Shoes[i].IsPartOfSet(Set.SetName))
                FoundItems.Add(Shoes[i]);
        break;
    case EInvSlot::Product:
        for (int i = 0; i < Products.Num(); i++)
            if (Products[i].IsPartOfSet(Set.SetName))
                FoundItems.Add(Products[i]);
        break;
    case EInvSlot::Horse:
        for (int i = 0; i < Animals.Num(); i++)
            if (Animals[i].IsPartOfSet(Set.SetName))
                FoundItems.Add(Animals[i]);
        break;
    }

    if (FoundItems.Num() > 0)
    {
        int ID = -1;

        ID = FMath::RandRange(0, FoundItems.Num() - 1);

        if (ID == -1 || FoundItems[ID].Price <= 0)
            return FindItemWithMaxLevelForSlot(25, Slot);

        return FoundItems[ID];
    }
    return FWInventoryItemBase();
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

FWQuestline UWGameData::FindQuestlineFromQuest(FWQuest Quest)
{
    for (int i = 0; i < Questlines.Num(); i++)
    {
        for (int j = 0; j < Questlines[i].Quests.Num(); j++)
        {
            if (Questlines[i].Quests[j].QuestName.Compare(Quest.QuestName) == 0)
                return Questlines[i];
        }
    }

    return FWQuestline();

}

FWQuest UWGameData::FindQuest(FString Name)
{
    for (int i = 0; i < Questlines.Num(); i++)
    {
        for (int j = 0; j < Questlines[i].Quests.Num(); j++)
            if (Questlines[i].Quests[j].QuestName.Compare(Name) == 0)
                return Questlines[i].Quests[j];
    }
    return FWQuest();
}

void UWGameData::SetUpSetIndexes()
{
    for (int i = 0; i < ItemSets.Num(); i++)
        ItemSets[i].SetIndex = i;

    for (int i = 0; i < Hats.Num(); i++)
    {
        if (Hats[i].IsPartOfSet())
            Hats[i].SetIndex = FindSet(Hats[i].SetName).SetIndex;
    }
    for (int i = 0; i < Necks.Num(); i++)
    {
        if (Necks[i].IsPartOfSet())
            Necks[i].SetIndex = FindSet(Necks[i].SetName).SetIndex;
    }
    for (int i = 0; i < Clothes.Num(); i++)
    {
        if (Clothes[i].IsPartOfSet())
            Clothes[i].SetIndex = FindSet(Clothes[i].SetName).SetIndex;
    }
    for (int i = 0; i < LeftHand.Num(); i++)
    {
        if (LeftHand[i].IsPartOfSet())
            LeftHand[i].SetIndex = FindSet(LeftHand[i].SetName).SetIndex;
    }
    for (int i = 0; i < RightHand.Num(); i++)
    {
        if (RightHand[i].IsPartOfSet())
            RightHand[i].SetIndex = FindSet(RightHand[i].SetName).SetIndex;
    }
    for (int i = 0; i < Belts.Num(); i++)
    {
        if (Belts[i].IsPartOfSet())
            Belts[i].SetIndex = FindSet(Belts[i].SetName).SetIndex;
    }
    for (int i = 0; i < Trousers.Num(); i++)
    {
        if (Trousers[i].IsPartOfSet())
            Trousers[i].SetIndex = FindSet(Trousers[i].SetName).SetIndex;
    }
    for (int i = 0; i < Shoes.Num(); i++)
    {
        if (Shoes[i].IsPartOfSet())
            Shoes[i].SetIndex = FindSet(Shoes[i].SetName).SetIndex;
    }
    for (int i = 0; i < Animals.Num(); i++)
    {
        if (Animals[i].IsPartOfSet())
            Animals[i].SetIndex = FindSet(Animals[i].SetName).SetIndex;
    }
    for (int i = 0; i < Products.Num(); i++)
    {
        if (Products[i].IsPartOfSet())
            Products[i].SetIndex = FindSet(Products[i].SetName).SetIndex;
    }

}

void UWGameData::CheckQuestsForMatchingNames()
{
    //TODO: this

    for (int i = 0; i < Questlines.Num(); i++)
    {
        for (int j = 0; j < Questlines[i].Quests.Num(); j++)
        {
            for (int i2 = 0; i2 < Questlines.Num(); i2++)
            {
                for (int j2 = 0; j2 < Questlines[i2].Quests.Num(); j2++)
                {
                    if (i == i2 && j == j2)
                        continue;

                    if (Questlines[i].Quests[j].QuestName.Compare(Questlines[i2].Quests[j2].QuestName) == 0)
                    {
                        GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Red, FString::Printf(TEXT("Duplicate questnames: %s in %d|%d and %d|%d"), *Questlines[i2].Quests[j2].QuestName, i, j, i2, j2));

                    }
                }
            }
        }
    }
}

void UWGameData::CheckQuestsForErrors()
{
    for(int i = 0; i < Questlines.Num(); i++)
        for (int j = 0; j < Questlines[i].Quests.Num(); j++)
        {
            //Prereq check
            for (int k = 0; k < Questlines[i].Quests[j].VisibilityRequirements.Num(); k++)
            {
                if (Questlines[i].Quests[j].VisibilityRequirements[k].HasItemCount > 0)
                {
                    auto Item = FindItemByIdentifier(Questlines[i].Quests[j].VisibilityRequirements[k].HasItem);
                    if (!Item.Is(Questlines[i].Quests[j].VisibilityRequirements[k].HasItem))
                        GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Red, FString::Printf(TEXT("No such item to have: %s in %d|%d"), *Questlines[i].Quests[j].VisibilityRequirements[k].HasItem, i, j));
                }

                if (Questlines[i].Quests[j].VisibilityRequirements[k].WearsItem.Len() > 0)
                {
                    auto Item = FindItemByIdentifier(Questlines[i].Quests[j].VisibilityRequirements[k].WearsItem);
                    if (!Item.Is(Questlines[i].Quests[j].VisibilityRequirements[k].WearsItem))
                        GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Red, FString::Printf(TEXT("No such item to wear: %s in %d|%d"), *Questlines[i].Quests[j].VisibilityRequirements[k].WearsItem, i, j));
                }

                if (Questlines[i].Quests[j].VisibilityRequirements[k].QuestFinished.Len() > 0)
                {
                    auto Quest = FindQuest(Questlines[i].Quests[j].VisibilityRequirements[k].QuestFinished);

                    if (!Quest.Is(Questlines[i].Quests[j].VisibilityRequirements[k].QuestFinished))
                        GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Red, FString::Printf(TEXT("No such quest to finish: %s in %d|%d"), *Questlines[i].Quests[j].VisibilityRequirements[k].QuestFinished, i, j));
                }
            }

            //Finish req check
            for (int k = 0; k < Questlines[i].Quests[j].FinishRequirements.Num(); k++)
            {
                if (Questlines[i].Quests[j].FinishRequirements[k].HasItemCount > 0)
                {
                    auto Item = FindItemByIdentifier(Questlines[i].Quests[j].FinishRequirements[k].HasItem);
                    if (!Item.Is(Questlines[i].Quests[j].FinishRequirements[k].HasItem))
                        GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Red, FString::Printf(TEXT("No such item to have: %s in %d|%d"), *Questlines[i].Quests[j].FinishRequirements[k].HasItem, i, j));
                }

                if (Questlines[i].Quests[j].FinishRequirements[k].WearsItem.Len() > 0)
                {
                    auto Item = FindItemByIdentifier(Questlines[i].Quests[j].FinishRequirements[k].WearsItem);
                    if (!Item.Is(Questlines[i].Quests[j].FinishRequirements[k].WearsItem))
                        GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Red, FString::Printf(TEXT("No such item to wear: %s in %d|%d"), *Questlines[i].Quests[j].FinishRequirements[k].WearsItem, i, j));
                }

                if (Questlines[i].Quests[j].FinishRequirements[k].QuestFinished.Len() > 0)
                {
                    auto Quest = FindQuest(Questlines[i].Quests[j].FinishRequirements[k].QuestFinished);

                    if (!Quest.Is(Questlines[i].Quests[j].FinishRequirements[k].QuestFinished))
                        GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Red, FString::Printf(TEXT("No such quest to finish: %s in %d|%d"), *Questlines[i].Quests[j].FinishRequirements[k].QuestFinished, i, j));
                }

                if (Questlines[i].Quests[j].FinishRequirements[k].WorkedJob.Len() > 0)
                {
                    auto Job = FindJob(Questlines[i].Quests[j].FinishRequirements[k].WorkedJob);


                    if (!Job.Is(Questlines[i].Quests[j].FinishRequirements[k].WorkedJob))
                        GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Red, FString::Printf(TEXT("No such job to work: %s in %d|%d"), *Questlines[i].Quests[j].FinishRequirements[k].WorkedJob, i, j));
                }

            }

            //Finish rewards check
            for (int k = 0; k < Questlines[i].Quests[j].FinishRewards.Num(); k++)
            {
                if (Questlines[i].Quests[j].FinishRewards[k].ItemIdentifier.Len() > 0)
                {
                    if(Questlines[i].Quests[j].FinishRewards[k].ItemCount <= 0)
                        GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Red, FString::Printf(TEXT("Null item reward in %d|%d"), i, j));

                    auto Item = FindItemByIdentifier(Questlines[i].Quests[j].FinishRewards[k].ItemIdentifier);
                    if (!Item.Is(Questlines[i].Quests[j].FinishRewards[k].ItemIdentifier))
                        GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Red, FString::Printf(TEXT("No such item to reward: %s in %d|%d"), *Questlines[i].Quests[j].FinishRewards[k].ItemIdentifier, i, j));
                }
            }



        }

}

//bool UWGameData::IsFirstSetEarlier(FString SetNameA, FString SetNameB)
//{
//    for (int i = 0; i < ItemSets.Num(); i++)
//    {
//        if (ItemSets[i].SetName.Compare(SetNameA) == 0)
//            return true;
//        else if (ItemSets[i].SetName.Compare(SetNameB) == 0)
//            return false;
//    }
//    return false;
//}
