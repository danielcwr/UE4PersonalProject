// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/StaticMesh.h"
#include "GameFramework/Actor.h"
#include "CPPFunctionLibrary.generated.h"


/**
 * 
 */
UCLASS()
class TESTMAPCIRCLEFIX_API UCPPFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "CPPFunctionLibrary")
		static bool SetRootComponent(class AActor* actor, class USceneComponent* newSceneComponent);

public:
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Child Classes", Keywords = "Get Child Classes"), Category = Class)
		static TArray<UClass*> GetClasses(UClass* ParentClass);

public:
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Sockets", Keywords = "Get Static Mesh Sockets"), Category = Class)
		static TArray<UStaticMeshSocket*> GetSockets(class UStaticMesh* staticMesh);

};
