// Fill out your copyright notice in the Description page of Project Settings.

#include "MyAIController.h"

void AMyAIController::BeginPlay()
{
	Super::BeginPlay();

	auto G_Tank = GetPlayTank();
	if (!G_Tank)
	{
		UE_LOG(LogTemp, Warning, TEXT("NO Get Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *(G_Tank->GetName()));
	}
}
void AMyAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto AITank = Cast<ATank >(GetPawn());
	
	if (GetPlayTank()) {
		AITank->ToAim(GetPlayTank()->GetActorLocation());
	}
	
}
ATank* AMyAIController::GetPlayTank()
{
	auto TT = GetWorld()->GetFirstPlayerController()->GetPawn();
	return Cast<ATank >(TT);
	
}


