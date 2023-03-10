// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "WGameData.h"
#include "GI_WestGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class WESTLOCAL_API UGI_WestGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		UWGameData* GameData;


};
