#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CoreCharacter.generated.h"

UCLASS()
class DIABLOLIKE_API ACoreCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ACoreCharacter();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, Category = "Character stats")
	float currentHealth;

	UPROPERTY(BlueprintReadWrite, Category = "Character stats")
	float maxHealth;

	UPROPERTY(BlueprintReadWrite, Category = "Character stats")
	float armor;

	UPROPERTY(BlueprintReadWrite, Category = "Character stats")
	float attackDamage;

	UPROPERTY(BlueprintReadWrite, Category = "Character stats")
	float attackSpeed;

	UPROPERTY(BlueprintReadWrite, Category = "Character stats")
	float movementSpeed;

	UPROPERTY(BlueprintReadWrite, Category = "Character stats")
	bool bIsDead;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Character Functions")
	void TakeDamages(float _amount);

	UFUNCTION(BlueprintCallable, Category = "Character Functions")
	void Heal(float _amount);

	UFUNCTION(BlueprintCallable, Category = "Character Functions")
	virtual void Revive();

	UFUNCTION(BlueprintCallable, Category = "Character Functions")
	void ModifyHealth(float _amount);

	UFUNCTION(BlueprintCallable, Category = "Character Functions")
	void ModifyDamages(float _amount);

	UFUNCTION(BlueprintCallable, Category = "Character Functions")
	void ModifyArmor(float _amount);

	UFUNCTION(BlueprintCallable, Category = "Character Functions")
	void ModifyAttackSpeed(float _amount);

	UFUNCTION(BlueprintCallable, Category = "Character Functions")
	void ModifyMovementSpeed(float _amount);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Character Functions")
	void OnDeath();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Character Functions")
	void Attack();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Character Functions")
	void OnHealthChange();
};
