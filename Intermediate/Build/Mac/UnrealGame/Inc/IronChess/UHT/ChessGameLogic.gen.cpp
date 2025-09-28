// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ChessGameLogic.h"
#include "ChessTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeChessGameLogic() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
IRONCHESS_API UClass* Z_Construct_UClass_UChessGameLogic();
IRONCHESS_API UClass* Z_Construct_UClass_UChessGameLogic_NoRegister();
IRONCHESS_API UEnum* Z_Construct_UEnum_IronChess_EGameState();
IRONCHESS_API UEnum* Z_Construct_UEnum_IronChess_EPieceColor();
IRONCHESS_API UFunction* Z_Construct_UDelegateFunction_UChessGameLogic_OnCheck__DelegateSignature();
IRONCHESS_API UFunction* Z_Construct_UDelegateFunction_UChessGameLogic_OnGameStateChanged__DelegateSignature();
IRONCHESS_API UFunction* Z_Construct_UDelegateFunction_UChessGameLogic_OnMoveMade__DelegateSignature();
IRONCHESS_API UScriptStruct* Z_Construct_UScriptStruct_FChessBoardState();
IRONCHESS_API UScriptStruct* Z_Construct_UScriptStruct_FChessMove();
IRONCHESS_API UScriptStruct* Z_Construct_UScriptStruct_FChessPiece();
IRONCHESS_API UScriptStruct* Z_Construct_UScriptStruct_FChessPosition();
UPackage* Z_Construct_UPackage__Script_IronChess();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FOnMoveMade ***********************************************************
struct Z_Construct_UDelegateFunction_UChessGameLogic_OnMoveMade__DelegateSignature_Statics
{
	struct ChessGameLogic_eventOnMoveMade_Parms
	{
		FChessMove Move;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Event delegates\n" },
#endif
		{ "ModuleRelativePath", "Core/ChessGameLogic.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Event delegates" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Move_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Move;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_UChessGameLogic_OnMoveMade__DelegateSignature_Statics::NewProp_Move = { "Move", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessGameLogic_eventOnMoveMade_Parms, Move), Z_Construct_UScriptStruct_FChessMove, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Move_MetaData), NewProp_Move_MetaData) }; // 1361898884
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UChessGameLogic_OnMoveMade__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UChessGameLogic_OnMoveMade__DelegateSignature_Statics::NewProp_Move,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UChessGameLogic_OnMoveMade__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_UChessGameLogic_OnMoveMade__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UChessGameLogic, nullptr, "OnMoveMade__DelegateSignature", Z_Construct_UDelegateFunction_UChessGameLogic_OnMoveMade__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UChessGameLogic_OnMoveMade__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UChessGameLogic_OnMoveMade__DelegateSignature_Statics::ChessGameLogic_eventOnMoveMade_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UChessGameLogic_OnMoveMade__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UChessGameLogic_OnMoveMade__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_UChessGameLogic_OnMoveMade__DelegateSignature_Statics::ChessGameLogic_eventOnMoveMade_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_UChessGameLogic_OnMoveMade__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UChessGameLogic_OnMoveMade__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void UChessGameLogic::FOnMoveMade_DelegateWrapper(const FMulticastScriptDelegate& OnMoveMade, FChessMove const& Move)
{
	struct ChessGameLogic_eventOnMoveMade_Parms
	{
		FChessMove Move;
	};
	ChessGameLogic_eventOnMoveMade_Parms Parms;
	Parms.Move=Move;
	OnMoveMade.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnMoveMade *************************************************************

// ********** Begin Delegate FOnGameStateChanged ***************************************************
struct Z_Construct_UDelegateFunction_UChessGameLogic_OnGameStateChanged__DelegateSignature_Statics
{
	struct ChessGameLogic_eventOnGameStateChanged_Parms
	{
		EGameState NewState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/ChessGameLogic.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_NewState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NewState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_UChessGameLogic_OnGameStateChanged__DelegateSignature_Statics::NewProp_NewState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_UChessGameLogic_OnGameStateChanged__DelegateSignature_Statics::NewProp_NewState = { "NewState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessGameLogic_eventOnGameStateChanged_Parms, NewState), Z_Construct_UEnum_IronChess_EGameState, METADATA_PARAMS(0, nullptr) }; // 2482667857
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UChessGameLogic_OnGameStateChanged__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UChessGameLogic_OnGameStateChanged__DelegateSignature_Statics::NewProp_NewState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UChessGameLogic_OnGameStateChanged__DelegateSignature_Statics::NewProp_NewState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UChessGameLogic_OnGameStateChanged__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_UChessGameLogic_OnGameStateChanged__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UChessGameLogic, nullptr, "OnGameStateChanged__DelegateSignature", Z_Construct_UDelegateFunction_UChessGameLogic_OnGameStateChanged__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UChessGameLogic_OnGameStateChanged__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UChessGameLogic_OnGameStateChanged__DelegateSignature_Statics::ChessGameLogic_eventOnGameStateChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UChessGameLogic_OnGameStateChanged__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UChessGameLogic_OnGameStateChanged__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_UChessGameLogic_OnGameStateChanged__DelegateSignature_Statics::ChessGameLogic_eventOnGameStateChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_UChessGameLogic_OnGameStateChanged__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UChessGameLogic_OnGameStateChanged__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void UChessGameLogic::FOnGameStateChanged_DelegateWrapper(const FMulticastScriptDelegate& OnGameStateChanged, EGameState NewState)
{
	struct ChessGameLogic_eventOnGameStateChanged_Parms
	{
		EGameState NewState;
	};
	ChessGameLogic_eventOnGameStateChanged_Parms Parms;
	Parms.NewState=NewState;
	OnGameStateChanged.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnGameStateChanged *****************************************************

// ********** Begin Delegate FOnCheck **************************************************************
struct Z_Construct_UDelegateFunction_UChessGameLogic_OnCheck__DelegateSignature_Statics
{
	struct ChessGameLogic_eventOnCheck_Parms
	{
		EPieceColor PlayerInCheck;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/ChessGameLogic.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_PlayerInCheck_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_PlayerInCheck;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_UChessGameLogic_OnCheck__DelegateSignature_Statics::NewProp_PlayerInCheck_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_UChessGameLogic_OnCheck__DelegateSignature_Statics::NewProp_PlayerInCheck = { "PlayerInCheck", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessGameLogic_eventOnCheck_Parms, PlayerInCheck), Z_Construct_UEnum_IronChess_EPieceColor, METADATA_PARAMS(0, nullptr) }; // 1636929315
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UChessGameLogic_OnCheck__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UChessGameLogic_OnCheck__DelegateSignature_Statics::NewProp_PlayerInCheck_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UChessGameLogic_OnCheck__DelegateSignature_Statics::NewProp_PlayerInCheck,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UChessGameLogic_OnCheck__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_UChessGameLogic_OnCheck__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UChessGameLogic, nullptr, "OnCheck__DelegateSignature", Z_Construct_UDelegateFunction_UChessGameLogic_OnCheck__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UChessGameLogic_OnCheck__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UChessGameLogic_OnCheck__DelegateSignature_Statics::ChessGameLogic_eventOnCheck_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UChessGameLogic_OnCheck__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UChessGameLogic_OnCheck__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_UChessGameLogic_OnCheck__DelegateSignature_Statics::ChessGameLogic_eventOnCheck_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_UChessGameLogic_OnCheck__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UChessGameLogic_OnCheck__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void UChessGameLogic::FOnCheck_DelegateWrapper(const FMulticastScriptDelegate& OnCheck, EPieceColor PlayerInCheck)
{
	struct ChessGameLogic_eventOnCheck_Parms
	{
		EPieceColor PlayerInCheck;
	};
	ChessGameLogic_eventOnCheck_Parms Parms;
	Parms.PlayerInCheck=PlayerInCheck;
	OnCheck.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnCheck ****************************************************************

// ********** Begin Class UChessGameLogic Function CanCastle ***************************************
struct Z_Construct_UFunction_UChessGameLogic_CanCastle_Statics
{
	struct ChessGameLogic_eventCanCastle_Parms
	{
		EPieceColor Color;
		bool Kingside;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Chess" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Special moves\n" },
#endif
		{ "ModuleRelativePath", "Core/ChessGameLogic.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Special moves" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_Color_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Color;
	static void NewProp_Kingside_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_Kingside;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UChessGameLogic_CanCastle_Statics::NewProp_Color_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UChessGameLogic_CanCastle_Statics::NewProp_Color = { "Color", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessGameLogic_eventCanCastle_Parms, Color), Z_Construct_UEnum_IronChess_EPieceColor, METADATA_PARAMS(0, nullptr) }; // 1636929315
void Z_Construct_UFunction_UChessGameLogic_CanCastle_Statics::NewProp_Kingside_SetBit(void* Obj)
{
	((ChessGameLogic_eventCanCastle_Parms*)Obj)->Kingside = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UChessGameLogic_CanCastle_Statics::NewProp_Kingside = { "Kingside", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ChessGameLogic_eventCanCastle_Parms), &Z_Construct_UFunction_UChessGameLogic_CanCastle_Statics::NewProp_Kingside_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UChessGameLogic_CanCastle_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ChessGameLogic_eventCanCastle_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UChessGameLogic_CanCastle_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ChessGameLogic_eventCanCastle_Parms), &Z_Construct_UFunction_UChessGameLogic_CanCastle_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UChessGameLogic_CanCastle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_CanCastle_Statics::NewProp_Color_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_CanCastle_Statics::NewProp_Color,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_CanCastle_Statics::NewProp_Kingside,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_CanCastle_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_CanCastle_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UChessGameLogic_CanCastle_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UChessGameLogic, nullptr, "CanCastle", Z_Construct_UFunction_UChessGameLogic_CanCastle_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_CanCastle_Statics::PropPointers), sizeof(Z_Construct_UFunction_UChessGameLogic_CanCastle_Statics::ChessGameLogic_eventCanCastle_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_CanCastle_Statics::Function_MetaDataParams), Z_Construct_UFunction_UChessGameLogic_CanCastle_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UChessGameLogic_CanCastle_Statics::ChessGameLogic_eventCanCastle_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UChessGameLogic_CanCastle()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UChessGameLogic_CanCastle_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UChessGameLogic::execCanCastle)
{
	P_GET_ENUM(EPieceColor,Z_Param_Color);
	P_GET_UBOOL(Z_Param_Kingside);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->CanCastle(EPieceColor(Z_Param_Color),Z_Param_Kingside);
	P_NATIVE_END;
}
// ********** End Class UChessGameLogic Function CanCastle *****************************************

// ********** Begin Class UChessGameLogic Function FindKing ****************************************
struct Z_Construct_UFunction_UChessGameLogic_FindKing_Statics
{
	struct ChessGameLogic_eventFindKing_Parms
	{
		EPieceColor Color;
		FChessPosition ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Chess" },
		{ "ModuleRelativePath", "Core/ChessGameLogic.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_Color_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Color;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UChessGameLogic_FindKing_Statics::NewProp_Color_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UChessGameLogic_FindKing_Statics::NewProp_Color = { "Color", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessGameLogic_eventFindKing_Parms, Color), Z_Construct_UEnum_IronChess_EPieceColor, METADATA_PARAMS(0, nullptr) }; // 1636929315
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UChessGameLogic_FindKing_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessGameLogic_eventFindKing_Parms, ReturnValue), Z_Construct_UScriptStruct_FChessPosition, METADATA_PARAMS(0, nullptr) }; // 1812120650
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UChessGameLogic_FindKing_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_FindKing_Statics::NewProp_Color_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_FindKing_Statics::NewProp_Color,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_FindKing_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_FindKing_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UChessGameLogic_FindKing_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UChessGameLogic, nullptr, "FindKing", Z_Construct_UFunction_UChessGameLogic_FindKing_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_FindKing_Statics::PropPointers), sizeof(Z_Construct_UFunction_UChessGameLogic_FindKing_Statics::ChessGameLogic_eventFindKing_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_FindKing_Statics::Function_MetaDataParams), Z_Construct_UFunction_UChessGameLogic_FindKing_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UChessGameLogic_FindKing_Statics::ChessGameLogic_eventFindKing_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UChessGameLogic_FindKing()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UChessGameLogic_FindKing_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UChessGameLogic::execFindKing)
{
	P_GET_ENUM(EPieceColor,Z_Param_Color);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FChessPosition*)Z_Param__Result=P_THIS->FindKing(EPieceColor(Z_Param_Color));
	P_NATIVE_END;
}
// ********** End Class UChessGameLogic Function FindKing ******************************************

// ********** Begin Class UChessGameLogic Function GetActivePlayer *********************************
struct Z_Construct_UFunction_UChessGameLogic_GetActivePlayer_Statics
{
	struct ChessGameLogic_eventGetActivePlayer_Parms
	{
		EPieceColor ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Chess" },
		{ "ModuleRelativePath", "Core/ChessGameLogic.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UChessGameLogic_GetActivePlayer_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UChessGameLogic_GetActivePlayer_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessGameLogic_eventGetActivePlayer_Parms, ReturnValue), Z_Construct_UEnum_IronChess_EPieceColor, METADATA_PARAMS(0, nullptr) }; // 1636929315
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UChessGameLogic_GetActivePlayer_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_GetActivePlayer_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_GetActivePlayer_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_GetActivePlayer_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UChessGameLogic_GetActivePlayer_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UChessGameLogic, nullptr, "GetActivePlayer", Z_Construct_UFunction_UChessGameLogic_GetActivePlayer_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_GetActivePlayer_Statics::PropPointers), sizeof(Z_Construct_UFunction_UChessGameLogic_GetActivePlayer_Statics::ChessGameLogic_eventGetActivePlayer_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_GetActivePlayer_Statics::Function_MetaDataParams), Z_Construct_UFunction_UChessGameLogic_GetActivePlayer_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UChessGameLogic_GetActivePlayer_Statics::ChessGameLogic_eventGetActivePlayer_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UChessGameLogic_GetActivePlayer()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UChessGameLogic_GetActivePlayer_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UChessGameLogic::execGetActivePlayer)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EPieceColor*)Z_Param__Result=P_THIS->GetActivePlayer();
	P_NATIVE_END;
}
// ********** End Class UChessGameLogic Function GetActivePlayer ***********************************

// ********** Begin Class UChessGameLogic Function GetAttackedSquares ******************************
struct Z_Construct_UFunction_UChessGameLogic_GetAttackedSquares_Statics
{
	struct ChessGameLogic_eventGetAttackedSquares_Parms
	{
		EPieceColor Color;
		TArray<FChessPosition> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Chess" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Move generation helpers\n" },
#endif
		{ "ModuleRelativePath", "Core/ChessGameLogic.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Move generation helpers" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_Color_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Color;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UChessGameLogic_GetAttackedSquares_Statics::NewProp_Color_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UChessGameLogic_GetAttackedSquares_Statics::NewProp_Color = { "Color", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessGameLogic_eventGetAttackedSquares_Parms, Color), Z_Construct_UEnum_IronChess_EPieceColor, METADATA_PARAMS(0, nullptr) }; // 1636929315
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UChessGameLogic_GetAttackedSquares_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FChessPosition, METADATA_PARAMS(0, nullptr) }; // 1812120650
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UChessGameLogic_GetAttackedSquares_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessGameLogic_eventGetAttackedSquares_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 1812120650
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UChessGameLogic_GetAttackedSquares_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_GetAttackedSquares_Statics::NewProp_Color_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_GetAttackedSquares_Statics::NewProp_Color,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_GetAttackedSquares_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_GetAttackedSquares_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_GetAttackedSquares_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UChessGameLogic_GetAttackedSquares_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UChessGameLogic, nullptr, "GetAttackedSquares", Z_Construct_UFunction_UChessGameLogic_GetAttackedSquares_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_GetAttackedSquares_Statics::PropPointers), sizeof(Z_Construct_UFunction_UChessGameLogic_GetAttackedSquares_Statics::ChessGameLogic_eventGetAttackedSquares_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_GetAttackedSquares_Statics::Function_MetaDataParams), Z_Construct_UFunction_UChessGameLogic_GetAttackedSquares_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UChessGameLogic_GetAttackedSquares_Statics::ChessGameLogic_eventGetAttackedSquares_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UChessGameLogic_GetAttackedSquares()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UChessGameLogic_GetAttackedSquares_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UChessGameLogic::execGetAttackedSquares)
{
	P_GET_ENUM(EPieceColor,Z_Param_Color);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FChessPosition>*)Z_Param__Result=P_THIS->GetAttackedSquares(EPieceColor(Z_Param_Color));
	P_NATIVE_END;
}
// ********** End Class UChessGameLogic Function GetAttackedSquares ********************************

