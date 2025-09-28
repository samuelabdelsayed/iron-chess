#include "BattleSequenceComponent.h"
#include "Engine/Engine.h"

UBattleSequenceComponent::UBattleSequenceComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
    PrimaryComponentTick.bStartWithTickEnabled = false;
}

void UBattleSequenceComponent::BeginPlay()
{
    Super::BeginPlay();
    UE_LOG(LogTemp, Log, TEXT("BattleSequenceComponent initialized"));
}

void UBattleSequenceComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    // Battle sequence updates would go here
}

bool UBattleSequenceComponent::ShouldTriggerBattle(const FChessMove& Move, int32 MovesSinceLastBattle) const
{
    return false; // Simplified for now
}

void UBattleSequenceComponent::TriggerBattleSequence(const FBattleContext& Context)
{
    UE_LOG(LogTemp, Log, TEXT("Battle sequence triggered"));
}

void UBattleSequenceComponent::StopCurrentBattle()
{
    UE_LOG(LogTemp, Log, TEXT("Battle sequence stopped"));
}

void UBattleSequenceComponent::LoadBattleAssets()
{
    UE_LOG(LogTemp, Log, TEXT("Battle assets loaded"));
}

void UBattleSequenceComponent::SetBattleConfig(EBattleSequenceType Type, const FBattleSequenceConfig& Config)
{
    UE_LOG(LogTemp, Log, TEXT("Battle config set"));
}

FBattleSequenceConfig UBattleSequenceComponent::GetBattleConfig(EBattleSequenceType Type) const
{
    return FBattleSequenceConfig();
}

float UBattleSequenceComponent::GetCurrentBattleProgress() const
{
    return 1.0f;
}

EBattleSequenceType UBattleSequenceComponent::DetermineBattleType(const FBattleContext& Context) const
{
    // Determine battle type based on move context
    if (Context.DefenderType != EPieceType::None) // This is a capture
    {
        if (Context.DefenderType == EPieceType::Queen)
        {
            return EBattleSequenceType::QueenCapture;
        }
        else if (Context.DefenderType == EPieceType::Rook)
        {
            return EBattleSequenceType::RookCapture;
        }
        else if (Context.DefenderType == EPieceType::Bishop)
        {
            return EBattleSequenceType::BishopCapture;
        }
        else if (Context.DefenderType == EPieceType::Knight)
        {
            return EBattleSequenceType::KnightCapture;
        }
        else if (Context.DefenderType == EPieceType::Pawn)
        {
            return EBattleSequenceType::PawnCapture;
        }
    }
    else if (Context.bIsCheckMove)
    {
        return EBattleSequenceType::Check;
    }
    else if (Context.bIsCheckmateMove)
    {
        return EBattleSequenceType::Checkmate;
    }
    else if (Context.TriggerMove.MoveType == EMoveType::Castling)
    {
        return EBattleSequenceType::Castling;
    }
    else if (Context.TriggerMove.MoveType == EMoveType::EnPassant)
    {
        return EBattleSequenceType::EnPassant;
    }
    else if (Context.TriggerMove.MoveType == EMoveType::Promotion)
    {
        return EBattleSequenceType::Promotion;
    }
    else
    {
        // Default battle type based on piece moved
        switch (Context.AttackerType)
        {
            case EPieceType::Pawn:
                return EBattleSequenceType::PawnCapture;
            case EPieceType::Rook:
                return EBattleSequenceType::RookCapture;
            case EPieceType::Bishop:
                return EBattleSequenceType::BishopCapture;
            case EPieceType::Queen:
                return EBattleSequenceType::QueenCapture;
            case EPieceType::King:
                return EBattleSequenceType::KingCapture;
            case EPieceType::Knight:
                return EBattleSequenceType::KnightCapture;
            default:
                return EBattleSequenceType::None;
        }
    }
    
    return EBattleSequenceType::None;
}