// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Floater.generated.h"

UCLASS()
class PRACTICE_API AFloater : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloater();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Floater Variables")
	UStaticMeshComponent* Mesh;
	

	UPROPERTY(EditAnywhere, Category = "Floater Variables")
	FVector InitialLocation;

	UPROPERTY(EditAnywhere, Category = "Floater Variables")
	FVector DirectLocation;
	
	UPROPERTY(EditAnywhere, Category = "Floater Variables")
	FVector PlacedLocation;

	UPROPERTY(EditDefaultsOnly, Category = "Floater Variables")
	bool bShouldFloat;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
