// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TOONSHADER_ToonShaderBPLibrary_generated_h
#error "ToonShaderBPLibrary.generated.h already included, missing '#pragma once' in ToonShaderBPLibrary.h"
#endif
#define TOONSHADER_ToonShaderBPLibrary_generated_h

#define HostProject_Plugins_ToonShader_Source_ToonShader_Public_ToonShaderBPLibrary_h_28_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execToonShaderSampleFunction) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Param); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=UToonShaderBPLibrary::ToonShaderSampleFunction(Z_Param_Param); \
		P_NATIVE_END; \
	}


#define HostProject_Plugins_ToonShader_Source_ToonShader_Public_ToonShaderBPLibrary_h_28_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execToonShaderSampleFunction) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Param); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=UToonShaderBPLibrary::ToonShaderSampleFunction(Z_Param_Param); \
		P_NATIVE_END; \
	}


#define HostProject_Plugins_ToonShader_Source_ToonShader_Public_ToonShaderBPLibrary_h_28_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUToonShaderBPLibrary(); \
	friend TOONSHADER_API class UClass* Z_Construct_UClass_UToonShaderBPLibrary(); \
public: \
	DECLARE_CLASS(UToonShaderBPLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/ToonShader"), NO_API) \
	DECLARE_SERIALIZER(UToonShaderBPLibrary) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define HostProject_Plugins_ToonShader_Source_ToonShader_Public_ToonShaderBPLibrary_h_28_INCLASS \
private: \
	static void StaticRegisterNativesUToonShaderBPLibrary(); \
	friend TOONSHADER_API class UClass* Z_Construct_UClass_UToonShaderBPLibrary(); \
public: \
	DECLARE_CLASS(UToonShaderBPLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/ToonShader"), NO_API) \
	DECLARE_SERIALIZER(UToonShaderBPLibrary) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define HostProject_Plugins_ToonShader_Source_ToonShader_Public_ToonShaderBPLibrary_h_28_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UToonShaderBPLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UToonShaderBPLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UToonShaderBPLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UToonShaderBPLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UToonShaderBPLibrary(UToonShaderBPLibrary&&); \
	NO_API UToonShaderBPLibrary(const UToonShaderBPLibrary&); \
public:


#define HostProject_Plugins_ToonShader_Source_ToonShader_Public_ToonShaderBPLibrary_h_28_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UToonShaderBPLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UToonShaderBPLibrary(UToonShaderBPLibrary&&); \
	NO_API UToonShaderBPLibrary(const UToonShaderBPLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UToonShaderBPLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UToonShaderBPLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UToonShaderBPLibrary)


#define HostProject_Plugins_ToonShader_Source_ToonShader_Public_ToonShaderBPLibrary_h_28_PRIVATE_PROPERTY_OFFSET
#define HostProject_Plugins_ToonShader_Source_ToonShader_Public_ToonShaderBPLibrary_h_25_PROLOG
#define HostProject_Plugins_ToonShader_Source_ToonShader_Public_ToonShaderBPLibrary_h_28_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_ToonShader_Source_ToonShader_Public_ToonShaderBPLibrary_h_28_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_ToonShader_Source_ToonShader_Public_ToonShaderBPLibrary_h_28_RPC_WRAPPERS \
	HostProject_Plugins_ToonShader_Source_ToonShader_Public_ToonShaderBPLibrary_h_28_INCLASS \
	HostProject_Plugins_ToonShader_Source_ToonShader_Public_ToonShaderBPLibrary_h_28_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define HostProject_Plugins_ToonShader_Source_ToonShader_Public_ToonShaderBPLibrary_h_28_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_ToonShader_Source_ToonShader_Public_ToonShaderBPLibrary_h_28_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_ToonShader_Source_ToonShader_Public_ToonShaderBPLibrary_h_28_RPC_WRAPPERS_NO_PURE_DECLS \
	HostProject_Plugins_ToonShader_Source_ToonShader_Public_ToonShaderBPLibrary_h_28_INCLASS_NO_PURE_DECLS \
	HostProject_Plugins_ToonShader_Source_ToonShader_Public_ToonShaderBPLibrary_h_28_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class ToonShaderBPLibrary."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID HostProject_Plugins_ToonShader_Source_ToonShader_Public_ToonShaderBPLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
