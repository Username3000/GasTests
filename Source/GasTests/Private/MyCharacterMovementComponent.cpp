// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacterMovementComponent.h"
#include "AttributeSets/CharacterBasis_AS.h"
#include "MyCharacter.h"

void UMyCharacterMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	UCharacterBasis_AS* attributeSet = Cast<AMyCharacter>(GetOwner())->CharacterBasis;
	attributeSet->OnWalkSpeedChangedSignature.AddUObject(this, &UMyCharacterMovementComponent::UpdateWalkSpeed);
	MaxWalkSpeed = attributeSet->GetWalkSpeedAttribute().GetNumericValue(attributeSet);
}

void UMyCharacterMovementComponent::UpdateWalkSpeed(float NewSpeed)
{
	MaxWalkSpeed = NewSpeed;
}
