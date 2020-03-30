// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"



// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//Setup pawn movement
	pawn_movement_ = CreateDefaultSubobject<UFloatingPawnMovement>("PawnMovement");

	//Setup static mesh
	static_mesh_ = CreateDefaultSubobject< UStaticMeshComponent >("StaticMesh");

	//Setup camera
	camera_ = CreateDefaultSubobject< UCameraComponent>("Camera");
	camera_->SetRelativeLocation(FVector(-500.f, 0.f, 0.f));
	camera_->SetupAttachment(static_mesh_);
	
	//Set root component
	SetRootComponent(static_mesh_);

	//Auto posses pawn to player0
	AutoPossessPlayer = EAutoReceiveInput::Player0;
		
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAxis("MoveForward", this, &AMyPawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyPawn::MoveRight);
}

void AMyPawn::MoveForward(float value) 
{
	pawn_movement_->AddInputVector(GetActorForwardVector() * value);
	
}

void AMyPawn::MoveRight(float value)
{
	pawn_movement_->AddInputVector(GetActorRightVector() * value);
}