// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Sound/SoundCue.h"
#include "Components/AudioComponent.h"
#include "HereAfterHUD.h"
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
	class UAudioComponent* AmbienceSound;

	UPROPERTY(BlueprintReadOnly, Category = "HUD")
	AHereAfterHUD* HUD;

	AHereAfterCharacter* Character;

	UFUNCTION(BlueprintCallable, Category = "SoundSwitch")
	void SwitchSound();

	USoundCue* PresentAmbiance;
	USoundCue* FutureAmbiance;
	UAudioComponent* PresAmb;
	UAudioComponent* FutAmb;

	bool bPresent = true;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	bool bStart = true;
	bool bWater = true;
	bool bMan = true;
	bool bDeer = true;
	bool bCasket = true;
};
