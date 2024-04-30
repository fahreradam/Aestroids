// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "Asteroids/Player/PlayerCharacter.h"
#include "GameFramework/PlayerController.h"
#include "Player_PC.generated.h"

/**
 * 
 */

class UInputAction;
class UInputMappingContext;
UCLASS()
class ASTEROIDS_API APlayer_PC : public APlayerController
{
	GENERATED_BODY()

	APlayer_PC();

	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

	UPROPERTY(EditDefaultsOnly, Category="Input")
	UInputAction* MoveAction;

	UPROPERTY(EditDefaultsOnly, Category="Input")
	UInputAction* PauseAction;

	UPROPERTY(EditDefaultsOnly, Category="Input")
	UInputAction* ShootAction;
	
	UPROPERTY(EditDefaultsOnly, Category="Input")
	UInputAction* RotateAction;
	
	UPROPERTY(EditDefaultsOnly, Category="Mapping Context")
	UInputMappingContext* MainMenuContext;
	
	UPROPERTY(EditDefaultsOnly, Category="Mapping Context")
	UInputMappingContext* GameContext;
	UFUNCTION()
	void Input_Shoot();

	UFUNCTION()
	void Input_Move(const FInputActionValue& Value);

	UFUNCTION()
	void Input_Rotate(const FInputActionValue& Value);

public:
	UPROPERTY(BlueprintReadOnly)
	APlayerCharacter* PlayerCharacter;

		
};
