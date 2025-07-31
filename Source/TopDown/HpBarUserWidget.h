// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HpBarUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWN_API UHpBarUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY()
	class UCharacterInfo* CharacterInfo;
	UPROPERTY(meta =())
	class UProgressBar* PB_Bar;
public:
	void BindHp(class UCharacterInfo* Info);
	void UpdateHp();
	
};
