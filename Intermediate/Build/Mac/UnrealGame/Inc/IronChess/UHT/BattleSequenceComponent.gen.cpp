// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BattleSequenceComponent.h"
#include "ChessTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeBattleSequenceComponent() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
ENGINE_API UClass* Z_Construct_UClass_UAudioComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent();
ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
IRONCHESS_API UClass* Z_Construct_UClass_UBattleSequenceComponent();
IRONCHESS_API UClass* Z_Construct_UClass_UBattleSequenceComponent_NoRegister();
IRONCHESS_API UEnum* Z_Construct_UEnum_IronChess_EBattleSequenceType();
IRONCHESS_API UEnum* Z_Construct_UEnum_IronChess_EPieceColor();
IRONCHESS_API UEnum* Z_Construct_UEnum_IronChess_EPieceType();
IRONCHESS_API UFunction* Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceFinished__DelegateSignature();
IRONCHESS_API UFunction* Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceProgress__DelegateSignature();
IRONCHESS_API UFunction* Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceStarted__DelegateSignature();
IRONCHESS_API UScriptStruct* Z_Construct_UScriptStruct_FBattleContext();
IRONCHESS_API UScriptStruct* Z_Construct_UScriptStruct_FBattleSequenceConfig();
IRONCHESS_API UScriptStruct* Z_Construct_UScriptStruct_FChessMove();
IRONCHESS_API UScriptStruct* Z_Construct_UScriptStruct_FChessPosition();
LEVELSEQUENCE_API UClass* Z_Construct_UClass_ULevelSequence_NoRegister();
LEVELSEQUENCE_API UClass* Z_Construct_UClass_ULevelSequencePlayer_NoRegister();
NIAGARA_API UClass* Z_Construct_UClass_UNiagaraComponent_NoRegister();
NIAGARA_API UClass* Z_Construct_UClass_UNiagaraSystem_NoRegister();
UPackage* Z_Construct_UPackage__Script_IronChess();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EBattleSequenceType *******************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EBattleSequenceType;
static UEnum* EBattleSequenceType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EBattleSequenceType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EBattleSequenceType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_IronChess_EBattleSequenceType, (UObject*)Z_Construct_UPackage__Script_IronChess(), TEXT("EBattleSequenceType"));
	}
	return Z_Registration_Info_UEnum_EBattleSequenceType.OuterSingleton;
}
template<> IRONCHESS_API UEnum* StaticEnum<EBattleSequenceType>()
{
	return EBattleSequenceType_StaticEnum();
}
struct Z_Construct_UEnum_IronChess_EBattleSequenceType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BishopCapture.Comment", "// Siege warfare\n" },
		{ "BishopCapture.Name", "EBattleSequenceType::BishopCapture" },
		{ "BishopCapture.ToolTip", "Siege warfare" },
		{ "BlueprintType", "true" },
		{ "Castling.Comment", "// Dramatic finale\n" },
		{ "Castling.Name", "EBattleSequenceType::Castling" },
		{ "Castling.ToolTip", "Dramatic finale" },
		{ "Check.Comment", "// Transformation scene\n" },
		{ "Check.Name", "EBattleSequenceType::Check" },
		{ "Check.ToolTip", "Transformation scene" },
		{ "Checkmate.Comment", "// Tension builder\n" },
		{ "Checkmate.Name", "EBattleSequenceType::Checkmate" },
		{ "Checkmate.ToolTip", "Tension builder" },
		{ "EnPassant.Comment", "// Strategic maneuver\n" },
		{ "EnPassant.Name", "EBattleSequenceType::EnPassant" },
		{ "EnPassant.ToolTip", "Strategic maneuver" },
		{ "KingCapture.Comment", "// Epic royal combat\n" },
		{ "KingCapture.Name", "EBattleSequenceType::KingCapture" },
		{ "KingCapture.ToolTip", "Epic royal combat" },
		{ "KnightCapture.Comment", "// Soldier vs soldier combat\n" },
		{ "KnightCapture.Name", "EBattleSequenceType::KnightCapture" },
		{ "KnightCapture.ToolTip", "Soldier vs soldier combat" },
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
		{ "None.Name", "EBattleSequenceType::None" },
		{ "PawnCapture.Name", "EBattleSequenceType::PawnCapture" },
		{ "Promotion.Comment", "// Surprise attack\n" },
		{ "Promotion.Name", "EBattleSequenceType::Promotion" },
		{ "Promotion.ToolTip", "Surprise attack" },
		{ "QueenCapture.Comment", "// Magical/religious battle\n" },
		{ "QueenCapture.Name", "EBattleSequenceType::QueenCapture" },
		{ "QueenCapture.ToolTip", "Magical/religious battle" },
		{ "RookCapture.Comment", "// Cavalry charge\n" },
		{ "RookCapture.Name", "EBattleSequenceType::RookCapture" },
		{ "RookCapture.ToolTip", "Cavalry charge" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EBattleSequenceType::None", (int64)EBattleSequenceType::None },
		{ "EBattleSequenceType::PawnCapture", (int64)EBattleSequenceType::PawnCapture },
		{ "EBattleSequenceType::KnightCapture", (int64)EBattleSequenceType::KnightCapture },
		{ "EBattleSequenceType::RookCapture", (int64)EBattleSequenceType::RookCapture },
		{ "EBattleSequenceType::BishopCapture", (int64)EBattleSequenceType::BishopCapture },
		{ "EBattleSequenceType::QueenCapture", (int64)EBattleSequenceType::QueenCapture },
		{ "EBattleSequenceType::KingCapture", (int64)EBattleSequenceType::KingCapture },
		{ "EBattleSequenceType::Castling", (int64)EBattleSequenceType::Castling },
		{ "EBattleSequenceType::EnPassant", (int64)EBattleSequenceType::EnPassant },
		{ "EBattleSequenceType::Promotion", (int64)EBattleSequenceType::Promotion },
		{ "EBattleSequenceType::Check", (int64)EBattleSequenceType::Check },
		{ "EBattleSequenceType::Checkmate", (int64)EBattleSequenceType::Checkmate },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_IronChess_EBattleSequenceType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_IronChess,
	nullptr,
	"EBattleSequenceType",
	"EBattleSequenceType",
	Z_Construct_UEnum_IronChess_EBattleSequenceType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_IronChess_EBattleSequenceType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_IronChess_EBattleSequenceType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_IronChess_EBattleSequenceType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_IronChess_EBattleSequenceType()
{
	if (!Z_Registration_Info_UEnum_EBattleSequenceType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EBattleSequenceType.InnerSingleton, Z_Construct_UEnum_IronChess_EBattleSequenceType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EBattleSequenceType.InnerSingleton;
}
// ********** End Enum EBattleSequenceType *********************************************************

// ********** Begin ScriptStruct FBattleSequenceConfig *********************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FBattleSequenceConfig;
class UScriptStruct* FBattleSequenceConfig::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FBattleSequenceConfig.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FBattleSequenceConfig.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FBattleSequenceConfig, (UObject*)Z_Construct_UPackage__Script_IronChess(), TEXT("BattleSequenceConfig"));
	}
	return Z_Registration_Info_UScriptStruct_FBattleSequenceConfig.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FBattleSequenceConfig_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SequenceType_MetaData[] = {
		{ "Category", "Battle Config" },
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SequenceAsset_MetaData[] = {
		{ "Category", "Battle Config" },
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Duration_MetaData[] = {
		{ "Category", "Battle Config" },
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUseDynamicCamera_MetaData[] = {
		{ "Category", "Battle Config" },
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ParticleEffects_MetaData[] = {
		{ "Category", "Battle Config" },
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SoundEffects_MetaData[] = {
		{ "Category", "Battle Config" },
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IntensityMultiplier_MetaData[] = {
		{ "Category", "Battle Config" },
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_SequenceType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SequenceType;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_SequenceAsset;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Duration;
	static void NewProp_bUseDynamicCamera_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseDynamicCamera;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_ParticleEffects_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ParticleEffects;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_SoundEffects_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_SoundEffects;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_IntensityMultiplier;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FBattleSequenceConfig>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FBattleSequenceConfig_Statics::NewProp_SequenceType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FBattleSequenceConfig_Statics::NewProp_SequenceType = { "SequenceType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FBattleSequenceConfig, SequenceType), Z_Construct_UEnum_IronChess_EBattleSequenceType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SequenceType_MetaData), NewProp_SequenceType_MetaData) }; // 2870919168
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FBattleSequenceConfig_Statics::NewProp_SequenceAsset = { "SequenceAsset", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FBattleSequenceConfig, SequenceAsset), Z_Construct_UClass_ULevelSequence_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SequenceAsset_MetaData), NewProp_SequenceAsset_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FBattleSequenceConfig_Statics::NewProp_Duration = { "Duration", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FBattleSequenceConfig, Duration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Duration_MetaData), NewProp_Duration_MetaData) };
void Z_Construct_UScriptStruct_FBattleSequenceConfig_Statics::NewProp_bUseDynamicCamera_SetBit(void* Obj)
{
	((FBattleSequenceConfig*)Obj)->bUseDynamicCamera = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FBattleSequenceConfig_Statics::NewProp_bUseDynamicCamera = { "bUseDynamicCamera", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FBattleSequenceConfig), &Z_Construct_UScriptStruct_FBattleSequenceConfig_Statics::NewProp_bUseDynamicCamera_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUseDynamicCamera_MetaData), NewProp_bUseDynamicCamera_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FBattleSequenceConfig_Statics::NewProp_ParticleEffects_Inner = { "ParticleEffects", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UNiagaraSystem_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FBattleSequenceConfig_Statics::NewProp_ParticleEffects = { "ParticleEffects", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FBattleSequenceConfig, ParticleEffects), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ParticleEffects_MetaData), NewProp_ParticleEffects_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FBattleSequenceConfig_Statics::NewProp_SoundEffects_Inner = { "SoundEffects", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FBattleSequenceConfig_Statics::NewProp_SoundEffects = { "SoundEffects", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FBattleSequenceConfig, SoundEffects), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SoundEffects_MetaData), NewProp_SoundEffects_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FBattleSequenceConfig_Statics::NewProp_IntensityMultiplier = { "IntensityMultiplier", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FBattleSequenceConfig, IntensityMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IntensityMultiplier_MetaData), NewProp_IntensityMultiplier_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FBattleSequenceConfig_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBattleSequenceConfig_Statics::NewProp_SequenceType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBattleSequenceConfig_Statics::NewProp_SequenceType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBattleSequenceConfig_Statics::NewProp_SequenceAsset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBattleSequenceConfig_Statics::NewProp_Duration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBattleSequenceConfig_Statics::NewProp_bUseDynamicCamera,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBattleSequenceConfig_Statics::NewProp_ParticleEffects_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBattleSequenceConfig_Statics::NewProp_ParticleEffects,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBattleSequenceConfig_Statics::NewProp_SoundEffects_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBattleSequenceConfig_Statics::NewProp_SoundEffects,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBattleSequenceConfig_Statics::NewProp_IntensityMultiplier,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBattleSequenceConfig_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FBattleSequenceConfig_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_IronChess,
	nullptr,
	&NewStructOps,
	"BattleSequenceConfig",
	Z_Construct_UScriptStruct_FBattleSequenceConfig_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBattleSequenceConfig_Statics::PropPointers),
	sizeof(FBattleSequenceConfig),
	alignof(FBattleSequenceConfig),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBattleSequenceConfig_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FBattleSequenceConfig_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FBattleSequenceConfig()
{
	if (!Z_Registration_Info_UScriptStruct_FBattleSequenceConfig.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FBattleSequenceConfig.InnerSingleton, Z_Construct_UScriptStruct_FBattleSequenceConfig_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FBattleSequenceConfig.InnerSingleton;
}
// ********** End ScriptStruct FBattleSequenceConfig ***********************************************

// ********** Begin ScriptStruct FBattleContext ****************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FBattleContext;
class UScriptStruct* FBattleContext::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FBattleContext.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FBattleContext.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FBattleContext, (UObject*)Z_Construct_UPackage__Script_IronChess(), TEXT("BattleContext"));
	}
	return Z_Registration_Info_UScriptStruct_FBattleContext.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FBattleContext_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TriggerMove_MetaData[] = {
		{ "Category", "BattleContext" },
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackerPosition_MetaData[] = {
		{ "Category", "BattleContext" },
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefenderPosition_MetaData[] = {
		{ "Category", "BattleContext" },
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackerType_MetaData[] = {
		{ "Category", "BattleContext" },
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefenderType_MetaData[] = {
		{ "Category", "BattleContext" },
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackerColor_MetaData[] = {
		{ "Category", "BattleContext" },
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MovesSinceLastBattle_MetaData[] = {
		{ "Category", "BattleContext" },
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsCheckMove_MetaData[] = {
		{ "Category", "BattleContext" },
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsCheckmateMove_MetaData[] = {
		{ "Category", "BattleContext" },
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_TriggerMove;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AttackerPosition;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DefenderPosition;
	static const UECodeGen_Private::FBytePropertyParams NewProp_AttackerType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_AttackerType;
	static const UECodeGen_Private::FBytePropertyParams NewProp_DefenderType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_DefenderType;
	static const UECodeGen_Private::FBytePropertyParams NewProp_AttackerColor_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_AttackerColor;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MovesSinceLastBattle;
	static void NewProp_bIsCheckMove_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsCheckMove;
	static void NewProp_bIsCheckmateMove_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsCheckmateMove;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FBattleContext>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FBattleContext_Statics::NewProp_TriggerMove = { "TriggerMove", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FBattleContext, TriggerMove), Z_Construct_UScriptStruct_FChessMove, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TriggerMove_MetaData), NewProp_TriggerMove_MetaData) }; // 1361898884
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FBattleContext_Statics::NewProp_AttackerPosition = { "AttackerPosition", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FBattleContext, AttackerPosition), Z_Construct_UScriptStruct_FChessPosition, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackerPosition_MetaData), NewProp_AttackerPosition_MetaData) }; // 1812120650
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FBattleContext_Statics::NewProp_DefenderPosition = { "DefenderPosition", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FBattleContext, DefenderPosition), Z_Construct_UScriptStruct_FChessPosition, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefenderPosition_MetaData), NewProp_DefenderPosition_MetaData) }; // 1812120650
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FBattleContext_Statics::NewProp_AttackerType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FBattleContext_Statics::NewProp_AttackerType = { "AttackerType", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FBattleContext, AttackerType), Z_Construct_UEnum_IronChess_EPieceType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackerType_MetaData), NewProp_AttackerType_MetaData) }; // 2986096202
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FBattleContext_Statics::NewProp_DefenderType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FBattleContext_Statics::NewProp_DefenderType = { "DefenderType", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FBattleContext, DefenderType), Z_Construct_UEnum_IronChess_EPieceType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefenderType_MetaData), NewProp_DefenderType_MetaData) }; // 2986096202
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FBattleContext_Statics::NewProp_AttackerColor_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FBattleContext_Statics::NewProp_AttackerColor = { "AttackerColor", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FBattleContext, AttackerColor), Z_Construct_UEnum_IronChess_EPieceColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackerColor_MetaData), NewProp_AttackerColor_MetaData) }; // 1636929315
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FBattleContext_Statics::NewProp_MovesSinceLastBattle = { "MovesSinceLastBattle", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FBattleContext, MovesSinceLastBattle), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MovesSinceLastBattle_MetaData), NewProp_MovesSinceLastBattle_MetaData) };
void Z_Construct_UScriptStruct_FBattleContext_Statics::NewProp_bIsCheckMove_SetBit(void* Obj)
{
	((FBattleContext*)Obj)->bIsCheckMove = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FBattleContext_Statics::NewProp_bIsCheckMove = { "bIsCheckMove", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FBattleContext), &Z_Construct_UScriptStruct_FBattleContext_Statics::NewProp_bIsCheckMove_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsCheckMove_MetaData), NewProp_bIsCheckMove_MetaData) };
