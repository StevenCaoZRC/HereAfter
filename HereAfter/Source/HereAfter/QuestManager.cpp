// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestManager.h"
#include "Quest.h"
#include "Engine/World.h"

// Sets default values
AQuestManager::AQuestManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AQuestManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AQuestManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

TArray<AQuest*> AQuestManager::GetQuests()
{
	return Quests;
}


void AQuestManager::AddQuest(FString _Name, FString _description, bool _active, bool _completed, bool _repeatable)
{
	AQuest* Temp = GetWorld()->SpawnActor<AQuest>(AQuest::StaticClass());
	Temp->Init(_Name, _description, _active, _completed, _repeatable);

	Quests.Push(Temp);
}


void AQuestManager::SetCurrentQuest(int _newcurr)
{
	if (CurrentQuest != NULL)
	{
		CurrentQuest->SetActive(false);
	}
	iCurrentQuest = _newcurr;
	CurrentQuest = Quests[iCurrentQuest];
	CurrentQuest->SetActive(true);
}


AQuest* AQuestManager::GetCurrentQuest()
{
	return CurrentQuest;
}

void AQuestManager::IncrementCurrentQuest()
{

	if (Quests[iCurrentQuest] != NULL)
	{
		iCurrentQuest++;
		SetCurrentQuest(iCurrentQuest);
	}
}

void AQuestManager::CompleteCurrentQuest()
{
	if (CurrentQuest->GetCompleted() != true)
	{
		CurrentQuest->SetCompleted(true);
	}
	IncrementCurrentQuest();
}

