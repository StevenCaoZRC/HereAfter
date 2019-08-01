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
	static ConstructorHelpers::FObjectFinder<USoundBase> Whis1(TEXT("/Game/FirstPerson/Audio/Whispering1"));
	Voices1 = Whis1.Object;
	static ConstructorHelpers::FObjectFinder<USoundBase> Whis2(TEXT("/Game/FirstPerson/Audio/Whispering2"));
	Voices2 = Whis2.Object;
}

void AHereAfterHUD::BeginPlay()
{
	Super::BeginPlay();
	Character = Cast<AHereAfterCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	Init();
	
	SetDialogue(56);
}

void AHereAfterHUD::DisplayDialogue(int _dID, FVector2D _pos)
{
	if (bDisplayDialogue == true)
	{
		GetTextSize((TEXT("%s"), *FString(DialogueMan->GetDialogues()[_dID]->GetDialogue())), fTextW, fTextH, uFont, 1.0f);
		DrawText((TEXT("%s"), *FString(DialogueMan->GetDialogues()[_dID]->GetDialogue())), FLinearColor::White, _pos.X - (fTextW/2), _pos.Y, uFont, 1.0f, false);
		fRemainingTime = fRemainingTime - GetWorld()->DeltaTimeSeconds;

		if (bPlaySound)
		{
			if (Voices1 != NULL && Voices2!=NULL)
			{
				int temp = FMath::RandRange(1, 2);

				if (temp == 1)
				{
					UGameplayStatics::SpawnSoundAtLocation(Character, Voices1, Character->GetActorLocation());
				}
				else
				{
					UGameplayStatics::SpawnSoundAtLocation(Character, Voices2, Character->GetActorLocation());
				}

				
			}
			bPlaySound = false;
		}

		
	}

	if (fRemainingTime <= 0 && bDisplayDialogue == true)
	{
		
		fRemainingTime = 6.6f;

		if (iDialogueID != DialogueMan->GetDialogues().Num() - 1)
		{
			iDialogueID++;
		}
		else
		{
			iDialogueID = 114;
		}

		if (DialogueMan->GetDialogues()[_dID]->GetContinue())
		{
			bDisplayDialogue = true;
			if (DialogueMan->GetDialogues()[iDialogueID]->GetTalking())
			{
				bPlaySound = true;
			}
		}
		else
		{
			bDisplayDialogue = false;
			bPlaySound = true;

		}
	}
}

void AHereAfterHUD::ResetDisDialogue()
{
	
	if (fRemainingTime <= 0 && bDisplayDialogue == false)
	{
		fRemainingTime = 6.6f;
		bDisplayDialogue = true;

	}
}

void AHereAfterHUD::SetDialogue(int _dID)
{
	if (iDialogueID <= DialogueMan->GetDialogues().Num() - 1)
	{
		iDialogueID = _dID;
		bDisplayDialogue = true;
	}
}

