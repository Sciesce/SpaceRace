// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class Pain_Ball_GravenTarget : TargetRules
{
	public Pain_Ball_GravenTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		ExtraModuleNames.Add("Pain_Ball_Graven");
	}
}
