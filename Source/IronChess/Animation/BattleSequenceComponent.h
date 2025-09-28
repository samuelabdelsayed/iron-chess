#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Engine/World.h"
#include "LevelSequence.h"
#include "LevelSequencePlayer.h"
#include "MovieSceneSequencePlayer.h"
#include "../Core/ChessTypes.h"
#include "BattleSequenceComponent.generated.h"

class UNiagaraSystem;
class UNiagaraComponent;
class ACameraActor;
class ULevelSequence;

UENUM(BlueprintType)
enum class EBattleSequenceType : uint8
{
    None,
    PawnCapture,      // Soldier vs soldier combat
    KnightCapture,    // Cavalry charge
    RookCapture,      // Siege warfare
    BishopCapture,    // Magical/religious battle
    QueenCapture,     // Epic royal combat
    KingCapture,      // Dramatic finale
    Castling,         // Strategic maneuver
    EnPassant,        // Surprise attack
    Promotion,        // Transformation scene
    Check,            // Tension builder
    Checkmate        // Victory sequence
};

USTRUCT(BlueprintType)
struct IRONCHESS_API FBattleSequenceConfig
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Battle Config")
    EBattleSequenceType SequenceType = EBattleSequenceType::None;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Battle Config")
    TSoftObjectPtr<ULevelSequence> SequenceAsset;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Battle Config")
    float Duration = 3.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Battle Config")
    bool bUseDynamicCamera = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Battle Config")
    TArray<TSoftObjectPtr<UNiagaraSystem>> ParticleEffects;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Battle Config")
    TArray<TSoftObjectPtr<USoundBase>> SoundEffects;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Battle Config")
    float IntensityMultiplier = 1.0f;

    FBattleSequenceConfig()
    {
        SequenceType = EBattleSequenceType::None;
        Duration = 3.0f;
        bUseDynamicCamera = true;
        IntensityMultiplier = 1.0f;
    }
};

USTRUCT(BlueprintType)
struct IRONCHESS_API FBattleContext
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite)
    FChessMove TriggerMove;

    UPROPERTY(BlueprintReadWrite)
    FChessPosition AttackerPosition;

    UPROPERTY(BlueprintReadWrite)
    FChessPosition DefenderPosition;

    UPROPERTY(BlueprintReadWrite)
    EPieceType AttackerType = EPieceType::None;

    UPROPERTY(BlueprintReadWrite)
    EPieceType DefenderType = EPieceType::None;

    UPROPERTY(BlueprintReadWrite)
    EPieceColor AttackerColor = EPieceColor::None;

    UPROPERTY(BlueprintReadWrite)
    int32 MovesSinceLastBattle = 0;

    UPROPERTY(BlueprintReadWrite)
    bool bIsCheckMove = false;

    UPROPERTY(BlueprintReadWrite)
    bool bIsCheckmateMove = false;

    FBattleContext()
    {
        AttackerType = EPieceType::None;
        DefenderType = EPieceType::None;
        AttackerColor = EPieceColor::None;
        MovesSinceLastBattle = 0;
        bIsCheckMove = false;
        bIsCheckmateMove = false;
    }
};

