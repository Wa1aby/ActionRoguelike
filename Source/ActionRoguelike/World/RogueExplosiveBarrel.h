// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActionSystem/RogueAttributeSet.h"
#include "GameFramework/Actor.h"
#include "RogueExplosiveBarrel.generated.h"


class URogueActionComponent;
class UNiagaraComponent;
class UStaticMeshComponent;
class URadialForceComponent;


UCLASS()
class ACTIONROGUELIKE_API ARogueExplosiveBarrel : public AActor
{
	GENERATED_BODY()

	int32 HitCounter = 0;

	FTimerHandle DelayedExplosionHandle;

	float ExplosionDelayTime;

	bool bExploded = false;

protected:

	UPROPERTY(VisibleAnywhere, Category = Components)
	TObjectPtr<URogueActionComponent> ActionComp;

	UPROPERTY(VisibleAnywhere, Category = Components)
	TObjectPtr<UStaticMeshComponent> MeshComp;

	UPROPERTY(VisibleAnywhere, Category = Components)
	TObjectPtr<URadialForceComponent> ForceComp;

	UPROPERTY(VisibleAnywhere, Category = Components)
	TObjectPtr<UNiagaraComponent> ExplosionComp;

	UPROPERTY(VisibleAnywhere, Category = Components)
	TObjectPtr<UNiagaraComponent> FlamesFXComp;

	void Explode();

	void OnHealthAttributeChanged(float NewValue, const FAttributeModification& AttributeModification);
	
public:	
	ARogueExplosiveBarrel();

	virtual void PostInitializeComponents() override;
};
