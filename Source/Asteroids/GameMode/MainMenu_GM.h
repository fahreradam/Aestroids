// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MainMenu_GM.generated.h"


/**
 * 
 */
UCLASS()
class ASTEROIDS_API AMainMenu_GM : public AGameModeBase
{
	
	GENERATED_BODY()

	virtual void BeginPlay() override;

public:

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> MainMenuClass;
	
	UPROPERTY(BlueprintReadOnly)
	UUserWidget* MainMenu = nullptr;
};
