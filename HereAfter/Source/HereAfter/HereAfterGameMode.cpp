// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "HereAfterGameMode.h"
#include "HereAfterHUD.h"
#include "HereAfterCharacter.h"
#include "UObject/ConstructorHelpers.h"

AHereAfterGameMode::AHereAfterGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = AHereAfterCharacter::StaticClass();

	// use our custom HUD class
	HUDClass = AHereAfterHUD::StaticClass();
}
