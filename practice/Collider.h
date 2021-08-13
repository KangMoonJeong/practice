// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Collider.generated.h"

UCLASS()
class PRACTICE_API ACollider : public APawn
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, Category = "Mesh");
	class UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, Category = "Mesh");
	class USphereComponent* Sphere;

	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	class UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, Category = "Mesh");
	class USpringArmComponent* SpringArm;

	FORCEINLINE UStaticMeshComponent* GetMesh() { return Mesh; }
	FORCEINLINE void SetMesh(UStaticMeshComponent* InMesh) { Mesh = InMesh; }

	FORCEINLINE USphereComponent* GetSphere() { return Sphere; }
	FORCEINLINE void SetSphere(USphereComponent* InSphere) { Sphere = InSphere; }

	FORCEINLINE UCameraComponent* GetCamera() { return Camera; }
	FORCEINLINE void SetCamera(UCameraComponent* InCamera) { Camera = InCamera; }

	FORCEINLINE USpringArmComponent* GetSpringArm() { return SpringArm; }
	FORCEINLINE void SetSpringArm(USpringArmComponent* InSpringArm) { SpringArm = InSpringArm; }


	UPROPERTY(VisibleAnywhere, Category = "Mesh");
	class UColliderMovementComponent* OurMovementComponent;



public:
	// Sets default values for this pawn's properties
	ACollider();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void MoveForward(float Value);
	void MoveRight(float Value);
	
	void PitchCamera(float AxisValue);
	void YawCamera(float AxisValue);
	FVector2D CameraInput;



public:
	UPROPERTY(EditAnywhere, Category = ATemp)
	int32 ClampTest;

	void ClampTestFunc();
};


