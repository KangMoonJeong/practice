// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorTest_Two.h"

// Sets default values
AActorTest_Two::AActorTest_Two()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AActorTest_Two::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AActorTest_Two::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

