#include "CoreCharacter.h"

ACoreCharacter::ACoreCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ACoreCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACoreCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACoreCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float ACoreCharacter::DamagesMitigation(float _baseDamage)
{
	return (_baseDamage / (1 + (armor / 100)));
}

void ACoreCharacter::TakeDamages(float _amount)
{
	float postMitigationDamages = DamagesMitigation(_amount);
	currentHealth -= postMitigationDamages;
	OnHealthChange();
	if (currentHealth <= 0)
	{
		bIsDead = true;
		OnDeath();
	}
}

void ACoreCharacter::Heal(float _amount)
{
	if (currentHealth == maxHealth) { return; }

	currentHealth = currentHealth + _amount > maxHealth ? maxHealth : currentHealth + _amount;
	OnHealthChange();
}

void ACoreCharacter::Revive()
{
	if (!bIsDead) { return; }

	currentHealth = maxHealth * 1.25f;
	bIsDead = false;
	OnHealthChange();
}

void ACoreCharacter::ModifyHealth(float _amount)
{
	maxHealth += _amount;
}

void ACoreCharacter::ModifyDamages(float _amount)
{
	attackDamage += _amount;
}

void ACoreCharacter::ModifyArmor(float _amount)
{
	armor += _amount;
}

void ACoreCharacter::ModifyAttackSpeed(float _amount)
{
	attackSpeed += _amount;
}

void ACoreCharacter::ModifyMovementSpeed(float _amount)
{
	movementSpeed += _amount;
}

void ACoreCharacter::SetupStats(UCharacterStats* _stats)
{
	if (IsValid(_stats))
	{
		maxHealth = _stats->health;
		currentHealth = _stats->health;
		armor = _stats->armor;
		attackDamage = _stats->attackDamage;
		attackSpeed = _stats->attackSpeed;
		movementSpeed = _stats->movementSpeed;
	}
}
