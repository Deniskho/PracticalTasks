// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterMode.h"
#include "Kismet/GameplayStatics.h"
#include "Turret.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"

void AShooterMode::BeginPlay()
{
	TArray<AActor *> turretActors;
	UGameplayStatics::GetAllActorsOfClass(this, ATurret::StaticClass(), turretActors);
	for (AActor * turretActor : turretActors)
	{
		ATurret * turret = Cast<ATurret>(turretActor);
		if (turret)
		{
			turret->OnTurretKilled.AddUFunction(this, "OnTurretKilled");
		}
	}
}

void AShooterMode::OnTurretKilled()
{
	Scores += 50.f;
}

float AShooterMode::GetScore()
{
	return Scores;
}

