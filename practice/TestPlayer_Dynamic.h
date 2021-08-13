// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestPlayer_Dynamic.generated.h"

UCLASS()
class PRACTICE_API ATestPlayer_Dynamic : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestPlayer_Dynamic();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


public:
	void Call_DeleFunc_Dynamic();
	void Call_DeleFunc_Dynamic_OneParam(int abc);

	UPROPERTY(EditAnywhere)
	TArray<class ABoom_Dynamic*> Booms;

};
