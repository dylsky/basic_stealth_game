// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FHitResult;
#ifdef FPSGAME_FPSLaunchpad_generated_h
#error "FPSLaunchpad.generated.h already included, missing '#pragma once' in FPSLaunchpad.h"
#endif
#define FPSGAME_FPSLaunchpad_generated_h

#define StealthGame_Source_FPSGame_Public_FPSLaunchpad_h_14_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execLaunch) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Launch(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	}


#define StealthGame_Source_FPSGame_Public_FPSLaunchpad_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execLaunch) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Launch(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	}


#define StealthGame_Source_FPSGame_Public_FPSLaunchpad_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFPSLaunchpad(); \
	friend FPSGAME_API class UClass* Z_Construct_UClass_AFPSLaunchpad(); \
public: \
	DECLARE_CLASS(AFPSLaunchpad, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/FPSGame"), NO_API) \
	DECLARE_SERIALIZER(AFPSLaunchpad) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define StealthGame_Source_FPSGame_Public_FPSLaunchpad_h_14_INCLASS \
private: \
	static void StaticRegisterNativesAFPSLaunchpad(); \
	friend FPSGAME_API class UClass* Z_Construct_UClass_AFPSLaunchpad(); \
public: \
	DECLARE_CLASS(AFPSLaunchpad, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/FPSGame"), NO_API) \
	DECLARE_SERIALIZER(AFPSLaunchpad) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define StealthGame_Source_FPSGame_Public_FPSLaunchpad_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFPSLaunchpad(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFPSLaunchpad) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFPSLaunchpad); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFPSLaunchpad); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFPSLaunchpad(AFPSLaunchpad&&); \
	NO_API AFPSLaunchpad(const AFPSLaunchpad&); \
public:


#define StealthGame_Source_FPSGame_Public_FPSLaunchpad_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFPSLaunchpad(AFPSLaunchpad&&); \
	NO_API AFPSLaunchpad(const AFPSLaunchpad&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFPSLaunchpad); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFPSLaunchpad); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFPSLaunchpad)


#define StealthGame_Source_FPSGame_Public_FPSLaunchpad_h_14_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__MeshComp() { return STRUCT_OFFSET(AFPSLaunchpad, MeshComp); } \
	FORCEINLINE static uint32 __PPO__OverlapComp() { return STRUCT_OFFSET(AFPSLaunchpad, OverlapComp); } \
	FORCEINLINE static uint32 __PPO__StaticFX() { return STRUCT_OFFSET(AFPSLaunchpad, StaticFX); }


#define StealthGame_Source_FPSGame_Public_FPSLaunchpad_h_11_PROLOG
#define StealthGame_Source_FPSGame_Public_FPSLaunchpad_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	StealthGame_Source_FPSGame_Public_FPSLaunchpad_h_14_PRIVATE_PROPERTY_OFFSET \
	StealthGame_Source_FPSGame_Public_FPSLaunchpad_h_14_RPC_WRAPPERS \
	StealthGame_Source_FPSGame_Public_FPSLaunchpad_h_14_INCLASS \
	StealthGame_Source_FPSGame_Public_FPSLaunchpad_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define StealthGame_Source_FPSGame_Public_FPSLaunchpad_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	StealthGame_Source_FPSGame_Public_FPSLaunchpad_h_14_PRIVATE_PROPERTY_OFFSET \
	StealthGame_Source_FPSGame_Public_FPSLaunchpad_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	StealthGame_Source_FPSGame_Public_FPSLaunchpad_h_14_INCLASS_NO_PURE_DECLS \
	StealthGame_Source_FPSGame_Public_FPSLaunchpad_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID StealthGame_Source_FPSGame_Public_FPSLaunchpad_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
