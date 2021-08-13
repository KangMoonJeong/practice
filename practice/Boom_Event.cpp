// Fill out your copyright notice in the Description page of Project Settings.


#include "Boom_Event.h"

// Sets default values
ABoom_Event::ABoom_Event()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABoom_Event::BeginPlay()
{
	Super::BeginPlay();

	Fuc_DeleEvent.AddUFunction(this, TEXT("CallDeleFunc_Event"));
	Fuc_DeleEvent_OneParam.AddUFunction(this, TEXT("CallDeleFunc_Event_OneParam"));
}

// Called every frame
void ABoom_Event::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Fuc_DeleEvent.Broadcast();
	Fuc_DeleEvent_OneParam.Broadcast(10);

}
void ABoom_Event::CallDeleFunc_Event()
{
	UE_LOG(LogTemp, Warning, TEXT("ABoom_Event::CallDeleFunc_Event"));
}

void ABoom_Event::CallDeleFunc_Event_OneParam(int32 nValue)
{
	UE_LOG(LogTemp, Warning, TEXT("ABoom_Event::CallDeleFunc_Event_OneParam : %d"), nValue);
}

void ABoom_Event::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Fuc_DeleEvent.Clear();
	Fuc_DeleEvent_OneParam.Clear();
}