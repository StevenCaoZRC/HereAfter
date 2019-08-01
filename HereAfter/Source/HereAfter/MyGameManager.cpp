// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameManager.h"

#include "Engine/Engine.h"
#include "Engine/World.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMyGameManager::AMyGameManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<USoundCue> Sound1(TEXT("/Game/FirstPerson/Audio/Amb1"));
	PresentAmbiance = Sound1.Object;
	static ConstructorHelpers::FObjectFinder<USoundCue> Sound2(TEXT("/Game/FirstPerson/Audio/Amb2"));
	FutureAmbiance = Sound2.Object;

}

// Called when the game starts or when spawned
void AMyGameManager::BeginPlay()
{
	Super::BeginPlay();

	PresAmb = UGameplayStatics::SpawnSound2D(this, PresentAmbiance);
	

	//FutAmb->Stop();

	QuestMan = GetWorld()->SpawnActor<AQuestManager>(AQuestManager::StaticClass());
	HUD = Cast<AHereAfterHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
	Character = Cast<AHereAfterCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	
	QuestMan->AddQuest("WaterQuest", "Collect a vial of well water", false, false, false);
	QuestMan->AddQuest("PlantQuest", "Retrieve a Mandragora", false, false, false);
	QuestMan->AddQuest("DeerQuest", "Find doe", false, false, false);
	QuestMan->AddQuest("BoxQuest", "Unearth casket", false, false, false);
	//QuestMan->AddQuest("Get Shyamalaned", "Traverse the woods to find the twist", false, false, false); 
	/*QuestMan->AddQuest("Get Water", "Traverse the woods to find the water", true, false, false);
	QuestMan->AddQuest("Get Dirt", "Traverse the woods to find the dirt", false, false, false);
	QuestMan->AddQuest("Get Schwifty", "Traverse the woods to find Mr Bulldops", false, false, false);
	QuestMan->AddQuest("Get Box", "Traverse the woods to find the box", false, false, false);
	QuestMan->AddQuest("Get Shyamalaned", "Traverse the woods to find the twist", false, false, false);*/
	QuestMan->SetCurrentQuest(0);

	

	

	
	for (int i = 0; i < QuestMan->GetQuests().Num(); i++)
	{
		UE_LOG(LogTemp, Log, TEXT("Quest Name:  %s"), *FString(QuestMan->GetQuests()[i]->GetName()));
		UE_LOG(LogTemp, Log, TEXT("Quest Description:  %s"), *FString(QuestMan->GetQuests()[i]->GetDescription()));
	}
	
}

void AMyGameManager::SwitchSound()
{
	if (bPresent == true)
	{
		PresAmb->Stop();
		FutAmb = UGameplayStatics::SpawnSound2D(this, FutureAmbiance);
		bPresent = false;
	}
	else
	{
		PresAmb = UGameplayStatics::SpawnSound2D(this, PresentAmbiance);
		FutAmb->Stop();
	}
}

// Called every frame
void AMyGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bStart)
	{
		HUD->SetDialogue(0);
		bStart = false;
	}
	if (!bStart && bWater && QuestMan->GetQuests()[0]->GetCompleted())
	{
		HUD->SetDialogue(28);
		bWater = false;
	}
	if (!bStart && !bWater && bMan && QuestMan->GetQuests()[1]->GetCompleted())
	{
		HUD->SetDialogue(37);
		bMan = false;
	}
	if (!bStart && !bWater && !bMan && bDeer && QuestMan->GetQuests()[2]->GetCompleted())
	{
		HUD->SetDialogue(44);
		bDeer = false;
	}
	if (!bStart && !bWater && !bMan && !bDeer && bCasket && QuestMan->GetQuests()[3]->GetCompleted())
	{
		HUD->SetDialogue(56);
		bCasket = false;
	}
	
	

}