// ********** Begin Class UChessGameLogic Function GetBoardState ***********************************
struct Z_Construct_UFunction_UChessGameLogic_GetBoardState_Statics
{
	struct ChessGameLogic_eventGetBoardState_Parms
	{
		FChessBoardState ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Chess" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Game state accessors\n" },
#endif
		{ "ModuleRelativePath", "Core/ChessGameLogic.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Game state accessors" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UChessGameLogic_GetBoardState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000008000582, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessGameLogic_eventGetBoardState_Parms, ReturnValue), Z_Construct_UScriptStruct_FChessBoardState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) }; // 902976410
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UChessGameLogic_GetBoardState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_GetBoardState_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_GetBoardState_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UChessGameLogic_GetBoardState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UChessGameLogic, nullptr, "GetBoardState", Z_Construct_UFunction_UChessGameLogic_GetBoardState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_GetBoardState_Statics::PropPointers), sizeof(Z_Construct_UFunction_UChessGameLogic_GetBoardState_Statics::ChessGameLogic_eventGetBoardState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_GetBoardState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UChessGameLogic_GetBoardState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UChessGameLogic_GetBoardState_Statics::ChessGameLogic_eventGetBoardState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UChessGameLogic_GetBoardState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UChessGameLogic_GetBoardState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UChessGameLogic::execGetBoardState)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FChessBoardState*)Z_Param__Result=P_THIS->GetBoardState();
	P_NATIVE_END;
}
// ********** End Class UChessGameLogic Function GetBoardState *************************************

