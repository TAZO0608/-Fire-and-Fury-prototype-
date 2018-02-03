// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Tank_Controller.generated.h"



UCLASS()
class TANK_DO_API ATank_Controller : public APlayerController
{
	GENERATED_BODY()
public:
	UFUNCTION()
	void  OnPossedTankDeath();
protected:
		UFUNCTION(BlueprintCallable, Category = "Setup")
		ATank * GetTank() const;


private:
	
	void   SetPawn(APawn* InPawn) override;
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void  AimWhat();
	bool Hitsomthing(FVector& outHitLocation );
	UPROPERTY(EditAnyWhere)
	float crosshair_x = 0.5 ;
	UPROPERTY(EditAnyWhere)
	float crosshair_y = 0.33333;
	UPROPERTY(EditAnyWhere)
	float Distance = 1000000;
	
};
