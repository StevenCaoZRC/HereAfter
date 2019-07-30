// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Dialogue.generated.h"

UCLASS()
class HEREAFTER_API ADialogue : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADialogue();
	UFUNCTION()
	void Init(FString _dialogue, bool bContinue);
	UFUNCTION()
	FString GetDialogue();
	UFUNCTION()
	void SetDialogue(FString _dialogue);
	UFUNCTION()
	bool GetContinue();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	UPROPERTY()
		FString Dialogue;
	UPROPERTY()
		bool bContinue = false;

};
