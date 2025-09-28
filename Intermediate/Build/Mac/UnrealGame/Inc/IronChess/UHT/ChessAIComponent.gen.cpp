// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ChessAIComponent.h"
#include "ChessTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeChessAIComponent() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
IRONCHESS_API UClass* Z_Construct_UClass_UChessAIComponent();
IRONCHESS_API UClass* Z_Construct_UClass_UChessAIComponent_NoRegister();
IRONCHESS_API UClass* Z_Construct_UClass_UChessGameLogic_NoRegister();
IRONCHESS_API UEnum* Z_Construct_UEnum_IronChess_EAIDifficulty();
IRONCHESS_API UEnum* Z_Construct_UEnum_IronChess_EPieceColor();
IRONCHESS_API UFunction* Z_Construct_UDelegateFunction_UChessAIComponent_OnAIMoveCalculated__DelegateSignature();
IRONCHESS_API UFunction* Z_Construct_UDelegateFunction_UChessAIComponent_OnAIThinking__DelegateSignature();
IRONCHESS_API UScriptStruct* Z_Construct_UScriptStruct_FAIPersonality();
IRONCHESS_API UScriptStruct* Z_Construct_UScriptStruct_FChessMove();
IRONCHESS_API UScriptStruct* Z_Construct_UScriptStruct_FMoveEvaluation();
UPackage* Z_Construct_UPackage__Script_IronChess();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EAIDifficulty *************************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EAIDifficulty;
static UEnum* EAIDifficulty_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EAIDifficulty.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EAIDifficulty.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_IronChess_EAIDifficulty, (UObject*)Z_Construct_UPackage__Script_IronChess(), TEXT("EAIDifficulty"));
	}
	return Z_Registration_Info_UEnum_EAIDifficulty.OuterSingleton;
}
template<> IRONCHESS_API UEnum* StaticEnum<EAIDifficulty>()
{
	return EAIDifficulty_StaticEnum();
}
struct Z_Construct_UEnum_IronChess_EAIDifficulty_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Advanced.Comment", "// Minimax depth 3-4\n" },
		{ "Advanced.Name", "EAIDifficulty::Advanced" },
		{ "Advanced.ToolTip", "Minimax depth 3-4" },
		{ "Beginner.Comment", "// Default/uninitialized value\n" },
		{ "Beginner.Name", "EAIDifficulty::Beginner" },
		{ "Beginner.ToolTip", "Default/uninitialized value" },
		{ "BlueprintType", "true" },
		{ "Casual.Comment", "// Simple evaluation\n" },
		{ "Casual.Name", "EAIDifficulty::Casual" },
		{ "Casual.ToolTip", "Simple evaluation" },
		{ "Expert.Comment", "// Opening book + basic tactics\n" },
		{ "Expert.Name", "EAIDifficulty::Expert" },
		{ "Expert.ToolTip", "Opening book + basic tactics" },
		{ "Grandmaster.Comment", "// Advanced evaluation + patterns\n" },
		{ "Grandmaster.Name", "EAIDifficulty::Grandmaster" },
		{ "Grandmaster.ToolTip", "Advanced evaluation + patterns" },
		{ "Intermediate.Comment", "// Minimax depth 2-3\n" },
		{ "Intermediate.Name", "EAIDifficulty::Intermediate" },
		{ "Intermediate.ToolTip", "Minimax depth 2-3" },
		{ "Master.Comment", "// Endgame knowledge + tactics\n" },
		{ "Master.Name", "EAIDifficulty::Master" },
		{ "Master.ToolTip", "Endgame knowledge + tactics" },
		{ "ModuleRelativePath", "AI/ChessAIComponent.h" },
		{ "None.Name", "EAIDifficulty::None" },
		{ "Novice.Comment", "// Random moves with basic patterns\n" },
		{ "Novice.Name", "EAIDifficulty::Novice" },
		{ "Novice.ToolTip", "Random moves with basic patterns" },
		{ "Superhuman.Comment", "// Limited Stockfish strength\n" },
		{ "Superhuman.Name", "EAIDifficulty::Superhuman" },
		{ "Superhuman.ToolTip", "Limited Stockfish strength" },
		{ "WorldClass.Comment", "// Deep analysis + strategic play\n" },
		{ "WorldClass.Name", "EAIDifficulty::WorldClass" },
		{ "WorldClass.ToolTip", "Deep analysis + strategic play" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EAIDifficulty::None", (int64)EAIDifficulty::None },
		{ "EAIDifficulty::Beginner", (int64)EAIDifficulty::Beginner },
		{ "EAIDifficulty::Novice", (int64)EAIDifficulty::Novice },
		{ "EAIDifficulty::Casual", (int64)EAIDifficulty::Casual },
		{ "EAIDifficulty::Intermediate", (int64)EAIDifficulty::Intermediate },
		{ "EAIDifficulty::Advanced", (int64)EAIDifficulty::Advanced },
		{ "EAIDifficulty::Expert", (int64)EAIDifficulty::Expert },
		{ "EAIDifficulty::Master", (int64)EAIDifficulty::Master },
		{ "EAIDifficulty::Grandmaster", (int64)EAIDifficulty::Grandmaster },
		{ "EAIDifficulty::WorldClass", (int64)EAIDifficulty::WorldClass },
		{ "EAIDifficulty::Superhuman", (int64)EAIDifficulty::Superhuman },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_IronChess_EAIDifficulty_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_IronChess,
	nullptr,
	"EAIDifficulty",
	"EAIDifficulty",
	Z_Construct_UEnum_IronChess_EAIDifficulty_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_IronChess_EAIDifficulty_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_IronChess_EAIDifficulty_Statics::Enum_MetaDataParams), Z_Construct_UEnum_IronChess_EAIDifficulty_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_IronChess_EAIDifficulty()
{
	if (!Z_Registration_Info_UEnum_EAIDifficulty.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EAIDifficulty.InnerSingleton, Z_Construct_UEnum_IronChess_EAIDifficulty_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EAIDifficulty.InnerSingleton;
}
// ********** End Enum EAIDifficulty ***************************************************************

// ********** Begin ScriptStruct FAIPersonality ****************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FAIPersonality;
class UScriptStruct* FAIPersonality::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FAIPersonality.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FAIPersonality.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAIPersonality, (UObject*)Z_Construct_UPackage__Script_IronChess(), TEXT("AIPersonality"));
	}
	return Z_Registration_Info_UScriptStruct_FAIPersonality.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FAIPersonality_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "AI/ChessAIComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Aggression_MetaData[] = {
		{ "Category", "AI Personality" },
		{ "ModuleRelativePath", "AI/ChessAIComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RiskTaking_MetaData[] = {
		{ "Category", "AI Personality" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// 0.0 = Defensive, 1.0 = Aggressive\n" },
#endif
		{ "ModuleRelativePath", "AI/ChessAIComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "0.0 = Defensive, 1.0 = Aggressive" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaterialValue_MetaData[] = {
		{ "Category", "AI Personality" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// 0.0 = Safe, 1.0 = Risky\n" },
#endif
		{ "ModuleRelativePath", "AI/ChessAIComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "0.0 = Safe, 1.0 = Risky" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_KingSafety_MetaData[] = {
		{ "Category", "AI Personality" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// How much AI values material vs position\n" },
#endif
		{ "ModuleRelativePath", "AI/ChessAIComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "How much AI values material vs position" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CenterControl_MetaData[] = {
		{ "Category", "AI Personality" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Priority for king safety\n" },
#endif
		{ "ModuleRelativePath", "AI/ChessAIComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Priority for king safety" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Aggression;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RiskTaking;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaterialValue;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_KingSafety;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CenterControl;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAIPersonality>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAIPersonality_Statics::NewProp_Aggression = { "Aggression", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAIPersonality, Aggression), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Aggression_MetaData), NewProp_Aggression_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAIPersonality_Statics::NewProp_RiskTaking = { "RiskTaking", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAIPersonality, RiskTaking), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RiskTaking_MetaData), NewProp_RiskTaking_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAIPersonality_Statics::NewProp_MaterialValue = { "MaterialValue", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAIPersonality, MaterialValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaterialValue_MetaData), NewProp_MaterialValue_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAIPersonality_Statics::NewProp_KingSafety = { "KingSafety", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAIPersonality, KingSafety), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_KingSafety_MetaData), NewProp_KingSafety_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAIPersonality_Statics::NewProp_CenterControl = { "CenterControl", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAIPersonality, CenterControl), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CenterControl_MetaData), NewProp_CenterControl_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAIPersonality_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAIPersonality_Statics::NewProp_Aggression,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAIPersonality_Statics::NewProp_RiskTaking,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAIPersonality_Statics::NewProp_MaterialValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAIPersonality_Statics::NewProp_KingSafety,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAIPersonality_Statics::NewProp_CenterControl,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAIPersonality_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAIPersonality_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_IronChess,
	nullptr,
	&NewStructOps,
	"AIPersonality",
	Z_Construct_UScriptStruct_FAIPersonality_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAIPersonality_Statics::PropPointers),
	sizeof(FAIPersonality),
	alignof(FAIPersonality),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAIPersonality_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAIPersonality_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FAIPersonality()
{
	if (!Z_Registration_Info_UScriptStruct_FAIPersonality.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FAIPersonality.InnerSingleton, Z_Construct_UScriptStruct_FAIPersonality_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FAIPersonality.InnerSingleton;
}
// ********** End ScriptStruct FAIPersonality ******************************************************

// ********** Begin ScriptStruct FMoveEvaluation ***************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FMoveEvaluation;
class UScriptStruct* FMoveEvaluation::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FMoveEvaluation.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FMoveEvaluation.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FMoveEvaluation, (UObject*)Z_Construct_UPackage__Script_IronChess(), TEXT("MoveEvaluation"));
	}
	return Z_Registration_Info_UScriptStruct_FMoveEvaluation.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FMoveEvaluation_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "AI/ChessAIComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Move_MetaData[] = {
		{ "Category", "MoveEvaluation" },
		{ "ModuleRelativePath", "AI/ChessAIComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Score_MetaData[] = {
		{ "Category", "MoveEvaluation" },
		{ "ModuleRelativePath", "AI/ChessAIComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Depth_MetaData[] = {
		{ "Category", "MoveEvaluation" },
		{ "ModuleRelativePath", "AI/ChessAIComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PrincipalVariation_MetaData[] = {
		{ "Category", "MoveEvaluation" },
		{ "ModuleRelativePath", "AI/ChessAIComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Move;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Score;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Depth;
	static const UECodeGen_Private::FStrPropertyParams NewProp_PrincipalVariation;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMoveEvaluation>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMoveEvaluation_Statics::NewProp_Move = { "Move", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMoveEvaluation, Move), Z_Construct_UScriptStruct_FChessMove, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Move_MetaData), NewProp_Move_MetaData) }; // 1361898884
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FMoveEvaluation_Statics::NewProp_Score = { "Score", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMoveEvaluation, Score), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Score_MetaData), NewProp_Score_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FMoveEvaluation_Statics::NewProp_Depth = { "Depth", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMoveEvaluation, Depth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Depth_MetaData), NewProp_Depth_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FMoveEvaluation_Statics::NewProp_PrincipalVariation = { "PrincipalVariation", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMoveEvaluation, PrincipalVariation), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PrincipalVariation_MetaData), NewProp_PrincipalVariation_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMoveEvaluation_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMoveEvaluation_Statics::NewProp_Move,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMoveEvaluation_Statics::NewProp_Score,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMoveEvaluation_Statics::NewProp_Depth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMoveEvaluation_Statics::NewProp_PrincipalVariation,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMoveEvaluation_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMoveEvaluation_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_IronChess,
	nullptr,
	&NewStructOps,
	"MoveEvaluation",
	Z_Construct_UScriptStruct_FMoveEvaluation_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMoveEvaluation_Statics::PropPointers),
	sizeof(FMoveEvaluation),
	alignof(FMoveEvaluation),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMoveEvaluation_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FMoveEvaluation_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FMoveEvaluation()
{
	if (!Z_Registration_Info_UScriptStruct_FMoveEvaluation.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FMoveEvaluation.InnerSingleton, Z_Construct_UScriptStruct_FMoveEvaluation_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FMoveEvaluation.InnerSingleton;
}
// ********** End ScriptStruct FMoveEvaluation *****************************************************

// ********** Begin Delegate FOnAIMoveCalculated ***************************************************
struct Z_Construct_UDelegateFunction_UChessAIComponent_OnAIMoveCalculated__DelegateSignature_Statics
{
	struct ChessAIComponent_eventOnAIMoveCalculated_Parms
	{
		FChessMove Move;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Events\n" },
#endif
		{ "ModuleRelativePath", "AI/ChessAIComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Events" },
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
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_UChessAIComponent_OnAIMoveCalculated__DelegateSignature_Statics::NewProp_Move = { "Move", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessAIComponent_eventOnAIMoveCalculated_Parms, Move), Z_Construct_UScriptStruct_FChessMove, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Move_MetaData), NewProp_Move_MetaData) }; // 1361898884
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UChessAIComponent_OnAIMoveCalculated__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UChessAIComponent_OnAIMoveCalculated__DelegateSignature_Statics::NewProp_Move,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UChessAIComponent_OnAIMoveCalculated__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_UChessAIComponent_OnAIMoveCalculated__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UChessAIComponent, nullptr, "OnAIMoveCalculated__DelegateSignature", Z_Construct_UDelegateFunction_UChessAIComponent_OnAIMoveCalculated__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UChessAIComponent_OnAIMoveCalculated__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UChessAIComponent_OnAIMoveCalculated__DelegateSignature_Statics::ChessAIComponent_eventOnAIMoveCalculated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UChessAIComponent_OnAIMoveCalculated__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UChessAIComponent_OnAIMoveCalculated__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_UChessAIComponent_OnAIMoveCalculated__DelegateSignature_Statics::ChessAIComponent_eventOnAIMoveCalculated_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_UChessAIComponent_OnAIMoveCalculated__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UChessAIComponent_OnAIMoveCalculated__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void UChessAIComponent::FOnAIMoveCalculated_DelegateWrapper(const FMulticastScriptDelegate& OnAIMoveCalculated, FChessMove const& Move)
{
	struct ChessAIComponent_eventOnAIMoveCalculated_Parms
	{
		FChessMove Move;
	};
	ChessAIComponent_eventOnAIMoveCalculated_Parms Parms;
	Parms.Move=Move;
	OnAIMoveCalculated.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnAIMoveCalculated *****************************************************

// ********** Begin Delegate FOnAIThinking *********************************************************
struct Z_Construct_UDelegateFunction_UChessAIComponent_OnAIThinking__DelegateSignature_Statics
{
	struct ChessAIComponent_eventOnAIThinking_Parms
	{
		float Progress;
		FString CurrentLine;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "AI/ChessAIComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentLine_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Progress;
	static const UECodeGen_Private::FStrPropertyParams NewProp_CurrentLine;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_UChessAIComponent_OnAIThinking__DelegateSignature_Statics::NewProp_Progress = { "Progress", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessAIComponent_eventOnAIThinking_Parms, Progress), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_UChessAIComponent_OnAIThinking__DelegateSignature_Statics::NewProp_CurrentLine = { "CurrentLine", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessAIComponent_eventOnAIThinking_Parms, CurrentLine), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentLine_MetaData), NewProp_CurrentLine_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UChessAIComponent_OnAIThinking__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UChessAIComponent_OnAIThinking__DelegateSignature_Statics::NewProp_Progress,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UChessAIComponent_OnAIThinking__DelegateSignature_Statics::NewProp_CurrentLine,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UChessAIComponent_OnAIThinking__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_UChessAIComponent_OnAIThinking__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UChessAIComponent, nullptr, "OnAIThinking__DelegateSignature", Z_Construct_UDelegateFunction_UChessAIComponent_OnAIThinking__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UChessAIComponent_OnAIThinking__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UChessAIComponent_OnAIThinking__DelegateSignature_Statics::ChessAIComponent_eventOnAIThinking_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UChessAIComponent_OnAIThinking__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UChessAIComponent_OnAIThinking__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_UChessAIComponent_OnAIThinking__DelegateSignature_Statics::ChessAIComponent_eventOnAIThinking_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_UChessAIComponent_OnAIThinking__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UChessAIComponent_OnAIThinking__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void UChessAIComponent::FOnAIThinking_DelegateWrapper(const FMulticastScriptDelegate& OnAIThinking, float Progress, const FString& CurrentLine)
{
	struct ChessAIComponent_eventOnAIThinking_Parms
	{
		float Progress;
		FString CurrentLine;
	};
	ChessAIComponent_eventOnAIThinking_Parms Parms;
	Parms.Progress=Progress;
	Parms.CurrentLine=CurrentLine;
	OnAIThinking.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnAIThinking ***********************************************************

// ********** Begin Class UChessAIComponent Function AnalyzePosition *******************************
struct Z_Construct_UFunction_UChessAIComponent_AnalyzePosition_Statics
{
	struct ChessAIComponent_eventAnalyzePosition_Parms
	{
		UChessGameLogic* GameLogic;
		int32 MaxDepth;
		TArray<FMoveEvaluation> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Chess AI" },
		{ "CPP_Default_MaxDepth", "5" },
		{ "ModuleRelativePath", "AI/ChessAIComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_GameLogic;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxDepth;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UChessAIComponent_AnalyzePosition_Statics::NewProp_GameLogic = { "GameLogic", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessAIComponent_eventAnalyzePosition_Parms, GameLogic), Z_Construct_UClass_UChessGameLogic_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UChessAIComponent_AnalyzePosition_Statics::NewProp_MaxDepth = { "MaxDepth", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessAIComponent_eventAnalyzePosition_Parms, MaxDepth), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UChessAIComponent_AnalyzePosition_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FMoveEvaluation, METADATA_PARAMS(0, nullptr) }; // 3428123318
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UChessAIComponent_AnalyzePosition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessAIComponent_eventAnalyzePosition_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 3428123318
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UChessAIComponent_AnalyzePosition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessAIComponent_AnalyzePosition_Statics::NewProp_GameLogic,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessAIComponent_AnalyzePosition_Statics::NewProp_MaxDepth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessAIComponent_AnalyzePosition_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessAIComponent_AnalyzePosition_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessAIComponent_AnalyzePosition_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UChessAIComponent_AnalyzePosition_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UChessAIComponent, nullptr, "AnalyzePosition", Z_Construct_UFunction_UChessAIComponent_AnalyzePosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UChessAIComponent_AnalyzePosition_Statics::PropPointers), sizeof(Z_Construct_UFunction_UChessAIComponent_AnalyzePosition_Statics::ChessAIComponent_eventAnalyzePosition_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessAIComponent_AnalyzePosition_Statics::Function_MetaDataParams), Z_Construct_UFunction_UChessAIComponent_AnalyzePosition_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UChessAIComponent_AnalyzePosition_Statics::ChessAIComponent_eventAnalyzePosition_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UChessAIComponent_AnalyzePosition()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UChessAIComponent_AnalyzePosition_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UChessAIComponent::execAnalyzePosition)
{
	P_GET_OBJECT(UChessGameLogic,Z_Param_GameLogic);
	P_GET_PROPERTY(FIntProperty,Z_Param_MaxDepth);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FMoveEvaluation>*)Z_Param__Result=P_THIS->AnalyzePosition(Z_Param_GameLogic,Z_Param_MaxDepth);
	P_NATIVE_END;
}
// ********** End Class UChessAIComponent Function AnalyzePosition *********************************

// ********** Begin Class UChessAIComponent Function EvaluatePosition ******************************
struct Z_Construct_UFunction_UChessAIComponent_EvaluatePosition_Statics
{
	struct ChessAIComponent_eventEvaluatePosition_Parms
	{
		UChessGameLogic* GameLogic;
		EPieceColor Perspective;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Chess AI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Analysis Functions\n" },
#endif
		{ "ModuleRelativePath", "AI/ChessAIComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Analysis Functions" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_GameLogic;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Perspective_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Perspective;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UChessAIComponent_EvaluatePosition_Statics::NewProp_GameLogic = { "GameLogic", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessAIComponent_eventEvaluatePosition_Parms, GameLogic), Z_Construct_UClass_UChessGameLogic_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UChessAIComponent_EvaluatePosition_Statics::NewProp_Perspective_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UChessAIComponent_EvaluatePosition_Statics::NewProp_Perspective = { "Perspective", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessAIComponent_eventEvaluatePosition_Parms, Perspective), Z_Construct_UEnum_IronChess_EPieceColor, METADATA_PARAMS(0, nullptr) }; // 1636929315
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UChessAIComponent_EvaluatePosition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessAIComponent_eventEvaluatePosition_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UChessAIComponent_EvaluatePosition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessAIComponent_EvaluatePosition_Statics::NewProp_GameLogic,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessAIComponent_EvaluatePosition_Statics::NewProp_Perspective_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessAIComponent_EvaluatePosition_Statics::NewProp_Perspective,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessAIComponent_EvaluatePosition_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessAIComponent_EvaluatePosition_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UChessAIComponent_EvaluatePosition_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UChessAIComponent, nullptr, "EvaluatePosition", Z_Construct_UFunction_UChessAIComponent_EvaluatePosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UChessAIComponent_EvaluatePosition_Statics::PropPointers), sizeof(Z_Construct_UFunction_UChessAIComponent_EvaluatePosition_Statics::ChessAIComponent_eventEvaluatePosition_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessAIComponent_EvaluatePosition_Statics::Function_MetaDataParams), Z_Construct_UFunction_UChessAIComponent_EvaluatePosition_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UChessAIComponent_EvaluatePosition_Statics::ChessAIComponent_eventEvaluatePosition_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UChessAIComponent_EvaluatePosition()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UChessAIComponent_EvaluatePosition_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UChessAIComponent::execEvaluatePosition)
{
	P_GET_OBJECT(UChessGameLogic,Z_Param_GameLogic);
	P_GET_ENUM(EPieceColor,Z_Param_Perspective);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->EvaluatePosition(Z_Param_GameLogic,EPieceColor(Z_Param_Perspective));
	P_NATIVE_END;
}
// ********** End Class UChessAIComponent Function EvaluatePosition ********************************

// ********** Begin Class UChessAIComponent Function GetBestMove ***********************************
struct Z_Construct_UFunction_UChessAIComponent_GetBestMove_Statics
{
	struct ChessAIComponent_eventGetBestMove_Parms
	{
		UChessGameLogic* GameLogic;
		float MaxThinkTime;
		FChessMove ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Chess AI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// AI Move Selection\n" },
#endif
		{ "CPP_Default_MaxThinkTime", "5.000000" },
		{ "ModuleRelativePath", "AI/ChessAIComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "AI Move Selection" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_GameLogic;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxThinkTime;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UChessAIComponent_GetBestMove_Statics::NewProp_GameLogic = { "GameLogic", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessAIComponent_eventGetBestMove_Parms, GameLogic), Z_Construct_UClass_UChessGameLogic_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UChessAIComponent_GetBestMove_Statics::NewProp_MaxThinkTime = { "MaxThinkTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessAIComponent_eventGetBestMove_Parms, MaxThinkTime), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UChessAIComponent_GetBestMove_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessAIComponent_eventGetBestMove_Parms, ReturnValue), Z_Construct_UScriptStruct_FChessMove, METADATA_PARAMS(0, nullptr) }; // 1361898884
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UChessAIComponent_GetBestMove_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessAIComponent_GetBestMove_Statics::NewProp_GameLogic,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessAIComponent_GetBestMove_Statics::NewProp_MaxThinkTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessAIComponent_GetBestMove_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessAIComponent_GetBestMove_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UChessAIComponent_GetBestMove_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UChessAIComponent, nullptr, "GetBestMove", Z_Construct_UFunction_UChessAIComponent_GetBestMove_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UChessAIComponent_GetBestMove_Statics::PropPointers), sizeof(Z_Construct_UFunction_UChessAIComponent_GetBestMove_Statics::ChessAIComponent_eventGetBestMove_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessAIComponent_GetBestMove_Statics::Function_MetaDataParams), Z_Construct_UFunction_UChessAIComponent_GetBestMove_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UChessAIComponent_GetBestMove_Statics::ChessAIComponent_eventGetBestMove_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UChessAIComponent_GetBestMove()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UChessAIComponent_GetBestMove_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UChessAIComponent::execGetBestMove)
{
	P_GET_OBJECT(UChessGameLogic,Z_Param_GameLogic);
	P_GET_PROPERTY(FFloatProperty,Z_Param_MaxThinkTime);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FChessMove*)Z_Param__Result=P_THIS->GetBestMove(Z_Param_GameLogic,Z_Param_MaxThinkTime);
	P_NATIVE_END;
}
// ********** End Class UChessAIComponent Function GetBestMove *************************************

// ********** Begin Class UChessAIComponent Function GetDifficulty *********************************
struct Z_Construct_UFunction_UChessAIComponent_GetDifficulty_Statics
{
	struct ChessAIComponent_eventGetDifficulty_Parms
	{
		EAIDifficulty ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Chess AI" },
		{ "ModuleRelativePath", "AI/ChessAIComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UChessAIComponent_GetDifficulty_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UChessAIComponent_GetDifficulty_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessAIComponent_eventGetDifficulty_Parms, ReturnValue), Z_Construct_UEnum_IronChess_EAIDifficulty, METADATA_PARAMS(0, nullptr) }; // 2665229670
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UChessAIComponent_GetDifficulty_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessAIComponent_GetDifficulty_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessAIComponent_GetDifficulty_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessAIComponent_GetDifficulty_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UChessAIComponent_GetDifficulty_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UChessAIComponent, nullptr, "GetDifficulty", Z_Construct_UFunction_UChessAIComponent_GetDifficulty_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UChessAIComponent_GetDifficulty_Statics::PropPointers), sizeof(Z_Construct_UFunction_UChessAIComponent_GetDifficulty_Statics::ChessAIComponent_eventGetDifficulty_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessAIComponent_GetDifficulty_Statics::Function_MetaDataParams), Z_Construct_UFunction_UChessAIComponent_GetDifficulty_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UChessAIComponent_GetDifficulty_Statics::ChessAIComponent_eventGetDifficulty_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UChessAIComponent_GetDifficulty()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UChessAIComponent_GetDifficulty_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UChessAIComponent::execGetDifficulty)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EAIDifficulty*)Z_Param__Result=P_THIS->GetDifficulty();
	P_NATIVE_END;
}
// ********** End Class UChessAIComponent Function GetDifficulty ***********************************

