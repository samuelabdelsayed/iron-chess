// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/ChessGameLogic.h"

#ifdef IRONCHESS_ChessGameLogic_generated_h
#error "ChessGameLogic.generated.h already included, missing '#pragma once' in ChessGameLogic.h"
#endif
#define IRONCHESS_ChessGameLogic_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

enum class EGameState : uint8;
enum class EPieceColor : uint8;
struct FChessBoardState;
struct FChessMove;
struct FChessPiece;
struct FChessPosition;

// ********** Begin Delegate FOnMoveMade ***********************************************************
#define FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Core_ChessGameLogic_h_83_DELEGATE \
static void FOnMoveMade_DelegateWrapper(const FMulticastScriptDelegate& OnMoveMade, FChessMove const& Move);


// ********** End Delegate FOnMoveMade *************************************************************

// ********** Begin Delegate FOnGameStateChanged ***************************************************
#define FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Core_ChessGameLogic_h_84_DELEGATE \
static void FOnGameStateChanged_DelegateWrapper(const FMulticastScriptDelegate& OnGameStateChanged, EGameState NewState);


// ********** End Delegate FOnGameStateChanged *****************************************************

// ********** Begin Delegate FOnCheck **************************************************************
#define FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Core_ChessGameLogic_h_85_DELEGATE \
static void FOnCheck_DelegateWrapper(const FMulticastScriptDelegate& OnCheck, EPieceColor PlayerInCheck);


// ********** End Delegate FOnCheck ****************************************************************

// ********** Begin Class UChessGameLogic **********************************************************
#define FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Core_ChessGameLogic_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execLoadFromFEN); \
	DECLARE_FUNCTION(execGetFENString); \
	DECLARE_FUNCTION(execGetAttackedSquares); \
	DECLARE_FUNCTION(execFindKing); \
	DECLARE_FUNCTION(execCanCastle); \
	DECLARE_FUNCTION(execGetMoveHistory); \
	DECLARE_FUNCTION(execGetMoveNumber); \
	DECLARE_FUNCTION(execGetGameState); \
	DECLARE_FUNCTION(execGetActivePlayer); \
	DECLARE_FUNCTION(execGetPieceAt); \
	DECLARE_FUNCTION(execGetBoardState); \
	DECLARE_FUNCTION(execResetGame); \
	DECLARE_FUNCTION(execIsStalemate); \
	DECLARE_FUNCTION(execIsCheckmate); \
	DECLARE_FUNCTION(execIsInCheck); \
	DECLARE_FUNCTION(execGetLegalMovesForPiece); \
	DECLARE_FUNCTION(execGetLegalMoves); \
	DECLARE_FUNCTION(execMakeMove); \
	DECLARE_FUNCTION(execIsValidMove);


IRONCHESS_API UClass* Z_Construct_UClass_UChessGameLogic_NoRegister();

#define FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Core_ChessGameLogic_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUChessGameLogic(); \
	friend struct Z_Construct_UClass_UChessGameLogic_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend IRONCHESS_API UClass* Z_Construct_UClass_UChessGameLogic_NoRegister(); \
public: \
	DECLARE_CLASS2(UChessGameLogic, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/IronChess"), Z_Construct_UClass_UChessGameLogic_NoRegister) \
	DECLARE_SERIALIZER(UChessGameLogic)


#define FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Core_ChessGameLogic_h_15_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UChessGameLogic(UChessGameLogic&&) = delete; \
	UChessGameLogic(const UChessGameLogic&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UChessGameLogic); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UChessGameLogic); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UChessGameLogic) \
	NO_API virtual ~UChessGameLogic();


#define FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Core_ChessGameLogic_h_12_PROLOG
#define FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Core_ChessGameLogic_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Core_ChessGameLogic_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Core_ChessGameLogic_h_15_INCLASS_NO_PURE_DECLS \
	FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Core_ChessGameLogic_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UChessGameLogic;

// ********** End Class UChessGameLogic ************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Core_ChessGameLogic_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
