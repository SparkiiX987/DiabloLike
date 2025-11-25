#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SpellComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSpellCasted, float, ManaCost);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DIABLOLIKE_API USpellComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	USpellComponent();

	UPROPERTY(BlueprintAssignable)
	FOnSpellCasted OnSpellCasted;

	UFUNCTION(BlueprintCallable)
	void CastSpell(float ManaCost);

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
