// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Boom_Mul.generated.h"


DECLARE_MULTICAST_DELEGATE(FDele_Multi);
DECLARE_MULTICAST_DELEGATE_OneParam(FDele_Multi_OneParam, int32);


UCLASS()
class PRACTICE_API ABoom_Mul : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoom_Mul();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void EndPlay(const EEndPlayReason::Type EndPlayReason);

	FDele_Multi Fuc_DeleMulti;
	FDele_Multi_OneParam Fuc_DeleMulti_OneParam;
};
