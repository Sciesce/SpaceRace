// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Pain_Ball_GravenHUD.generated.h"

UCLASS()
class APain_Ball_GravenHUD : public AHUD
{
	GENERATED_BODY()

public:
	APain_Ball_GravenHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

