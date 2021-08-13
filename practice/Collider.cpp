// Fill out your copyright notice in the Description page of Project Settings.


#include "Collider.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "ColliderMovementComponent.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
ACollider::ACollider()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(GetRootComponent());
	Sphere->InitSphereRadius(40.f);


	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(GetRootComponent());
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshComponentAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (MeshComponentAsset.Succeeded())
	{
		Mesh->SetStaticMesh(MeshComponentAsset.Object);
		Mesh->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
		Mesh->SetWorldScale3D(FVector(0.8f, 0.8f, 0.8f));

	}

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->SetRelativeRotation(FRotator(-45.f, 0.f, 0.f));
	SpringArm->bEnableCameraLag = true;
	SpringArm->TargetArmLength = 400.f;
	SpringArm->CameraLagSpeed = 3.f;
	
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

	OurMovementComponent = CreateDefaultSubobject<UColliderMovementComponent>(TEXT("MovementComponent"));
	OurMovementComponent->UpdatedComponent = RootComponent;

	CameraInput = FVector2D(0.f, 0.f);

	AutoPossessPlayer = EAutoReceiveInput::Player0;


	ClampTest = 4;

}

// Called when the game starts or when spawned
void ACollider::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACollider::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACollider::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ACollider::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ACollider::MoveRight);

	
	PlayerInputComponent->BindAction(TEXT("ClampTest"), EInputEvent::IE_Pressed, this, &ACollider::ClampTestFunc);
	
}

void ACollider::MoveForward(float input)
{
	FVector Forward = GetActorForwardVector();
	if (OurMovementComponent)
	{
		OurMovementComponent->AddInputVector(Forward * input);
	}
}

void ACollider::MoveRight(float input)
{
	FVector Right = GetActorRightVector();
	if (OurMovementComponent)
	{
		OurMovementComponent->AddInputVector(Right * input);
	}
}

void ACollider::PitchCamera(float AxisValue)
{
	CameraInput.X = AxisValue;
}

void ACollider::YawCamera(float AxisValue)
{
	CameraInput.Y = AxisValue;
} 

void ACollider::ClampTestFunc()
{
	ClampTest = FMath::Clamp(ClampTest, 1, 10);

	UE_LOG(LogTemp, Warning, TEXT("%d"), ClampTest);

}
