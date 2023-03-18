// Fill out your copyright notice in the Description page of Project Settings.


#include "WPlayer.h"
#include "WSkillSet.h"
#include "GI_WestGameInstance.h"
#include "WGameData.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AWPlayer::AWPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

int AWPlayer::GetTotalStrength() const
{
	return CharacterSkills.Strength + ClothesSkills.Strength + SetSkills.Strength + BuffSkills.Strength;
}

int AWPlayer::GetTotalMobility() const
{
	return CharacterSkills.Mobility + ClothesSkills.Mobility + SetSkills.Mobility + BuffSkills.Mobility;
}

int AWPlayer::GetTotalDexterity() const
{
	return CharacterSkills.Dexterity + ClothesSkills.Dexterity + SetSkills.Dexterity + BuffSkills.Dexterity;
}

int AWPlayer::GetTotalCharisma() const
{
	return CharacterSkills.Charisma + ClothesSkills.Charisma + SetSkills.Charisma + BuffSkills.Charisma;
}

int AWPlayer::GetTotalConstruction() const
{
	return CharacterSkills.Construction + ClothesSkills.Construction + SetSkills.Construction + BuffSkills.Construction + GetTotalStrength();
}

int AWPlayer::GetTotalVigor() const
{
	return CharacterSkills.Vigor + ClothesSkills.Vigor + SetSkills.Vigor + BuffSkills.Vigor + GetTotalStrength();
}

int AWPlayer::GetTotalToughness() const
{
	return CharacterSkills.Toughness + ClothesSkills.Toughness + SetSkills.Toughness + BuffSkills.Toughness + GetTotalStrength();
}

int AWPlayer::GetTotalStamina() const
{
	return CharacterSkills.Stamina + ClothesSkills.Stamina + SetSkills.Stamina + BuffSkills.Stamina + GetTotalStrength();
}

int AWPlayer::GetTotalHealthPoints() const
{
	return CharacterSkills.HealthPoints + ClothesSkills.HealthPoints + SetSkills.HealthPoints + BuffSkills.HealthPoints + GetTotalStrength();
}

int AWPlayer::GetTotalRiding() const
{
	return CharacterSkills.Riding + ClothesSkills.Riding + SetSkills.Riding + BuffSkills.Riding + GetTotalMobility();
}

int AWPlayer::GetTotalReflex() const
{
	return CharacterSkills.Reflex + ClothesSkills.Reflex + SetSkills.Reflex + BuffSkills.Reflex + GetTotalMobility();
}

int AWPlayer::GetTotalDodging() const
{
	return CharacterSkills.Dodging + ClothesSkills.Dodging + SetSkills.Dodging + BuffSkills.Dodging + GetTotalMobility();
}

int AWPlayer::GetTotalHiding() const
{
	return CharacterSkills.Hiding + ClothesSkills.Hiding + SetSkills.Hiding + BuffSkills.Hiding + GetTotalMobility();
}

int AWPlayer::GetTotalSwimming() const
{
	return CharacterSkills.Swimming + ClothesSkills.Swimming + SetSkills.Swimming + BuffSkills.Swimming + GetTotalMobility();
}

int AWPlayer::GetTotalAiming() const
{
	return CharacterSkills.Aiming + ClothesSkills.Aiming + SetSkills.Aiming + BuffSkills.Aiming + GetTotalDexterity();
}

int AWPlayer::GetTotalShooting() const
{
	return CharacterSkills.Shooting + ClothesSkills.Shooting + SetSkills.Shooting + BuffSkills.Shooting + GetTotalDexterity();
}

int AWPlayer::GetTotalTrapping() const
{
	return CharacterSkills.Trapping + ClothesSkills.Trapping + SetSkills.Trapping + BuffSkills.Trapping + GetTotalDexterity();
}

int AWPlayer::GetTotalFineMotorSkills() const
{
	return CharacterSkills.FineMotorSkills + ClothesSkills.FineMotorSkills + SetSkills.FineMotorSkills + BuffSkills.FineMotorSkills + GetTotalDexterity();
}

int AWPlayer::GetTotalRepairing() const
{
	return CharacterSkills.Repairing + ClothesSkills.Repairing + SetSkills.Repairing + BuffSkills.Repairing + GetTotalDexterity();
}

int AWPlayer::GetTotalLeadership() const
{
	return CharacterSkills.Leadership + ClothesSkills.Leadership + SetSkills.Leadership + BuffSkills.Leadership + GetTotalCharisma();
}

int AWPlayer::GetTotalTactic() const
{
	return CharacterSkills.Tactic + ClothesSkills.Tactic + SetSkills.Tactic + BuffSkills.Tactic + GetTotalCharisma();
}

int AWPlayer::GetTotalTrading() const
{
	return CharacterSkills.Trading + ClothesSkills.Trading + SetSkills.Trading + BuffSkills.Trading + GetTotalCharisma();
}

int AWPlayer::GetTotalAnimalInstinct() const
{
	return CharacterSkills.AnimalInstinct + ClothesSkills.AnimalInstinct + SetSkills.AnimalInstinct + BuffSkills.AnimalInstinct + GetTotalCharisma();
}

int AWPlayer::GetTotalAppearance() const
{
	return CharacterSkills.Appearance + ClothesSkills.Appearance + SetSkills.Appearance + BuffSkills.Appearance + GetTotalCharisma();
}

float AWPlayer::GetTotalFindingChance() const
{
	return CharacterSkills.FindingChance * ClothesSkills.FindingChance * SetSkills.FindingChance * BuffSkills.FindingChance;
}

float AWPlayer::GetTotalLuck() const
{
	return CharacterSkills.Luck * ClothesSkills.Luck * SetSkills.Luck * BuffSkills.Luck;
}

float AWPlayer::GetTotalMoneyPercentage() const
{
	return CharacterSkills.MoneyPercentage * ClothesSkills.MoneyPercentage * SetSkills.MoneyPercentage * BuffSkills.MoneyPercentage;
}

float AWPlayer::GetTotalXPPercentage() const
{
	return CharacterSkills.XPPercentage * ClothesSkills.XPPercentage * SetSkills.XPPercentage * BuffSkills.XPPercentage;
}

float AWPlayer::GetTotalSpeed() const
{
	float BaseSpeed = (1.0f + 0.01f * GetTotalRiding());
	float Multiplier = (CharacterSkills.Speed * ClothesSkills.Speed * SetSkills.Speed * BuffSkills.Speed);
	return BaseSpeed * Multiplier;
}

