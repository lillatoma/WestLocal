// Fill out your copyright notice in the Description page of Project Settings.


#include "UWGameUI.h"
#include "WPlayer.h"
#include "GI_WestGameInstance.h"
#include "WGameData.h"

void UUWGameUI::SpendSkillPoint(WSkillNames Skill)
{

    //TOOO:Removethecheat
    Player->UnspentSkillPoints++;
    Player->SpendSkillPoint(Skill);
 
}

void UUWGameUI::SpendAttributePoint(WSkillNames Skill)
{
    //TOOO:Removethecheat
    Player->UnspentAttributePoints++;
    Player->SpendAttributePoint(Skill);
}

FString UUWGameUI::UpdateSkillText(WSkillNames Skill)
{
    int Number = Player->GetTotalOf(Skill);

    return FString::FromInt(Number);
}

FString UUWGameUI::UpdateUnspentSkillText()
{
    int Number = Player->UnspentSkillPoints;
    
    return FString("Unspent Skills: ") + FString::FromInt(Number);
}

FString UUWGameUI::UpdateUnspentAttributesText()
{
    int Number = Player->UnspentAttributePoints;

    return FString("Unspent Attributes: ") + FString::FromInt(Number);
}

UGI_WestGameInstance* UUWGameUI::FindGameInstance()
{
    if (Instance)
        return Instance;

    Instance = Cast<UGI_WestGameInstance>(GetGameInstance());

    return Instance;
}

void UUWGameUI::PreviousJobPlace()
{
    auto GI = FindGameInstance();
    int LatestID = GI->GameData->JobPlaces.Num() - 1;
    JobPlaceIndex--;
    if (JobPlaceIndex < 0)
        JobPlaceIndex = LatestID;
    JobIndex = -1;
}

void UUWGameUI::NextJobPlace()
{
    auto GI = FindGameInstance();
    int LatestID = GI->GameData->JobPlaces.Num() - 1;
    JobPlaceIndex++;
    if (JobPlaceIndex > LatestID)
        JobPlaceIndex = 0;
    JobIndex = -1;
}

int UUWGameUI::GetCurrentJobPlaceJobCount()
{
    auto GI = FindGameInstance();
    return GI->GameData->JobPlaces[JobPlaceIndex].Jobs.Num();
}

void UUWGameUI::SetJob(int index)
{
    int JC = GetCurrentJobPlaceJobCount();
    if(index >= 0 && index < JC)
        JobIndex = index;
}

bool UUWGameUI::ShouldShowJobPanelOnRight()
{
    return JobIndex > -1;
}

FWJobPlace UUWGameUI::GetCurrentJobPlace()
{
    auto GI = FindGameInstance();
    return GI->GameData->JobPlaces[JobPlaceIndex];

}

FString UUWGameUI::GetCurrentJobPlaceName()
{
    auto GI = FindGameInstance();
    return GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].JobName;
}

FString UUWGameUI::GetJobNameForID(int ID)
{
    auto GI = FindGameInstance();
    return GI->GameData->JobPlaces[JobPlaceIndex].Jobs[ID].JobName;
}

FWJob UUWGameUI::GetCurrentJob()
{
    auto GI = FindGameInstance();
    return GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex];
}

bool UUWGameUI::IsJobWorkable()
{
    auto GI = FindGameInstance();
    int Level = Player->Level;
    int LaborPoints = GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateLaborPoints(Player->GetTotalSkills());
    return GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].IsJobWorkable(Level, LaborPoints);
}

int UUWGameUI::GetCurrentJobProductCount()
{
    auto GI = FindGameInstance();
    int Level = Player->Level;
    return GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].Rewards.Num();
}

FString UUWGameUI::GetSmallCash()
{
    auto GI = FindGameInstance();
    FWSkillSet Total = Player->GetTotalSkills();
    int LaborPoints = GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateLaborPoints(Total);
    return FString("$") + FString::FromInt(GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateCash(LaborPoints, Total.MoneyPercentage, EWorkLength::Short));
}

FString UUWGameUI::GetSmallXP()
{
    auto GI = FindGameInstance();
    FWSkillSet Total = Player->GetTotalSkills();
    int LaborPoints = GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateLaborPoints(Total);
    return FString::FromInt(GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateXP(LaborPoints, Total.XPPercentage, EWorkLength::Short));
}