// ********** Begin Class UChessAIComponent Function GetPersonality ********************************
struct Z_Construct_UFunction_UChessAIComponent_GetPersonality_Statics
{
	struct ChessAIComponent_eventGetPersonality_Parms
	{
		FAIPersonality ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Chess AI" },
		{ "ModuleRelativePath", "AI/ChessAIComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UChessAIComponent_GetPersonality_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000008000582, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessAIComponent_eventGetPersonality_Parms, ReturnValue), Z_Construct_UScriptStruct_FAIPersonality, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) }; // 2061810822
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UChessAIComponent_GetPersonality_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessAIComponent_GetPersonality_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessAIComponent_GetPersonality_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UChessAIComponent_GetPersonality_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UChessAIComponent, nullptr, "GetPersonality", Z_Construct_UFunction_UChessAIComponent_GetPersonality_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UChessAIComponent_GetPersonality_Statics::PropPointers), sizeof(Z_Construct_UFunction_UChessAIComponent_GetPersonality_Statics::ChessAIComponent_eventGetPersonality_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessAIComponent_GetPersonality_Statics::Function_MetaDataParams), Z_Construct_UFunction_UChessAIComponent_GetPersonality_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UChessAIComponent_GetPersonality_Statics::ChessAIComponent_eventGetPersonality_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UChessAIComponent_GetPersonality()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UChessAIComponent_GetPersonality_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UChessAIComponent::execGetPersonality)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FAIPersonality*)Z_Param__Result=P_THIS->GetPersonality();
	P_NATIVE_END;
}
// ********** End Class UChessAIComponent Function GetPersonality **********************************

