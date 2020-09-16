// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "MyActor.generated.h"

UCLASS()
class PAIN_BALL_GRAVEN_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//declaring functions to be defined or overridden

	virtual void PostActorCreated() override;
	virtual void PostLoad() override;
	virtual void CreateSquare(); 

private:
	//mesh declaration
	UPROPERTY(VisibleAnywhere)
		UProceduralMeshComponent* mesh;
	
	
};
