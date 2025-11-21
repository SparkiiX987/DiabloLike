#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GridBasedGenerationBase.h"
#include "ItemActor.h"
#include "DungeonGamemode.generated.h"

UCLASS()
class DIABLOLIKE_API ADungeonGamemode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AGridBasedGenerationBase> dungeonGeneration;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<APawn> playerPawn;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<TSubclassOf<APawn>> enemiesClasses;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<TSubclassOf<AItemActor>> itemsClasses;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TObjectPtr<AGridBasedGenerationBase> dungeonGenerator;

protected:
	UFUNCTION(BlueprintCallable)
	void StartDungeon();

	UFUNCTION()
	void SpawnPlayer();

	UFUNCTION()
	void SpawnEnemiesAndObject();

	UFUNCTION()
	bool SpawnEnemie(TArray<int> _roomsIndexWitEnemies, UWorld* _world);

	UFUNCTION()
	bool SpawnItem(TArray<int> _roomsIndexWitEnemies, UWorld* _world);
};
