// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ImGuiCommon.h"
#include "imgui_internal.h"
#include "ImGuiActor.generated.h"

#define IM_MIN(A, B)            (((A) < (B)) ? (A) : (B))
#define IM_MAX(A, B)            (((A) >= (B)) ? (A) : (B))
#define IM_CLAMP(V, MN, MX)     ((V) < (MN) ? (MN) : (V) > (MX) ? (MX) : (V))

UCLASS()
class BLUESKY_API AImGuiActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AImGuiActor();
#if WITH_IMGUI
	void ImGui_Tick();
#endif

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void ImGuiBeginPlay();
	static	void HelpMarker(const char* desc);
	virtual void ShowMyDemoWindow();
	virtual void ShowMyStyleWindow();
	virtual void ShowFontSelect(const char* label);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere, Category="IMGUI | WINDOW | OPTION")
	bool bShowWindow;
};
