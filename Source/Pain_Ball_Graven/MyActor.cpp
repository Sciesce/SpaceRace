// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActor.h"
#include "ProceduralMeshComponent.h"


// Sets default values **is constructor function
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//defining the mesh/creating subobject
	mesh = CreateDefaultSubobject <UProceduralMeshComponent>(TEXT("GeneratedMesh")); 
	RootComponent = mesh; //assigning the mesh to be the root component

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor::PostActorCreated() //called when actor is finished spawning into the world
{
	Super::PostActorCreated();
	CreateSquare(); //calling create square function
}

void AMyActor::PostLoad() //cleanup after object is loaded
{
	Super::PostLoad();
	CreateSquare(); //calling create square function
}

//defining createsquare function
void AMyActor::CreateSquare()
{
	//defining various arrays
	TArray<FVector> Vertices;
	TArray<int32> Triangles;
	TArray<FVector> Normals;
	TArray<FLinearColor> Colors;

	//adding vertices to Vertices array
	Vertices.Add(FVector(0.f, 0.f, 0.f));
	Vertices.Add(FVector(0.f, 100.f, 0.f));
	Vertices.Add(FVector(0.f, 0.f, 100.f));
	Vertices.Add(FVector(0.f, 100.f, 100.f));

	//adding triangles to triangle array
	Triangles.Add(0);
	Triangles.Add(1);
	Triangles.Add(2);
	Triangles.Add(3);
	Triangles.Add(2);
	Triangles.Add(1);

	//loop to create plane 
	for (int32 i = 0; i < Vertices.Num(); i++)
	{
		Normals.Add(FVector(0.f, 0.f, 1.f));
		Colors.Add(FLinearColor::Red);
	}

	TArray<FVector2D> UV0; //defining textures/UV's
	TArray<FProcMeshTangent> Tangents;
	mesh->CreateMeshSection_LinearColor(0, Vertices, Triangles, Normals, UV0, Colors, Tangents, true);  //creating mesh
}

