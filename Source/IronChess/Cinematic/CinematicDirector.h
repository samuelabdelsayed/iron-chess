#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Core/ChessTypes.h"
#include "LevelSequence.h"
#include "CineCameraActor.h"
#include "MovieSceneSequencePlayer.h"
#include "CinematicDirector.generated.h"

class ULevelSequence;
class ULevelSequencePlayer;
class ACineCameraActor;
class UNiagaraSystem;
class USoundMix;
class USoundClass;

UENUM(BlueprintType)
enum class ECinematicPhase : uint8
{
    Opening,        // Game introduction
    EarlyGame,      // Opening moves
    MiddleGame,     // Main battle
    EndGame,        // Final phase
    Climax,         // Checkmate moment
    Epilogue        // Victory celebration
};

UENUM(BlueprintType)
enum class ENarrativeTheme : uint8
{
    HeroicVictory,    // Underdog triumph
    TacticalGenius,   // Strategic masterpiece
    EpicBattle,       // Back-and-forth struggle
    SwiftConquest,    // Dominant performance
    TragedyAndLoss,   // Heroic defeat
    Redemption        // Comeback victory
};

USTRUCT(BlueprintType)
struct IRONCHESS_API FCinematicShot
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shot")
    FString ShotName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shot")
    float Duration = 3.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shot")
    FTransform CameraTransform;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shot")
    float CameraFOV = 90.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shot")
    TArray<FChessMove> FocusMoves;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shot")
    FString NarrationText;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shot")
    TSoftObjectPtr<USoundBase> NarrationAudio;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shot")
    TArray<TSoftObjectPtr<UNiagaraSystem>> VisualEffects;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shot")
    bool bShowPieceHighlight = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shot")
    bool bUseSlowMotion = false;

    FCinematicShot()
    {
        Duration = 3.0f;
        CameraFOV = 90.0f;
        bShowPieceHighlight = true;
        bUseSlowMotion = false;
    }
};

USTRUCT(BlueprintType)
struct IRONCHESS_API FCinematicSequence
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sequence")
    ENarrativeTheme Theme = ENarrativeTheme::EpicBattle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sequence")
    TArray<FCinematicShot> Shots;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sequence")
    TSoftObjectPtr<USoundBase> BackgroundMusic;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sequence")
    float TotalDuration = 30.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sequence")
    FString OpeningNarration;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sequence")
    FString ClosingNarration;

    FCinematicSequence()
    {
        Theme = ENarrativeTheme::EpicBattle;
        TotalDuration = 30.0f;
    }
};

USTRUCT(BlueprintType)
struct IRONCHESS_API FGameAnalysis
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly)
    TArray<FChessMove> KeyMoves;

    UPROPERTY(BlueprintReadOnly)
    TArray<FChessMove> TacticalMoves;

    UPROPERTY(BlueprintReadOnly)
    TArray<FChessMove> SacrificesMade;

    UPROPERTY(BlueprintReadOnly)
    TArray<FChessMove> TurningPoints;

    UPROPERTY(BlueprintReadOnly)
    EPieceColor Winner = EPieceColor::None;

    UPROPERTY(BlueprintReadOnly)
    int32 GameLength = 0;

    UPROPERTY(BlueprintReadOnly)
    bool bWasDominantVictory = false;

    UPROPERTY(BlueprintReadOnly)
    bool bWasComeback = false;

    UPROPERTY(BlueprintReadOnly)
    float AverageMoveDifficulty = 0.0f;

    UPROPERTY(BlueprintReadOnly)
    ENarrativeTheme SuggestedTheme = ENarrativeTheme::EpicBattle;
};

/**
 * Cinematic Director responsible for creating epic endgame reenactments
 * Analyzes completed games and generates medieval war story cinematics
 */
UCLASS(BlueprintType, Blueprintable)
class IRONCHESS_API ACinematicDirector : public AActor
{
    GENERATED_BODY()

public:
    ACinematicDirector();

    // Main cinematic functions
    UFUNCTION(BlueprintCallable, Category = "Cinematic")
    void CreateEndgameReenactment(const TArray<FChessMove>& MoveHistory, EPieceColor Winner);

    UFUNCTION(BlueprintCallable, Category = "Cinematic")
    void PlayCinematicSequence(const FCinematicSequence& Sequence);

    UFUNCTION(BlueprintCallable, Category = "Cinematic")
    void StopCinematic();

    UFUNCTION(BlueprintCallable, Category = "Cinematic")
    void SkipToNextShot();

    // Game analysis
    UFUNCTION(BlueprintCallable, Category = "Analysis")
    FGameAnalysis AnalyzeGame(const TArray<FChessMove>& MoveHistory, EPieceColor Winner);

    UFUNCTION(BlueprintCallable, Category = "Analysis")
    ENarrativeTheme DetermineGameTheme(const FGameAnalysis& Analysis);

    // Sequence generation
    UFUNCTION(BlueprintCallable, Category = "Generation")
    FCinematicSequence GenerateCinematicSequence(const FGameAnalysis& Analysis);

    UFUNCTION(BlueprintCallable, Category = "Generation")
    TArray<FCinematicShot> CreateShotsFromMoves(const TArray<FChessMove>& KeyMoves, ENarrativeTheme Theme);

    // Narrative generation
    UFUNCTION(BlueprintCallable, Category = "Narrative")
    FString GenerateOpeningNarration(const FGameAnalysis& Analysis);

    UFUNCTION(BlueprintCallable, Category = "Narrative")
    FString GenerateClosingNarration(const FGameAnalysis& Analysis);

