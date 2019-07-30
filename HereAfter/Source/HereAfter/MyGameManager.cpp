// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameManager.h"
#include "Engine/Engine.h"
#include "Engine/World.h"

// Sets default values
AMyGameManager::AMyGameManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;



	
	
}

// Called when the game starts or when spawned
void AMyGameManager::BeginPlay()
{
	Super::BeginPlay();

	QuestMan = GetWorld()->SpawnActor<AQuestManager>(AQuestManager::StaticClass());
	

	
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

// Called every frame
void AMyGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

