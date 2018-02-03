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
		MoveToActor(GetPlayTank(), RadiusToPlayer);
		AITank->ToAim(GetPlayTank()->GetActorLocation());
		if (AITank->myAim_Component->FireState == EFireState::Lock) 
		{
			AITank->FIRE();
		}
		
		
	}
	
}
ATank* AMyAIController::GetPlayTank()
{
	auto TT = GetWorld()->GetFirstPlayerController()->GetPawn();
	return Cast<ATank >(TT);
	
}
void AMyAIController::OnPossedTankDeath()
{
	my = Cast<ATank>(GetPawn());
	my->mSmoke->Activate();
	UE_LOG(LogTemp, Warning, TEXT("DDDDDDReceived!"))
	if (!ensure(GetPawn())) { return; } 
	GetPawn()->DetachFromControllerPendingDestroy();
}
void  AMyAIController::SetPawn(APawn* InPawn)
 {
	Super::SetPawn(InPawn);
	if (InPawn)
		{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }
		
					// Subscribe our local method to the tank's death event
			PossessedTank->OnDeath.AddUniqueDynamic(this, &AMyAIController::OnPossedTankDeath);
		}
}