    UFUNCTION(BlueprintCallable, Category = "Narrative")
    FString GenerateMoveNarration(const FChessMove& Move, const FString& Context);

    // Camera management
    UFUNCTION(BlueprintCallable, Category = "Camera")
    void SetupCinematicCamera(const FCinematicShot& Shot);

    UFUNCTION(BlueprintCallable, Category = "Camera")
    FTransform CalculateCameraPosition(const FChessMove& Move, const FString& ShotType);

    // State queries
    UFUNCTION(BlueprintPure, Category = "Cinematic")
    bool IsPlayingCinematic() const { return bIsPlayingCinematic; }

    UFUNCTION(BlueprintPure, Category = "Cinematic")
    float GetCinematicProgress() const;

    UFUNCTION(BlueprintPure, Category = "Cinematic")
    int32 GetCurrentShotIndex() const { return CurrentShotIndex; }

    // Events
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCinematicStarted, const FCinematicSequence&, Sequence);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCinematicFinished);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnShotChanged, int32, ShotIndex, const FCinematicShot&, Shot);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnNarrationSpoken, const FString&, Text, float, Duration);

    UPROPERTY(BlueprintAssignable)
    FOnCinematicStarted OnCinematicStarted;

    UPROPERTY(BlueprintAssignable)
    FOnCinematicFinished OnCinematicFinished;

    UPROPERTY(BlueprintAssignable)
    FOnShotChanged OnShotChanged;

    UPROPERTY(BlueprintAssignable)
    FOnNarrationSpoken OnNarrationSpoken;

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

    // Cinematic settings
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cinematic Settings")
    float DefaultShotDuration = 4.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cinematic Settings")
    float CameraTransitionTime = 1.5f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cinematic Settings")
    bool bAutoGenerateShots = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cinematic Settings")
    int32 MaxShotsPerSequence = 10;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cinematic Settings")
    float NarrationSpeed = 1.0f;

    // Audio settings
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
    TSoftObjectPtr<USoundMix> CinematicSoundMix;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
    float MusicVolume = 0.7f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
    float NarrationVolume = 0.9f;

    // Narrative templates
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Narrative")
    TMap<ENarrativeTheme, FString> OpeningTemplates;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Narrative")
    TMap<ENarrativeTheme, FString> ClosingTemplates;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Narrative")
    TMap<EPieceType, FString> PieceDescriptions;

private:
    // Current cinematic state
    UPROPERTY()
    bool bIsPlayingCinematic = false;

    UPROPERTY()
    FCinematicSequence CurrentSequence;

    UPROPERTY()
    int32 CurrentShotIndex = 0;

    UPROPERTY()
    FCinematicShot CurrentShot;

    UPROPERTY()
    float CurrentShotTime = 0.0f;

    UPROPERTY()
    float ShotElapsedTime = 0.0f;

    UPROPERTY()
    float TotalCinematicTime = 0.0f;

    // Camera and audio components
    UPROPERTY()
    ACineCameraActor* CinematicCamera = nullptr;

    UPROPERTY()
    UAudioComponent* BackgroundMusicComponent = nullptr;

    UPROPERTY()
    UAudioComponent* NarrationComponent = nullptr;

    UPROPERTY()
    ULevelSequencePlayer* SequencePlayer = nullptr;

    // Analysis helpers
    TArray<FChessMove> FindKeyMoves(const TArray<FChessMove>& MoveHistory);
    TArray<FChessMove> FindTacticalMoves(const TArray<FChessMove>& MoveHistory);
    TArray<FChessMove> FindSacrifices(const TArray<FChessMove>& MoveHistory);
    TArray<FChessMove> FindTurningPoints(const TArray<FChessMove>& MoveHistory);
    bool WasDominantVictory(const TArray<FChessMove>& MoveHistory, EPieceColor Winner);
    bool WasComeback(const TArray<FChessMove>& MoveHistory, EPieceColor Winner);

    // Shot generation helpers
    FCinematicShot CreateEstablishingShot(const TArray<FChessMove>& MoveHistory);
    FCinematicShot CreateKeyMoveShot(const FChessMove& Move, int32 MoveIndex, ENarrativeTheme Theme);
    FCinematicShot CreateClimaxShot(const FChessMove& CheckmateMove, EPieceColor Winner);
    FCinematicShot CreateEpilogueShot(EPieceColor Winner, ENarrativeTheme Theme);

    // Camera positioning
    FTransform GetOverviewCameraTransform();
    FTransform GetCloseupCameraTransform(const FChessPosition& Position);
    FTransform GetDramaticCameraTransform(const FChessMove& Move);
    FTransform GetVictoryCameraTransform(EPieceColor Winner);

    // Narrative generation
    FString ProcessNarrativeTemplate(const FString& Template, const FGameAnalysis& Analysis);
    FString GetPieceDescription(EPieceType Type, EPieceColor Color, bool bVerbose = false);
    FString GetMoveDescription(const FChessMove& Move, bool bDramatic = true);
    FString GetPositionDescription(const FChessPosition& Position);

    // Audio management
    void PlayBackgroundMusic(const FCinematicSequence& Sequence);
    void PlayNarration(const FString& Text, float Duration);
    void StopAllAudio();

    // Cinematic execution
    void UpdateCurrentShot(float DeltaTime);
    void TransitionToNextShot();
    void FinishCinematic();

    // Utility functions
    void InitializeNarrativeTemplates();
    void InitializePieceDescriptions();
    
    // Helper functions
    float CalculateAverageMoveDifficulty(const TArray<FChessMove>& MoveHistory);
    FString GetMoveContext(const FChessMove& Move, int32 MoveIndex, ENarrativeTheme Theme);
};