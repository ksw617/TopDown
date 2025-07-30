// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator_CheckAttackRange.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWN_API UBTDecorator_CheckAttackRange : public UBTDecorator
{
	GENERATED_BODY()
public:
	UBTDecorator_CheckAttackRange();
public:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
