// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "Pain_Ball_GravenGameMode.h"
#include "Pain_Ball_GravenHUD.h"
#include "Pain_Ball_GravenCharacter.h"
#include "UObject/ConstructorHelpers.h"

APain_Ball_GravenGameMode::APain_Ball_GravenGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = APain_Ball_GravenHUD::StaticClass();
}
