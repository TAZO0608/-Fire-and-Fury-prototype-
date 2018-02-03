// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class TANK_DO_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere, Category = "Setup")
	float Delaytime = 5;
	UPROPERTY(EditAnywhere, Category = "Setup")
	float Damage = 20.f;
	void TimeExpire();
	// Sets default values for this actor's properties
	AProjectile();
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	//virtual void Tick(float DeltaTime) override;
	UPROPERTY(VisibleAnywhere,Category = "Com")
	UStaticMeshComponent*  mCollisionMesh = nullptr;
	UPROPERTY(VisibleAnywhere, Category = "Com")
	UParticleSystemComponent* mLaunchBlast = nullptr;
	UPROPERTY(VisibleAnywhere, Category = "Com")
	UParticleSystemComponent* mImpact = nullptr;
	UPROPERTY(VisibleAnywhere, Category = "Com")
	URadialForceComponent* mImpluse = nullptr;
	
};