void Z_Construct_UScriptStruct_FBattleContext_Statics::NewProp_bIsCheckmateMove_SetBit(void* Obj)
{
	((FBattleContext*)Obj)->bIsCheckmateMove = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FBattleContext_Statics::NewProp_bIsCheckmateMove = { "bIsCheckmateMove", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FBattleContext), &Z_Construct_UScriptStruct_FBattleContext_Statics::NewProp_bIsCheckmateMove_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsCheckmateMove_MetaData), NewProp_bIsCheckmateMove_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FBattleContext_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBattleContext_Statics::NewProp_TriggerMove,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBattleContext_Statics::NewProp_AttackerPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBattleContext_Statics::NewProp_DefenderPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBattleContext_Statics::NewProp_AttackerType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBattleContext_Statics::NewProp_AttackerType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBattleContext_Statics::NewProp_DefenderType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBattleContext_Statics::NewProp_DefenderType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBattleContext_Statics::NewProp_AttackerColor_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBattleContext_Statics::NewProp_AttackerColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBattleContext_Statics::NewProp_MovesSinceLastBattle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBattleContext_Statics::NewProp_bIsCheckMove,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBattleContext_Statics::NewProp_bIsCheckmateMove,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBattleContext_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FBattleContext_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_IronChess,
	nullptr,
	&NewStructOps,
	"BattleContext",
	Z_Construct_UScriptStruct_FBattleContext_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBattleContext_Statics::PropPointers),
	sizeof(FBattleContext),
	alignof(FBattleContext),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBattleContext_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FBattleContext_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FBattleContext()
{
	if (!Z_Registration_Info_UScriptStruct_FBattleContext.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FBattleContext.InnerSingleton, Z_Construct_UScriptStruct_FBattleContext_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FBattleContext.InnerSingleton;
}
// ********** End ScriptStruct FBattleContext ******************************************************

// ********** Begin Delegate FOnBattleSequenceStarted **********************************************
struct Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceStarted__DelegateSignature_Statics
{
	struct BattleSequenceComponent_eventOnBattleSequenceStarted_Parms
	{
		EBattleSequenceType BattleType;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Events\n" },
#endif
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Events" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_BattleType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_BattleType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceStarted__DelegateSignature_Statics::NewProp_BattleType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceStarted__DelegateSignature_Statics::NewProp_BattleType = { "BattleType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BattleSequenceComponent_eventOnBattleSequenceStarted_Parms, BattleType), Z_Construct_UEnum_IronChess_EBattleSequenceType, METADATA_PARAMS(0, nullptr) }; // 2870919168
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceStarted__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceStarted__DelegateSignature_Statics::NewProp_BattleType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceStarted__DelegateSignature_Statics::NewProp_BattleType,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceStarted__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceStarted__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBattleSequenceComponent, nullptr, "OnBattleSequenceStarted__DelegateSignature", Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceStarted__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceStarted__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceStarted__DelegateSignature_Statics::BattleSequenceComponent_eventOnBattleSequenceStarted_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceStarted__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceStarted__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceStarted__DelegateSignature_Statics::BattleSequenceComponent_eventOnBattleSequenceStarted_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceStarted__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceStarted__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void UBattleSequenceComponent::FOnBattleSequenceStarted_DelegateWrapper(const FMulticastScriptDelegate& OnBattleSequenceStarted, EBattleSequenceType BattleType)
{
	struct BattleSequenceComponent_eventOnBattleSequenceStarted_Parms
	{
		EBattleSequenceType BattleType;
	};
	BattleSequenceComponent_eventOnBattleSequenceStarted_Parms Parms;
	Parms.BattleType=BattleType;
	OnBattleSequenceStarted.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnBattleSequenceStarted ************************************************

// ********** Begin Delegate FOnBattleSequenceFinished *********************************************
struct Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceFinished__DelegateSignature_Statics
{
	struct BattleSequenceComponent_eventOnBattleSequenceFinished_Parms
	{
		EBattleSequenceType BattleType;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_BattleType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_BattleType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceFinished__DelegateSignature_Statics::NewProp_BattleType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceFinished__DelegateSignature_Statics::NewProp_BattleType = { "BattleType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BattleSequenceComponent_eventOnBattleSequenceFinished_Parms, BattleType), Z_Construct_UEnum_IronChess_EBattleSequenceType, METADATA_PARAMS(0, nullptr) }; // 2870919168
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceFinished__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceFinished__DelegateSignature_Statics::NewProp_BattleType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceFinished__DelegateSignature_Statics::NewProp_BattleType,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceFinished__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceFinished__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBattleSequenceComponent, nullptr, "OnBattleSequenceFinished__DelegateSignature", Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceFinished__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceFinished__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceFinished__DelegateSignature_Statics::BattleSequenceComponent_eventOnBattleSequenceFinished_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceFinished__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceFinished__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceFinished__DelegateSignature_Statics::BattleSequenceComponent_eventOnBattleSequenceFinished_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceFinished__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceFinished__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void UBattleSequenceComponent::FOnBattleSequenceFinished_DelegateWrapper(const FMulticastScriptDelegate& OnBattleSequenceFinished, EBattleSequenceType BattleType)
{
	struct BattleSequenceComponent_eventOnBattleSequenceFinished_Parms
	{
		EBattleSequenceType BattleType;
	};
	BattleSequenceComponent_eventOnBattleSequenceFinished_Parms Parms;
	Parms.BattleType=BattleType;
	OnBattleSequenceFinished.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnBattleSequenceFinished ***********************************************

// ********** Begin Delegate FOnBattleSequenceProgress *********************************************
struct Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceProgress__DelegateSignature_Statics
{
	struct BattleSequenceComponent_eventOnBattleSequenceProgress_Parms
	{
		EBattleSequenceType BattleType;
		float Progress;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_BattleType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_BattleType;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Progress;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceProgress__DelegateSignature_Statics::NewProp_BattleType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceProgress__DelegateSignature_Statics::NewProp_BattleType = { "BattleType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BattleSequenceComponent_eventOnBattleSequenceProgress_Parms, BattleType), Z_Construct_UEnum_IronChess_EBattleSequenceType, METADATA_PARAMS(0, nullptr) }; // 2870919168
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceProgress__DelegateSignature_Statics::NewProp_Progress = { "Progress", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BattleSequenceComponent_eventOnBattleSequenceProgress_Parms, Progress), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceProgress__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceProgress__DelegateSignature_Statics::NewProp_BattleType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceProgress__DelegateSignature_Statics::NewProp_BattleType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceProgress__DelegateSignature_Statics::NewProp_Progress,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceProgress__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceProgress__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBattleSequenceComponent, nullptr, "OnBattleSequenceProgress__DelegateSignature", Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceProgress__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceProgress__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceProgress__DelegateSignature_Statics::BattleSequenceComponent_eventOnBattleSequenceProgress_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceProgress__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceProgress__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceProgress__DelegateSignature_Statics::BattleSequenceComponent_eventOnBattleSequenceProgress_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceProgress__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceProgress__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void UBattleSequenceComponent::FOnBattleSequenceProgress_DelegateWrapper(const FMulticastScriptDelegate& OnBattleSequenceProgress, EBattleSequenceType BattleType, float Progress)
{
	struct BattleSequenceComponent_eventOnBattleSequenceProgress_Parms
	{
		EBattleSequenceType BattleType;
		float Progress;
	};
	BattleSequenceComponent_eventOnBattleSequenceProgress_Parms Parms;
	Parms.BattleType=BattleType;
	Parms.Progress=Progress;
	OnBattleSequenceProgress.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnBattleSequenceProgress ***********************************************

// ********** Begin Class UBattleSequenceComponent Function DetermineBattleType ********************
struct Z_Construct_UFunction_UBattleSequenceComponent_DetermineBattleType_Statics
{
	struct BattleSequenceComponent_eventDetermineBattleType_Parms
	{
		FBattleContext Context;
		EBattleSequenceType ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Battle Sequence" },
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBattleSequenceComponent_DetermineBattleType_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BattleSequenceComponent_eventDetermineBattleType_Parms, Context), Z_Construct_UScriptStruct_FBattleContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Context_MetaData), NewProp_Context_MetaData) }; // 1079302706
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UBattleSequenceComponent_DetermineBattleType_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UBattleSequenceComponent_DetermineBattleType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BattleSequenceComponent_eventDetermineBattleType_Parms, ReturnValue), Z_Construct_UEnum_IronChess_EBattleSequenceType, METADATA_PARAMS(0, nullptr) }; // 2870919168
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBattleSequenceComponent_DetermineBattleType_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBattleSequenceComponent_DetermineBattleType_Statics::NewProp_Context,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBattleSequenceComponent_DetermineBattleType_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBattleSequenceComponent_DetermineBattleType_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBattleSequenceComponent_DetermineBattleType_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBattleSequenceComponent_DetermineBattleType_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBattleSequenceComponent, nullptr, "DetermineBattleType", Z_Construct_UFunction_UBattleSequenceComponent_DetermineBattleType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UBattleSequenceComponent_DetermineBattleType_Statics::PropPointers), sizeof(Z_Construct_UFunction_UBattleSequenceComponent_DetermineBattleType_Statics::BattleSequenceComponent_eventDetermineBattleType_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBattleSequenceComponent_DetermineBattleType_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBattleSequenceComponent_DetermineBattleType_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBattleSequenceComponent_DetermineBattleType_Statics::BattleSequenceComponent_eventDetermineBattleType_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBattleSequenceComponent_DetermineBattleType()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBattleSequenceComponent_DetermineBattleType_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBattleSequenceComponent::execDetermineBattleType)
{
	P_GET_STRUCT_REF(FBattleContext,Z_Param_Out_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EBattleSequenceType*)Z_Param__Result=P_THIS->DetermineBattleType(Z_Param_Out_Context);
	P_NATIVE_END;
}
// ********** End Class UBattleSequenceComponent Function DetermineBattleType **********************

// ********** Begin Class UBattleSequenceComponent Function GetBattleConfig ************************
struct Z_Construct_UFunction_UBattleSequenceComponent_GetBattleConfig_Statics
{
	struct BattleSequenceComponent_eventGetBattleConfig_Parms
	{
		EBattleSequenceType Type;
		FBattleSequenceConfig ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Battle Sequence" },
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_Type_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Type;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UBattleSequenceComponent_GetBattleConfig_Statics::NewProp_Type_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UBattleSequenceComponent_GetBattleConfig_Statics::NewProp_Type = { "Type", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BattleSequenceComponent_eventGetBattleConfig_Parms, Type), Z_Construct_UEnum_IronChess_EBattleSequenceType, METADATA_PARAMS(0, nullptr) }; // 2870919168
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBattleSequenceComponent_GetBattleConfig_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BattleSequenceComponent_eventGetBattleConfig_Parms, ReturnValue), Z_Construct_UScriptStruct_FBattleSequenceConfig, METADATA_PARAMS(0, nullptr) }; // 1240726401
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBattleSequenceComponent_GetBattleConfig_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBattleSequenceComponent_GetBattleConfig_Statics::NewProp_Type_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBattleSequenceComponent_GetBattleConfig_Statics::NewProp_Type,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBattleSequenceComponent_GetBattleConfig_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBattleSequenceComponent_GetBattleConfig_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBattleSequenceComponent_GetBattleConfig_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBattleSequenceComponent, nullptr, "GetBattleConfig", Z_Construct_UFunction_UBattleSequenceComponent_GetBattleConfig_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UBattleSequenceComponent_GetBattleConfig_Statics::PropPointers), sizeof(Z_Construct_UFunction_UBattleSequenceComponent_GetBattleConfig_Statics::BattleSequenceComponent_eventGetBattleConfig_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBattleSequenceComponent_GetBattleConfig_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBattleSequenceComponent_GetBattleConfig_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBattleSequenceComponent_GetBattleConfig_Statics::BattleSequenceComponent_eventGetBattleConfig_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBattleSequenceComponent_GetBattleConfig()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBattleSequenceComponent_GetBattleConfig_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBattleSequenceComponent::execGetBattleConfig)
{
	P_GET_ENUM(EBattleSequenceType,Z_Param_Type);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FBattleSequenceConfig*)Z_Param__Result=P_THIS->GetBattleConfig(EBattleSequenceType(Z_Param_Type));
	P_NATIVE_END;
}
// ********** End Class UBattleSequenceComponent Function GetBattleConfig **************************

// ********** Begin Class UBattleSequenceComponent Function GetBattleFrequency *********************
struct Z_Construct_UFunction_UBattleSequenceComponent_GetBattleFrequency_Statics
{
	struct BattleSequenceComponent_eventGetBattleFrequency_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Battle Sequence" },
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBattleSequenceComponent_GetBattleFrequency_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BattleSequenceComponent_eventGetBattleFrequency_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBattleSequenceComponent_GetBattleFrequency_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBattleSequenceComponent_GetBattleFrequency_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBattleSequenceComponent_GetBattleFrequency_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBattleSequenceComponent_GetBattleFrequency_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBattleSequenceComponent, nullptr, "GetBattleFrequency", Z_Construct_UFunction_UBattleSequenceComponent_GetBattleFrequency_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UBattleSequenceComponent_GetBattleFrequency_Statics::PropPointers), sizeof(Z_Construct_UFunction_UBattleSequenceComponent_GetBattleFrequency_Statics::BattleSequenceComponent_eventGetBattleFrequency_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBattleSequenceComponent_GetBattleFrequency_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBattleSequenceComponent_GetBattleFrequency_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBattleSequenceComponent_GetBattleFrequency_Statics::BattleSequenceComponent_eventGetBattleFrequency_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBattleSequenceComponent_GetBattleFrequency()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBattleSequenceComponent_GetBattleFrequency_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBattleSequenceComponent::execGetBattleFrequency)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetBattleFrequency();
	P_NATIVE_END;
}
// ********** End Class UBattleSequenceComponent Function GetBattleFrequency ***********************

// ********** Begin Class UBattleSequenceComponent Function GetCurrentBattleProgress ***************
struct Z_Construct_UFunction_UBattleSequenceComponent_GetCurrentBattleProgress_Statics
{
	struct BattleSequenceComponent_eventGetCurrentBattleProgress_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Battle Sequence" },
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UBattleSequenceComponent_GetCurrentBattleProgress_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BattleSequenceComponent_eventGetCurrentBattleProgress_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBattleSequenceComponent_GetCurrentBattleProgress_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBattleSequenceComponent_GetCurrentBattleProgress_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBattleSequenceComponent_GetCurrentBattleProgress_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBattleSequenceComponent_GetCurrentBattleProgress_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBattleSequenceComponent, nullptr, "GetCurrentBattleProgress", Z_Construct_UFunction_UBattleSequenceComponent_GetCurrentBattleProgress_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UBattleSequenceComponent_GetCurrentBattleProgress_Statics::PropPointers), sizeof(Z_Construct_UFunction_UBattleSequenceComponent_GetCurrentBattleProgress_Statics::BattleSequenceComponent_eventGetCurrentBattleProgress_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBattleSequenceComponent_GetCurrentBattleProgress_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBattleSequenceComponent_GetCurrentBattleProgress_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBattleSequenceComponent_GetCurrentBattleProgress_Statics::BattleSequenceComponent_eventGetCurrentBattleProgress_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBattleSequenceComponent_GetCurrentBattleProgress()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBattleSequenceComponent_GetCurrentBattleProgress_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBattleSequenceComponent::execGetCurrentBattleProgress)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetCurrentBattleProgress();
	P_NATIVE_END;
}
// ********** End Class UBattleSequenceComponent Function GetCurrentBattleProgress *****************

