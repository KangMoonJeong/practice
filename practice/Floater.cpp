// Fill out your copyright notice in the Description page of Project Settings.


#include "Floater.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AFloater::AFloater()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));

	bShouldFloat = false;

}

// Called when the game starts or when spawned
void AFloater::BeginPlay()
{
	Super::BeginPlay();
	
	InitialLocation = GetActorLocation();

	SetActorLocation(PlacedLocation);

}

// Called every frame
void AFloater::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bShouldFloat)
	{
		FHitResult HitResult;
		AddActorWorldOffset(DirectLocation, false, &HitResult);
	}
}

