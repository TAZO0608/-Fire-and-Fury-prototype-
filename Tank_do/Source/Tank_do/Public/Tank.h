// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Projectile.h"

#include "MyMovement.h"
#include "Aim_Component.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"


class UMyBarrel;
class UMyTurret;


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);
UCLASS()
class TANK_DO_API ATank : public APawn
{
	GENERATED_BODY()

public:
	FTankDelegate OnDeath;

	UFUNCTION(BlueprintPure, Category = "Setup")
	float GetPercentage();

	// Sets default values for this pawn's properties
	void ToAim(FVector hitlocation);

	virtual float TakeDamage
	(
		float DamageAmount,
		struct FDamageEvent const & DamageEvent,
		class AController * EventInstigator,
		AActor * DamageCauser
	)override;

	UFUNCTION(BlueprintCallable, Category = "Setup")void SettoBarrel(UMyBarrel* barreltoset);
	UFUNCTION(BlueprintCallable, Category = "Setup")void SettoTurret(UMyTurret* turrettoset);
	UFUNCTION(BlueprintCallable, Category = "Setup")void FIRE();
	UPROPERTY(EditAnywhere, Category = "Fire")
		float launchspeed = 10000.0;
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		TSubclassOf<AProjectile> myprojectile;
	UPROPERTY(EditAnywhere, Category = "Fire")
	float Gap_of_Attack = 3.0;

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void  GetSmoke(UParticleSystemComponent* mSmoke);
	UPROPERTY(VisibleAnywhere, Category = "Com")
	UParticleSystemComponent* mSmoke = nullptr;

	UPROPERTY(BlueprintReadOnly)
	UAim_Component* myAim_Component;
protected:
	UPROPERTY(BlueprintReadOnly)
	UMyMovement* myMovement;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	
	

private:
	ATank();

	bool  isbarrelmoving();
	EFireState  T_FireState = EFireState::Loading;
	UPROPERTY(EditAnywhere, Category = "Setup")
	int32 T_AmmoAmount = 64;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	float lasttime = 0;
	UPROPERTY(EditAnywhere, Category = "Setup")
	int32 StartHealth = 100;
	UPROPERTY(VisibleAnywhere, Category = "Setup")
		int32 NowHealth;
	
};
