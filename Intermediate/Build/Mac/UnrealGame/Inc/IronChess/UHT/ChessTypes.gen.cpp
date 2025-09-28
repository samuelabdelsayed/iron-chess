// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ChessTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeChessTypes() {}

// ********** Begin Cross Module References ********************************************************
IRONCHESS_API UEnum* Z_Construct_UEnum_IronChess_EGameState();
IRONCHESS_API UEnum* Z_Construct_UEnum_IronChess_EMoveType();
IRONCHESS_API UEnum* Z_Construct_UEnum_IronChess_EPieceColor();
IRONCHESS_API UEnum* Z_Construct_UEnum_IronChess_EPieceType();
IRONCHESS_API UScriptStruct* Z_Construct_UScriptStruct_FChessBoardState();
IRONCHESS_API UScriptStruct* Z_Construct_UScriptStruct_FChessMove();
IRONCHESS_API UScriptStruct* Z_Construct_UScriptStruct_FChessPiece();
IRONCHESS_API UScriptStruct* Z_Construct_UScriptStruct_FChessPosition();
UPackage* Z_Construct_UPackage__Script_IronChess();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EPieceType ****************************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPieceType;
static UEnum* EPieceType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EPieceType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EPieceType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_IronChess_EPieceType, (UObject*)Z_Construct_UPackage__Script_IronChess(), TEXT("EPieceType"));
	}
	return Z_Registration_Info_UEnum_EPieceType.OuterSingleton;
}
template<> IRONCHESS_API UEnum* StaticEnum<EPieceType>()
{
	return EPieceType_StaticEnum();
}
struct Z_Construct_UEnum_IronChess_EPieceType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Bishop.Name", "EPieceType::Bishop" },
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Core types and enumerations for the Iron Chess game system\n */// Forward declarations\n" },
#endif
		{ "King.Name", "EPieceType::King" },
		{ "Knight.Name", "EPieceType::Knight" },
		{ "ModuleRelativePath", "Core/ChessTypes.h" },
		{ "None.Name", "EPieceType::None" },
		{ "Pawn.Name", "EPieceType::Pawn" },
		{ "Queen.Name", "EPieceType::Queen" },
		{ "Rook.Name", "EPieceType::Rook" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Core types and enumerations for the Iron Chess game system\n // Forward declarations" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EPieceType::None", (int64)EPieceType::None },
		{ "EPieceType::Pawn", (int64)EPieceType::Pawn },
		{ "EPieceType::Rook", (int64)EPieceType::Rook },
		{ "EPieceType::Knight", (int64)EPieceType::Knight },
		{ "EPieceType::Bishop", (int64)EPieceType::Bishop },
		{ "EPieceType::Queen", (int64)EPieceType::Queen },
		{ "EPieceType::King", (int64)EPieceType::King },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_IronChess_EPieceType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_IronChess,
	nullptr,
	"EPieceType",
	"EPieceType",
	Z_Construct_UEnum_IronChess_EPieceType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_IronChess_EPieceType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_IronChess_EPieceType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_IronChess_EPieceType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_IronChess_EPieceType()
{
	if (!Z_Registration_Info_UEnum_EPieceType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPieceType.InnerSingleton, Z_Construct_UEnum_IronChess_EPieceType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EPieceType.InnerSingleton;
}
// ********** End Enum EPieceType ******************************************************************

// ********** Begin Enum EPieceColor ***************************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPieceColor;
static UEnum* EPieceColor_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EPieceColor.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EPieceColor.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_IronChess_EPieceColor, (UObject*)Z_Construct_UPackage__Script_IronChess(), TEXT("EPieceColor"));
	}
	return Z_Registration_Info_UEnum_EPieceColor.OuterSingleton;
}
template<> IRONCHESS_API UEnum* StaticEnum<EPieceColor>()
{
	return EPieceColor_StaticEnum();
}
struct Z_Construct_UEnum_IronChess_EPieceColor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Black.Name", "EPieceColor::Black" },
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Core/ChessTypes.h" },
		{ "None.Name", "EPieceColor::None" },
		{ "White.Name", "EPieceColor::White" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EPieceColor::None", (int64)EPieceColor::None },
		{ "EPieceColor::White", (int64)EPieceColor::White },
		{ "EPieceColor::Black", (int64)EPieceColor::Black },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_IronChess_EPieceColor_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_IronChess,
	nullptr,
	"EPieceColor",
	"EPieceColor",
	Z_Construct_UEnum_IronChess_EPieceColor_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_IronChess_EPieceColor_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_IronChess_EPieceColor_Statics::Enum_MetaDataParams), Z_Construct_UEnum_IronChess_EPieceColor_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_IronChess_EPieceColor()
{
	if (!Z_Registration_Info_UEnum_EPieceColor.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPieceColor.InnerSingleton, Z_Construct_UEnum_IronChess_EPieceColor_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EPieceColor.InnerSingleton;
}
// ********** End Enum EPieceColor *****************************************************************

// ********** Begin Enum EGameState ****************************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EGameState;
static UEnum* EGameState_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EGameState.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EGameState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_IronChess_EGameState, (UObject*)Z_Construct_UPackage__Script_IronChess(), TEXT("EGameState"));
	}
	return Z_Registration_Info_UEnum_EGameState.OuterSingleton;
}
template<> IRONCHESS_API UEnum* StaticEnum<EGameState>()
{
	return EGameState_StaticEnum();
}
struct Z_Construct_UEnum_IronChess_EGameState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Check.Name", "EGameState::Check" },
		{ "Checkmate.Name", "EGameState::Checkmate" },
		{ "Draw.Name", "EGameState::Draw" },
		{ "InProgress.Name", "EGameState::InProgress" },
		{ "ModuleRelativePath", "Core/ChessTypes.h" },
		{ "Stalemate.Name", "EGameState::Stalemate" },
		{ "WaitingForPlayers.Name", "EGameState::WaitingForPlayers" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EGameState::WaitingForPlayers", (int64)EGameState::WaitingForPlayers },
		{ "EGameState::InProgress", (int64)EGameState::InProgress },
		{ "EGameState::Check", (int64)EGameState::Check },
		{ "EGameState::Checkmate", (int64)EGameState::Checkmate },
		{ "EGameState::Stalemate", (int64)EGameState::Stalemate },
		{ "EGameState::Draw", (int64)EGameState::Draw },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_IronChess_EGameState_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_IronChess,
	nullptr,
	"EGameState",
	"EGameState",
	Z_Construct_UEnum_IronChess_EGameState_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_IronChess_EGameState_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_IronChess_EGameState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_IronChess_EGameState_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_IronChess_EGameState()
{
	if (!Z_Registration_Info_UEnum_EGameState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EGameState.InnerSingleton, Z_Construct_UEnum_IronChess_EGameState_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EGameState.InnerSingleton;
}
// ********** End Enum EGameState ******************************************************************

// ********** Begin Enum EMoveType *****************************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EMoveType;
static UEnum* EMoveType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EMoveType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EMoveType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_IronChess_EMoveType, (UObject*)Z_Construct_UPackage__Script_IronChess(), TEXT("EMoveType"));
	}
	return Z_Registration_Info_UEnum_EMoveType.OuterSingleton;
}
template<> IRONCHESS_API UEnum* StaticEnum<EMoveType>()
{
	return EMoveType_StaticEnum();
}
struct Z_Construct_UEnum_IronChess_EMoveType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Capture.Name", "EMoveType::Capture" },
		{ "Castle.Name", "EMoveType::Castle" },
		{ "Castling.Name", "EMoveType::Castling" },
		{ "EnPassant.Name", "EMoveType::EnPassant" },
		{ "ModuleRelativePath", "Core/ChessTypes.h" },
		{ "Normal.Name", "EMoveType::Normal" },
		{ "PawnPromotion.Name", "EMoveType::PawnPromotion" },
		{ "Promotion.Name", "EMoveType::Promotion" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EMoveType::Normal", (int64)EMoveType::Normal },
		{ "EMoveType::Capture", (int64)EMoveType::Capture },
		{ "EMoveType::Castling", (int64)EMoveType::Castling },
		{ "EMoveType::Castle", (int64)EMoveType::Castle },
		{ "EMoveType::EnPassant", (int64)EMoveType::EnPassant },
		{ "EMoveType::PawnPromotion", (int64)EMoveType::PawnPromotion },
		{ "EMoveType::Promotion", (int64)EMoveType::Promotion },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_IronChess_EMoveType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_IronChess,
	nullptr,
	"EMoveType",
	"EMoveType",
	Z_Construct_UEnum_IronChess_EMoveType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_IronChess_EMoveType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_IronChess_EMoveType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_IronChess_EMoveType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_IronChess_EMoveType()
{
	if (!Z_Registration_Info_UEnum_EMoveType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EMoveType.InnerSingleton, Z_Construct_UEnum_IronChess_EMoveType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EMoveType.InnerSingleton;
}
// ********** End Enum EMoveType *******************************************************************

// ********** Begin ScriptStruct FChessPosition ****************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FChessPosition;
class UScriptStruct* FChessPosition::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FChessPosition.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FChessPosition.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FChessPosition, (UObject*)Z_Construct_UPackage__Script_IronChess(), TEXT("ChessPosition"));
	}
	return Z_Registration_Info_UScriptStruct_FChessPosition.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FChessPosition_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Represents a position on the chess board\n */" },
