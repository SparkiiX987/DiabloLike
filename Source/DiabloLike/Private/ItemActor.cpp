#include "ItemActor.h"

AItemActor::AItemActor()
{
	PrimaryActorTick.bCanEverTick = true;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mesh"));
	mesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

void AItemActor::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(itemContained))
	{
		mesh->SetStaticMesh(itemContained->itemMesh);
	}
	
}

void AItemActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

