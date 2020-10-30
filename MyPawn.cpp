// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include "Components/InputComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "TimerManager.h"



// Sets default values
AMyPawn::AMyPawn()
{
 	
	PrimaryActorTick.bCanEverTick = true;
	CapsuleCom=CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collider"));
	RootComponent = CapsuleCom;
	CameraCom=CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraCom->SetupAttachment(RootComponent);
	StaticMeshCom=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Component"));
	StaticMeshCom->SetupAttachment(RootComponent);
	
	
	

}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(FTH,this,&AMyPawn::Damage,DamageRate,true,1.0f);
}
// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(!MovementDirection.IsZero())
	{
		const FVector NewLocation=GetActorLocation()+(MovementDirection*DeltaTime*MovementSpeed);
		SetActorLocation(NewLocation);
		
	}
	
}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis(TEXT("MoveUp"),this,&AMyPawn::MoveForward);
	InputComponent->BindAxis(TEXT("MoveRight"),this,&AMyPawn::MoveRight);

}
void AMyPawn::MoveRight(float value)
{
	MovementDirection.Y=FMath::Clamp(value,-1.0f,1.0f);
}

void AMyPawn::MoveForward(float value)
{
	MovementDirection.X=FMath::Clamp(value,-1.0f,1.0f);
}

void AMyPawn::Damage() 
{   
	UE_LOG(LogTemp, Warning, TEXT("My Health is %f"),Health);
	Health=Health-1;
}
