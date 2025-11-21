#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseItem.h"
#include "ItemActor.generated.h"

UCLASS()
class DIABLOLIKE_API AItemActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AItemActor();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = "true"))
	TObjectPtr<UStaticMeshComponent> mesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TObjectPtr<UBaseItem> itemContained;

public:	
	virtual void Tick(float DeltaTime) override;

};
