// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ActorTest_Two.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorTest.generated.h"

UCLASS()
class PRACTICE_API AActorTest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActorTest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(EditAnywhere, Category = "ATemp")
	TArray<class AActorTest_Two*> P_Array_ActorTest_Two;

	UPROPERTY(EditAnywhere, Category = "ATemp")
	AActorTest_Two* P_ActorTest_Two;




};
