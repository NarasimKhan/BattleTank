// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()


public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	ATank* GetControlledTank() const;
	
	// Start the tank moving the barrel so that shot would hit where crosshaid intersect the world
	void AimTowardsCrosshair();

	// Return out parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	
	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = 0.5;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 0.3333;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
