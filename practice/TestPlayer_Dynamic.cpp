// Fill out your copyright notice in the Description page of Project Settings.


#include "TestPlayer_Dynamic.h"
#include "Boom_Dynamic.h"



// Sets default values
ATestPlayer_Dynamic::ATestPlayer_Dynamic()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestPlayer_Dynamic::BeginPlay()
{
	Super::BeginPlay();
	for (ABoom_Dynamic* boom : Booms)
	{
		
		boom->Fuc_Dynamic.AddDynamic(this, &ATestPlayer_Dynamic::Call_DeleFunc_Dynamic);
		boom->Fuc_Dynamic_OneParam.AddDynamic(this, &ATestPlayer_Dynamic::Call_DeleFunc_Dynamic_OneParam);
	}

}

// Called every frame
void ATestPlayer_Dynamic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATestPlayer_Dynamic::Call_DeleFunc_Dynamic()
{
	UE_LOG(LogTemp, Warning, TEXT("ATestPlayer_Dynamic::CallDeleFunc_Dynamic()"));
}

void ATestPlayer_Dynamic::Call_DeleFunc_Dynamic_OneParam(int abc)
{
	UE_LOG(LogTemp, Warning, TEXT("CallDeleFunc_Dynamic_OneParam()    %d"), abc);
}

