// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class HEREAFTER_API Quest
{
public:
	Quest(FString _Name, FString _Description);
	~Quest();

private:
	FString sQuestName;
	FString sQuestDescription;
};