// ********** Begin Class UChessGameLogic Function GetFENString ************************************
struct Z_Construct_UFunction_UChessGameLogic_GetFENString_Statics
{
	struct ChessGameLogic_eventGetFENString_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Chess" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// FEN notation support\n" },
#endif
		{ "ModuleRelativePath", "Core/ChessGameLogic.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "FEN notation support" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UChessGameLogic_GetFENString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessGameLogic_eventGetFENString_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UChessGameLogic_GetFENString_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_GetFENString_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_GetFENString_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UChessGameLogic_GetFENString_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UChessGameLogic, nullptr, "GetFENString", Z_Construct_UFunction_UChessGameLogic_GetFENString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_GetFENString_Statics::PropPointers), sizeof(Z_Construct_UFunction_UChessGameLogic_GetFENString_Statics::ChessGameLogic_eventGetFENString_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_GetFENString_Statics::Function_MetaDataParams), Z_Construct_UFunction_UChessGameLogic_GetFENString_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UChessGameLogic_GetFENString_Statics::ChessGameLogic_eventGetFENString_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UChessGameLogic_GetFENString()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UChessGameLogic_GetFENString_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UChessGameLogic::execGetFENString)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetFENString();
	P_NATIVE_END;
}
// ********** End Class UChessGameLogic Function GetFENString **************************************

