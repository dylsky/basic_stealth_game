// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSLaunchpad.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"


// Sets default values
AFPSLaunchpad::AFPSLaunchpad()
{
	OverlapComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	OverlapComp->SetBoxExtent(FVector(150.0f, 150.0f, 25.0f));
	RootComponent = OverlapComp;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(RootComponent);

	OverlapComp->OnComponentBeginOverlap.AddDynamic(this, &AFPSLaunchpad::Launch);
}

// Called when the game starts or when spawned
void AFPSLaunchpad::BeginPlay()
{
	Super::BeginPlay();
}

void AFPSLaunchpad::PlayEffects()
{
	UGameplayStatics::SpawnEmitterAtLocation(this, StaticFX, GetActorLocation());
}

void AFPSLaunchpad::Launch(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	UE_LOG(LogTemp, Log, TEXT("Onhit handler called 1"));
	PlayEffects();

	FVector LauchVelocity = FVector(0, 0, 1) * 1000;

	ACharacter* charRef = Cast<ACharacter>(OtherActor);
	if (charRef)
	{
		charRef->LaunchCharacter(LauchVelocity, false, false);
	}
	else 
	{
		OtherComp->AddImpulse(LauchVelocity, NAME_None, true);
		UE_LOG(LogTemp, Log, TEXT("Onhit handler called 2"));
	}
}

