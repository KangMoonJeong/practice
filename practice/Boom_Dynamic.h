// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Boom_Dynamic.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDele_Dynamic);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDele_Dynamic_OneParam, int32, SomeParameter);

UCLASS()
class PRACTICE_API ABoom_Dynamic : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoom_Dynamic();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(BlueprintAssignable, VisibleAnywhere, BlueprintCallable, Category = "Event")
	FDele_Dynamic Fuc_Dynamic;

	UPROPERTY(BlueprintAssignable, VisibleAnywhere, BlueprintCallable, Category = "Event")
	FDele_Dynamic_OneParam Fuc_Dynamic_OneParam;


	void EndPlay(const EEndPlayReason::Type EndPlayReason);
};