// ********** Begin Class UChessGameLogic Function GetGameState ************************************
struct Z_Construct_UFunction_UChessGameLogic_GetGameState_Statics
{
	struct ChessGameLogic_eventGetGameState_Parms
	{
		EGameState ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Chess" },
		{ "ModuleRelativePath", "Core/ChessGameLogic.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UChessGameLogic_GetGameState_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UChessGameLogic_GetGameState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessGameLogic_eventGetGameState_Parms, ReturnValue), Z_Construct_UEnum_IronChess_EGameState, METADATA_PARAMS(0, nullptr) }; // 2482667857
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UChessGameLogic_GetGameState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_GetGameState_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_GetGameState_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_GetGameState_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UChessGameLogic_GetGameState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UChessGameLogic, nullptr, "GetGameState", Z_Construct_UFunction_UChessGameLogic_GetGameState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_GetGameState_Statics::PropPointers), sizeof(Z_Construct_UFunction_UChessGameLogic_GetGameState_Statics::ChessGameLogic_eventGetGameState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_GetGameState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UChessGameLogic_GetGameState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UChessGameLogic_GetGameState_Statics::ChessGameLogic_eventGetGameState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UChessGameLogic_GetGameState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UChessGameLogic_GetGameState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UChessGameLogic::execGetGameState)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EGameState*)Z_Param__Result=P_THIS->GetGameState();
	P_NATIVE_END;
}
// ********** End Class UChessGameLogic Function GetGameState **************************************

// ********** Begin Class UChessGameLogic Function GetLegalMoves ***********************************
struct Z_Construct_UFunction_UChessGameLogic_GetLegalMoves_Statics
{
	struct ChessGameLogic_eventGetLegalMoves_Parms
	{
		EPieceColor Color;
		TArray<FChessMove> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Chess" },
		{ "ModuleRelativePath", "Core/ChessGameLogic.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_Color_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Color;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UChessGameLogic_GetLegalMoves_Statics::NewProp_Color_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UChessGameLogic_GetLegalMoves_Statics::NewProp_Color = { "Color", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessGameLogic_eventGetLegalMoves_Parms, Color), Z_Construct_UEnum_IronChess_EPieceColor, METADATA_PARAMS(0, nullptr) }; // 1636929315
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UChessGameLogic_GetLegalMoves_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FChessMove, METADATA_PARAMS(0, nullptr) }; // 1361898884
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UChessGameLogic_GetLegalMoves_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessGameLogic_eventGetLegalMoves_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 1361898884
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UChessGameLogic_GetLegalMoves_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_GetLegalMoves_Statics::NewProp_Color_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_GetLegalMoves_Statics::NewProp_Color,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_GetLegalMoves_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_GetLegalMoves_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_GetLegalMoves_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UChessGameLogic_GetLegalMoves_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UChessGameLogic, nullptr, "GetLegalMoves", Z_Construct_UFunction_UChessGameLogic_GetLegalMoves_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_GetLegalMoves_Statics::PropPointers), sizeof(Z_Construct_UFunction_UChessGameLogic_GetLegalMoves_Statics::ChessGameLogic_eventGetLegalMoves_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_GetLegalMoves_Statics::Function_MetaDataParams), Z_Construct_UFunction_UChessGameLogic_GetLegalMoves_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UChessGameLogic_GetLegalMoves_Statics::ChessGameLogic_eventGetLegalMoves_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UChessGameLogic_GetLegalMoves()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UChessGameLogic_GetLegalMoves_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UChessGameLogic::execGetLegalMoves)
{
	P_GET_ENUM(EPieceColor,Z_Param_Color);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FChessMove>*)Z_Param__Result=P_THIS->GetLegalMoves(EPieceColor(Z_Param_Color));
	P_NATIVE_END;
}
// ********** End Class UChessGameLogic Function GetLegalMoves *************************************

// ********** Begin Class UChessGameLogic Function GetLegalMovesForPiece ***************************
struct Z_Construct_UFunction_UChessGameLogic_GetLegalMovesForPiece_Statics
{
	struct ChessGameLogic_eventGetLegalMovesForPiece_Parms
	{
		FChessPosition Position;
		TArray<FChessMove> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Chess" },
		{ "ModuleRelativePath", "Core/ChessGameLogic.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Position_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Position;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UChessGameLogic_GetLegalMovesForPiece_Statics::NewProp_Position = { "Position", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessGameLogic_eventGetLegalMovesForPiece_Parms, Position), Z_Construct_UScriptStruct_FChessPosition, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Position_MetaData), NewProp_Position_MetaData) }; // 1812120650
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UChessGameLogic_GetLegalMovesForPiece_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FChessMove, METADATA_PARAMS(0, nullptr) }; // 1361898884
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UChessGameLogic_GetLegalMovesForPiece_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessGameLogic_eventGetLegalMovesForPiece_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 1361898884
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UChessGameLogic_GetLegalMovesForPiece_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_GetLegalMovesForPiece_Statics::NewProp_Position,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_GetLegalMovesForPiece_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_GetLegalMovesForPiece_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_GetLegalMovesForPiece_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UChessGameLogic_GetLegalMovesForPiece_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UChessGameLogic, nullptr, "GetLegalMovesForPiece", Z_Construct_UFunction_UChessGameLogic_GetLegalMovesForPiece_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_GetLegalMovesForPiece_Statics::PropPointers), sizeof(Z_Construct_UFunction_UChessGameLogic_GetLegalMovesForPiece_Statics::ChessGameLogic_eventGetLegalMovesForPiece_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_GetLegalMovesForPiece_Statics::Function_MetaDataParams), Z_Construct_UFunction_UChessGameLogic_GetLegalMovesForPiece_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UChessGameLogic_GetLegalMovesForPiece_Statics::ChessGameLogic_eventGetLegalMovesForPiece_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UChessGameLogic_GetLegalMovesForPiece()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UChessGameLogic_GetLegalMovesForPiece_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UChessGameLogic::execGetLegalMovesForPiece)
{
	P_GET_STRUCT_REF(FChessPosition,Z_Param_Out_Position);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FChessMove>*)Z_Param__Result=P_THIS->GetLegalMovesForPiece(Z_Param_Out_Position);
	P_NATIVE_END;
}
// ********** End Class UChessGameLogic Function GetLegalMovesForPiece *****************************

// ********** Begin Class UChessGameLogic Function GetMoveHistory **********************************
struct Z_Construct_UFunction_UChessGameLogic_GetMoveHistory_Statics
{
	struct ChessGameLogic_eventGetMoveHistory_Parms
	{
		TArray<FChessMove> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Chess" },
		{ "ModuleRelativePath", "Core/ChessGameLogic.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UChessGameLogic_GetMoveHistory_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FChessMove, METADATA_PARAMS(0, nullptr) }; // 1361898884
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UChessGameLogic_GetMoveHistory_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessGameLogic_eventGetMoveHistory_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 1361898884
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UChessGameLogic_GetMoveHistory_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_GetMoveHistory_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_GetMoveHistory_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_GetMoveHistory_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UChessGameLogic_GetMoveHistory_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UChessGameLogic, nullptr, "GetMoveHistory", Z_Construct_UFunction_UChessGameLogic_GetMoveHistory_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_GetMoveHistory_Statics::PropPointers), sizeof(Z_Construct_UFunction_UChessGameLogic_GetMoveHistory_Statics::ChessGameLogic_eventGetMoveHistory_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_GetMoveHistory_Statics::Function_MetaDataParams), Z_Construct_UFunction_UChessGameLogic_GetMoveHistory_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UChessGameLogic_GetMoveHistory_Statics::ChessGameLogic_eventGetMoveHistory_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UChessGameLogic_GetMoveHistory()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UChessGameLogic_GetMoveHistory_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UChessGameLogic::execGetMoveHistory)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FChessMove>*)Z_Param__Result=P_THIS->GetMoveHistory();
	P_NATIVE_END;
}
// ********** End Class UChessGameLogic Function GetMoveHistory ************************************

