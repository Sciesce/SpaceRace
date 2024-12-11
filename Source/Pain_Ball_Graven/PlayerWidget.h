// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerWidget.generated.h"

/**
 * 
 */
UCLASS()
class PAIN_BALL_GRAVEN_API UPlayerWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	//constructor
	UFUNCTION(BlueprintImplementableEvent)
		void TextUpdate(int playerScore);
	
	
	
};