#endif
		{ "ModuleRelativePath", "Core/ChessTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Represents a position on the chess board" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rank_MetaData[] = {
		{ "Category", "ChessPosition" },
		{ "ModuleRelativePath", "Core/ChessTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_File_MetaData[] = {
		{ "Category", "ChessPosition" },
		{ "ModuleRelativePath", "Core/ChessTypes.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_Rank;
	static const UECodeGen_Private::FIntPropertyParams NewProp_File;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FChessPosition>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FChessPosition_Statics::NewProp_Rank = { "Rank", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FChessPosition, Rank), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rank_MetaData), NewProp_Rank_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FChessPosition_Statics::NewProp_File = { "File", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FChessPosition, File), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_File_MetaData), NewProp_File_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FChessPosition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FChessPosition_Statics::NewProp_Rank,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FChessPosition_Statics::NewProp_File,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FChessPosition_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FChessPosition_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_IronChess,
	nullptr,
	&NewStructOps,
	"ChessPosition",
	Z_Construct_UScriptStruct_FChessPosition_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FChessPosition_Statics::PropPointers),
	sizeof(FChessPosition),
	alignof(FChessPosition),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FChessPosition_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FChessPosition_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FChessPosition()
{
	if (!Z_Registration_Info_UScriptStruct_FChessPosition.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FChessPosition.InnerSingleton, Z_Construct_UScriptStruct_FChessPosition_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FChessPosition.InnerSingleton;
}
// ********** End ScriptStruct FChessPosition ******************************************************

// ********** Begin ScriptStruct FChessPiece *******************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FChessPiece;
class UScriptStruct* FChessPiece::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FChessPiece.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FChessPiece.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FChessPiece, (UObject*)Z_Construct_UPackage__Script_IronChess(), TEXT("ChessPiece"));
	}
	return Z_Registration_Info_UScriptStruct_FChessPiece.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FChessPiece_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Represents a chess piece\n */" },
