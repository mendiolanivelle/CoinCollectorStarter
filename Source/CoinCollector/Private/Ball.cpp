// Fill out your copyright notice in the Description page of Project Settings.

#include "Ball.h"


// Sets default values
ABall::ABall()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StatMeshComp = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SpriArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	CamComp = CreateDefaultSubobject<UCameraComponent>("Camera");
	
	RootComponent = StatMeshComp;
	SpriArmComp->SetupAttachment(StatMeshComp);
	CamComp->SetupAttachment(SpriArmComp);

	StatMeshComp->SetSimulatePhysics(true);
	MovementForce = 1000000;

}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

// Called to bind functionality to input
void ABall::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("MoveUp", this, &ABall::MoveUp);
	InputComponent->BindAxis("MoveRight", this, &ABall::MoveRight);

}

void ABall::MoveUp(float value)
{
	FVector ForceToAdd = FVector(1, 0, 0) * value * MovementForce;
	StatMeshComp->AddForce(ForceToAdd);
}

void ABall::MoveRight(float value)
{
	FVector ForceToAdd = FVector(0, 1, 0) * value * MovementForce;
	StatMeshComp->AddForce(ForceToAdd);
}

