// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WSkillSet.h"
#include "WJob.h"
#include "WJobPlace.h"
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

	UFUNCTION(BlueprintCallable)
		FString UpdateUnspentSkillText(WSkillNames Skill);

	UFUNCTION(BlueprintCallable)
		FString UpdateUnspentAttributesText(WSkillNames Skill);

	UFUNCTION(BlueprintCallable)
		class UGI_WestGameInstance* FindGameInstance();

	UFUNCTION(BlueprintCallable)
		void PreviousJobPlace();

	UFUNCTION(BlueprintCallable)
		void NextJobPlace();

	UFUNCTION(BlueprintCallable)
		bool ShouldShowJobPanelOnRight();

	UFUNCTION(BlueprintCallable)
		FWJobPlace GetCurrentJobPlace();

	UFUNCTION(BlueprintCallable)
		FString GetJobNameForID(int ID);

	UFUNCTION(BlueprintCallable)
		FWJob GetCurrentJob();

	UFUNCTION(BlueprintCallable)
		bool IsJobWorkable();

	UFUNCTION(BlueprintCallable)
		FString GetSmallCash();

	UFUNCTION(BlueprintCallable)
		FString GetSmallXP();

	UFUNCTION(BlueprintCallable)
		FString GetSmallLuck();

	UFUNCTION(BlueprintCallable)
		FString GetSmallProductName(int id);

	UFUNCTION(BlueprintCallable)
		FString GetSmallProductPercent(int id);

	UFUNCTION(BlueprintCallable)
		FString GetMidCash();

	UFUNCTION(BlueprintCallable)
		FString GetMidXP();

	UFUNCTION(BlueprintCallable)
		FString GetMidLuck();

	UFUNCTION(BlueprintCallable)
		FString GetMidProductName(int id);

	UFUNCTION(BlueprintCallable)
		FString GetMidProductPercent(int id);

	UFUNCTION(BlueprintCallable)
		FString GetLongCash();

	UFUNCTION(BlueprintCallable)
		FString GetLongXP();

	UFUNCTION(BlueprintCallable)
		FString GetLongLuck();

	UFUNCTION(BlueprintCallable)
		FString GetLongProductName(int id);

	UFUNCTION(BlueprintCallable)
		FString GetLongProductPercent(int id);

	void SetPlayer(class AWPlayer* P);

private:
	UPROPERTY()
		class AWPlayer* Player;

	UPROPERTY(EditAnywhere)
		class UGI_WestGameInstance* Instance;

	UPROPERTY(EditAnywhere)
		int JobPlaceIndex = 0;

	UPROPERTY(EditAnywhere)
		int JobIndex = -1;
	
};
