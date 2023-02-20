// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "MyAbilitySystemComponent.h"

#include "CharacterBasis_AS.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)


UCLASS()
class GASTESTS_API UCharacterBasis_AS : public UAttributeSet
{
	GENERATED_BODY()

public:

	UCharacterBasis_AS();
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const override;

	void ClampAttributes(const FGameplayAttribute& Attribute, float& NewValue) const;

	//		ATTRIBUTES		//

	//Health
	UPROPERTY(BlueprintReadOnly, Category = "Health")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UCharacterBasis_AS, Health)
	
	//Max health
	UPROPERTY(BlueprintReadOnly, Category = "Health")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UCharacterBasis_AS, MaxHealth)

	//Walk speed    JumpVelocity
	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	FGameplayAttributeData WalkSpeed;
	ATTRIBUTE_ACCESSORS(UCharacterBasis_AS, WalkSpeed)
};
