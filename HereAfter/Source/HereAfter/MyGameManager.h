// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HereAfterCharacter.h"
#include "QuestManager.h"
#include "GameFramework/Actor.h"
#include "MyGameManager.generated.h"

UCLASS()
class HEREAFTER_API AMyGameManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyGameManager();
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "QuestManager")
		AQuestManager* QuestMan;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	class USoundBase* AmbienceSound;

	AHereAfterCharacter* Character;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	

};
