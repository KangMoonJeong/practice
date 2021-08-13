// Fill out your copyright notice in the Description page of Project Settings.


#include "Boom.h"

// Sets default values
ABoom::ABoom()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABoom::BeginPlay()
{
	Super::BeginPlay();
	Tick_Boom(1.0f);
	EndPlay(EEndPlayReason::Destroyed);

}

// Called every frame
void ABoom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*if (Fuc_DeleSingle.IsBound() == true)	Fuc_DeleSingle.Execute();
	if (Fuc_DeleSingle_OneParam.IsBound() == true) Fuc_DeleSingle_OneParam.Execute(123);*/

}

void ABoom::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	//! 델리게이트 해제
	Fuc_DeleSingle.Unbind();
	Fuc_DeleSingle_OneParam.Unbind();
}

void ABoom::Tick_Boom(float DeltaTime)
{
	//! Delegate호출하는 부분
	if (Fuc_DeleSingle.IsBound() == true)	Fuc_DeleSingle.Execute();
	if (Fuc_DeleSingle_OneParam.IsBound() == true) Fuc_DeleSingle_OneParam.Execute(123);
}