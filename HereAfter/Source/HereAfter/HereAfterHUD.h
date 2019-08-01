// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "HereAfterCharacter.h"
#include "DialogueManager.h"
#include "Engine/Engine.h"
#include "GameFramework/HUD.h"
#include "HereAfterHUD.generated.h"

UCLASS()
class AHereAfterHUD : public AHUD
{
	GENERATED_BODY()

public:
	AHereAfterHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;
	virtual void BeginPlay() override;
	void DisplayDialogue(int _dID, FVector2D _pos);
	UFUNCTION(BlueprintCallable, Category = "Dialogue")
	void Init();
	void ResetDisDialogue();
	UFUNCTION(BlueprintCallable, Category = "Dialogue")
	void SetDialogue(int _dID);

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;
	ADialogueManager* DialogueMan;
	bool bDisplayDialogue = false;
	bool bPlaySound = true;
	int iDialogueID = 0;
	float fRemainingTime = 6.6f;
	UFont* uFont;
	float fTextW;
	float fTextH;
	USoundBase* Voices1;
	USoundBase* Voices2;
	AHereAfterCharacter* Character;
};

