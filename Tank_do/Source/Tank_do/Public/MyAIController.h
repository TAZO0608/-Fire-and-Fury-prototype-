// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "MyAIController.generated.h"

/**
 * 
 */
UCLASS()
class TANK_DO_API AMyAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	ATank * GetPlayTank();
	virtual void BeginPlay() override;
	
	
};
