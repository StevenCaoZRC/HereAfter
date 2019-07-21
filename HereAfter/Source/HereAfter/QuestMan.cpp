// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestMan.h"

// Sets default values for this component's properties
UQuestMan::UQuestMan()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UQuestMan::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UQuestMan::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

std::vector<UQuestComponent*> UQuestMan::GetQuests()
{
	return Quests;
}


void UQuestMan::AddQuest(FString _Name, FString _description, bool _active, bool _completed, bool _repeatable)
{
	UQuestComponent* Temp = new UQuestComponent(_Name, _description, _active, _completed, _repeatable);
	Quests.push_back(Temp);
}


void UQuestMan::SetCurrentQuest(int _newcurr)
{
	iCurrentQuest = _newcurr;
	CurrentQuest = Quests[iCurrentQuest];
}


UQuestComponent* UQuestMan::GetCurrentQuest()
{
	return CurrentQuest;
}
