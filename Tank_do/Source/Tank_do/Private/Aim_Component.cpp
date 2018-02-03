// Fill out your copyright notice in the Description page of Project Settings.

#include "Aim_Component.h"

#include "MyBarrel.h"
#include "MyTurret.h"

// Sets default values for this component's properties
UAim_Component::UAim_Component()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}



void UAim_Component::FinalToAim(FVector hitlocation, float launchspeed)
{
	if (!Barrel) { return; }
	FVector OutDir;
	FVector StartLocation = Barrel->GetComponentLocation();
	if ( UGameplayStatics::SuggestProjectileVelocity
			(
				this,
				OutDir,
				StartLocation,
				hitlocation,
				launchspeed,
				false,
				0,
				0,
				ESuggestProjVelocityTraceOption::DoNotTrace
			)
		)
	{
		ProjectDir = OutDir.GetSafeNormal();
		movetoward(ProjectDir);
	}
	
}

int UAim_Component::GetAmmoAmount() const
{
	return AmmoAmount;
}

FString UAim_Component::GetState() const
{
	FString tt;
	if (FireState == EFireState::Loading)
	{
		tt = "Loading";
	}
	else if (FireState == EFireState::Aiming)
	{
		tt = "Aiming";
	}
	else
	{
		tt = "Locked";
	}



	return tt;
}

void UAim_Component::movetoward(FVector Dir) 
{
	auto R_final = Dir.Rotation();
	auto R_start = Barrel->GetForwardVector().Rotation();
	auto Offsetrotation = R_final- R_start ;
	Barrel->Elevate(Offsetrotation.Pitch);
	//UE_LOG(LogTemp, Warning, TEXT("%f"), Offsetrotation.Yaw);
	if (FMath::Abs(Offsetrotation.Yaw) < 180)
	{
		Turret->Yaw(Offsetrotation.Yaw);
	}
	
	else
	{
		

		Turret->Yaw(-Offsetrotation.Yaw);

	}
}


