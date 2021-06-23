// Fill out your copyright notice in the Description page of Project Settings.

#include "CPPFunctionLibrary.h"

bool UCPPFunctionLibrary::SetRootComponent(class AActor* actor, class USceneComponent* newSceneComponent)
{
	return actor->SetRootComponent(newSceneComponent);
};

TArray<UClass*> UCPPFunctionLibrary::GetClasses(UClass* ParentClass)
{
	TArray<UClass*> Results;

	// get our parent blueprint class
	const FString ParentClassName = ParentClass->GetName();
	UObject* ClassPackage = ANY_PACKAGE;
	UClass* ParentBPClass = FindObject<UClass>(ClassPackage, *ParentClassName);

	// iterate over UClass, this might be heavy on performance, so keep in mind..
	// better suggestions for a check are welcome
	for (TObjectIterator<UClass> It; It; ++It)
	{
		if (It->IsChildOf(ParentBPClass))
		{
			// It is a child of the Parent Class
			// make sure we don't include our parent class in the array (weak name check, suggestions welcome)
			if (It->GetName() != ParentClassName)
			{
				Results.Add(*It);
			}
		}
	}

	return Results;
}

TArray < UStaticMeshSocket*> UCPPFunctionLibrary::GetSockets(class UStaticMesh* staticMesh)
{
	return staticMesh->Sockets;
}