#endif
		{ "ModuleRelativePath", "Core/ChessTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Represents a chess piece" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Type_MetaData[] = {
		{ "Category", "ChessPiece" },
		{ "ModuleRelativePath", "Core/ChessTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Color_MetaData[] = {
		{ "Category", "ChessPiece" },
		{ "ModuleRelativePath", "Core/ChessTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HasMoved_MetaData[] = {
		{ "Category", "ChessPiece" },
		{ "ModuleRelativePath", "Core/ChessTypes.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_Type_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Type;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Color_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Color;
	static void NewProp_HasMoved_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_HasMoved;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FChessPiece>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FChessPiece_Statics::NewProp_Type_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FChessPiece_Statics::NewProp_Type = { "Type", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FChessPiece, Type), Z_Construct_UEnum_IronChess_EPieceType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Type_MetaData), NewProp_Type_MetaData) }; // 2986096202
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FChessPiece_Statics::NewProp_Color_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FChessPiece_Statics::NewProp_Color = { "Color", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FChessPiece, Color), Z_Construct_UEnum_IronChess_EPieceColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Color_MetaData), NewProp_Color_MetaData) }; // 1636929315
void Z_Construct_UScriptStruct_FChessPiece_Statics::NewProp_HasMoved_SetBit(void* Obj)
{
	((FChessPiece*)Obj)->HasMoved = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FChessPiece_Statics::NewProp_HasMoved = { "HasMoved", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FChessPiece), &Z_Construct_UScriptStruct_FChessPiece_Statics::NewProp_HasMoved_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HasMoved_MetaData), NewProp_HasMoved_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FChessPiece_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FChessPiece_Statics::NewProp_Type_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FChessPiece_Statics::NewProp_Type,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FChessPiece_Statics::NewProp_Color_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FChessPiece_Statics::NewProp_Color,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FChessPiece_Statics::NewProp_HasMoved,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FChessPiece_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FChessPiece_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_IronChess,
	nullptr,
	&NewStructOps,
	"ChessPiece",
	Z_Construct_UScriptStruct_FChessPiece_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FChessPiece_Statics::PropPointers),
	sizeof(FChessPiece),
	alignof(FChessPiece),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FChessPiece_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FChessPiece_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FChessPiece()
{
	if (!Z_Registration_Info_UScriptStruct_FChessPiece.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FChessPiece.InnerSingleton, Z_Construct_UScriptStruct_FChessPiece_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FChessPiece.InnerSingleton;
}
// ********** End ScriptStruct FChessPiece *********************************************************

// ********** Begin ScriptStruct FChessMove ********************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FChessMove;
class UScriptStruct* FChessMove::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FChessMove.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FChessMove.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FChessMove, (UObject*)Z_Construct_UPackage__Script_IronChess(), TEXT("ChessMove"));
	}
	return Z_Registration_Info_UScriptStruct_FChessMove.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FChessMove_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Represents a chess move\n */" },
