// Fill out your copyright notice in the Description page of Project Settings.


#include "Boom_Mul.h"

// Sets default values
ABoom_Mul::ABoom_Mul()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABoom_Mul::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABoom_Mul::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Fuc_DeleMulti.IsBound() == true) Fuc_DeleMulti.Broadcast();
	if (Fuc_DeleMulti_OneParam.IsBound() == true) Fuc_DeleMulti_OneParam.Broadcast(456);
}

void ABoom_Mul::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	//! 델리게이트 해제
	Fuc_DeleMulti.Clear();
	Fuc_DeleMulti_OneParam.Clear();
}