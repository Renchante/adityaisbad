// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehicle.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "WheeledVehicleMovementComponent4W.h"

#include "ElectricCar_CPP.generated.h"

/**
 * 
 */
UCLASS()
class CREATION_API AElectricCar_CPP : public AWheeledVehicle
{
	GENERATED_BODY()
	
public:
	AElectricCar_CPP();

	virtual void Tick(float DeltaTime) override; 

	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;

	//Movement Car Declaration Functions (Throttle, Steering, HandBrake)
	UFUNCTION(BlueprintCallable)
	void Throttle(float value);

	UFUNCTION(BlueprintCallable)
	void Steering(float value);

	UFUNCTION(BlueprintCallable)
	void HandBrakeON();
	UFUNCTION(BlueprintCallable)
	void HandBrakeOFF();


	//Camera and Mouse Input Function (Pitch and Yaw)
	UFUNCTION(BlueprintCallable)
	void CameraPitch(float axisValue);

	UFUNCTION(BlueprintCallable)
	void CameraYaw(float axisValue);


protected:
	//Camera Components 
	UPROPERTY(EditAnywhere)
	class USpringArmComponent* SpringArm;
	
	UPROPERTY(EditAnywhere)
	class UCameraComponent* Camera;

};