void AHereAfterHUD::Init()
{
	//uFont

	DialogueMan = GetWorld()->SpawnActor<ADialogueManager>(ADialogueManager::StaticClass());
	//Start of the game
	DialogueMan->AddDialogue("Hello Traveller. What luck that you should appear here.", true, true); //0
	DialogueMan->AddDialogue("Please, come closer. I wish to show you something.", true, true); //1
	DialogueMan->AddDialogue("", true, false);//2
	DialogueMan->AddDialogue("I am the guardian of this forest. It has been my home for many years", true, true); //3
	DialogueMan->AddDialogue("My roots run deep here, caring for all creatures that inhabit this place.", false, true); //4
	DialogueMan->AddDialogue("Press 'Q' to Time Jump", false, false);//5
	DialogueMan->AddDialogue("But we are under threat. This is a vision of the future - our future.", true, true); //6
	DialogueMan->AddDialogue("This beautiful place will become nothing but ash if we do not stop it.", true, true); //7
	DialogueMan->AddDialogue("All the beauty, all the life will be gone.", true, true); //8
	DialogueMan->AddDialogue("", true, false);//9
	DialogueMan->AddDialogue("I need your help. Together we can prevent this future from unfolding.", true, true); //10
	DialogueMan->AddDialogue("", true, false);//11
	DialogueMan->AddDialogue("Four items lie in this forest: some here, and some in the future", true, true); //12
	DialogueMan->AddDialogue("I can grant you the ability to step between there worlds...", true, true); //13
	DialogueMan->AddDialogue("... but you must promise me that you will endeavour to save us.", true, true); //14
	DialogueMan->AddDialogue("", true, false);//15
	DialogueMan->AddDialogue("Use the power of stepping between now and the future to find these items.", true, true); //16
	DialogueMan->AddDialogue("If you are stuck, it will help your journey", true, true); //17
	DialogueMan->AddDialogue("Time has a way of dissolving even the most immovable of obstacles", true, true); //18
	DialogueMan->AddDialogue("While sometimes creating ones of its own.", true, true); //19
	DialogueMan->AddDialogue("", true, false);//20
	DialogueMan->AddDialogue("Our fate is in your hands. Only you can stop this.", true, true); //21
	DialogueMan->AddDialogue("Thank you, Traveller.", false, true);//22
	//Well Water
	DialogueMan->AddDialogue("Sees no light, makes no sound.", true, true); //23
	DialogueMan->AddDialogue("A river courses deep underground.", true, true); //24
	DialogueMan->AddDialogue("", true, false);//25
	DialogueMan->AddDialogue("The soil here crumbles and can no longer sustain me.", true, true); //26
	DialogueMan->AddDialogue("You must seek a vial of the clearest, purest water from a well deep in the woods.", false, true); //27
	//Mandrake
	DialogueMan->AddDialogue("Those who toil in winter are joyous in spring.", true, true); //28
	DialogueMan->AddDialogue("As the world ripens for harvesting.", true, true); //29
	DialogueMan->AddDialogue("", true, false);//30
	DialogueMan->AddDialogue("All plants can be eaten; but some, only once.", true, true); //31
	DialogueMan->AddDialogue("The forest’s bounty knows no bounds:", true, true); //32
	DialogueMan->AddDialogue("life-giving herbs coexist with deadly poisons.", true, true); //33
	DialogueMan->AddDialogue("I require a very specific cultivar of the Mandragora plant.", true, true); //34
	DialogueMan->AddDialogue("A farm lies ahead, but has been untended for many moons.", true, true); //35
	DialogueMan->AddDialogue("There, you may find what I need.", false, true); //36
	//Deer
	DialogueMan->AddDialogue("Two windows to the world, two windows to the soul.", true, true); //37
	DialogueMan->AddDialogue("Bring me what houses the mind of a doe.", true, true); //38
	DialogueMan->AddDialogue("", true, false);//39
	DialogueMan->AddDialogue("Life, death, and time. All things are fated, Traveller.", true, true); //40
	DialogueMan->AddDialogue("Yet some fates we can change.", true, true); //41
	DialogueMan->AddDialogue("Remember the death that will befall this realm if we cannot alter the course of destiny. ", true, true); //42
	DialogueMan->AddDialogue("Please do not fail me now.", false, true); //43
	//Bridge and the box
	DialogueMan->AddDialogue("In the earth my casket lies buried below.", true, true); //44
	DialogueMan->AddDialogue("But fear not, for now it holds only curios.", true, true); //45
	DialogueMan->AddDialogue("", true, false);//46
	DialogueMan->AddDialogue("You are close to the end, Traveller. I have but one item left for you to retrieve.", true, true); //47
	DialogueMan->AddDialogue("Long ago, I sealed a precious talisman away in a charmed safebox.", true, true); //48
	DialogueMan->AddDialogue("This was stolen from me and buried past the edge of the forest’s realm.", true, true); //49
	DialogueMan->AddDialogue("I feel its power emanating near where the river runs…", true, true); //50
	DialogueMan->AddDialogue("Bring my casket back, so that I may unseal it and ensure this forest shall never fall to ruin.", false, true); //51
	//Out of bounds
	DialogueMan->AddDialogue("Traveller, do not forget your pact.", true, true); //52
	DialogueMan->AddDialogue("The woods can hide treachery in their depths...", false, true); //53
	//Once all items are collected
	DialogueMan->AddDialogue("Traveller! You have found all I need.", true, true); //54
	DialogueMan->AddDialogue("Quickly, return to me. The future beckons.", false, true); //55
	//Once you are back at the tree
	DialogueMan->AddDialogue("Ahhh… at last.", true, true); //56
	DialogueMan->AddDialogue("You have done well, Traveller. Because of you, I may return to my true form.", true, true);//57
	DialogueMan->AddDialogue("", true, false);//58
	DialogueMan->AddDialogue("Oh? Indeed, I was not always inhabiting this tree.", true, true); //59
	DialogueMan->AddDialogue("No, Traveller, I once walked these woods just as you have.", true, true); //60
	DialogueMan->AddDialogue("I lived here peacefully: brewing, divining, enchanting.", true, true); //61
	DialogueMan->AddDialogue("", true, false);//62
	DialogueMan->AddDialogue("Occasionally outsiders such as yourself would cross the threshold", true, true); //63
	DialogueMan->AddDialogue("where the forest would shine upon them.", true, true); //64
	DialogueMan->AddDialogue("And I would gift elixirs and carve sigils for luck upon their saddles.", true, true);//65
	DialogueMan->AddDialogue("", true, false);//66
	DialogueMan->AddDialogue("But one day I was found.", true, true); //67
	DialogueMan->AddDialogue("Tales had spread, and they came for me with dogs and torches.", true, true); //68
	DialogueMan->AddDialogue("They stabbed me as I slept, and threw my body under the floorboards of my own home.", true, true); //69
	DialogueMan->AddDialogue("", true, false);//70
	DialogueMan->AddDialogue("Yet they did not know the true extent of my powers.", true, true); //71
	DialogueMan->AddDialogue("While my body and blood melted into the earth", true, true); //72
	DialogueMan->AddDialogue("My rage was sown into the forest to take root and grow stronger.", true, true); //73
	DialogueMan->AddDialogue("Years have passed...", true, true); //74
	DialogueMan->AddDialogue("And I have lain here...", true, true); //75
	DialogueMan->AddDialogue("Communing with the Old Ones...", true, true); //76
	DialogueMan->AddDialogue("Biding my time...", true, true); //77
	DialogueMan->AddDialogue("Waiting to bloom...", true, true); //78
	DialogueMan->AddDialogue("Waiting…", true, true); //79
	DialogueMan->AddDialogue("For you.", true, true); //80
	DialogueMan->AddDialogue("", true, true);//81
	DialogueMan->AddDialogue("The precious talisman I hid in that casket…", true, true); //82
	DialogueMan->AddDialogue("Please open it.", false, true); //83
	//Open Box
	DialogueMan->AddDialogue("My ceremonial dagger, hidden all those years ago.", true, true); //84
	DialogueMan->AddDialogue("With this knife, our fate will be sealed.", true, true); //85
	DialogueMan->AddDialogue("As I gave my blood for the forest, give your blood to me.", true, true); //86
	DialogueMan->AddDialogue("Your life will seed the strength to manifest my true form.", true, true); //87
	DialogueMan->AddDialogue("", true, true);//88
	DialogueMan->AddDialogue("Do not fear - we can rule together.", true, true); //89
	DialogueMan->AddDialogue("The power I can afford you is greater than any human conception.", true, true); //90
	DialogueMan->AddDialogue("Your heart is pure, and fit to be rewarded.", true, true); //91
	DialogueMan->AddDialogue("", true, false);//92
	DialogueMan->AddDialogue("This is your final challenge, Traveller.", true, true);//93
	DialogueMan->AddDialogue("Water, earth, bone - and blood.", true, true);//94
	DialogueMan->AddDialogue("Please open it and let forth your life.", false, true);//95
	//Show Prompt: E to open casket
	DialogueMan->AddDialogue("Wait - from whence did this come!?", true, true);//96
	DialogueMan->AddDialogue("That's not the dagger - that keystone... from this very building!", true, true);//97
	DialogueMan->AddDialogue("It cannot be!", true, false);//98
	DialogueMan->AddDialogue("", true, false);//99
	DialogueMan->AddDialogue("Take it away from this place! My hut must not be unsealed!", true, false);//100
	//Go to hut and open it
	DialogueMan->AddDialogue("Traveller! What deceit is this?", true, true);//101
	DialogueMan->AddDialogue("No matter.", true, true);//102
	DialogueMan->AddDialogue("You were never important anyway - nothing but a pawn in my machinations.", true, true);//103
	DialogueMan->AddDialogue("Your insolence will not stop me.", true, true);//104
	DialogueMan->AddDialogue("Your blood shall be spilled either way.", true, true);//105
	DialogueMan->AddDialogue("", true, false);//106
	DialogueMan->AddDialogue("I shall take this wretched planet back from those who wronged me and craft it into an altar for the Old Ones.", true, true);//107
	DialogueMan->AddDialogue("Why should those who trample and rampage through these woods be allowed to live?", true, true);//108
	DialogueMan->AddDialogue("Gaze upon my fearsome glory as my leaves block out the sun!", true, true);//109
	DialogueMan->AddDialogue("None shall be spared! ", false, true);//110
	//Go to campfire pick up torch
	DialogueMan->AddDialogue("No!", true, true);//111
	DialogueMan->AddDialogue("NO!", true, true);//112
	DialogueMan->AddDialogue("The future is mine!", false, true);//113
	//The empty string, do DO do do
	DialogueMan->AddDialogue("", false, false);//114

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

	// draw the crosshair

	
	//FCanvasTileItem TileItem( CrosshairDrawPosition, CrosshairTex->Resource, FLinearColor::White);
	//TileItem.BlendMode = SE_BLEND_Translucent;
	//Canvas->DrawItem( TileItem );
}