#endif
		{ "ModuleRelativePath", "Core/ChessTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Represents a chess move" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_From_MetaData[] = {
		{ "Category", "ChessMove" },
		{ "ModuleRelativePath", "Core/ChessTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_To_MetaData[] = {
		{ "Category", "ChessMove" },
		{ "ModuleRelativePath", "Core/ChessTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveType_MetaData[] = {
		{ "Category", "ChessMove" },
		{ "ModuleRelativePath", "Core/ChessTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PromotionPiece_MetaData[] = {
		{ "Category", "ChessMove" },
		{ "ModuleRelativePath", "Core/ChessTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CapturedPiece_MetaData[] = {
		{ "Category", "ChessMove" },
		{ "ModuleRelativePath", "Core/ChessTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IsCheck_MetaData[] = {
		{ "Category", "ChessMove" },
		{ "ModuleRelativePath", "Core/ChessTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IsCheckmate_MetaData[] = {
		{ "Category", "ChessMove" },
		{ "ModuleRelativePath", "Core/ChessTypes.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_From;
	static const UECodeGen_Private::FStructPropertyParams NewProp_To;
	static const UECodeGen_Private::FBytePropertyParams NewProp_MoveType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_MoveType;
	static const UECodeGen_Private::FBytePropertyParams NewProp_PromotionPiece_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_PromotionPiece;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CapturedPiece;
	static void NewProp_IsCheck_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_IsCheck;
	static void NewProp_IsCheckmate_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_IsCheckmate;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FChessMove>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FChessMove_Statics::NewProp_From = { "From", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FChessMove, From), Z_Construct_UScriptStruct_FChessPosition, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_From_MetaData), NewProp_From_MetaData) }; // 1812120650
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FChessMove_Statics::NewProp_To = { "To", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FChessMove, To), Z_Construct_UScriptStruct_FChessPosition, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_To_MetaData), NewProp_To_MetaData) }; // 1812120650
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FChessMove_Statics::NewProp_MoveType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FChessMove_Statics::NewProp_MoveType = { "MoveType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FChessMove, MoveType), Z_Construct_UEnum_IronChess_EMoveType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveType_MetaData), NewProp_MoveType_MetaData) }; // 948456255
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FChessMove_Statics::NewProp_PromotionPiece_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FChessMove_Statics::NewProp_PromotionPiece = { "PromotionPiece", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FChessMove, PromotionPiece), Z_Construct_UEnum_IronChess_EPieceType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PromotionPiece_MetaData), NewProp_PromotionPiece_MetaData) }; // 2986096202
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FChessMove_Statics::NewProp_CapturedPiece = { "CapturedPiece", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FChessMove, CapturedPiece), Z_Construct_UScriptStruct_FChessPiece, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CapturedPiece_MetaData), NewProp_CapturedPiece_MetaData) }; // 15703377
void Z_Construct_UScriptStruct_FChessMove_Statics::NewProp_IsCheck_SetBit(void* Obj)
{
	((FChessMove*)Obj)->IsCheck = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FChessMove_Statics::NewProp_IsCheck = { "IsCheck", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FChessMove), &Z_Construct_UScriptStruct_FChessMove_Statics::NewProp_IsCheck_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IsCheck_MetaData), NewProp_IsCheck_MetaData) };
