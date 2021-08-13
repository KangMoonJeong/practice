// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Boom.generated.h"

DECLARE_DELEGATE(FDele_Single);
DECLARE_DELEGATE_OneParam(FDele_Single_OneParam, int32);


UCLASS()
class PRACTICE_API ABoom : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoom();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	FDele_Single Fuc_DeleSingle;
	FDele_Single_OneParam Fuc_DeleSingle_OneParam;

	void Tick_Boom(float DeltaTime);
	void EndPlay(const EEndPlayReason::Type EndPlayReason);
};
