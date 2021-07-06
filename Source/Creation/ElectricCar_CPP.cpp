// Fill out your copyright notice in the Description page of Project Settings.


#include "ElectricCar_CPP.h"

AElectricCar_CPP::AElectricCar_CPP()
{
	UWheeledVehicleMovementComponent4W* vehicleMovement = CastChecked<UWheeledVehicleMovementComponent4W>(GetVehicleMovementComponent());

	//Tire Load
	vehicleMovement->MinNormalizedTireLoad = 0.0f;
	vehicleMovement->MinNormalizedTireLoadFiltered = 0.2f;
	vehicleMovement->MaxNormalizedTireLoad = 2.0f;
	vehicleMovement->MaxNormalizedTireLoadFiltered = 2.0f;

	//Torque Setup
	vehicleMovement->MaxEngineRPM = 5700.0f;
	vehicleMovement->EngineSetup.TorqueCurve.GetRichCurve()->Reset();
	vehicleMovement->EngineSetup.TorqueCurve.GetRichCurve()->AddKey(0.0f, 400.0f);
	vehicleMovement->EngineSetup.TorqueCurve.GetRichCurve()->AddKey(1890.0f, 500.0f);
	vehicleMovement->EngineSetup.TorqueCurve.GetRichCurve()->AddKey(5730.0f, 400.0f);

	//Steering Setup
	vehicleMovement->SteeringCurve.GetRichCurve()->Reset();
	vehicleMovement->SteeringCurve.GetRichCurve()->AddKey(0.0f, 1.0f);
	vehicleMovement->SteeringCurve.GetRichCurve()->AddKey(40.0f, 0.7f);
	vehicleMovement->SteeringCurve.GetRichCurve()->AddKey(120.0f, 0.6f);

	vehicleMovement->DifferentialSetup.DifferentialType = EVehicleDifferential4W::LimitedSlip_4W;
	vehicleMovement->DifferentialSetup.FrontRearSplit = 0.65f;

	//Gear Box Setup (Automatic)
	vehicleMovement->TransmissionSetup.bUseGearAutoBox = true;
	vehicleMovement->TransmissionSetup.GearSwitchTime = 0.15f;
	vehicleMovement->TransmissionSetup.GearAutoBoxLatency = 1.0f;


	//Setting up the spring arm and camera components 
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 1000.0f;
	SpringArm->bUsePawnControlRotation = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
}

void AElectricCar_CPP::Tick(float DeltaTime)
{

}

void AElectricCar_CPP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Axis Inputs Car Movements (Moveing forward and turning)
	PlayerInputComponent->BindAxis("MoveForward", this, &AElectricCar_CPP::Throttle);
	PlayerInputComponent->BindAxis("MoveRight", this, &AElectricCar_CPP::Steering);

	//Axis Inputs Camera (Pitch and Yaw Camera)
	PlayerInputComponent->BindAxis("LookUp", this, &AElectricCar_CPP::CameraPitch);
	PlayerInputComponent->BindAxis("Turn", this, &AElectricCar_CPP::CameraYaw);

	//Action Inputs (Handbrake on and off)
	PlayerInputComponent->BindAction("Handbrake", IE_Pressed, this, &AElectricCar_CPP::HandBrakeON);
	PlayerInputComponent->BindAction("Handbrake", IE_Released, this, &AElectricCar_CPP::HandBrakeOFF);
}


//Car Movement Definition Functions (Throttle and Steering)
void AElectricCar_CPP::Throttle(float value)
{
	GetVehicleMovementComponent()->SetThrottleInput(value);
}

void AElectricCar_CPP::Steering(float value)
{
	GetVehicleMovementComponent()->SetSteeringInput(value);
}


//Handbrake Definition Functions
void AElectricCar_CPP::HandBrakeON()
{
	GetVehicleMovementComponent()->SetHandbrakeInput(true);
}

void AElectricCar_CPP::HandBrakeOFF()
{
	GetVehicleMovementComponent()->SetHandbrakeInput(false);
}


//Camera Definition Functions (Pitch and Yaw)
void AElectricCar_CPP::CameraPitch(float axisValue)
{
	if (axisValue != 0.0f)
	{
		AddControllerPitchInput(axisValue);
	}
}

void AElectricCar_CPP::CameraYaw(float axisValue)
{
	if (axisValue != 0.0f)
	{
		AddControllerYawInput(axisValue);
	}
}
