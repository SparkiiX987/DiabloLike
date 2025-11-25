#include "ItemActor.h"

AItemActor::AItemActor()
{
	PrimaryActorTick.bCanEverTick = true;

	collider = CreateDefaultSubobject<UBoxComponent>(TEXT("collider"));
	collider->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mesh"));
	mesh->AttachToComponent(collider, FAttachmentTransformRules::KeepRelativeTransform);

	skeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("skeletal mesh"));
	skeletalMesh->AttachToComponent(collider, FAttachmentTransformRules::KeepRelativeTransform);
}

void AItemActor::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(itemContained))
	{
		if (IsValid(itemContained->itemMesh))
		{
			mesh->SetStaticMesh(itemContained->itemMesh);
		}
		else if (itemContained->itemSkeletalMesh)
		{
			skeletalMesh->SetSkeletalMesh(itemContained->itemSkeletalMesh);
		}
	}
	
}

void AItemActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

