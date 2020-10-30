// Fill out your copyright notice in the Description page of Project Settings.


#include "OnHit.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AOnHit::AOnHit()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    MyBox=CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	MyBox->SetSimulatePhysics(true);
	MyBox->SetNotifyRigidBodyCollision(true);
	MyBox->BodyInstance.SetCollisionProfileName("BlockAllDynamic");
	MyBox->OnComponentHit.AddDynamic(this,&AOnHit::OnCompHit);
	RootComponent=MyBox;



}

// Called when the game starts or when spawned
void AOnHit::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOnHit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
void AOnHit::OnCompHit(UPrimitiveComponent *HitComp, AActor *OtherActor, UPrimitiveComponent *OtherComp, FVector NormalImpulse, const FHitResult &Hit)
{
	if((OtherActor!=NULL)&&(OtherActor!=this)&&(OtherComp!=NULL))
	{
		if(GEngine)
		{
			 GEngine->AddOnScreenDebugMessage(-1,15.0f,FColor::Blue,FString::Printf(TEXT("This Hit : %s"),*OtherActor->GetName()));
		}
	}
}
