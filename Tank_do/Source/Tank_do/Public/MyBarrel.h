// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "MyBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TANK_DO_API UMyBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float relativeSpeed);
	
private:
	UPROPERTY(EditAnywhere, Category = "Setup")
	float DegreePS = 10.0;
	UPROPERTY(EditAnywhere, Category = "Setup")
	float P_MAX_Degree = 40.0;
	UPROPERTY(EditAnywhere, Category = "Setup")
	float P_MIN_Degree = -8.0;

	
};
