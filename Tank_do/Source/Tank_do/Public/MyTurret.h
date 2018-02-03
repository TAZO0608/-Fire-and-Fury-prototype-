// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "MyTurret.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TANK_DO_API UMyTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
		void Yaw(float relativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category = "Setup")
		float DegreePS = 20.0;
		//UPROPERTY(EditAnywhere, Category = "Setup")
			//float Y_MAX_Degree = 179.99;
		//UPROPERTY(EditAnywhere, Category = "Setup")
			//float Y_MIN_Degree = -179.99;
	
};
