// Fill out your copyright notice in the Description page of Project Settings.


#include "TestPlayer_Event.h"

// Sets default values
ATestPlayer_Event::ATestPlayer_Event()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestPlayer_Event::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestPlayer_Event::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

