// Fill out your copyright notice in the Description page of Project Settings.


#include "ColliderMovementComponent.h"

void UColliderMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!PawnOwner || !UpdatedComponent || ShouldSkipUpdate(DeltaTime))
	{
		return;
	}
	FVector DesiredMovementThisFrame = ConsumeInputVector().GetClampedToMaxSize(1.0f);
	// 길이가 Value인 이 벡터의 복사본을 만들어서 반환하는 함수
	if (!DesiredMovementThisFrame.IsNearlyZero())
	{
		FHitResult Hit;
		SafeMoveUpdatedComponent(DesiredMovementThisFrame, UpdatedComponent->GetComponentRotation(), true, Hit);
		if (Hit.IsValidBlockingHit())
		{
			SlideAlongSurface(DesiredMovementThisFrame, 1.f - Hit.Time, Hit.Normal, Hit);
		}
	}
}