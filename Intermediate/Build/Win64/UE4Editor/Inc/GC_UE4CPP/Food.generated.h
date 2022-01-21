// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GC_UE4CPP_Food_generated_h
#error "Food.generated.h already included, missing '#pragma once' in Food.h"
#endif
#define GC_UE4CPP_Food_generated_h

#define GC_UE4CPP_Source_GC_UE4CPP_Food_h_12_SPARSE_DATA
#define GC_UE4CPP_Source_GC_UE4CPP_Food_h_12_RPC_WRAPPERS
#define GC_UE4CPP_Source_GC_UE4CPP_Food_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define GC_UE4CPP_Source_GC_UE4CPP_Food_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFood(); \
	friend struct Z_Construct_UClass_AFood_Statics; \
public: \
	DECLARE_CLASS(AFood, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GC_UE4CPP"), NO_API) \
	DECLARE_SERIALIZER(AFood)


#define GC_UE4CPP_Source_GC_UE4CPP_Food_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAFood(); \
	friend struct Z_Construct_UClass_AFood_Statics; \
public: \
	DECLARE_CLASS(AFood, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GC_UE4CPP"), NO_API) \
	DECLARE_SERIALIZER(AFood)


#define GC_UE4CPP_Source_GC_UE4CPP_Food_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFood(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFood) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFood); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFood); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFood(AFood&&); \
	NO_API AFood(const AFood&); \
public:


#define GC_UE4CPP_Source_GC_UE4CPP_Food_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFood(AFood&&); \
	NO_API AFood(const AFood&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFood); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFood); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFood)


#define GC_UE4CPP_Source_GC_UE4CPP_Food_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__StaticMesh() { return STRUCT_OFFSET(AFood, StaticMesh); }


#define GC_UE4CPP_Source_GC_UE4CPP_Food_h_9_PROLOG
#define GC_UE4CPP_Source_GC_UE4CPP_Food_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GC_UE4CPP_Source_GC_UE4CPP_Food_h_12_PRIVATE_PROPERTY_OFFSET \
	GC_UE4CPP_Source_GC_UE4CPP_Food_h_12_SPARSE_DATA \
	GC_UE4CPP_Source_GC_UE4CPP_Food_h_12_RPC_WRAPPERS \
	GC_UE4CPP_Source_GC_UE4CPP_Food_h_12_INCLASS \
	GC_UE4CPP_Source_GC_UE4CPP_Food_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GC_UE4CPP_Source_GC_UE4CPP_Food_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GC_UE4CPP_Source_GC_UE4CPP_Food_h_12_PRIVATE_PROPERTY_OFFSET \
	GC_UE4CPP_Source_GC_UE4CPP_Food_h_12_SPARSE_DATA \
	GC_UE4CPP_Source_GC_UE4CPP_Food_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	GC_UE4CPP_Source_GC_UE4CPP_Food_h_12_INCLASS_NO_PURE_DECLS \
	GC_UE4CPP_Source_GC_UE4CPP_Food_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GC_UE4CPP_API UClass* StaticClass<class AFood>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID GC_UE4CPP_Source_GC_UE4CPP_Food_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
