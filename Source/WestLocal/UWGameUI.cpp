// Fill out your copyright notice in the Description page of Project Settings.


#include "UWGameUI.h"
#include "WPlayer.h"

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

void UUWGameUI::SetPlayer(AWPlayer* P)
{
    Player = P;
}