int AWPlayer::GetTotalOf(WSkillNames Skill) const
{
	switch (Skill)
	{
	case WSkillNames::Strength:
			return GetTotalStrength();
			break;
	case WSkillNames::Dexterity:
		return GetTotalDexterity();
		break;
	case WSkillNames::Mobility:
		return GetTotalMobility();
		break;
	case WSkillNames::Charisma:
		return GetTotalCharisma();
		break;

	case WSkillNames::Construction:
		return GetTotalConstruction();
		break;
	case WSkillNames::Vigor:
		return GetTotalVigor();
		break;
	case WSkillNames::Toughness:
		return GetTotalToughness();
		break;
	case WSkillNames::Stamina:
		return GetTotalStamina();
		break;
	case WSkillNames::HealthPoints:
		return GetTotalHealthPoints();
		break;
	case WSkillNames::Riding:
		return GetTotalRiding();
		break;
	case WSkillNames::Reflex:
		return GetTotalReflex();
		break;
	case WSkillNames::Dodging:
		return GetTotalDodging();
		break;
	case WSkillNames::Hiding:
		return GetTotalHiding();
		break;
	case WSkillNames::Swimming:
		return GetTotalSwimming();
		break;
	case WSkillNames::Aiming:
		return GetTotalAiming();
		break;
	case WSkillNames::Shooting:
		return GetTotalShooting();
		break;
	case WSkillNames::Trapping:
		return GetTotalTrapping();
		break;
	case WSkillNames::FineMotorSkills:
		return GetTotalFineMotorSkills();
		break;
	case WSkillNames::Repairing:
		return GetTotalRepairing();
		break;
	case WSkillNames::Leadership:
		return GetTotalLeadership();
		break;
	case WSkillNames::Tactic:
		return GetTotalTactic();
		break;
	case WSkillNames::Trading:
		return GetTotalTrading();
		break;
	case WSkillNames::AnimalInstinct:
		return GetTotalAnimalInstinct();
		break;
	case WSkillNames::Appearance:
		return GetTotalAppearance();
		break;

	}
	return 0;
}

int AWPlayer::GetTotalExtraWorkPoints() const
{
	return CharacterSkills.ExtraWorkPoints + ClothesSkills.ExtraWorkPoints + SetSkills.ExtraWorkPoints + BuffSkills.ExtraWorkPoints;
}

WSkillSet AWPlayer::GetTotalSkills() const
{
	WSkillSet Total;
	Total.Strength = GetTotalStrength();
	Total.Mobility = GetTotalMobility();
	Total.Dexterity = GetTotalDexterity();
	Total.Charisma= GetTotalCharisma();

	Total.Construction = GetTotalConstruction();
	Total.Vigor = GetTotalVigor();
	Total.Toughness = GetTotalToughness();
	Total.Stamina = GetTotalStamina();
	Total.HealthPoints = GetTotalHealthPoints();

	Total.Riding = GetTotalRiding();
	Total.Reflex = GetTotalReflex();
	Total.Dodging = GetTotalDodging();
	Total.Hiding = GetTotalHiding();
	Total.Swimming = GetTotalSwimming();

	Total.Aiming = GetTotalAiming();
	Total.Shooting = GetTotalShooting();
	Total.Trapping = GetTotalTrapping();
	Total.FineMotorSkills = GetTotalFineMotorSkills();
	Total.Repairing = GetTotalRepairing();

	Total.Leadership = GetTotalLeadership();
	Total.Tactic = GetTotalTactic();
	Total.Trading = GetTotalTrading();
	Total.Appearance = GetTotalAppearance();
	Total.AnimalInstinct = GetTotalAnimalInstinct();

	Total.MoneyPercentage = GetTotalMoneyPercentage();
	Total.XPPercentage = GetTotalXPPercentage();
	Total.Luck = GetTotalLuck();
	Total.FindingChance = GetTotalFindingChance();
	Total.Speed = GetTotalSpeed();

	Total.ExtraWorkPoints = GetTotalExtraWorkPoints();

	return Total;
}

int AWPlayer::GetLevel() const
{
	return Level;
}

bool AWPlayer::EligibleForNextLevel() const
{
	int NextLevelXP = GameInstance->GameData->LevelRequirements[Level - 1];
	return XPToNextLevel < NextLevelXP;
}

void AWPlayer::LevelUp()
{
	if (!EligibleForNextLevel())
		return;
	XPToNextLevel -= GameInstance->GameData->LevelRequirements[Level - 1];
	Level++;
	UnspentSkillPoints++;
	UnspentAttributePoints += 3;

	if (AutoSpendSkills)
		AutoSpendSkillsFunc();

	CalculateClothesSkillSet();
	CalculateSetSkillSet();
}

void AWPlayer::SpendSkillPoint(WSkillNames Skill)
{
	if (Skill != WSkillNames::Strength && Skill != WSkillNames::Mobility
		&& Skill != WSkillNames::Dexterity && Skill != WSkillNames::Charisma)
		return;
	if (UnspentSkillPoints > 0)
	{
		switch (Skill)
		{
		case WSkillNames::Strength:
			CharacterSkills.Strength++;
			break;
		case WSkillNames::Mobility:
			CharacterSkills.Mobility++;
			break;
		case WSkillNames::Dexterity:
			CharacterSkills.Dexterity++;
			break;
		case WSkillNames::Charisma:
			CharacterSkills.Charisma++;
			break;
		}
		UnspentSkillPoints--;
	}
}

void AWPlayer::SpendAttributePoint(WSkillNames Skill)
{
	if (Skill < WSkillNames::Construction || Skill > WSkillNames::Appearance)
		return;
	if (UnspentAttributePoints > 0)
	{
		switch (Skill)
		{
		case WSkillNames::Construction:
			CharacterSkills.Construction++;
			break;
		case WSkillNames::Vigor:
			CharacterSkills.Vigor++;
			break;
		case WSkillNames::Stamina:
			CharacterSkills.Construction++;
			break;
		case WSkillNames::Toughness:
			CharacterSkills.Toughness++;
			break;
		case WSkillNames::HealthPoints:
			CharacterSkills.HealthPoints++;
			break;
		case WSkillNames::Riding:
			CharacterSkills.Riding++;
			break;
		case WSkillNames::Reflex:
			CharacterSkills.Reflex++;
			break;
		case WSkillNames::Dodging:
			CharacterSkills.Dodging++;
			break;
		case WSkillNames::Hiding:
			CharacterSkills.Hiding++;
			break;
		case WSkillNames::Swimming:
			CharacterSkills.Swimming++;
			break;
		case WSkillNames::Aiming:
			CharacterSkills.Aiming++;
			break;
		case WSkillNames::Shooting:
			CharacterSkills.Shooting++;
			break;
		case WSkillNames::Trapping:
			CharacterSkills.Trapping++;
			break;
		case WSkillNames::FineMotorSkills:
			CharacterSkills.FineMotorSkills++;
			break;
		case WSkillNames::Repairing:
			CharacterSkills.Repairing++;
			break;
		case WSkillNames::Leadership:
			CharacterSkills.Leadership++;
			break;
		case WSkillNames::Tactic:
			CharacterSkills.Tactic++;
			break;
		case WSkillNames::Trading:
			CharacterSkills.Trading++;
			break;
		case WSkillNames::AnimalInstinct:
			CharacterSkills.AnimalInstinct++;
			break;
		case WSkillNames::Appearance:
			CharacterSkills.Appearance++;
			break;
		}
		UnspentAttributePoints--;
	}
}

