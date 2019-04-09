// Fill out your copyright notice in the Description page of Project Settings.

#include "Turret.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"

// Sets default values
ATurret::ATurret()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TurretBody = CreateDefaultSubobject<UStaticMeshComponent>("Body");
	TurretBody->SetupAttachment(GetRootComponent());
	TurretBody->OnComponentHit.AddDynamic(this, &ATurret::OnComponentHit);

	Health = 100.f;

}

// when the turret is hit
void ATurret::OnComponentHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	Health -= 25.f;
	if (GEngine)
	{ // for showing current health of turret in scene
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::SanitizeFloat(Health)); 
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Turret health is:"));
	}
	if (Health == 0)
	{ 
		// calling function from ShooterMode with events to increase the score
		if (OnTurretKilled.IsBound())
		{
			OnTurretKilled.Broadcast();
		}

		// for showing the current score
		UWorld * CurrentWorld = GetWorld();
		if (CurrentWorld)
		{
			AShooterMode * GM = Cast<AShooterMode>(CurrentWorld->GetAuthGameMode());
			if (GM)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::SanitizeFloat(GM->GetScore()));
				GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Your score is:"));
			}
		}

		// destroying actor when the health is 0
		Destroy();
	}

}

// Called when the game starts or when spawned
void ATurret::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATurret::BeginDestroy()
{
	Super::BeginDestroy();
}

