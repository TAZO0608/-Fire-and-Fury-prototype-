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
	UE_LOG(LogTemp, Warning, TEXT("ZZZZZ"));

}
ATank* ATank_Controller::GetTank() 
{
	return Cast<ATank >(GetPawn());
}
void ATank_Controller::AimWhat() {

}