void AWPlayer::AutoSpendSkillsFunc()
{
	while (UnspentSkillPoints > 0)
	{
		WSkillNames Skill = (WSkillNames)FMath::RandRange(0, 3);
		SpendSkillPoint(Skill);
	}
	while (UnspentAttributePoints > 0)
	{
		WSkillNames Skill = (WSkillNames)FMath::RandRange(4, 23);
		SpendAttributePoint(Skill);
	}
}

void AWPlayer::StopCursor()
{
	APlayerController* PlayerControllerRef = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	PlayerControllerRef->SetShowMouseCursor(true);
}

// Called when the game starts or when spawned
void AWPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	GameInstance = Cast<UGI_WestGameInstance>(GetGameInstance());

	APlayerController* PlayerControllerRef = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	PlayerControllerRef->SetShowMouseCursor(true);
	FTimerHandle UnusedHandle;
	GetWorld()->GetTimerManager().SetTimer(UnusedHandle, this, &AWPlayer::StopCursor, 0.01f, false);

	Inventory = NewObject<UWInventory>();
}

// Called every frame
void AWPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AWPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AWPlayer::TakeOffHat()
{
	if (!Hat)
		return;
	Inventory->AddItem(Hat, 1);
	delete Hat;

	CalculateClothesSkillSet();
	CalculateSetSkillSet();
}

void AWPlayer::TakeOffNeck()
{
	if (!Neck)
		return;
	Inventory->AddItem(Neck, 1);
	delete Neck;

	CalculateClothesSkillSet();
	CalculateSetSkillSet();
}

void AWPlayer::TakeOffBody()
{
	if (!Body)
		return;
	Inventory->AddItem(Body, 1);
	delete Body;

	CalculateClothesSkillSet();
	CalculateSetSkillSet();
}

void AWPlayer::TakeOffLeftHand()
{
	if (!LeftHand)
		return;
	Inventory->AddItem(LeftHand, 1);
	delete LeftHand;

	CalculateClothesSkillSet();
	CalculateSetSkillSet();
}

void AWPlayer::TakeOffRightHand()
{
	if (!RightHand)
		return;
	Inventory->AddItem(RightHand, 1);
	delete RightHand;

	CalculateClothesSkillSet();
	CalculateSetSkillSet();
}

void AWPlayer::TakeOffBelt()
{
	if (!Belt)
		return;
	Inventory->AddItem(Belt, 1);
	delete Belt;

	CalculateClothesSkillSet();
	CalculateSetSkillSet();
}

void AWPlayer::TakeOffPants()
{
	if (!Pants)
		return;
	Inventory->AddItem(Pants, 1);
	delete Pants;

	CalculateClothesSkillSet();
	CalculateSetSkillSet();
}

void AWPlayer::TakeOffShoes()
{
	if (!Shoes)
		return;
	Inventory->AddItem(Shoes, 1);
	delete Shoes;

	CalculateClothesSkillSet();
	CalculateSetSkillSet();
}

void AWPlayer::TakeOffHorse()
{
	if (!Horse)
		return;
	Inventory->AddItem(Horse, 1);
	delete Horse;

	CalculateClothesSkillSet();
	CalculateSetSkillSet();
}

void AWPlayer::TakeOffProduct()
{
	if (!Product)
		return;
	Inventory->AddItem(Product, 1);
	delete Product;

	CalculateClothesSkillSet();
	CalculateSetSkillSet();
}

void AWPlayer::TakeOffAll()
{
	TakeOffHat();
	TakeOffNeck();
	TakeOffBody();
	TakeOffLeftHand();
	TakeOffRightHand();
	TakeOffBelt();
	TakeOffPants();
	TakeOffShoes();
	TakeOffHorse();
	TakeOffProduct();
}

void AWPlayer::TakeOnHat(int Index)
{
	if (Inventory->Items[Index]->Slot != EInvSlot::Hat)
		return;
	if (Hat)
	{
		Inventory->AddItem(Hat,1);
		Hat->MakeEqual(Inventory->Items[Index]);
		Inventory->RemoveItem(Index, 1);
	}
	else
	{
		Hat = new FWInventoryItemBase();
		Hat->MakeEqual(Inventory->Items[Index]);
		Inventory->RemoveItem(Index, 1);
	}
}

void AWPlayer::TakeOnNeck(int Index)
{
	if (Inventory->Items[Index]->Slot != EInvSlot::Neck)
		return;
	if (Neck)
	{
		Inventory->AddItem(Neck, 1);
		Neck->MakeEqual(Inventory->Items[Index]);
		Inventory->RemoveItem(Index, 1);
	}
	else
	{
		Neck = new FWInventoryItemBase();
		Neck->MakeEqual(Inventory->Items[Index]);
		Inventory->RemoveItem(Index, 1);
	}
}

void AWPlayer::TakeOnBody(int Index)
{
	if (Inventory->Items[Index]->Slot != EInvSlot::Body)
		return;
	if (Body)
	{
		Inventory->AddItem(Body, 1);
		Body->MakeEqual(Inventory->Items[Index]);
		Inventory->RemoveItem(Index, 1);
	}
	else
	{
		Body = new FWInventoryItemBase();
		Body->MakeEqual(Inventory->Items[Index]);
		Inventory->RemoveItem(Index, 1);
	}
}

void AWPlayer::TakeOnLeftHand(int Index)
{
	if (Inventory->Items[Index]->Slot != EInvSlot::LeftHand)
		return;
	if (LeftHand)
	{
		Inventory->AddItem(LeftHand, 1);
		LeftHand->MakeEqual(Inventory->Items[Index]);
		Inventory->RemoveItem(Index, 1);
	}
	else
	{
		LeftHand = new FWInventoryItemBase();
		LeftHand->MakeEqual(Inventory->Items[Index]);
		Inventory->RemoveItem(Index, 1);
	}
}

