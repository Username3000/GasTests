// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "MyAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class GASTESTS_API UMyAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool WasSuccessfullyAppliedEffect(FActiveGameplayEffectHandle Handle);

	UFUNCTION(BlueprintCallable)
	bool ApplyDamageEffect(TSubclassOf<UGameplayEffect> DamageEffect, float EffectLevel, AController* Instigator);
};
