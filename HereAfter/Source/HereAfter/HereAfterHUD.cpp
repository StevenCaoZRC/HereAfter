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
	

	bDisplayDialogue = true;
}

void AHereAfterHUD::DisplayDialogue(int _dID, FVector2D _pos)
{
	if (bDisplayDialogue == true)
	{
		GetTextSize((TEXT("%s"), *FString(DialogueMan->GetDialogues()[_dID]->GetDialogue())), fTextW, fTextH, uFont, 1.0f);
		DrawText((TEXT("%s"), *FString(DialogueMan->GetDialogues()[_dID]->GetDialogue())), FLinearColor::White, _pos.X - (fTextW/2), _pos.Y, uFont, 1.0f, false);
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

void AHereAfterHUD::SetDialogue(int _dID)
{

}

void AHereAfterHUD::Init()
{
	//uFont

	DialogueMan = GetWorld()->SpawnActor<ADialogueManager>(ADialogueManager::StaticClass());
	//Start of the game
	DialogueMan->AddDialogue("Hello Traveller. What luck that you should appear here.", true); //0
	DialogueMan->AddDialogue("Please, come closer. I wish to show you something.", false); //1
	DialogueMan->AddDialogue("I am the guardian of this forest. It has been my home for many years", true); //2
	DialogueMan->AddDialogue("My roots run deep here, caring for all creatures that inhabit this place.", false); //3
	DialogueMan->AddDialogue("But we are under threat. This is a vision of the future - our future.", true); //4
	DialogueMan->AddDialogue("This beautiful place will become nothing but ash if we do not stop it.", true); //5
	DialogueMan->AddDialogue("All the beauty, all the life will be gone.", false); //6
	DialogueMan->AddDialogue("I need your help. Together we can prevent this future from unfolding.", false); //7
	DialogueMan->AddDialogue("Four items lie in this forest: some here, and some in the future", true); //8
	DialogueMan->AddDialogue("I can grant you the ability to step between there worlds...", true); //9
	DialogueMan->AddDialogue("... but you must promise me that you will endeavour to save us.", false); //10
	DialogueMan->AddDialogue("Use the power of stepping between now and the future to find these items.", true); //11
	DialogueMan->AddDialogue("If you are stuck, it will help your journey", true); //12
	DialogueMan->AddDialogue("Time has a way of dissolving even the most immovable of obstacles", true); //13
	DialogueMan->AddDialogue("While sometimes creating ones of its own.", false); //14
	DialogueMan->AddDialogue("Our fate is in your hands. Only you can stop this.", true); //15
	DialogueMan->AddDialogue("Thank you, Traveller.", false); //16
	//Well Water
	DialogueMan->AddDialogue("Sees no light, makes no sound.", true); //17
	DialogueMan->AddDialogue("A river courses deep underground.", false); //18

	DialogueMan->AddDialogue("The soil here crumbles and can no longer sustain me.", true); //19
	DialogueMan->AddDialogue("You must seek a vial of the clearest, purest water from a well deep in the woods.", false); //20
	//Mandrake
	DialogueMan->AddDialogue("Those who toil in winter are joyous in spring.", true); //21
	DialogueMan->AddDialogue("As the world ripens for harvesting.", false); //22
	DialogueMan->AddDialogue("All plants can be eaten; but some, only once.", true); //23
	DialogueMan->AddDialogue("The forest’s bounty knows no bounds:", true); //24
	DialogueMan->AddDialogue("life-giving herbs coexist with deadly poisons.", true); //25
	DialogueMan->AddDialogue("I require a very specific cultivar of the Mandragora plant.", true); //26
	DialogueMan->AddDialogue("A farm lies ahead, but has been untended for many moons.", true); //27
	DialogueMan->AddDialogue("There, you may find what I need.", false); //28
	//Deer
	DialogueMan->AddDialogue("Two windows to the world, two windows to the soul.", true); //29
	DialogueMan->AddDialogue("Bring me what houses the mind of a doe.", true); //30
	DialogueMan->AddDialogue("Life, death, and time. All things are fated, Traveller.", true); //31
	DialogueMan->AddDialogue("Yet some fates we can change.", true); //32
	DialogueMan->AddDialogue("Remember the death that will befall this realm if we cannot alter the course of destiny. ", true); //33
	DialogueMan->AddDialogue("Please do not fail me now.", false); //34
	//Bridge and the box
	DialogueMan->AddDialogue("In the earth my casket lies buried below.", true); //35
	DialogueMan->AddDialogue("But fear not, for now it holds only curios.", false); //36
	DialogueMan->AddDialogue("You are close to the end, Traveller. I have but one item left for you to retrieve.", true); //37
	DialogueMan->AddDialogue("Long ago, I sealed a precious talisman away in a charmed safebox.", true); //38
	DialogueMan->AddDialogue("This was stolen from me and buried past the edge of the forest’s realm.", false); //39
	DialogueMan->AddDialogue("I feel its power emanating near where the river runs…", false); //40
	DialogueMan->AddDialogue("Bring my casket back, so that I may unseal it and ensure this forest shall never fall to ruin.", false); //41
	//Out of bounds
	DialogueMan->AddDialogue("Traveller, do not forget your pact.", false); //42
	DialogueMan->AddDialogue("The woods can hide treachery in their depths...", false); //43
	//Once all items are collected
	DialogueMan->AddDialogue("Traveller! You have found all I need.", false); //44
	DialogueMan->AddDialogue("Quickly, return to me. The future beckons.", false); //45
	//Once you are back at the tree
	DialogueMan->AddDialogue("Ahhh… at last.", false); //46
	DialogueMan->AddDialogue("You have done well, Traveller. Because of you, I may return to my true form.", false); //47
	DialogueMan->AddDialogue("Oh? Indeed, I was not always inhabiting this tree.", false); //48
	DialogueMan->AddDialogue("No, Traveller, I once walked these woods just as you have.", false); //49
	DialogueMan->AddDialogue("I lived here peacefully: brewing, divining, enchanting.", false); //50
	DialogueMan->AddDialogue("Occasionally outsiders such as yourself would cross the threshold", false); //51
	DialogueMan->AddDialogue("where the forest would shine upon them and I would gift elixirs and carve sigils for luck upon their saddles.", false); //52
	DialogueMan->AddDialogue("But one day I was found.", false); //53
	DialogueMan->AddDialogue("Tales had spread, and they came for me with dogs and torches.", false); //54
	DialogueMan->AddDialogue("They stabbed me as I slept, and threw my body under the floorboards of my own home.", false); //55
	DialogueMan->AddDialogue("Yet they did not know the true extent of my powers.", false); //56
	DialogueMan->AddDialogue("While my body and blood melted into the earth", false); //57
	DialogueMan->AddDialogue("My rage was sown into the forest to take root and grow stronger.", false); //58
	DialogueMan->AddDialogue("Years have passed...", false); //59
	DialogueMan->AddDialogue("And I have lain here...", false); //60
	DialogueMan->AddDialogue("Communing with the Old Ones...", false); //61
	DialogueMan->AddDialogue("Biding my time...", false); //62
	DialogueMan->AddDialogue("Waiting to bloom...", false); //63
	DialogueMan->AddDialogue("Waiting…", false); //64
	DialogueMan->AddDialogue("for you.", false); //65
	DialogueMan->AddDialogue("The precious talisman I hid in that casket…", false); //66
	DialogueMan->AddDialogue("Please open it.", false); //67
	//Open Box
	DialogueMan->AddDialogue("My ceremonial dagger, hidden all those years ago.", true); //68
	DialogueMan->AddDialogue("With this knife, our fate will be sealed.", true); //69
	DialogueMan->AddDialogue("As I gave my blood for the forest, give your blood to me.", true); //70
	DialogueMan->AddDialogue("Your life will seed the strength to manifest my true form.", false); //71

	DialogueMan->AddDialogue("Do not fear - we can rule together.", true); //72
	DialogueMan->AddDialogue("The power I can afford you is greater than any human conception.", true); //73
	DialogueMan->AddDialogue("Your heart is pure, and fit to be rewarded.", false); //74

	DialogueMan->AddDialogue("This is your final challenge, Traveller.", true); //75
	DialogueMan->AddDialogue("Water, earth, bone - and blood.", false);//76
	//Go to door and open it
	DialogueMan->AddDialogue("Traveller! What deceit is this?", true);//77
	DialogueMan->AddDialogue("No matter.", true);//78
	DialogueMan->AddDialogue("You were never important anyway - nothing but a pawn in my machinations.", true);//79
	DialogueMan->AddDialogue("Your insolence will not stop me.", true);//80
	DialogueMan->AddDialogue("Your blood shall be spilled either way.", false);//81


	DialogueMan->AddDialogue("I shall take this wretched planet back from those who wronged me and craft it into an altar for the Old Ones.", true);//82
	DialogueMan->AddDialogue("Why should those who trample and rampage through these woods be allowed to live?", true);//83
	DialogueMan->AddDialogue("Gaze upon my fearsome glory as my leaves block out the sun!", true);//84
	DialogueMan->AddDialogue("None shall be spared! ", false);//85
	//Go to campfire pick up torch
	DialogueMan->AddDialogue("No!", true);//86
	DialogueMan->AddDialogue("NO!", true);//87
	DialogueMan->AddDialogue("The future is mine!", false);//88

}

void AHereAfterHUD::DrawHUD()
{
	Super::DrawHUD();

	// Draw very simple crosshair

	// find center of the Canvas
	const FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);
	const FVector2D CenterBottom(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.85f);

	// offset by half the texture's dimensions so that the center of the texture aligns with the center of the Canvas
	const FVector2D CrosshairDrawPosition( (Center.X),
										   (Center.Y + 20.0f));

	DisplayDialogue(iDialogueID, CenterBottom);
	ResetDisDialogue();

	// draw the crosshair

	
	//FCanvasTileItem TileItem( CrosshairDrawPosition, CrosshairTex->Resource, FLinearColor::White);
	//TileItem.BlendMode = SE_BLEND_Translucent;
	//Canvas->DrawItem( TileItem );
}
