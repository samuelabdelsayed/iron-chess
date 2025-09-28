// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AI/ChessAIComponent.h"

#ifdef IRONCHESS_ChessAIComponent_generated_h
#error "ChessAIComponent.generated.h already included, missing '#pragma once' in ChessAIComponent.h"
#endif
#define IRONCHESS_ChessAIComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class UChessGameLogic;
enum class EAIDifficulty : uint8;
enum class EPieceColor : uint8;
struct FAIPersonality;
struct FChessMove;
struct FMoveEvaluation;

// ********** Begin ScriptStruct FAIPersonality ****************************************************
#define FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_AI_ChessAIComponent_h_29_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FAIPersonality_Statics; \
	static class UScriptStruct* StaticStruct();


struct FAIPersonality;
// ********** End ScriptStruct FAIPersonality ******************************************************

// ********** Begin ScriptStruct FMoveEvaluation ***************************************************
#define FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_AI_ChessAIComponent_h_59_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FMoveEvaluation_Statics; \
	static class UScriptStruct* StaticStruct();


struct FMoveEvaluation;
// ********** End ScriptStruct FMoveEvaluation *****************************************************

// ********** Begin Delegate FOnAIMoveCalculated ***************************************************
#define FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_AI_ChessAIComponent_h_126_DELEGATE \
static void FOnAIMoveCalculated_DelegateWrapper(const FMulticastScriptDelegate& OnAIMoveCalculated, FChessMove const& Move);


// ********** End Delegate FOnAIMoveCalculated *****************************************************

// ********** Begin Delegate FOnAIThinking *********************************************************
#define FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_AI_ChessAIComponent_h_127_DELEGATE \
static void FOnAIThinking_DelegateWrapper(const FMulticastScriptDelegate& OnAIThinking, float Progress, const FString& CurrentLine);


// ********** End Delegate FOnAIThinking ***********************************************************

// ********** Begin Class UChessAIComponent ********************************************************
#define FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_AI_ChessAIComponent_h_85_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execIsEndgame); \
	DECLARE_FUNCTION(execEvaluatePosition); \
	DECLARE_FUNCTION(execGetStockfishMove); \
	DECLARE_FUNCTION(execInitializeStockfish); \
	DECLARE_FUNCTION(execGetPersonality); \
	DECLARE_FUNCTION(execSetPersonality); \
	DECLARE_FUNCTION(execGetDifficulty); \
	DECLARE_FUNCTION(execSetDifficulty); \
	DECLARE_FUNCTION(execAnalyzePosition); \
	DECLARE_FUNCTION(execGetBestMove);


IRONCHESS_API UClass* Z_Construct_UClass_UChessAIComponent_NoRegister();

#define FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_AI_ChessAIComponent_h_85_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUChessAIComponent(); \
	friend struct Z_Construct_UClass_UChessAIComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend IRONCHESS_API UClass* Z_Construct_UClass_UChessAIComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UChessAIComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/IronChess"), Z_Construct_UClass_UChessAIComponent_NoRegister) \
	DECLARE_SERIALIZER(UChessAIComponent)


#define FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_AI_ChessAIComponent_h_85_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UChessAIComponent(UChessAIComponent&&) = delete; \
	UChessAIComponent(const UChessAIComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UChessAIComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UChessAIComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UChessAIComponent) \
	NO_API virtual ~UChessAIComponent();


#define FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_AI_ChessAIComponent_h_82_PROLOG
#define FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_AI_ChessAIComponent_h_85_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_AI_ChessAIComponent_h_85_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_AI_ChessAIComponent_h_85_INCLASS_NO_PURE_DECLS \
	FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_AI_ChessAIComponent_h_85_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UChessAIComponent;

// ********** End Class UChessAIComponent **********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_AI_ChessAIComponent_h

// ********** Begin Enum EAIDifficulty *************************************************************
#define FOREACH_ENUM_EAIDIFFICULTY(op) \
	op(EAIDifficulty::None) \
	op(EAIDifficulty::Beginner) \
	op(EAIDifficulty::Novice) \
	op(EAIDifficulty::Casual) \
	op(EAIDifficulty::Intermediate) \
	op(EAIDifficulty::Advanced) \
	op(EAIDifficulty::Expert) \
	op(EAIDifficulty::Master) \
	op(EAIDifficulty::Grandmaster) \
	op(EAIDifficulty::WorldClass) \
	op(EAIDifficulty::Superhuman) 

enum class EAIDifficulty : uint8;
template<> struct TIsUEnumClass<EAIDifficulty> { enum { Value = true }; };
template<> IRONCHESS_API UEnum* StaticEnum<EAIDifficulty>();
// ********** End Enum EAIDifficulty ***************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
