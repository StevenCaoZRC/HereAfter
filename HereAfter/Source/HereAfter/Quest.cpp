// Fill out your copyright notice in the Description page of Project Settings.


#include "Quest.h"


Quest::Quest(FString _Name, FString _Description, bool _active, bool _completed, bool _repeatable)
{
	sQuestName = _Name;
	sQuestDescription = _Description;
	bActive = _active;
	bCompleted = _completed;
	bRepeatable = _repeatable;
}

Quest::~Quest()
{
}

FString Quest::GetName()
{
	return sQuestName;
}


FString Quest::GetDescription()
{
	return sQuestDescription;
}


bool Quest::GetActive()
{
	return bActive;
}


bool Quest::GetCompleted()
{
	return bCompleted;
}


bool Quest::GetRepeatable()
{
	return bRepeatable;
}


void Quest::SetActive(bool _active)
{
	bActive = _active;
}


void Quest::SetCompleted(bool _completed)
{
	bCompleted = _completed;
}


void Quest::SetRepeatable(bool _repeatable)
{
	bRepeatable = _repeatable;
}
