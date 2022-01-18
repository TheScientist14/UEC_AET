// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GC_UE4CPP/Goblin.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGoblin() {}
// Cross Module References
	GC_UE4CPP_API UClass* Z_Construct_UClass_AGoblin_NoRegister();
	GC_UE4CPP_API UClass* Z_Construct_UClass_AGoblin();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_GC_UE4CPP();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	void AGoblin::StaticRegisterNativesAGoblin()
	{
	}
	UClass* Z_Construct_UClass_AGoblin_NoRegister()
	{
		return AGoblin::StaticClass();
	}
	struct Z_Construct_UClass_AGoblin_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Food_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Food;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_StaticMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_StaticMesh;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Spots_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Spots_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Spots;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGoblin_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_GC_UE4CPP,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGoblin_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Goblin.h" },
		{ "ModuleRelativePath", "Goblin.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGoblin_Statics::NewProp_Food_MetaData[] = {
		{ "Category", "Goblin" },
		{ "ModuleRelativePath", "Goblin.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGoblin_Statics::NewProp_Food = { "Food", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGoblin, Food), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AGoblin_Statics::NewProp_Food_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AGoblin_Statics::NewProp_Food_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGoblin_Statics::NewProp_StaticMesh_MetaData[] = {
		{ "Category", "Goblin" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Goblin.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGoblin_Statics::NewProp_StaticMesh = { "StaticMesh", nullptr, (EPropertyFlags)0x0020080000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGoblin, StaticMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AGoblin_Statics::NewProp_StaticMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AGoblin_Statics::NewProp_StaticMesh_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGoblin_Statics::NewProp_Spots_Inner = { "Spots", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGoblin_Statics::NewProp_Spots_MetaData[] = {
		{ "Category", "Goblin" },
		{ "ModuleRelativePath", "Goblin.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AGoblin_Statics::NewProp_Spots = { "Spots", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGoblin, Spots), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_AGoblin_Statics::NewProp_Spots_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AGoblin_Statics::NewProp_Spots_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGoblin_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGoblin_Statics::NewProp_Food,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGoblin_Statics::NewProp_StaticMesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGoblin_Statics::NewProp_Spots_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGoblin_Statics::NewProp_Spots,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGoblin_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGoblin>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGoblin_Statics::ClassParams = {
		&AGoblin::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AGoblin_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AGoblin_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AGoblin_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AGoblin_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGoblin()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGoblin_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGoblin, 2479064468);
	template<> GC_UE4CPP_API UClass* StaticClass<AGoblin>()
	{
		return AGoblin::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGoblin(Z_Construct_UClass_AGoblin, &AGoblin::StaticClass, TEXT("/Script/GC_UE4CPP"), TEXT("AGoblin"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGoblin);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
