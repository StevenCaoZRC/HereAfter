// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "QuestComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HEREAFTER_API UQuestComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UQuestComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	UQuestComponent(FString _Name, FString _Description, bool _active, bool _completed, bool _repeatable);
	UFUNCTION()
		FString GetName();
	UFUNCTION()
		FString GetDescription();
	UFUNCTION()
		bool GetActive();
	UFUNCTION()
		bool GetCompleted();
	UFUNCTION()
		bool GetRepeatable();
	UFUNCTION()
		void SetActive(bool _active);
	UFUNCTION()
		void SetCompleted(bool _completed);
	UFUNCTION()
		void SetRepeatable(bool _repeatable);

private:
	UPROPERTY()
		FString sQuestName;
	UPROPERTY()
		FString sQuestDescription;
	UPROPERTY()
		bool bActive;
	UPROPERTY()
		bool bCompleted;
	UPROPERTY()
		bool bRepeatable;

		
};
