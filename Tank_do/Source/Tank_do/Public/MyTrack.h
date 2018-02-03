// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "MyTrack.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TANK_DO_API UMyTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	public:
		UFUNCTION(BlueprintCallable, Category = "input")
		void SetThrottle(float v);
		UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
private:
		void   BeginPlay() override;
		UPROPERTY(EditAnywhere, Category = "Setup")
		float DegreePS = 20.0;
		UPROPERTY(EditAnywhere, Category = "Setup")
		float MAXForce = 102000000.0;
		UMyTrack();
		void  TickComponent(float DeltaTime, enum ELevelTick TickType,FActorComponentTickFunction * ThisTickFunction) override;
		void  SideForce();
		float currentThrottle = 0;
		void Drive();
};
