// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WJob.h"
#include "UObject/NoExportTypes.h"
#include "WJobPlace.generated.h"

/**
 * 
 */
UCLASS()
class WESTLOCAL_API UWJobPlace : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
		TArray<FWJob> Jobs;

};
