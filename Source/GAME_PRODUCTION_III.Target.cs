// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class GAME_PRODUCTION_IIITarget : TargetRules
{
	public GAME_PRODUCTION_IIITarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		ExtraModuleNames.Add("GAME_PRODUCTION_III");
	}
}
