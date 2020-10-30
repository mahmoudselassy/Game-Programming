// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "MyTriggerBoxActor.generated.h"

/**
 * 
 */
UCLASS()
class FPS_TEST2_API AMyTriggerBoxActor : public ATriggerBox
{
	GENERATED_BODY()
public:	
	
	AMyTriggerBoxActor();
	UFUNCTION()
	void OnOverlapBegin(class AActor* OverlappedActor,class AActor* OtherActor);
	UFUNCTION()
	void OnOverlapEnd(class AActor* OverlappedActor,class AActor* OtherActor);
	UPROPERTY(EditAnywhere)
	class AActor* SpecificActor;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	

	
};
