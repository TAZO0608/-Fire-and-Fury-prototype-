// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Kismet/GameplayStatics.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Aim_Component.generated.h"

UENUM()
enum class EFireState : uint8
{
	Loading,
	Aiming,
	Lock,
	OutOfAmmo
};


class UMyBarrel;
class UMyTurret;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANK_DO_API UAim_Component : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAim_Component();
	FVector ProjectDir;
	UMyBarrel* Barrel = nullptr;
	UMyTurret* Turret = nullptr;
	
	void FinalToAim(FVector hitlocation, float launchspeed);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	int GetAmmoAmount() const;
	UFUNCTION(BlueprintCallable, Category = "Setup")
		FString GetState() const;
	UPROPERTY(EditAnywhere, Category = "Fire")
	int32 AmmoAmount = 64;

	UPROPERTY(BlueprintReadOnly, Category = "State")
		EFireState  FireState = EFireState::Loading;
private:
	void movetoward(FVector Dir);
	
	
};
