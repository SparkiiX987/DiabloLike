#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class ItemType : uint8
{
    WEAPON     UMETA(DisplayName = "Weapon"),
    HELMET     UMETA(DisplayName = "Helmet"),
    CHESTPLATE UMETA(DisplayName = "Chestplate"),
    BOOTS      UMETA(DisplayName = "Boots"),
    OTHER      UMETA(DisplayName = "Other")
};