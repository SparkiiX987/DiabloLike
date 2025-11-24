#include "GridBasedGenerationBase.h"
#include "DungeonGamemode.h"

AGridBasedGenerationBase::AGridBasedGenerationBase()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AGridBasedGenerationBase::GenerateDunjon()
{
	GenerateGrid();
	GenerateRooms();
	GenerateCoridors();
}

FVector AGridBasedGenerationBase::GetCellLocation(FIntPoint _cellPos)
{
	ARoomBase* cell = grid[FIntPoint(_cellPos.X, _cellPos.Y)];

	return cell->GetActorLocation();
}

FIntPoint AGridBasedGenerationBase::GetRoomCenter(int _cellIndex)
{
	return roomsCenter[_cellIndex];
}

const int32 AGridBasedGenerationBase::GetRoomNumber() const
{
	return roomNumber;
}

void AGridBasedGenerationBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGridBasedGenerationBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGridBasedGenerationBase::GenerateGrid()
{
	UWorld* world = GetWorld();
	if (IsValid(world))
	{
		for (int x = 0; x < gridSize.X; x++)
		{
			for (int y = 0; y < gridSize.Y; y++)
			{
				ARoomBase* gridCell = (ARoomBase*)world->SpawnActor(gridPrefab);
				if (IsValid(gridCell))
				{
					grid.Add(FIntPoint(x, y), gridCell);
					gridCell->SetOwner(this);
					gridCell->SetActorRelativeLocation(FVector(x * cellSize.X, y * cellSize.Y, 0));
					gridCell->ChangeCellType(CellType::EMPTY);
				}
			}
		}
	}
}

void AGridBasedGenerationBase::GenerateRooms()
{
	UWorld* world = GetWorld();
	if (IsValid(world))
	{
		int security = 0;
		int iteration = 0;
		while (iteration < roomNumber && security < 100)
		{
			security++;
			int randomPosX = FMath::RandRange(1, (gridSize.X - 2));
			int randomPosY = FMath::RandRange(1, (gridSize.Y - 2));

			int randomSizeX = FMath::RandRange(minRoomSize.X, maxRoomSize.X);
			int randomSizeY = FMath::RandRange(minRoomSize.Y, maxRoomSize.Y);

			if (IsRoomValid(randomPosX, randomPosY, randomSizeX, randomSizeY))
			{
				roomsCenter.Add(FIntPoint(randomPosX + randomSizeX / 2, randomPosY + randomSizeY / 2));
				for (int x = randomPosX; x < randomPosX + randomSizeX; x++)
				{
					for (int y = randomPosY; y < randomPosY + randomSizeY; y++)
					{
						grid[FIntPoint(x, y)]->ChangeCellType(CellType::ROOM);
					}
				}
				iteration++;
			}
		}
	}
}

void AGridBasedGenerationBase::GenerateCoridors()
{
	roomsCenter.Sort([](const FIntPoint& A, const FIntPoint& B) {
		return A.X < B.X;
		});

	for (int i = 0; i < roomsCenter.Num() - 1; i++)
	{
		FIntPoint& room1 = roomsCenter[i];
		FIntPoint& room2 = roomsCenter[i + 1];

		CraveCorridor(room1.X, room1.Y, room2.X, room2.Y);
	}
}

void AGridBasedGenerationBase::CraveCorridor(int x1, int y1, int x2, int y2)
{
	auto SetCell = [&](int x, int y) 
	{
		FIntPoint key(x, y);
		if (grid.Contains(key) && grid[key])
			grid[key]->ChangeCellType(CellType::CORRIDOR);
	};

	if (FMath::RandBool()) 
	{
		int step = x1 <= x2 ? 1 : -1;
		for (int x = x1; x != x2 + step; x += step) SetCell(x, y1);
		step = y1 <= y2 ? 1 : -1;
		for (int y = y1; y != y2 + step; y += step) SetCell(x2, y); 
	}
	else 
	{
		int step = y1 <= y2 ? 1 : -1;
		for (int y = y1; y != y2 + step; y += step) SetCell(x1, y);
		step = x1 <= x2 ? 1 : -1;
		for (int x = x1; x != x2 + step; x += step) SetCell(x, y2);
	}
}

bool AGridBasedGenerationBase::IsRoomValid(int _roomPosX, int _roomPosY, int _roomSizeX, int _roomSizeY)
{
	if (_roomPosX < 0 || _roomPosY < 0) 
	{ 
		return false;
	}
	if (_roomPosX + _roomSizeX > gridSize.X - 1)
	{
		return false;
	}
	if (_roomPosY + _roomSizeY > gridSize.Y - 1)
	{
		return false;
	}

	for (int x = _roomPosX; x < _roomPosX + _roomSizeX; x++)
	{
		for (int y = _roomPosY; y < _roomPosY + _roomSizeY; y++)
		{
			FIntPoint key(x, y);
			if (!grid.Contains(key) || grid[key]->GetType() != CellType::EMPTY)
			{
				return false;
			}

		}
	}

	return true;
}