/**
 * Component responsible for triggering and managing battle sequences
 * Creates cinematic mini war-scenes every 3 moves and for special events
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), BlueprintType)
class IRONCHESS_API UBattleSequenceComponent : public USceneComponent
{
    GENERATED_BODY()

public:
    UBattleSequenceComponent();

    // Battle Sequence Management
    UFUNCTION(BlueprintCallable, Category = "Battle Sequence")
    void TriggerBattleSequence(const FBattleContext& Context);

    UFUNCTION(BlueprintCallable, Category = "Battle Sequence")
    bool ShouldTriggerBattle(const FChessMove& Move, int32 MovesSinceLastBattle) const;

    UFUNCTION(BlueprintCallable, Category = "Battle Sequence")
    EBattleSequenceType DetermineBattleType(const FBattleContext& Context) const;

    UFUNCTION(BlueprintCallable, Category = "Battle Sequence")
    void StopCurrentBattle();

    // Configuration
    UFUNCTION(BlueprintCallable, Category = "Battle Sequence")
    void SetBattleConfig(EBattleSequenceType Type, const FBattleSequenceConfig& Config);

    UFUNCTION(BlueprintPure, Category = "Battle Sequence")
    FBattleSequenceConfig GetBattleConfig(EBattleSequenceType Type) const;

    // Battle Frequency Control
    UFUNCTION(BlueprintCallable, Category = "Battle Sequence")
    void SetBattleFrequency(int32 MovesPerBattle) { BattleFrequency = MovesPerBattle; }

    UFUNCTION(BlueprintPure, Category = "Battle Sequence")
    int32 GetBattleFrequency() const { return BattleFrequency; }

    // State Queries
    UFUNCTION(BlueprintPure, Category = "Battle Sequence")
    bool IsPlayingBattleSequence() const { return bIsPlayingBattle; }

    UFUNCTION(BlueprintPure, Category = "Battle Sequence")
    float GetCurrentBattleProgress() const;

    // Events
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBattleSequenceStarted, EBattleSequenceType, BattleType);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBattleSequenceFinished, EBattleSequenceType, BattleType);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBattleSequenceProgress, EBattleSequenceType, BattleType, float, Progress);

    UPROPERTY(BlueprintAssignable)
    FOnBattleSequenceStarted OnBattleSequenceStarted;

    UPROPERTY(BlueprintAssignable)
    FOnBattleSequenceFinished OnBattleSequenceFinished;

    UPROPERTY(BlueprintAssignable)
    FOnBattleSequenceProgress OnBattleSequenceProgress;

protected:
    virtual void BeginPlay() override;
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    // Battle sequence configurations
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Battle Configs")
    TMap<EBattleSequenceType, FBattleSequenceConfig> BattleConfigs;

    // Timing settings
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Battle Settings")
    int32 BattleFrequency = 3; // Trigger battle every N moves

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Battle Settings")
    float MinBattleDuration = 2.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Battle Settings")
    float MaxBattleDuration = 8.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Battle Settings")
    bool bAutoTriggerOnCaptures = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Battle Settings")
    bool bAutoTriggerOnCheck = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Battle Settings")
    bool bAutoTriggerOnSpecialMoves = true;

    // Camera settings for battles
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
    float BattleCameraBlendTime = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
    TArray<FTransform> PredefinedCameraPositions;

private:
    // Current battle state
    UPROPERTY()
    bool bIsPlayingBattle = false;

    UPROPERTY()
    EBattleSequenceType CurrentBattleType = EBattleSequenceType::None;

    UPROPERTY()
    float CurrentBattleTime = 0.0f;

    UPROPERTY()
    float CurrentBattleDuration = 0.0f;

    UPROPERTY()
    ULevelSequencePlayer* CurrentSequencePlayer = nullptr;

    UPROPERTY()
    TArray<UNiagaraComponent*> ActiveParticleEffects;

    UPROPERTY()
    TArray<UAudioComponent*> ActiveSoundEffects;

    // Battle execution
    void ExecuteBattleSequence(const FBattleSequenceConfig& Config, const FBattleContext& Context);
    void PlayLevelSequence(const FBattleSequenceConfig& Config, const FBattleContext& Context);
    void SpawnParticleEffects(const FBattleSequenceConfig& Config, const FBattleContext& Context);
    void PlaySoundEffects(const FBattleSequenceConfig& Config, const FBattleContext& Context);
    void SetupBattleCamera(const FBattleSequenceConfig& Config, const FBattleContext& Context);
    
    // Battle cleanup
    void CleanupBattleEffects();
    void RestoreGameCamera();

    // Configuration initialization
    void InitializeBattleConfigs();
    void LoadBattleAssets();

    // Dynamic battle generation
    FVector GetBattlePosition(const FBattleContext& Context) const;
    FRotator GetBattleRotation(const FBattleContext& Context) const;
    float CalculateBattleIntensity(const FBattleContext& Context) const;
    
    // Special battle types
    void HandlePawnBattle(const FBattleContext& Context);
    void HandleKnightBattle(const FBattleContext& Context);
    void HandleRookBattle(const FBattleContext& Context);
    void HandleBishopBattle(const FBattleContext& Context);
    void HandleQueenBattle(const FBattleContext& Context);
    void HandleKingBattle(const FBattleContext& Context);
    void HandleSpecialMoveBattle(const FBattleContext& Context);
    
    // Camera animation
    void AnimateCameraToBattle(const FVector& Position, const FRotator& Rotation);
    void CreateDynamicCameraShake(float Intensity);
    
    // Utility functions
    FString GetBattleSequencePath(EBattleSequenceType Type) const;
    TArray<FVector> GetParticleSpawnPositions(const FBattleContext& Context) const;
};