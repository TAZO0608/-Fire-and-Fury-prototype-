// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank_Controller.h"

ATank* ATank_Controller::GetTank() 
{
	return Cast<ATank >(GetPawn());
}





