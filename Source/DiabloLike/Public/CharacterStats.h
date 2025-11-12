// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CharacterStats.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class DIABLOLIKE_API UCharacterStats : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character stats")
	float health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character stats")
	float armor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character stats")
	float attackDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character stats")
	float attackSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character stats")
	float movementSpeed;
	
};
