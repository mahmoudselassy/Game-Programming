// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

class UCapsuleComponent;
class UCameraComponent;
class UStaticMeshComponent;
UCLASS()
class DAMAGE_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	//Variables
	UPROPERTY(VisibleAnywhere,Category="Components")
	UCapsuleComponent* CapsuleCom;
	UPROPERTY(VisibleAnywhere,Category="Components")
	UCameraComponent* CameraCom;
	UPROPERTY(VisibleAnywhere,Category="Components")
	UStaticMeshComponent* StaticMeshCom;
	UPROPERTY(EditAnywhere,Category="Speed")
	float MovementSpeed=100.0f;
	UPROPERTY(EditAnywhere,Category="Health")
	float Health=100.0f;
	UPROPERTY(VisibleAnywhere,Category="Health")
	float DamageRate=0.5f;
	FVector MovementDirection;
	FTimerHandle FTH;

	//Functions
	void MoveRight(float value);
	void MoveForward(float value);
	void Damage();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	

};