FString UUWGameUI::GetSmallLuck()
{
    auto GI = FindGameInstance();
    FWSkillSet Total = Player->GetTotalSkills();
    int LaborPoints = GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateLaborPoints(Total);
    return FString("$") + FString::FromInt(GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateLuck(LaborPoints, Total.Luck, EWorkLength::Short));
}

FString UUWGameUI::GetSmallProductName(int id)
{
    auto GI = FindGameInstance();
    FWInventoryItemBase Item = GI->GameData->FindItemByIdentifier(GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].Rewards[id].IdentifierName);
    return Item.ItemName;

}

FString UUWGameUI::GetSmallProductPercent(int id)
{
    auto GI = FindGameInstance();
    FWSkillSet Total = Player->GetTotalSkills();
    int LaborPoints = GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateLaborPoints(Total);
    return FString::SanitizeFloat(100.f * GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateFindingChance(id, LaborPoints, Total.FindingChance, EWorkLength::Short)) + FString("%");
}

FString UUWGameUI::GetMidCash()
{
    auto GI = FindGameInstance();
    FWSkillSet Total = Player->GetTotalSkills();
    int LaborPoints = GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateLaborPoints(Total);
    return FString("$") + FString::FromInt(GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateCash(LaborPoints, Total.MoneyPercentage, EWorkLength::Medium));
}

FString UUWGameUI::GetMidXP()
{
    auto GI = FindGameInstance();
    FWSkillSet Total = Player->GetTotalSkills();
    int LaborPoints = GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateLaborPoints(Total);
    return FString::FromInt(GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateXP(LaborPoints, Total.XPPercentage, EWorkLength::Medium));
}

FString UUWGameUI::GetMidLuck()
{
    auto GI = FindGameInstance();
    FWSkillSet Total = Player->GetTotalSkills();
    int LaborPoints = GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateLaborPoints(Total);
    return FString("$") + FString::FromInt(GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateLuck(LaborPoints, Total.Luck, EWorkLength::Medium));
}

FString UUWGameUI::GetMidProductName(int id)
{
    auto GI = FindGameInstance();
    FWInventoryItemBase Item = GI->GameData->FindItemByIdentifier(GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].Rewards[id].IdentifierName);
    return Item.ItemName;
}

FString UUWGameUI::GetMidProductPercent(int id)
{
    auto GI = FindGameInstance();
    FWSkillSet Total = Player->GetTotalSkills();
    int LaborPoints = GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateLaborPoints(Total);
    return FString::SanitizeFloat(100.f * GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateFindingChance(id, LaborPoints, Total.FindingChance, EWorkLength::Medium)) + FString("%");
}

FString UUWGameUI::GetLongCash() 
{
    auto GI = FindGameInstance();
    FWSkillSet Total = Player->GetTotalSkills();
    int LaborPoints = GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateLaborPoints(Total);
    return FString("$") + FString::FromInt(GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateCash(LaborPoints, Total.MoneyPercentage, EWorkLength::Long));
}

FString UUWGameUI::GetLongXP() 
{
    auto GI = FindGameInstance();
    FWSkillSet Total = Player->GetTotalSkills();
    int LaborPoints = GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateLaborPoints(Total);
    return FString::FromInt(GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateXP(LaborPoints, Total.XPPercentage, EWorkLength::Long));
}

FString UUWGameUI::GetLongLuck() 
{
    auto GI = FindGameInstance();
    FWSkillSet Total = Player->GetTotalSkills();
    int LaborPoints = GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateLaborPoints(Total);
    return FString("$") + FString::FromInt(GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateLuck(LaborPoints, Total.Luck, EWorkLength::Long));
}

FString UUWGameUI::GetLongProductName(int id) 
{
    auto GI = FindGameInstance();
    FWInventoryItemBase Item = GI->GameData->FindItemByIdentifier(GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].Rewards[id].IdentifierName);
    return Item.ItemName;
}

FString UUWGameUI::GetLongProductPercent(int id) 
{
    auto GI = FindGameInstance();
    FWSkillSet Total = Player->GetTotalSkills();
    int LaborPoints = GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateLaborPoints(Total);
    return FString::SanitizeFloat(100.f * GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateFindingChance(id, LaborPoints, Total.FindingChance, EWorkLength::Long)) + FString("%");
}

bool UUWGameUI::IsCurrentJobValid()
{
    if (JobIndex < 0)
        return false;

    auto GI = FindGameInstance();
    if (JobIndex >= GI->GameData->JobPlaces[JobPlaceIndex].Jobs.Num())
        return false;
    return true;
}