// ********** Begin Class UChessGameLogic Function GetMoveNumber ***********************************
struct Z_Construct_UFunction_UChessGameLogic_GetMoveNumber_Statics
{
	struct ChessGameLogic_eventGetMoveNumber_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Chess" },
		{ "ModuleRelativePath", "Core/ChessGameLogic.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UChessGameLogic_GetMoveNumber_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessGameLogic_eventGetMoveNumber_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UChessGameLogic_GetMoveNumber_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_GetMoveNumber_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_GetMoveNumber_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UChessGameLogic_GetMoveNumber_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UChessGameLogic, nullptr, "GetMoveNumber", Z_Construct_UFunction_UChessGameLogic_GetMoveNumber_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_GetMoveNumber_Statics::PropPointers), sizeof(Z_Construct_UFunction_UChessGameLogic_GetMoveNumber_Statics::ChessGameLogic_eventGetMoveNumber_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_GetMoveNumber_Statics::Function_MetaDataParams), Z_Construct_UFunction_UChessGameLogic_GetMoveNumber_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UChessGameLogic_GetMoveNumber_Statics::ChessGameLogic_eventGetMoveNumber_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UChessGameLogic_GetMoveNumber()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UChessGameLogic_GetMoveNumber_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UChessGameLogic::execGetMoveNumber)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetMoveNumber();
	P_NATIVE_END;
}
// ********** End Class UChessGameLogic Function GetMoveNumber *************************************

// ********** Begin Class UChessGameLogic Function GetPieceAt **************************************
struct Z_Construct_UFunction_UChessGameLogic_GetPieceAt_Statics
{
	struct ChessGameLogic_eventGetPieceAt_Parms
	{
		FChessPosition Position;
		FChessPiece ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Chess" },
		{ "ModuleRelativePath", "Core/ChessGameLogic.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Position_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Position;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UChessGameLogic_GetPieceAt_Statics::NewProp_Position = { "Position", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessGameLogic_eventGetPieceAt_Parms, Position), Z_Construct_UScriptStruct_FChessPosition, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Position_MetaData), NewProp_Position_MetaData) }; // 1812120650
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UChessGameLogic_GetPieceAt_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessGameLogic_eventGetPieceAt_Parms, ReturnValue), Z_Construct_UScriptStruct_FChessPiece, METADATA_PARAMS(0, nullptr) }; // 15703377
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UChessGameLogic_GetPieceAt_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_GetPieceAt_Statics::NewProp_Position,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_GetPieceAt_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_GetPieceAt_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UChessGameLogic_GetPieceAt_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UChessGameLogic, nullptr, "GetPieceAt", Z_Construct_UFunction_UChessGameLogic_GetPieceAt_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_GetPieceAt_Statics::PropPointers), sizeof(Z_Construct_UFunction_UChessGameLogic_GetPieceAt_Statics::ChessGameLogic_eventGetPieceAt_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_GetPieceAt_Statics::Function_MetaDataParams), Z_Construct_UFunction_UChessGameLogic_GetPieceAt_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UChessGameLogic_GetPieceAt_Statics::ChessGameLogic_eventGetPieceAt_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UChessGameLogic_GetPieceAt()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UChessGameLogic_GetPieceAt_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UChessGameLogic::execGetPieceAt)
{
	P_GET_STRUCT_REF(FChessPosition,Z_Param_Out_Position);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FChessPiece*)Z_Param__Result=P_THIS->GetPieceAt(Z_Param_Out_Position);
	P_NATIVE_END;
}
// ********** End Class UChessGameLogic Function GetPieceAt ****************************************

// ********** Begin Class UChessGameLogic Function IsCheckmate *************************************
struct Z_Construct_UFunction_UChessGameLogic_IsCheckmate_Statics
{
	struct ChessGameLogic_eventIsCheckmate_Parms
	{
		EPieceColor Color;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Chess" },
		{ "ModuleRelativePath", "Core/ChessGameLogic.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_Color_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Color;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UChessGameLogic_IsCheckmate_Statics::NewProp_Color_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UChessGameLogic_IsCheckmate_Statics::NewProp_Color = { "Color", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessGameLogic_eventIsCheckmate_Parms, Color), Z_Construct_UEnum_IronChess_EPieceColor, METADATA_PARAMS(0, nullptr) }; // 1636929315
void Z_Construct_UFunction_UChessGameLogic_IsCheckmate_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ChessGameLogic_eventIsCheckmate_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UChessGameLogic_IsCheckmate_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ChessGameLogic_eventIsCheckmate_Parms), &Z_Construct_UFunction_UChessGameLogic_IsCheckmate_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UChessGameLogic_IsCheckmate_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_IsCheckmate_Statics::NewProp_Color_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_IsCheckmate_Statics::NewProp_Color,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_IsCheckmate_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_IsCheckmate_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UChessGameLogic_IsCheckmate_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UChessGameLogic, nullptr, "IsCheckmate", Z_Construct_UFunction_UChessGameLogic_IsCheckmate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_IsCheckmate_Statics::PropPointers), sizeof(Z_Construct_UFunction_UChessGameLogic_IsCheckmate_Statics::ChessGameLogic_eventIsCheckmate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_IsCheckmate_Statics::Function_MetaDataParams), Z_Construct_UFunction_UChessGameLogic_IsCheckmate_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UChessGameLogic_IsCheckmate_Statics::ChessGameLogic_eventIsCheckmate_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UChessGameLogic_IsCheckmate()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UChessGameLogic_IsCheckmate_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UChessGameLogic::execIsCheckmate)
{
	P_GET_ENUM(EPieceColor,Z_Param_Color);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsCheckmate(EPieceColor(Z_Param_Color));
	P_NATIVE_END;
}
// ********** End Class UChessGameLogic Function IsCheckmate ***************************************