void AWPlayer::TakeOnRightHand(int Index)
{
	if (Inventory->Items[Index]->Slot != EInvSlot::RightHand)
		return;
	if (RightHand)
	{
		Inventory->AddItem(RightHand, 1);
		RightHand->MakeEqual(Inventory->Items[Index]);
		Inventory->RemoveItem(Index, 1);
	}
	else
	{
		RightHand = new FWInventoryItemBase();
		RightHand->MakeEqual(Inventory->Items[Index]);
		Inventory->RemoveItem(Index, 1);
	}
}

void AWPlayer::TakeOnBelt(int Index)
{
	if (Inventory->Items[Index]->Slot != EInvSlot::Belt)
		return;
	if (Belt)
	{
		Inventory->AddItem(Belt, 1);
		Belt->MakeEqual(Inventory->Items[Index]);
		Inventory->RemoveItem(Index, 1);
	}
	else
	{
		Belt = new FWInventoryItemBase();
		Belt->MakeEqual(Inventory->Items[Index]);
		Inventory->RemoveItem(Index, 1);
	}
}

void AWPlayer::TakeOnPants(int Index)
{
	if (Inventory->Items[Index]->Slot != EInvSlot::Pants)
		return;
	if (Pants)
	{
		Inventory->AddItem(Pants, 1);
		Pants->MakeEqual(Inventory->Items[Index]);
		Inventory->RemoveItem(Index, 1);
	}
	else
	{
		Pants = new FWInventoryItemBase();
		Pants->MakeEqual(Inventory->Items[Index]);
		Inventory->RemoveItem(Index, 1);
	}
}

void AWPlayer::TakeOnShoes(int Index)
{
	if (Inventory->Items[Index]->Slot != EInvSlot::Shoes)
		return;
	if (Shoes)
	{
		Inventory->AddItem(Shoes, 1);
		Shoes->MakeEqual(Inventory->Items[Index]);
		Inventory->RemoveItem(Index, 1);
	}
	else
	{
		Shoes = new FWInventoryItemBase();
		Shoes->MakeEqual(Inventory->Items[Index]);
		Inventory->RemoveItem(Index, 1);
	}
}

void AWPlayer::TakeOnHorse(int Index)
{
	if (Inventory->Items[Index]->Slot != EInvSlot::Horse)
		return;
	if (Horse)
	{
		Inventory->AddItem(Horse, 1);
		Horse->MakeEqual(Inventory->Items[Index]);
		Inventory->RemoveItem(Index, 1);
	}
	else
	{
		Horse = new FWInventoryItemBase();
		Horse->MakeEqual(Inventory->Items[Index]);
		Inventory->RemoveItem(Index, 1);
	}
}

void AWPlayer::TakeOnProduct(int Index)
{
	if (Inventory->Items[Index]->Slot != EInvSlot::Product)
		return;
	if (Product)
	{
		Inventory->AddItem(Product, 1);
		Product->MakeEqual(Inventory->Items[Index]);
		Inventory->RemoveItem(Index, 1);
	}
	else
	{
		Product = new FWInventoryItemBase();
		Product->MakeEqual(Inventory->Items[Index]);
		Inventory->RemoveItem(Index, 1);
	}
}

void AWPlayer::TakeOn(int Index)
{
	switch (Inventory->Items[Index]->Slot)
	{
	case EInvSlot::Hat:
		TakeOnHat(Index);
		break;
	case EInvSlot::Neck:
		TakeOnNeck(Index);
		break;
	case EInvSlot::Body:
		TakeOnBody(Index);
		break;
	case EInvSlot::LeftHand:
		TakeOnLeftHand(Index);
		break;
	case EInvSlot::RightHand:
		TakeOnRightHand(Index);
		break;
	case EInvSlot::Belt:
		TakeOnBelt(Index);
		break;
	case EInvSlot::Pants:
		TakeOnPants(Index);
		break;
	case EInvSlot::Shoes:
		TakeOnShoes(Index);
		break;
	case EInvSlot::Horse:
		TakeOnHorse(Index);
		break;
	case EInvSlot::Product:
		TakeOnProduct(Index);
		break;
	}
	return;
}

bool AWPlayer::HasItemInSlot(EInvSlot Slot)
{
	switch (Slot)
	{
	case EInvSlot::Hat:
		return Hat != nullptr;
	case EInvSlot::Neck:
			return Neck != nullptr;
		case EInvSlot::Body:
			return Body != nullptr;
		case EInvSlot::LeftHand:
			return LeftHand != nullptr;
		case EInvSlot::RightHand:
			return RightHand != nullptr;
		case EInvSlot::Belt:
			return Belt != nullptr;
		case EInvSlot::Pants:
			return Pants != nullptr;
		case EInvSlot::Shoes:
			return Shoes != nullptr;
	case EInvSlot::Horse:
		return Horse != nullptr;
	case EInvSlot::Product:
		return Product != nullptr;
	}
	return true;
}

FWInventoryItemBase* AWPlayer::GetItemInSlot(EInvSlot Slot)
{
	switch (Slot)
	{
	case EInvSlot::Hat:
		return Hat;
	case EInvSlot::Neck:
			return Neck;
		case EInvSlot::Body:
			return Body;
		case EInvSlot::LeftHand:
			return LeftHand;
		case EInvSlot::RightHand:
			return RightHand;
		case EInvSlot::Belt:
			return Belt;
		case EInvSlot::Pants:
			return Pants;
		case EInvSlot::Shoes:
			return Shoes;
		case EInvSlot::Horse:
			return Horse;
		case EInvSlot::Product:
			return Product;
	}
	return nullptr;
}

TArray<FWInventoryItemBase*> AWPlayer::GetSlottedItems()
{
	TArray<FWInventoryItemBase*> Items;

	FWInventoryItemBase* Item;
	Item = GetItemInSlot(EInvSlot::Hat);
	if (Item)
		Items.Add(Item);

	Item = GetItemInSlot(EInvSlot::Neck);
	if (Item)
		Items.Add(Item);

	Item = GetItemInSlot(EInvSlot::Body);
	if (Item)
		Items.Add(Item);

	Item = GetItemInSlot(EInvSlot::LeftHand);
	if (Item)
		Items.Add(Item);

	Item = GetItemInSlot(EInvSlot::RightHand);
	if (Item)
		Items.Add(Item);

	Item = GetItemInSlot(EInvSlot::Belt);
	if (Item)
		Items.Add(Item);

	Item = GetItemInSlot(EInvSlot::Pants);
	if (Item)
		Items.Add(Item);

	Item = GetItemInSlot(EInvSlot::Shoes);
	if (Item)
		Items.Add(Item);

	Item = GetItemInSlot(EInvSlot::Horse);
	if (Item)
		Items.Add(Item);

	Item = GetItemInSlot(EInvSlot::Product);
	if (Item)
		Items.Add(Item);

	return Items;
}

