// Fill out your copyright notice in the Description page of Project Settings.


#include "LightSwitch.h"

// Sets default values
ALightSwitch::ALightSwitch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	LightSwitch = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Switch"));
	LightSource = CreateDefaultSubobject<UPointLightComponent>(TEXT("Light"));

	RootComponent = CollisionComponent;
	LightSwitch->SetupAttachment(RootComponent);
	LightSource->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ALightSwitch::BeginPlay()
{
	Super::BeginPlay();

	toggleLight = false;
	
}

// Called every frame
void ALightSwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (toggleLight == true)
	{
		LightSource->SetIntensity(5000.0f);
	}
	else if (toggleLight == false)
	{
		LightSource->SetIntensity(0.0f);
	}

}

void ALightSwitch::Use_Implementation()
{
	toggleLight = (toggleLight == true) ? false : true;

}

