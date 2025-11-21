#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CellType.h"
#include "RoomBase.generated.h"

UCLASS()
class DIABLOLIKE_API ARoomBase : public AActor
{
	GENERATED_BODY()
	
public:	
	ARoomBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = "true"))
	TObjectPtr<UStaticMeshComponent> mesh;

public:	
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable)
	void ChangeCellType(CellType _newType);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	const CellType GetType() const;

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	CellType type = CellType::EMPTY;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TObjectPtr<UStaticMesh> emptyRoom;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TObjectPtr<UStaticMesh> room;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TObjectPtr<UStaticMesh> wallRoom;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TObjectPtr<UStaticMesh> corridorRoom;
};