// ********** Begin Class UChessGameLogic Function IsInCheck ***************************************
struct Z_Construct_UFunction_UChessGameLogic_IsInCheck_Statics
{
	struct ChessGameLogic_eventIsInCheck_Parms
	{
		EPieceColor Color;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Chess" },
		{ "ModuleRelativePath", "Core/ChessGameLogic.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_Color_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Color;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UChessGameLogic_IsInCheck_Statics::NewProp_Color_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UChessGameLogic_IsInCheck_Statics::NewProp_Color = { "Color", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessGameLogic_eventIsInCheck_Parms, Color), Z_Construct_UEnum_IronChess_EPieceColor, METADATA_PARAMS(0, nullptr) }; // 1636929315
void Z_Construct_UFunction_UChessGameLogic_IsInCheck_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ChessGameLogic_eventIsInCheck_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UChessGameLogic_IsInCheck_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ChessGameLogic_eventIsInCheck_Parms), &Z_Construct_UFunction_UChessGameLogic_IsInCheck_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UChessGameLogic_IsInCheck_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_IsInCheck_Statics::NewProp_Color_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_IsInCheck_Statics::NewProp_Color,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_IsInCheck_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_IsInCheck_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UChessGameLogic_IsInCheck_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UChessGameLogic, nullptr, "IsInCheck", Z_Construct_UFunction_UChessGameLogic_IsInCheck_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_IsInCheck_Statics::PropPointers), sizeof(Z_Construct_UFunction_UChessGameLogic_IsInCheck_Statics::ChessGameLogic_eventIsInCheck_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_IsInCheck_Statics::Function_MetaDataParams), Z_Construct_UFunction_UChessGameLogic_IsInCheck_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UChessGameLogic_IsInCheck_Statics::ChessGameLogic_eventIsInCheck_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UChessGameLogic_IsInCheck()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UChessGameLogic_IsInCheck_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UChessGameLogic::execIsInCheck)
{
	P_GET_ENUM(EPieceColor,Z_Param_Color);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsInCheck(EPieceColor(Z_Param_Color));
	P_NATIVE_END;
}
// ********** End Class UChessGameLogic Function IsInCheck *****************************************

// ********** Begin Class UChessGameLogic Function IsStalemate *************************************
struct Z_Construct_UFunction_UChessGameLogic_IsStalemate_Statics
{
	struct ChessGameLogic_eventIsStalemate_Parms
	{
		EPieceColor Color;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Chess" },
		{ "ModuleRelativePath", "Core/ChessGameLogic.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_Color_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Color;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UChessGameLogic_IsStalemate_Statics::NewProp_Color_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UChessGameLogic_IsStalemate_Statics::NewProp_Color = { "Color", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessGameLogic_eventIsStalemate_Parms, Color), Z_Construct_UEnum_IronChess_EPieceColor, METADATA_PARAMS(0, nullptr) }; // 1636929315
void Z_Construct_UFunction_UChessGameLogic_IsStalemate_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ChessGameLogic_eventIsStalemate_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UChessGameLogic_IsStalemate_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ChessGameLogic_eventIsStalemate_Parms), &Z_Construct_UFunction_UChessGameLogic_IsStalemate_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UChessGameLogic_IsStalemate_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_IsStalemate_Statics::NewProp_Color_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_IsStalemate_Statics::NewProp_Color,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_IsStalemate_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_IsStalemate_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UChessGameLogic_IsStalemate_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UChessGameLogic, nullptr, "IsStalemate", Z_Construct_UFunction_UChessGameLogic_IsStalemate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_IsStalemate_Statics::PropPointers), sizeof(Z_Construct_UFunction_UChessGameLogic_IsStalemate_Statics::ChessGameLogic_eventIsStalemate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_IsStalemate_Statics::Function_MetaDataParams), Z_Construct_UFunction_UChessGameLogic_IsStalemate_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UChessGameLogic_IsStalemate_Statics::ChessGameLogic_eventIsStalemate_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UChessGameLogic_IsStalemate()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UChessGameLogic_IsStalemate_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UChessGameLogic::execIsStalemate)
{
	P_GET_ENUM(EPieceColor,Z_Param_Color);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsStalemate(EPieceColor(Z_Param_Color));
	P_NATIVE_END;
}
// ********** End Class UChessGameLogic Function IsStalemate ***************************************

// ********** Begin Class UChessGameLogic Function IsValidMove *************************************
struct Z_Construct_UFunction_UChessGameLogic_IsValidMove_Statics
{
	struct ChessGameLogic_eventIsValidMove_Parms
	{
		FChessMove Move;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Chess" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Core game functions\n" },
#endif
		{ "ModuleRelativePath", "Core/ChessGameLogic.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Core game functions" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Move_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Move;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UChessGameLogic_IsValidMove_Statics::NewProp_Move = { "Move", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessGameLogic_eventIsValidMove_Parms, Move), Z_Construct_UScriptStruct_FChessMove, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Move_MetaData), NewProp_Move_MetaData) }; // 1361898884
void Z_Construct_UFunction_UChessGameLogic_IsValidMove_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ChessGameLogic_eventIsValidMove_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UChessGameLogic_IsValidMove_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ChessGameLogic_eventIsValidMove_Parms), &Z_Construct_UFunction_UChessGameLogic_IsValidMove_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UChessGameLogic_IsValidMove_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_IsValidMove_Statics::NewProp_Move,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_IsValidMove_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_IsValidMove_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UChessGameLogic_IsValidMove_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UChessGameLogic, nullptr, "IsValidMove", Z_Construct_UFunction_UChessGameLogic_IsValidMove_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_IsValidMove_Statics::PropPointers), sizeof(Z_Construct_UFunction_UChessGameLogic_IsValidMove_Statics::ChessGameLogic_eventIsValidMove_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_IsValidMove_Statics::Function_MetaDataParams), Z_Construct_UFunction_UChessGameLogic_IsValidMove_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UChessGameLogic_IsValidMove_Statics::ChessGameLogic_eventIsValidMove_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UChessGameLogic_IsValidMove()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UChessGameLogic_IsValidMove_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UChessGameLogic::execIsValidMove)
{
	P_GET_STRUCT_REF(FChessMove,Z_Param_Out_Move);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsValidMove(Z_Param_Out_Move);
	P_NATIVE_END;
}
// ********** End Class UChessGameLogic Function IsValidMove ***************************************