TArray<int> AWPlayer::GetAllItemsForSlot(EInvSlot Slot)
{
	TArray<int> Ret;
	int Length = Inventory->GetSize();
	for (int i = 0; i < Length; i++)
	{
		if (Inventory->Items[i]->Slot == Slot)
			Ret.Add(i);
	}
	return Ret;
}

int AWPlayer::RateSingularItemForJob(FWJob Job, int Index)
{
	int Rating = 0;
	for (int i = 0; i < Inventory->Items[Index]->FixedAttributes.Num(); i++)
	{
		if (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == Job.NeededAttribute1)
			Rating += Inventory->Items[Index]->FixedAttributes[i].IntValue;
		if (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == Job.NeededAttribute2)
			Rating += Inventory->Items[Index]->FixedAttributes[i].IntValue;
		if (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == Job.NeededAttribute3)
			Rating += Inventory->Items[Index]->FixedAttributes[i].IntValue;
		if (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == Job.NeededAttribute4)
			Rating += Inventory->Items[Index]->FixedAttributes[i].IntValue;
		if (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == Job.NeededAttribute5)
			Rating += Inventory->Items[Index]->FixedAttributes[i].IntValue;

		if ((Inventory->Items[Index]->FixedAttributes[i].FixedSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute1))
			|| (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute2))
			|| (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute3))
			|| (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute4))
			|| (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute5)))
			Rating += Inventory->Items[Index]->FixedAttributes[i].IntValue;

		if ((Inventory->Items[Index]->FixedAttributes[i].FixedSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute1))
			|| (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute2))
			|| (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute3))
			|| (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute4))
			|| (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute5)))
			Rating += Inventory->Items[Index]->FixedAttributes[i].IntValue;

		if ((Inventory->Items[Index]->FixedAttributes[i].FixedSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute1))
			|| (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute2))
			|| (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute3))
			|| (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute4))
			|| (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute5)))
			Rating += Inventory->Items[Index]->FixedAttributes[i].IntValue;

		if ((Inventory->Items[Index]->FixedAttributes[i].FixedSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute1))
			|| (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute2))
			|| (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute3))
			|| (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute4))
			|| (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute5)))
			Rating += Inventory->Items[Index]->FixedAttributes[i].IntValue;


		if (Inventory->Items[Index]->FixedAttributes[i].FixedSkill == WSkillNames::ExtraWorkPoints)
			Rating += Inventory->Items[Index]->FixedAttributes[i].IntValue;
	}
	for (int i = 0; i < Inventory->Items[Index]->LeveledAttributes.Num(); i++)
	{
		if (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == Job.NeededAttribute1)
			Rating += FMath::CeilToInt32(Inventory->Items[Index]->LeveledAttributes[i].FloatValue * Level);
		if (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == Job.NeededAttribute2)
			Rating += FMath::CeilToInt32(Inventory->Items[Index]->LeveledAttributes[i].FloatValue * Level);
		if (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == Job.NeededAttribute3)
			Rating += FMath::CeilToInt32(Inventory->Items[Index]->LeveledAttributes[i].FloatValue * Level);
		if (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == Job.NeededAttribute4)
			Rating += FMath::CeilToInt32(Inventory->Items[Index]->LeveledAttributes[i].FloatValue * Level);
		if (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == Job.NeededAttribute5)
			Rating += FMath::CeilToInt32(Inventory->Items[Index]->LeveledAttributes[i].FloatValue * Level);
		if (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == WSkillNames::ExtraWorkPoints)
			Rating += FMath::CeilToInt32(Inventory->Items[Index]->LeveledAttributes[i].FloatValue * Level);

		if ((Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute1))
			|| (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute2))
			|| (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute3))
			|| (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute4))
			|| (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute5)))
			Rating += FMath::CeilToInt32(Inventory->Items[Index]->LeveledAttributes[i].FloatValue * Level);

		if ((Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute1))
			|| (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute2))
			|| (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute3))
			|| (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute4))
			|| (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute5)))
			Rating += FMath::CeilToInt32(Inventory->Items[Index]->LeveledAttributes[i].FloatValue * Level);

		if ((Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute1))
			|| (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute2))
			|| (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute3))
			|| (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute4))
			|| (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute5)))
			Rating += FMath::CeilToInt32(Inventory->Items[Index]->LeveledAttributes[i].FloatValue * Level);

		if ((Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute1))
			|| (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute2))
			|| (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute3))
			|| (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute4))
			|| (Inventory->Items[Index]->LeveledAttributes[i].LeveledSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute5)))
			Rating += FMath::CeilToInt32(Inventory->Items[Index]->LeveledAttributes[i].FloatValue * Level);

	}
	return Rating;
}

