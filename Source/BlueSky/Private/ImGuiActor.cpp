// Fill out your copyright notice in the Description page of Project Settings.


#include "BlueSky/Public/ImGuiActor.h"

bool imgui_show_demo_window = false;
bool imgui_show_style_window = false;

// Sets default values
AImGuiActor::AImGuiActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}



// Called when the game starts or when spawned
void AImGuiActor::BeginPlay()
{
	Super::BeginPlay();
#if WITH_IMGUI
	//OnWorldDebug
	//委托给ImGui调试事件。在世界更新期间，世界代表每帧被调用一次，在他们的世界失效后，调用列表被清除。每个更新的世界都会调用多上下文委托一次。早期调试委托在世界tick开始时被调用，调试委托在世界post actor tick或4.18以下的引擎版本中在世界tick开始时被调用。事件的顺序以一种多上下文委托可以用来绘制页眉或页脚的方式定义:多上下文早期调试，世界早期调试，世界调试，多上下文调试。
	FImGuiDelegates::OnWorldDebug().AddUObject(this, &AImGuiActor::ImGui_Tick);
#endif
	
	
}

// Called every frame
void AImGuiActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

#if WITH_IMGUI

void AImGuiActor::ImGui_Tick()
{

	//更改字体
	//ImGuiContextManager.cpp
	//有些代码写完能跑就不要动了，不然MSVC又要报错了
	
	if (imgui_show_demo_window)		ImGui::ShowDemoWindow();
	if (imgui_show_style_window)	ImGui::ShowStyleEditor();
	
	if (ImGui::Begin("Window", &bShowWindow, ImGuiWindowFlags_MenuBar))
	{
		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("MENU"))
			{
				ImGui::MenuItem("DEMO WINDOW", "demo", &imgui_show_demo_window);
				ImGui::MenuItem("STYLE WINDOW", "style", &imgui_show_style_window);
				
				ImGui::EndMenu();
			}

			ImGui::EndMenuBar();
		}
		ImGui::Text(u8"中文测试");

		ImGui::End();
	}
}

#endif

