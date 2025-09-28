#include "CinematicDirector.h"
#include "Engine/Engine.h"

ACinematicDirector::ACinematicDirector()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ACinematicDirector::BeginPlay()
{
    Super::BeginPlay();
    UE_LOG(LogTemp, Log, TEXT("CinematicDirector initialized"));
}

void ACinematicDirector::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    // Cinematic updates would go here
}

void ACinematicDirector::CreateEndgameReenactment(const TArray<FChessMove>& MoveHistory, EPieceColor Winner)
{
    UE_LOG(LogTemp, Log, TEXT("Creating endgame reenactment"));
}

void ACinematicDirector::PlayCinematicSequence(const FCinematicSequence& Sequence)
{
    UE_LOG(LogTemp, Log, TEXT("Playing cinematic sequence"));
}

void ACinematicDirector::StopCinematic()
{
    bIsPlayingCinematic = false;
    UE_LOG(LogTemp, Log, TEXT("Cinematic stopped"));
}

void ACinematicDirector::SkipToNextShot()
{
    UE_LOG(LogTemp, Log, TEXT("Skipped to next shot"));
}

float ACinematicDirector::GetCinematicProgress() const
{
    return 1.0f;
}

FTransform ACinematicDirector::CalculateCameraPosition(const FChessMove& Move, const FString& ShotType)
{
    return FTransform::Identity;
}

void ACinematicDirector::SetupCinematicCamera(const FCinematicShot& Shot)
{
    UE_LOG(LogTemp, Log, TEXT("Setting up cinematic camera"));
}

FString ACinematicDirector::GenerateMoveNarration(const FChessMove& Move, const FString& Context)
{
    return TEXT("Epic chess move narration");
}

float ACinematicDirector::CalculateAverageMoveDifficulty(const TArray<FChessMove>& MoveHistory)
{
    return 5.0f;
}

FString ACinematicDirector::GetMoveContext(const FChessMove& Move, int32 MoveIndex, ENarrativeTheme Theme)
{
    return TEXT("Move context");
}

FGameAnalysis ACinematicDirector::AnalyzeGame(const TArray<FChessMove>& MoveHistory, EPieceColor Winner)
{
    FGameAnalysis Analysis;
    Analysis.GameLength = MoveHistory.Num();
    Analysis.Winner = Winner;
    Analysis.AverageMoveDifficulty = CalculateAverageMoveDifficulty(MoveHistory);
    
    // Find key moves
    Analysis.KeyMoves = FindKeyMoves(MoveHistory);
    Analysis.TacticalMoves = FindTacticalMoves(MoveHistory);
    Analysis.SacrificesMade = FindSacrifices(MoveHistory);
    Analysis.TurningPoints = FindTurningPoints(MoveHistory);
    
    // Determine game characteristics
    Analysis.bWasDominantVictory = WasDominantVictory(MoveHistory, Winner);
    Analysis.bWasComeback = WasComeback(MoveHistory, Winner);
    Analysis.SuggestedTheme = DetermineGameTheme(Analysis);
    
    UE_LOG(LogTemp, Log, TEXT("Game analysis completed: %d moves"), Analysis.GameLength);
    return Analysis;
}

ENarrativeTheme ACinematicDirector::DetermineGameTheme(const FGameAnalysis& Analysis)
{
    // Determine theme based on game characteristics
    if (Analysis.GameLength < 20)
    {
        return ENarrativeTheme::SwiftConquest;
    }
    else if (Analysis.bWasComeback)
    {
        return ENarrativeTheme::Redemption;
    }
    else if (Analysis.TacticalMoves.Num() > Analysis.GameLength * 0.3f)
    {
        return ENarrativeTheme::TacticalGenius;
    }
    else if (Analysis.SacrificesMade.Num() > 0 || Analysis.KeyMoves.Num() > Analysis.GameLength * 0.4f)
    {
        return ENarrativeTheme::EpicBattle;
    }
    else if (Analysis.bWasDominantVictory)
    {
        return ENarrativeTheme::SwiftConquest;
    }
    else
    {
        return ENarrativeTheme::HeroicVictory;
    }
}

TArray<FCinematicShot> ACinematicDirector::CreateShotsFromMoves(const TArray<FChessMove>& MoveHistory, ENarrativeTheme Theme)
{
    TArray<FCinematicShot> Shots;
    
    // Create opening shot
    FCinematicShot OpeningShot;
    OpeningShot.ShotName = TEXT("Establishing Shot");
    OpeningShot.Duration = 3.0f;
    OpeningShot.CameraTransform = FTransform::Identity;
    OpeningShot.NarrationText = TEXT("Wide shot of the medieval battlefield");
    Shots.Add(OpeningShot);
    
    // Create shots for key moves
    for (int32 i = 0; i < MoveHistory.Num(); i += 3) // Every 3rd move
    {
        const FChessMove& Move = MoveHistory[i];
        
        FCinematicShot MoveShot;
        FString ShotType = (Move.MoveType == EMoveType::Capture) ? TEXT("Action") : TEXT("Strategy");
        MoveShot.ShotName = ShotType + TEXT(" Shot");
        MoveShot.Duration = (Move.MoveType == EMoveType::Capture) ? 4.0f : 2.0f;
        MoveShot.CameraTransform = CalculateCameraPosition(Move, ShotType);
        MoveShot.NarrationText = GenerateMoveNarration(Move, GetMoveContext(Move, i, Theme));
        Shots.Add(MoveShot);
    }
    
    // Create closing shot
    FCinematicShot ClosingShot;
    ClosingShot.ShotName = TEXT("Victory Shot");
    ClosingShot.Duration = 5.0f;
    ClosingShot.CameraTransform = FTransform::Identity;
    ClosingShot.NarrationText = TEXT("The victor stands triumphant over the conquered realm");
    Shots.Add(ClosingShot);
    
    UE_LOG(LogTemp, Log, TEXT("Created %d cinematic shots"), Shots.Num());
    return Shots;
}

