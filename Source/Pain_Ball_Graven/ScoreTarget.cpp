// Fill out your copyright notice in the Description page of Project Settings.

#include "ScoreTarget.h"


// Sets default values
AScoreTarget::AScoreTarget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));

	RootComponent = meshComp;

}

// Called when the game starts or when spawned
void AScoreTarget::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AScoreTarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

