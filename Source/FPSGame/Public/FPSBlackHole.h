// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPSBlackHole.generated.h"

class USphereComponent;


UCLASS()
class FPSGAME_API AFPSBlackHole : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPSBlackHole();
	
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UStaticMeshComponent* MeshComp;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		USphereComponent* InnerSphereComp;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		USphereComponent* OuterSphereComp;

	UPROPERTY(EditDefaultsOnly, Category = "Effects")
		UParticleSystem* StaticFx;

	void PlayEffects();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;	

	UFUNCTION()
	void OverlapInnerSphere(UPrimitiveComponent* OvelappingComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, 
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
};
