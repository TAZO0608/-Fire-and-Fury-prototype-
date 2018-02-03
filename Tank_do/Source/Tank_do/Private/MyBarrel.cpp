// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBarrel.h"
void UMyBarrel::Elevate(float relativeSpeed)
{
	relativeSpeed = FMath::Clamp<float>(relativeSpeed, -1, +1);
	auto NewRotation = (RelativeRotation.Pitch + (relativeSpeed * DegreePS * GetWorld()->DeltaTimeSeconds));
	auto FinalRotation = FMath::Clamp<float>(NewRotation, P_MIN_Degree, P_MAX_Degree);
	SetRelativeRotation(FRotator(FinalRotation, 0, 0));
	
}