int AWPlayer::RateSingularItemForJob(FWJob Job,FWInventoryItemBase Item)
{
	int Rating = 0;
	for (int i = 0; i < Item.FixedAttributes.Num(); i++)
	{
		if (Item.FixedAttributes[i].FixedSkill == Job.NeededAttribute1)
			Rating += Item.FixedAttributes[i].IntValue;
		if (Item.FixedAttributes[i].FixedSkill == Job.NeededAttribute2)
			Rating += Item.FixedAttributes[i].IntValue;
		if (Item.FixedAttributes[i].FixedSkill == Job.NeededAttribute3)
			Rating += Item.FixedAttributes[i].IntValue;
		if (Item.FixedAttributes[i].FixedSkill == Job.NeededAttribute4)
			Rating += Item.FixedAttributes[i].IntValue;
		if (Item.FixedAttributes[i].FixedSkill == Job.NeededAttribute5)
			Rating += Item.FixedAttributes[i].IntValue;

		if ((Item.FixedAttributes[i].FixedSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute1))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute2))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute3))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute4))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute5)))
			Rating += Item.FixedAttributes[i].IntValue;

		if ((Item.FixedAttributes[i].FixedSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute1))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute2))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute3))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute4))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute5)))
			Rating += Item.FixedAttributes[i].IntValue;

		if ((Item.FixedAttributes[i].FixedSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute1))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute2))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute3))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute4))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute5)))
			Rating += Item.FixedAttributes[i].IntValue;

		if ((Item.FixedAttributes[i].FixedSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute1))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute2))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute3))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute4))
			|| (Item.FixedAttributes[i].FixedSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute5)))
			Rating += Item.FixedAttributes[i].IntValue;

		if (Item.FixedAttributes[i].FixedSkill == WSkillNames::ExtraWorkPoints)
			Rating += Item.FixedAttributes[i].IntValue;
	}
	for (int i = 0; i < Item.LeveledAttributes.Num(); i++)
	{
		if (Item.LeveledAttributes[i].LeveledSkill == Job.NeededAttribute1)
			Rating += FMath::CeilToInt32(Item.LeveledAttributes[i].FloatValue * Level);
		if (Item.LeveledAttributes[i].LeveledSkill == Job.NeededAttribute2)
			Rating += FMath::CeilToInt32(Item.LeveledAttributes[i].FloatValue * Level);
		if (Item.LeveledAttributes[i].LeveledSkill == Job.NeededAttribute3)
			Rating += FMath::CeilToInt32(Item.LeveledAttributes[i].FloatValue * Level);
		if (Item.LeveledAttributes[i].LeveledSkill == Job.NeededAttribute4)
			Rating += FMath::CeilToInt32(Item.LeveledAttributes[i].FloatValue * Level);
		if (Item.LeveledAttributes[i].LeveledSkill == Job.NeededAttribute5)
			Rating += FMath::CeilToInt32(Item.LeveledAttributes[i].FloatValue * Level);
		if (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::ExtraWorkPoints)
			Rating += FMath::CeilToInt32(Item.LeveledAttributes[i].FloatValue * Level);

		if ((Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute1))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute2))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute3))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute4))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Strength && IsStrengthSkill(Job.NeededAttribute5)))
			Rating += FMath::CeilToInt32(Item.LeveledAttributes[i].FloatValue * Level);

		if ((Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute1))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute2))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute3))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute4))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Mobility && IsMobilitySkill(Job.NeededAttribute5)))
			Rating += FMath::CeilToInt32(Item.LeveledAttributes[i].FloatValue * Level);

		if ((Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute1))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute2))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute3))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute4))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Dexterity && IsDexteritySkill(Job.NeededAttribute5)))
			Rating += FMath::CeilToInt32(Item.LeveledAttributes[i].FloatValue * Level);

		if ((Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute1))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute2))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute3))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute4))
			|| (Item.LeveledAttributes[i].LeveledSkill == WSkillNames::Charisma && IsCharismaSkill(Job.NeededAttribute5)))
			Rating += FMath::CeilToInt32(Item.LeveledAttributes[i].FloatValue * Level);


	}
	return Rating;
}

void AWPlayer::FindBestSlotItemForJob(FWJob Job, EInvSlot Slot)
{
	TArray<int> SlotItems = GetAllItemsForSlot(Slot);


	if (SlotItems.Num() > 0)
	{
		FWInventoryItemBase* SlottedItem = GetItemInSlot(Slot);
		
		int BestIndex = -1;
		int BestRating = 0;

		if (!SlottedItem && Inventory->Items[SlotItems[0]]->MinLevel <= Level)
		{
			BestIndex = SlotItems[0];
			BestRating = RateSingularItemForJob(Job, BestIndex);
		}
		else
		{
			BestRating = RateSingularItemForJob(Job, *SlottedItem);
		}

		for (int i = 1; i < SlotItems.Num(); i++)
		{
			if (Inventory->Items[SlotItems[0]]->MinLevel > Level)
				continue;
			int Rating = BestRating = RateSingularItemForJob(Job, SlotItems[i]);
			if (Rating > BestRating)
			{
				BestRating = Rating;
				BestIndex = SlotItems[i];
			}
		}

		if (BestIndex != -1)
		{
			TakeOn(BestIndex);
		}

	}
}

void AWPlayer::FindBestInventoryForJob(FWJob Job)
{
	FindBestSlotItemForJob(Job, EInvSlot::Hat);
	FindBestSlotItemForJob(Job, EInvSlot::Neck);
	FindBestSlotItemForJob(Job, EInvSlot::Body);
	FindBestSlotItemForJob(Job, EInvSlot::LeftHand);
	FindBestSlotItemForJob(Job, EInvSlot::RightHand);
	FindBestSlotItemForJob(Job, EInvSlot::Belt);
	FindBestSlotItemForJob(Job, EInvSlot::Pants);
	FindBestSlotItemForJob(Job, EInvSlot::Shoes);
	FindBestSlotItemForJob(Job, EInvSlot::Horse);
	FindBestSlotItemForJob(Job, EInvSlot::Product);
}

void AWPlayer::EmptyClothesSkillSet()
{
	ClothesSkills = WSkillSet();
}

