// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WQuest.h"
#include "WQuestline.generated.h"

/**
 * 
 */
USTRUCT(Blueprintable)
struct WESTLOCAL_API FWQuestline
{
	GENERATED_BODY()
public:
	FWQuestline();
	~FWQuestline();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Repeatable = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FWQuestRequirement> Requirements;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FWQuest> Quests;

	bool IsVisible(class AWPlayer* Player);

};