// ********** Begin Class UChessAIComponent Function GetStockfishMove ******************************
struct Z_Construct_UFunction_UChessAIComponent_GetStockfishMove_Statics
{
	struct ChessAIComponent_eventGetStockfishMove_Parms
	{
		FString FENPosition;
		int32 SkillLevel;
		FChessMove ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Chess AI" },
		{ "CPP_Default_SkillLevel", "20" },
		{ "ModuleRelativePath", "AI/ChessAIComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FENPosition_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_FENPosition;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SkillLevel;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UChessAIComponent_GetStockfishMove_Statics::NewProp_FENPosition = { "FENPosition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessAIComponent_eventGetStockfishMove_Parms, FENPosition), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FENPosition_MetaData), NewProp_FENPosition_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UChessAIComponent_GetStockfishMove_Statics::NewProp_SkillLevel = { "SkillLevel", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessAIComponent_eventGetStockfishMove_Parms, SkillLevel), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UChessAIComponent_GetStockfishMove_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessAIComponent_eventGetStockfishMove_Parms, ReturnValue), Z_Construct_UScriptStruct_FChessMove, METADATA_PARAMS(0, nullptr) }; // 1361898884
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UChessAIComponent_GetStockfishMove_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessAIComponent_GetStockfishMove_Statics::NewProp_FENPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessAIComponent_GetStockfishMove_Statics::NewProp_SkillLevel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessAIComponent_GetStockfishMove_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessAIComponent_GetStockfishMove_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UChessAIComponent_GetStockfishMove_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UChessAIComponent, nullptr, "GetStockfishMove", Z_Construct_UFunction_UChessAIComponent_GetStockfishMove_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UChessAIComponent_GetStockfishMove_Statics::PropPointers), sizeof(Z_Construct_UFunction_UChessAIComponent_GetStockfishMove_Statics::ChessAIComponent_eventGetStockfishMove_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessAIComponent_GetStockfishMove_Statics::Function_MetaDataParams), Z_Construct_UFunction_UChessAIComponent_GetStockfishMove_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UChessAIComponent_GetStockfishMove_Statics::ChessAIComponent_eventGetStockfishMove_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UChessAIComponent_GetStockfishMove()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UChessAIComponent_GetStockfishMove_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UChessAIComponent::execGetStockfishMove)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_FENPosition);
	P_GET_PROPERTY(FIntProperty,Z_Param_SkillLevel);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FChessMove*)Z_Param__Result=P_THIS->GetStockfishMove(Z_Param_FENPosition,Z_Param_SkillLevel);
	P_NATIVE_END;
}
// ********** End Class UChessAIComponent Function GetStockfishMove ********************************

