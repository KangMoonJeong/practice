// Fill out your copyright notice in the Description page of Project Settings.

#include "TestPlayer_Mul.h"
#include "Boom_Mul.h"

// Sets default values
ATestPlayer_Mul::ATestPlayer_Mul()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestPlayer_Mul::BeginPlay()
{
	Super::BeginPlay();

	for (ABoom_Mul* Boom_d : Booms)
	{
		//! MultiCast
		Boom_d->Fuc_DeleMulti.AddUFunction(this, FName("CallDeleFunc_Multi_1"));
		Boom_d->Fuc_DeleMulti.AddUFunction(this, FName("CallDeleFunc_Multi_2"));
		Boom_d->Fuc_DeleMulti_OneParam.AddUFunction(this, FName("CallDeleFunc_Multi_OneParam_1"));
		Boom_d->Fuc_DeleMulti_OneParam.AddUFunction(this, FName("CallDeleFunc_Multi_OneParam_2"));
	}
}

// Called every frame
void ATestPlayer_Mul::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATestPlayer_Mul::CallDeleFunc_Multi_1()
{
	UE_LOG(LogTemp, Warning, TEXT("CallDeleFunc_Multi_1"));
}

void ATestPlayer_Mul::CallDeleFunc_Multi_2()
{
	UE_LOG(LogTemp, Warning, TEXT("CallDeleFunc_Multi_2"));
}

void ATestPlayer_Mul::CallDeleFunc_Multi_OneParam_1(int32 nValue)
{
	UE_LOG(LogTemp, Warning, TEXT("CallDeleFunc_Multi_OneParam_1 / %d"), nValue);
}

void ATestPlayer_Mul::CallDeleFunc_Multi_OneParam_2(int32 nValue)
{
	UE_LOG(LogTemp, Warning, TEXT("CallDeleFunc_Multi_OneParam_2 / %d"), nValue);
}