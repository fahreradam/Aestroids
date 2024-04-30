// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"


// Sets default values
APlayerCharacter::APlayerCharacter()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");

	RootComponent = MeshComponent;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlayerCharacter::Shoot()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Red, "Shoot");
}

void APlayerCharacter::Move(float Movement)
{
	if(Controller != nullptr)
	{
		AddMovementInput(GetActorForwardVector(), Movement);
	}
	
	GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Red, "Move");
}

void APlayerCharacter::Roation(float Rotation)
{
	if(Controller != nullptr)
	{
		FRotator Rot = GetControlRotation();
		Rot.Yaw += Rotation;
		AddActorLocalRotation(Rot);
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Red, "Rotation");
}


