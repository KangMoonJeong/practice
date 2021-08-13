// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestPlayer_Mul.generated.h"

UCLASS()
class PRACTICE_API ATestPlayer_Mul : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestPlayer_Mul();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UFUNCTION()
	void CallDeleFunc_Multi_1();
	UFUNCTION()
	void CallDeleFunc_Multi_2();


	UFUNCTION()
	void CallDeleFunc_Multi_OneParam_1(int32 nValue);
	UFUNCTION()
	void CallDeleFunc_Multi_OneParam_2(int32 nValue);

	UPROPERTY(EditAnywhere)
	TArray<class ABoom_Mul*> Booms;
};
