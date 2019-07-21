// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <vector>

#include "CoreMinimal.h"
#include "QuestComponent.h"
#include "Components/ActorComponent.h"
#include "QuestMan.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HEREAFTER_API UQuestMan : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UQuestMan();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
		std::vector<UQuestComponent*> GetQuests();
	UFUNCTION()
		void AddQuest(FString _Name, FString _description, bool _active, bool _completed, bool _repeatable);
	UFUNCTION()
		void SetCurrentQuest(int _newcurr);
	UFUNCTION()
		class UQuestComponent* GetCurrentQuest();
private:
	UPROPERTY()
		class UQuestComponent* CurrentQuest;
	UPROPERTY()
		std::vector<UQuestComponent*> Quests;
	UPROPERTY()
		int iCurrentQuest = 0;

		
};
