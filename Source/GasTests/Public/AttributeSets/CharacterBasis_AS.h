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

DECLARE_MULTICAST_DELEGATE_OneParam(FOnWalkSpeedChangedSignature, float);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnAccelerationChangedSignature, float);

UCLASS()
class GASTESTS_API UCharacterBasis_AS : public UAttributeSet
{
	GENERATED_BODY()

public:

	UCharacterBasis_AS();
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const override;
	virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) override;

	FOnWalkSpeedChangedSignature OnWalkSpeedChangedSignature;
	FOnAccelerationChangedSignature OnAccelerationChangedSignature;

	void ClampAttributes(const FGameplayAttribute& Attribute, float& NewValue) const;

	//		ATTRIBUTES		//

	//Health
	UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing = OnRep_Health)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UCharacterBasis_AS, Health)
	
	//Max health
	UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing = OnRep_Health)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UCharacterBasis_AS, MaxHealth)

	//Walk speed
	UPROPERTY(BlueprintReadOnly, Category = "Movement", ReplicatedUsing = OnRep_Health)
	FGameplayAttributeData WalkSpeed;
	ATTRIBUTE_ACCESSORS(UCharacterBasis_AS, WalkSpeed)

	//Acceleration
	UPROPERTY(BlueprintReadOnly, Category = "Movement", ReplicatedUsing = OnRep_Acceleration)
	FGameplayAttributeData Acceleration;
	ATTRIBUTE_ACCESSORS(UCharacterBasis_AS, Acceleration)


	//		REPLICATION		//

	UFUNCTION()
	virtual void OnRep_Health(const FGameplayAttributeData& OldHealth);

	UFUNCTION()
	virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth);

	UFUNCTION()
	virtual void OnRep_WalkSpeed(const FGameplayAttributeData& OldWalkSpeed);

	UFUNCTION()
	virtual void OnRep_Acceleration(const FGameplayAttributeData& OldAcceleration);


};
