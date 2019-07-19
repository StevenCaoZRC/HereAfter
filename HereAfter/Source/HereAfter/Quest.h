// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <string>

/**
 * 
 */
class HEREAFTER_API Quest
{
public:
	Quest(FString _Name, FString _Description, bool _active, bool _completed, bool _repeatable);
	FString GetName();
	FString GetDescription();
	bool GetActive();
	bool GetCompleted();
	bool GetRepeatable();
	void SetActive(bool _active);
	void SetCompleted(bool _completed);
	void SetRepeatable(bool _repeatable);
	~Quest();

private:
	FString sQuestName;
	FString sQuestDescription;
	bool bActive;
	bool bCompleted;
	bool bRepeatable;
};
