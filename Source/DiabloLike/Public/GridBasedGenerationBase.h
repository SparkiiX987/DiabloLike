#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RoomBase.h"
#include "GridBasedGenerationBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGenerationEnd);

UCLASS()
class DIABLOLIKE_API AGridBasedGenerationBase : public AActor
{
	GENERATED_BODY()
	
public:	
	AGridBasedGenerationBase();

	UFUNCTION(BlueprintCallable)
	void GenerateDunjon();

	UFUNCTION()
	FVector GetCellLocation(FIntPoint _cellPos);

	UFUNCTION()
	FIntPoint GetRoomCenter(int _cellIndex);

	UPROPERTY(BlueprintAssignable, Category = "Generation")
	FOnGenerationEnd OnGenerationEnd;

	UFUNCTION()
	const int32 GetRoomNumber() const;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = "true"))
	TSubclassOf<ARoomBase> gridPrefab;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = "true"))
	int32 roomNumber;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = "true"))
	FIntPoint cellSize;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = "true"))
	FIntPoint minRoomSize;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = "true"))
	FIntPoint maxRoomSize;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = "true"))
	FIntPoint gridSize;

	UPROPERTY()
	TMap<FIntPoint, ARoomBase*> grid;

	UPROPERTY()
	TArray<FIntPoint> roomsCenter;

	UFUNCTION()
	void GenerateGrid();

	UFUNCTION()
	void GenerateRooms();

	UFUNCTION()
	void GenerateCoridors();

	UFUNCTION()
	void CraveCorridor(int x1, int y1, int x2, int y2);

	UFUNCTION()
	bool IsRoomValid(int _roomPosX, int _roomPosY, int _roomSizeX, int _roomSizeY);

public:	
	virtual void Tick(float DeltaTime) override;

};
