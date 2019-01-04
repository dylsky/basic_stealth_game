// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSAIGuard.h"
#include "Perception/PawnSensingComponent.h"
#include "DrawDebugHelpers.h"
#include "FPSGameMode.h"
#include "Ai/Navigation/NavigationSystem.h"
#include "Net/UnrealNetwork.h"

// Sets default values
AFPSAIGuard::AFPSAIGuard()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));
}

// Called when the game starts or when spawned
void AFPSAIGuard::BeginPlay()
{
	Super::BeginPlay();
	PawnSensingComp->OnSeePawn.AddDynamic(this, &AFPSAIGuard::OnPawnSee);
	PawnSensingComp->OnHearNoise.AddDynamic(this, &AFPSAIGuard::OnHearNoise);

	OriginalRotation = GetActorRotation();

	GuardState = EAIState::Idle;

	if(bPartorl){
		MoveToNextPatrolPoint();
	}
}

void AFPSAIGuard::OnPawnSee(APawn* SeenPawn)
{
	if (SeenPawn == nullptr) return;
	SetGuardState(EAIState::Alerted);
	DrawDebugSphere(GetWorld(), SeenPawn->GetActorLocation(), 32, 12, FColor::Yellow, false, 10);

	AController* Controller = GetController();
	if(Controller)
	{
		Controller->StopMovement();
	}

	AFPSGameMode* GM = Cast<AFPSGameMode>(GetWorld()->GetAuthGameMode());
	if (GM)
	{
		GM->CompleteMission(SeenPawn, false);
	}
}

void AFPSAIGuard::OnHearNoise(APawn* InstigatorPawn, const FVector& Location, float Volume)
{
	if(GuardState == EAIState::Alerted) return;

	if (InstigatorPawn == nullptr) return;
	DrawDebugSphere(GetWorld(), Location, 16, 12, FColor::Red, false, 10);

	FVector Direction = Location - GetActorLocation();
	Direction.Normalize();

	FRotator NewRotator = FRotationMatrix::MakeFromX(Direction).Rotator();
	NewRotator.Pitch = 0;
	NewRotator.Roll = 0;
	SetActorRotation(NewRotator);

	GetWorldTimerManager().ClearTimer(TimerHandle_ResetOrientation);

	GetWorldTimerManager().SetTimer(TimerHandle_ResetOrientation, this, &AFPSAIGuard::ResetOrientation, 3.0f);

	SetGuardState(EAIState::Suspicious);

	AController* Controller = GetController();
	if (Controller)
	{
		Controller->StopMovement();
	}

}

void AFPSAIGuard::ResetOrientation()
{
	if(GuardState == EAIState::Alerted) return;
	SetActorRotation(OriginalRotation);
	SetGuardState(EAIState::Idle);	 

	if(bPartorl)
	{
		MoveToNextPatrolPoint();
	}
}

void AFPSAIGuard::OnRep_GuardState()
{
	OnStateChange(GuardState);
}

void AFPSAIGuard::SetGuardState(EAIState newState)
{
	if (GuardState == newState) return;
	GuardState = newState;

	OnRep_GuardState();
}

// Called every frame
void AFPSAIGuard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CurrentPatrolPoint)
	{
		FVector delta = GetActorLocation() - CurrentPatrolPoint->GetActorLocation();
		float distanceToGoal = delta.Size();
		if(distanceToGoal <= 100)
		{
			MoveToNextPatrolPoint();
		}
	}

}

void AFPSAIGuard::MoveToNextPatrolPoint()
{
	if(CurrentPatrolPoint == nullptr || CurrentPatrolPoint == SecondPatrolPoint)
	{
		UE_LOG(LogTemp, Log, TEXT("Moving to first point"));
		CurrentPatrolPoint = FirstPatrolPoint;
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Moving to second point"));
		CurrentPatrolPoint = SecondPatrolPoint;
	}
	UNavigationSystem::SimpleMoveToActor(GetController(), CurrentPatrolPoint);

}


void AFPSAIGuard::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AFPSAIGuard, GuardState);
}
