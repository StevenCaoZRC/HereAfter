// Fill out your copyright notice in the Description page of Project Settings.


#include "Quest.h"

// Sets default values
AQuest::AQuest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AQuest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AQuest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AQuest::Init(FString _Name, FString _Description, bool _active, bool _completed, bool _repeatable)
{
	sQuestName = _Name;
	sQuestDescription = _Description;
	bActive = _active;
	bCompleted = _completed;
	bRepeatable = _repeatable;
}



FString AQuest::GetName()
{
	return sQuestName;
}


FString AQuest::GetDescription()
{
	return sQuestDescription;
}


bool AQuest::GetActive()
{
	return bActive;
}


bool AQuest::GetCompleted()
{
	return bCompleted;
}


bool AQuest::GetRepeatable()
{
	return bRepeatable;
}


void AQuest::SetActive(bool _active)
{
	bActive = _active;
}


void AQuest::SetCompleted(bool _completed)
{
	bCompleted = _completed;
}


void AQuest::SetRepeatable(bool _repeatable)
{
	bRepeatable = _repeatable;
}

