// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ImGuiCommon.h"
#include "ImGuiFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class BLUESKY_API UImGuiFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category="IMGUI")
	void AddFont(FString FilePath, int size, bool Activate);
};
