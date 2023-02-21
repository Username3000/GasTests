// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributeSets/CharacterBasis_AS.h"
#include "Net/UnrealNetwork.h"

UCharacterBasis_AS::UCharacterBasis_AS() {}

void UCharacterBasis_AS::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UCharacterBasis_AS, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCharacterBasis_AS, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCharacterBasis_AS, WalkSpeed, COND_None, REPNOTIFY_Always);
}

void UCharacterBasis_AS::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);
	ClampAttributes(Attribute, NewValue);
}

void UCharacterBasis_AS::PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const
{
	Super::PreAttributeBaseChange(Attribute, NewValue);
	ClampAttributes(Attribute, NewValue);
}

void UCharacterBasis_AS::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
	if (Attribute == GetWalkSpeedAttribute())
	{
		OnWalkSpeedChangedSignature.Broadcast(NewValue);
	}
}

void UCharacterBasis_AS::ClampAttributes(const FGameplayAttribute& Attribute, float& NewValue) const
{
	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
	}
}

void UCharacterBasis_AS::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCharacterBasis_AS, Health, OldHealth)
}

void UCharacterBasis_AS::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCharacterBasis_AS, MaxHealth, OldMaxHealth)
}

void UCharacterBasis_AS::OnRep_WalkSpeed(const FGameplayAttributeData& OldWalkSpeed)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCharacterBasis_AS, WalkSpeed, OldWalkSpeed)
}