// ********** Begin Class UChessGameLogic Function LoadFromFEN *************************************
struct Z_Construct_UFunction_UChessGameLogic_LoadFromFEN_Statics
{
	struct ChessGameLogic_eventLoadFromFEN_Parms
	{
		FString FENString;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Chess" },
		{ "ModuleRelativePath", "Core/ChessGameLogic.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FENString_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_FENString;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UChessGameLogic_LoadFromFEN_Statics::NewProp_FENString = { "FENString", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessGameLogic_eventLoadFromFEN_Parms, FENString), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FENString_MetaData), NewProp_FENString_MetaData) };
void Z_Construct_UFunction_UChessGameLogic_LoadFromFEN_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ChessGameLogic_eventLoadFromFEN_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UChessGameLogic_LoadFromFEN_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ChessGameLogic_eventLoadFromFEN_Parms), &Z_Construct_UFunction_UChessGameLogic_LoadFromFEN_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UChessGameLogic_LoadFromFEN_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_LoadFromFEN_Statics::NewProp_FENString,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_LoadFromFEN_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_LoadFromFEN_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UChessGameLogic_LoadFromFEN_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UChessGameLogic, nullptr, "LoadFromFEN", Z_Construct_UFunction_UChessGameLogic_LoadFromFEN_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_LoadFromFEN_Statics::PropPointers), sizeof(Z_Construct_UFunction_UChessGameLogic_LoadFromFEN_Statics::ChessGameLogic_eventLoadFromFEN_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_LoadFromFEN_Statics::Function_MetaDataParams), Z_Construct_UFunction_UChessGameLogic_LoadFromFEN_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UChessGameLogic_LoadFromFEN_Statics::ChessGameLogic_eventLoadFromFEN_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UChessGameLogic_LoadFromFEN()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UChessGameLogic_LoadFromFEN_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UChessGameLogic::execLoadFromFEN)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_FENString);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->LoadFromFEN(Z_Param_FENString);
	P_NATIVE_END;
}
// ********** End Class UChessGameLogic Function LoadFromFEN ***************************************

// ********** Begin Class UChessGameLogic Function MakeMove ****************************************
struct Z_Construct_UFunction_UChessGameLogic_MakeMove_Statics
{
	struct ChessGameLogic_eventMakeMove_Parms
	{
		FChessMove Move;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Chess" },
		{ "ModuleRelativePath", "Core/ChessGameLogic.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Move_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Move;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UChessGameLogic_MakeMove_Statics::NewProp_Move = { "Move", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessGameLogic_eventMakeMove_Parms, Move), Z_Construct_UScriptStruct_FChessMove, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Move_MetaData), NewProp_Move_MetaData) }; // 1361898884
void Z_Construct_UFunction_UChessGameLogic_MakeMove_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ChessGameLogic_eventMakeMove_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UChessGameLogic_MakeMove_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ChessGameLogic_eventMakeMove_Parms), &Z_Construct_UFunction_UChessGameLogic_MakeMove_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UChessGameLogic_MakeMove_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_MakeMove_Statics::NewProp_Move,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessGameLogic_MakeMove_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_MakeMove_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UChessGameLogic_MakeMove_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UChessGameLogic, nullptr, "MakeMove", Z_Construct_UFunction_UChessGameLogic_MakeMove_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_MakeMove_Statics::PropPointers), sizeof(Z_Construct_UFunction_UChessGameLogic_MakeMove_Statics::ChessGameLogic_eventMakeMove_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_MakeMove_Statics::Function_MetaDataParams), Z_Construct_UFunction_UChessGameLogic_MakeMove_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UChessGameLogic_MakeMove_Statics::ChessGameLogic_eventMakeMove_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UChessGameLogic_MakeMove()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UChessGameLogic_MakeMove_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UChessGameLogic::execMakeMove)
{
	P_GET_STRUCT_REF(FChessMove,Z_Param_Out_Move);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->MakeMove(Z_Param_Out_Move);
	P_NATIVE_END;
}
// ********** End Class UChessGameLogic Function MakeMove ******************************************

// ********** Begin Class UChessGameLogic Function ResetGame ***************************************
struct Z_Construct_UFunction_UChessGameLogic_ResetGame_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Chess" },
		{ "ModuleRelativePath", "Core/ChessGameLogic.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UChessGameLogic_ResetGame_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UChessGameLogic, nullptr, "ResetGame", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessGameLogic_ResetGame_Statics::Function_MetaDataParams), Z_Construct_UFunction_UChessGameLogic_ResetGame_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UChessGameLogic_ResetGame()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UChessGameLogic_ResetGame_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UChessGameLogic::execResetGame)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ResetGame();
	P_NATIVE_END;
}
// ********** End Class UChessGameLogic Function ResetGame *****************************************

// ********** Begin Class UChessGameLogic **********************************************************
void UChessGameLogic::StaticRegisterNativesUChessGameLogic()
{
	UClass* Class = UChessGameLogic::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "CanCastle", &UChessGameLogic::execCanCastle },
		{ "FindKing", &UChessGameLogic::execFindKing },
		{ "GetActivePlayer", &UChessGameLogic::execGetActivePlayer },
		{ "GetAttackedSquares", &UChessGameLogic::execGetAttackedSquares },
		{ "GetBoardState", &UChessGameLogic::execGetBoardState },
		{ "GetFENString", &UChessGameLogic::execGetFENString },
		{ "GetGameState", &UChessGameLogic::execGetGameState },
		{ "GetLegalMoves", &UChessGameLogic::execGetLegalMoves },
		{ "GetLegalMovesForPiece", &UChessGameLogic::execGetLegalMovesForPiece },
		{ "GetMoveHistory", &UChessGameLogic::execGetMoveHistory },
		{ "GetMoveNumber", &UChessGameLogic::execGetMoveNumber },
		{ "GetPieceAt", &UChessGameLogic::execGetPieceAt },
		{ "IsCheckmate", &UChessGameLogic::execIsCheckmate },
		{ "IsInCheck", &UChessGameLogic::execIsInCheck },
		{ "IsStalemate", &UChessGameLogic::execIsStalemate },
		{ "IsValidMove", &UChessGameLogic::execIsValidMove },
		{ "LoadFromFEN", &UChessGameLogic::execLoadFromFEN },
		{ "MakeMove", &UChessGameLogic::execMakeMove },
		{ "ResetGame", &UChessGameLogic::execResetGame },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UChessGameLogic;
