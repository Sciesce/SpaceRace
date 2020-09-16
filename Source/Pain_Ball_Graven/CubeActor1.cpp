// Fill out your copyright notice in the Description page of Project Settings.

#include "CubeActor1.h"


// Sets default values
ACubeActor1::ACubeActor1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//creating subobject
	mesh = CreateDefaultSubobject<URuntimeMeshComponent>(TEXT("GeneratedMesh"));

	//assigning root as mesh
	RootComponent = mesh;

}

// Called when the game starts or when spawned
void ACubeActor1::BeginPlay()
{
	Super::BeginPlay();
	GenerateBoxMesh(); //calling the function to actually generate the mesh
	
	mesh->SetMaterial(0, ComponentMat);
}

// Called every frame
void ACubeActor1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACubeActor1::GenerateBoxMesh() {
	TArray < FVector > Vertices; //vertices array
	TArray < FVector > Normals; //norms array
	TArray < FRuntimeMeshTangent > Tangents; //tangent array
	TArray < FVector2D > TextureCoordinates; //texture coord array
	TArray < int32 > Triangles; //triangles array
	TArray < FColor > Colors; //colors array
	CreateBoxMesh(FVector(50, 50, 50), Vertices, Triangles, Normals, TextureCoordinates, Tangents, Colors); // Create the mesh section, specifying collision.  
	mesh->CreateMeshSection(0, Vertices, Triangles, Normals, TextureCoordinates, Colors, Tangents, true);
}

