// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}

	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPositionNoScale(targetLocation);
}

void AMovingPlatform::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (HasAuthority())
	{
		FVector ActorLocation = GetActorLocation();
		float JourneyLength = (GlobalTargetLocation - GlobalStartLocation).Size();
		float JourneyTravelled = (ActorLocation - GlobalStartLocation).Size();
		if (JourneyTravelled >= JourneyLength)
		{
			FVector SwapStartTarget = GlobalStartLocation;
			GlobalStartLocation = GlobalTargetLocation;
			GlobalTargetLocation = SwapStartTarget;
		}
		FVector MovementDirection = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
		ActorLocation += speed * DeltaSeconds * MovementDirection;
		SetActorLocation(ActorLocation);
	}
}

