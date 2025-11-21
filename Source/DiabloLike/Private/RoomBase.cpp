#include "RoomBase.h"

ARoomBase::ARoomBase()
{
	PrimaryActorTick.bCanEverTick = true;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mesh"));
	mesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

void ARoomBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARoomBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARoomBase::ChangeCellType(CellType _newType)
{
	type = _newType;
	switch (_newType)
	{
	case CellType::WALL:
		mesh->SetStaticMesh(wallRoom);
		break;
	case CellType::EMPTY:
		mesh->SetStaticMesh(emptyRoom);
		break;
	case CellType::ROOM:
		mesh->SetStaticMesh(room);
		break;
	case CellType::CORRIDOR:
		mesh->SetStaticMesh(corridorRoom);
		break;
	}
}

const CellType ARoomBase::GetType() const
{
	return type;
}

