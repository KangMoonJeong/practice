// Fill out your copyright notice in the Description page of Project Settings.


#include "Boom.h"
#include "TestPlayer.h"
// Sets default values
ATestPlayer::ATestPlayer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestPlayer::BeginPlay()
{
	Super::BeginPlay();

	for (ABoom* Boom_d : Booms)
	{
		Boom_d->Fuc_DeleSingle.BindUFunction(this, TEXT("CallDeleFunc_Single"));
		Boom_d->Fuc_DeleSingle_OneParam.BindUFunction(this, FName("CallDeleFunc_Single_OneParam"));
	}

}

// Called every frame
void ATestPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATestPlayer::CallDeleFunc_Single()
{
	UE_LOG(LogTemp, Warning, TEXT("CallDeleFunc_Single"));
}

void ATestPlayer::CallDeleFunc_Single_OneParam(int32 nValue)
{
	UE_LOG(LogTemp, Warning, TEXT("CallDeleFunc_Single_OneParam / %d"), nValue);
}