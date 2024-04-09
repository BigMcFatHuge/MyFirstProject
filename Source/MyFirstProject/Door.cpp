// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	DoorFrame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Frame"));
	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));

	RootComponent = CollisionComponent;
	DoorFrame->SetupAttachment(RootComponent);
	Door->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float newRotation;

	if (isOpen == true)
	{
		newRotation = 90.0f;
	}
	else if (isOpen == false)
	{
		newRotation = 0.0f;
	}

	FRotator newLocation = Door->GetRelativeRotation();

	newLocation.Yaw = newRotation;

	Door->SetRelativeRotation(newLocation);

}

void ADoor::Use_Implementation()
{
	isOpen = (isOpen == true) ? false : true;

}

