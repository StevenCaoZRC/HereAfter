// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HereAfter/HereAfterHUD.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHereAfterHUD() {}
// Cross Module References
	HEREAFTER_API UClass* Z_Construct_UClass_AHereAfterHUD_NoRegister();
	HEREAFTER_API UClass* Z_Construct_UClass_AHereAfterHUD();
	ENGINE_API UClass* Z_Construct_UClass_AHUD();
	UPackage* Z_Construct_UPackage__Script_HereAfter();
// End Cross Module References
	void AHereAfterHUD::StaticRegisterNativesAHereAfterHUD()
	{
	}
	UClass* Z_Construct_UClass_AHereAfterHUD_NoRegister()
	{
		return AHereAfterHUD::StaticClass();
	}
	struct Z_Construct_UClass_AHereAfterHUD_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AHereAfterHUD_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AHUD,
		(UObject* (*)())Z_Construct_UPackage__Script_HereAfter,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHereAfterHUD_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Rendering Actor Input Replication" },
		{ "IncludePath", "HereAfterHUD.h" },
		{ "ModuleRelativePath", "HereAfterHUD.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AHereAfterHUD_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHereAfterHUD>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AHereAfterHUD_Statics::ClassParams = {
		&AHereAfterHUD::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AHereAfterHUD_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AHereAfterHUD_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AHereAfterHUD()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AHereAfterHUD_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AHereAfterHUD, 3293951686);
	template<> HEREAFTER_API UClass* StaticClass<AHereAfterHUD>()
	{
		return AHereAfterHUD::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AHereAfterHUD(Z_Construct_UClass_AHereAfterHUD, &AHereAfterHUD::StaticClass, TEXT("/Script/HereAfter"), TEXT("AHereAfterHUD"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AHereAfterHUD);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
