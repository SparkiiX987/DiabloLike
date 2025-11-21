// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class CellType : uint8
{
    EMPTY    UMETA(DisplayName = "Empty"),
    ROOM     UMETA(DisplayName = "Room"),
    CORRIDOR UMETA(DisplayName = "Corridor"),
    WALL     UMETA(DisplayName = "Wall"),
};
