// Fill out your copyright notice in the Description page of Project Settings.


#include "GetNumberOfPawns.h"

// Sets default values
AGetNumberOfPawns::AGetNumberOfPawns()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
     
}

// Called when the game starts or when spawned
void AGetNumberOfPawns::BeginPlay()
{
	Super::BeginPlay();
	int32 NumOfPawns=GetWorld()->GetNumPawns();
	if(GEngine)
	{
	    GEngine->AddOnScreenDebugMessage(-1,15.0f,FColor::Blue,FString::Printf(TEXT("%d"),NumOfPawns));
	}
	
}

// Called every frame
void AGetNumberOfPawns::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

