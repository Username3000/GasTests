// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAbilitySystemComponent.h"

bool UMyAbilitySystemComponent::WasSuccessfullyAppliedEffect(FActiveGameplayEffectHandle Handle)
{
	return Handle.WasSuccessfullyApplied();
}

bool UMyAbilitySystemComponent::ApplyDamageEffect(TSubclassOf<UGameplayEffect> DamageEffect, float EffectLevel, AController* Instigator)
{

	if (!IsValid(DamageEffect))
	{
		return false;
	}

	FGameplayEffectContextHandle EffectContext = MakeEffectContext();
	EffectContext.AddSourceObject(this);

	FGameplayEffectSpecHandle SpecHandle = MakeOutgoingSpec(DamageEffect, EffectLevel, EffectContext);
	FActiveGameplayEffectHandle EffectHandle = ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());

	return EffectHandle.WasSuccessfullyApplied();
}
