// Fill out your copyright notice in the Description page of Project Settings.


#include "UWGameUI.h"
#include "WSkillSet.h"
#include "WPlayer.h"
#include "GI_WestGameInstance.h"
#include "WGameData.h"

void UUWGameUI::SpendSkillPoint(WSkillNames Skill)
{


    //Player->UnspentSkillPoints++;
    Player->SpendSkillPoint(Skill);
 
}

void UUWGameUI::SpendAttributePoint(WSkillNames Skill)
{

    //Player->UnspentAttributePoints++;
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

bool UUWGameUI::IsJobNeededForQuests(int ID)
{
    auto GI = FindGameInstance();
    FWJob Job = GI->GameData->JobPlaces[JobPlaceIndex].Jobs[ID];

    for (int i = 0; i < Player->AcceptedQuests.Num(); i++)
    {
        for (int j = 0; j < Player->AcceptedQuests[i].FinishRequirements.Num(); j++)
        {
            if (Job.JobName.Compare(Player->AcceptedQuests[i].FinishRequirements[j].WorkedJob) == 0)
            {
                if (Player->AcceptedQuests[i].FinishRequirements[j].AmountsWorkedNeeded > Player->AcceptedQuests[i].FinishRequirements[j].AmountsWorked
                    || Player->AcceptedQuests[i].FinishRequirements[j].TimeWorkedNeeded > Player->AcceptedQuests[i].FinishRequirements[j].TimeWorked)
                    return true;
            }

            for (int k = 0; k < Job.Rewards.Num(); k++)
            {
                if (Job.Rewards[k].IdentifierName.Compare(Player->AcceptedQuests[i].FinishRequirements[j].NeedsItem) == 0
                    && Player->AcceptedQuests[i].FinishRequirements[j].NeedsItemCount > Player->Inventory->HasItem(Player->AcceptedQuests[i].FinishRequirements[j].NeedsItem))
                    return true;

                if (Job.Rewards[k].IdentifierName.Compare(Player->AcceptedQuests[i].FinishRequirements[j].HasItem) == 0
                    && Player->AcceptedQuests[i].FinishRequirements[j].HasItemCount > Player->Inventory->HasItem(Player->AcceptedQuests[i].FinishRequirements[j].HasItem))
                    return true;
            }

        }
    }

    return false;
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

void UUWGameUI::GetBestPossibleEquipment()
{
    auto GI = FindGameInstance();
    FWSkillSet Total = Player->GetTotalSkills();
    FWJob Job = GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex];
    Player->FindBestInventoryForJob(Job);
}


void UUWGameUI::GetBestPossibleEquipmentSetted()
{
    auto GI = FindGameInstance();
    FWSkillSet Total = Player->GetTotalSkills();
    FWJob Job = GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex];
    Player->FindBestInventoryForJobSetted(Job);
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
    return Item.GetItemName();

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
    return Item.GetItemName();
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
    return Item.GetItemName();
}

FString UUWGameUI::GetLongProductPercent(int id) 
{
    auto GI = FindGameInstance();
    FWSkillSet Total = Player->GetTotalSkills();
    int LaborPoints = GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateLaborPoints(Total);
    return FString::SanitizeFloat(100.f * GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JobIndex].CalculateFindingChance(id, LaborPoints, Total.FindingChance, EWorkLength::Long)) + FString("%");
}

bool UUWGameUI::IsMidJobWorkable()
{
    return Player->Level >= 10;
}

bool UUWGameUI::IsLongJobWorkable()
{
    return Player->Level >= 20;
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
    else return Slotted->GetItemName();
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
        return Player->Inventory->Items[Idx]->GetItemName();
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
    if (ItemClickMode == 0)
    {
        int Idx = InvFirstItemIndex + SubIdx;
        if (IsItemAtIndex(SubIdx))
            Player->TakeOn(Idx);
    }
    else if (ItemClickMode == 1)
        TrySellItem(SubIdx);
    else TryUpgradeItem(SubIdx);
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

void UUWGameUI::InventorySortBySlot(EInvSlot ISlot)
{
    Player->SortInventoryForSlot(ISlot);
}

void UUWGameUI::InventorySortByUpgradable()
{
    Player->SortInventoryForUpgradable();
}

void UUWGameUI::InventorySortByPrice()
{
    Player->SortInventoryForPrice();
}

void UUWGameUI::InventorySortBySets()
{
    Player->SortInventoryForSets();
}

void UUWGameUI::TrySellItem(int SubIdx)
{
    int Idx = InvFirstItemIndex + SubIdx;
    if (IsItemAtIndex(SubIdx))
        Player->TrySellItem(Idx);
}

void UUWGameUI::TryUpgradeItem(int SubIdx)
{
    int Idx = InvFirstItemIndex + SubIdx;
    if (IsItemAtIndex(SubIdx))
        Player->TryUpgradeItem(Idx);
}

bool UUWGameUI::IsItemEquipingMode()
{
    return ItemClickMode == 0;
}

bool UUWGameUI::IsItemSellingMode()
{
    return ItemClickMode == 1;
}

bool UUWGameUI::IsItemUpgradingMode()
{
    return ItemClickMode == 2;
}

void UUWGameUI::SetItemMode(int Mode)
{
    ItemClickMode = Mode;
}

bool UUWGameUI::ShouldShowItemDescription(int SubIdx)
{
    return IsItemAtIndex(SubIdx);
}

bool UUWGameUI::ShouldShowItemDescriptionSlot(EInvSlot ISlot)
{
    return IsItemEquippedInSlot(ISlot);
}

FString UUWGameUI::GetItemDescriptionName(int SubIdx)
{
    int Idx = InvFirstItemIndex + SubIdx;
    if (IsItemAtIndex(SubIdx))
        return Player->Inventory->Items[Idx]->GetItemName();
    return FString("undefined");
}

FString UUWGameUI::GetItemDescriptionNameSlot(EInvSlot ISlot)
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
    else return Slotted->GetItemName();
}