FString ACinematicDirector::GenerateOpeningNarration(const FGameAnalysis& Analysis)
{
    FString Narration;
    FString GameLengthDesc = (Analysis.GameLength < 30) ? TEXT("swift") : (Analysis.GameLength < 60) ? TEXT("epic") : TEXT("legendary");
    
    switch (Analysis.SuggestedTheme)
    {
        case ENarrativeTheme::HeroicVictory:
            Narration = FString::Printf(TEXT("In the ancient realm of chess, two mighty armies prepare for battle. This %s campaign shall determine the fate of kingdoms..."), *GameLengthDesc);
            break;
        case ENarrativeTheme::EpicBattle:
            Narration = TEXT("Steel clashes against steel as warriors prepare for the most brutal campaign ever witnessed. Blood will flow like rivers...");
            break;
        case ENarrativeTheme::TacticalGenius:
            Narration = TEXT("In the halls of strategy, where mind conquers brawn, two master tacticians prepare their intricate webs of war...");
            break;
        case ENarrativeTheme::SwiftConquest:
            Narration = TEXT("Lightning strikes across the battlefield as armies clash in a furious, decisive campaign that will be over before the sun sets...");
            break;
        case ENarrativeTheme::Redemption:
            Narration = TEXT("From the ashes of defeat, a fallen commander rises to reclaim honor and restore their rightful throne...");
            break;
        default:
            Narration = TEXT("Two armies face each other across the field of honor, ready to write their legacy in the annals of chess...");
    }
    
    return Narration;
}

FString ACinematicDirector::GenerateClosingNarration(const FGameAnalysis& Analysis)
{
    FString WinnerText = (Analysis.Winner == EPieceColor::White) ? TEXT("White") : TEXT("Black");
    
    FString Narration = FString::Printf(
        TEXT("And so, after %d moves of brilliant strategy and fierce combat, the %s army emerges victorious. "),
        Analysis.GameLength,
        *WinnerText
    );
    
    if (Analysis.bWasDominantVictory)
    {
        Narration += TEXT("Through overwhelming superiority and tactical brilliance, they have conquered the realm.");
    }
    else if (Analysis.bWasComeback)
    {
        Narration += TEXT("From the brink of defeat, they have snatched victory through determination and skill.");
    }
    else if (Analysis.TacticalMoves.Num() > 0)
    {
        Narration += TEXT("Through cunning tactics and strategic brilliance, they have claimed the throne.");
    }
    else
    {
        Narration += TEXT("With patient maneuvering and masterful positioning, they have achieved ultimate victory.");
    }
    
    Narration += TEXT(" The battlefield falls silent, and a new chapter in chess history begins.");
    
    return Narration;
}

FCinematicSequence ACinematicDirector::GenerateCinematicSequence(const FGameAnalysis& Analysis)
{
    FCinematicSequence Sequence;
    Sequence.Theme = Analysis.SuggestedTheme;
    Sequence.OpeningNarration = GenerateOpeningNarration(Analysis);
    Sequence.ClosingNarration = GenerateClosingNarration(Analysis);
    Sequence.TotalDuration = 30.0f; // Base duration
    
    // Add duration based on game length
    if (Analysis.GameLength > 60)
    {
        Sequence.TotalDuration += 15.0f;
    }
    else if (Analysis.GameLength < 30)
    {
        Sequence.TotalDuration -= 10.0f;
    }
    
    UE_LOG(LogTemp, Log, TEXT("Generated cinematic sequence: %.1f seconds"), Sequence.TotalDuration);
    
    return Sequence;
}

// Helper function implementations
TArray<FChessMove> ACinematicDirector::FindKeyMoves(const TArray<FChessMove>& MoveHistory)
{
    TArray<FChessMove> KeyMoves;
    for (const FChessMove& Move : MoveHistory)
    {
        if (Move.MoveType == EMoveType::Capture || Move.IsCheck || Move.IsCheckmate)
        {
            KeyMoves.Add(Move);
        }
    }
    return KeyMoves;
}

TArray<FChessMove> ACinematicDirector::FindTacticalMoves(const TArray<FChessMove>& MoveHistory)
{
    TArray<FChessMove> TacticalMoves;
    for (const FChessMove& Move : MoveHistory)
    {
        if (Move.MoveType == EMoveType::Capture || Move.MoveType == EMoveType::Castling)
        {
            TacticalMoves.Add(Move);
        }
    }
    return TacticalMoves;
}

TArray<FChessMove> ACinematicDirector::FindSacrifices(const TArray<FChessMove>& MoveHistory)
{
    // Simplified - would need more complex analysis
    TArray<FChessMove> Sacrifices;
    return Sacrifices;
}

TArray<FChessMove> ACinematicDirector::FindTurningPoints(const TArray<FChessMove>& MoveHistory)
{
    TArray<FChessMove> TurningPoints;
    for (const FChessMove& Move : MoveHistory)
    {
        if (Move.IsCheck || Move.IsCheckmate)
        {
            TurningPoints.Add(Move);
        }
    }
    return TurningPoints;
}

bool ACinematicDirector::WasDominantVictory(const TArray<FChessMove>& MoveHistory, EPieceColor Winner)
{
    // Simplified - game was dominant if it was relatively short
    return MoveHistory.Num() < 30;
}

bool ACinematicDirector::WasComeback(const TArray<FChessMove>& MoveHistory, EPieceColor Winner)
{
    // Simplified - assume comeback if game was long
    return MoveHistory.Num() > 60;
}