// Fill out your copyright notice in the Description page of Project Settings.


#include "Dialogue.h"

// Sets default values
ADialogue::ADialogue()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADialogue::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADialogue::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADialogue::Init(FString _dialogue, bool _bContinue)
{
	SetDialogue(_dialogue);
	bContinue = _bContinue;
}

FString ADialogue::GetDialogue()
{
	return Dialogue;
}

void ADialogue::SetDialogue(FString _dialogue)
{
	Dialogue = _dialogue;
}

bool ADialogue::GetContinue()
{
	return bContinue;
}

