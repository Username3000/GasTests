// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "GameplayEffectTypes.h"
#include "MyAbilitySystemComponent.h"
#include "GameplayEffectTypes.h"
#include "AttributeSets/CharacterBasis_AS.h"

#include "MyCharacter.generated.h"

UCLASS()
class GASTESTS_API AMyCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UMyAbilitySystemComponent* AbilitySystemComponent;


public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//AbilitySystemComponent getr
	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	//		ATTRIBUTE SETS		//

	UPROPERTY()
	class UCharacterBasis_AS* CharacterBasis;


};
