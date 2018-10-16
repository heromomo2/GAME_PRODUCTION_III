// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "GAME_PRODUCTION_IIICharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Engine/GameEngine.h"// i add this header

AGAME_PRODUCTION_IIICharacter::AGAME_PRODUCTION_IIICharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	

	// Don't rotate when the controller rotates.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Create a camera boom attached to the root (capsule)
	//CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	//CameraBoom->SetupAttachment(RootComponent);
	//CameraBoom->bAbsoluteRotation = true; // Rotation of the character should not affect rotation of boom
	//CameraBoom->bDoCollisionTest = false;
	//CameraBoom->TargetArmLength = 2900.f;
	//CameraBoom->SocketOffset = FVector(0.f,0.f,0.f);
	//CameraBoom->RelativeRotation = FRotator(0.f,180.f,0.f);

	// Create a camera and attach to boom
	//SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
//	SideViewCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	//SideViewCameraComponent->bUsePawnControlRotation = false; // We don't want the controller rotating the camera

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Face in the direction we are moving..
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->GravityScale = 0.0f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 1000.f;
	GetCharacterMovement()->GroundFriction = 3.f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MaxFlySpeed = 600.f;

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
// Input

void AGAME_PRODUCTION_IIICharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
//	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump); 
//	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAxis("MoveRight", this, &AGAME_PRODUCTION_IIICharacter::MoveRight);
	PlayerInputComponent->BindAxis("MoveUpward", this, &AGAME_PRODUCTION_IIICharacter::MoveUpward);// up and down
	PlayerInputComponent->BindAction("Pepper", IE_Pressed, this, &AGAME_PRODUCTION_IIICharacter::Pepper);// pepper
	PlayerInputComponent->BindTouch(IE_Pressed, this, &AGAME_PRODUCTION_IIICharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &AGAME_PRODUCTION_IIICharacter::TouchStopped);
}

void AGAME_PRODUCTION_IIICharacter::Pepper()//Pepper
{
	// add movement in that direction
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("YOU HAVE THROWN PEPPER"));
}
void AGAME_PRODUCTION_IIICharacter::MoveUpward(float DeltaTime)
{ if(IsOnLadder == true)
	{
	  FVector NewLocation = GetActorLocation();
	  NewLocation.Z += (DeltaTime * 10.f);
	  SetActorLocation(NewLocation);
	//if (GEngine)
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("MoveForward is becalling")); 
    }
	// add movement in that direction
	//FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Z);
	//AddMovementInput(FVector(Direction), Value);
	//AddMovementInput(FVector(0.f, 0.f, -1.f), Val);
 	/*if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("MoveForward is becalling"));*/
}
void AGAME_PRODUCTION_IIICharacter::MoveRight(float Value)
{
	// add movement in that direction
	AddMovementInput(FVector(0.f,-1.f,0.f), Value);
}

void AGAME_PRODUCTION_IIICharacter::TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	// jump on any touch
	//Jump();
}

void AGAME_PRODUCTION_IIICharacter::TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	//StopJumping();
}

// overlap

void AGAME_PRODUCTION_IIICharacter::NotifyActorBeginOverlap(AActor*OtherActor)
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("overlap begin happen"));
	IsOnLadder = true;
	GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Flying);// set to flying  mode
}
void AGAME_PRODUCTION_IIICharacter::NotifyActorEndOverlap(AActor*OtherActor)
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("overlap end happen"));
	IsOnLadder = false;
	GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Walking);// set to walking mode
}
