// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Animation/BattleSequenceComponent.h"

#ifdef IRONCHESS_BattleSequenceComponent_generated_h
#error "BattleSequenceComponent.generated.h already included, missing '#pragma once' in BattleSequenceComponent.h"
#endif
#define IRONCHESS_BattleSequenceComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

enum class EBattleSequenceType : uint8;
struct FBattleContext;
struct FBattleSequenceConfig;
struct FChessMove;

// ********** Begin ScriptStruct FBattleSequenceConfig *********************************************
#define FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Animation_BattleSequenceComponent_h_37_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FBattleSequenceConfig_Statics; \
	static class UScriptStruct* StaticStruct();


struct FBattleSequenceConfig;
// ********** End ScriptStruct FBattleSequenceConfig ***********************************************

// ********** Begin ScriptStruct FBattleContext ****************************************************
#define FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Animation_BattleSequenceComponent_h_72_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FBattleContext_Statics; \
	static class UScriptStruct* StaticStruct();


struct FBattleContext;
// ********** End ScriptStruct FBattleContext ******************************************************

// ********** Begin Delegate FOnBattleSequenceStarted **********************************************
#define FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Animation_BattleSequenceComponent_h_159_DELEGATE \
static void FOnBattleSequenceStarted_DelegateWrapper(const FMulticastScriptDelegate& OnBattleSequenceStarted, EBattleSequenceType BattleType);


// ********** End Delegate FOnBattleSequenceStarted ************************************************

// ********** Begin Delegate FOnBattleSequenceFinished *********************************************
#define FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Animation_BattleSequenceComponent_h_160_DELEGATE \
static void FOnBattleSequenceFinished_DelegateWrapper(const FMulticastScriptDelegate& OnBattleSequenceFinished, EBattleSequenceType BattleType);


// ********** End Delegate FOnBattleSequenceFinished ***********************************************

// ********** Begin Delegate FOnBattleSequenceProgress *********************************************
#define FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Animation_BattleSequenceComponent_h_161_DELEGATE \
static void FOnBattleSequenceProgress_DelegateWrapper(const FMulticastScriptDelegate& OnBattleSequenceProgress, EBattleSequenceType BattleType, float Progress);


// ********** End Delegate FOnBattleSequenceProgress ***********************************************

// ********** Begin Class UBattleSequenceComponent *************************************************
#define FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Animation_BattleSequenceComponent_h_119_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetCurrentBattleProgress); \
	DECLARE_FUNCTION(execIsPlayingBattleSequence); \
	DECLARE_FUNCTION(execGetBattleFrequency); \
	DECLARE_FUNCTION(execSetBattleFrequency); \
	DECLARE_FUNCTION(execGetBattleConfig); \
	DECLARE_FUNCTION(execSetBattleConfig); \
	DECLARE_FUNCTION(execStopCurrentBattle); \
	DECLARE_FUNCTION(execDetermineBattleType); \
	DECLARE_FUNCTION(execShouldTriggerBattle); \
	DECLARE_FUNCTION(execTriggerBattleSequence);


IRONCHESS_API UClass* Z_Construct_UClass_UBattleSequenceComponent_NoRegister();

#define FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Animation_BattleSequenceComponent_h_119_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUBattleSequenceComponent(); \
	friend struct Z_Construct_UClass_UBattleSequenceComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend IRONCHESS_API UClass* Z_Construct_UClass_UBattleSequenceComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UBattleSequenceComponent, USceneComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/IronChess"), Z_Construct_UClass_UBattleSequenceComponent_NoRegister) \
	DECLARE_SERIALIZER(UBattleSequenceComponent)


#define FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Animation_BattleSequenceComponent_h_119_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UBattleSequenceComponent(UBattleSequenceComponent&&) = delete; \
	UBattleSequenceComponent(const UBattleSequenceComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UBattleSequenceComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UBattleSequenceComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UBattleSequenceComponent) \
	NO_API virtual ~UBattleSequenceComponent();


#define FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Animation_BattleSequenceComponent_h_116_PROLOG
#define FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Animation_BattleSequenceComponent_h_119_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Animation_BattleSequenceComponent_h_119_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Animation_BattleSequenceComponent_h_119_INCLASS_NO_PURE_DECLS \
	FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Animation_BattleSequenceComponent_h_119_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UBattleSequenceComponent;

// ********** End Class UBattleSequenceComponent ***************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_samuelabdelsayed_Documents_Repositories_iron_chess_Source_IronChess_Animation_BattleSequenceComponent_h

// ********** Begin Enum EBattleSequenceType *******************************************************
#define FOREACH_ENUM_EBATTLESEQUENCETYPE(op) \
	op(EBattleSequenceType::None) \
	op(EBattleSequenceType::PawnCapture) \
	op(EBattleSequenceType::KnightCapture) \
	op(EBattleSequenceType::RookCapture) \
	op(EBattleSequenceType::BishopCapture) \
	op(EBattleSequenceType::QueenCapture) \
	op(EBattleSequenceType::KingCapture) \
	op(EBattleSequenceType::Castling) \
	op(EBattleSequenceType::EnPassant) \
	op(EBattleSequenceType::Promotion) \
	op(EBattleSequenceType::Check) \
	op(EBattleSequenceType::Checkmate) 

enum class EBattleSequenceType : uint8;
template<> struct TIsUEnumClass<EBattleSequenceType> { enum { Value = true }; };
template<> IRONCHESS_API UEnum* StaticEnum<EBattleSequenceType>();
// ********** End Enum EBattleSequenceType *********************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