FString UUWGameUI::GetItemDescriptionBuffs(int SubIdx)
{
    int Idx = InvFirstItemIndex + SubIdx;
    if (IsItemAtIndex(SubIdx))
    {
        FString BuffText;

        FWSkillSet Skills = Player->Inventory->Items[Idx]->CalculateSkills(Player->Level);

        if (Skills.DamageMin > 0 && Skills.DamageMax > 0)
            BuffText += FString::FromInt(Skills.DamageMin) + "-" + FString::FromInt(Skills.DamageMax) + " Damage\n";
        if (Skills.FortDamageMin > 0 && Skills.FortDamageMax > 0)
            BuffText += FString::FromInt(Skills.FortDamageMin) + "-" + FString::FromInt(Skills.FortDamageMax) + " Damage in fort battles\n";

        if (Skills.Strength > 0)
            BuffText += FString("+") + FString::FromInt(Skills.Strength) + " Strength\n";
        if (Skills.Mobility > 0)
            BuffText += FString("+") + FString::FromInt(Skills.Mobility) + " Mobility\n";
        if (Skills.Dexterity > 0)
            BuffText += FString("+") + FString::FromInt(Skills.Dexterity) + " Dexterity\n";
        if (Skills.Charisma > 0)
            BuffText += FString("+") + FString::FromInt(Skills.Charisma) + " Charisma\n";

        if (Skills.Construction > 0)
            BuffText += FString("+") + FString::FromInt(Skills.Construction) + " Construction\n";
        if (Skills.Vigor > 0)
            BuffText += FString("+") + FString::FromInt(Skills.Vigor) + " Vigor\n";
        if (Skills.Toughness > 0)
            BuffText += FString("+") + FString::FromInt(Skills.Toughness) + " Toughness\n";
        if (Skills.Stamina > 0)
            BuffText += FString("+") + FString::FromInt(Skills.Stamina) + " Stamina\n";
        if (Skills.HealthPoints > 0)
            BuffText += FString("+") + FString::FromInt(Skills.HealthPoints) + " Health Points\n";

        if (Skills.Riding > 0)
            BuffText += FString("+") + FString::FromInt(Skills.Riding) + " Riding\n";
        if (Skills.Reflex > 0)
            BuffText += FString("+") + FString::FromInt(Skills.Reflex) + " Reflex\n";
        if (Skills.Dodging > 0)
            BuffText += FString("+") + FString::FromInt(Skills.Dodging) + " Dodging\n";
        if (Skills.Hiding > 0)
            BuffText += FString("+") + FString::FromInt(Skills.Hiding) + " Hiding\n";
        if (Skills.Swimming > 0)
            BuffText += FString("+") + FString::FromInt(Skills.Swimming) + " Swimming\n";

        if (Skills.Aiming > 0)
            BuffText += FString("+") + FString::FromInt(Skills.Aiming) + " Aiming\n";
        if (Skills.Shooting > 0)
            BuffText += FString("+") + FString::FromInt(Skills.Shooting) + " Shooting\n";
        if (Skills.Trapping > 0)
            BuffText += FString("+") + FString::FromInt(Skills.Trapping) + " Trapping\n";
        if (Skills.FineMotorSkills > 0)
            BuffText += FString("+") + FString::FromInt(Skills.FineMotorSkills) + " Fine Motor Skills\n";
        if (Skills.Repairing > 0)
            BuffText += FString("+") + FString::FromInt(Skills.Repairing) + " Repairing\n";

        if (Skills.Leadership > 0)
            BuffText += FString("+") + FString::FromInt(Skills.Leadership) + " Leadership\n";
        if (Skills.Tactic > 0)
            BuffText += FString("+") + FString::FromInt(Skills.Tactic) + " Tactic\n";
        if (Skills.Trading > 0)
            BuffText += FString("+") + FString::FromInt(Skills.Trading) + " Trading\n";
        if (Skills.AnimalInstinct > 0)
            BuffText += FString("+") + FString::FromInt(Skills.AnimalInstinct) + " Animal Instinct\n";
        if (Skills.Appearance > 0)
            BuffText += FString("+") + FString::FromInt(Skills.Appearance) + " Appearance\n";


        if (Skills.FindingChance > 1)
            BuffText += FString("+") + FString::SanitizeFloat(Skills.FindingChance * 100 - 100) + "% Finding chance\n";
        if (Skills.Luck > 1)
            BuffText += FString("+") + FString::SanitizeFloat(Skills.Luck * 100 - 100) + "% Luck\n";
        if (Skills.XPPercentage> 1)
            BuffText += FString("+") + FString::SanitizeFloat(Skills.XPPercentage * 100 - 100) + "% XP bonus\n";
        if (Skills.MoneyPercentage > 1)
            BuffText += FString("+") + FString::SanitizeFloat(Skills.MoneyPercentage * 100 - 100) + "% Cash bonus\n";
        if (Skills.Speed > 1)
            BuffText += FString("+") + FString::SanitizeFloat(Skills.Speed * 100 - 100) + "% Speed\n";
        if (Skills.ExtraWorkPoints > 0)
            BuffText += FString("+") + FString::FromInt(Skills.ExtraWorkPoints) + " Labor points\n";

        return BuffText;
    }

    else return FString("undefined");
}

