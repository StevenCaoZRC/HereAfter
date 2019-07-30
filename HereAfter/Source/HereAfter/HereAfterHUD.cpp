// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "HereAfterHUD.h"
#include "Engine/World.h"
#include "Engine/Canvas.h"
#include "Engine/Texture2D.h"
#include "TextureResource.h"
#include "CanvasItem.h"
#include "UObject/ConstructorHelpers.h"

AHereAfterHUD::AHereAfterHUD()
{
	// Set the crosshair texture
	static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("/Game/FirstPerson/Textures/T_Dot"));
	CrosshairTex = CrosshairTexObj.Object;
	static ConstructorHelpers::FObjectFinder<UFont> FontObject(TEXT("/Game/FirstPerson/Fonts/HTOWERT_Font"));
	uFont = FontObject.Object;
}

void AHereAfterHUD::BeginPlay()
{
	Super::BeginPlay();
	Init();
	DialogueMan = GetWorld()->SpawnActor<ADialogueManager>(ADialogueManager::StaticClass());
	DialogueMan->AddDialogue("Hello Traveller. What luck that you should appear here.", true);
	DialogueMan->AddDialogue("Please, come closer. I wish to show you something.", false);
	DialogueMan->AddDialogue("I am the guardian of this forest. It has been my home for many years", true);
	DialogueMan->AddDialogue("My roots run deep here, caring for all creatures that inhabit this place.", false);
	DialogueMan->AddDialogue("But we are under threat. This is a vision of the future - our future.", true);
	DialogueMan->AddDialogue("This beautiful place will become nothing but ash if we do not stop it.", true);
	DialogueMan->AddDialogue("All the beauty, all the life will be gone.", false);
	DialogueMan->AddDialogue("I need your help. Together we can prevent this future from unfolding.", false);
	DialogueMan->AddDialogue("Four items lie in this forest: some here, and some in the future", true);
	DialogueMan->AddDialogue("I can grant you the ability to step between there worlds...", true);
	DialogueMan->AddDialogue("... but you must promise me that you will endeavour to save us.", false);
	DialogueMan->AddDialogue("Our fate is in your hands. Only you can stop this.", true);
	DialogueMan->AddDialogue("Thank you, Traveller.", false);

	bDisplayDialogue = true;
}

void AHereAfterHUD::DisplayDialogue(int _dID, FVector2D _pos)
{
	if (bDisplayDialogue == true)
	{
		GetTextSize((TEXT("%s"), *FString(DialogueMan->GetDialogues()[_dID]->GetDialogue())), fTextW, fTextH, uFont, 2.0f);
		DrawText((TEXT("%s"), *FString(DialogueMan->GetDialogues()[_dID]->GetDialogue())), FLinearColor::White, _pos.X - (fTextW/2), _pos.Y + 200, uFont, 2.0f, false);
	}

	if (fRemainingTime <= 0 && bDisplayDialogue == true)
	{
		fRemainingTime = 5.0f;

		if (DialogueMan->GetDialogues()[_dID]->GetContinue())
		{
			bDisplayDialogue = true;
		}
		else
		{
			bDisplayDialogue = false;
		}

		if (iDialogueID != DialogueMan->GetDialogues().Num() - 1)
		{
			iDialogueID++;
		}
		else
		{
			iDialogueID = 0;
		}
		
	}
}

void AHereAfterHUD::ResetDisDialogue()
{
	fRemainingTime = fRemainingTime - GetWorld()->DeltaTimeSeconds;

	if (fRemainingTime <= 0 && bDisplayDialogue == false)
	{
		fRemainingTime = 5.0f;
		bDisplayDialogue = true;

	}
}

void AHereAfterHUD::Init()
{
	

}

void AHereAfterHUD::DrawHUD()
{
	Super::DrawHUD();

	// Draw very simple crosshair

	// find center of the Canvas
	const FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);
	const FVector2D CenterBottom(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

	// offset by half the texture's dimensions so that the center of the texture aligns with the center of the Canvas
	const FVector2D CrosshairDrawPosition( (Center.X),
										   (Center.Y + 20.0f));

	DisplayDialogue(iDialogueID, CenterBottom);
	ResetDisDialogue();

	// draw the crosshair
<<<<<<< HEAD
	
	//FCanvasTileItem TileItem( CrosshairDrawPosition, CrosshairTex->Resource, FLinearColor::White);
	//TileItem.BlendMode = SE_BLEND_Translucent;
	//Canvas->DrawItem( TileItem );
	
=======
	//FCanvasTileItem TileItem( CrosshairDrawPosition, CrosshairTex->Resource, FLinearColor::White);
	//TileItem.BlendMode = SE_BLEND_Translucent;
	//Canvas->DrawItem( TileItem );
>>>>>>> develop
}
