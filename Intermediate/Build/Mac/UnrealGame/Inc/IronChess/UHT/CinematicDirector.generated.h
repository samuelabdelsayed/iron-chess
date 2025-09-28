// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Cinematic/CinematicDirector.h"

#ifdef IRONCHESS_CinematicDirector_generated_h
#error "CinematicDirector.generated.h already included, missing '#pragma once' in CinematicDirector.h"
#endif
#define IRONCHESS_CinematicDirector_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

enum class ENarrativeTheme : uint8;
enum class EPieceColor : uint8;
struct FChessMove;
struct FCinematicSequence;
struct FCinematicShot;
struct FGameAnalysis;

// ********** Begin ScriptStruct FCinematicShot ****************************************************
#define FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Cinematic_CinematicDirector_h_43_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FCinematicShot_Statics; \
	static class UScriptStruct* StaticStruct();


struct FCinematicShot;
// ********** End ScriptStruct FCinematicShot ******************************************************

// ********** Begin ScriptStruct FCinematicSequence ************************************************
#define FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Cinematic_CinematicDirector_h_87_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FCinematicSequence_Statics; \
	static class UScriptStruct* StaticStruct();


struct FCinematicSequence;
// ********** End ScriptStruct FCinematicSequence **************************************************

// ********** Begin ScriptStruct FGameAnalysis *****************************************************
#define FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Cinematic_CinematicDirector_h_117_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FGameAnalysis_Statics; \
	static class UScriptStruct* StaticStruct();


struct FGameAnalysis;
// ********** End ScriptStruct FGameAnalysis *******************************************************

// ********** Begin Delegate FOnCinematicStarted ***************************************************
#define FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Cinematic_CinematicDirector_h_217_DELEGATE \
static void FOnCinematicStarted_DelegateWrapper(const FMulticastScriptDelegate& OnCinematicStarted, FCinematicSequence const& Sequence);


// ********** End Delegate FOnCinematicStarted *****************************************************

// ********** Begin Delegate FOnCinematicFinished **************************************************
#define FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Cinematic_CinematicDirector_h_218_DELEGATE \
static void FOnCinematicFinished_DelegateWrapper(const FMulticastScriptDelegate& OnCinematicFinished);


// ********** End Delegate FOnCinematicFinished ****************************************************

// ********** Begin Delegate FOnShotChanged ********************************************************
#define FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Cinematic_CinematicDirector_h_219_DELEGATE \
static void FOnShotChanged_DelegateWrapper(const FMulticastScriptDelegate& OnShotChanged, int32 ShotIndex, FCinematicShot const& Shot);


// ********** End Delegate FOnShotChanged **********************************************************

// ********** Begin Delegate FOnNarrationSpoken ****************************************************
#define FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Cinematic_CinematicDirector_h_220_DELEGATE \
static void FOnNarrationSpoken_DelegateWrapper(const FMulticastScriptDelegate& OnNarrationSpoken, const FString& Text, float Duration);


// ********** End Delegate FOnNarrationSpoken ******************************************************

// ********** Begin Class ACinematicDirector *******************************************************
#define FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Cinematic_CinematicDirector_h_157_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetCurrentShotIndex); \
	DECLARE_FUNCTION(execGetCinematicProgress); \
	DECLARE_FUNCTION(execIsPlayingCinematic); \
	DECLARE_FUNCTION(execCalculateCameraPosition); \
	DECLARE_FUNCTION(execSetupCinematicCamera); \
	DECLARE_FUNCTION(execGenerateMoveNarration); \
	DECLARE_FUNCTION(execGenerateClosingNarration); \
	DECLARE_FUNCTION(execGenerateOpeningNarration); \
	DECLARE_FUNCTION(execCreateShotsFromMoves); \
	DECLARE_FUNCTION(execGenerateCinematicSequence); \
	DECLARE_FUNCTION(execDetermineGameTheme); \
	DECLARE_FUNCTION(execAnalyzeGame); \
	DECLARE_FUNCTION(execSkipToNextShot); \
	DECLARE_FUNCTION(execStopCinematic); \
	DECLARE_FUNCTION(execPlayCinematicSequence); \
	DECLARE_FUNCTION(execCreateEndgameReenactment);


IRONCHESS_API UClass* Z_Construct_UClass_ACinematicDirector_NoRegister();

#define FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Cinematic_CinematicDirector_h_157_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACinematicDirector(); \
	friend struct Z_Construct_UClass_ACinematicDirector_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend IRONCHESS_API UClass* Z_Construct_UClass_ACinematicDirector_NoRegister(); \
public: \
	DECLARE_CLASS2(ACinematicDirector, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/IronChess"), Z_Construct_UClass_ACinematicDirector_NoRegister) \
	DECLARE_SERIALIZER(ACinematicDirector)


#define FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Cinematic_CinematicDirector_h_157_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ACinematicDirector(ACinematicDirector&&) = delete; \
	ACinematicDirector(const ACinematicDirector&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACinematicDirector); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACinematicDirector); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACinematicDirector) \
	NO_API virtual ~ACinematicDirector();


#define FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Cinematic_CinematicDirector_h_154_PROLOG
#define FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Cinematic_CinematicDirector_h_157_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Cinematic_CinematicDirector_h_157_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Cinematic_CinematicDirector_h_157_INCLASS_NO_PURE_DECLS \
	FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Cinematic_CinematicDirector_h_157_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ACinematicDirector;

// ********** End Class ACinematicDirector *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Cinematic_CinematicDirector_h

// ********** Begin Enum ECinematicPhase ***********************************************************
#define FOREACH_ENUM_ECINEMATICPHASE(op) \
	op(ECinematicPhase::Opening) \
	op(ECinematicPhase::EarlyGame) \
	op(ECinematicPhase::MiddleGame) \
	op(ECinematicPhase::EndGame) \
	op(ECinematicPhase::Climax) \
	op(ECinematicPhase::Epilogue) 

enum class ECinematicPhase : uint8;
template<> struct TIsUEnumClass<ECinematicPhase> { enum { Value = true }; };
template<> IRONCHESS_API UEnum* StaticEnum<ECinematicPhase>();
// ********** End Enum ECinematicPhase *************************************************************

// ********** Begin Enum ENarrativeTheme ***********************************************************
#define FOREACH_ENUM_ENARRATIVETHEME(op) \
	op(ENarrativeTheme::HeroicVictory) \
	op(ENarrativeTheme::TacticalGenius) \
	op(ENarrativeTheme::EpicBattle) \
	op(ENarrativeTheme::SwiftConquest) \
	op(ENarrativeTheme::TragedyAndLoss) \
	op(ENarrativeTheme::Redemption) 

enum class ENarrativeTheme : uint8;
template<> struct TIsUEnumClass<ENarrativeTheme> { enum { Value = true }; };
template<> IRONCHESS_API UEnum* StaticEnum<ENarrativeTheme>();
// ********** End Enum ENarrativeTheme *************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
