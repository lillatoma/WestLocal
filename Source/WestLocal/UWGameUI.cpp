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

void UUWGameUI::SetPlayer(AWPlayer* P)
{
    Player = P;
}
