// Fill out your copyright notice in the Description page of Project Settings.


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
		}
	}
}
