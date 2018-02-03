// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "MyTrack.h"
#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "MyMovement.generated.h"

/**
 * 
 */
UCLASS()
class TANK_DO_API UMyMovement : public UNavMovementComponent
{
	GENERATED_BODY()

public:
	 void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
	UFUNCTION(BlueprintCallable, Category = "input")
	void moveforward (float v);
	UFUNCTION(BlueprintCallable, Category = "input")
	void TurnRight(float v);
	UMyTrack* left_track;
	UMyTrack* right_track;
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetTrack(UMyTrack* L , UMyTrack* R);
	
	
	
};