FString UUWGameUI::GetItemDescriptionBuffsSlot(EInvSlot ISlot)
{
    if (Player->GetItemInSlot(ISlot))
    {
        FString BuffText;

        FWSkillSet Skills = Player->GetItemInSlot(ISlot)->CalculateSkills(Player->Level);

        if (Skills.DamageMin > 0 && Skills.DamageMax > 0)
            BuffText += FString::FromInt(Skills.DamageMin) + "-" + FString::FromInt(Skills.DamageMax) + " Damage\n";
        if (Skills.FortDamageMin > 0 && Skills.FortDamageMax > 0)
            BuffText += FString::FromInt(Skills.FortDamageMin) + "-" + FString::FromInt(Skills.FortDamageMax) + " Damage in fort battles\n";

        if (Skills.Strength > 0)
            BuffText += FString("+") + FString::FromInt(Skills.Strength) + " Strength\n";
        if (Skills.Mobility > 0)
            BuffText += FString("+") + FString::FromInt(Skills.Mobility) + " Mobility\n";
        if (Skills.Dexterity > 0)
            BuffText += FString("+") + FString::FromInt(Skills.Dexterity) + " Dexterity\n";
        if (Skills.Charisma > 0)
            BuffText += FString("+") + FString::FromInt(Skills.Charisma) + " Charisma\n";

        if (Skills.Construction > 0)
            BuffText += FString("+") + FString::FromInt(Skills.Construction) + " Construction\n";
        if (Skills.Vigor > 0)
            BuffText += FString("+") + FString::FromInt(Skills.Vigor) + " Vigor\n";
        if (Skills.Toughness > 0)
            BuffText += FString("+") + FString::FromInt(Skills.Toughness) + " Toughness\n";
        if (Skills.Stamina > 0)
            BuffText += FString("+") + FString::FromInt(Skills.Stamina) + " Stamina\n";
        if (Skills.HealthPoints > 0)
            BuffText += FString("+") + FString::FromInt(Skills.HealthPoints) + " Health Points\n";

        if (Skills.Riding > 0)
            BuffText += FString("+") + FString::FromInt(Skills.Riding) + " Riding\n";
        if (Skills.Reflex > 0)
            BuffText += FString("+") + FString::FromInt(Skills.Reflex) + " Reflex\n";
        if (Skills.Dodging > 0)
            BuffText += FString("+") + FString::FromInt(Skills.Dodging) + " Dodging\n";
        if (Skills.Hiding > 0)
            BuffText += FString("+") + FString::FromInt(Skills.Hiding) + " Hiding\n";
        if (Skills.Swimming > 0)
            BuffText += FString("+") + FString::FromInt(Skills.Swimming) + " Swimming\n";

        if (Skills.Aiming > 0)
            BuffText += FString("+") + FString::FromInt(Skills.Aiming) + " Aiming\n";
        if (Skills.Shooting > 0)
            BuffText += FString("+") + FString::FromInt(Skills.Shooting) + " Shooting\n";
        if (Skills.Trapping > 0)
            BuffText += FString("+") + FString::FromInt(Skills.Trapping) + " Trapping\n";
        if (Skills.FineMotorSkills > 0)
            BuffText += FString("+") + FString::FromInt(Skills.FineMotorSkills) + " Fine Motor Skills\n";
        if (Skills.Repairing > 0)
            BuffText += FString("+") + FString::FromInt(Skills.Repairing) + " Repairing\n";

        if (Skills.Leadership > 0)
            BuffText += FString("+") + FString::FromInt(Skills.Leadership) + " Leadership\n";
        if (Skills.Tactic > 0)
            BuffText += FString("+") + FString::FromInt(Skills.Tactic) + " Tactic\n";
        if (Skills.Trading > 0)
            BuffText += FString("+") + FString::FromInt(Skills.Trading) + " Trading\n";
        if (Skills.AnimalInstinct > 0)
            BuffText += FString("+") + FString::FromInt(Skills.AnimalInstinct) + " Animal Instinct\n";
        if (Skills.Appearance > 0)
            BuffText += FString("+") + FString::FromInt(Skills.Appearance) + " Appearance\n";


        if (Skills.FindingChance > 1)
            BuffText += FString("+") + FString::SanitizeFloat(Skills.FindingChance * 100 - 100) + "% Finding chance\n";
        if (Skills.Luck > 1)
            BuffText += FString("+") + FString::SanitizeFloat(Skills.Luck * 100 - 100) + "% Luck\n";
        if (Skills.XPPercentage > 1)
            BuffText += FString("+") + FString::SanitizeFloat(Skills.XPPercentage * 100 - 100) + "% XP bonus\n";
        if (Skills.MoneyPercentage > 1)
            BuffText += FString("+") + FString::SanitizeFloat(Skills.MoneyPercentage * 100 - 100) + "% Cash bonus\n";
        if (Skills.Speed > 1)
            BuffText += FString("+") + FString::SanitizeFloat(Skills.Speed * 100 - 100) + "% Speed\n";
        if (Skills.ExtraWorkPoints > 0)
            BuffText += FString("+") + FString::FromInt(Skills.ExtraWorkPoints) + " Labor points\n";

        return BuffText;
    }

    else return FString("undefined");
}

FString UUWGameUI::GetItemDescriptionLevelReq(int SubIdx)
{
    int Idx = InvFirstItemIndex + SubIdx;
    if (IsItemAtIndex(SubIdx))
        return FString("Level Needed: ") + FString::FromInt(Player->Inventory->Items[Idx]->MinLevel);
    return FString("undefined");
}

FString UUWGameUI::GetItemDescriptionLevelReqSlot(EInvSlot ISlot)
{
    FWInventoryItemBase* Slotted = Player->GetItemInSlot(ISlot);
    if (Slotted)
        return FString("Level Needed: ") + FString::FromInt(Slotted->MinLevel);
    return FString("undefined");
}

FString UUWGameUI::GetItemDescriptionPrice(int SubIdx)
{
    int Idx = InvFirstItemIndex + SubIdx;
    if (IsItemAtIndex(SubIdx))
        return FString("Price: $") + FString::FromInt(Player->Inventory->Items[Idx]->Price);
    return FString("undefined");
}

FString UUWGameUI::GetItemDescriptionPriceSlot(EInvSlot ISlot)
{
    FWInventoryItemBase* Slotted = Player->GetItemInSlot(ISlot);
    if (Slotted)
        return FString("Price: $") + FString::FromInt(Slotted->Price);
    return FString("undefined");
}

bool UUWGameUI::ShouldShowJobDescription(int JPIndex)
{
    return JPIndex >= 0 && JPIndex < GetCurrentJobPlaceJobCount();
}

FString UUWGameUI::GetJobDescriptionName(int JPIndex)
{
    auto GI = FindGameInstance();

    if(IsJobDescriptionWorkable(JPIndex))
        return GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JPIndex].JobName;
    else
        return GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JPIndex].JobName + " (Not workable)";
}

bool UUWGameUI::IsJobDescriptionWorkable(int JPIndex)
{
    auto GI = FindGameInstance();
    int Level = Player->Level;
    int LaborPoints = GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JPIndex].CalculateLaborPoints(Player->GetTotalSkills());
    return GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JPIndex].IsJobWorkable(Level, LaborPoints);
}

