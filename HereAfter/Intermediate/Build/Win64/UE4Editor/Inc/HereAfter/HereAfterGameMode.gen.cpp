// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HereAfter/HereAfterGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHereAfterGameMode() {}
// Cross Module References
	HEREAFTER_API UClass* Z_Construct_UClass_AHereAfterGameMode_NoRegister();
	HEREAFTER_API UClass* Z_Construct_UClass_AHereAfterGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_HereAfter();
// End Cross Module References
	void AHereAfterGameMode::StaticRegisterNativesAHereAfterGameMode()
	{
	}
	UClass* Z_Construct_UClass_AHereAfterGameMode_NoRegister()
	{
		return AHereAfterGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AHereAfterGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AHereAfterGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_HereAfter,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHereAfterGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "HereAfterGameMode.h" },
		{ "ModuleRelativePath", "HereAfterGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AHereAfterGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHereAfterGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AHereAfterGameMode_Statics::ClassParams = {
		&AHereAfterGameMode::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802A8u,
		METADATA_PARAMS(Z_Construct_UClass_AHereAfterGameMode_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AHereAfterGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AHereAfterGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AHereAfterGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AHereAfterGameMode, 1520685402);
	template<> HEREAFTER_API UClass* StaticClass<AHereAfterGameMode>()
	{
		return AHereAfterGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AHereAfterGameMode(Z_Construct_UClass_AHereAfterGameMode, &AHereAfterGameMode::StaticClass, TEXT("/Script/HereAfter"), TEXT("AHereAfterGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AHereAfterGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
