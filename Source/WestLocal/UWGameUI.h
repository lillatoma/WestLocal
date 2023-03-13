// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WSkillSet.h"
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

	void SetPlayer(class AWPlayer* P);

private:
	UPROPERTY()
		class AWPlayer* Player;
	
};
