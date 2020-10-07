// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "Pain_Ball_GravenProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Engine/DecalActor.h"
#include "Components/DecalComponent.h"
#include "ScoreTarget.h"
#include "MovingActor.h"
#include "Components/SphereComponent.h"

APain_Ball_GravenProjectile::APain_Ball_GravenProjectile() 
{
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &APain_Ball_GravenProjectile::OnHit);		// set up a notification for when this component hits something blocking

	// Players can't walk on it
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;

	// Set as root component
	RootComponent = CollisionComp;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	SetReplicates(true);
	SetReplicateMovement(true);

	static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/Materials/Paintsplatter_Mat.Paintsplatter_Mat'")); //picking material
	if (Material.Object != NULL) //if material isn't null
	{
		DecalMat = (UMaterial*)Material.Object; //set to decal mat
	}

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;

	
}

void APain_Ball_GravenProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
	/*if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());

		Destroy();
	}*/

	AScoreTarget* Target = Cast<AScoreTarget>(OtherActor);

	AMovingActor* MovingActor = Cast<AMovingActor>(OtherActor);

	if ((OtherActor != NULL) && (OtherActor != this)) //if other actors isn't null or itself
	{
		if (DecalMat != nullptr) //if decalmat isn't null
		{

			if (OtherActor->ActorHasTag(EnemyTag))
			{
				playerChar = Cast<APain_Ball_GravenCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn()); //getting player reference
				playerChar->UpdateScore(30); //giving more points for shooting enemy ai
				UGameplayStatics::ApplyDamage(OtherActor, 30.f, GetWorld()->GetFirstPlayerController(), this, Misc); //applying damage to targets w/tag
			}
			else if (OtherActor->ActorHasTag(WaterTag))
			{
				FVector HitVector(0.f, 0.f, 1);
				UGameplayStatics::ApplyPointDamage(OtherActor, 100.f, HitVector, Hit, GetWorld()->GetFirstPlayerController(), this, Misc);//(OtherActor, 100.f, HitVector, GetWorld()->GetFirstPlayerController(), this, Misc);
			}
			
			else if (OtherActor != MovingActor)
			{
				auto Decal = UGameplayStatics::SpawnDecalAtLocation(GetWorld(), DecalMat, FVector(UKismetMathLibrary::RandomFloatInRange(20.f, 40.f)), Hit.Location, Hit.Normal.Rotation(), 0.f); //set decal and size
				auto MatInstance = Decal->CreateDynamicMaterialInstance(); //set mat instance
				//UGameplayStatics::SpawnDecalAtLocation(GetWorld(), DecalMat, FVector(UKismetMathLibrary::RandomFloatInRange(20.f, 40.f)), Hit.Location, Hit.Normal.Rotation(), 0.f);

				MatInstance->SetScalarParameterValue("Frame", UKismetMathLibrary::RandomIntegerInRange(0, 3)); //getting random texture from spritesheet
				MatInstance->SetVectorParameterValue("Color", FLinearColor(UKismetMathLibrary::RandomFloatInRange(0.f, 1.f), UKismetMathLibrary::RandomFloatInRange(0.f, 1.f), UKismetMathLibrary::RandomFloatInRange(0.f, 1.f))); //setting color


				if (OtherActor == Target)
				{
					playerChar = Cast<APain_Ball_GravenCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn()); //getting player reference
					playerChar->UpdateScore(10); //adding 10 points for cube shot
				}
			}
			else
			{
				auto Decal = UGameplayStatics::SpawnDecalAttached(DecalMat, FVector(UKismetMathLibrary::RandomFloatInRange(20.f, 40.f)), Hit.Component.Get(), Hit.BoneName, Hit.ImpactPoint, Hit.Normal.Rotation(), EAttachLocation::KeepWorldPosition, 0.f);
				auto MatInstance = Decal->CreateDynamicMaterialInstance(); //set mat instance

				MatInstance->SetScalarParameterValue("Frame", UKismetMathLibrary::RandomIntegerInRange(0, 3)); //getting random texture from spritesheet
				MatInstance->SetVectorParameterValue("Color", FLinearColor(UKismetMathLibrary::RandomFloatInRange(0.f, 1.f), UKismetMathLibrary::RandomFloatInRange(0.f, 1.f), UKismetMathLibrary::RandomFloatInRange(0.f, 1.f))); //setting color


			}
			Destroy();
		}
	}
}