FString UUWGameUI::GetJobDescriptionSkillName(WSkillNames SkillName)
{
    switch (SkillName)
    {
    case WSkillNames::Strength:
        return FString("Strength");
        break;
    case WSkillNames::Mobility:
        return FString("Mobility");
        break;
    case WSkillNames::Dexterity:
        return FString("Dexterity");
        break;
    case WSkillNames::Charisma:
        return FString("Charisma");
        break;
    case WSkillNames::Construction:
        return FString("Construction");
        break;
    case WSkillNames::Vigor:
        return FString("Vigor");
        break;
    case WSkillNames::Toughness:
        return FString("Toughness");
        break;
    case WSkillNames::Stamina:
        return FString("Stamina");
        break;
    case WSkillNames::HealthPoints:
        return FString("Health Points");
        break;
    case WSkillNames::Riding:
        return FString("Riding");
        break;
    case WSkillNames::Reflex:
        return FString("Reflex");
        break;
    case WSkillNames::Dodging:
        return FString("Dodging");
        break;
    case WSkillNames::Hiding:
        return FString("Hiding");
        break;
    case WSkillNames::Swimming:
        return FString("Swimming");
        break;
    case WSkillNames::Aiming:
        return FString("Aiming");
        break;
    case WSkillNames::Shooting:
        return FString("Shooting");
        break;
    case WSkillNames::Trapping:
        return FString("Trapping");
        break;
    case WSkillNames::FineMotorSkills:
        return FString("Fine Motor Skills");
        break;
    case WSkillNames::Repairing:
        return FString("Repairing");
        break;
    case WSkillNames::Leadership:
        return FString("Leadership");
        break;
    case WSkillNames::Tactic:
        return FString("Tactic");
        break;
    case WSkillNames::Trading:
        return FString("Trading");
        break;
    case WSkillNames::AnimalInstinct:
        return FString("Animal Instinct");
        break;
    case WSkillNames::Appearance:
        return FString("Appearance");
        break;

    default:
        return FString("Unknown");
    }


    return FString();
}

int UUWGameUI::GetJobDescriptionSkillValue(WSkillNames SkillName, FWSkillSet Skills)
{
    switch (SkillName)
    {
    case WSkillNames::Construction:
        return Skills.Construction;
        break;
    case WSkillNames::Vigor:
        return Skills.Vigor;
        break;
    case WSkillNames::Toughness:
        return Skills.Toughness;
        break;
    case WSkillNames::Stamina:
        return Skills.Stamina;
        break;
    case WSkillNames::HealthPoints:
        return Skills.HealthPoints;
        break;
    case WSkillNames::Riding:
        return Skills.Riding;
        break;
    case WSkillNames::Reflex:
        return Skills.Reflex;
        break;
    case WSkillNames::Dodging:
        return Skills.Dodging;
        break;
    case WSkillNames::Hiding:
        return Skills.Hiding;
        break;
    case WSkillNames::Swimming:
        return Skills.Swimming;
        break;
    case WSkillNames::Aiming:
        return Skills.Aiming;
        break;
    case WSkillNames::Shooting:
        return Skills.Shooting;
        break;
    case WSkillNames::Trapping:
        return Skills.Trapping;
        break;
    case WSkillNames::FineMotorSkills:
        return Skills.FineMotorSkills;
        break;
    case WSkillNames::Repairing:
        return Skills.Repairing;
        break;
    case WSkillNames::Leadership:
        return Skills.Leadership;
        break;
    case WSkillNames::Tactic:
        return Skills.Tactic;
        break;
    case WSkillNames::Trading:
        return Skills.Trading;
        break;
    case WSkillNames::AnimalInstinct:
        return Skills.AnimalInstinct;
        break;
    case WSkillNames::Appearance:
        return Skills.Appearance;
        break;
    default:
        return 0;
        break;
    }

    return 0;
}

FString UUWGameUI::GetJobDescriptionLaborPoints(int JPIndex)
{
    FString String;
    FWSkillSet Skills = Player->GetTotalSkills();   
    auto GI = FindGameInstance();
    FWJob Job = GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JPIndex];

    int Value1 = GetJobDescriptionSkillValue(Job.NeededAttribute1, Skills);
    int Value2 = GetJobDescriptionSkillValue(Job.NeededAttribute2, Skills);
    int Value3 = GetJobDescriptionSkillValue(Job.NeededAttribute3, Skills);
    int Value4 = GetJobDescriptionSkillValue(Job.NeededAttribute4, Skills);
    int Value5 = GetJobDescriptionSkillValue(Job.NeededAttribute5, Skills);


    String += GetJobDescriptionSkillName(Job.NeededAttribute1) + ": " + FString::FromInt(Value1) + "\n";
    String += GetJobDescriptionSkillName(Job.NeededAttribute2) + ": " + FString::FromInt(Value2) + "\n";
    String += GetJobDescriptionSkillName(Job.NeededAttribute3) + ": " + FString::FromInt(Value3) + "\n";
    String += GetJobDescriptionSkillName(Job.NeededAttribute4) + ": " + FString::FromInt(Value4) + "\n";
    String += GetJobDescriptionSkillName(Job.NeededAttribute5) + ": " + FString::FromInt(Value5) + "\n";
    int LaborPoints = GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JPIndex].CalculateLaborPoints(Player->GetTotalSkills());
    String += "Laborpoints: " + FString::FromInt(LaborPoints) + "\n";
    String += "Required: " + FString::FromInt(GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JPIndex].MinDifficulty) + "\n";
    String += "Gold: " + FString::FromInt(GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JPIndex].MinDifficulty * 3 + 10) + "\n";




    return String;
}

int UUWGameUI::GetJobIndex()
{
    return JobIndex;
}

FString UUWGameUI::GetJobDescriptionLevelReq(int JPIndex)
{
    auto GI = FindGameInstance();
    FWJob Job = GI->GameData->JobPlaces[JobPlaceIndex].Jobs[JPIndex];

    return FString("Level Needed: ") + FString::FromInt(Job.MinLevel);


}

TArray<FWQuest> UUWGameUI::GetAllPossibleQuests()
{
    return Player->GetAllQuests();
}

void UUWGameUI::OnQuestsPageOpen()
{
    QuestFirstIndex = 0;
    CurrentQuestIndex = -1;
}

void UUWGameUI::PreviousQuestPage(TArray<FWQuest> Quests)
{
    if (QuestFirstIndex - 9 >= 0)
        QuestFirstIndex -= 9;
    else if (QuestFirstIndex >= 0)
        QuestFirstIndex = 0;
}

void UUWGameUI::NextQuestPage(TArray<FWQuest> Quests)
{
    if (QuestFirstIndex + 9 < Quests.Num() - 1)
        QuestFirstIndex += 9;
}

bool UUWGameUI::IsQuestVisibleAtIndex(TArray<FWQuest> Quests, int SubIdx)
{
    if (QuestFirstIndex + SubIdx >= 0 && QuestFirstIndex + SubIdx < Quests.Num())
        return true;
    return false;
}

