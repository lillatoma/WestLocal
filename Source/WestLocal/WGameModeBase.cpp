// Fill out your copyright notice in the Description page of Project Settings.


#include "GI_WestGameInstance.h"
#include "WGameModeBase.h"
#include "UWGameUI.h"
#include "WPlayer.h"

void AWGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	if(PlayerClass)
		Player = Cast<AWPlayer>(GetWorld()->SpawnActor<AActor>(PlayerClass, FVector(), FRotator()));
	if (UIClass)
	{
		UI = Cast<UUWGameUI>(CreateWidget(GetWorld(), UIClass));
		if (UI)
		{
			UI->AddToViewport();
			UI->SetPlayer(Player);
			if (Player)
			{
				Player->UI = UI;
			}
		}
	}
	UGI_WestGameInstance* Instance = Cast<UGI_WestGameInstance>(GetGameInstance());

	Instance->PregenerateShopItems();
	Instance->GameData->SetUpSetIndexes();
	Instance->GameData->CheckQuestsForMatchingNames();
	Instance->GameData->CheckQuestsForErrors();
	
}
