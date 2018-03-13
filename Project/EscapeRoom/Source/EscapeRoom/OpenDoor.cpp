// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "Engine/World.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	this->player = this->GetWorld()->GetFirstPlayerController()->GetPawn();
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	bool is = this->pressurePlate->IsOverlappingActor(this->player);
	FString a = this->GetOwner()->GetName() + " " + this->pressurePlate->GetName() + " " + this->player->GetName() + " " + (is ? "true" : "false");
	UE_LOG(LogTemp, Warning, TEXT("%s"), *a);
	if (pressurePlate->IsOverlappingActor(player))
	{
		this->Open();
	}
}

void UOpenDoor::Open()
{
	AActor* owner = GetOwner();
	owner->SetActorRotation(FRotator(0, -60, 0));
}
