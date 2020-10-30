// Fill out your copyright notice in the Description page of Project Settings.


#include "TimerTestAndSetViewTarget.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ATimerTest::ATimerTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
}

// Called when the game starts or when spawned
void ATimerTest::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(TH,this,&ATimerTest::RepeatingFunction,2.0f,true,5.0f);
	APlayerController* OurPlayer=UGameplayStatics::GetPlayerController(this,0);
	OurPlayer->SetViewTarget(MyActor);
	

	

     
}

// Called every frame
void ATimerTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ATimerTest::RepeatingFunction()
{
	if(GEngine)
	{
	    GEngine->AddOnScreenDebugMessage(-1,15.0f,FColor::Blue,TEXT("Hello %s"));
	}
}