void Z_Construct_UScriptStruct_FChessMove_Statics::NewProp_IsCheckmate_SetBit(void* Obj)
{
	((FChessMove*)Obj)->IsCheckmate = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FChessMove_Statics::NewProp_IsCheckmate = { "IsCheckmate", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FChessMove), &Z_Construct_UScriptStruct_FChessMove_Statics::NewProp_IsCheckmate_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IsCheckmate_MetaData), NewProp_IsCheckmate_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FChessMove_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FChessMove_Statics::NewProp_From,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FChessMove_Statics::NewProp_To,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FChessMove_Statics::NewProp_MoveType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FChessMove_Statics::NewProp_MoveType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FChessMove_Statics::NewProp_PromotionPiece_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FChessMove_Statics::NewProp_PromotionPiece,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FChessMove_Statics::NewProp_CapturedPiece,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FChessMove_Statics::NewProp_IsCheck,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FChessMove_Statics::NewProp_IsCheckmate,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FChessMove_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FChessMove_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_IronChess,
	nullptr,
	&NewStructOps,
	"ChessMove",
	Z_Construct_UScriptStruct_FChessMove_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FChessMove_Statics::PropPointers),
	sizeof(FChessMove),
	alignof(FChessMove),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FChessMove_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FChessMove_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FChessMove()
{
	if (!Z_Registration_Info_UScriptStruct_FChessMove.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FChessMove.InnerSingleton, Z_Construct_UScriptStruct_FChessMove_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FChessMove.InnerSingleton;
}
// ********** End ScriptStruct FChessMove **********************************************************

// ********** Begin ScriptStruct FChessBoardState **************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FChessBoardState;
class UScriptStruct* FChessBoardState::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FChessBoardState.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FChessBoardState.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FChessBoardState, (UObject*)Z_Construct_UPackage__Script_IronChess(), TEXT("ChessBoardState"));
	}
	return Z_Registration_Info_UScriptStruct_FChessBoardState.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FChessBoardState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Represents the complete state of the chess board\n */" },
