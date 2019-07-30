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
	static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("/Game/FirstPerson/Textures/FirstPersonCrosshair"));
	CrosshairTex = CrosshairTexObj.Object;
	static ConstructorHelpers::FObjectFinder<UFont> FontObject(TEXT("/Game/FirstPerson/Fonts/HTOWERT_Font"));
	uFont = FontObject.Object;
}

void AHereAfterHUD::BeginPlay()
{
	Super::BeginPlay();
	Init();
	DialogueMan = GetWorld()->SpawnActor<ADialogueManager>(ADialogueManager::StaticClass());
	DialogueMan->AddDialogue("GET MY SHIT, YOU FUCKING BASTARD!");
	DialogueMan->AddDialogue("WHERE MY SHIT, YOU FUCKING BASTARD?");
	bDisplayDialogue = true;
}

void AHereAfterHUD::DisplayDialogue(int _dID, FVector2D _pos)
{
	if (bDisplayDialogue == true)
	{
		GetTextSize((TEXT("%s"), *FString(DialogueMan->GetDialogues()[1]->GetDialogue())), fTextW, fTextH, uFont, 1.5f);
		DrawText((TEXT("%s"), *FString(DialogueMan->GetDialogues()[_dID]->GetDialogue())), FLinearColor::White, _pos.X - (fTextW/2), _pos.Y, uFont, 1.5f, false);
	}

	fRemainingTime = fRemainingTime - GetWorld()->DeltaTimeSeconds;

	if (fRemainingTime <= 0 && bDisplayDialogue == true)
	{
		fRemainingTime = 5.0f;
		bDisplayDialogue = false;
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

	DisplayDialogue(1, CenterBottom);

	// draw the crosshair
	
	FCanvasTileItem TileItem( CrosshairDrawPosition, CrosshairTex->Resource, FLinearColor::White);
	TileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem( TileItem );
	
}
