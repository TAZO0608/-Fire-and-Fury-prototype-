// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank_Controller.h"


void ATank_Controller::BeginPlay()
{
	Super::BeginPlay();

	auto G_Tank = GetTank();
	if (!G_Tank)
	{
		UE_LOG(LogTemp, Warning, TEXT("NO Get Tank"));
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *(G_Tank->GetName()));
	}
}

void ATank_Controller::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimWhat();
	

}
ATank* ATank_Controller::GetTank() const
{
	return Cast<ATank >(GetPawn());
}
void ATank_Controller::AimWhat() {
	if (!GetTank()) { return; }
	FVector Hitlocation;
	if (Hitsomthing(Hitlocation))
	{
		GetTank()->ToAim(Hitlocation);
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("Nothing"));
	}

}
bool ATank_Controller::Hitsomthing(FVector& outHitLocation)
{
	int32 ScreenSize_X, ScreenSize_y;
	GetViewportSize(ScreenSize_X, ScreenSize_y);
	FVector2D ScreeonLocation = FVector2D(ScreenSize_X*crosshair_x, ScreenSize_y*crosshair_y);
	FVector CameraLocation;
	FVector WorldDirection;
	if (DeprojectScreenPositionToWorld(ScreeonLocation.X, ScreeonLocation.Y, CameraLocation, WorldDirection)) 
	{
		FHitResult HitSomeone;
		if (GetWorld()->LineTraceSingleByChannel(HitSomeone, CameraLocation, CameraLocation + (WorldDirection*Distance), ECollisionChannel::ECC_Camera))
		{
			outHitLocation = HitSomeone.Location;
			return true;
		}
	}
	return false;
}
void ATank_Controller::OnPossedTankDeath()
{
	UE_LOG(LogTemp, Warning, TEXT("DDDDDDReceived!"))
		if (!ensure(GetPawn())) { return; }
	StartSpectatingOnly();
}
void  ATank_Controller::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }

		
		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATank_Controller::OnPossedTankDeath);
	}
}