#endif
		{ "ModuleRelativePath", "Core/ChessTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Represents the complete state of the chess board" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Board_MetaData[] = {
		{ "Category", "ChessBoardState" },
		{ "ModuleRelativePath", "Core/ChessTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActivePlayer_MetaData[] = {
		{ "Category", "ChessBoardState" },
		{ "ModuleRelativePath", "Core/ChessTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GameState_MetaData[] = {
		{ "Category", "ChessBoardState" },
		{ "ModuleRelativePath", "Core/ChessTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveNumber_MetaData[] = {
		{ "Category", "ChessBoardState" },
		{ "ModuleRelativePath", "Core/ChessTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HalfMoveCount_MetaData[] = {
		{ "Category", "ChessBoardState" },
		{ "ModuleRelativePath", "Core/ChessTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnPassantTarget_MetaData[] = {
		{ "Category", "ChessBoardState" },
		{ "ModuleRelativePath", "Core/ChessTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WhiteCanCastleKingside_MetaData[] = {
		{ "Category", "ChessBoardState" },
		{ "ModuleRelativePath", "Core/ChessTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WhiteCanCastleQueenside_MetaData[] = {
		{ "Category", "ChessBoardState" },
		{ "ModuleRelativePath", "Core/ChessTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BlackCanCastleKingside_MetaData[] = {
		{ "Category", "ChessBoardState" },
		{ "ModuleRelativePath", "Core/ChessTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BlackCanCastleQueenside_MetaData[] = {
		{ "Category", "ChessBoardState" },
		{ "ModuleRelativePath", "Core/ChessTypes.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Board_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Board;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ActivePlayer_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ActivePlayer;
	static const UECodeGen_Private::FBytePropertyParams NewProp_GameState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_GameState;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MoveNumber;
	static const UECodeGen_Private::FIntPropertyParams NewProp_HalfMoveCount;
	static const UECodeGen_Private::FStructPropertyParams NewProp_EnPassantTarget;
	static void NewProp_WhiteCanCastleKingside_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_WhiteCanCastleKingside;
	static void NewProp_WhiteCanCastleQueenside_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_WhiteCanCastleQueenside;
	static void NewProp_BlackCanCastleKingside_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_BlackCanCastleKingside;
	static void NewProp_BlackCanCastleQueenside_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_BlackCanCastleQueenside;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FChessBoardState>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FChessBoardState_Statics::NewProp_Board_Inner = { "Board", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FChessPiece, METADATA_PARAMS(0, nullptr) }; // 15703377
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FChessBoardState_Statics::NewProp_Board = { "Board", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FChessBoardState, Board), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Board_MetaData), NewProp_Board_MetaData) }; // 15703377
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FChessBoardState_Statics::NewProp_ActivePlayer_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FChessBoardState_Statics::NewProp_ActivePlayer = { "ActivePlayer", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FChessBoardState, ActivePlayer), Z_Construct_UEnum_IronChess_EPieceColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActivePlayer_MetaData), NewProp_ActivePlayer_MetaData) }; // 1636929315
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FChessBoardState_Statics::NewProp_GameState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FChessBoardState_Statics::NewProp_GameState = { "GameState", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FChessBoardState, GameState), Z_Construct_UEnum_IronChess_EGameState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GameState_MetaData), NewProp_GameState_MetaData) }; // 2482667857
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FChessBoardState_Statics::NewProp_MoveNumber = { "MoveNumber", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FChessBoardState, MoveNumber), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveNumber_MetaData), NewProp_MoveNumber_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FChessBoardState_Statics::NewProp_HalfMoveCount = { "HalfMoveCount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FChessBoardState, HalfMoveCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HalfMoveCount_MetaData), NewProp_HalfMoveCount_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FChessBoardState_Statics::NewProp_EnPassantTarget = { "EnPassantTarget", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FChessBoardState, EnPassantTarget), Z_Construct_UScriptStruct_FChessPosition, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnPassantTarget_MetaData), NewProp_EnPassantTarget_MetaData) }; // 1812120650
void Z_Construct_UScriptStruct_FChessBoardState_Statics::NewProp_WhiteCanCastleKingside_SetBit(void* Obj)
{
	((FChessBoardState*)Obj)->WhiteCanCastleKingside = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FChessBoardState_Statics::NewProp_WhiteCanCastleKingside = { "WhiteCanCastleKingside", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FChessBoardState), &Z_Construct_UScriptStruct_FChessBoardState_Statics::NewProp_WhiteCanCastleKingside_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WhiteCanCastleKingside_MetaData), NewProp_WhiteCanCastleKingside_MetaData) };
void Z_Construct_UScriptStruct_FChessBoardState_Statics::NewProp_WhiteCanCastleQueenside_SetBit(void* Obj)
{
	((FChessBoardState*)Obj)->WhiteCanCastleQueenside = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FChessBoardState_Statics::NewProp_WhiteCanCastleQueenside = { "WhiteCanCastleQueenside", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FChessBoardState), &Z_Construct_UScriptStruct_FChessBoardState_Statics::NewProp_WhiteCanCastleQueenside_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WhiteCanCastleQueenside_MetaData), NewProp_WhiteCanCastleQueenside_MetaData) };
void Z_Construct_UScriptStruct_FChessBoardState_Statics::NewProp_BlackCanCastleKingside_SetBit(void* Obj)
{
	((FChessBoardState*)Obj)->BlackCanCastleKingside = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FChessBoardState_Statics::NewProp_BlackCanCastleKingside = { "BlackCanCastleKingside", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FChessBoardState), &Z_Construct_UScriptStruct_FChessBoardState_Statics::NewProp_BlackCanCastleKingside_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BlackCanCastleKingside_MetaData), NewProp_BlackCanCastleKingside_MetaData) };
