// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PCGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PRACTICE_API UPCGameInstance : public UGameInstance
{
	GENERATED_BODY()
	

public:
	UPCGameInstance();
	void Init();
	
};
