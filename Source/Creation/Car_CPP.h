// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Car_CPP.generated.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

UCLASS()
class CREATION_API ACar_CPP : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACar_CPP();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Components to be added in Blueprints
	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* CarMesh;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArm;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

};
