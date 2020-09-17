// Fill out your copyright notice in the Description page of Project Settings.

#include "ParticleActor.h"
#include "Engine.h"


// Sets default values
AParticleActor::AParticleActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	dustP = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle System"));

	RootComponent = dustP; //assigning as root

}

// Called when the game starts or when spawned
void AParticleActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AParticleActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AParticleActor::printNum()
{
	GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Blue, FString::SanitizeFloat(numValue));
}

