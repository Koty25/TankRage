// Copyright Epic Games, Inc. All Rights Reserved.

#include "TankRageGameMode.h"
#include "TankRageCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATankRageGameMode::ATankRageGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
