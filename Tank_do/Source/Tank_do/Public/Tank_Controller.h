// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Tank_Controller.generated.h"

/**
 * 
 */
UCLASS()
class TANK_DO_API ATank_Controller : public APlayerController
{
	GENERATED_BODY()

public:
	ATank * GetTank();
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void  AimWhat();
	
};
