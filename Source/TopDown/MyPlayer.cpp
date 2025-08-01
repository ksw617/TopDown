// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Enemy.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AMyPlayer::AMyPlayer()
{

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true);
	CameraBoom->TargetArmLength = 800.0f;
	CameraBoom->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	
}

void AMyPlayer::ApplyDamage(AActor* actor)
{
	auto Enemy = Cast<AEnemy>(actor);
	if (Enemy)
	{
		UGameplayStatics::ApplyDamage(Enemy, 10.f, GetController(), nullptr, NULL);
	}
}

void AMyPlayer::OnDead(AActor* DamageCauser)
{
	//Todo
	UE_LOG(LogTemp, Log, TEXT("OnDead"));
}

