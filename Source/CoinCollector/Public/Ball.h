// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Ball.generated.h"

UCLASS()
class COINCOLLECTOR_API ABall : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Basic Component")
	UStaticMeshComponent* StatMeshComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Basic Component")
	USpringArmComponent* SpriArmComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Basic Component")
	UCameraComponent* CamComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basic Component")
		float MovementForce;

	void MoveUp(float value);
	void MoveRight(float value);


};
