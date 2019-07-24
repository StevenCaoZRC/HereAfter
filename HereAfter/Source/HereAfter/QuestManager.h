// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Quest.h"
#include "GameFramework/Actor.h"
#include "QuestManager.generated.h"

UCLASS()
class HEREAFTER_API AQuestManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AQuestManager();
	UFUNCTION()
		TArray<AQuest*> GetQuests();
	UFUNCTION()
		void AddQuest(FString _Name, FString _description, bool _active, bool _completed, bool _repeatable);
	UFUNCTION()
		void SetCurrentQuest(int _newcurr);
	UFUNCTION()
		AQuest* GetCurrentQuest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY()
		AQuest* CurrentQuest;
	UPROPERTY()
		TArray<AQuest*> Quests;
	UPROPERTY()
		int iCurrentQuest = 0;

};