// ********** Begin Class UBattleSequenceComponent Function IsPlayingBattleSequence ****************
struct Z_Construct_UFunction_UBattleSequenceComponent_IsPlayingBattleSequence_Statics
{
	struct BattleSequenceComponent_eventIsPlayingBattleSequence_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Battle Sequence" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// State Queries\n" },
#endif
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "State Queries" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UBattleSequenceComponent_IsPlayingBattleSequence_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BattleSequenceComponent_eventIsPlayingBattleSequence_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBattleSequenceComponent_IsPlayingBattleSequence_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BattleSequenceComponent_eventIsPlayingBattleSequence_Parms), &Z_Construct_UFunction_UBattleSequenceComponent_IsPlayingBattleSequence_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBattleSequenceComponent_IsPlayingBattleSequence_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBattleSequenceComponent_IsPlayingBattleSequence_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBattleSequenceComponent_IsPlayingBattleSequence_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBattleSequenceComponent_IsPlayingBattleSequence_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBattleSequenceComponent, nullptr, "IsPlayingBattleSequence", Z_Construct_UFunction_UBattleSequenceComponent_IsPlayingBattleSequence_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UBattleSequenceComponent_IsPlayingBattleSequence_Statics::PropPointers), sizeof(Z_Construct_UFunction_UBattleSequenceComponent_IsPlayingBattleSequence_Statics::BattleSequenceComponent_eventIsPlayingBattleSequence_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBattleSequenceComponent_IsPlayingBattleSequence_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBattleSequenceComponent_IsPlayingBattleSequence_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBattleSequenceComponent_IsPlayingBattleSequence_Statics::BattleSequenceComponent_eventIsPlayingBattleSequence_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBattleSequenceComponent_IsPlayingBattleSequence()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBattleSequenceComponent_IsPlayingBattleSequence_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBattleSequenceComponent::execIsPlayingBattleSequence)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsPlayingBattleSequence();
	P_NATIVE_END;
}
// ********** End Class UBattleSequenceComponent Function IsPlayingBattleSequence ******************

