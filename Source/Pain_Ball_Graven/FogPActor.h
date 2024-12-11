// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Particles/ParticleSystemComponent.h"
#include "Pain_Ball_GravenCharacter.h"
#include "FogPActor.generated.h"

UCLASS()
class PAIN_BALL_GRAVEN_API AFogPActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFogPActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//declaring fog
	UPROPERTY(EditAnywhere)
		UParticleSystemComponent* fog_p;
	
	//declaring playerchar variable so it's not called during tick
	UPROPERTY()
		APain_Ball_GravenCharacter* playerChar;

};
