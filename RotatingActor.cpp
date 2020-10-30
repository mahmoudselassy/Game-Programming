// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatingActor.h"

// Sets default values
ARotatingActor::ARotatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    PitchValue=0.0f;
	YawValue=0.0f;
	RowValue=0.0f;
}

// Called when the game starts or when spawned
void ARotatingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARotatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FQuat QuatRotation=FQuat(FRotator(PitchValue,YawValue,RowValue));
	AddActorLocalRotation(QuatRotation,false,0,ETeleportType::None);
	
	
}

