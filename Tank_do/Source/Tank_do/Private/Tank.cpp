// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Tank_do.h"
#include "MyBarrel.h"
#include "MyTurret.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	myAim_Component = CreateDefaultSubobject<UAim_Component>(FName("my_aim_component"));
	T_FireState = myAim_Component->FireState;
	T_AmmoAmount = myAim_Component->AmmoAmount;
	myMovement = CreateDefaultSubobject<UMyMovement>(FName("my_move_component"));

	//mSmoke = CreateDefaultSubobject<UParticleSystemComponent>(FName("MYSmoke"));
	//mSmoke->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	//mSmoke->bAutoActivate = false;
}
void ATank::SettoBarrel(UMyBarrel* barreltoset)
{
	if (!barreltoset) { return; }
	myAim_Component->Barrel = barreltoset;
}
void ATank::SettoTurret(UMyTurret* turrettoset)
{
	if (!turrettoset) { return; }
	myAim_Component->Turret = turrettoset;
}
// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	lasttime = UGameplayStatics::GetRealTimeSeconds(GetWorld());
	NowHealth = StartHealth;
}
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if ((UGameplayStatics::GetRealTimeSeconds(GetWorld()) - lasttime < Gap_of_Attack))
	{
		myAim_Component->FireState = EFireState::Loading;
		T_FireState = EFireState::Loading;
	}
	else if (isbarrelmoving()) 
	{
		myAim_Component->FireState = EFireState::Aiming;
		T_FireState = EFireState::Aiming;
	}
	else
	{
		myAim_Component->FireState = EFireState::Lock;
		T_FireState = EFireState::Lock;
	}
	
}

bool ATank::isbarrelmoving() 
{
	auto vv = myAim_Component->ProjectDir;
	auto dd = myAim_Component->Barrel->GetForwardVector();


		
		return !(vv.Equals(dd, 0.01));
	
}
void ATank::GetSmoke(UParticleSystemComponent* Smoke)
{
	mSmoke = Smoke;
}
// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float ATank::TakeDamage
(
	float DamageAmount,
	struct FDamageEvent const & DamageEvent,
	class AController * EventInstigator,
	AActor * DamageCauser
) 
{
	int32 pp = FPlatformMath::RoundToInt(DamageAmount);
	auto dd = FMath::Clamp<int32>(pp, 0, NowHealth);
	NowHealth -= dd;
	if (NowHealth <= 0) 
	{
		UE_LOG(LogTemp, Warning, TEXT("Received!"))
		OnDeath.Broadcast();
		mSmoke->Activate();
	}

	return dd;
}

float ATank::GetPercentage()
{
	return ((float)NowHealth / (float)StartHealth);
}



void ATank::ToAim(FVector hitlocation) {

	myAim_Component->FinalToAim(hitlocation, launchspeed);
}
void ATank::FIRE()
{
	//UE_LOG(LogTemp, Warning, TEXT("%f"), UGameplayStatics::GetRealTimeSeconds(GetWorld()));
	
		if (T_FireState == EFireState::Aiming || T_FireState == EFireState::Lock)
		{
			GetWorld()->SpawnActor<AProjectile>
				(
					myprojectile,
					myAim_Component->Barrel->GetSocketLocation(FName("Socket")),
					myAim_Component->Barrel->GetSocketRotation(FName("Socket"))
					);
			//myAim_Component->Barrel
			UE_LOG(LogTemp, Warning, TEXT("FIRE"));
			lasttime = UGameplayStatics::GetRealTimeSeconds(GetWorld());
			myAim_Component->AmmoAmount--;
			T_AmmoAmount--;
			//if (T_AmmoAmount == 0)
			//{
				//myAim_Component->FireState = EFireState::OutOfAmmo;
				//T_FireState = EFireState::OutOfAmmo;
			//}
		}
}

