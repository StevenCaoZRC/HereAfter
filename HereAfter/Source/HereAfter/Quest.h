// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Quest.generated.h"

UCLASS()
class HEREAFTER_API AQuest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AQuest();
	UFUNCTION()
		void Init(FString _Name, FString _Description, bool _active, bool _completed, bool _repeatable);
	UFUNCTION(BlueprintCallable, Category = "Quest")
		FString GetName();
	UFUNCTION()
		FString GetDescription();
	UFUNCTION()
		bool GetActive();
	UFUNCTION(BlueprintCallable, Category = "Quest")
		bool GetCompleted();
	UFUNCTION()
		bool GetRepeatable();
	UFUNCTION()
		void SetActive(bool _active);
	UFUNCTION(BlueprintCallable, Category = "Quest")
		void SetCompleted(bool _completed);
	UFUNCTION()
		void SetRepeatable(bool _repeatable);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

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