void AWPlayer::CalculateClothingForSkillSet(EInvSlot Slot)
{
	FWInventoryItemBase* SlottedItem = GetItemInSlot(Slot);

	for (int i = 0; i < SlottedItem->FixedAttributes.Num(); i++)
	{
		switch (SlottedItem->FixedAttributes[i].FixedSkill)
		{
		case WSkillNames::Strength:
			ClothesSkills.Strength += SlottedItem->FixedAttributes[i].IntValue;
			break;
		case WSkillNames::Mobility:
			ClothesSkills.Mobility += SlottedItem->FixedAttributes[i].IntValue;
			break;
		case WSkillNames::Dexterity:
			ClothesSkills.Dexterity += SlottedItem->FixedAttributes[i].IntValue;
			break;
		case WSkillNames::Charisma:
			ClothesSkills.Charisma += SlottedItem->FixedAttributes[i].IntValue;
			break;
		case WSkillNames::Construction:
			ClothesSkills.Construction += SlottedItem->FixedAttributes[i].IntValue;
			break;
		case WSkillNames::Vigor:
			ClothesSkills.Vigor += SlottedItem->FixedAttributes[i].IntValue;
			break;
		case WSkillNames::Toughness:
			ClothesSkills.Toughness += SlottedItem->FixedAttributes[i].IntValue;
			break;
		case WSkillNames::Stamina:
			ClothesSkills.Stamina += SlottedItem->FixedAttributes[i].IntValue;
			break;
		case WSkillNames::HealthPoints:
			ClothesSkills.HealthPoints += SlottedItem->FixedAttributes[i].IntValue;
			break;
		case WSkillNames::Riding:
			ClothesSkills.Riding += SlottedItem->FixedAttributes[i].IntValue;
			break;
		case WSkillNames::Reflex:
			ClothesSkills.Reflex += SlottedItem->FixedAttributes[i].IntValue;
			break;
		case WSkillNames::Dodging:
			ClothesSkills.Dodging += SlottedItem->FixedAttributes[i].IntValue;
			break;
		case WSkillNames::Hiding:
			ClothesSkills.Hiding += SlottedItem->FixedAttributes[i].IntValue;
			break;
		case WSkillNames::Swimming:
			ClothesSkills.Swimming += SlottedItem->FixedAttributes[i].IntValue;
			break;
		case WSkillNames::Aiming:
			ClothesSkills.Aiming += SlottedItem->FixedAttributes[i].IntValue;
			break;
		case WSkillNames::Shooting:
			ClothesSkills.Shooting += SlottedItem->FixedAttributes[i].IntValue;
			break;
		case WSkillNames::Trapping:
			ClothesSkills.Trapping += SlottedItem->FixedAttributes[i].IntValue;
			break;
		case WSkillNames::FineMotorSkills:
			ClothesSkills.FineMotorSkills += SlottedItem->FixedAttributes[i].IntValue;
			break;
		case WSkillNames::Repairing:
			ClothesSkills.Repairing += SlottedItem->FixedAttributes[i].IntValue;
			break;
		case WSkillNames::Leadership:
			ClothesSkills.Leadership += SlottedItem->FixedAttributes[i].IntValue;
			break;
		case WSkillNames::Tactic:
			ClothesSkills.Tactic += SlottedItem->FixedAttributes[i].IntValue;
			break;
		case WSkillNames::Trading:
			ClothesSkills.Trading += SlottedItem->FixedAttributes[i].IntValue;
			break;
		case WSkillNames::AnimalInstinct:
			ClothesSkills.AnimalInstinct += SlottedItem->FixedAttributes[i].IntValue;
			break;
		case WSkillNames::Appearance:
			ClothesSkills.Appearance += SlottedItem->FixedAttributes[i].IntValue;
			break;

		case WSkillNames::XPPercentage:
			ClothesSkills.XPPercentage += SlottedItem->FixedAttributes[i].FloatValue;
			break;
		case WSkillNames::MoneyPercentage:
			ClothesSkills.MoneyPercentage += SlottedItem->FixedAttributes[i].FloatValue;
			break;
		case WSkillNames::FindingChance:
			ClothesSkills.FindingChance += SlottedItem->FixedAttributes[i].FloatValue;
			break;
		case WSkillNames::Luck:
			ClothesSkills.Luck += SlottedItem->FixedAttributes[i].FloatValue;
			break;
		case WSkillNames::Speed:
			ClothesSkills.Speed += SlottedItem->FixedAttributes[i].FloatValue;
			break;

		case WSkillNames::ExtraWorkPoints:
			ClothesSkills.Appearance += SlottedItem->FixedAttributes[i].IntValue;
			break;
		}
	}

	for (int i = 0; i < SlottedItem->LeveledAttributes.Num(); i++)
	{
		switch (SlottedItem->LeveledAttributes[i].LeveledSkill)
		{
		case WSkillNames::Strength:
			ClothesSkills.Strength += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
			break;
		case WSkillNames::Mobility:
			ClothesSkills.Mobility += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
			break;
		case WSkillNames::Dexterity:
			ClothesSkills.Dexterity += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
			break;
		case WSkillNames::Charisma:
			ClothesSkills.Charisma += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
			break;
		case WSkillNames::Construction:
			ClothesSkills.Construction += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
			break;
		case WSkillNames::Vigor:
			ClothesSkills.Vigor += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
			break;
		case WSkillNames::Toughness:
			ClothesSkills.Toughness += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
			break;
		case WSkillNames::Stamina:
			ClothesSkills.Stamina += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
			break;
		case WSkillNames::HealthPoints:
			ClothesSkills.HealthPoints += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
			break;
		case WSkillNames::Riding:
			ClothesSkills.Riding += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
			break;
		case WSkillNames::Reflex:
			ClothesSkills.Reflex += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
			break;
		case WSkillNames::Dodging:
			ClothesSkills.Dodging += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
			break;
		case WSkillNames::Hiding:
			ClothesSkills.Hiding += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
			break;
		case WSkillNames::Swimming:
			ClothesSkills.Swimming += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
			break;
		case WSkillNames::Aiming:
			ClothesSkills.Aiming += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
			break;
		case WSkillNames::Shooting:
			ClothesSkills.Shooting += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
			break;
		case WSkillNames::Trapping:
			ClothesSkills.Trapping += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
			break;
		case WSkillNames::FineMotorSkills:
			ClothesSkills.FineMotorSkills += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
			break;
		case WSkillNames::Repairing:
			ClothesSkills.Repairing += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
			break;
		case WSkillNames::Leadership:
			ClothesSkills.Leadership += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
			break;
		case WSkillNames::Tactic:
			ClothesSkills.Tactic += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
			break;
		case WSkillNames::Trading:
			ClothesSkills.Trading += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
			break;
		case WSkillNames::AnimalInstinct:
			ClothesSkills.AnimalInstinct += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
			break;
		case WSkillNames::Appearance:
			ClothesSkills.Appearance += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
			break;

		case WSkillNames::XPPercentage:
			ClothesSkills.XPPercentage += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
			break;
		case WSkillNames::MoneyPercentage:
			ClothesSkills.MoneyPercentage += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
			break;
		case WSkillNames::FindingChance:
			ClothesSkills.FindingChance += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
			break;
		case WSkillNames::Luck:
			ClothesSkills.Luck += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
			break;
		case WSkillNames::Speed:
			ClothesSkills.Speed += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
			break;

		case WSkillNames::ExtraWorkPoints:
			ClothesSkills.Appearance += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
			break;
		}
	}
}

void AWPlayer::CalculateClothesSkillSet()
{
	EmptySetSkillSet();

	CalculateClothingForSkillSet(EInvSlot::Hat);
	CalculateClothingForSkillSet(EInvSlot::Neck);
	CalculateClothingForSkillSet(EInvSlot::Body);
	CalculateClothingForSkillSet(EInvSlot::LeftHand);
	CalculateClothingForSkillSet(EInvSlot::RightHand);
	CalculateClothingForSkillSet(EInvSlot::Belt);
	CalculateClothingForSkillSet(EInvSlot::Pants);
	CalculateClothingForSkillSet(EInvSlot::Shoes);
	CalculateClothingForSkillSet(EInvSlot::Horse);
	CalculateClothingForSkillSet(EInvSlot::Product);
}

void AWPlayer::EmptySetSkillSet()
{
	SetSkills = WSkillSet();
}