// ********** Begin Class UChessAIComponent Function InitializeStockfish ***************************
struct Z_Construct_UFunction_UChessAIComponent_InitializeStockfish_Statics
{
	struct ChessAIComponent_eventInitializeStockfish_Parms
	{
		FString ExecutablePath;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Chess AI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Stockfish Integration\n" },
#endif
		{ "ModuleRelativePath", "AI/ChessAIComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Stockfish Integration" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExecutablePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ExecutablePath;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UChessAIComponent_InitializeStockfish_Statics::NewProp_ExecutablePath = { "ExecutablePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessAIComponent_eventInitializeStockfish_Parms, ExecutablePath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExecutablePath_MetaData), NewProp_ExecutablePath_MetaData) };
void Z_Construct_UFunction_UChessAIComponent_InitializeStockfish_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ChessAIComponent_eventInitializeStockfish_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UChessAIComponent_InitializeStockfish_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ChessAIComponent_eventInitializeStockfish_Parms), &Z_Construct_UFunction_UChessAIComponent_InitializeStockfish_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UChessAIComponent_InitializeStockfish_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessAIComponent_InitializeStockfish_Statics::NewProp_ExecutablePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessAIComponent_InitializeStockfish_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessAIComponent_InitializeStockfish_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UChessAIComponent_InitializeStockfish_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UChessAIComponent, nullptr, "InitializeStockfish", Z_Construct_UFunction_UChessAIComponent_InitializeStockfish_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UChessAIComponent_InitializeStockfish_Statics::PropPointers), sizeof(Z_Construct_UFunction_UChessAIComponent_InitializeStockfish_Statics::ChessAIComponent_eventInitializeStockfish_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessAIComponent_InitializeStockfish_Statics::Function_MetaDataParams), Z_Construct_UFunction_UChessAIComponent_InitializeStockfish_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UChessAIComponent_InitializeStockfish_Statics::ChessAIComponent_eventInitializeStockfish_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UChessAIComponent_InitializeStockfish()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UChessAIComponent_InitializeStockfish_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UChessAIComponent::execInitializeStockfish)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ExecutablePath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->InitializeStockfish(Z_Param_ExecutablePath);
	P_NATIVE_END;
}
// ********** End Class UChessAIComponent Function InitializeStockfish *****************************

