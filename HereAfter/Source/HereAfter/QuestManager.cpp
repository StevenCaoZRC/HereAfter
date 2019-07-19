// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestManager.h"
#include "Quest.h"

QuestManager::QuestManager()
{
}

QuestManager::~QuestManager()
{
}

std::vector<Quest*> QuestManager::GetQuests()
{
	return Quests;
}


void QuestManager::AddQuest(FString _Name, FString _description, bool _active, bool _completed, bool _repeatable)
{
	Quest* Temp = new Quest(_Name, _description, _active, _completed, _repeatable);
	Quests.push_back(Temp);
}


void QuestManager::SetCurrentQuest(int _newcurr)
{
	iCurrentQuest = _newcurr;
	CurrentQuest = Quests[iCurrentQuest];
}


Quest* QuestManager::GetCurrentQuest()
{
	return CurrentQuest;
}