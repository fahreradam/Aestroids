// Fill out your copyright notice in the Description page of Project Settings.


#include "Player_PC.h"

#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/Character.h"


APlayer_PC::APlayer_PC()
{
	bAutoManageActiveCameraTarget = false;
}

void APlayer_PC::BeginPlay()
{
	Super::BeginPlay();
	
	TArray<AActor*> CameraActors;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);

	for (auto const CameraActor : CameraActors)
	{
		if (CameraActor->ActorHasTag("GameView"))
		{
			ClientSetViewTarget(CameraActor);
			break;
		}
	}

	if(GetPawn() && GetPawn()->IsA(APlayerCharacter::StaticClass()))
    {
        PlayerCharacter = Cast<APlayerCharacter>(GetPawn());
    }
	
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		// add the mapping context so we get controls
		Subsystem->AddMappingContext(GameContext, 0);
	}	
}

void APlayer_PC::SetupInputComponent()
{
	Super::SetupInputComponent();

	if(UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(ShootAction, ETriggerEvent::Started,this, &APlayer_PC::Input_Shoot);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlayer_PC::Input_Move);
		EnhancedInputComponent->BindAction(RotateAction, ETriggerEvent::Triggered, this, &APlayer_PC::Input_Rotate);
	}
}

void APlayer_PC::Input_Shoot()
{
	PlayerCharacter->Shoot();
}

void APlayer_PC::Input_Move(const FInputActionValue& Value)
{
	if(PlayerCharacter != nullptr)
	{
		float MovementVector = Value.Get<float>();
    
        PlayerCharacter->Move(MovementVector);
	}
}

void APlayer_PC::Input_Rotate(const FInputActionValue& Value)
{
	if(PlayerCharacter != nullptr)
	{
		float Rotation = Value.Get<float>();
    	PlayerCharacter->Roation(Rotation);	
	}
}

