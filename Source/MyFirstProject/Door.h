// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "UseableInterface.h"
#include "Door.generated.h"

UCLASS()
class MYFIRSTPROJECT_API ADoor : public AActor, public IUseableInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* CollisionComponent;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* DoorFrame;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Door;

	bool isOpen;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Use_Implementation() override;

};
