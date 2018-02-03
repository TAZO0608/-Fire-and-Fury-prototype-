// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTurret.h"


void UMyTurret::Yaw(float relativeSpeed)
{
	relativeSpeed = FMath::Clamp<float>(relativeSpeed, -1, +1);
	auto NewRotation = (RelativeRotation.Yaw + (relativeSpeed * DegreePS * GetWorld()->DeltaTimeSeconds));
	//auto FinalRotation = FMath::Clamp<float>(NewRotation, Y_MIN_Degree, Y_MAX_Degree);
	SetRelativeRotation(FRotator(0, NewRotation, 0));


}

