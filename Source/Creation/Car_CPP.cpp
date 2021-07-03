// Fill out your copyright notice in the Description page of Project Settings.


#include "Car_CPP.h"

// Sets default values
ACar_CPP::ACar_CPP()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//Initialize Components
	CarMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Car Mesh"));
	
	SpringArm = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Camera"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	

	RootComponent = CarMesh;
}

// Called when the game starts or when spawned
void ACar_CPP::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACar_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACar_CPP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