// ********** Begin Class UBattleSequenceComponent Function SetBattleConfig ************************
struct Z_Construct_UFunction_UBattleSequenceComponent_SetBattleConfig_Statics
{
	struct BattleSequenceComponent_eventSetBattleConfig_Parms
	{
		EBattleSequenceType Type;
		FBattleSequenceConfig Config;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Battle Sequence" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Configuration\n" },
#endif
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Configuration" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Config_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_Type_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Type;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Config;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UBattleSequenceComponent_SetBattleConfig_Statics::NewProp_Type_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UBattleSequenceComponent_SetBattleConfig_Statics::NewProp_Type = { "Type", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BattleSequenceComponent_eventSetBattleConfig_Parms, Type), Z_Construct_UEnum_IronChess_EBattleSequenceType, METADATA_PARAMS(0, nullptr) }; // 2870919168
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBattleSequenceComponent_SetBattleConfig_Statics::NewProp_Config = { "Config", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BattleSequenceComponent_eventSetBattleConfig_Parms, Config), Z_Construct_UScriptStruct_FBattleSequenceConfig, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Config_MetaData), NewProp_Config_MetaData) }; // 1240726401
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBattleSequenceComponent_SetBattleConfig_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBattleSequenceComponent_SetBattleConfig_Statics::NewProp_Type_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBattleSequenceComponent_SetBattleConfig_Statics::NewProp_Type,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBattleSequenceComponent_SetBattleConfig_Statics::NewProp_Config,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBattleSequenceComponent_SetBattleConfig_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBattleSequenceComponent_SetBattleConfig_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBattleSequenceComponent, nullptr, "SetBattleConfig", Z_Construct_UFunction_UBattleSequenceComponent_SetBattleConfig_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UBattleSequenceComponent_SetBattleConfig_Statics::PropPointers), sizeof(Z_Construct_UFunction_UBattleSequenceComponent_SetBattleConfig_Statics::BattleSequenceComponent_eventSetBattleConfig_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBattleSequenceComponent_SetBattleConfig_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBattleSequenceComponent_SetBattleConfig_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBattleSequenceComponent_SetBattleConfig_Statics::BattleSequenceComponent_eventSetBattleConfig_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBattleSequenceComponent_SetBattleConfig()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBattleSequenceComponent_SetBattleConfig_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBattleSequenceComponent::execSetBattleConfig)
{
	P_GET_ENUM(EBattleSequenceType,Z_Param_Type);
	P_GET_STRUCT_REF(FBattleSequenceConfig,Z_Param_Out_Config);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetBattleConfig(EBattleSequenceType(Z_Param_Type),Z_Param_Out_Config);
	P_NATIVE_END;
}
// ********** End Class UBattleSequenceComponent Function SetBattleConfig **************************

