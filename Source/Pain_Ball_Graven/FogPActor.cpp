// Fill out your copyright notice in the Description page of Project Settings.

#include "FogPActor.h"
#include "Pain_Ball_GravenCharacter.h"


// Sets default values
AFogPActor::AFogPActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	fog_p = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Paritlce System"));

	RootComponent = fog_p;

}

// Called when the game starts or when spawned
void AFogPActor::BeginPlay()
{
	Super::BeginPlay();
	
	playerChar = Cast<APain_Ball_GravenCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

// Called every frame
void AFogPActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//setting foot socket locations on tick
	FVector Loc = playerChar->GetMesh()->GetSocketLocation("LeftFootSocket");
	FVector Loc1 = playerChar->GetMesh()->GetSocketLocation("RightFootSocket");

	if (fog_p) //if the fog exists
	{
		fog_p->SetVectorParameter("KickFog", Loc); //perform kickfog
		fog_p->SetVectorParameter("KickFog", Loc1); //perform kickfog
	}


}