FString UUWGameUI::GetQuestNameAtIndex(TArray<FWQuest> Quests, int SubIdx)
{
    if (IsQuestVisibleAtIndex(Quests, SubIdx))
    {
        auto GI = FindGameInstance();
        FWQuestline QuestLine = GI->GameData->FindQuestlineFromQuest(Quests[QuestFirstIndex + SubIdx]);

        return Quests[QuestFirstIndex + SubIdx].QuestName + " (" + QuestLine.Name + ")";
    }
    return FString("undefined");
}

void UUWGameUI::SelectQuestAtIndex(TArray<FWQuest> Quests, int SubIdx)
{
    CurrentQuestIndex = QuestFirstIndex + SubIdx;
}

bool UUWGameUI::ShouldShowQuestPanelOnRight(TArray<FWQuest> Quests)
{
    return CurrentQuestIndex >= 0;
}

FString UUWGameUI::GetCurrentQuestName(TArray<FWQuest> Quests)
{
    if (CurrentQuestIndex >= 0 && CurrentQuestIndex < Quests.Num())
    {
        auto GI = FindGameInstance();
        FWQuestline QuestLine = GI->GameData->FindQuestlineFromQuest(Quests[CurrentQuestIndex]);
        return Quests[CurrentQuestIndex].QuestName + " (" + QuestLine.Name + ")";
    }
    return FString("undefined");
}

FString UUWGameUI::GetCurrentQuestFinishRequirements(TArray<FWQuest> Quests)
{
    if (CurrentQuestIndex >= 0 && CurrentQuestIndex < Quests.Num())
    {
        FString String = "Requirements:\n";

        if (Quests[CurrentQuestIndex].FinishRequirements.Num() == 0)
            String += "-";
        else
        {
            for (int i = 0; i < Quests[CurrentQuestIndex].FinishRequirements.Num(); i++)
            {
                FWQuestRequirement Current = Quests[CurrentQuestIndex].FinishRequirements[i];

                if (Current.QuestFinished.Len() > 0)
                {
                    
                    //GI->GameData->FindQuest(Current.QuestFinished)
                    int FinishedVal = 0;
                    if (Player->IsQuestFinished(Current.QuestFinished))
                        FinishedVal = 1;

                    String += Current.QuestFinished + " finished: " + FString::FromInt(FinishedVal) + "/1\n";
                }
                if (Current.HasItem.Len() > 0)
                {
                    auto GI = FindGameInstance();
                    FString IName = GI->GameData->FindItemByIdentifier(Current.HasItem).GetItemName();
            
                    int Count = Player->Inventory->HasItem(Current.HasItem);

                    String += IName + ": " + FString::FromInt(Count) + "/" + FString::FromInt(Current.HasItemCount) + "\n";
                }
                if (Current.NeedsItem.Len() > 0) 
                {
                    auto GI = FindGameInstance();
                    FString IName = GI->GameData->FindItemByIdentifier(Current.NeedsItem).GetItemName();

                    int Count = Player->Inventory->HasItem(Current.NeedsItem);

                    String += IName + ": " + FString::FromInt(Count) + "/" + FString::FromInt(Current.NeedsItemCount) + "\n";
                }

                if (Current.WearsItem.Len() > 0)
                {
                    auto GI = FindGameInstance();
                    FString IName = GI->GameData->FindItemByIdentifier(Current.WearsItem).GetItemName();
                    int Wears = 0;
                    if (Player->WearsItem(Current.WearsItem))
                        Wears = 1;

                    String += "Wears " + IName + ": " + FString::FromInt(Wears) + "/1\n";
                }

                if (Current.WorkedJob.Len() > 0)
                {
                    auto GI = FindGameInstance();

                    if (Current.AmountsWorkedNeeded > 0)
                    {
                        String += Current.WorkedJob + ": " + FString::FromInt(Current.AmountsWorked) + "/" + FString::FromInt(Current.AmountsWorkedNeeded) + "\n";
                    }
                    if (Current.TimeWorkedNeeded > 0)
                    {
                        int SecondsDone = Current.TimeWorked % 60;
                        int MinutesDone = (Current.TimeWorked % 3600) / 60;
                        int HoursDone = Current.TimeWorked / 3600;
                        int SecondsNeeded = Current.TimeWorkedNeeded % 60;
                        int MinutesNeeded = (Current.TimeWorkedNeeded % 3600) / 60;
                        int HoursNeeded = Current.TimeWorkedNeeded / 3600;

                        FString TimeTextDone, TimeTextNeeded;

                        if (HoursDone > 0) TimeTextDone += FString::FromInt(HoursDone) + " h ";
                        if (MinutesDone > 0) TimeTextDone += FString::FromInt(MinutesDone) + " m ";
                        if (SecondsDone > 0 || (HoursDone == 0 && MinutesDone == 0)) TimeTextDone += FString::FromInt(SecondsDone) + " s ";


                        if (HoursNeeded > 0) TimeTextNeeded += FString::FromInt(HoursNeeded) + " h ";
                        if (MinutesNeeded > 0) TimeTextNeeded += FString::FromInt(MinutesNeeded) + " m ";
                        if (SecondsNeeded > 0) TimeTextNeeded += FString::FromInt(SecondsNeeded) + " s";


                        String += Current.WorkedJob + " (" + TimeTextDone + "/" + TimeTextNeeded + ")\n";
                    }
                }

                if (Current.HasMoney > 0)
                {
                    String += "Money: $" + FString::FromInt(Player->Money + Player->Bank) + "/$" + FString::FromInt(Current.HasMoney) + "\n";
                }

                if (Current.LevelsReached > 0)
                {
                    String += "Level: " + FString::FromInt(Player->Level) + "/" + FString::FromInt(Current.LevelsReached) + "\n";
                }


            }
        }


        return String;
    }


    return FString("Requirements:\nundefined");
}