// ********** Begin Class UBattleSequenceComponent Function SetBattleFrequency *********************
struct Z_Construct_UFunction_UBattleSequenceComponent_SetBattleFrequency_Statics
{
	struct BattleSequenceComponent_eventSetBattleFrequency_Parms
	{
		int32 MovesPerBattle;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Battle Sequence" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Battle Frequency Control\n" },
#endif
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Battle Frequency Control" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_MovesPerBattle;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBattleSequenceComponent_SetBattleFrequency_Statics::NewProp_MovesPerBattle = { "MovesPerBattle", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BattleSequenceComponent_eventSetBattleFrequency_Parms, MovesPerBattle), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBattleSequenceComponent_SetBattleFrequency_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBattleSequenceComponent_SetBattleFrequency_Statics::NewProp_MovesPerBattle,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBattleSequenceComponent_SetBattleFrequency_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBattleSequenceComponent_SetBattleFrequency_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBattleSequenceComponent, nullptr, "SetBattleFrequency", Z_Construct_UFunction_UBattleSequenceComponent_SetBattleFrequency_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UBattleSequenceComponent_SetBattleFrequency_Statics::PropPointers), sizeof(Z_Construct_UFunction_UBattleSequenceComponent_SetBattleFrequency_Statics::BattleSequenceComponent_eventSetBattleFrequency_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBattleSequenceComponent_SetBattleFrequency_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBattleSequenceComponent_SetBattleFrequency_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBattleSequenceComponent_SetBattleFrequency_Statics::BattleSequenceComponent_eventSetBattleFrequency_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBattleSequenceComponent_SetBattleFrequency()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBattleSequenceComponent_SetBattleFrequency_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBattleSequenceComponent::execSetBattleFrequency)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_MovesPerBattle);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetBattleFrequency(Z_Param_MovesPerBattle);
	P_NATIVE_END;
}
// ********** End Class UBattleSequenceComponent Function SetBattleFrequency ***********************

