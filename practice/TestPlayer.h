// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestPlayer.generated.h"

UCLASS()
class PRACTICE_API ATestPlayer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//class ABoom* m_pBoom;

	UFUNCTION()
	void CallDeleFunc_Single();
	UFUNCTION()
	void CallDeleFunc_Single_OneParam(int32 nValue);


	UPROPERTY(EditAnywhere)
	TArray<class ABoom*> Booms;
};
