// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WhiteBoardActor.generated.h"

UCLASS()
class WHITEBOARDCPP_API AWhiteBoardActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWhiteBoardActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* whiteboard_mesh;

	UPROPERTY(EditAnywhere)
		UMaterialInterface* markerMat;

	UPROPERTY(EditAnywhere)
		UMaterialInstanceDynamic* whiteboardMarker_MI;

	UPROPERTY(EditAnywhere)
		UTextureRenderTarget2D* renderTarget;

	UFUNCTION(BlueprintCallable)
		void DrawOnWhiteboard(FVector2D LocationToDraw);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float drawSize;
};
