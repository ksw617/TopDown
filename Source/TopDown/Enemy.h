// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemy.generated.h"

UCLASS()
class TOPDOWN_API AEnemy : public ACharacter
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly)
	bool bHighlighted = false;
	UPROPERTY(VisibleAnywhere)
	bool bIsAttacking = false;
	UPROPERTY()
	class UCharacterAnim* CharacterAnim;
	UPROPERTY(BlueprintReadOnly)
	class UWidgetComponent* HpBar;
	UPROPERTY()
	class UCharacterInfo* CharacterInfo;

public:
	// Sets default values for this character's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
public:
	void Highlight();
	void Unhighlight();
public:
	void Attack();
	void OnAttackHit(); 
	UFUNCTION()
	void OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted);
	void OnDead(AActor* DamageCauser);

};
