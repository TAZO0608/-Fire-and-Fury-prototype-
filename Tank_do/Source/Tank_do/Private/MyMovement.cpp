// Fill out your copyright notice in the Description page of Project Settings.

#include "MyMovement.h"


void UMyMovement::moveforward(float v) 
{
	left_track->SetThrottle(v);
	right_track->SetThrottle(v);
	//UE_LOG(LogTemp, Warning, TEXT("%f"), v);
}

void UMyMovement::TurnRight(float v)
{
	left_track->SetThrottle(v);
	right_track->SetThrottle(-v);
	//UE_LOG(LogTemp, Warning, TEXT("%f"), v);
}

void UMyMovement::SetTrack(UMyTrack* L, UMyTrack* R)
{
	left_track = L;
	right_track = R;
}
void UMyMovement::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) 
{
	auto TankDir = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto MoveDir = MoveVelocity.GetSafeNormal();
	float cc =  FVector::DotProduct(TankDir, MoveDir);
	float ss = FVector::CrossProduct(TankDir, MoveDir).Z;
	moveforward(cc);
	TurnRight(ss);
	//UE_LOG(LogTemp, Warning, TEXT("%s has v is%s"),*TankName  ,*MoveVelocity.ToString() );

}

