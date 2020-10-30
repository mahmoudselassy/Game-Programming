// Fill out your copyright notice in the Description page of Project Settings.


#include "FindPlayerLocation.h"

// Sets default values
AFindPlayerLocation::AFindPlayerLocation()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFindPlayerLocation::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFindPlayerLocation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
/*	FVector MyCharacterLocation=GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	FRotator MyCharacterRotation=GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorRotation();
    if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1,2.0f,FColor::Purple,FString::Printf(TEXT("PlayerLocation is %s"),*MyCharacterLocation.ToString()));
		GEngine->AddOnScreenDebugMessage(-1,2.0f,FColor::Yellow,FString::Printf(TEXT("PlayerRotation is %s"),*MyCharacterRotation.ToString()));
	}
	*/
	SetA
}

