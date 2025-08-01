// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "EnemyAIController.h"
#include "Kismet/GameplayStatics.h"
#include "MyPlayer.h"


// Sets default values
AEnemy::AEnemy()
{

	AIControllerClass = AEnemyAIController::StaticClass(); 
}

void AEnemy::Highlight()
{
	bHighlighted = true;
	GetMesh()->SetRenderCustomDepth(true);
	
}



void AEnemy::Unhighlight()
{
	bHighlighted = false;
	GetMesh()->SetRenderCustomDepth(false);
}



void AEnemy::ApplyDamage(AActor* actor)
{
	auto Player = Cast<AMyPlayer>(actor);
	if (Player)
	{
		UGameplayStatics::ApplyDamage(Player, 10.f, GetController(), nullptr, NULL);
	}
}


void AEnemy::OnDead(AActor* DamageCauser)
{
	//Todo
	UE_LOG(LogTemp, Log, TEXT("OnDead"));
}
