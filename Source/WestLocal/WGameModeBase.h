// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "WGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class WESTLOCAL_API AWGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		TSubclassOf<class AWPlayer> PlayerClass;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class UUserWidget> UIClass;



protected:
	virtual void BeginPlay() override;
	
private:
	class AWPlayer* Player;
	class UUWGameUI* UI;

};
