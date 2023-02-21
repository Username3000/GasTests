// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "MyCharacterMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class GASTESTS_API UMyCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
	
private:
	virtual void BeginPlay() override;

	void UpdateWalkSpeed(float NewSpeed);
	void UpdateAcceleration(float NewSpeed);
};
