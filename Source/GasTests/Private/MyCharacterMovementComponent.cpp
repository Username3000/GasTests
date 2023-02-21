// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacterMovementComponent.h"
#include "AttributeSets/CharacterBasis_AS.h"
#include "MyCharacter.h"

void UMyCharacterMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	UCharacterBasis_AS* attributeSet = Cast<AMyCharacter>(GetOwner())->CharacterBasis;
	attributeSet->OnWalkSpeedChangedSignature.AddUObject(this, &UMyCharacterMovementComponent::UpdateWalkSpeed);
	attributeSet->OnAccelerationChangedSignature.AddUObject(this, &UMyCharacterMovementComponent::UpdateAcceleration);

	MaxWalkSpeed = attributeSet->GetWalkSpeedAttribute().GetNumericValue(attributeSet);
	MaxAcceleration = attributeSet->GetAccelerationAttribute().GetNumericValue(attributeSet);
}

void UMyCharacterMovementComponent::UpdateWalkSpeed(float NewSpeed)
{
	MaxWalkSpeed = NewSpeed;
}

void UMyCharacterMovementComponent::UpdateAcceleration(float NewSpeed)
{
	MaxAcceleration = NewSpeed;
}
