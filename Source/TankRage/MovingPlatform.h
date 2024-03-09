// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class TANKRAGE_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()
public:
	AMovingPlatform();
	UPROPERTY(EditAnywhere)
	float speed = 20.f;
	UPROPERTY(EditAnywhere, meta=(MakeEditWidget = true))
	FVector targetLocation;

private:
	FVector GlobalStartLocation;
	FVector GlobalTargetLocation;
	
protected:
	virtual void Tick(float DeltaSeconds) override;
	virtual void BeginPlay() override;	
};
