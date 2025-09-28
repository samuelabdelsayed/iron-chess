// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CinematicDirector.h"
#include "ChessTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeCinematicDirector() {}

// ********** Begin Cross Module References ********************************************************
CINEMATICCAMERA_API UClass* Z_Construct_UClass_ACineCameraActor_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UAudioComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USoundMix_NoRegister();
IRONCHESS_API UClass* Z_Construct_UClass_ACinematicDirector();
IRONCHESS_API UClass* Z_Construct_UClass_ACinematicDirector_NoRegister();
IRONCHESS_API UEnum* Z_Construct_UEnum_IronChess_ECinematicPhase();
IRONCHESS_API UEnum* Z_Construct_UEnum_IronChess_ENarrativeTheme();
IRONCHESS_API UEnum* Z_Construct_UEnum_IronChess_EPieceColor();
IRONCHESS_API UEnum* Z_Construct_UEnum_IronChess_EPieceType();
IRONCHESS_API UFunction* Z_Construct_UDelegateFunction_ACinematicDirector_OnCinematicFinished__DelegateSignature();
IRONCHESS_API UFunction* Z_Construct_UDelegateFunction_ACinematicDirector_OnCinematicStarted__DelegateSignature();
IRONCHESS_API UFunction* Z_Construct_UDelegateFunction_ACinematicDirector_OnNarrationSpoken__DelegateSignature();
IRONCHESS_API UFunction* Z_Construct_UDelegateFunction_ACinematicDirector_OnShotChanged__DelegateSignature();
IRONCHESS_API UScriptStruct* Z_Construct_UScriptStruct_FChessMove();
IRONCHESS_API UScriptStruct* Z_Construct_UScriptStruct_FCinematicSequence();
IRONCHESS_API UScriptStruct* Z_Construct_UScriptStruct_FCinematicShot();
IRONCHESS_API UScriptStruct* Z_Construct_UScriptStruct_FGameAnalysis();
LEVELSEQUENCE_API UClass* Z_Construct_UClass_ULevelSequencePlayer_NoRegister();
NIAGARA_API UClass* Z_Construct_UClass_UNiagaraSystem_NoRegister();
UPackage* Z_Construct_UPackage__Script_IronChess();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum ECinematicPhase ***********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ECinematicPhase;
static UEnum* ECinematicPhase_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ECinematicPhase.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ECinematicPhase.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_IronChess_ECinematicPhase, (UObject*)Z_Construct_UPackage__Script_IronChess(), TEXT("ECinematicPhase"));
	}
	return Z_Registration_Info_UEnum_ECinematicPhase.OuterSingleton;
}
template<> IRONCHESS_API UEnum* StaticEnum<ECinematicPhase>()
{
	return ECinematicPhase_StaticEnum();
}
struct Z_Construct_UEnum_IronChess_ECinematicPhase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Climax.Comment", "// Final phase\n" },
		{ "Climax.Name", "ECinematicPhase::Climax" },
		{ "Climax.ToolTip", "Final phase" },
		{ "EarlyGame.Comment", "// Game introduction\n" },
		{ "EarlyGame.Name", "ECinematicPhase::EarlyGame" },
		{ "EarlyGame.ToolTip", "Game introduction" },
		{ "EndGame.Comment", "// Main battle\n" },
		{ "EndGame.Name", "ECinematicPhase::EndGame" },
		{ "EndGame.ToolTip", "Main battle" },
		{ "Epilogue.Comment", "// Checkmate moment\n" },
		{ "Epilogue.Name", "ECinematicPhase::Epilogue" },
		{ "Epilogue.ToolTip", "Checkmate moment" },
		{ "MiddleGame.Comment", "// Opening moves\n" },
		{ "MiddleGame.Name", "ECinematicPhase::MiddleGame" },
		{ "MiddleGame.ToolTip", "Opening moves" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
		{ "Opening.Name", "ECinematicPhase::Opening" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ECinematicPhase::Opening", (int64)ECinematicPhase::Opening },
		{ "ECinematicPhase::EarlyGame", (int64)ECinematicPhase::EarlyGame },
		{ "ECinematicPhase::MiddleGame", (int64)ECinematicPhase::MiddleGame },
		{ "ECinematicPhase::EndGame", (int64)ECinematicPhase::EndGame },
		{ "ECinematicPhase::Climax", (int64)ECinematicPhase::Climax },
		{ "ECinematicPhase::Epilogue", (int64)ECinematicPhase::Epilogue },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_IronChess_ECinematicPhase_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_IronChess,
	nullptr,
	"ECinematicPhase",
	"ECinematicPhase",
	Z_Construct_UEnum_IronChess_ECinematicPhase_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_IronChess_ECinematicPhase_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_IronChess_ECinematicPhase_Statics::Enum_MetaDataParams), Z_Construct_UEnum_IronChess_ECinematicPhase_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_IronChess_ECinematicPhase()
{
	if (!Z_Registration_Info_UEnum_ECinematicPhase.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ECinematicPhase.InnerSingleton, Z_Construct_UEnum_IronChess_ECinematicPhase_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ECinematicPhase.InnerSingleton;
}
// ********** End Enum ECinematicPhase *************************************************************

// ********** Begin Enum ENarrativeTheme ***********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ENarrativeTheme;
static UEnum* ENarrativeTheme_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ENarrativeTheme.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ENarrativeTheme.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_IronChess_ENarrativeTheme, (UObject*)Z_Construct_UPackage__Script_IronChess(), TEXT("ENarrativeTheme"));
	}
	return Z_Registration_Info_UEnum_ENarrativeTheme.OuterSingleton;
}
template<> IRONCHESS_API UEnum* StaticEnum<ENarrativeTheme>()
{
	return ENarrativeTheme_StaticEnum();
}
struct Z_Construct_UEnum_IronChess_ENarrativeTheme_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "EpicBattle.Comment", "// Strategic masterpiece\n" },
		{ "EpicBattle.Name", "ENarrativeTheme::EpicBattle" },
		{ "EpicBattle.ToolTip", "Strategic masterpiece" },
		{ "HeroicVictory.Name", "ENarrativeTheme::HeroicVictory" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
		{ "Redemption.Comment", "// Heroic defeat\n" },
		{ "Redemption.Name", "ENarrativeTheme::Redemption" },
		{ "Redemption.ToolTip", "Heroic defeat" },
		{ "SwiftConquest.Comment", "// Back-and-forth struggle\n" },
		{ "SwiftConquest.Name", "ENarrativeTheme::SwiftConquest" },
		{ "SwiftConquest.ToolTip", "Back-and-forth struggle" },
		{ "TacticalGenius.Comment", "// Underdog triumph\n" },
		{ "TacticalGenius.Name", "ENarrativeTheme::TacticalGenius" },
		{ "TacticalGenius.ToolTip", "Underdog triumph" },
		{ "TragedyAndLoss.Comment", "// Dominant performance\n" },
		{ "TragedyAndLoss.Name", "ENarrativeTheme::TragedyAndLoss" },
		{ "TragedyAndLoss.ToolTip", "Dominant performance" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ENarrativeTheme::HeroicVictory", (int64)ENarrativeTheme::HeroicVictory },
		{ "ENarrativeTheme::TacticalGenius", (int64)ENarrativeTheme::TacticalGenius },
		{ "ENarrativeTheme::EpicBattle", (int64)ENarrativeTheme::EpicBattle },
		{ "ENarrativeTheme::SwiftConquest", (int64)ENarrativeTheme::SwiftConquest },
		{ "ENarrativeTheme::TragedyAndLoss", (int64)ENarrativeTheme::TragedyAndLoss },
		{ "ENarrativeTheme::Redemption", (int64)ENarrativeTheme::Redemption },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_IronChess_ENarrativeTheme_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_IronChess,
	nullptr,
	"ENarrativeTheme",
	"ENarrativeTheme",
	Z_Construct_UEnum_IronChess_ENarrativeTheme_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_IronChess_ENarrativeTheme_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_IronChess_ENarrativeTheme_Statics::Enum_MetaDataParams), Z_Construct_UEnum_IronChess_ENarrativeTheme_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_IronChess_ENarrativeTheme()
{
	if (!Z_Registration_Info_UEnum_ENarrativeTheme.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ENarrativeTheme.InnerSingleton, Z_Construct_UEnum_IronChess_ENarrativeTheme_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ENarrativeTheme.InnerSingleton;
}
// ********** End Enum ENarrativeTheme *************************************************************

// ********** Begin ScriptStruct FCinematicShot ****************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FCinematicShot;
class UScriptStruct* FCinematicShot::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FCinematicShot.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FCinematicShot.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FCinematicShot, (UObject*)Z_Construct_UPackage__Script_IronChess(), TEXT("CinematicShot"));
	}
	return Z_Registration_Info_UScriptStruct_FCinematicShot.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FCinematicShot_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShotName_MetaData[] = {
		{ "Category", "Shot" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Duration_MetaData[] = {
		{ "Category", "Shot" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraTransform_MetaData[] = {
		{ "Category", "Shot" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraFOV_MetaData[] = {
		{ "Category", "Shot" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FocusMoves_MetaData[] = {
		{ "Category", "Shot" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NarrationText_MetaData[] = {
		{ "Category", "Shot" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NarrationAudio_MetaData[] = {
		{ "Category", "Shot" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VisualEffects_MetaData[] = {
		{ "Category", "Shot" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowPieceHighlight_MetaData[] = {
		{ "Category", "Shot" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUseSlowMotion_MetaData[] = {
		{ "Category", "Shot" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ShotName;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Duration;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CameraTransform;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CameraFOV;
	static const UECodeGen_Private::FStructPropertyParams NewProp_FocusMoves_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_FocusMoves;
	static const UECodeGen_Private::FStrPropertyParams NewProp_NarrationText;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_NarrationAudio;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_VisualEffects_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_VisualEffects;
	static void NewProp_bShowPieceHighlight_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowPieceHighlight;
	static void NewProp_bUseSlowMotion_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseSlowMotion;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCinematicShot>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FCinematicShot_Statics::NewProp_ShotName = { "ShotName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCinematicShot, ShotName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShotName_MetaData), NewProp_ShotName_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCinematicShot_Statics::NewProp_Duration = { "Duration", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCinematicShot, Duration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Duration_MetaData), NewProp_Duration_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCinematicShot_Statics::NewProp_CameraTransform = { "CameraTransform", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCinematicShot, CameraTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraTransform_MetaData), NewProp_CameraTransform_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCinematicShot_Statics::NewProp_CameraFOV = { "CameraFOV", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCinematicShot, CameraFOV), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraFOV_MetaData), NewProp_CameraFOV_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCinematicShot_Statics::NewProp_FocusMoves_Inner = { "FocusMoves", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FChessMove, METADATA_PARAMS(0, nullptr) }; // 1361898884
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FCinematicShot_Statics::NewProp_FocusMoves = { "FocusMoves", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCinematicShot, FocusMoves), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FocusMoves_MetaData), NewProp_FocusMoves_MetaData) }; // 1361898884
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FCinematicShot_Statics::NewProp_NarrationText = { "NarrationText", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCinematicShot, NarrationText), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NarrationText_MetaData), NewProp_NarrationText_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FCinematicShot_Statics::NewProp_NarrationAudio = { "NarrationAudio", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCinematicShot, NarrationAudio), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NarrationAudio_MetaData), NewProp_NarrationAudio_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FCinematicShot_Statics::NewProp_VisualEffects_Inner = { "VisualEffects", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UNiagaraSystem_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FCinematicShot_Statics::NewProp_VisualEffects = { "VisualEffects", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCinematicShot, VisualEffects), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VisualEffects_MetaData), NewProp_VisualEffects_MetaData) };
void Z_Construct_UScriptStruct_FCinematicShot_Statics::NewProp_bShowPieceHighlight_SetBit(void* Obj)
{
	((FCinematicShot*)Obj)->bShowPieceHighlight = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FCinematicShot_Statics::NewProp_bShowPieceHighlight = { "bShowPieceHighlight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FCinematicShot), &Z_Construct_UScriptStruct_FCinematicShot_Statics::NewProp_bShowPieceHighlight_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowPieceHighlight_MetaData), NewProp_bShowPieceHighlight_MetaData) };
void Z_Construct_UScriptStruct_FCinematicShot_Statics::NewProp_bUseSlowMotion_SetBit(void* Obj)
{
	((FCinematicShot*)Obj)->bUseSlowMotion = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FCinematicShot_Statics::NewProp_bUseSlowMotion = { "bUseSlowMotion", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FCinematicShot), &Z_Construct_UScriptStruct_FCinematicShot_Statics::NewProp_bUseSlowMotion_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUseSlowMotion_MetaData), NewProp_bUseSlowMotion_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCinematicShot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCinematicShot_Statics::NewProp_ShotName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCinematicShot_Statics::NewProp_Duration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCinematicShot_Statics::NewProp_CameraTransform,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCinematicShot_Statics::NewProp_CameraFOV,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCinematicShot_Statics::NewProp_FocusMoves_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCinematicShot_Statics::NewProp_FocusMoves,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCinematicShot_Statics::NewProp_NarrationText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCinematicShot_Statics::NewProp_NarrationAudio,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCinematicShot_Statics::NewProp_VisualEffects_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCinematicShot_Statics::NewProp_VisualEffects,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCinematicShot_Statics::NewProp_bShowPieceHighlight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCinematicShot_Statics::NewProp_bUseSlowMotion,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCinematicShot_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCinematicShot_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_IronChess,
	nullptr,
	&NewStructOps,
	"CinematicShot",
	Z_Construct_UScriptStruct_FCinematicShot_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCinematicShot_Statics::PropPointers),
	sizeof(FCinematicShot),
	alignof(FCinematicShot),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCinematicShot_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FCinematicShot_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FCinematicShot()
{
	if (!Z_Registration_Info_UScriptStruct_FCinematicShot.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FCinematicShot.InnerSingleton, Z_Construct_UScriptStruct_FCinematicShot_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FCinematicShot.InnerSingleton;
}
// ********** End ScriptStruct FCinematicShot ******************************************************

// ********** Begin ScriptStruct FCinematicSequence ************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FCinematicSequence;
class UScriptStruct* FCinematicSequence::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FCinematicSequence.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FCinematicSequence.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FCinematicSequence, (UObject*)Z_Construct_UPackage__Script_IronChess(), TEXT("CinematicSequence"));
	}
	return Z_Registration_Info_UScriptStruct_FCinematicSequence.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FCinematicSequence_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Theme_MetaData[] = {
		{ "Category", "Sequence" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Shots_MetaData[] = {
		{ "Category", "Sequence" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BackgroundMusic_MetaData[] = {
		{ "Category", "Sequence" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalDuration_MetaData[] = {
		{ "Category", "Sequence" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OpeningNarration_MetaData[] = {
		{ "Category", "Sequence" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClosingNarration_MetaData[] = {
		{ "Category", "Sequence" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_Theme_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Theme;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Shots_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Shots;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_BackgroundMusic;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TotalDuration;
	static const UECodeGen_Private::FStrPropertyParams NewProp_OpeningNarration;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ClosingNarration;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCinematicSequence>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FCinematicSequence_Statics::NewProp_Theme_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FCinematicSequence_Statics::NewProp_Theme = { "Theme", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCinematicSequence, Theme), Z_Construct_UEnum_IronChess_ENarrativeTheme, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Theme_MetaData), NewProp_Theme_MetaData) }; // 3662323089
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCinematicSequence_Statics::NewProp_Shots_Inner = { "Shots", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FCinematicShot, METADATA_PARAMS(0, nullptr) }; // 3331727041
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FCinematicSequence_Statics::NewProp_Shots = { "Shots", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCinematicSequence, Shots), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Shots_MetaData), NewProp_Shots_MetaData) }; // 3331727041
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FCinematicSequence_Statics::NewProp_BackgroundMusic = { "BackgroundMusic", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCinematicSequence, BackgroundMusic), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BackgroundMusic_MetaData), NewProp_BackgroundMusic_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCinematicSequence_Statics::NewProp_TotalDuration = { "TotalDuration", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCinematicSequence, TotalDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalDuration_MetaData), NewProp_TotalDuration_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FCinematicSequence_Statics::NewProp_OpeningNarration = { "OpeningNarration", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCinematicSequence, OpeningNarration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OpeningNarration_MetaData), NewProp_OpeningNarration_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FCinematicSequence_Statics::NewProp_ClosingNarration = { "ClosingNarration", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCinematicSequence, ClosingNarration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClosingNarration_MetaData), NewProp_ClosingNarration_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCinematicSequence_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCinematicSequence_Statics::NewProp_Theme_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCinematicSequence_Statics::NewProp_Theme,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCinematicSequence_Statics::NewProp_Shots_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCinematicSequence_Statics::NewProp_Shots,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCinematicSequence_Statics::NewProp_BackgroundMusic,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCinematicSequence_Statics::NewProp_TotalDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCinematicSequence_Statics::NewProp_OpeningNarration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCinematicSequence_Statics::NewProp_ClosingNarration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCinematicSequence_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCinematicSequence_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_IronChess,
	nullptr,
	&NewStructOps,
	"CinematicSequence",
	Z_Construct_UScriptStruct_FCinematicSequence_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCinematicSequence_Statics::PropPointers),
	sizeof(FCinematicSequence),
	alignof(FCinematicSequence),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCinematicSequence_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FCinematicSequence_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FCinematicSequence()
{
	if (!Z_Registration_Info_UScriptStruct_FCinematicSequence.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FCinematicSequence.InnerSingleton, Z_Construct_UScriptStruct_FCinematicSequence_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FCinematicSequence.InnerSingleton;
}
// ********** End ScriptStruct FCinematicSequence **************************************************

// ********** Begin ScriptStruct FGameAnalysis *****************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FGameAnalysis;
class UScriptStruct* FGameAnalysis::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FGameAnalysis.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FGameAnalysis.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FGameAnalysis, (UObject*)Z_Construct_UPackage__Script_IronChess(), TEXT("GameAnalysis"));
	}
	return Z_Registration_Info_UScriptStruct_FGameAnalysis.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FGameAnalysis_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_KeyMoves_MetaData[] = {
		{ "Category", "GameAnalysis" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TacticalMoves_MetaData[] = {
		{ "Category", "GameAnalysis" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SacrificesMade_MetaData[] = {
		{ "Category", "GameAnalysis" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TurningPoints_MetaData[] = {
		{ "Category", "GameAnalysis" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Winner_MetaData[] = {
		{ "Category", "GameAnalysis" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GameLength_MetaData[] = {
		{ "Category", "GameAnalysis" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bWasDominantVictory_MetaData[] = {
		{ "Category", "GameAnalysis" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bWasComeback_MetaData[] = {
		{ "Category", "GameAnalysis" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AverageMoveDifficulty_MetaData[] = {
		{ "Category", "GameAnalysis" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SuggestedTheme_MetaData[] = {
		{ "Category", "GameAnalysis" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_KeyMoves_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_KeyMoves;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TacticalMoves_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_TacticalMoves;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SacrificesMade_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_SacrificesMade;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TurningPoints_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_TurningPoints;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Winner_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Winner;
	static const UECodeGen_Private::FIntPropertyParams NewProp_GameLength;
	static void NewProp_bWasDominantVictory_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bWasDominantVictory;
	static void NewProp_bWasComeback_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bWasComeback;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AverageMoveDifficulty;
	static const UECodeGen_Private::FBytePropertyParams NewProp_SuggestedTheme_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SuggestedTheme;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FGameAnalysis>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FGameAnalysis_Statics::NewProp_KeyMoves_Inner = { "KeyMoves", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FChessMove, METADATA_PARAMS(0, nullptr) }; // 1361898884
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FGameAnalysis_Statics::NewProp_KeyMoves = { "KeyMoves", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGameAnalysis, KeyMoves), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_KeyMoves_MetaData), NewProp_KeyMoves_MetaData) }; // 1361898884
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FGameAnalysis_Statics::NewProp_TacticalMoves_Inner = { "TacticalMoves", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FChessMove, METADATA_PARAMS(0, nullptr) }; // 1361898884
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FGameAnalysis_Statics::NewProp_TacticalMoves = { "TacticalMoves", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGameAnalysis, TacticalMoves), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TacticalMoves_MetaData), NewProp_TacticalMoves_MetaData) }; // 1361898884
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FGameAnalysis_Statics::NewProp_SacrificesMade_Inner = { "SacrificesMade", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FChessMove, METADATA_PARAMS(0, nullptr) }; // 1361898884
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FGameAnalysis_Statics::NewProp_SacrificesMade = { "SacrificesMade", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGameAnalysis, SacrificesMade), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SacrificesMade_MetaData), NewProp_SacrificesMade_MetaData) }; // 1361898884
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FGameAnalysis_Statics::NewProp_TurningPoints_Inner = { "TurningPoints", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FChessMove, METADATA_PARAMS(0, nullptr) }; // 1361898884
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FGameAnalysis_Statics::NewProp_TurningPoints = { "TurningPoints", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGameAnalysis, TurningPoints), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TurningPoints_MetaData), NewProp_TurningPoints_MetaData) }; // 1361898884
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FGameAnalysis_Statics::NewProp_Winner_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FGameAnalysis_Statics::NewProp_Winner = { "Winner", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGameAnalysis, Winner), Z_Construct_UEnum_IronChess_EPieceColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Winner_MetaData), NewProp_Winner_MetaData) }; // 1636929315
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FGameAnalysis_Statics::NewProp_GameLength = { "GameLength", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGameAnalysis, GameLength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GameLength_MetaData), NewProp_GameLength_MetaData) };
void Z_Construct_UScriptStruct_FGameAnalysis_Statics::NewProp_bWasDominantVictory_SetBit(void* Obj)
{
	((FGameAnalysis*)Obj)->bWasDominantVictory = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FGameAnalysis_Statics::NewProp_bWasDominantVictory = { "bWasDominantVictory", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FGameAnalysis), &Z_Construct_UScriptStruct_FGameAnalysis_Statics::NewProp_bWasDominantVictory_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bWasDominantVictory_MetaData), NewProp_bWasDominantVictory_MetaData) };
void Z_Construct_UScriptStruct_FGameAnalysis_Statics::NewProp_bWasComeback_SetBit(void* Obj)
{
	((FGameAnalysis*)Obj)->bWasComeback = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FGameAnalysis_Statics::NewProp_bWasComeback = { "bWasComeback", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FGameAnalysis), &Z_Construct_UScriptStruct_FGameAnalysis_Statics::NewProp_bWasComeback_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bWasComeback_MetaData), NewProp_bWasComeback_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FGameAnalysis_Statics::NewProp_AverageMoveDifficulty = { "AverageMoveDifficulty", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGameAnalysis, AverageMoveDifficulty), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AverageMoveDifficulty_MetaData), NewProp_AverageMoveDifficulty_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FGameAnalysis_Statics::NewProp_SuggestedTheme_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FGameAnalysis_Statics::NewProp_SuggestedTheme = { "SuggestedTheme", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGameAnalysis, SuggestedTheme), Z_Construct_UEnum_IronChess_ENarrativeTheme, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SuggestedTheme_MetaData), NewProp_SuggestedTheme_MetaData) }; // 3662323089
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FGameAnalysis_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameAnalysis_Statics::NewProp_KeyMoves_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameAnalysis_Statics::NewProp_KeyMoves,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameAnalysis_Statics::NewProp_TacticalMoves_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameAnalysis_Statics::NewProp_TacticalMoves,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameAnalysis_Statics::NewProp_SacrificesMade_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameAnalysis_Statics::NewProp_SacrificesMade,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameAnalysis_Statics::NewProp_TurningPoints_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameAnalysis_Statics::NewProp_TurningPoints,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameAnalysis_Statics::NewProp_Winner_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameAnalysis_Statics::NewProp_Winner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameAnalysis_Statics::NewProp_GameLength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameAnalysis_Statics::NewProp_bWasDominantVictory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameAnalysis_Statics::NewProp_bWasComeback,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameAnalysis_Statics::NewProp_AverageMoveDifficulty,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameAnalysis_Statics::NewProp_SuggestedTheme_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGameAnalysis_Statics::NewProp_SuggestedTheme,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameAnalysis_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FGameAnalysis_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_IronChess,
	nullptr,
	&NewStructOps,
	"GameAnalysis",
	Z_Construct_UScriptStruct_FGameAnalysis_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameAnalysis_Statics::PropPointers),
	sizeof(FGameAnalysis),
	alignof(FGameAnalysis),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGameAnalysis_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FGameAnalysis_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FGameAnalysis()
{
	if (!Z_Registration_Info_UScriptStruct_FGameAnalysis.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FGameAnalysis.InnerSingleton, Z_Construct_UScriptStruct_FGameAnalysis_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FGameAnalysis.InnerSingleton;
}
// ********** End ScriptStruct FGameAnalysis *******************************************************

// ********** Begin Delegate FOnCinematicStarted ***************************************************
struct Z_Construct_UDelegateFunction_ACinematicDirector_OnCinematicStarted__DelegateSignature_Statics
{
	struct CinematicDirector_eventOnCinematicStarted_Parms
	{
		FCinematicSequence Sequence;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Events\n" },
#endif
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Events" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Sequence_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Sequence;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_ACinematicDirector_OnCinematicStarted__DelegateSignature_Statics::NewProp_Sequence = { "Sequence", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicDirector_eventOnCinematicStarted_Parms, Sequence), Z_Construct_UScriptStruct_FCinematicSequence, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Sequence_MetaData), NewProp_Sequence_MetaData) }; // 3391121615
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ACinematicDirector_OnCinematicStarted__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ACinematicDirector_OnCinematicStarted__DelegateSignature_Statics::NewProp_Sequence,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ACinematicDirector_OnCinematicStarted__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_ACinematicDirector_OnCinematicStarted__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ACinematicDirector, nullptr, "OnCinematicStarted__DelegateSignature", Z_Construct_UDelegateFunction_ACinematicDirector_OnCinematicStarted__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ACinematicDirector_OnCinematicStarted__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_ACinematicDirector_OnCinematicStarted__DelegateSignature_Statics::CinematicDirector_eventOnCinematicStarted_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ACinematicDirector_OnCinematicStarted__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ACinematicDirector_OnCinematicStarted__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_ACinematicDirector_OnCinematicStarted__DelegateSignature_Statics::CinematicDirector_eventOnCinematicStarted_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_ACinematicDirector_OnCinematicStarted__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ACinematicDirector_OnCinematicStarted__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void ACinematicDirector::FOnCinematicStarted_DelegateWrapper(const FMulticastScriptDelegate& OnCinematicStarted, FCinematicSequence const& Sequence)
{
	struct CinematicDirector_eventOnCinematicStarted_Parms
	{
		FCinematicSequence Sequence;
	};
	CinematicDirector_eventOnCinematicStarted_Parms Parms;
	Parms.Sequence=Sequence;
	OnCinematicStarted.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnCinematicStarted *****************************************************

// ********** Begin Delegate FOnCinematicFinished **************************************************
struct Z_Construct_UDelegateFunction_ACinematicDirector_OnCinematicFinished__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_ACinematicDirector_OnCinematicFinished__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ACinematicDirector, nullptr, "OnCinematicFinished__DelegateSignature", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ACinematicDirector_OnCinematicFinished__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ACinematicDirector_OnCinematicFinished__DelegateSignature_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UDelegateFunction_ACinematicDirector_OnCinematicFinished__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ACinematicDirector_OnCinematicFinished__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void ACinematicDirector::FOnCinematicFinished_DelegateWrapper(const FMulticastScriptDelegate& OnCinematicFinished)
{
	OnCinematicFinished.ProcessMulticastDelegate<UObject>(NULL);
}
// ********** End Delegate FOnCinematicFinished ****************************************************

// ********** Begin Delegate FOnShotChanged ********************************************************
struct Z_Construct_UDelegateFunction_ACinematicDirector_OnShotChanged__DelegateSignature_Statics
{
	struct CinematicDirector_eventOnShotChanged_Parms
	{
		int32 ShotIndex;
		FCinematicShot Shot;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Shot_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ShotIndex;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Shot;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_ACinematicDirector_OnShotChanged__DelegateSignature_Statics::NewProp_ShotIndex = { "ShotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicDirector_eventOnShotChanged_Parms, ShotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_ACinematicDirector_OnShotChanged__DelegateSignature_Statics::NewProp_Shot = { "Shot", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicDirector_eventOnShotChanged_Parms, Shot), Z_Construct_UScriptStruct_FCinematicShot, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Shot_MetaData), NewProp_Shot_MetaData) }; // 3331727041
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ACinematicDirector_OnShotChanged__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ACinematicDirector_OnShotChanged__DelegateSignature_Statics::NewProp_ShotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ACinematicDirector_OnShotChanged__DelegateSignature_Statics::NewProp_Shot,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ACinematicDirector_OnShotChanged__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_ACinematicDirector_OnShotChanged__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ACinematicDirector, nullptr, "OnShotChanged__DelegateSignature", Z_Construct_UDelegateFunction_ACinematicDirector_OnShotChanged__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ACinematicDirector_OnShotChanged__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_ACinematicDirector_OnShotChanged__DelegateSignature_Statics::CinematicDirector_eventOnShotChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ACinematicDirector_OnShotChanged__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ACinematicDirector_OnShotChanged__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_ACinematicDirector_OnShotChanged__DelegateSignature_Statics::CinematicDirector_eventOnShotChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_ACinematicDirector_OnShotChanged__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ACinematicDirector_OnShotChanged__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void ACinematicDirector::FOnShotChanged_DelegateWrapper(const FMulticastScriptDelegate& OnShotChanged, int32 ShotIndex, FCinematicShot const& Shot)
{
	struct CinematicDirector_eventOnShotChanged_Parms
	{
		int32 ShotIndex;
		FCinematicShot Shot;
	};
	CinematicDirector_eventOnShotChanged_Parms Parms;
	Parms.ShotIndex=ShotIndex;
	Parms.Shot=Shot;
	OnShotChanged.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnShotChanged **********************************************************

// ********** Begin Delegate FOnNarrationSpoken ****************************************************
struct Z_Construct_UDelegateFunction_ACinematicDirector_OnNarrationSpoken__DelegateSignature_Statics
{
	struct CinematicDirector_eventOnNarrationSpoken_Parms
	{
		FString Text;
		float Duration;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Text_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_Text;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Duration;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_ACinematicDirector_OnNarrationSpoken__DelegateSignature_Statics::NewProp_Text = { "Text", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicDirector_eventOnNarrationSpoken_Parms, Text), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Text_MetaData), NewProp_Text_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_ACinematicDirector_OnNarrationSpoken__DelegateSignature_Statics::NewProp_Duration = { "Duration", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicDirector_eventOnNarrationSpoken_Parms, Duration), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ACinematicDirector_OnNarrationSpoken__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ACinematicDirector_OnNarrationSpoken__DelegateSignature_Statics::NewProp_Text,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ACinematicDirector_OnNarrationSpoken__DelegateSignature_Statics::NewProp_Duration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ACinematicDirector_OnNarrationSpoken__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_ACinematicDirector_OnNarrationSpoken__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ACinematicDirector, nullptr, "OnNarrationSpoken__DelegateSignature", Z_Construct_UDelegateFunction_ACinematicDirector_OnNarrationSpoken__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ACinematicDirector_OnNarrationSpoken__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_ACinematicDirector_OnNarrationSpoken__DelegateSignature_Statics::CinematicDirector_eventOnNarrationSpoken_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ACinematicDirector_OnNarrationSpoken__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ACinematicDirector_OnNarrationSpoken__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_ACinematicDirector_OnNarrationSpoken__DelegateSignature_Statics::CinematicDirector_eventOnNarrationSpoken_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_ACinematicDirector_OnNarrationSpoken__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ACinematicDirector_OnNarrationSpoken__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void ACinematicDirector::FOnNarrationSpoken_DelegateWrapper(const FMulticastScriptDelegate& OnNarrationSpoken, const FString& Text, float Duration)
{
	struct CinematicDirector_eventOnNarrationSpoken_Parms
	{
		FString Text;
		float Duration;
	};
	CinematicDirector_eventOnNarrationSpoken_Parms Parms;
	Parms.Text=Text;
	Parms.Duration=Duration;
	OnNarrationSpoken.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnNarrationSpoken ******************************************************

// ********** Begin Class ACinematicDirector Function AnalyzeGame **********************************
struct Z_Construct_UFunction_ACinematicDirector_AnalyzeGame_Statics
{
	struct CinematicDirector_eventAnalyzeGame_Parms
	{
		TArray<FChessMove> MoveHistory;
		EPieceColor Winner;
		FGameAnalysis ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Analysis" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Game analysis\n" },
#endif
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Game analysis" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveHistory_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_MoveHistory_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_MoveHistory;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Winner_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Winner;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ACinematicDirector_AnalyzeGame_Statics::NewProp_MoveHistory_Inner = { "MoveHistory", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FChessMove, METADATA_PARAMS(0, nullptr) }; // 1361898884
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ACinematicDirector_AnalyzeGame_Statics::NewProp_MoveHistory = { "MoveHistory", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicDirector_eventAnalyzeGame_Parms, MoveHistory), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveHistory_MetaData), NewProp_MoveHistory_MetaData) }; // 1361898884
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ACinematicDirector_AnalyzeGame_Statics::NewProp_Winner_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_ACinematicDirector_AnalyzeGame_Statics::NewProp_Winner = { "Winner", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicDirector_eventAnalyzeGame_Parms, Winner), Z_Construct_UEnum_IronChess_EPieceColor, METADATA_PARAMS(0, nullptr) }; // 1636929315
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ACinematicDirector_AnalyzeGame_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicDirector_eventAnalyzeGame_Parms, ReturnValue), Z_Construct_UScriptStruct_FGameAnalysis, METADATA_PARAMS(0, nullptr) }; // 2277182007
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACinematicDirector_AnalyzeGame_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACinematicDirector_AnalyzeGame_Statics::NewProp_MoveHistory_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACinematicDirector_AnalyzeGame_Statics::NewProp_MoveHistory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACinematicDirector_AnalyzeGame_Statics::NewProp_Winner_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACinematicDirector_AnalyzeGame_Statics::NewProp_Winner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACinematicDirector_AnalyzeGame_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_AnalyzeGame_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACinematicDirector_AnalyzeGame_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ACinematicDirector, nullptr, "AnalyzeGame", Z_Construct_UFunction_ACinematicDirector_AnalyzeGame_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_AnalyzeGame_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACinematicDirector_AnalyzeGame_Statics::CinematicDirector_eventAnalyzeGame_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_AnalyzeGame_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACinematicDirector_AnalyzeGame_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ACinematicDirector_AnalyzeGame_Statics::CinematicDirector_eventAnalyzeGame_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACinematicDirector_AnalyzeGame()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACinematicDirector_AnalyzeGame_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACinematicDirector::execAnalyzeGame)
{
	P_GET_TARRAY_REF(FChessMove,Z_Param_Out_MoveHistory);
	P_GET_ENUM(EPieceColor,Z_Param_Winner);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGameAnalysis*)Z_Param__Result=P_THIS->AnalyzeGame(Z_Param_Out_MoveHistory,EPieceColor(Z_Param_Winner));
	P_NATIVE_END;
}
// ********** End Class ACinematicDirector Function AnalyzeGame ************************************

// ********** Begin Class ACinematicDirector Function CalculateCameraPosition **********************
struct Z_Construct_UFunction_ACinematicDirector_CalculateCameraPosition_Statics
{
	struct CinematicDirector_eventCalculateCameraPosition_Parms
	{
		FChessMove Move;
		FString ShotType;
		FTransform ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Camera" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Move_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShotType_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Move;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ShotType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ACinematicDirector_CalculateCameraPosition_Statics::NewProp_Move = { "Move", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicDirector_eventCalculateCameraPosition_Parms, Move), Z_Construct_UScriptStruct_FChessMove, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Move_MetaData), NewProp_Move_MetaData) }; // 1361898884
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ACinematicDirector_CalculateCameraPosition_Statics::NewProp_ShotType = { "ShotType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicDirector_eventCalculateCameraPosition_Parms, ShotType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShotType_MetaData), NewProp_ShotType_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ACinematicDirector_CalculateCameraPosition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicDirector_eventCalculateCameraPosition_Parms, ReturnValue), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACinematicDirector_CalculateCameraPosition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACinematicDirector_CalculateCameraPosition_Statics::NewProp_Move,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACinematicDirector_CalculateCameraPosition_Statics::NewProp_ShotType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACinematicDirector_CalculateCameraPosition_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_CalculateCameraPosition_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACinematicDirector_CalculateCameraPosition_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ACinematicDirector, nullptr, "CalculateCameraPosition", Z_Construct_UFunction_ACinematicDirector_CalculateCameraPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_CalculateCameraPosition_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACinematicDirector_CalculateCameraPosition_Statics::CinematicDirector_eventCalculateCameraPosition_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_CalculateCameraPosition_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACinematicDirector_CalculateCameraPosition_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ACinematicDirector_CalculateCameraPosition_Statics::CinematicDirector_eventCalculateCameraPosition_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACinematicDirector_CalculateCameraPosition()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACinematicDirector_CalculateCameraPosition_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACinematicDirector::execCalculateCameraPosition)
{
	P_GET_STRUCT_REF(FChessMove,Z_Param_Out_Move);
	P_GET_PROPERTY(FStrProperty,Z_Param_ShotType);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FTransform*)Z_Param__Result=P_THIS->CalculateCameraPosition(Z_Param_Out_Move,Z_Param_ShotType);
	P_NATIVE_END;
}
// ********** End Class ACinematicDirector Function CalculateCameraPosition ************************

// ********** Begin Class ACinematicDirector Function CreateEndgameReenactment *********************
struct Z_Construct_UFunction_ACinematicDirector_CreateEndgameReenactment_Statics
{
	struct CinematicDirector_eventCreateEndgameReenactment_Parms
	{
		TArray<FChessMove> MoveHistory;
		EPieceColor Winner;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cinematic" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Main cinematic functions\n" },
#endif
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Main cinematic functions" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveHistory_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_MoveHistory_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_MoveHistory;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Winner_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Winner;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ACinematicDirector_CreateEndgameReenactment_Statics::NewProp_MoveHistory_Inner = { "MoveHistory", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FChessMove, METADATA_PARAMS(0, nullptr) }; // 1361898884
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ACinematicDirector_CreateEndgameReenactment_Statics::NewProp_MoveHistory = { "MoveHistory", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicDirector_eventCreateEndgameReenactment_Parms, MoveHistory), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveHistory_MetaData), NewProp_MoveHistory_MetaData) }; // 1361898884
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ACinematicDirector_CreateEndgameReenactment_Statics::NewProp_Winner_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_ACinematicDirector_CreateEndgameReenactment_Statics::NewProp_Winner = { "Winner", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicDirector_eventCreateEndgameReenactment_Parms, Winner), Z_Construct_UEnum_IronChess_EPieceColor, METADATA_PARAMS(0, nullptr) }; // 1636929315
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACinematicDirector_CreateEndgameReenactment_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACinematicDirector_CreateEndgameReenactment_Statics::NewProp_MoveHistory_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACinematicDirector_CreateEndgameReenactment_Statics::NewProp_MoveHistory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACinematicDirector_CreateEndgameReenactment_Statics::NewProp_Winner_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACinematicDirector_CreateEndgameReenactment_Statics::NewProp_Winner,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_CreateEndgameReenactment_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACinematicDirector_CreateEndgameReenactment_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ACinematicDirector, nullptr, "CreateEndgameReenactment", Z_Construct_UFunction_ACinematicDirector_CreateEndgameReenactment_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_CreateEndgameReenactment_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACinematicDirector_CreateEndgameReenactment_Statics::CinematicDirector_eventCreateEndgameReenactment_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_CreateEndgameReenactment_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACinematicDirector_CreateEndgameReenactment_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ACinematicDirector_CreateEndgameReenactment_Statics::CinematicDirector_eventCreateEndgameReenactment_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACinematicDirector_CreateEndgameReenactment()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACinematicDirector_CreateEndgameReenactment_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACinematicDirector::execCreateEndgameReenactment)
{
	P_GET_TARRAY_REF(FChessMove,Z_Param_Out_MoveHistory);
	P_GET_ENUM(EPieceColor,Z_Param_Winner);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CreateEndgameReenactment(Z_Param_Out_MoveHistory,EPieceColor(Z_Param_Winner));
	P_NATIVE_END;
}
// ********** End Class ACinematicDirector Function CreateEndgameReenactment ***********************

// ********** Begin Class ACinematicDirector Function CreateShotsFromMoves *************************
struct Z_Construct_UFunction_ACinematicDirector_CreateShotsFromMoves_Statics
{
	struct CinematicDirector_eventCreateShotsFromMoves_Parms
	{
		TArray<FChessMove> KeyMoves;
		ENarrativeTheme Theme;
		TArray<FCinematicShot> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generation" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_KeyMoves_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_KeyMoves_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_KeyMoves;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Theme_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Theme;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ACinematicDirector_CreateShotsFromMoves_Statics::NewProp_KeyMoves_Inner = { "KeyMoves", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FChessMove, METADATA_PARAMS(0, nullptr) }; // 1361898884
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ACinematicDirector_CreateShotsFromMoves_Statics::NewProp_KeyMoves = { "KeyMoves", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicDirector_eventCreateShotsFromMoves_Parms, KeyMoves), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_KeyMoves_MetaData), NewProp_KeyMoves_MetaData) }; // 1361898884
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ACinematicDirector_CreateShotsFromMoves_Statics::NewProp_Theme_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_ACinematicDirector_CreateShotsFromMoves_Statics::NewProp_Theme = { "Theme", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicDirector_eventCreateShotsFromMoves_Parms, Theme), Z_Construct_UEnum_IronChess_ENarrativeTheme, METADATA_PARAMS(0, nullptr) }; // 3662323089
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ACinematicDirector_CreateShotsFromMoves_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FCinematicShot, METADATA_PARAMS(0, nullptr) }; // 3331727041
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ACinematicDirector_CreateShotsFromMoves_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicDirector_eventCreateShotsFromMoves_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 3331727041
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACinematicDirector_CreateShotsFromMoves_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACinematicDirector_CreateShotsFromMoves_Statics::NewProp_KeyMoves_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACinematicDirector_CreateShotsFromMoves_Statics::NewProp_KeyMoves,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACinematicDirector_CreateShotsFromMoves_Statics::NewProp_Theme_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACinematicDirector_CreateShotsFromMoves_Statics::NewProp_Theme,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACinematicDirector_CreateShotsFromMoves_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACinematicDirector_CreateShotsFromMoves_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_CreateShotsFromMoves_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACinematicDirector_CreateShotsFromMoves_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ACinematicDirector, nullptr, "CreateShotsFromMoves", Z_Construct_UFunction_ACinematicDirector_CreateShotsFromMoves_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_CreateShotsFromMoves_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACinematicDirector_CreateShotsFromMoves_Statics::CinematicDirector_eventCreateShotsFromMoves_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_CreateShotsFromMoves_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACinematicDirector_CreateShotsFromMoves_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ACinematicDirector_CreateShotsFromMoves_Statics::CinematicDirector_eventCreateShotsFromMoves_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACinematicDirector_CreateShotsFromMoves()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACinematicDirector_CreateShotsFromMoves_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACinematicDirector::execCreateShotsFromMoves)
{
	P_GET_TARRAY_REF(FChessMove,Z_Param_Out_KeyMoves);
	P_GET_ENUM(ENarrativeTheme,Z_Param_Theme);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FCinematicShot>*)Z_Param__Result=P_THIS->CreateShotsFromMoves(Z_Param_Out_KeyMoves,ENarrativeTheme(Z_Param_Theme));
	P_NATIVE_END;
}
// ********** End Class ACinematicDirector Function CreateShotsFromMoves ***************************

// ********** Begin Class ACinematicDirector Function DetermineGameTheme ***************************
struct Z_Construct_UFunction_ACinematicDirector_DetermineGameTheme_Statics
{
	struct CinematicDirector_eventDetermineGameTheme_Parms
	{
		FGameAnalysis Analysis;
		ENarrativeTheme ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Analysis" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Analysis_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Analysis;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ACinematicDirector_DetermineGameTheme_Statics::NewProp_Analysis = { "Analysis", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicDirector_eventDetermineGameTheme_Parms, Analysis), Z_Construct_UScriptStruct_FGameAnalysis, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Analysis_MetaData), NewProp_Analysis_MetaData) }; // 2277182007
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ACinematicDirector_DetermineGameTheme_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_ACinematicDirector_DetermineGameTheme_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicDirector_eventDetermineGameTheme_Parms, ReturnValue), Z_Construct_UEnum_IronChess_ENarrativeTheme, METADATA_PARAMS(0, nullptr) }; // 3662323089
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACinematicDirector_DetermineGameTheme_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACinematicDirector_DetermineGameTheme_Statics::NewProp_Analysis,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACinematicDirector_DetermineGameTheme_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACinematicDirector_DetermineGameTheme_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_DetermineGameTheme_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACinematicDirector_DetermineGameTheme_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ACinematicDirector, nullptr, "DetermineGameTheme", Z_Construct_UFunction_ACinematicDirector_DetermineGameTheme_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_DetermineGameTheme_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACinematicDirector_DetermineGameTheme_Statics::CinematicDirector_eventDetermineGameTheme_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_DetermineGameTheme_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACinematicDirector_DetermineGameTheme_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ACinematicDirector_DetermineGameTheme_Statics::CinematicDirector_eventDetermineGameTheme_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACinematicDirector_DetermineGameTheme()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACinematicDirector_DetermineGameTheme_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACinematicDirector::execDetermineGameTheme)
{
	P_GET_STRUCT_REF(FGameAnalysis,Z_Param_Out_Analysis);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ENarrativeTheme*)Z_Param__Result=P_THIS->DetermineGameTheme(Z_Param_Out_Analysis);
	P_NATIVE_END;
}
// ********** End Class ACinematicDirector Function DetermineGameTheme *****************************

// ********** Begin Class ACinematicDirector Function GenerateCinematicSequence ********************
struct Z_Construct_UFunction_ACinematicDirector_GenerateCinematicSequence_Statics
{
	struct CinematicDirector_eventGenerateCinematicSequence_Parms
	{
		FGameAnalysis Analysis;
		FCinematicSequence ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Sequence generation\n" },
#endif
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sequence generation" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Analysis_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Analysis;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ACinematicDirector_GenerateCinematicSequence_Statics::NewProp_Analysis = { "Analysis", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicDirector_eventGenerateCinematicSequence_Parms, Analysis), Z_Construct_UScriptStruct_FGameAnalysis, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Analysis_MetaData), NewProp_Analysis_MetaData) }; // 2277182007
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ACinematicDirector_GenerateCinematicSequence_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicDirector_eventGenerateCinematicSequence_Parms, ReturnValue), Z_Construct_UScriptStruct_FCinematicSequence, METADATA_PARAMS(0, nullptr) }; // 3391121615
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACinematicDirector_GenerateCinematicSequence_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACinematicDirector_GenerateCinematicSequence_Statics::NewProp_Analysis,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACinematicDirector_GenerateCinematicSequence_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_GenerateCinematicSequence_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACinematicDirector_GenerateCinematicSequence_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ACinematicDirector, nullptr, "GenerateCinematicSequence", Z_Construct_UFunction_ACinematicDirector_GenerateCinematicSequence_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_GenerateCinematicSequence_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACinematicDirector_GenerateCinematicSequence_Statics::CinematicDirector_eventGenerateCinematicSequence_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_GenerateCinematicSequence_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACinematicDirector_GenerateCinematicSequence_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ACinematicDirector_GenerateCinematicSequence_Statics::CinematicDirector_eventGenerateCinematicSequence_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACinematicDirector_GenerateCinematicSequence()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACinematicDirector_GenerateCinematicSequence_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACinematicDirector::execGenerateCinematicSequence)
{
	P_GET_STRUCT_REF(FGameAnalysis,Z_Param_Out_Analysis);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FCinematicSequence*)Z_Param__Result=P_THIS->GenerateCinematicSequence(Z_Param_Out_Analysis);
	P_NATIVE_END;
}
// ********** End Class ACinematicDirector Function GenerateCinematicSequence **********************

// ********** Begin Class ACinematicDirector Function GenerateClosingNarration *********************
struct Z_Construct_UFunction_ACinematicDirector_GenerateClosingNarration_Statics
{
	struct CinematicDirector_eventGenerateClosingNarration_Parms
	{
		FGameAnalysis Analysis;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Narrative" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Analysis_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Analysis;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ACinematicDirector_GenerateClosingNarration_Statics::NewProp_Analysis = { "Analysis", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicDirector_eventGenerateClosingNarration_Parms, Analysis), Z_Construct_UScriptStruct_FGameAnalysis, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Analysis_MetaData), NewProp_Analysis_MetaData) }; // 2277182007
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ACinematicDirector_GenerateClosingNarration_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicDirector_eventGenerateClosingNarration_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACinematicDirector_GenerateClosingNarration_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACinematicDirector_GenerateClosingNarration_Statics::NewProp_Analysis,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACinematicDirector_GenerateClosingNarration_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_GenerateClosingNarration_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACinematicDirector_GenerateClosingNarration_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ACinematicDirector, nullptr, "GenerateClosingNarration", Z_Construct_UFunction_ACinematicDirector_GenerateClosingNarration_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_GenerateClosingNarration_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACinematicDirector_GenerateClosingNarration_Statics::CinematicDirector_eventGenerateClosingNarration_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_GenerateClosingNarration_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACinematicDirector_GenerateClosingNarration_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ACinematicDirector_GenerateClosingNarration_Statics::CinematicDirector_eventGenerateClosingNarration_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACinematicDirector_GenerateClosingNarration()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACinematicDirector_GenerateClosingNarration_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACinematicDirector::execGenerateClosingNarration)
{
	P_GET_STRUCT_REF(FGameAnalysis,Z_Param_Out_Analysis);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GenerateClosingNarration(Z_Param_Out_Analysis);
	P_NATIVE_END;
}
// ********** End Class ACinematicDirector Function GenerateClosingNarration ***********************

// ********** Begin Class ACinematicDirector Function GenerateMoveNarration ************************
struct Z_Construct_UFunction_ACinematicDirector_GenerateMoveNarration_Statics
{
	struct CinematicDirector_eventGenerateMoveNarration_Parms
	{
		FChessMove Move;
		FString Context;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Narrative" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Move_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Move;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Context;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ACinematicDirector_GenerateMoveNarration_Statics::NewProp_Move = { "Move", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicDirector_eventGenerateMoveNarration_Parms, Move), Z_Construct_UScriptStruct_FChessMove, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Move_MetaData), NewProp_Move_MetaData) }; // 1361898884
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ACinematicDirector_GenerateMoveNarration_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicDirector_eventGenerateMoveNarration_Parms, Context), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Context_MetaData), NewProp_Context_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ACinematicDirector_GenerateMoveNarration_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicDirector_eventGenerateMoveNarration_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACinematicDirector_GenerateMoveNarration_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACinematicDirector_GenerateMoveNarration_Statics::NewProp_Move,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACinematicDirector_GenerateMoveNarration_Statics::NewProp_Context,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACinematicDirector_GenerateMoveNarration_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_GenerateMoveNarration_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACinematicDirector_GenerateMoveNarration_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ACinematicDirector, nullptr, "GenerateMoveNarration", Z_Construct_UFunction_ACinematicDirector_GenerateMoveNarration_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_GenerateMoveNarration_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACinematicDirector_GenerateMoveNarration_Statics::CinematicDirector_eventGenerateMoveNarration_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_GenerateMoveNarration_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACinematicDirector_GenerateMoveNarration_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ACinematicDirector_GenerateMoveNarration_Statics::CinematicDirector_eventGenerateMoveNarration_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACinematicDirector_GenerateMoveNarration()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACinematicDirector_GenerateMoveNarration_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACinematicDirector::execGenerateMoveNarration)
{
	P_GET_STRUCT_REF(FChessMove,Z_Param_Out_Move);
	P_GET_PROPERTY(FStrProperty,Z_Param_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GenerateMoveNarration(Z_Param_Out_Move,Z_Param_Context);
	P_NATIVE_END;
}
// ********** End Class ACinematicDirector Function GenerateMoveNarration **************************

// ********** Begin Class ACinematicDirector Function GenerateOpeningNarration *********************
struct Z_Construct_UFunction_ACinematicDirector_GenerateOpeningNarration_Statics
{
	struct CinematicDirector_eventGenerateOpeningNarration_Parms
	{
		FGameAnalysis Analysis;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Narrative" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Narrative generation\n" },
#endif
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Narrative generation" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Analysis_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Analysis;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ACinematicDirector_GenerateOpeningNarration_Statics::NewProp_Analysis = { "Analysis", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicDirector_eventGenerateOpeningNarration_Parms, Analysis), Z_Construct_UScriptStruct_FGameAnalysis, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Analysis_MetaData), NewProp_Analysis_MetaData) }; // 2277182007
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ACinematicDirector_GenerateOpeningNarration_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicDirector_eventGenerateOpeningNarration_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACinematicDirector_GenerateOpeningNarration_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACinematicDirector_GenerateOpeningNarration_Statics::NewProp_Analysis,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACinematicDirector_GenerateOpeningNarration_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_GenerateOpeningNarration_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACinematicDirector_GenerateOpeningNarration_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ACinematicDirector, nullptr, "GenerateOpeningNarration", Z_Construct_UFunction_ACinematicDirector_GenerateOpeningNarration_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_GenerateOpeningNarration_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACinematicDirector_GenerateOpeningNarration_Statics::CinematicDirector_eventGenerateOpeningNarration_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_GenerateOpeningNarration_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACinematicDirector_GenerateOpeningNarration_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ACinematicDirector_GenerateOpeningNarration_Statics::CinematicDirector_eventGenerateOpeningNarration_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACinematicDirector_GenerateOpeningNarration()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACinematicDirector_GenerateOpeningNarration_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACinematicDirector::execGenerateOpeningNarration)
{
	P_GET_STRUCT_REF(FGameAnalysis,Z_Param_Out_Analysis);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GenerateOpeningNarration(Z_Param_Out_Analysis);
	P_NATIVE_END;
}
// ********** End Class ACinematicDirector Function GenerateOpeningNarration ***********************

// ********** Begin Class ACinematicDirector Function GetCinematicProgress *************************
struct Z_Construct_UFunction_ACinematicDirector_GetCinematicProgress_Statics
{
	struct CinematicDirector_eventGetCinematicProgress_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cinematic" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ACinematicDirector_GetCinematicProgress_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicDirector_eventGetCinematicProgress_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACinematicDirector_GetCinematicProgress_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACinematicDirector_GetCinematicProgress_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_GetCinematicProgress_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACinematicDirector_GetCinematicProgress_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ACinematicDirector, nullptr, "GetCinematicProgress", Z_Construct_UFunction_ACinematicDirector_GetCinematicProgress_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_GetCinematicProgress_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACinematicDirector_GetCinematicProgress_Statics::CinematicDirector_eventGetCinematicProgress_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_GetCinematicProgress_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACinematicDirector_GetCinematicProgress_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ACinematicDirector_GetCinematicProgress_Statics::CinematicDirector_eventGetCinematicProgress_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACinematicDirector_GetCinematicProgress()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACinematicDirector_GetCinematicProgress_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACinematicDirector::execGetCinematicProgress)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetCinematicProgress();
	P_NATIVE_END;
}
// ********** End Class ACinematicDirector Function GetCinematicProgress ***************************

// ********** Begin Class ACinematicDirector Function GetCurrentShotIndex **************************
struct Z_Construct_UFunction_ACinematicDirector_GetCurrentShotIndex_Statics
{
	struct CinematicDirector_eventGetCurrentShotIndex_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cinematic" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ACinematicDirector_GetCurrentShotIndex_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicDirector_eventGetCurrentShotIndex_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACinematicDirector_GetCurrentShotIndex_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACinematicDirector_GetCurrentShotIndex_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_GetCurrentShotIndex_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACinematicDirector_GetCurrentShotIndex_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ACinematicDirector, nullptr, "GetCurrentShotIndex", Z_Construct_UFunction_ACinematicDirector_GetCurrentShotIndex_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_GetCurrentShotIndex_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACinematicDirector_GetCurrentShotIndex_Statics::CinematicDirector_eventGetCurrentShotIndex_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_GetCurrentShotIndex_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACinematicDirector_GetCurrentShotIndex_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ACinematicDirector_GetCurrentShotIndex_Statics::CinematicDirector_eventGetCurrentShotIndex_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACinematicDirector_GetCurrentShotIndex()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACinematicDirector_GetCurrentShotIndex_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACinematicDirector::execGetCurrentShotIndex)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetCurrentShotIndex();
	P_NATIVE_END;
}
// ********** End Class ACinematicDirector Function GetCurrentShotIndex ****************************

// ********** Begin Class ACinematicDirector Function IsPlayingCinematic ***************************
struct Z_Construct_UFunction_ACinematicDirector_IsPlayingCinematic_Statics
{
	struct CinematicDirector_eventIsPlayingCinematic_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cinematic" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// State queries\n" },
#endif
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "State queries" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_ACinematicDirector_IsPlayingCinematic_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((CinematicDirector_eventIsPlayingCinematic_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ACinematicDirector_IsPlayingCinematic_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CinematicDirector_eventIsPlayingCinematic_Parms), &Z_Construct_UFunction_ACinematicDirector_IsPlayingCinematic_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACinematicDirector_IsPlayingCinematic_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACinematicDirector_IsPlayingCinematic_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_IsPlayingCinematic_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACinematicDirector_IsPlayingCinematic_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ACinematicDirector, nullptr, "IsPlayingCinematic", Z_Construct_UFunction_ACinematicDirector_IsPlayingCinematic_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_IsPlayingCinematic_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACinematicDirector_IsPlayingCinematic_Statics::CinematicDirector_eventIsPlayingCinematic_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_IsPlayingCinematic_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACinematicDirector_IsPlayingCinematic_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ACinematicDirector_IsPlayingCinematic_Statics::CinematicDirector_eventIsPlayingCinematic_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACinematicDirector_IsPlayingCinematic()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACinematicDirector_IsPlayingCinematic_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACinematicDirector::execIsPlayingCinematic)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsPlayingCinematic();
	P_NATIVE_END;
}
// ********** End Class ACinematicDirector Function IsPlayingCinematic *****************************

// ********** Begin Class ACinematicDirector Function PlayCinematicSequence ************************
struct Z_Construct_UFunction_ACinematicDirector_PlayCinematicSequence_Statics
{
	struct CinematicDirector_eventPlayCinematicSequence_Parms
	{
		FCinematicSequence Sequence;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cinematic" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Sequence_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Sequence;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ACinematicDirector_PlayCinematicSequence_Statics::NewProp_Sequence = { "Sequence", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicDirector_eventPlayCinematicSequence_Parms, Sequence), Z_Construct_UScriptStruct_FCinematicSequence, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Sequence_MetaData), NewProp_Sequence_MetaData) }; // 3391121615
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACinematicDirector_PlayCinematicSequence_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACinematicDirector_PlayCinematicSequence_Statics::NewProp_Sequence,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_PlayCinematicSequence_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACinematicDirector_PlayCinematicSequence_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ACinematicDirector, nullptr, "PlayCinematicSequence", Z_Construct_UFunction_ACinematicDirector_PlayCinematicSequence_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_PlayCinematicSequence_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACinematicDirector_PlayCinematicSequence_Statics::CinematicDirector_eventPlayCinematicSequence_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_PlayCinematicSequence_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACinematicDirector_PlayCinematicSequence_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ACinematicDirector_PlayCinematicSequence_Statics::CinematicDirector_eventPlayCinematicSequence_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACinematicDirector_PlayCinematicSequence()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACinematicDirector_PlayCinematicSequence_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACinematicDirector::execPlayCinematicSequence)
{
	P_GET_STRUCT_REF(FCinematicSequence,Z_Param_Out_Sequence);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->PlayCinematicSequence(Z_Param_Out_Sequence);
	P_NATIVE_END;
}
// ********** End Class ACinematicDirector Function PlayCinematicSequence **************************

// ********** Begin Class ACinematicDirector Function SetupCinematicCamera *************************
struct Z_Construct_UFunction_ACinematicDirector_SetupCinematicCamera_Statics
{
	struct CinematicDirector_eventSetupCinematicCamera_Parms
	{
		FCinematicShot Shot;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Camera management\n" },
#endif
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Camera management" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Shot_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Shot;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ACinematicDirector_SetupCinematicCamera_Statics::NewProp_Shot = { "Shot", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CinematicDirector_eventSetupCinematicCamera_Parms, Shot), Z_Construct_UScriptStruct_FCinematicShot, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Shot_MetaData), NewProp_Shot_MetaData) }; // 3331727041
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACinematicDirector_SetupCinematicCamera_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACinematicDirector_SetupCinematicCamera_Statics::NewProp_Shot,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_SetupCinematicCamera_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACinematicDirector_SetupCinematicCamera_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ACinematicDirector, nullptr, "SetupCinematicCamera", Z_Construct_UFunction_ACinematicDirector_SetupCinematicCamera_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_SetupCinematicCamera_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACinematicDirector_SetupCinematicCamera_Statics::CinematicDirector_eventSetupCinematicCamera_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_SetupCinematicCamera_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACinematicDirector_SetupCinematicCamera_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ACinematicDirector_SetupCinematicCamera_Statics::CinematicDirector_eventSetupCinematicCamera_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACinematicDirector_SetupCinematicCamera()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACinematicDirector_SetupCinematicCamera_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACinematicDirector::execSetupCinematicCamera)
{
	P_GET_STRUCT_REF(FCinematicShot,Z_Param_Out_Shot);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetupCinematicCamera(Z_Param_Out_Shot);
	P_NATIVE_END;
}
// ********** End Class ACinematicDirector Function SetupCinematicCamera ***************************

// ********** Begin Class ACinematicDirector Function SkipToNextShot *******************************
struct Z_Construct_UFunction_ACinematicDirector_SkipToNextShot_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cinematic" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACinematicDirector_SkipToNextShot_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ACinematicDirector, nullptr, "SkipToNextShot", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_SkipToNextShot_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACinematicDirector_SkipToNextShot_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_ACinematicDirector_SkipToNextShot()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACinematicDirector_SkipToNextShot_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACinematicDirector::execSkipToNextShot)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SkipToNextShot();
	P_NATIVE_END;
}
// ********** End Class ACinematicDirector Function SkipToNextShot *********************************

// ********** Begin Class ACinematicDirector Function StopCinematic ********************************
struct Z_Construct_UFunction_ACinematicDirector_StopCinematic_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Cinematic" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACinematicDirector_StopCinematic_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ACinematicDirector, nullptr, "StopCinematic", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACinematicDirector_StopCinematic_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACinematicDirector_StopCinematic_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_ACinematicDirector_StopCinematic()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACinematicDirector_StopCinematic_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACinematicDirector::execStopCinematic)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StopCinematic();
	P_NATIVE_END;
}
// ********** End Class ACinematicDirector Function StopCinematic **********************************

// ********** Begin Class ACinematicDirector *******************************************************
void ACinematicDirector::StaticRegisterNativesACinematicDirector()
{
	UClass* Class = ACinematicDirector::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "AnalyzeGame", &ACinematicDirector::execAnalyzeGame },
		{ "CalculateCameraPosition", &ACinematicDirector::execCalculateCameraPosition },
		{ "CreateEndgameReenactment", &ACinematicDirector::execCreateEndgameReenactment },
		{ "CreateShotsFromMoves", &ACinematicDirector::execCreateShotsFromMoves },
		{ "DetermineGameTheme", &ACinematicDirector::execDetermineGameTheme },
		{ "GenerateCinematicSequence", &ACinematicDirector::execGenerateCinematicSequence },
		{ "GenerateClosingNarration", &ACinematicDirector::execGenerateClosingNarration },
		{ "GenerateMoveNarration", &ACinematicDirector::execGenerateMoveNarration },
		{ "GenerateOpeningNarration", &ACinematicDirector::execGenerateOpeningNarration },
		{ "GetCinematicProgress", &ACinematicDirector::execGetCinematicProgress },
		{ "GetCurrentShotIndex", &ACinematicDirector::execGetCurrentShotIndex },
		{ "IsPlayingCinematic", &ACinematicDirector::execIsPlayingCinematic },
		{ "PlayCinematicSequence", &ACinematicDirector::execPlayCinematicSequence },
		{ "SetupCinematicCamera", &ACinematicDirector::execSetupCinematicCamera },
		{ "SkipToNextShot", &ACinematicDirector::execSkipToNextShot },
		{ "StopCinematic", &ACinematicDirector::execStopCinematic },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_ACinematicDirector;
UClass* ACinematicDirector::GetPrivateStaticClass()
{
	using TClass = ACinematicDirector;
	if (!Z_Registration_Info_UClass_ACinematicDirector.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("CinematicDirector"),
			Z_Registration_Info_UClass_ACinematicDirector.InnerSingleton,
			StaticRegisterNativesACinematicDirector,
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
	return Z_Registration_Info_UClass_ACinematicDirector.InnerSingleton;
}
UClass* Z_Construct_UClass_ACinematicDirector_NoRegister()
{
	return ACinematicDirector::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ACinematicDirector_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Cinematic Director responsible for creating epic endgame reenactments\n * Analyzes completed games and generates medieval war story cinematics\n */" },
#endif
		{ "IncludePath", "Cinematic/CinematicDirector.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cinematic Director responsible for creating epic endgame reenactments\nAnalyzes completed games and generates medieval war story cinematics" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCinematicStarted_MetaData[] = {
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCinematicFinished_MetaData[] = {
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnShotChanged_MetaData[] = {
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnNarrationSpoken_MetaData[] = {
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultShotDuration_MetaData[] = {
		{ "Category", "Cinematic Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Cinematic settings\n" },
#endif
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cinematic settings" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraTransitionTime_MetaData[] = {
		{ "Category", "Cinematic Settings" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAutoGenerateShots_MetaData[] = {
		{ "Category", "Cinematic Settings" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxShotsPerSequence_MetaData[] = {
		{ "Category", "Cinematic Settings" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NarrationSpeed_MetaData[] = {
		{ "Category", "Cinematic Settings" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CinematicSoundMix_MetaData[] = {
		{ "Category", "Audio" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Audio settings\n" },
#endif
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Audio settings" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MusicVolume_MetaData[] = {
		{ "Category", "Audio" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NarrationVolume_MetaData[] = {
		{ "Category", "Audio" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OpeningTemplates_MetaData[] = {
		{ "Category", "Narrative" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Narrative templates\n" },
#endif
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Narrative templates" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClosingTemplates_MetaData[] = {
		{ "Category", "Narrative" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PieceDescriptions_MetaData[] = {
		{ "Category", "Narrative" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsPlayingCinematic_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Current cinematic state\n" },
#endif
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current cinematic state" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentSequence_MetaData[] = {
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentShotIndex_MetaData[] = {
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentShot_MetaData[] = {
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentShotTime_MetaData[] = {
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShotElapsedTime_MetaData[] = {
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalCinematicTime_MetaData[] = {
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CinematicCamera_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Camera and audio components\n" },
#endif
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Camera and audio components" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BackgroundMusicComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NarrationComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SequencePlayer_MetaData[] = {
		{ "ModuleRelativePath", "Cinematic/CinematicDirector.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCinematicStarted;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCinematicFinished;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnShotChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnNarrationSpoken;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DefaultShotDuration;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CameraTransitionTime;
	static void NewProp_bAutoGenerateShots_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoGenerateShots;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxShotsPerSequence;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NarrationSpeed;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_CinematicSoundMix;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MusicVolume;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NarrationVolume;
	static const UECodeGen_Private::FStrPropertyParams NewProp_OpeningTemplates_ValueProp;
	static const UECodeGen_Private::FBytePropertyParams NewProp_OpeningTemplates_Key_KeyProp_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_OpeningTemplates_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_OpeningTemplates;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ClosingTemplates_ValueProp;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ClosingTemplates_Key_KeyProp_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ClosingTemplates_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_ClosingTemplates;
	static const UECodeGen_Private::FStrPropertyParams NewProp_PieceDescriptions_ValueProp;
	static const UECodeGen_Private::FBytePropertyParams NewProp_PieceDescriptions_Key_KeyProp_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_PieceDescriptions_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_PieceDescriptions;
	static void NewProp_bIsPlayingCinematic_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsPlayingCinematic;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentSequence;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentShotIndex;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentShot;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentShotTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ShotElapsedTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TotalCinematicTime;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CinematicCamera;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BackgroundMusicComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NarrationComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SequencePlayer;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ACinematicDirector_AnalyzeGame, "AnalyzeGame" }, // 2277231442
		{ &Z_Construct_UFunction_ACinematicDirector_CalculateCameraPosition, "CalculateCameraPosition" }, // 1674952668
		{ &Z_Construct_UFunction_ACinematicDirector_CreateEndgameReenactment, "CreateEndgameReenactment" }, // 2251720573
		{ &Z_Construct_UFunction_ACinematicDirector_CreateShotsFromMoves, "CreateShotsFromMoves" }, // 2920636851
		{ &Z_Construct_UFunction_ACinematicDirector_DetermineGameTheme, "DetermineGameTheme" }, // 1353883713
		{ &Z_Construct_UFunction_ACinematicDirector_GenerateCinematicSequence, "GenerateCinematicSequence" }, // 1387921859
		{ &Z_Construct_UFunction_ACinematicDirector_GenerateClosingNarration, "GenerateClosingNarration" }, // 836168330
		{ &Z_Construct_UFunction_ACinematicDirector_GenerateMoveNarration, "GenerateMoveNarration" }, // 2625518718
		{ &Z_Construct_UFunction_ACinematicDirector_GenerateOpeningNarration, "GenerateOpeningNarration" }, // 2943855314
		{ &Z_Construct_UFunction_ACinematicDirector_GetCinematicProgress, "GetCinematicProgress" }, // 424511765
		{ &Z_Construct_UFunction_ACinematicDirector_GetCurrentShotIndex, "GetCurrentShotIndex" }, // 3767799391
		{ &Z_Construct_UFunction_ACinematicDirector_IsPlayingCinematic, "IsPlayingCinematic" }, // 1903004603
		{ &Z_Construct_UDelegateFunction_ACinematicDirector_OnCinematicFinished__DelegateSignature, "OnCinematicFinished__DelegateSignature" }, // 3868964678
		{ &Z_Construct_UDelegateFunction_ACinematicDirector_OnCinematicStarted__DelegateSignature, "OnCinematicStarted__DelegateSignature" }, // 224823818
		{ &Z_Construct_UDelegateFunction_ACinematicDirector_OnNarrationSpoken__DelegateSignature, "OnNarrationSpoken__DelegateSignature" }, // 53661311
		{ &Z_Construct_UDelegateFunction_ACinematicDirector_OnShotChanged__DelegateSignature, "OnShotChanged__DelegateSignature" }, // 778040281
		{ &Z_Construct_UFunction_ACinematicDirector_PlayCinematicSequence, "PlayCinematicSequence" }, // 2430123962
		{ &Z_Construct_UFunction_ACinematicDirector_SetupCinematicCamera, "SetupCinematicCamera" }, // 1147562064
		{ &Z_Construct_UFunction_ACinematicDirector_SkipToNextShot, "SkipToNextShot" }, // 988645653
		{ &Z_Construct_UFunction_ACinematicDirector_StopCinematic, "StopCinematic" }, // 494196934
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACinematicDirector>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_ACinematicDirector_Statics::NewProp_OnCinematicStarted = { "OnCinematicStarted", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACinematicDirector, OnCinematicStarted), Z_Construct_UDelegateFunction_ACinematicDirector_OnCinematicStarted__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCinematicStarted_MetaData), NewProp_OnCinematicStarted_MetaData) }; // 224823818
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_ACinematicDirector_Statics::NewProp_OnCinematicFinished = { "OnCinematicFinished", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACinematicDirector, OnCinematicFinished), Z_Construct_UDelegateFunction_ACinematicDirector_OnCinematicFinished__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCinematicFinished_MetaData), NewProp_OnCinematicFinished_MetaData) }; // 3868964678
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_ACinematicDirector_Statics::NewProp_OnShotChanged = { "OnShotChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACinematicDirector, OnShotChanged), Z_Construct_UDelegateFunction_ACinematicDirector_OnShotChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnShotChanged_MetaData), NewProp_OnShotChanged_MetaData) }; // 778040281
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_ACinematicDirector_Statics::NewProp_OnNarrationSpoken = { "OnNarrationSpoken", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACinematicDirector, OnNarrationSpoken), Z_Construct_UDelegateFunction_ACinematicDirector_OnNarrationSpoken__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnNarrationSpoken_MetaData), NewProp_OnNarrationSpoken_MetaData) }; // 53661311
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACinematicDirector_Statics::NewProp_DefaultShotDuration = { "DefaultShotDuration", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACinematicDirector, DefaultShotDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultShotDuration_MetaData), NewProp_DefaultShotDuration_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACinematicDirector_Statics::NewProp_CameraTransitionTime = { "CameraTransitionTime", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACinematicDirector, CameraTransitionTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraTransitionTime_MetaData), NewProp_CameraTransitionTime_MetaData) };
void Z_Construct_UClass_ACinematicDirector_Statics::NewProp_bAutoGenerateShots_SetBit(void* Obj)
{
	((ACinematicDirector*)Obj)->bAutoGenerateShots = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ACinematicDirector_Statics::NewProp_bAutoGenerateShots = { "bAutoGenerateShots", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ACinematicDirector), &Z_Construct_UClass_ACinematicDirector_Statics::NewProp_bAutoGenerateShots_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAutoGenerateShots_MetaData), NewProp_bAutoGenerateShots_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ACinematicDirector_Statics::NewProp_MaxShotsPerSequence = { "MaxShotsPerSequence", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACinematicDirector, MaxShotsPerSequence), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxShotsPerSequence_MetaData), NewProp_MaxShotsPerSequence_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACinematicDirector_Statics::NewProp_NarrationSpeed = { "NarrationSpeed", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACinematicDirector, NarrationSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NarrationSpeed_MetaData), NewProp_NarrationSpeed_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_ACinematicDirector_Statics::NewProp_CinematicSoundMix = { "CinematicSoundMix", nullptr, (EPropertyFlags)0x0024080000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACinematicDirector, CinematicSoundMix), Z_Construct_UClass_USoundMix_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CinematicSoundMix_MetaData), NewProp_CinematicSoundMix_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACinematicDirector_Statics::NewProp_MusicVolume = { "MusicVolume", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACinematicDirector, MusicVolume), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MusicVolume_MetaData), NewProp_MusicVolume_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACinematicDirector_Statics::NewProp_NarrationVolume = { "NarrationVolume", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACinematicDirector, NarrationVolume), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NarrationVolume_MetaData), NewProp_NarrationVolume_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_ACinematicDirector_Statics::NewProp_OpeningTemplates_ValueProp = { "OpeningTemplates", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_ACinematicDirector_Statics::NewProp_OpeningTemplates_Key_KeyProp_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_ACinematicDirector_Statics::NewProp_OpeningTemplates_Key_KeyProp = { "OpeningTemplates_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_IronChess_ENarrativeTheme, METADATA_PARAMS(0, nullptr) }; // 3662323089
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_ACinematicDirector_Statics::NewProp_OpeningTemplates = { "OpeningTemplates", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACinematicDirector, OpeningTemplates), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OpeningTemplates_MetaData), NewProp_OpeningTemplates_MetaData) }; // 3662323089
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_ACinematicDirector_Statics::NewProp_ClosingTemplates_ValueProp = { "ClosingTemplates", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_ACinematicDirector_Statics::NewProp_ClosingTemplates_Key_KeyProp_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_ACinematicDirector_Statics::NewProp_ClosingTemplates_Key_KeyProp = { "ClosingTemplates_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_IronChess_ENarrativeTheme, METADATA_PARAMS(0, nullptr) }; // 3662323089
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_ACinematicDirector_Statics::NewProp_ClosingTemplates = { "ClosingTemplates", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACinematicDirector, ClosingTemplates), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClosingTemplates_MetaData), NewProp_ClosingTemplates_MetaData) }; // 3662323089
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_ACinematicDirector_Statics::NewProp_PieceDescriptions_ValueProp = { "PieceDescriptions", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_ACinematicDirector_Statics::NewProp_PieceDescriptions_Key_KeyProp_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_ACinematicDirector_Statics::NewProp_PieceDescriptions_Key_KeyProp = { "PieceDescriptions_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_IronChess_EPieceType, METADATA_PARAMS(0, nullptr) }; // 2986096202
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_ACinematicDirector_Statics::NewProp_PieceDescriptions = { "PieceDescriptions", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACinematicDirector, PieceDescriptions), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PieceDescriptions_MetaData), NewProp_PieceDescriptions_MetaData) }; // 2986096202
void Z_Construct_UClass_ACinematicDirector_Statics::NewProp_bIsPlayingCinematic_SetBit(void* Obj)
{
	((ACinematicDirector*)Obj)->bIsPlayingCinematic = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ACinematicDirector_Statics::NewProp_bIsPlayingCinematic = { "bIsPlayingCinematic", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ACinematicDirector), &Z_Construct_UClass_ACinematicDirector_Statics::NewProp_bIsPlayingCinematic_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsPlayingCinematic_MetaData), NewProp_bIsPlayingCinematic_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ACinematicDirector_Statics::NewProp_CurrentSequence = { "CurrentSequence", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACinematicDirector, CurrentSequence), Z_Construct_UScriptStruct_FCinematicSequence, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentSequence_MetaData), NewProp_CurrentSequence_MetaData) }; // 3391121615
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ACinematicDirector_Statics::NewProp_CurrentShotIndex = { "CurrentShotIndex", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACinematicDirector, CurrentShotIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentShotIndex_MetaData), NewProp_CurrentShotIndex_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ACinematicDirector_Statics::NewProp_CurrentShot = { "CurrentShot", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACinematicDirector, CurrentShot), Z_Construct_UScriptStruct_FCinematicShot, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentShot_MetaData), NewProp_CurrentShot_MetaData) }; // 3331727041
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACinematicDirector_Statics::NewProp_CurrentShotTime = { "CurrentShotTime", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACinematicDirector, CurrentShotTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentShotTime_MetaData), NewProp_CurrentShotTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACinematicDirector_Statics::NewProp_ShotElapsedTime = { "ShotElapsedTime", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACinematicDirector, ShotElapsedTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShotElapsedTime_MetaData), NewProp_ShotElapsedTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACinematicDirector_Statics::NewProp_TotalCinematicTime = { "TotalCinematicTime", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACinematicDirector, TotalCinematicTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalCinematicTime_MetaData), NewProp_TotalCinematicTime_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACinematicDirector_Statics::NewProp_CinematicCamera = { "CinematicCamera", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACinematicDirector, CinematicCamera), Z_Construct_UClass_ACineCameraActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CinematicCamera_MetaData), NewProp_CinematicCamera_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACinematicDirector_Statics::NewProp_BackgroundMusicComponent = { "BackgroundMusicComponent", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACinematicDirector, BackgroundMusicComponent), Z_Construct_UClass_UAudioComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BackgroundMusicComponent_MetaData), NewProp_BackgroundMusicComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACinematicDirector_Statics::NewProp_NarrationComponent = { "NarrationComponent", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACinematicDirector, NarrationComponent), Z_Construct_UClass_UAudioComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NarrationComponent_MetaData), NewProp_NarrationComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACinematicDirector_Statics::NewProp_SequencePlayer = { "SequencePlayer", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACinematicDirector, SequencePlayer), Z_Construct_UClass_ULevelSequencePlayer_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SequencePlayer_MetaData), NewProp_SequencePlayer_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACinematicDirector_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACinematicDirector_Statics::NewProp_OnCinematicStarted,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACinematicDirector_Statics::NewProp_OnCinematicFinished,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACinematicDirector_Statics::NewProp_OnShotChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACinematicDirector_Statics::NewProp_OnNarrationSpoken,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACinematicDirector_Statics::NewProp_DefaultShotDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACinematicDirector_Statics::NewProp_CameraTransitionTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACinematicDirector_Statics::NewProp_bAutoGenerateShots,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACinematicDirector_Statics::NewProp_MaxShotsPerSequence,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACinematicDirector_Statics::NewProp_NarrationSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACinematicDirector_Statics::NewProp_CinematicSoundMix,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACinematicDirector_Statics::NewProp_MusicVolume,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACinematicDirector_Statics::NewProp_NarrationVolume,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACinematicDirector_Statics::NewProp_OpeningTemplates_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACinematicDirector_Statics::NewProp_OpeningTemplates_Key_KeyProp_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACinematicDirector_Statics::NewProp_OpeningTemplates_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACinematicDirector_Statics::NewProp_OpeningTemplates,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACinematicDirector_Statics::NewProp_ClosingTemplates_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACinematicDirector_Statics::NewProp_ClosingTemplates_Key_KeyProp_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACinematicDirector_Statics::NewProp_ClosingTemplates_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACinematicDirector_Statics::NewProp_ClosingTemplates,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACinematicDirector_Statics::NewProp_PieceDescriptions_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACinematicDirector_Statics::NewProp_PieceDescriptions_Key_KeyProp_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACinematicDirector_Statics::NewProp_PieceDescriptions_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACinematicDirector_Statics::NewProp_PieceDescriptions,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACinematicDirector_Statics::NewProp_bIsPlayingCinematic,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACinematicDirector_Statics::NewProp_CurrentSequence,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACinematicDirector_Statics::NewProp_CurrentShotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACinematicDirector_Statics::NewProp_CurrentShot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACinematicDirector_Statics::NewProp_CurrentShotTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACinematicDirector_Statics::NewProp_ShotElapsedTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACinematicDirector_Statics::NewProp_TotalCinematicTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACinematicDirector_Statics::NewProp_CinematicCamera,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACinematicDirector_Statics::NewProp_BackgroundMusicComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACinematicDirector_Statics::NewProp_NarrationComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACinematicDirector_Statics::NewProp_SequencePlayer,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACinematicDirector_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ACinematicDirector_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_IronChess,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACinematicDirector_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACinematicDirector_Statics::ClassParams = {
	&ACinematicDirector::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ACinematicDirector_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ACinematicDirector_Statics::PropPointers),
	0,
	0x009001A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACinematicDirector_Statics::Class_MetaDataParams), Z_Construct_UClass_ACinematicDirector_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ACinematicDirector()
{
	if (!Z_Registration_Info_UClass_ACinematicDirector.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACinematicDirector.OuterSingleton, Z_Construct_UClass_ACinematicDirector_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACinematicDirector.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ACinematicDirector);
ACinematicDirector::~ACinematicDirector() {}
// ********** End Class ACinematicDirector *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Cinematic_CinematicDirector_h__Script_IronChess_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ ECinematicPhase_StaticEnum, TEXT("ECinematicPhase"), &Z_Registration_Info_UEnum_ECinematicPhase, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2960331212U) },
		{ ENarrativeTheme_StaticEnum, TEXT("ENarrativeTheme"), &Z_Registration_Info_UEnum_ENarrativeTheme, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3662323089U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FCinematicShot::StaticStruct, Z_Construct_UScriptStruct_FCinematicShot_Statics::NewStructOps, TEXT("CinematicShot"), &Z_Registration_Info_UScriptStruct_FCinematicShot, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCinematicShot), 3331727041U) },
		{ FCinematicSequence::StaticStruct, Z_Construct_UScriptStruct_FCinematicSequence_Statics::NewStructOps, TEXT("CinematicSequence"), &Z_Registration_Info_UScriptStruct_FCinematicSequence, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCinematicSequence), 3391121615U) },
		{ FGameAnalysis::StaticStruct, Z_Construct_UScriptStruct_FGameAnalysis_Statics::NewStructOps, TEXT("GameAnalysis"), &Z_Registration_Info_UScriptStruct_FGameAnalysis, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FGameAnalysis), 2277182007U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACinematicDirector, ACinematicDirector::StaticClass, TEXT("ACinematicDirector"), &Z_Registration_Info_UClass_ACinematicDirector, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACinematicDirector), 930759600U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Cinematic_CinematicDirector_h__Script_IronChess_1732563070(TEXT("/Script/IronChess"),
	Z_CompiledInDeferFile_FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Cinematic_CinematicDirector_h__Script_IronChess_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Cinematic_CinematicDirector_h__Script_IronChess_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Cinematic_CinematicDirector_h__Script_IronChess_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Cinematic_CinematicDirector_h__Script_IronChess_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Cinematic_CinematicDirector_h__Script_IronChess_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Cinematic_CinematicDirector_h__Script_IronChess_Statics::EnumInfo));
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