FString UUWGameUI::GetCurrentQuestFinishRewards(TArray<FWQuest> Quests)
{
    if (CurrentQuestIndex >= 0 && CurrentQuestIndex < Quests.Num())
    {
        FString String = FString("Rewards:\n");
        if (Quests[CurrentQuestIndex].FinishRewards.Num() == 0)
            String += "-";
        else
        {
            for (int i = 0; i < Quests[CurrentQuestIndex].FinishRewards.Num(); i++)
            {
                FWQuestReward Current = Quests[CurrentQuestIndex].FinishRewards[i];

                if (Current.ItemIdentifier.Len() > 0)
                {
                    auto GI = FindGameInstance();
                    FString IName = GI->GameData->FindItemByIdentifier(Current.ItemIdentifier).GetItemName();
                    String += IName + "(" + FString::FromInt(Current.ItemCount) + "x)\n";
                }
                if (Current.Money > 0)
                {
                    String += "$" + FString::FromInt(Current.Money) + "\n";
                }
                if (Current.XP > 0)
                {
                    String += FString::FromInt(Current.XP) + " XP\n";
                }
                if (Current.AttributePoints > 0)
                {
                    String += FString::FromInt(Current.AttributePoints) + " attribute points\n";
                }
                if (Current.SkillPoints > 0)
                {
                    String += FString::FromInt(Current.SkillPoints) + " skill points\n";
                }
                if (Current.PointsOnSpecified > 0)
                {
                    String += FString::FromInt(Current.PointsOnSpecified) + " " + GetJobDescriptionSkillName(Current.Skill) + "\n";
                }
            }
        }
        return String;
    }



    return FString("Rewards:\nundefined");
}

bool UUWGameUI::IsSelectedQuestAcceptable(TArray<FWQuest> Quests)
{
    return !Player->IsQuestAccepted(Quests[CurrentQuestIndex]) && Quests[CurrentQuestIndex].IsVisible(Player);
}

bool UUWGameUI::IsSelectedQuestFinishable(TArray<FWQuest> Quests)
{
    return Quests[CurrentQuestIndex].IsCompleteable(Player);
}

bool UUWGameUI::TryAcceptQuest(TArray<FWQuest> Quests)
{
    if (!IsSelectedQuestAcceptable(Quests))
        return false;

    Player->AddQuestToWatchList(Quests[CurrentQuestIndex]);
    return true;
}

bool UUWGameUI::TryFinishQuest(TArray<FWQuest> Quests)
{
    if (!IsSelectedQuestFinishable(Quests))
        return false;

    Player->FinishQuest(Quests[CurrentQuestIndex].QuestName);

    return true;

}

void UUWGameUI::TryRefreshShopItems()
{
    Player->TryAskForNewShopPage();
}

void UUWGameUI::TryBuyShopItem(EInvSlot ISlot)
{
    Player->TryBuyShopItemInSlot(ISlot);
}

FString UUWGameUI::GetNameOfShopItem(EInvSlot ISlot)
{
    auto GI = FindGameInstance();

    FString String;

    switch (ISlot)
    {
    case EInvSlot::Hat:
        String = GI->ShopItems[0].GetItemName();
        break;
    case EInvSlot::Neck:
        String = GI->ShopItems[1].GetItemName();
        break;
    case EInvSlot::Body:
        String = GI->ShopItems[2].GetItemName();
        break;
    case EInvSlot::LeftHand:
        String = GI->ShopItems[3].GetItemName();
        break;
    case EInvSlot::RightHand:
        String = GI->ShopItems[4].GetItemName();
        break;
    case EInvSlot::Belt:
        String = GI->ShopItems[5].GetItemName();
        break;
    case EInvSlot::Pants:
        String = GI->ShopItems[6].GetItemName();
        break;
    case EInvSlot::Shoes:
        String = GI->ShopItems[7].GetItemName();
        break;
    case EInvSlot::Horse:
        String = GI->ShopItems[8].GetItemName();
        break;
    case EInvSlot::Product:
        String = GI->ShopItems[9].GetItemName();
        break;
    }
    return String;
}

FString UUWGameUI::GetPriceOfShopItem(EInvSlot ISlot)
{
    auto GI = FindGameInstance();

    FString String;

    switch (ISlot)
    {
    case EInvSlot::Hat:
        String = "$" + FString::FromInt(GI->ShopPrices[0]);
        break;
    case EInvSlot::Neck:
        String = "$" + FString::FromInt(GI->ShopPrices[1]);
        break;
    case EInvSlot::Body:
        String = "$" + FString::FromInt(GI->ShopPrices[2]);
        break;
    case EInvSlot::LeftHand:
        String = "$" + FString::FromInt(GI->ShopPrices[3]);
        break;
    case EInvSlot::RightHand:
        String = "$" + FString::FromInt(GI->ShopPrices[4]);
        break;
    case EInvSlot::Belt:
        String = "$" + FString::FromInt(GI->ShopPrices[5]);
        break;
    case EInvSlot::Pants:
        String = "$" + FString::FromInt(GI->ShopPrices[6]);
        break;
    case EInvSlot::Shoes:
        String = "$" + FString::FromInt(GI->ShopPrices[7]);
        break;
    case EInvSlot::Horse:
        String = "$" + FString::FromInt(GI->ShopPrices[8]);
        break;
    case EInvSlot::Product:
        String = "$" + FString::FromInt(GI->ShopPrices[9]);
        break;
    }
    return String;
}

FString UUWGameUI::GetShopItemDescriptionName(EInvSlot ISlot)
{
    return GetNameOfShopItem(ISlot);
}

