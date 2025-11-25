#include "SpellComponent.h"

USpellComponent::USpellComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void USpellComponent::CastSpell(float ManaCost)
{
	OnSpellCasted.Broadcast(ManaCost);
}

void USpellComponent::BeginPlay()
{
	Super::BeginPlay();

	
}


void USpellComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

