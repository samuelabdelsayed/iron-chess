// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeIronChess_init() {}
	IRONCHESS_API UFunction* Z_Construct_UDelegateFunction_ACinematicDirector_OnCinematicFinished__DelegateSignature();
	IRONCHESS_API UFunction* Z_Construct_UDelegateFunction_ACinematicDirector_OnCinematicStarted__DelegateSignature();
	IRONCHESS_API UFunction* Z_Construct_UDelegateFunction_ACinematicDirector_OnNarrationSpoken__DelegateSignature();
	IRONCHESS_API UFunction* Z_Construct_UDelegateFunction_ACinematicDirector_OnShotChanged__DelegateSignature();
	IRONCHESS_API UFunction* Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceFinished__DelegateSignature();
	IRONCHESS_API UFunction* Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceProgress__DelegateSignature();
	IRONCHESS_API UFunction* Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceStarted__DelegateSignature();
	IRONCHESS_API UFunction* Z_Construct_UDelegateFunction_UChessAIComponent_OnAIMoveCalculated__DelegateSignature();
	IRONCHESS_API UFunction* Z_Construct_UDelegateFunction_UChessAIComponent_OnAIThinking__DelegateSignature();
	IRONCHESS_API UFunction* Z_Construct_UDelegateFunction_UChessGameLogic_OnCheck__DelegateSignature();
	IRONCHESS_API UFunction* Z_Construct_UDelegateFunction_UChessGameLogic_OnGameStateChanged__DelegateSignature();
	IRONCHESS_API UFunction* Z_Construct_UDelegateFunction_UChessGameLogic_OnMoveMade__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_IronChess;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_IronChess()
	{
		if (!Z_Registration_Info_UPackage__Script_IronChess.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_ACinematicDirector_OnCinematicFinished__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_ACinematicDirector_OnCinematicStarted__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_ACinematicDirector_OnNarrationSpoken__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_ACinematicDirector_OnShotChanged__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceFinished__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceProgress__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_UBattleSequenceComponent_OnBattleSequenceStarted__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_UChessAIComponent_OnAIMoveCalculated__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_UChessAIComponent_OnAIThinking__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_UChessGameLogic_OnCheck__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_UChessGameLogic_OnGameStateChanged__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_UChessGameLogic_OnMoveMade__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/IronChess",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x01DA6F0D,
				0xD61D6E6C,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_IronChess.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_IronChess.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_IronChess(Z_Construct_UPackage__Script_IronChess, TEXT("/Script/IronChess"), Z_Registration_Info_UPackage__Script_IronChess, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x01DA6F0D, 0xD61D6E6C));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