UClass* UChessGameLogic::GetPrivateStaticClass()
{
	using TClass = UChessGameLogic;
	if (!Z_Registration_Info_UClass_UChessGameLogic.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ChessGameLogic"),
			Z_Registration_Info_UClass_UChessGameLogic.InnerSingleton,
			StaticRegisterNativesUChessGameLogic,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UChessGameLogic.InnerSingleton;
}
UClass* Z_Construct_UClass_UChessGameLogic_NoRegister()
{
	return UChessGameLogic::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UChessGameLogic_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Core chess game logic implementation\n * Handles move validation, game state management, and rule enforcement\n */" },
#endif
		{ "IncludePath", "Core/ChessGameLogic.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Core/ChessGameLogic.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Core chess game logic implementation\nHandles move validation, game state management, and rule enforcement" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnMoveMade_MetaData[] = {
		{ "ModuleRelativePath", "Core/ChessGameLogic.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnGameStateChanged_MetaData[] = {
		{ "ModuleRelativePath", "Core/ChessGameLogic.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCheck_MetaData[] = {
		{ "ModuleRelativePath", "Core/ChessGameLogic.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BoardState_MetaData[] = {
		{ "Category", "Chess" },
		{ "ModuleRelativePath", "Core/ChessGameLogic.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveHistory_MetaData[] = {
		{ "Category", "Chess" },
		{ "ModuleRelativePath", "Core/ChessGameLogic.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnMoveMade;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnGameStateChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCheck;
	static const UECodeGen_Private::FStructPropertyParams NewProp_BoardState;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MoveHistory_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_MoveHistory;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UChessGameLogic_CanCastle, "CanCastle" }, // 3109340776
		{ &Z_Construct_UFunction_UChessGameLogic_FindKing, "FindKing" }, // 3498847808
		{ &Z_Construct_UFunction_UChessGameLogic_GetActivePlayer, "GetActivePlayer" }, // 2788545706
		{ &Z_Construct_UFunction_UChessGameLogic_GetAttackedSquares, "GetAttackedSquares" }, // 1323537825
		{ &Z_Construct_UFunction_UChessGameLogic_GetBoardState, "GetBoardState" }, // 324656590
		{ &Z_Construct_UFunction_UChessGameLogic_GetFENString, "GetFENString" }, // 2565432071
		{ &Z_Construct_UFunction_UChessGameLogic_GetGameState, "GetGameState" }, // 3444353854
		{ &Z_Construct_UFunction_UChessGameLogic_GetLegalMoves, "GetLegalMoves" }, // 4087224731
		{ &Z_Construct_UFunction_UChessGameLogic_GetLegalMovesForPiece, "GetLegalMovesForPiece" }, // 3947230191
		{ &Z_Construct_UFunction_UChessGameLogic_GetMoveHistory, "GetMoveHistory" }, // 1933687933
		{ &Z_Construct_UFunction_UChessGameLogic_GetMoveNumber, "GetMoveNumber" }, // 3885521946
		{ &Z_Construct_UFunction_UChessGameLogic_GetPieceAt, "GetPieceAt" }, // 4241236112
		{ &Z_Construct_UFunction_UChessGameLogic_IsCheckmate, "IsCheckmate" }, // 1322449122
		{ &Z_Construct_UFunction_UChessGameLogic_IsInCheck, "IsInCheck" }, // 2828443745
		{ &Z_Construct_UFunction_UChessGameLogic_IsStalemate, "IsStalemate" }, // 2943488399
		{ &Z_Construct_UFunction_UChessGameLogic_IsValidMove, "IsValidMove" }, // 2455024235
		{ &Z_Construct_UFunction_UChessGameLogic_LoadFromFEN, "LoadFromFEN" }, // 2803622421
		{ &Z_Construct_UFunction_UChessGameLogic_MakeMove, "MakeMove" }, // 1282291791
		{ &Z_Construct_UDelegateFunction_UChessGameLogic_OnCheck__DelegateSignature, "OnCheck__DelegateSignature" }, // 2260239443
		{ &Z_Construct_UDelegateFunction_UChessGameLogic_OnGameStateChanged__DelegateSignature, "OnGameStateChanged__DelegateSignature" }, // 7011284
		{ &Z_Construct_UDelegateFunction_UChessGameLogic_OnMoveMade__DelegateSignature, "OnMoveMade__DelegateSignature" }, // 719037048
		{ &Z_Construct_UFunction_UChessGameLogic_ResetGame, "ResetGame" }, // 571885778
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UChessGameLogic>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UChessGameLogic_Statics::NewProp_OnMoveMade = { "OnMoveMade", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UChessGameLogic, OnMoveMade), Z_Construct_UDelegateFunction_UChessGameLogic_OnMoveMade__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnMoveMade_MetaData), NewProp_OnMoveMade_MetaData) }; // 719037048
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UChessGameLogic_Statics::NewProp_OnGameStateChanged = { "OnGameStateChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UChessGameLogic, OnGameStateChanged), Z_Construct_UDelegateFunction_UChessGameLogic_OnGameStateChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnGameStateChanged_MetaData), NewProp_OnGameStateChanged_MetaData) }; // 7011284
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UChessGameLogic_Statics::NewProp_OnCheck = { "OnCheck", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UChessGameLogic, OnCheck), Z_Construct_UDelegateFunction_UChessGameLogic_OnCheck__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCheck_MetaData), NewProp_OnCheck_MetaData) }; // 2260239443
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UChessGameLogic_Statics::NewProp_BoardState = { "BoardState", nullptr, (EPropertyFlags)0x0020080000020015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UChessGameLogic, BoardState), Z_Construct_UScriptStruct_FChessBoardState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BoardState_MetaData), NewProp_BoardState_MetaData) }; // 902976410
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UChessGameLogic_Statics::NewProp_MoveHistory_Inner = { "MoveHistory", nullptr, (EPropertyFlags)0x0000000000020000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FChessMove, METADATA_PARAMS(0, nullptr) }; // 1361898884
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UChessGameLogic_Statics::NewProp_MoveHistory = { "MoveHistory", nullptr, (EPropertyFlags)0x0020080000020015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UChessGameLogic, MoveHistory), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveHistory_MetaData), NewProp_MoveHistory_MetaData) }; // 1361898884
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UChessGameLogic_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UChessGameLogic_Statics::NewProp_OnMoveMade,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UChessGameLogic_Statics::NewProp_OnGameStateChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UChessGameLogic_Statics::NewProp_OnCheck,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UChessGameLogic_Statics::NewProp_BoardState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UChessGameLogic_Statics::NewProp_MoveHistory_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UChessGameLogic_Statics::NewProp_MoveHistory,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UChessGameLogic_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UChessGameLogic_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_IronChess,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UChessGameLogic_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UChessGameLogic_Statics::ClassParams = {
	&UChessGameLogic::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UChessGameLogic_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UChessGameLogic_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UChessGameLogic_Statics::Class_MetaDataParams), Z_Construct_UClass_UChessGameLogic_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UChessGameLogic()
{
	if (!Z_Registration_Info_UClass_UChessGameLogic.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UChessGameLogic.OuterSingleton, Z_Construct_UClass_UChessGameLogic_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UChessGameLogic.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UChessGameLogic);
UChessGameLogic::~UChessGameLogic() {}
// ********** End Class UChessGameLogic ************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Core_ChessGameLogic_h__Script_IronChess_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UChessGameLogic, UChessGameLogic::StaticClass, TEXT("UChessGameLogic"), &Z_Registration_Info_UClass_UChessGameLogic, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UChessGameLogic), 1029908993U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Core_ChessGameLogic_h__Script_IronChess_401954281(TEXT("/Script/IronChess"),
	Z_CompiledInDeferFile_FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Core_ChessGameLogic_h__Script_IronChess_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Core_ChessGameLogic_h__Script_IronChess_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