FString UUWGameUI::GetShopItemDescriptionBuffs(EInvSlot ISlot)
{
    auto GI = FindGameInstance();
    FString BuffText;

    FWSkillSet Skills;
    
    switch (ISlot)
    {
    case EInvSlot::Hat:
        Skills = GI->ShopItems[0].CalculateSkills(Player->Level);
        break;
    case EInvSlot::Neck:
        Skills = GI->ShopItems[1].CalculateSkills(Player->Level);
        break;
    case EInvSlot::Body:
        Skills = GI->ShopItems[2].CalculateSkills(Player->Level);
        break;
    case EInvSlot::LeftHand:
        Skills = GI->ShopItems[3].CalculateSkills(Player->Level);
        break;
    case EInvSlot::RightHand:
        Skills = GI->ShopItems[4].CalculateSkills(Player->Level);
        break;
    case EInvSlot::Belt:
        Skills = GI->ShopItems[5].CalculateSkills(Player->Level);
        break;
    case EInvSlot::Pants:
        Skills = GI->ShopItems[6].CalculateSkills(Player->Level);
        break;
    case EInvSlot::Shoes:
        Skills = GI->ShopItems[7].CalculateSkills(Player->Level);
        break;
    case EInvSlot::Horse:
        Skills = GI->ShopItems[8].CalculateSkills(Player->Level);
        break;
    case EInvSlot::Product:
        Skills = GI->ShopItems[9].CalculateSkills(Player->Level);
        break;
    }

    if (Skills.DamageMin > 0 && Skills.DamageMax > 0)
        BuffText += FString::FromInt(Skills.DamageMin) + "-" + FString::FromInt(Skills.DamageMax) + " Damage\n";
    if (Skills.FortDamageMin > 0 && Skills.FortDamageMax > 0)
        BuffText += FString::FromInt(Skills.FortDamageMin) + "-" + FString::FromInt(Skills.FortDamageMax) + " Damage in fort battles\n";

    if (Skills.Strength > 0)
        BuffText += FString("+") + FString::FromInt(Skills.Strength) + " Strength\n";
    if (Skills.Mobility > 0)
        BuffText += FString("+") + FString::FromInt(Skills.Mobility) + " Mobility\n";
    if (Skills.Dexterity > 0)
        BuffText += FString("+") + FString::FromInt(Skills.Dexterity) + " Dexterity\n";
    if (Skills.Charisma > 0)
        BuffText += FString("+") + FString::FromInt(Skills.Charisma) + " Charisma\n";

    if (Skills.Construction > 0)
        BuffText += FString("+") + FString::FromInt(Skills.Construction) + " Construction\n";
    if (Skills.Vigor > 0)
        BuffText += FString("+") + FString::FromInt(Skills.Vigor) + " Vigor\n";
    if (Skills.Toughness > 0)
        BuffText += FString("+") + FString::FromInt(Skills.Toughness) + " Toughness\n";
    if (Skills.Stamina > 0)
        BuffText += FString("+") + FString::FromInt(Skills.Stamina) + " Stamina\n";
    if (Skills.HealthPoints > 0)
        BuffText += FString("+") + FString::FromInt(Skills.HealthPoints) + " Health Points\n";

    if (Skills.Riding > 0)
        BuffText += FString("+") + FString::FromInt(Skills.Riding) + " Riding\n";
    if (Skills.Reflex > 0)
        BuffText += FString("+") + FString::FromInt(Skills.Reflex) + " Reflex\n";
    if (Skills.Dodging > 0)
        BuffText += FString("+") + FString::FromInt(Skills.Dodging) + " Dodging\n";
    if (Skills.Hiding > 0)
        BuffText += FString("+") + FString::FromInt(Skills.Hiding) + " Hiding\n";
    if (Skills.Swimming > 0)
        BuffText += FString("+") + FString::FromInt(Skills.Swimming) + " Swimming\n";

    if (Skills.Aiming > 0)
        BuffText += FString("+") + FString::FromInt(Skills.Aiming) + " Aiming\n";
    if (Skills.Shooting > 0)
        BuffText += FString("+") + FString::FromInt(Skills.Shooting) + " Shooting\n";
    if (Skills.Trapping > 0)
        BuffText += FString("+") + FString::FromInt(Skills.Trapping) + " Trapping\n";
    if (Skills.FineMotorSkills > 0)
        BuffText += FString("+") + FString::FromInt(Skills.FineMotorSkills) + " Fine Motor Skills\n";
    if (Skills.Repairing > 0)
        BuffText += FString("+") + FString::FromInt(Skills.Repairing) + " Repairing\n";

    if (Skills.Leadership > 0)
        BuffText += FString("+") + FString::FromInt(Skills.Leadership) + " Leadership\n";
    if (Skills.Tactic > 0)
        BuffText += FString("+") + FString::FromInt(Skills.Tactic) + " Tactic\n";
    if (Skills.Trading > 0)
        BuffText += FString("+") + FString::FromInt(Skills.Trading) + " Trading\n";
    if (Skills.AnimalInstinct > 0)
        BuffText += FString("+") + FString::FromInt(Skills.AnimalInstinct) + " Animal Instinct\n";
    if (Skills.Appearance > 0)
        BuffText += FString("+") + FString::FromInt(Skills.Appearance) + " Appearance\n";


    if (Skills.FindingChance > 1)
        BuffText += FString("+") + FString::SanitizeFloat(Skills.FindingChance * 100 - 100) + "% Finding chance\n";
    if (Skills.Luck > 1)
        BuffText += FString("+") + FString::SanitizeFloat(Skills.Luck * 100 - 100) + "% Luck\n";
    if (Skills.XPPercentage > 1)
        BuffText += FString("+") + FString::SanitizeFloat(Skills.XPPercentage * 100 - 100) + "% XP bonus\n";
    if (Skills.MoneyPercentage > 1)
        BuffText += FString("+") + FString::SanitizeFloat(Skills.MoneyPercentage * 100 - 100) + "% Cash bonus\n";
    if (Skills.Speed > 1)
        BuffText += FString("+") + FString::SanitizeFloat(Skills.Speed * 100 - 100) + "% Speed\n";
    if (Skills.ExtraWorkPoints > 0)
        BuffText += FString("+") + FString::FromInt(Skills.ExtraWorkPoints) + " Labor points\n";

    return BuffText;
    return FString("undefined");
}

FString UUWGameUI::GetShopItemDescriptionPrice(EInvSlot ISlot)
{
    auto GI = FindGameInstance();

    int Price = 0;

    switch (ISlot)
    {
    case EInvSlot::Hat:
        Price = GI->ShopItems[0].Price;
        break;
    case EInvSlot::Neck:
        Price = GI->ShopItems[1].Price;
        break;
    case EInvSlot::Body:
        Price = GI->ShopItems[2].Price;
        break;
    case EInvSlot::LeftHand:
        Price = GI->ShopItems[3].Price;
        break;
    case EInvSlot::RightHand:
        Price = GI->ShopItems[4].Price;
        break;
    case EInvSlot::Belt:
        Price = GI->ShopItems[5].Price;
        break;
    case EInvSlot::Pants:
        Price = GI->ShopItems[6].Price;
        break;
    case EInvSlot::Shoes:
        Price = GI->ShopItems[7].Price;
        break;
    case EInvSlot::Horse:
        Price = GI->ShopItems[8].Price;
        break;
    case EInvSlot::Product:
        Price = GI->ShopItems[9].Price;
        break;

    }

    return FString("Price: $") + FString::FromInt(Price);
}

