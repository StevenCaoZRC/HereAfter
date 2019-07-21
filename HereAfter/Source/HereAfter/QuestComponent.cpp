// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestComponent.h"

// Sets default values for this component's properties
UQuestComponent::UQuestComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UQuestComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UQuestComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

UQuestComponent::UQuestComponent(FString _Name, FString _Description, bool _active, bool _completed, bool _repeatable)
{
	sQuestName = _Name;
	sQuestDescription = _Description;
	bActive = _active;
	bCompleted = _completed;
	bRepeatable = _repeatable;
}



FString UQuestComponent::GetName()
{
	return sQuestName;
}


FString UQuestComponent::GetDescription()
{
	return sQuestDescription;
}


bool UQuestComponent::GetActive()
{
	return bActive;
}


bool UQuestComponent::GetCompleted()
{
	return bCompleted;
}


bool UQuestComponent::GetRepeatable()
{
	return bRepeatable;
}


void UQuestComponent::SetActive(bool _active)
{
	bActive = _active;
}


void UQuestComponent::SetCompleted(bool _completed)
{
	bCompleted = _completed;
}


void UQuestComponent::SetRepeatable(bool _repeatable)
{
	bRepeatable = _repeatable;
}