void UUWGameUI::TryWorkJob(EWorkLength Length)
{
    auto Inst = FindGameInstance();

    FWJob Job = Inst->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex];

    if (Length == EWorkLength::Short)
        Player->WorkJob(Job, Length);
    else if (Length == EWorkLength::Medium && Player->Level >= 10)
        Player->WorkJob(Job, Length);
    else if (Length == EWorkLength::Long && Player->Level >= 20)
        Player->WorkJob(Job, Length);
}

FString UUWGameUI::GetEquippedItemName(EInvSlot ISlot)
{
    FWInventoryItemBase* Slotted = Player->GetItemInSlot(ISlot);

    if (!Slotted)
    {
        switch (ISlot)
        {
        case EInvSlot::Hat:
            return FString("Hat");
            break;
        case EInvSlot::Neck:
            return FString("Neck");
            break;
        case EInvSlot::Body:
            return FString("Clothes");
            break;
        case EInvSlot::LeftHand:
            return FString("Left Hand");
            break;
        case EInvSlot::RightHand:
            return FString("RightHand");
            break;
        case EInvSlot::Belt:
            return FString("Belt");
            break;
        case EInvSlot::Pants:
            return FString("Pants");
            break;
        case EInvSlot::Shoes:
            return FString("Shoes");
            break;
        case EInvSlot::Horse:
            return FString("Animal");
            break;
        case EInvSlot::Product:
            return FString("Product");
            break;
        default:
            return FString("Item");
            break;
        }
    }
    else return Slotted->ItemName;
}

bool UUWGameUI::IsItemEquippedInSlot(EInvSlot ISlot)
{
    FWInventoryItemBase* Slotted = Player->GetItemInSlot(ISlot);

    return Slotted != nullptr;
}

void UUWGameUI::TryUnequipItem(EInvSlot ISlot)
{
    switch (ISlot)
    {
    case EInvSlot::Hat:
        Player->TakeOffHat();
        break;
    case EInvSlot::Neck:
        Player->TakeOffNeck();
        break;
    case EInvSlot::Body:
        Player->TakeOffBody();
        break;
    case EInvSlot::LeftHand:
        Player->TakeOffLeftHand();
        break;
    case EInvSlot::RightHand:
        Player->TakeOffRightHand();
        break;
    case EInvSlot::Belt:
        Player->TakeOffBelt();
        break;
    case EInvSlot::Pants:
        Player->TakeOffPants();
        break;
    case EInvSlot::Shoes:
        Player->TakeOffShoes();
        break;
    case EInvSlot::Horse:
        Player->TakeOffHorse();
        break;
    case EInvSlot::Product:
        Player->TakeOffProduct();
        break;
    }
}

void UUWGameUI::MakePageValid()
{
    while (1)
    {
        if (InvFirstItemIndex == 0 || IsItemAtIndex(0))
            break;
        PreviousInventoryPage();
    }
}

bool UUWGameUI::IsItemAtIndex(int SubIdx)
{
    int Idx = InvFirstItemIndex + SubIdx;

    return Idx < Player->Inventory->Items.Num();
}

FString UUWGameUI::GetItemNameAtIndex(int SubIdx)
{
    int Idx = InvFirstItemIndex + SubIdx;
    if(IsItemAtIndex(SubIdx))
        return Player->Inventory->Items[Idx]->ItemName;
    return FString("undefined");
}

FString UUWGameUI::GetItemCountAtIndex(int SubIdx)
{
    int Idx = InvFirstItemIndex + SubIdx;
    if (IsItemAtIndex(SubIdx))
        return FString::FromInt(Player->Inventory->Items[Idx]->Count);
    return FString("0");
}

void UUWGameUI::TryEquipItem(int SubIdx)
{
    int Idx = InvFirstItemIndex + SubIdx;
    if (IsItemAtIndex(SubIdx))
        Player->TakeOn(Idx);
}

void UUWGameUI::NextInventoryPage()
{
    if (IsItemAtIndex(15))
        InvFirstItemIndex += 15;
}

void UUWGameUI::PreviousInventoryPage()
{
    InvFirstItemIndex -= 15;
    if (InvFirstItemIndex < 0)
        InvFirstItemIndex = 0;
}


void UUWGameUI::SetPlayer(AWPlayer* P)
{
    Player = P;
}