FString UUWGameUI::GetShopItemDescriptionMinLevel(EInvSlot ISlot)
{
    auto GI = FindGameInstance();

    int Level = 0;

    switch (ISlot)
    {
    case EInvSlot::Hat:
        Level = GI->ShopItems[0].MinLevel;
        break;
    case EInvSlot::Neck:
        Level = GI->ShopItems[1].MinLevel;
        break;
    case EInvSlot::Body:
        Level = GI->ShopItems[2].MinLevel;
        break;
    case EInvSlot::LeftHand:
        Level = GI->ShopItems[3].MinLevel;
        break;
    case EInvSlot::RightHand:
        Level = GI->ShopItems[4].MinLevel;
        break;
    case EInvSlot::Belt:
        Level = GI->ShopItems[5].MinLevel;
        break;
    case EInvSlot::Pants:
        Level = GI->ShopItems[6].MinLevel;
        break;
    case EInvSlot::Shoes:
        Level = GI->ShopItems[7].MinLevel;
        break;
    case EInvSlot::Horse:
        Level = GI->ShopItems[8].MinLevel;
        break;
    case EInvSlot::Product:
        Level = GI->ShopItems[9].MinLevel;
        break;

    }

    return FString("Level Needed: ") + FString::FromInt(Level);
}

bool UUWGameUI::ShouldToDoListBeVisible()
{
    for (int i = 0; i < Player->AcceptedQuests.Num(); i++)
    {
        for (int j = 0; j < Player->AcceptedQuests[i].FinishRequirements.Num(); j++)
        {
            auto Req = Player->AcceptedQuests[i].FinishRequirements[j];

            if (Req.AmountsWorkedNeeded > Req.AmountsWorked)
                return true;

            if (Req.TimeWorkedNeeded > Req.TimeWorked)
                return true;

            if (Req.QuestFinished.Len() > 0 && !Player->IsQuestFinished(Req.QuestFinished))
                return true;

            if (Req.HasItemCount > 0 && Player->Inventory->HasItem(Req.HasItem) < Req.HasItemCount)
                return true;
            
            if (Req.NeedsItemCount > 0 && Player->Inventory->HasItem(Req.NeedsItem) < Req.NeedsItemCount)
                return true;

            if (Req.HasMoney > 0 && Req.HasMoney > Player->Money + Player->Bank)
                return true;

            if (Req.LevelsReached > 0 && Player->Level < Req.LevelsReached)
                return true;

            if (Req.WearsItem.Len() > 0 && !Player->WearsItem(Req.WearsItem))
                return true;

        }
    }


    return false;
}

FString UUWGameUI::GetToDoListText()
{
    FString Text;

    for (int i = 0; i < Player->AcceptedQuests.Num(); i++)
    {
        for (int j = 0; j < Player->AcceptedQuests[i].FinishRequirements.Num(); j++)
        {
            auto Req = Player->AcceptedQuests[i].FinishRequirements[j];

            if (Req.AmountsWorkedNeeded > Req.AmountsWorked)
                Text += Req.WorkedJob + " (" + FString::FromInt(Req.AmountsWorked) + "/" + FString::FromInt(Req.AmountsWorkedNeeded) + ")\n";

            if (Req.TimeWorkedNeeded > Req.TimeWorked)
            {
                int SecondsDone = Req.TimeWorked % 60;
                int MinutesDone = (Req.TimeWorked % 3600) / 60;
                int HoursDone = Req.TimeWorked / 3600;
                int SecondsNeeded = Req.TimeWorkedNeeded % 60;
                int MinutesNeeded = (Req.TimeWorkedNeeded % 3600) / 60;
                int HoursNeeded = Req.TimeWorkedNeeded / 3600;

                FString TimeTextDone, TimeTextNeeded;

                if (HoursDone > 0) TimeTextDone += FString::FromInt(HoursDone) + " h ";
                if (MinutesDone > 0) TimeTextDone += FString::FromInt(MinutesDone) + " m ";
                if (SecondsDone > 0 || (HoursDone == 0 && MinutesDone == 0)) TimeTextDone += FString::FromInt(SecondsDone) + " s ";


                if (HoursNeeded > 0) TimeTextNeeded += FString::FromInt(HoursNeeded) + " h ";
                if (MinutesNeeded > 0) TimeTextNeeded += FString::FromInt(MinutesNeeded) + " m ";
                if (SecondsNeeded > 0) TimeTextNeeded += FString::FromInt(SecondsNeeded) + " s";


                Text += Req.WorkedJob + " (" + TimeTextDone + "/" + TimeTextNeeded + ")\n";
            }

            if (Req.QuestFinished.Len() > 0 && !Player->IsQuestFinished(Req.QuestFinished))
                Text += Req.QuestFinished + " finished\n";

            if (Req.HasItemCount > 0 && Player->Inventory->HasItem(Req.HasItem) < Req.HasItemCount)
            {
                auto GI = FindGameInstance();
                FWInventoryItemBase Item = GI->GameData->FindItemByIdentifier(Req.HasItem);
                Text += Item.ItemName + " (" + FString::FromInt(Player->Inventory->HasItem(Req.HasItem)) + "/" + FString::FromInt(Req.HasItemCount) + ")\n";
            }
            if (Req.NeedsItemCount > 0 && Player->Inventory->HasItem(Req.NeedsItem) < Req.NeedsItemCount)
            {
                auto GI = FindGameInstance();
                FWInventoryItemBase Item = GI->GameData->FindItemByIdentifier(Req.NeedsItem);
                Text += Item.ItemName + " (" + FString::FromInt(Player->Inventory->HasItem(Req.NeedsItem)) + "/" + FString::FromInt(Req.NeedsItemCount) + ")\n";
            }

            if (Req.HasMoney > 0 && Req.HasMoney > Player->Money + Player->Bank)
                Text += "Cash ($" + FString::FromInt(Player->Money + Player->Bank) + "/" + FString::FromInt(Req.HasMoney) + ")\n";

            if (Req.LevelsReached > 0 && Player->Level < Req.LevelsReached)
                Text += "Reach level " + FString::FromInt(Req.LevelsReached) + "\n";

            if (Req.WearsItem.Len() > 0 && !Player->WearsItem(Req.WearsItem))
            {
                auto GI = FindGameInstance();
                FWInventoryItemBase Item = GI->GameData->FindItemByIdentifier(Req.WearsItem);

                if (Player->Inventory->HasItem(Req.WearsItem))
                    Text += "WEAR " + Item.ItemName + "\n";
                else
                    Text += "Find " + Item.ItemName + "\n";
                    
            }

        }
    }


    return Text;

    return FString();
}


void UUWGameUI::SetPlayer(AWPlayer* P)
{
    Player = P;
}
