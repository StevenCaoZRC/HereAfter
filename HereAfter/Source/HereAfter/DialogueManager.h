// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Dialogue.h"
#include "GameFramework/Actor.h"
#include "DialogueManager.generated.h"

UCLASS()
class HEREAFTER_API ADialogueManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADialogueManager();
	UFUNCTION()
		TArray<ADialogue*> GetDialogues();
	UFUNCTION()
		void AddDialogue(FString _Dialogue, bool _bContinue);
	UFUNCTION()
		void SetCurrentDialogue(int _newcurr);
	UFUNCTION()
		ADialogue* GetCurrentDialogue();
	UFUNCTION()
		void IncrementCurrentDialogue();
	UFUNCTION()
		void CompleteCurrentDialogue();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	UPROPERTY()
		ADialogue* CurrentDialogue;
	UPROPERTY()
		TArray<ADialogue*> Dialogues;
	UPROPERTY()
		int iCurrentDialogue = 0;

};
