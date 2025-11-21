#include "DungeonGamemode.h"

void ADungeonGamemode::StartDungeon()
{
    UWorld* world = GetWorld();
    if (!IsValid(world)) 
    {
        return;
    }

    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("World"));
    }

    dungeonGenerator = (AGridBasedGenerationBase*)world->SpawnActor(dungeonGeneration);
    dungeonGenerator->OnGenerationEnd.AddDynamic(this, &ADungeonGamemode::SpawnPlayer);
    dungeonGenerator->OnGenerationEnd.AddDynamic(this, &ADungeonGamemode::SpawnEnemiesAndObject);
    dungeonGenerator->GenerateDunjon();
    dungeonGenerator->OnGenerationEnd.Broadcast();
}

void ADungeonGamemode::SpawnPlayer()
{
	UWorld* world = GetWorld();
	if (!IsValid(world)) { return; }

    FIntPoint cellGridPosition = dungeonGenerator->GetRoomCenter(0);
    FVector playerSpawnLocation = dungeonGenerator->GetCellLocation(cellGridPosition);

    FTransform SpawnTransform;
    SpawnTransform.SetLocation(FVector(playerSpawnLocation.X, playerSpawnLocation.Y, playerSpawnLocation.Z + 100));
    SpawnTransform.SetRotation(FQuat::Identity);

    APawn* PlayerPawn = world->SpawnActor<APawn>(playerPawn, SpawnTransform);
    if (!PlayerPawn) return;

    APlayerController* PC = world->GetFirstPlayerController();
    if (PC)
        PC->Possess(PlayerPawn);
}

void ADungeonGamemode::SpawnEnemiesAndObject()
{
    UWorld* world = GetWorld();
    if (!IsValid(world)) { return; }

    TArray<int> roomsIndexWitEnemies;

    for (int i = 0; i < dungeonGenerator->GetRoomNumber() - 1;)
    {
        if (FMath::RandBool())
        {
            if (SpawnEnemie(roomsIndexWitEnemies, world))
            {
                i++;
            }
        }
        else
        {
            if (SpawnItem(roomsIndexWitEnemies, world))
            {
                i++;
            }
        }
    }
}

bool ADungeonGamemode::SpawnEnemie(TArray<int> _roomsIndexWitEnemies, UWorld* _world)
{
    int randomRoomIndex = FMath::RandRange(1, dungeonGenerator->GetRoomNumber() - 1);
    if (_roomsIndexWitEnemies.Contains(randomRoomIndex))
    {
        return false;
    }

    _roomsIndexWitEnemies.Add(randomRoomIndex);

    FIntPoint cellGridPosition = dungeonGenerator->GetRoomCenter(randomRoomIndex);
    FVector enemySpawnLocation = dungeonGenerator->GetCellLocation(cellGridPosition);

    FTransform SpawnTransform;
    SpawnTransform.SetLocation(FVector(enemySpawnLocation.X, enemySpawnLocation.Y, enemySpawnLocation.Z + 100));
    SpawnTransform.SetRotation(FQuat::Identity);

    int enemySpawnedIndex = FMath::RandRange(0, enemiesClasses.Num() - 1);

    _world->SpawnActor<APawn>(enemiesClasses[enemySpawnedIndex], SpawnTransform);

    return true;
}

bool ADungeonGamemode::SpawnItem(TArray<int> _roomsIndexWitEnemies, UWorld* _world)
{
    int randomRoomIndex = FMath::RandRange(1, dungeonGenerator->GetRoomNumber() - 1);
    if (_roomsIndexWitEnemies.Contains(randomRoomIndex))
    {
        return false;
    }

    _roomsIndexWitEnemies.Add(randomRoomIndex);

    FIntPoint cellGridPosition = dungeonGenerator->GetRoomCenter(randomRoomIndex);
    FVector itemSpawnLocation = dungeonGenerator->GetCellLocation(cellGridPosition);

    FTransform SpawnTransform;
    SpawnTransform.SetLocation(FVector(itemSpawnLocation.X, itemSpawnLocation.Y, itemSpawnLocation.Z + 20));
    SpawnTransform.SetRotation(FQuat::Identity);

    int itemSpawnedIndex = FMath::RandRange(0, itemsClasses.Num() - 1);

    _world->SpawnActor<AActor>(itemsClasses[itemSpawnedIndex], SpawnTransform);

    return true;
}
