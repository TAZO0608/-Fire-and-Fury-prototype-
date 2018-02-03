// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTrack.h"
UMyTrack::UMyTrack()
{
	PrimaryComponentTick.bCanEverTick = true;
	
}
void  UMyTrack::BeginPlay()
{
	Super::BeginPlay();
	OnComponentHit.AddDynamic(this, &UMyTrack::OnHit);
}
void UMyTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	SideForce();
	Drive();
	currentThrottle = 0;
	//UE_LOG(LogTemp, Warning, TEXT("HIT"));
}
void UMyTrack::SetThrottle(float v) 
{
	//UE_LOG(LogTemp, Warning, TEXT("%f"), v);
	currentThrottle = FMath::Clamp<float>((currentThrottle + v), -1.25, 1.25);
	

}
void  UMyTrack::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)
{
	//Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}
void UMyTrack::SideForce() 
{
	auto SlipSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	auto DeltaTime = GetWorld()->GetDeltaSeconds();
	auto AAA = -1 * (SlipSpeed / DeltaTime) * GetRightVector();
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());

	if (!TankRoot) return;

	TankRoot->AddForce(0.5*AAA*(TankRoot->GetMass()));
}
void UMyTrack::Drive()
{
	auto Forceapply = GetForwardVector() * currentThrottle*MAXForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(Forceapply, ForceLocation);
}