// ********** Begin Class UBattleSequenceComponent Function ShouldTriggerBattle ********************
struct Z_Construct_UFunction_UBattleSequenceComponent_ShouldTriggerBattle_Statics
{
	struct BattleSequenceComponent_eventShouldTriggerBattle_Parms
	{
		FChessMove Move;
		int32 MovesSinceLastBattle;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Battle Sequence" },
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Move_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Move;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MovesSinceLastBattle;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBattleSequenceComponent_ShouldTriggerBattle_Statics::NewProp_Move = { "Move", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BattleSequenceComponent_eventShouldTriggerBattle_Parms, Move), Z_Construct_UScriptStruct_FChessMove, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Move_MetaData), NewProp_Move_MetaData) }; // 1361898884
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBattleSequenceComponent_ShouldTriggerBattle_Statics::NewProp_MovesSinceLastBattle = { "MovesSinceLastBattle", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BattleSequenceComponent_eventShouldTriggerBattle_Parms, MovesSinceLastBattle), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBattleSequenceComponent_ShouldTriggerBattle_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BattleSequenceComponent_eventShouldTriggerBattle_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBattleSequenceComponent_ShouldTriggerBattle_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BattleSequenceComponent_eventShouldTriggerBattle_Parms), &Z_Construct_UFunction_UBattleSequenceComponent_ShouldTriggerBattle_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBattleSequenceComponent_ShouldTriggerBattle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBattleSequenceComponent_ShouldTriggerBattle_Statics::NewProp_Move,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBattleSequenceComponent_ShouldTriggerBattle_Statics::NewProp_MovesSinceLastBattle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBattleSequenceComponent_ShouldTriggerBattle_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBattleSequenceComponent_ShouldTriggerBattle_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBattleSequenceComponent_ShouldTriggerBattle_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBattleSequenceComponent, nullptr, "ShouldTriggerBattle", Z_Construct_UFunction_UBattleSequenceComponent_ShouldTriggerBattle_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UBattleSequenceComponent_ShouldTriggerBattle_Statics::PropPointers), sizeof(Z_Construct_UFunction_UBattleSequenceComponent_ShouldTriggerBattle_Statics::BattleSequenceComponent_eventShouldTriggerBattle_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBattleSequenceComponent_ShouldTriggerBattle_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBattleSequenceComponent_ShouldTriggerBattle_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBattleSequenceComponent_ShouldTriggerBattle_Statics::BattleSequenceComponent_eventShouldTriggerBattle_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBattleSequenceComponent_ShouldTriggerBattle()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBattleSequenceComponent_ShouldTriggerBattle_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBattleSequenceComponent::execShouldTriggerBattle)
{
	P_GET_STRUCT_REF(FChessMove,Z_Param_Out_Move);
	P_GET_PROPERTY(FIntProperty,Z_Param_MovesSinceLastBattle);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ShouldTriggerBattle(Z_Param_Out_Move,Z_Param_MovesSinceLastBattle);
	P_NATIVE_END;
}
// ********** End Class UBattleSequenceComponent Function ShouldTriggerBattle **********************

// ********** Begin Class UBattleSequenceComponent Function StopCurrentBattle **********************
struct Z_Construct_UFunction_UBattleSequenceComponent_StopCurrentBattle_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Battle Sequence" },
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBattleSequenceComponent_StopCurrentBattle_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBattleSequenceComponent, nullptr, "StopCurrentBattle", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBattleSequenceComponent_StopCurrentBattle_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBattleSequenceComponent_StopCurrentBattle_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UBattleSequenceComponent_StopCurrentBattle()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBattleSequenceComponent_StopCurrentBattle_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBattleSequenceComponent::execStopCurrentBattle)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StopCurrentBattle();
	P_NATIVE_END;
}
// ********** End Class UBattleSequenceComponent Function StopCurrentBattle ************************

