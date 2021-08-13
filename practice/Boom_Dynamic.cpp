// Fill out your copyright notice in the Description page of Project Settings.


#include "Boom_Dynamic.h"

// Sets default values
ABoom_Dynamic::ABoom_Dynamic()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABoom_Dynamic::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABoom_Dynamic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(Fuc_Dynamic.IsBound() == true)
		Fuc_Dynamic.Broadcast();

	if (Fuc_Dynamic_OneParam.IsBound() == true)
		Fuc_Dynamic_OneParam.Broadcast(999999);
}

void ABoom_Dynamic::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Fuc_Dynamic.Clear();
	Fuc_Dynamic_OneParam.Clear();
}