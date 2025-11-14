// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ItemType.h"
#include "BaseItem.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class DIABLOLIKE_API UBaseItem : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UStaticMesh> itemMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UMaterialInterface> itemImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float bonusDamages;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float bonusArmor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float bonusHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float bonusAS;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float bonusMS;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ItemType itemType;
};
