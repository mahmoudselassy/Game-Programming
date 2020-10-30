

#include "MyTriggerBoxActor.h"
#include "DrawDebugHelpers.h"



AMyTriggerBoxActor::AMyTriggerBoxActor() 
{
    OnActorBeginOverlap.AddDynamic(this,&AMyTriggerBoxActor::OnOverlapBegin);
    OnActorEndOverlap.AddDynamic(this,&AMyTriggerBoxActor::OnOverlapEnd);
}
void AMyTriggerBoxActor::BeginPlay() 
{   
    Super::BeginPlay();
    DrawDebugBox(GetWorld(),GetActorLocation(),GetComponentsBoundingBox().GetExtent(),FColor::Green,true,-1,0,5);
}

void AMyTriggerBoxActor::OnOverlapBegin(class AActor* OverlappedActor,class AActor* OtherActor) 
{
    if(OtherActor&&(OtherActor!=this)&&OtherActor==SpecificActor)
    { UE_LOG(LogTemp, Warning, TEXT("Hello"));}
}

void AMyTriggerBoxActor::OnOverlapEnd(class AActor* OverlappedActor,class AActor* OtherActor) 
{
    if(OtherActor&&(OtherActor!=this)&&OtherActor==SpecificActor)
     {UE_LOG(LogTemp, Warning, TEXT("Bye"));}
     

}