void Z_Construct_UScriptStruct_FChessBoardState_Statics::NewProp_BlackCanCastleQueenside_SetBit(void* Obj)
{
	((FChessBoardState*)Obj)->BlackCanCastleQueenside = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FChessBoardState_Statics::NewProp_BlackCanCastleQueenside = { "BlackCanCastleQueenside", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FChessBoardState), &Z_Construct_UScriptStruct_FChessBoardState_Statics::NewProp_BlackCanCastleQueenside_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BlackCanCastleQueenside_MetaData), NewProp_BlackCanCastleQueenside_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FChessBoardState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FChessBoardState_Statics::NewProp_Board_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FChessBoardState_Statics::NewProp_Board,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FChessBoardState_Statics::NewProp_ActivePlayer_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FChessBoardState_Statics::NewProp_ActivePlayer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FChessBoardState_Statics::NewProp_GameState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FChessBoardState_Statics::NewProp_GameState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FChessBoardState_Statics::NewProp_MoveNumber,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FChessBoardState_Statics::NewProp_HalfMoveCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FChessBoardState_Statics::NewProp_EnPassantTarget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FChessBoardState_Statics::NewProp_WhiteCanCastleKingside,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FChessBoardState_Statics::NewProp_WhiteCanCastleQueenside,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FChessBoardState_Statics::NewProp_BlackCanCastleKingside,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FChessBoardState_Statics::NewProp_BlackCanCastleQueenside,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FChessBoardState_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FChessBoardState_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_IronChess,
	nullptr,
	&NewStructOps,
	"ChessBoardState",
	Z_Construct_UScriptStruct_FChessBoardState_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FChessBoardState_Statics::PropPointers),
	sizeof(FChessBoardState),
	alignof(FChessBoardState),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FChessBoardState_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FChessBoardState_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FChessBoardState()
{
	if (!Z_Registration_Info_UScriptStruct_FChessBoardState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FChessBoardState.InnerSingleton, Z_Construct_UScriptStruct_FChessBoardState_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FChessBoardState.InnerSingleton;
}
// ********** End ScriptStruct FChessBoardState ****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Core_ChessTypes_h__Script_IronChess_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EPieceType_StaticEnum, TEXT("EPieceType"), &Z_Registration_Info_UEnum_EPieceType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2986096202U) },
		{ EPieceColor_StaticEnum, TEXT("EPieceColor"), &Z_Registration_Info_UEnum_EPieceColor, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1636929315U) },
		{ EGameState_StaticEnum, TEXT("EGameState"), &Z_Registration_Info_UEnum_EGameState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2482667857U) },
		{ EMoveType_StaticEnum, TEXT("EMoveType"), &Z_Registration_Info_UEnum_EMoveType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 948456255U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FChessPosition::StaticStruct, Z_Construct_UScriptStruct_FChessPosition_Statics::NewStructOps, TEXT("ChessPosition"), &Z_Registration_Info_UScriptStruct_FChessPosition, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FChessPosition), 1812120650U) },
		{ FChessPiece::StaticStruct, Z_Construct_UScriptStruct_FChessPiece_Statics::NewStructOps, TEXT("ChessPiece"), &Z_Registration_Info_UScriptStruct_FChessPiece, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FChessPiece), 15703377U) },
		{ FChessMove::StaticStruct, Z_Construct_UScriptStruct_FChessMove_Statics::NewStructOps, TEXT("ChessMove"), &Z_Registration_Info_UScriptStruct_FChessMove, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FChessMove), 1361898884U) },
		{ FChessBoardState::StaticStruct, Z_Construct_UScriptStruct_FChessBoardState_Statics::NewStructOps, TEXT("ChessBoardState"), &Z_Registration_Info_UScriptStruct_FChessBoardState, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FChessBoardState), 902976410U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Core_ChessTypes_h__Script_IronChess_2722373984(TEXT("/Script/IronChess"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Core_ChessTypes_h__Script_IronChess_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Core_ChessTypes_h__Script_IronChess_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Core_ChessTypes_h__Script_IronChess_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Core_ChessTypes_h__Script_IronChess_Statics::EnumInfo));
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
