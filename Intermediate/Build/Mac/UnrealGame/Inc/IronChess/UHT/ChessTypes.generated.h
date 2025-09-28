// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/ChessTypes.h"

#ifdef IRONCHESS_ChessTypes_generated_h
#error "ChessTypes.generated.h already included, missing '#pragma once' in ChessTypes.h"
#endif
#define IRONCHESS_ChessTypes_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FChessPosition ****************************************************
#define FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Core_ChessTypes_h_61_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FChessPosition_Statics; \
	static class UScriptStruct* StaticStruct();


struct FChessPosition;
// ********** End ScriptStruct FChessPosition ******************************************************

// ********** Begin ScriptStruct FChessPiece *******************************************************
#define FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Core_ChessTypes_h_102_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FChessPiece_Statics; \
	static class UScriptStruct* StaticStruct();


struct FChessPiece;
// ********** End ScriptStruct FChessPiece *********************************************************

// ********** Begin ScriptStruct FChessMove ********************************************************
#define FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Core_ChessTypes_h_141_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FChessMove_Statics; \
	static class UScriptStruct* StaticStruct();


struct FChessMove;
// ********** End ScriptStruct FChessMove **********************************************************

// ********** Begin ScriptStruct FChessBoardState **************************************************
#define FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Core_ChessTypes_h_189_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FChessBoardState_Statics; \
	static class UScriptStruct* StaticStruct();


struct FChessBoardState;
// ********** End ScriptStruct FChessBoardState ****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Core_ChessTypes_h

// ********** Begin Enum EPieceType ****************************************************************
#define FOREACH_ENUM_EPIECETYPE(op) \
	op(EPieceType::None) \
	op(EPieceType::Pawn) \
	op(EPieceType::Rook) \
	op(EPieceType::Knight) \
	op(EPieceType::Bishop) \
	op(EPieceType::Queen) \
	op(EPieceType::King) 

enum class EPieceType : uint8;
template<> struct TIsUEnumClass<EPieceType> { enum { Value = true }; };
template<> IRONCHESS_API UEnum* StaticEnum<EPieceType>();
// ********** End Enum EPieceType ******************************************************************

// ********** Begin Enum EPieceColor ***************************************************************
#define FOREACH_ENUM_EPIECECOLOR(op) \
	op(EPieceColor::None) \
	op(EPieceColor::White) \
	op(EPieceColor::Black) 

enum class EPieceColor : uint8;
template<> struct TIsUEnumClass<EPieceColor> { enum { Value = true }; };
template<> IRONCHESS_API UEnum* StaticEnum<EPieceColor>();
// ********** End Enum EPieceColor *****************************************************************

// ********** Begin Enum EGameState ****************************************************************
#define FOREACH_ENUM_EGAMESTATE(op) \
	op(EGameState::WaitingForPlayers) \
	op(EGameState::InProgress) \
	op(EGameState::Check) \
	op(EGameState::Checkmate) \
	op(EGameState::Stalemate) \
	op(EGameState::Draw) 

enum class EGameState : uint8;
template<> struct TIsUEnumClass<EGameState> { enum { Value = true }; };
template<> IRONCHESS_API UEnum* StaticEnum<EGameState>();
// ********** End Enum EGameState ******************************************************************

// ********** Begin Enum EMoveType *****************************************************************
#define FOREACH_ENUM_EMOVETYPE(op) \
	op(EMoveType::Normal) \
	op(EMoveType::Capture) \
	op(EMoveType::Castling) \
	op(EMoveType::Castle) \
	op(EMoveType::EnPassant) \
	op(EMoveType::PawnPromotion) \
	op(EMoveType::Promotion) 

enum class EMoveType : uint8;
template<> struct TIsUEnumClass<EMoveType> { enum { Value = true }; };
template<> IRONCHESS_API UEnum* StaticEnum<EMoveType>();
// ********** End Enum EMoveType *******************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
