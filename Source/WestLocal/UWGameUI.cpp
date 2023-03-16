// Fill out your copyright notice in the Description page of Project Settings.


#include "UWGameUI.h"
#include "WPlayer.h"
#include "GI_WestGameInstance.h"
#include "WGameData.h"

void UUWGameUI::SpendSkillPoint(WSkillNames Skill)
{
    Player->SpendSkillPoint(Skill);
 
}

void UUWGameUI::SpendAttributePoint(WSkillNames Skill)
{
    Player->SpendAttributePoint(Skill);
}

FString UUWGameUI::UpdateSkillText(WSkillNames Skill)
{
    int Number = Player->GetTotalOf(Skill);

    return FString::FromInt(Number);
}

FString UUWGameUI::UpdateUnspentSkillText(WSkillNames Skill)
{
    int Number = Player->UnspentSkillPoints;
    
    return FString("Unspent Skills: ") + FString::FromInt(Number);
}

FString UUWGameUI::UpdateUnspentAttributesText(WSkillNames Skill)
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

bool UUWGameUI::ShouldShowJobPanelOnRight()
{
    return JobIndex > -1;
}

FWJobPlace UUWGameUI::GetCurrentJobPlace()
{
    auto GI = FindGameInstance();
    return GI->GameData->JobPlaces[JobPlaceIndex];

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

FString UUWGameUI::GetSmallCash()
{
    auto GI = FindGameInstance();
    WSkillSet Total = Player->GetTotalSkills();
    int LaborPoints = GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateLaborPoints(Total);
    return FString("$") + FString::FromInt(GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateCash(LaborPoints, Total.MoneyPercentage, EWorkLength::Short));
}

FString UUWGameUI::GetSmallXP()
{
    auto GI = FindGameInstance();
    WSkillSet Total = Player->GetTotalSkills();
    int LaborPoints = GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateLaborPoints(Total);
    return FString::FromInt(GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateXP(LaborPoints, Total.XPPercentage, EWorkLength::Short));
}

FString UUWGameUI::GetSmallLuck()
{
    auto GI = FindGameInstance();
    WSkillSet Total = Player->GetTotalSkills();
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
    WSkillSet Total = Player->GetTotalSkills();
    int LaborPoints = GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateLaborPoints(Total);
    return FString::FromInt(GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateFindingChance(id, LaborPoints, Total.FindingChance, EWorkLength::Short));
}

FString UUWGameUI::GetMidCash()
{
    auto GI = FindGameInstance();
    WSkillSet Total = Player->GetTotalSkills();
    int LaborPoints = GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateLaborPoints(Total);
    return FString("$") + FString::FromInt(GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateCash(LaborPoints, Total.MoneyPercentage, EWorkLength::Medium));
}

FString UUWGameUI::GetMidXP()
{
    auto GI = FindGameInstance();
    WSkillSet Total = Player->GetTotalSkills();
    int LaborPoints = GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateLaborPoints(Total);
    return FString::FromInt(GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateXP(LaborPoints, Total.XPPercentage, EWorkLength::Medium));
}

FString UUWGameUI::GetMidLuck()
{
    auto GI = FindGameInstance();
    WSkillSet Total = Player->GetTotalSkills();
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
    WSkillSet Total = Player->GetTotalSkills();
    int LaborPoints = GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateLaborPoints(Total);
    return FString::FromInt(GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateFindingChance(id, LaborPoints, Total.FindingChance, EWorkLength::Medium));
}

FString UUWGameUI::GetLongCash() 
{
    auto GI = FindGameInstance();
    WSkillSet Total = Player->GetTotalSkills();
    int LaborPoints = GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateLaborPoints(Total);
    return FString("$") + FString::FromInt(GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateCash(LaborPoints, Total.MoneyPercentage, EWorkLength::Long));
}

FString UUWGameUI::GetLongXP() 
{
    auto GI = FindGameInstance();
    WSkillSet Total = Player->GetTotalSkills();
    int LaborPoints = GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateLaborPoints(Total);
    return FString::FromInt(GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateXP(LaborPoints, Total.XPPercentage, EWorkLength::Long));
}

FString UUWGameUI::GetLongLuck() 
{
    auto GI = FindGameInstance();
    WSkillSet Total = Player->GetTotalSkills();
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
    WSkillSet Total = Player->GetTotalSkills();
    int LaborPoints = GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateLaborPoints(Total);
    return FString::FromInt(GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateFindingChance(id, LaborPoints, Total.FindingChance, EWorkLength::Long));
}

void UUWGameUI::SetPlayer(AWPlayer* P)
{
    Player = P;
}
