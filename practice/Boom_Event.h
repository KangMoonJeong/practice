// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Boom_Event.generated.h"

UCLASS()
class PRACTICE_API ABoom_Event : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoom_Event();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



public:
	//! Event
	DECLARE_EVENT(ABoom, FDele_Event);
	DECLARE_EVENT_OneParam(ABoom, FDele_Event_OneParam, int32);

public:
	FDele_Event Fuc_DeleEvent;
	FDele_Event_OneParam Fuc_DeleEvent_OneParam;


public:
	UFUNCTION()
	void CallDeleFunc_Event();


	UFUNCTION()
	void CallDeleFunc_Event_OneParam(int32 nValue);

	void EndPlay(const EEndPlayReason::Type EndPlayReason);

};
