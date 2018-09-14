// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "GAME_PRODUCTION_IIIGameMode.h"
#include "GAME_PRODUCTION_IIICharacter.h"
#include "UObject/ConstructorHelpers.h"

AGAME_PRODUCTION_IIIGameMode::AGAME_PRODUCTION_IIIGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
