// Fill out your copyright notice in the Description page of Project Settings.

#include "PositionReport.h"
#include "GameFramework/Actor.h"


// Sets default values for this component's properties
UPositionReport::UPositionReport()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPositionReport::BeginPlay()
{
	Super::BeginPlay();

	AActor* owner = this->GetOwner();
	UE_LOG(LogTemp, Warning, TEXT("%s is at %s"), *owner->GetName(), *owner->GetTransform().GetLocation().ToString());

	owner->SetActorLocation(FVector(1, 1, 1));
	UE_LOG(LogTemp, Warning, TEXT("%s is at %s"), *owner->GetName(), *owner->GetTransform().GetLocation().ToString());

	
}


// Called every frame
void UPositionReport::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//UE_LOG(LogTemp, Log, TEXT(this->tra));
}

