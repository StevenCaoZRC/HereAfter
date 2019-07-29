// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
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
	void DisplayDialogue(int _dID);
	void Init();

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;
	ADialogueManager* DialogueMan;
	bool bDisplayDialogue;
	int iDialogueID;
	ADialogue* CurrentDialogue;
	float fRemainingTime = 5.0f;
	UFont* uFont;

};

