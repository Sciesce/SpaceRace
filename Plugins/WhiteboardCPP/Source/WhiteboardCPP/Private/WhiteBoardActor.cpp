// Fill out your copyright notice in the Description page of Project Settings.

#include "WhiteBoardActor.h"
#include "Kismet/KismetRenderingLibrary.h"
#include "Engine.h"


// Sets default values
AWhiteBoardActor::AWhiteBoardActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	whiteboard_mesh = CreateDefaultSubobject<UStaticMeshComponent>(("Static Mesh")); 
	RootComponent = whiteboard_mesh; //making root

	static ConstructorHelpers::FObjectFinder<UStaticMesh>asset(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube.1M_Cube'")); //getting mesh
	
	whiteboard_mesh->SetStaticMesh(asset.Object); //setting static mesh to selected object

	static ConstructorHelpers::FObjectFinder<UMaterial>asset1(TEXT("Material'/Game/Whiteboard_Fun/M_Whiteboard.M_Whiteboard'")); //getting material

	whiteboard_mesh->SetMaterial(0, asset1.Object); //setting material

	static ConstructorHelpers::FObjectFinder<UMaterial>asset2(TEXT("Material'/Game/Whiteboard_Fun/M_WhiteboardMarker.M_WhiteboardMarker'")); //getting material

	markerMat = asset2.Object; //setting whiteboard market asset

	static ConstructorHelpers::FObjectFinder<UTextureRenderTarget2D>asset3(TEXT("CanvasRenderTarget2D'/Game/Whiteboard_Fun/RT_Whiteboard.RT_Whiteboard'")); //getting render mat

	renderTarget = asset3.Object; //setting render target
}

// Called when the game starts or when spawned
void AWhiteBoardActor::BeginPlay()
{
	Super::BeginPlay();
	
	if (markerMat)
	{
		whiteboardMarker_MI = UMaterialInstanceDynamic::Create(markerMat, this);
	}

	UKismetRenderingLibrary::ClearRenderTarget2D(this, renderTarget, FLinearColor::Black); //clearing render target on begin play

	whiteboardMarker_MI->SetScalarParameterValue("DrawSize", drawSize);

}

// Called every frame
void AWhiteBoardActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWhiteBoardActor::DrawOnWhiteboard(FVector2D LocationToDraw)
{

	whiteboardMarker_MI->SetVectorParameterValue("DrawLocation", FLinearColor(LocationToDraw.X, LocationToDraw.Y, 0)); //setting where to draw based off of camera

	UKismetRenderingLibrary::DrawMaterialToRenderTarget(this, renderTarget, whiteboardMarker_MI); //drawing on board

}