// ********** Begin Class UChessAIComponent Function IsEndgame *************************************
struct Z_Construct_UFunction_UChessAIComponent_IsEndgame_Statics
{
	struct ChessAIComponent_eventIsEndgame_Parms
	{
		UChessGameLogic* GameLogic;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Chess AI" },
		{ "ModuleRelativePath", "AI/ChessAIComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_GameLogic;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UChessAIComponent_IsEndgame_Statics::NewProp_GameLogic = { "GameLogic", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessAIComponent_eventIsEndgame_Parms, GameLogic), Z_Construct_UClass_UChessGameLogic_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UChessAIComponent_IsEndgame_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ChessAIComponent_eventIsEndgame_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UChessAIComponent_IsEndgame_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ChessAIComponent_eventIsEndgame_Parms), &Z_Construct_UFunction_UChessAIComponent_IsEndgame_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UChessAIComponent_IsEndgame_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessAIComponent_IsEndgame_Statics::NewProp_GameLogic,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessAIComponent_IsEndgame_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessAIComponent_IsEndgame_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UChessAIComponent_IsEndgame_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UChessAIComponent, nullptr, "IsEndgame", Z_Construct_UFunction_UChessAIComponent_IsEndgame_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UChessAIComponent_IsEndgame_Statics::PropPointers), sizeof(Z_Construct_UFunction_UChessAIComponent_IsEndgame_Statics::ChessAIComponent_eventIsEndgame_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessAIComponent_IsEndgame_Statics::Function_MetaDataParams), Z_Construct_UFunction_UChessAIComponent_IsEndgame_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UChessAIComponent_IsEndgame_Statics::ChessAIComponent_eventIsEndgame_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UChessAIComponent_IsEndgame()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UChessAIComponent_IsEndgame_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UChessAIComponent::execIsEndgame)
{
	P_GET_OBJECT(UChessGameLogic,Z_Param_GameLogic);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsEndgame(Z_Param_GameLogic);
	P_NATIVE_END;
}
// ********** End Class UChessAIComponent Function IsEndgame ***************************************

// ********** Begin Class UChessAIComponent Function SetDifficulty *********************************
struct Z_Construct_UFunction_UChessAIComponent_SetDifficulty_Statics
{
	struct ChessAIComponent_eventSetDifficulty_Parms
	{
		EAIDifficulty NewDifficulty;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Chess AI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Difficulty Management\n" },
#endif
		{ "ModuleRelativePath", "AI/ChessAIComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Difficulty Management" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_NewDifficulty_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NewDifficulty;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UChessAIComponent_SetDifficulty_Statics::NewProp_NewDifficulty_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UChessAIComponent_SetDifficulty_Statics::NewProp_NewDifficulty = { "NewDifficulty", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessAIComponent_eventSetDifficulty_Parms, NewDifficulty), Z_Construct_UEnum_IronChess_EAIDifficulty, METADATA_PARAMS(0, nullptr) }; // 2665229670
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UChessAIComponent_SetDifficulty_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessAIComponent_SetDifficulty_Statics::NewProp_NewDifficulty_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessAIComponent_SetDifficulty_Statics::NewProp_NewDifficulty,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessAIComponent_SetDifficulty_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UChessAIComponent_SetDifficulty_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UChessAIComponent, nullptr, "SetDifficulty", Z_Construct_UFunction_UChessAIComponent_SetDifficulty_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UChessAIComponent_SetDifficulty_Statics::PropPointers), sizeof(Z_Construct_UFunction_UChessAIComponent_SetDifficulty_Statics::ChessAIComponent_eventSetDifficulty_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessAIComponent_SetDifficulty_Statics::Function_MetaDataParams), Z_Construct_UFunction_UChessAIComponent_SetDifficulty_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UChessAIComponent_SetDifficulty_Statics::ChessAIComponent_eventSetDifficulty_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UChessAIComponent_SetDifficulty()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UChessAIComponent_SetDifficulty_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UChessAIComponent::execSetDifficulty)
{
	P_GET_ENUM(EAIDifficulty,Z_Param_NewDifficulty);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetDifficulty(EAIDifficulty(Z_Param_NewDifficulty));
	P_NATIVE_END;
}
// ********** End Class UChessAIComponent Function SetDifficulty ***********************************

// ********** Begin Class UChessAIComponent Function SetPersonality ********************************
struct Z_Construct_UFunction_UChessAIComponent_SetPersonality_Statics
{
	struct ChessAIComponent_eventSetPersonality_Parms
	{
		FAIPersonality NewPersonality;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Chess AI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// AI Personality\n" },
#endif
		{ "ModuleRelativePath", "AI/ChessAIComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "AI Personality" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NewPersonality_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_NewPersonality;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UChessAIComponent_SetPersonality_Statics::NewProp_NewPersonality = { "NewPersonality", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ChessAIComponent_eventSetPersonality_Parms, NewPersonality), Z_Construct_UScriptStruct_FAIPersonality, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NewPersonality_MetaData), NewProp_NewPersonality_MetaData) }; // 2061810822
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UChessAIComponent_SetPersonality_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UChessAIComponent_SetPersonality_Statics::NewProp_NewPersonality,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessAIComponent_SetPersonality_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UChessAIComponent_SetPersonality_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UChessAIComponent, nullptr, "SetPersonality", Z_Construct_UFunction_UChessAIComponent_SetPersonality_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UChessAIComponent_SetPersonality_Statics::PropPointers), sizeof(Z_Construct_UFunction_UChessAIComponent_SetPersonality_Statics::ChessAIComponent_eventSetPersonality_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UChessAIComponent_SetPersonality_Statics::Function_MetaDataParams), Z_Construct_UFunction_UChessAIComponent_SetPersonality_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UChessAIComponent_SetPersonality_Statics::ChessAIComponent_eventSetPersonality_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UChessAIComponent_SetPersonality()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UChessAIComponent_SetPersonality_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UChessAIComponent::execSetPersonality)
{
	P_GET_STRUCT_REF(FAIPersonality,Z_Param_Out_NewPersonality);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetPersonality(Z_Param_Out_NewPersonality);
	P_NATIVE_END;
}
// ********** End Class UChessAIComponent Function SetPersonality **********************************

// ********** Begin Class UChessAIComponent ********************************************************
void UChessAIComponent::StaticRegisterNativesUChessAIComponent()
{
	UClass* Class = UChessAIComponent::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "AnalyzePosition", &UChessAIComponent::execAnalyzePosition },
		{ "EvaluatePosition", &UChessAIComponent::execEvaluatePosition },
		{ "GetBestMove", &UChessAIComponent::execGetBestMove },
		{ "GetDifficulty", &UChessAIComponent::execGetDifficulty },
		{ "GetPersonality", &UChessAIComponent::execGetPersonality },
		{ "GetStockfishMove", &UChessAIComponent::execGetStockfishMove },
		{ "InitializeStockfish", &UChessAIComponent::execInitializeStockfish },
		{ "IsEndgame", &UChessAIComponent::execIsEndgame },
		{ "SetDifficulty", &UChessAIComponent::execSetDifficulty },
		{ "SetPersonality", &UChessAIComponent::execSetPersonality },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UChessAIComponent;
UClass* UChessAIComponent::GetPrivateStaticClass()
{
	using TClass = UChessAIComponent;
	if (!Z_Registration_Info_UClass_UChessAIComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ChessAIComponent"),
			Z_Registration_Info_UClass_UChessAIComponent.InnerSingleton,
			StaticRegisterNativesUChessAIComponent,
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
	return Z_Registration_Info_UClass_UChessAIComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UChessAIComponent_NoRegister()
{
	return UChessAIComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UChessAIComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "Custom" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * AI Component for chess gameplay\n * Handles difficulty scaling, move calculation, and personality-based play styles\n */" },
#endif
		{ "IncludePath", "AI/ChessAIComponent.h" },
		{ "ModuleRelativePath", "AI/ChessAIComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "AI Component for chess gameplay\nHandles difficulty scaling, move calculation, and personality-based play styles" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnAIMoveCalculated_MetaData[] = {
		{ "ModuleRelativePath", "AI/ChessAIComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnAIThinking_MetaData[] = {
		{ "ModuleRelativePath", "AI/ChessAIComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentDifficulty_MetaData[] = {
		{ "Category", "Chess AI" },
		{ "ModuleRelativePath", "AI/ChessAIComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Personality_MetaData[] = {
		{ "Category", "Chess AI" },
		{ "ModuleRelativePath", "AI/ChessAIComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUseOpeningBook_MetaData[] = {
		{ "Category", "Chess AI" },
		{ "ModuleRelativePath", "AI/ChessAIComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUseEndgameTablebase_MetaData[] = {
		{ "Category", "Chess AI" },
		{ "ModuleRelativePath", "AI/ChessAIComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultThinkTime_MetaData[] = {
		{ "Category", "Chess AI" },
		{ "ModuleRelativePath", "AI/ChessAIComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TranspositionTable_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Transposition table for caching evaluations\n" },
#endif
		{ "ModuleRelativePath", "AI/ChessAIComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Transposition table for caching evaluations" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnAIMoveCalculated;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnAIThinking;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CurrentDifficulty_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CurrentDifficulty;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Personality;
	static void NewProp_bUseOpeningBook_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseOpeningBook;
	static void NewProp_bUseEndgameTablebase_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseEndgameTablebase;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DefaultThinkTime;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TranspositionTable_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_TranspositionTable_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_TranspositionTable;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UChessAIComponent_AnalyzePosition, "AnalyzePosition" }, // 4209286001
		{ &Z_Construct_UFunction_UChessAIComponent_EvaluatePosition, "EvaluatePosition" }, // 1033986146
		{ &Z_Construct_UFunction_UChessAIComponent_GetBestMove, "GetBestMove" }, // 4109898385
		{ &Z_Construct_UFunction_UChessAIComponent_GetDifficulty, "GetDifficulty" }, // 3651856752
		{ &Z_Construct_UFunction_UChessAIComponent_GetPersonality, "GetPersonality" }, // 1917159380
		{ &Z_Construct_UFunction_UChessAIComponent_GetStockfishMove, "GetStockfishMove" }, // 1758517138
		{ &Z_Construct_UFunction_UChessAIComponent_InitializeStockfish, "InitializeStockfish" }, // 1314700603
		{ &Z_Construct_UFunction_UChessAIComponent_IsEndgame, "IsEndgame" }, // 3238627254
		{ &Z_Construct_UDelegateFunction_UChessAIComponent_OnAIMoveCalculated__DelegateSignature, "OnAIMoveCalculated__DelegateSignature" }, // 2483958309
		{ &Z_Construct_UDelegateFunction_UChessAIComponent_OnAIThinking__DelegateSignature, "OnAIThinking__DelegateSignature" }, // 2892307637
		{ &Z_Construct_UFunction_UChessAIComponent_SetDifficulty, "SetDifficulty" }, // 3568703266
		{ &Z_Construct_UFunction_UChessAIComponent_SetPersonality, "SetPersonality" }, // 2796698962
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UChessAIComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UChessAIComponent_Statics::NewProp_OnAIMoveCalculated = { "OnAIMoveCalculated", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UChessAIComponent, OnAIMoveCalculated), Z_Construct_UDelegateFunction_UChessAIComponent_OnAIMoveCalculated__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnAIMoveCalculated_MetaData), NewProp_OnAIMoveCalculated_MetaData) }; // 2483958309
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UChessAIComponent_Statics::NewProp_OnAIThinking = { "OnAIThinking", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UChessAIComponent, OnAIThinking), Z_Construct_UDelegateFunction_UChessAIComponent_OnAIThinking__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnAIThinking_MetaData), NewProp_OnAIThinking_MetaData) }; // 2892307637
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UChessAIComponent_Statics::NewProp_CurrentDifficulty_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UChessAIComponent_Statics::NewProp_CurrentDifficulty = { "CurrentDifficulty", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UChessAIComponent, CurrentDifficulty), Z_Construct_UEnum_IronChess_EAIDifficulty, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentDifficulty_MetaData), NewProp_CurrentDifficulty_MetaData) }; // 2665229670
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UChessAIComponent_Statics::NewProp_Personality = { "Personality", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UChessAIComponent, Personality), Z_Construct_UScriptStruct_FAIPersonality, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Personality_MetaData), NewProp_Personality_MetaData) }; // 2061810822
void Z_Construct_UClass_UChessAIComponent_Statics::NewProp_bUseOpeningBook_SetBit(void* Obj)
{
	((UChessAIComponent*)Obj)->bUseOpeningBook = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UChessAIComponent_Statics::NewProp_bUseOpeningBook = { "bUseOpeningBook", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UChessAIComponent), &Z_Construct_UClass_UChessAIComponent_Statics::NewProp_bUseOpeningBook_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUseOpeningBook_MetaData), NewProp_bUseOpeningBook_MetaData) };
