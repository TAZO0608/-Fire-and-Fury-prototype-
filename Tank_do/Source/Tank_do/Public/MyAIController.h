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
	UFUNCTION()
	void  OnPossedTankDeath();
	UPROPERTY(VisibleAnywhere, Category = "Com")
	UParticleSystemComponent* mSmoke = nullptr;
private:
	void   SetPawn(APawn* InPawn) override;
	ATank * GetPlayTank();
	ATank* my;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, Category = "Setup")
	float RadiusToPlayer = 6000;

	
};
