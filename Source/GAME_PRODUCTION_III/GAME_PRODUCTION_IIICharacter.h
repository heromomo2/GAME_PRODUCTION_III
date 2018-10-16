// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GAME_PRODUCTION_IIICharacter.generated.h"

UCLASS(config=Game)
class AGAME_PRODUCTION_IIICharacter : public ACharacter
{
	GENERATED_BODY()

	/** Side view camera */
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	//class UCameraComponent* SideViewCameraComponent;

	/** Camera boom positioning the camera beside the character */
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	//class USpringArmComponent* CameraBoom;

protected:
	/* called for Pepper*/
	void Pepper();

	/** Called for side to side input */
	void MoveRight(float Val);

	/** Called for Move up and down input */
	void MoveUpward(float DeltaTime);

	/** Handle touch inputs. */
	void TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location);

	/** Handle touch stop event. */
	void TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End of APawn interface

	/// bool is see player is on the ladder
	bool IsOnLadder = false;

	// enum  movement of mode 
	enum EMovementMode1
	{
		MOVE_None,
		MOVE_Walking,
		MOVE_NavWalking,
		MOVE_Falling,
		MOVE_Swimming,
		MOVE_Flying,
		MOVE_Custom,
		MOVE_MAX,
	};


public:
	AGAME_PRODUCTION_IIICharacter();

	/** Returns SideViewCameraComponent subobject **/
	//FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return SideViewCameraComponent; }
	/** Returns CameraBoom subobject **/
	//FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	virtual void NotifyActorBeginOverlap(AActor*OtherActer)override;
	virtual void NotifyActorEndOverlap(AActor*OtherActer)override;
	virtual void SetMovementMode(EMovementMode);
	
};
