// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GC_UE4CPP/MyPlayerController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyPlayerController() {}
// Cross Module References
	GC_UE4CPP_API UClass* Z_Construct_UClass_AMyPlayerController_NoRegister();
	GC_UE4CPP_API UClass* Z_Construct_UClass_AMyPlayerController();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	UPackage* Z_Construct_UPackage__Script_GC_UE4CPP();
// End Cross Module References
	DEFINE_FUNCTION(AMyPlayerController::execMoveRight)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_DeltaY);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->MoveRight(Z_Param_DeltaY);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyPlayerController::execMoveForward)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_DeltaX);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->MoveForward(Z_Param_DeltaX);
		P_NATIVE_END;
	}
	void AMyPlayerController::StaticRegisterNativesAMyPlayerController()
	{
		UClass* Class = AMyPlayerController::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "MoveForward", &AMyPlayerController::execMoveForward },
			{ "MoveRight", &AMyPlayerController::execMoveRight },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AMyPlayerController_MoveForward_Statics
	{
		struct MyPlayerController_eventMoveForward_Parms
		{
			float DeltaX;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DeltaX;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AMyPlayerController_MoveForward_Statics::NewProp_DeltaX = { "DeltaX", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyPlayerController_eventMoveForward_Parms, DeltaX), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyPlayerController_MoveForward_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyPlayerController_MoveForward_Statics::NewProp_DeltaX,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyPlayerController_MoveForward_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyPlayerController_MoveForward_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyPlayerController, nullptr, "MoveForward", nullptr, nullptr, sizeof(MyPlayerController_eventMoveForward_Parms), Z_Construct_UFunction_AMyPlayerController_MoveForward_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayerController_MoveForward_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyPlayerController_MoveForward_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayerController_MoveForward_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyPlayerController_MoveForward()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyPlayerController_MoveForward_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyPlayerController_MoveRight_Statics
	{
		struct MyPlayerController_eventMoveRight_Parms
		{
			float DeltaY;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DeltaY;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AMyPlayerController_MoveRight_Statics::NewProp_DeltaY = { "DeltaY", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyPlayerController_eventMoveRight_Parms, DeltaY), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyPlayerController_MoveRight_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyPlayerController_MoveRight_Statics::NewProp_DeltaY,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyPlayerController_MoveRight_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyPlayerController_MoveRight_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyPlayerController, nullptr, "MoveRight", nullptr, nullptr, sizeof(MyPlayerController_eventMoveRight_Parms), Z_Construct_UFunction_AMyPlayerController_MoveRight_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayerController_MoveRight_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyPlayerController_MoveRight_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayerController_MoveRight_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyPlayerController_MoveRight()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyPlayerController_MoveRight_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AMyPlayerController_NoRegister()
	{
		return AMyPlayerController::StaticClass();
	}
	struct Z_Construct_UClass_AMyPlayerController_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMyPlayerController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerController,
		(UObject* (*)())Z_Construct_UPackage__Script_GC_UE4CPP,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AMyPlayerController_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AMyPlayerController_MoveForward, "MoveForward" }, // 4209814419
		{ &Z_Construct_UFunction_AMyPlayerController_MoveRight, "MoveRight" }, // 1344065932
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyPlayerController_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "MyPlayerController.h" },
		{ "ModuleRelativePath", "MyPlayerController.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMyPlayerController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyPlayerController>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMyPlayerController_Statics::ClassParams = {
		&AMyPlayerController::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x009002A4u,
		METADATA_PARAMS(Z_Construct_UClass_AMyPlayerController_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMyPlayerController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMyPlayerController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMyPlayerController_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMyPlayerController, 3859960024);
	template<> GC_UE4CPP_API UClass* StaticClass<AMyPlayerController>()
	{
		return AMyPlayerController::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMyPlayerController(Z_Construct_UClass_AMyPlayerController, &AMyPlayerController::StaticClass, TEXT("/Script/GC_UE4CPP"), TEXT("AMyPlayerController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMyPlayerController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
