// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu_GM.h"

#include "Blueprint/UserWidget.h"

void AMainMenu_GM::BeginPlay()
{
	Super::BeginPlay();
	
	if(MainMenuClass)
	{
		MainMenu = CreateWidget<UUserWidget>(GetWorld(), MainMenuClass);
		if (MainMenu)
		{
			MainMenu->AddToViewport();
		}
	}
}
