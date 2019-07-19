// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameManager.h"

// Sets default values
AMyGameManager::AMyGameManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	QuestMan = new QuestManager();
	QuestMan->AddQuest("Get Water", "Traverse the woods to find the water", false, false, false);
	QuestMan->AddQuest("Get Dirt", "Traverse the woods to find the dirt", false, false, false);
	QuestMan->AddQuest("Get Schwifty", "Traverse the woods to find Mr Bulldops", false, false, false);
	QuestMan->AddQuest("Get Box", "Traverse the woods to find the box", false, false, false);
	QuestMan->AddQuest("Get Shyamalaned", "Traverse the woods to find the twist", false, false, false);
}

// Called when the game starts or when spawned
void AMyGameManager::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

