// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Quest.h"
#include <vector>

/**
 * 
 */
class HEREAFTER_API QuestManager
{
public:
	QuestManager();
	~QuestManager();

	std::vector<Quest*> GetQuests();
	void AddQuest(FString _Name, FString _description, bool _active, bool _completed, bool _repeatable);
	void SetCurrentQuest(int _newcurr);
	Quest* GetCurrentQuest();

private:
	Quest* CurrentQuest;
	std::vector<Quest*> Quests;
	int iCurrentQuest = 0;
};