// ********** Begin Class UBattleSequenceComponent Function TriggerBattleSequence ******************
struct Z_Construct_UFunction_UBattleSequenceComponent_TriggerBattleSequence_Statics
{
	struct BattleSequenceComponent_eventTriggerBattleSequence_Parms
	{
		FBattleContext Context;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Battle Sequence" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Battle Sequence Management\n" },
#endif
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Battle Sequence Management" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBattleSequenceComponent_TriggerBattleSequence_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BattleSequenceComponent_eventTriggerBattleSequence_Parms, Context), Z_Construct_UScriptStruct_FBattleContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Context_MetaData), NewProp_Context_MetaData) }; // 1079302706
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBattleSequenceComponent_TriggerBattleSequence_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBattleSequenceComponent_TriggerBattleSequence_Statics::NewProp_Context,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBattleSequenceComponent_TriggerBattleSequence_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBattleSequenceComponent_TriggerBattleSequence_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBattleSequenceComponent, nullptr, "TriggerBattleSequence", Z_Construct_UFunction_UBattleSequenceComponent_TriggerBattleSequence_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UBattleSequenceComponent_TriggerBattleSequence_Statics::PropPointers), sizeof(Z_Construct_UFunction_UBattleSequenceComponent_TriggerBattleSequence_Statics::BattleSequenceComponent_eventTriggerBattleSequence_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBattleSequenceComponent_TriggerBattleSequence_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBattleSequenceComponent_TriggerBattleSequence_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBattleSequenceComponent_TriggerBattleSequence_Statics::BattleSequenceComponent_eventTriggerBattleSequence_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBattleSequenceComponent_TriggerBattleSequence()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBattleSequenceComponent_TriggerBattleSequence_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBattleSequenceComponent::execTriggerBattleSequence)
{
	P_GET_STRUCT_REF(FBattleContext,Z_Param_Out_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->TriggerBattleSequence(Z_Param_Out_Context);
	P_NATIVE_END;
}
// ********** End Class UBattleSequenceComponent Function TriggerBattleSequence ********************

// ********** Begin Class UBattleSequenceComponent *************************************************
void UBattleSequenceComponent::StaticRegisterNativesUBattleSequenceComponent()
{
	UClass* Class = UBattleSequenceComponent::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "DetermineBattleType", &UBattleSequenceComponent::execDetermineBattleType },
		{ "GetBattleConfig", &UBattleSequenceComponent::execGetBattleConfig },
		{ "GetBattleFrequency", &UBattleSequenceComponent::execGetBattleFrequency },
		{ "GetCurrentBattleProgress", &UBattleSequenceComponent::execGetCurrentBattleProgress },
		{ "IsPlayingBattleSequence", &UBattleSequenceComponent::execIsPlayingBattleSequence },
		{ "SetBattleConfig", &UBattleSequenceComponent::execSetBattleConfig },
		{ "SetBattleFrequency", &UBattleSequenceComponent::execSetBattleFrequency },
		{ "ShouldTriggerBattle", &UBattleSequenceComponent::execShouldTriggerBattle },
		{ "StopCurrentBattle", &UBattleSequenceComponent::execStopCurrentBattle },
		{ "TriggerBattleSequence", &UBattleSequenceComponent::execTriggerBattleSequence },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UBattleSequenceComponent;
UClass* UBattleSequenceComponent::GetPrivateStaticClass()
{
	using TClass = UBattleSequenceComponent;
	if (!Z_Registration_Info_UClass_UBattleSequenceComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("BattleSequenceComponent"),
			Z_Registration_Info_UClass_UBattleSequenceComponent.InnerSingleton,
			StaticRegisterNativesUBattleSequenceComponent,
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
	return Z_Registration_Info_UClass_UBattleSequenceComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UBattleSequenceComponent_NoRegister()
{
	return UBattleSequenceComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UBattleSequenceComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "Custom" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Component responsible for triggering and managing battle sequences\n * Creates cinematic mini war-scenes every 3 moves and for special events\n */" },
#endif
		{ "HideCategories", "Trigger PhysicsVolume" },
		{ "IncludePath", "Animation/BattleSequenceComponent.h" },
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Component responsible for triggering and managing battle sequences\nCreates cinematic mini war-scenes every 3 moves and for special events" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnBattleSequenceStarted_MetaData[] = {
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnBattleSequenceFinished_MetaData[] = {
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnBattleSequenceProgress_MetaData[] = {
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BattleConfigs_MetaData[] = {
		{ "Category", "Battle Configs" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Battle sequence configurations\n" },
#endif
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Battle sequence configurations" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BattleFrequency_MetaData[] = {
		{ "Category", "Battle Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Timing settings\n" },
#endif
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Timing settings" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinBattleDuration_MetaData[] = {
		{ "Category", "Battle Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Trigger battle every N moves\n" },
#endif
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Trigger battle every N moves" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxBattleDuration_MetaData[] = {
		{ "Category", "Battle Settings" },
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoTriggerOnCaptures_MetaData[] = {
		{ "Category", "Battle Settings" },
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoTriggerOnCheck_MetaData[] = {
		{ "Category", "Battle Settings" },
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoTriggerOnSpecialMoves_MetaData[] = {
		{ "Category", "Battle Settings" },
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BattleCameraBlendTime_MetaData[] = {
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Camera settings for battles\n" },
#endif
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Camera settings for battles" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PredefinedCameraPositions_MetaData[] = {
		{ "Category", "Camera" },
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsPlayingBattle_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Current battle state\n" },
#endif
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current battle state" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentBattleType_MetaData[] = {
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentBattleTime_MetaData[] = {
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentBattleDuration_MetaData[] = {
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentSequencePlayer_MetaData[] = {
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActiveParticleEffects_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActiveSoundEffects_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Animation/BattleSequenceComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnBattleSequenceStarted;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnBattleSequenceFinished;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnBattleSequenceProgress;
	static const UECodeGen_Private::FStructPropertyParams NewProp_BattleConfigs_ValueProp;
	static const UECodeGen_Private::FBytePropertyParams NewProp_BattleConfigs_Key_KeyProp_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_BattleConfigs_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_BattleConfigs;
	static const UECodeGen_Private::FIntPropertyParams NewProp_BattleFrequency;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinBattleDuration;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxBattleDuration;
	static void NewProp_bAutoTriggerOnCaptures_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoTriggerOnCaptures;
	static void NewProp_bAutoTriggerOnCheck_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoTriggerOnCheck;
	static void NewProp_bAutoTriggerOnSpecialMoves_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoTriggerOnSpecialMoves;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BattleCameraBlendTime;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PredefinedCameraPositions_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_PredefinedCameraPositions;
	static void NewProp_bIsPlayingBattle_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsPlayingBattle;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CurrentBattleType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CurrentBattleType;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentBattleTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentBattleDuration;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentSequencePlayer;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ActiveParticleEffects_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ActiveParticleEffects;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ActiveSoundEffects_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ActiveSoundEffects;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UBattleSequenceComponent_DetermineBattleType, "DetermineBattleType" }, // 1051366014
		{ &Z_Construct_UFunction_UBattleSequenceComponent_GetBattleConfig, "GetBattleConfig" }, // 3223172323
		{ &Z_Construct_UFunction_UBattleSequenceComponent_GetBattleFrequency, "GetBattleFrequency" }, // 554537571
		{ &Z_Construct_UFunction_UBattleSequenceComponent_GetCurrentBattleProgress, "GetCurrentBattleProgress" }, // 975326470
		{ &Z_Construct_UFunction_UBattleSequenceComponent_IsPlayingBattleSequence, "IsPlayingBattleSequence" }, // 1732908189
		{ &Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceFinished__DelegateSignature, "OnBattleSequenceFinished__DelegateSignature" }, // 2676186244
		{ &Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceProgress__DelegateSignature, "OnBattleSequenceProgress__DelegateSignature" }, // 3691295281
		{ &Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceStarted__DelegateSignature, "OnBattleSequenceStarted__DelegateSignature" }, // 948865276
		{ &Z_Construct_UFunction_UBattleSequenceComponent_SetBattleConfig, "SetBattleConfig" }, // 4034797445
		{ &Z_Construct_UFunction_UBattleSequenceComponent_SetBattleFrequency, "SetBattleFrequency" }, // 1186766394
		{ &Z_Construct_UFunction_UBattleSequenceComponent_ShouldTriggerBattle, "ShouldTriggerBattle" }, // 1077484234
		{ &Z_Construct_UFunction_UBattleSequenceComponent_StopCurrentBattle, "StopCurrentBattle" }, // 3606141622
		{ &Z_Construct_UFunction_UBattleSequenceComponent_TriggerBattleSequence, "TriggerBattleSequence" }, // 917125023
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBattleSequenceComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_OnBattleSequenceStarted = { "OnBattleSequenceStarted", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBattleSequenceComponent, OnBattleSequenceStarted), Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceStarted__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnBattleSequenceStarted_MetaData), NewProp_OnBattleSequenceStarted_MetaData) }; // 948865276
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_OnBattleSequenceFinished = { "OnBattleSequenceFinished", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBattleSequenceComponent, OnBattleSequenceFinished), Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceFinished__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnBattleSequenceFinished_MetaData), NewProp_OnBattleSequenceFinished_MetaData) }; // 2676186244
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_OnBattleSequenceProgress = { "OnBattleSequenceProgress", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBattleSequenceComponent, OnBattleSequenceProgress), Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceProgress__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnBattleSequenceProgress_MetaData), NewProp_OnBattleSequenceProgress_MetaData) }; // 3691295281
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_BattleConfigs_ValueProp = { "BattleConfigs", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FBattleSequenceConfig, METADATA_PARAMS(0, nullptr) }; // 1240726401
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_BattleConfigs_Key_KeyProp_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_BattleConfigs_Key_KeyProp = { "BattleConfigs_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_IronChess_EBattleSequenceType, METADATA_PARAMS(0, nullptr) }; // 2870919168
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_BattleConfigs = { "BattleConfigs", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBattleSequenceComponent, BattleConfigs), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BattleConfigs_MetaData), NewProp_BattleConfigs_MetaData) }; // 2870919168 1240726401
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_BattleFrequency = { "BattleFrequency", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBattleSequenceComponent, BattleFrequency), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BattleFrequency_MetaData), NewProp_BattleFrequency_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_MinBattleDuration = { "MinBattleDuration", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBattleSequenceComponent, MinBattleDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinBattleDuration_MetaData), NewProp_MinBattleDuration_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_MaxBattleDuration = { "MaxBattleDuration", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBattleSequenceComponent, MaxBattleDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxBattleDuration_MetaData), NewProp_MaxBattleDuration_MetaData) };
void Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_bAutoTriggerOnCaptures_SetBit(void* Obj)
{
	((UBattleSequenceComponent*)Obj)->bAutoTriggerOnCaptures = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_bAutoTriggerOnCaptures = { "bAutoTriggerOnCaptures", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UBattleSequenceComponent), &Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_bAutoTriggerOnCaptures_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoTriggerOnCaptures_MetaData), NewProp_bAutoTriggerOnCaptures_MetaData) };
void Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_bAutoTriggerOnCheck_SetBit(void* Obj)
{
	((UBattleSequenceComponent*)Obj)->bAutoTriggerOnCheck = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_bAutoTriggerOnCheck = { "bAutoTriggerOnCheck", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UBattleSequenceComponent), &Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_bAutoTriggerOnCheck_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoTriggerOnCheck_MetaData), NewProp_bAutoTriggerOnCheck_MetaData) };
void Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_bAutoTriggerOnSpecialMoves_SetBit(void* Obj)
{
	((UBattleSequenceComponent*)Obj)->bAutoTriggerOnSpecialMoves = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_bAutoTriggerOnSpecialMoves = { "bAutoTriggerOnSpecialMoves", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UBattleSequenceComponent), &Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_bAutoTriggerOnSpecialMoves_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoTriggerOnSpecialMoves_MetaData), NewProp_bAutoTriggerOnSpecialMoves_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_BattleCameraBlendTime = { "BattleCameraBlendTime", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBattleSequenceComponent, BattleCameraBlendTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BattleCameraBlendTime_MetaData), NewProp_BattleCameraBlendTime_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_PredefinedCameraPositions_Inner = { "PredefinedCameraPositions", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_PredefinedCameraPositions = { "PredefinedCameraPositions", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBattleSequenceComponent, PredefinedCameraPositions), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PredefinedCameraPositions_MetaData), NewProp_PredefinedCameraPositions_MetaData) };
void Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_bIsPlayingBattle_SetBit(void* Obj)
{
	((UBattleSequenceComponent*)Obj)->bIsPlayingBattle = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_bIsPlayingBattle = { "bIsPlayingBattle", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UBattleSequenceComponent), &Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_bIsPlayingBattle_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsPlayingBattle_MetaData), NewProp_bIsPlayingBattle_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_CurrentBattleType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_CurrentBattleType = { "CurrentBattleType", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBattleSequenceComponent, CurrentBattleType), Z_Construct_UEnum_IronChess_EBattleSequenceType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentBattleType_MetaData), NewProp_CurrentBattleType_MetaData) }; // 2870919168
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_CurrentBattleTime = { "CurrentBattleTime", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBattleSequenceComponent, CurrentBattleTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentBattleTime_MetaData), NewProp_CurrentBattleTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_CurrentBattleDuration = { "CurrentBattleDuration", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBattleSequenceComponent, CurrentBattleDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentBattleDuration_MetaData), NewProp_CurrentBattleDuration_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_CurrentSequencePlayer = { "CurrentSequencePlayer", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBattleSequenceComponent, CurrentSequencePlayer), Z_Construct_UClass_ULevelSequencePlayer_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentSequencePlayer_MetaData), NewProp_CurrentSequencePlayer_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_ActiveParticleEffects_Inner = { "ActiveParticleEffects", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UNiagaraComponent_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_ActiveParticleEffects = { "ActiveParticleEffects", nullptr, (EPropertyFlags)0x0040008000000008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBattleSequenceComponent, ActiveParticleEffects), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActiveParticleEffects_MetaData), NewProp_ActiveParticleEffects_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_ActiveSoundEffects_Inner = { "ActiveSoundEffects", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UAudioComponent_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_ActiveSoundEffects = { "ActiveSoundEffects", nullptr, (EPropertyFlags)0x0040008000000008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBattleSequenceComponent, ActiveSoundEffects), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActiveSoundEffects_MetaData), NewProp_ActiveSoundEffects_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UBattleSequenceComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_OnBattleSequenceStarted,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_OnBattleSequenceFinished,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_OnBattleSequenceProgress,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_BattleConfigs_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_BattleConfigs_Key_KeyProp_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_BattleConfigs_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_BattleConfigs,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_BattleFrequency,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_MinBattleDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_MaxBattleDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_bAutoTriggerOnCaptures,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_bAutoTriggerOnCheck,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_bAutoTriggerOnSpecialMoves,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_BattleCameraBlendTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_PredefinedCameraPositions_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_PredefinedCameraPositions,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_bIsPlayingBattle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_CurrentBattleType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_CurrentBattleType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_CurrentBattleTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_CurrentBattleDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_CurrentSequencePlayer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_ActiveParticleEffects_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_ActiveParticleEffects,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_ActiveSoundEffects_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBattleSequenceComponent_Statics::NewProp_ActiveSoundEffects,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBattleSequenceComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UBattleSequenceComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_USceneComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_IronChess,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBattleSequenceComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UBattleSequenceComponent_Statics::ClassParams = {
	&UBattleSequenceComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UBattleSequenceComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UBattleSequenceComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBattleSequenceComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UBattleSequenceComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UBattleSequenceComponent()
{
	if (!Z_Registration_Info_UClass_UBattleSequenceComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBattleSequenceComponent.OuterSingleton, Z_Construct_UClass_UBattleSequenceComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UBattleSequenceComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UBattleSequenceComponent);
UBattleSequenceComponent::~UBattleSequenceComponent() {}
// ********** End Class UBattleSequenceComponent ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Animation_BattleSequenceComponent_h__Script_IronChess_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EBattleSequenceType_StaticEnum, TEXT("EBattleSequenceType"), &Z_Registration_Info_UEnum_EBattleSequenceType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2870919168U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FBattleSequenceConfig::StaticStruct, Z_Construct_UScriptStruct_FBattleSequenceConfig_Statics::NewStructOps, TEXT("BattleSequenceConfig"), &Z_Registration_Info_UScriptStruct_FBattleSequenceConfig, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FBattleSequenceConfig), 1240726401U) },
		{ FBattleContext::StaticStruct, Z_Construct_UScriptStruct_FBattleContext_Statics::NewStructOps, TEXT("BattleContext"), &Z_Registration_Info_UScriptStruct_FBattleContext, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FBattleContext), 1079302706U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UBattleSequenceComponent, UBattleSequenceComponent::StaticClass, TEXT("UBattleSequenceComponent"), &Z_Registration_Info_UClass_UBattleSequenceComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBattleSequenceComponent), 4122313912U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Animation_BattleSequenceComponent_h__Script_IronChess_3328136748(TEXT("/Script/IronChess"),
	Z_CompiledInDeferFile_FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Animation_BattleSequenceComponent_h__Script_IronChess_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Animation_BattleSequenceComponent_h__Script_IronChess_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Animation_BattleSequenceComponent_h__Script_IronChess_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Animation_BattleSequenceComponent_h__Script_IronChess_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Animation_BattleSequenceComponent_h__Script_IronChess_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Animation_BattleSequenceComponent_h__Script_IronChess_Statics::EnumInfo));
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
