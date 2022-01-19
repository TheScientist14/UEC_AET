// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GC_UE4CPP/AI_Enemie.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAI_Enemie() {}
// Cross Module References
	GC_UE4CPP_API UClass* Z_Construct_UClass_AAI_Enemie_NoRegister();
	GC_UE4CPP_API UClass* Z_Construct_UClass_AAI_Enemie();
	AIMODULE_API UClass* Z_Construct_UClass_AAIController();
	UPackage* Z_Construct_UPackage__Script_GC_UE4CPP();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AAI_Enemie::execGoToRandomPoints)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->GoToRandomPoints();
		P_NATIVE_END;
	}
	void AAI_Enemie::StaticRegisterNativesAAI_Enemie()
	{
		UClass* Class = AAI_Enemie::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GoToRandomPoints", &AAI_Enemie::execGoToRandomPoints },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AAI_Enemie_GoToRandomPoints_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AAI_Enemie_GoToRandomPoints_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "AI_Enemie.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AAI_Enemie_GoToRandomPoints_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AAI_Enemie, nullptr, "GoToRandomPoints", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AAI_Enemie_GoToRandomPoints_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AAI_Enemie_GoToRandomPoints_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AAI_Enemie_GoToRandomPoints()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AAI_Enemie_GoToRandomPoints_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AAI_Enemie_NoRegister()
	{
		return AAI_Enemie::StaticClass();
	}
	struct Z_Construct_UClass_AAI_Enemie_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Points_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Points_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Points;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AAI_Enemie_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AAIController,
		(UObject* (*)())Z_Construct_UPackage__Script_GC_UE4CPP,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AAI_Enemie_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AAI_Enemie_GoToRandomPoints, "GoToRandomPoints" }, // 564765510
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAI_Enemie_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "AI_Enemie.h" },
		{ "ModuleRelativePath", "AI_Enemie.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAI_Enemie_Statics::NewProp_Points_Inner = { "Points", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAI_Enemie_Statics::NewProp_Points_MetaData[] = {
		{ "ModuleRelativePath", "AI_Enemie.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AAI_Enemie_Statics::NewProp_Points = { "Points", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAI_Enemie, Points), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_AAI_Enemie_Statics::NewProp_Points_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAI_Enemie_Statics::NewProp_Points_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AAI_Enemie_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAI_Enemie_Statics::NewProp_Points_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAI_Enemie_Statics::NewProp_Points,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AAI_Enemie_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAI_Enemie>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AAI_Enemie_Statics::ClassParams = {
		&AAI_Enemie::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AAI_Enemie_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AAI_Enemie_Statics::PropPointers),
		0,
		0x009002A4u,
		METADATA_PARAMS(Z_Construct_UClass_AAI_Enemie_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AAI_Enemie_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AAI_Enemie()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AAI_Enemie_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AAI_Enemie, 4185383557);
	template<> GC_UE4CPP_API UClass* StaticClass<AAI_Enemie>()
	{
		return AAI_Enemie::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AAI_Enemie(Z_Construct_UClass_AAI_Enemie, &AAI_Enemie::StaticClass, TEXT("/Script/GC_UE4CPP"), TEXT("AAI_Enemie"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AAI_Enemie);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
