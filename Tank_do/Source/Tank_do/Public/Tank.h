// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Aim_Component.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class TANK_DO_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	void ToAim(FVector hitlocation);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UAim_Component* myAim_Component;

private:
	ATank();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