//RMC spawn function
void ACubeActor1::CreateBoxMesh(FVector BoxRadius, TArray < FVector > & Vertices, TArray < int32 > & Triangles, TArray < FVector > & Normals, TArray < FVector2D > & UVs, TArray < FRuntimeMeshTangent > & Tangents, TArray < FColor > & Colors) {
	FVector BoxVerts[8];

	//defining boxverts array item
	BoxVerts[0] = FVector(-BoxRadius.X, BoxRadius.Y, BoxRadius.Z);
	BoxVerts[1] = FVector(BoxRadius.X, BoxRadius.Y, BoxRadius.Z);
	BoxVerts[2] = FVector(BoxRadius.X, -BoxRadius.Y, BoxRadius.Z);
	BoxVerts[3] = FVector(-BoxRadius.X, -BoxRadius.Y, BoxRadius.Z);
	BoxVerts[4] = FVector(-BoxRadius.X, BoxRadius.Y, -BoxRadius.Z);
	BoxVerts[5] = FVector(BoxRadius.X, BoxRadius.Y, -BoxRadius.Z);
	BoxVerts[6] = FVector(BoxRadius.X, -BoxRadius.Y, -BoxRadius.Z);
	BoxVerts[7] = FVector(-BoxRadius.X, -BoxRadius.Y, -BoxRadius.Z); 
	
	// Generate triangles (from quads). 
	Triangles.Reset();
	const int32 NumVerts = 24; // 6 faces x 4 verts per face 
	Colors.Reset();
	Colors.AddUninitialized(NumVerts);
	for (int i = 0; i < NumVerts / 3; i++) {
		Colors[i * 3] = FColor(255, 0, 0);
		Colors[i * 3 + 1] = FColor(0, 255, 0);
		Colors[i * 3 + 2] = FColor(0, 0, 255);
	}
	Vertices.Reset();
	Vertices.AddUninitialized(NumVerts);
	Normals.Reset();
	Normals.AddUninitialized(NumVerts);
	Tangents.Reset();
	Tangents.AddUninitialized(NumVerts);

	//setting verts to equal box verts
	Vertices[0] = BoxVerts[0];
	Vertices[1] = BoxVerts[1];
	Vertices[2] = BoxVerts[2];
	Vertices[3] = BoxVerts[3];

	//adding to triangles array
	Triangles.Add(0);
	Triangles.Add(1);
	Triangles.Add(3);
	Triangles.Add(1);
	Triangles.Add(2);
	Triangles.Add(3);
	Normals[0] = Normals[1] = Normals[2] = Normals[3] = FVector(0, 0, 1);  //normals = FVector
	Tangents[0] = Tangents[1] = Tangents[2] = Tangents[3] = FRuntimeMeshTangent(0.f, -1.f, 0.f);  //Tangents = Runtime Tangent
	
	//setting verts to equal box verts
	Vertices[4] = BoxVerts[4];
	Vertices[5] = BoxVerts[0];
	Vertices[6] = BoxVerts[3];
	Vertices[7] = BoxVerts[7];
	
	//adding to triangles array
	Triangles.Add(4);
	Triangles.Add(5);
	Triangles.Add(7);
	Triangles.Add(5);
	Triangles.Add(6);
	Triangles.Add(7); 
	
	//defining the arrays for the bottom of the cube
	Normals[4] = Normals[5] = Normals[6] = Normals[7] = FVector(-1, 0, 0); //normals = FVector
	Tangents[4] = Tangents[5] = Tangents[6] = Tangents[7] = FRuntimeMeshTangent(0.f, -1.f, 0.f); //Tangents = Runtime Tangent
	
	//setting verts to equal box verts
	Vertices[8] = BoxVerts[5];
	Vertices[9] = BoxVerts[1];
	Vertices[10] = BoxVerts[0];
	Vertices[11] = BoxVerts[4];

	//adding to triangles array
	Triangles.Add(8);
	Triangles.Add(9);
	Triangles.Add(11);
	Triangles.Add(9);
	Triangles.Add(10);
	Triangles.Add(11);
	Normals[8] = Normals[9] = Normals[10] = Normals[11] = FVector(0, 1, 0);  //normals = FVector
	Tangents[8] = Tangents[9] = Tangents[10] = Tangents[11] = FRuntimeMeshTangent(-1.f, 0.f, 0.f);  //Tangents = Runtime Tangent
	

	//setting verts to equal box verts
	Vertices[12] = BoxVerts[6];
	Vertices[13] = BoxVerts[2];
	Vertices[14] = BoxVerts[1];
	Vertices[15] = BoxVerts[5];

	//adding to triangles array
	Triangles.Add(12);
	Triangles.Add(13);
	Triangles.Add(15);
	Triangles.Add(13);
	Triangles.Add(14);
	Triangles.Add(15);
	Normals[12] = Normals[13] = Normals[14] = Normals[15] = FVector(1, 0, 0);  //normals = FVector
	Tangents[12] = Tangents[13] = Tangents[14] = Tangents[15] = FRuntimeMeshTangent(0.f, 1.f, 0.f);  //Tangents = Runtime Tangent
	

	//setting verts to equal box verts
	Vertices[16] = BoxVerts[7];
	Vertices[17] = BoxVerts[3];
	Vertices[18] = BoxVerts[2];
	Vertices[19] = BoxVerts[6];

	//adding to triangles array
	Triangles.Add(16);
	Triangles.Add(17);
	Triangles.Add(19);
	Triangles.Add(17);
	Triangles.Add(18);
	Triangles.Add(19);
	Normals[16] = Normals[17] = Normals[18] = Normals[19] = FVector(0, -1, 0);  //normals = FVector
	Tangents[16] = Tangents[17] = Tangents[18] = Tangents[19] = FRuntimeMeshTangent(1.f, 0.f, 0.f);  //Tangents = Runtime Tangent
	

	//setting verts to equal box verts
	Vertices[20] = BoxVerts[7];
	Vertices[21] = BoxVerts[6];
	Vertices[22] = BoxVerts[5];
	Vertices[23] = BoxVerts[4];

	//adding to triangles array
	Triangles.Add(20);
	Triangles.Add(21);
	Triangles.Add(23);
	Triangles.Add(21);
	Triangles.Add(22);
	Triangles.Add(23);
	Normals[20] = Normals[21] = Normals[22] = Normals[23] = FVector(0, 0, -1);  //normals = FVector
	Tangents[20] = Tangents[21] = Tangents[22] = Tangents[23] = FRuntimeMeshTangent(0.f, 1.f, 0.f); //Tangents = Runtime Tangent
	
	
	// Resetting the UVs and then setting them to equal FVector2D
	UVs.Reset();
	UVs.AddUninitialized(NumVerts);
	UVs[0] = UVs[4] = UVs[8] = UVs[12] = UVs[16] = UVs[20] = FVector2D(0.f, 0.f);
	UVs[1] = UVs[5] = UVs[9] = UVs[13] = UVs[17] = UVs[21] = FVector2D(0.f, 1.f);
	UVs[2] = UVs[6] = UVs[10] = UVs[14] = UVs[18] = UVs[22] = FVector2D(1.f, 1.f);
	UVs[3] = UVs[7] = UVs[11] = UVs[15] = UVs[19] = UVs[23] = FVector2D(1.f, 0.f);
}