void Z_Construct_UClass_UChessAIComponent_Statics::NewProp_bUseEndgameTablebase_SetBit(void* Obj)
{
	((UChessAIComponent*)Obj)->bUseEndgameTablebase = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UChessAIComponent_Statics::NewProp_bUseEndgameTablebase = { "bUseEndgameTablebase", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UChessAIComponent), &Z_Construct_UClass_UChessAIComponent_Statics::NewProp_bUseEndgameTablebase_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUseEndgameTablebase_MetaData), NewProp_bUseEndgameTablebase_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UChessAIComponent_Statics::NewProp_DefaultThinkTime = { "DefaultThinkTime", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UChessAIComponent, DefaultThinkTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultThinkTime_MetaData), NewProp_DefaultThinkTime_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UChessAIComponent_Statics::NewProp_TranspositionTable_ValueProp = { "TranspositionTable", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FMoveEvaluation, METADATA_PARAMS(0, nullptr) }; // 3428123318
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UChessAIComponent_Statics::NewProp_TranspositionTable_Key_KeyProp = { "TranspositionTable_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UChessAIComponent_Statics::NewProp_TranspositionTable = { "TranspositionTable", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UChessAIComponent, TranspositionTable), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TranspositionTable_MetaData), NewProp_TranspositionTable_MetaData) }; // 3428123318
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UChessAIComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UChessAIComponent_Statics::NewProp_OnAIMoveCalculated,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UChessAIComponent_Statics::NewProp_OnAIThinking,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UChessAIComponent_Statics::NewProp_CurrentDifficulty_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UChessAIComponent_Statics::NewProp_CurrentDifficulty,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UChessAIComponent_Statics::NewProp_Personality,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UChessAIComponent_Statics::NewProp_bUseOpeningBook,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UChessAIComponent_Statics::NewProp_bUseEndgameTablebase,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UChessAIComponent_Statics::NewProp_DefaultThinkTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UChessAIComponent_Statics::NewProp_TranspositionTable_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UChessAIComponent_Statics::NewProp_TranspositionTable_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UChessAIComponent_Statics::NewProp_TranspositionTable,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UChessAIComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UChessAIComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_IronChess,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UChessAIComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UChessAIComponent_Statics::ClassParams = {
	&UChessAIComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UChessAIComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UChessAIComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UChessAIComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UChessAIComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UChessAIComponent()
{
	if (!Z_Registration_Info_UClass_UChessAIComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UChessAIComponent.OuterSingleton, Z_Construct_UClass_UChessAIComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UChessAIComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UChessAIComponent);
UChessAIComponent::~UChessAIComponent() {}
// ********** End Class UChessAIComponent **********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_AI_ChessAIComponent_h__Script_IronChess_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EAIDifficulty_StaticEnum, TEXT("EAIDifficulty"), &Z_Registration_Info_UEnum_EAIDifficulty, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2665229670U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FAIPersonality::StaticStruct, Z_Construct_UScriptStruct_FAIPersonality_Statics::NewStructOps, TEXT("AIPersonality"), &Z_Registration_Info_UScriptStruct_FAIPersonality, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAIPersonality), 2061810822U) },
		{ FMoveEvaluation::StaticStruct, Z_Construct_UScriptStruct_FMoveEvaluation_Statics::NewStructOps, TEXT("MoveEvaluation"), &Z_Registration_Info_UScriptStruct_FMoveEvaluation, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FMoveEvaluation), 3428123318U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UChessAIComponent, UChessAIComponent::StaticClass, TEXT("UChessAIComponent"), &Z_Registration_Info_UClass_UChessAIComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UChessAIComponent), 2430589570U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_AI_ChessAIComponent_h__Script_IronChess_3288134663(TEXT("/Script/IronChess"),
	Z_CompiledInDeferFile_FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_AI_ChessAIComponent_h__Script_IronChess_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_AI_ChessAIComponent_h__Script_IronChess_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_AI_ChessAIComponent_h__Script_IronChess_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_AI_ChessAIComponent_h__Script_IronChess_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_AI_ChessAIComponent_h__Script_IronChess_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_AI_ChessAIComponent_h__Script_IronChess_Statics::EnumInfo));
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
