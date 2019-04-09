// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ShooterMode.generated.h"

/**
 * 
 */
UCLASS()
class PZ_3_API AShooterMode : public AGameModeBase
{
	GENERATED_BODY()

    float Scores;

	virtual void BeginPlay() override;

public:
	UFUNCTION()
	void OnTurretKilled();

	UFUNCTION()
	float GetScore();
};
