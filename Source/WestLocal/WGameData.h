// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WInventoryItemBase.h"
#include "WJobPlace.h"
#include "WSet.h"
#include "WQuestline.h"
#include "Engine/DataAsset.h"
#include "WGameData.generated.h"

/**
 * 
 */
UCLASS()
class WESTLOCAL_API UWGameData : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
		TArray<FWInventoryItemBase> Hats;
	UPROPERTY(EditAnywhere)
		TArray<FWInventoryItemBase> Necks;
	UPROPERTY(EditAnywhere)
		TArray<FWInventoryItemBase> Clothes;
	UPROPERTY(EditAnywhere)
		TArray<FWInventoryItemBase> Shoes;
	UPROPERTY(EditAnywhere)
		TArray<FWInventoryItemBase> Trousers;
	UPROPERTY(EditAnywhere)
		TArray<FWInventoryItemBase> Belts;
	UPROPERTY(EditAnywhere)
		TArray<FWInventoryItemBase> LeftHand;
	UPROPERTY(EditAnywhere)
		TArray<FWInventoryItemBase> RightHand;
	UPROPERTY(EditAnywhere)
		TArray<FWInventoryItemBase> Animals;
	UPROPERTY(EditAnywhere)
		TArray<FWInventoryItemBase> Products;

	UPROPERTY(EditAnywhere)
		TArray<FWSet> ItemSets;


	UPROPERTY(EditAnywhere)
		TArray<FWJobPlace> JobPlaces;
	
	UPROPERTY(EditAnywhere)
		TArray<int> LevelRequirements;

	UPROPERTY(EditAnywhere)
		TArray<FWQuestline> Questlines;

	FWInventoryItemBase FindItemByIdentifier(FString Identifier);

	FWInventoryItemBase FindItemInPriceRange(int Min, int Max);

	FWSet FindSet(FString Set);

	FWQuestline FindQuestline(FString Name);

	FWQuest FindQuest(FString Name);
	


};
