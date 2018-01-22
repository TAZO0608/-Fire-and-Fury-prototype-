// Fill out your copyright notice in the Description page of Project Settings.

#include "Aim_Component.h"


// Sets default values for this component's properties
UAim_Component::UAim_Component()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAim_Component::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAim_Component::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
void UAim_Component::FinalToAim(FVector hitlocation) 
{
	
	UE_LOG(LogTemp, Warning, TEXT("%s>>%s"), *(GetOwner()->GetName()), *(hitlocation.ToString()));
};

