// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"
//#include "Tank_do.h"


// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	mCollisionMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("MYCollisionMesh"));
	SetRootComponent(mCollisionMesh);
	mCollisionMesh->SetNotifyRigidBodyCollision(true);
	mCollisionMesh->SetVisibility(false);

	mLaunchBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("MYLaunchBlast"));
	mLaunchBlast->AttachToComponent(RootComponent,FAttachmentTransformRules::KeepRelativeTransform);

	mImpluse = CreateDefaultSubobject<URadialForceComponent>(FName("MYImpluse"));
	mImpluse->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	mImpact = CreateDefaultSubobject<UParticleSystemComponent>(FName("MYImpact"));
	mImpact->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	mImpact->bAutoActivate = false;
}


// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	mCollisionMesh->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);
	
}
void AProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	mLaunchBlast->Deactivate();
	mImpact->Activate();
	mImpluse->FireImpulse();
	SetRootComponent(mImpact);
	mCollisionMesh->DestroyComponent();

	UGameplayStatics::ApplyRadialDamage(this, Damage, GetActorLocation(), mImpluse->Radius, UDamageType::StaticClass(), TArray<AActor*>());


	FTimerHandle TT;
	GetWorld()->GetTimerManager().SetTimer( TT ,this, &AProjectile::TimeExpire, Delaytime,false );
}


void AProjectile::TimeExpire() 
{
	Destroy();
}
// Called every frame
//void AProjectile::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}