void AWPlayer::CalculateSetForSkillSet(FString SetName)
{
	int ItemsFound = 0;
	if (GetItemInSlot(EInvSlot::Hat)->IsPartOfSet(SetName)) ItemsFound++;
	if (GetItemInSlot(EInvSlot::Neck)->IsPartOfSet(SetName)) ItemsFound++;
	if (GetItemInSlot(EInvSlot::Body)->IsPartOfSet(SetName)) ItemsFound++;
	if (GetItemInSlot(EInvSlot::LeftHand)->IsPartOfSet(SetName)) ItemsFound++;
	if (GetItemInSlot(EInvSlot::RightHand)->IsPartOfSet(SetName)) ItemsFound++;
	if (GetItemInSlot(EInvSlot::Belt)->IsPartOfSet(SetName)) ItemsFound++;
	if (GetItemInSlot(EInvSlot::Pants)->IsPartOfSet(SetName)) ItemsFound++;
	if (GetItemInSlot(EInvSlot::Shoes)->IsPartOfSet(SetName)) ItemsFound++;
	if (GetItemInSlot(EInvSlot::Horse)->IsPartOfSet(SetName)) ItemsFound++;
	if (GetItemInSlot(EInvSlot::Product)->IsPartOfSet(SetName)) ItemsFound++;

	if (ItemsFound > 0)
	{
		FWSet Set = GameInstance->GameData->FindSet(SetName);

		FWCombinedAttributeList Attributes = Set.CalculateBonuses(ItemsFound);

		FWCombinedAttributeList* SlottedItem = &Attributes;

		for (int i = 0; i < SlottedItem->FixedAttributes.Num(); i++)
		{
			switch (SlottedItem->FixedAttributes[i].FixedSkill)
			{
			case WSkillNames::Strength:
				SetSkills.Strength += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Mobility:
				SetSkills.Mobility += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Dexterity:
				SetSkills.Dexterity += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Charisma:
				SetSkills.Charisma += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Construction:
				SetSkills.Construction += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Vigor:
				SetSkills.Vigor += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Toughness:
				SetSkills.Toughness += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Stamina:
				SetSkills.Stamina += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::HealthPoints:
				SetSkills.HealthPoints += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Riding:
				SetSkills.Riding += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Reflex:
				SetSkills.Reflex += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Dodging:
				SetSkills.Dodging += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Hiding:
				SetSkills.Hiding += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Swimming:
				SetSkills.Swimming += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Aiming:
				SetSkills.Aiming += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Shooting:
				SetSkills.Shooting += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Trapping:
				SetSkills.Trapping += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::FineMotorSkills:
				SetSkills.FineMotorSkills += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Repairing:
				SetSkills.Repairing += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Leadership:
				SetSkills.Leadership += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Tactic:
				SetSkills.Tactic += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Trading:
				SetSkills.Trading += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::AnimalInstinct:
				SetSkills.AnimalInstinct += SlottedItem->FixedAttributes[i].IntValue;
				break;
			case WSkillNames::Appearance:
				SetSkills.Appearance += SlottedItem->FixedAttributes[i].IntValue;
				break;

			case WSkillNames::XPPercentage:
				SetSkills.XPPercentage += SlottedItem->FixedAttributes[i].FloatValue;
				break;
			case WSkillNames::MoneyPercentage:
				SetSkills.MoneyPercentage += SlottedItem->FixedAttributes[i].FloatValue;
				break;
			case WSkillNames::FindingChance:
				SetSkills.FindingChance += SlottedItem->FixedAttributes[i].FloatValue;
				break;
			case WSkillNames::Luck:
				SetSkills.Luck += SlottedItem->FixedAttributes[i].FloatValue;
				break;
			case WSkillNames::Speed:
				SetSkills.Speed += SlottedItem->FixedAttributes[i].FloatValue;
				break;

			case WSkillNames::ExtraWorkPoints:
				SetSkills.Appearance += SlottedItem->FixedAttributes[i].IntValue;
				break;
			}
		}

		for (int i = 0; i < SlottedItem->LeveledAttributes.Num(); i++)
		{
			switch (SlottedItem->LeveledAttributes[i].LeveledSkill)
			{
			case WSkillNames::Strength:
				SetSkills.Strength += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Mobility:
				SetSkills.Mobility += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Dexterity:
				SetSkills.Dexterity += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Charisma:
				SetSkills.Charisma += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Construction:
				SetSkills.Construction += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Vigor:
				SetSkills.Vigor += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Toughness:
				SetSkills.Toughness += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Stamina:
				SetSkills.Stamina += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::HealthPoints:
				SetSkills.HealthPoints += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Riding:
				SetSkills.Riding += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Reflex:
				SetSkills.Reflex += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Dodging:
				SetSkills.Dodging += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Hiding:
				SetSkills.Hiding += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Swimming:
				SetSkills.Swimming += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Aiming:
				SetSkills.Aiming += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Shooting:
				SetSkills.Shooting += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Trapping:
				SetSkills.Trapping += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::FineMotorSkills:
				SetSkills.FineMotorSkills += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Repairing:
				SetSkills.Repairing += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Leadership:
				SetSkills.Leadership += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Tactic:
				SetSkills.Tactic += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Trading:
				SetSkills.Trading += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::AnimalInstinct:
				SetSkills.AnimalInstinct += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Appearance:
				SetSkills.Appearance += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;

			case WSkillNames::XPPercentage:
				SetSkills.XPPercentage += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::MoneyPercentage:
				SetSkills.MoneyPercentage += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::FindingChance:
				SetSkills.FindingChance += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Luck:
				SetSkills.Luck += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			case WSkillNames::Speed:
				SetSkills.Speed += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;

			case WSkillNames::ExtraWorkPoints:
				SetSkills.Appearance += FMath::CeilToInt32(SlottedItem->LeveledAttributes[i].FloatValue * Level);
				break;
			}
		}
	}
}

void AWPlayer::CalculateSetSkillSet()
{
	EmptySetSkillSet();
	TArray<FString> AddedSets;

	TArray<FWInventoryItemBase*> Items = GetSlottedItems();

	for (int i = 0; i < Items.Num(); i++)
	{
		if (Items[i]->IsPartOfSet())
		{
			bool bFound = false;
			for(int j = 0; j < AddedSets.Num(); j++)
				if (Items[i]->SetName.Compare(AddedSets[j]) == 0)
				{
					bFound = true;
					break;
				}

			if (!bFound)
			{
				AddedSets.Add(Items[i]->SetName);
				CalculateSetForSkillSet(Items[i]->SetName);
			}
		}
	}
}
