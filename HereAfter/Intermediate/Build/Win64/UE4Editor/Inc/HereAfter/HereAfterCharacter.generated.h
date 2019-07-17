// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef HEREAFTER_HereAfterCharacter_generated_h
#error "HereAfterCharacter.generated.h already included, missing '#pragma once' in HereAfterCharacter.h"
#endif
#define HEREAFTER_HereAfterCharacter_generated_h

#define HereAfter_Source_HereAfter_HereAfterCharacter_h_14_RPC_WRAPPERS
#define HereAfter_Source_HereAfter_HereAfterCharacter_h_14_RPC_WRAPPERS_NO_PURE_DECLS
#define HereAfter_Source_HereAfter_HereAfterCharacter_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAHereAfterCharacter(); \
	friend struct Z_Construct_UClass_AHereAfterCharacter_Statics; \
public: \
	DECLARE_CLASS(AHereAfterCharacter, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/HereAfter"), NO_API) \
	DECLARE_SERIALIZER(AHereAfterCharacter)


#define HereAfter_Source_HereAfter_HereAfterCharacter_h_14_INCLASS \
private: \
	static void StaticRegisterNativesAHereAfterCharacter(); \
	friend struct Z_Construct_UClass_AHereAfterCharacter_Statics; \
public: \
	DECLARE_CLASS(AHereAfterCharacter, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/HereAfter"), NO_API) \
	DECLARE_SERIALIZER(AHereAfterCharacter)


#define HereAfter_Source_HereAfter_HereAfterCharacter_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AHereAfterCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AHereAfterCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AHereAfterCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AHereAfterCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AHereAfterCharacter(AHereAfterCharacter&&); \
	NO_API AHereAfterCharacter(const AHereAfterCharacter&); \
public:


#define HereAfter_Source_HereAfter_HereAfterCharacter_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AHereAfterCharacter(AHereAfterCharacter&&); \
	NO_API AHereAfterCharacter(const AHereAfterCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AHereAfterCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AHereAfterCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AHereAfterCharacter)


#define HereAfter_Source_HereAfter_HereAfterCharacter_h_14_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Mesh1P() { return STRUCT_OFFSET(AHereAfterCharacter, Mesh1P); } \
	FORCEINLINE static uint32 __PPO__FP_Gun() { return STRUCT_OFFSET(AHereAfterCharacter, FP_Gun); } \
	FORCEINLINE static uint32 __PPO__FP_MuzzleLocation() { return STRUCT_OFFSET(AHereAfterCharacter, FP_MuzzleLocation); } \
	FORCEINLINE static uint32 __PPO__VR_Gun() { return STRUCT_OFFSET(AHereAfterCharacter, VR_Gun); } \
	FORCEINLINE static uint32 __PPO__VR_MuzzleLocation() { return STRUCT_OFFSET(AHereAfterCharacter, VR_MuzzleLocation); } \
	FORCEINLINE static uint32 __PPO__FirstPersonCameraComponent() { return STRUCT_OFFSET(AHereAfterCharacter, FirstPersonCameraComponent); } \
	FORCEINLINE static uint32 __PPO__R_MotionController() { return STRUCT_OFFSET(AHereAfterCharacter, R_MotionController); } \
	FORCEINLINE static uint32 __PPO__L_MotionController() { return STRUCT_OFFSET(AHereAfterCharacter, L_MotionController); }


#define HereAfter_Source_HereAfter_HereAfterCharacter_h_11_PROLOG
#define HereAfter_Source_HereAfter_HereAfterCharacter_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HereAfter_Source_HereAfter_HereAfterCharacter_h_14_PRIVATE_PROPERTY_OFFSET \
	HereAfter_Source_HereAfter_HereAfterCharacter_h_14_RPC_WRAPPERS \
	HereAfter_Source_HereAfter_HereAfterCharacter_h_14_INCLASS \
	HereAfter_Source_HereAfter_HereAfterCharacter_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define HereAfter_Source_HereAfter_HereAfterCharacter_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HereAfter_Source_HereAfter_HereAfterCharacter_h_14_PRIVATE_PROPERTY_OFFSET \
	HereAfter_Source_HereAfter_HereAfterCharacter_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	HereAfter_Source_HereAfter_HereAfterCharacter_h_14_INCLASS_NO_PURE_DECLS \
	HereAfter_Source_HereAfter_HereAfterCharacter_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> HEREAFTER_API UClass* StaticClass<class AHereAfterCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID HereAfter_Source_HereAfter_HereAfterCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
