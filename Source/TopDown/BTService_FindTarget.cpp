// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_FindTarget.h"
#include "EnemyAIController.h"
#include "MyPlayer.h"
#include "Engine/OverlapResult.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_FindTarget::UBTService_FindTarget()
{
	NodeName = TEXT("Find Target");
	Interval = 1.f; //1��
}

void UBTService_FindTarget::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	
	auto Pawn = OwnerComp.GetAIOwner()->GetPawn();
	if (Pawn)
	{
		FVector Center = Pawn->GetActorLocation();
		float Range = 500.f;
		TArray<FOverlapResult> OverlapResults;
		FCollisionQueryParams QueryParams(NAME_None, false, Pawn);

		bool Result = GetWorld()->OverlapMultiByChannel
		(
			OUT OverlapResults,
			Center, 
			FQuat::Identity,
			ECollisionChannel::ECC_GameTraceChannel2,
			FCollisionShape::MakeSphere(Range),
			QueryParams
		);

		if (Result)
		{
			for (auto& OverlapResult : OverlapResults)
			{
				auto Player = Cast<AMyPlayer>(OverlapResult.GetActor());
				if (Player)
				{
					DrawDebugSphere(GetWorld(), Center, Range, 10, FColor::Green, false, 0.5f);
					OwnerComp.GetBlackboardComponent()->SetValueAsObject(FName("Target"), Player);
					return;
				}
			}

		}

		DrawDebugSphere(GetWorld(), Center, Range, 10, FColor::Red, false, 0.5f);
		OwnerComp.GetBlackboardComponent()->SetValueAsObject(FName("Target"), nullptr);

	}
}
