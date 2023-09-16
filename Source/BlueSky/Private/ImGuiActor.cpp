// Fill out your copyright notice in the Description page of Project Settings.


#include "BlueSky/Public/ImGuiActor.h"


#include "ThumbnailRendering/WorldThumbnailInfo.h"

bool imgui_show_demo_window = false;
bool imgui_show_style_window = false;
bool imgui_show_mydemo_window = false;
bool imgui_show_styleEdit_window = false;

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
	FImGuiDelegates::OnWorldEarlyDebug().AddUObject(this, &AImGuiActor::ImGui_Tick);
#endif
	
	
}

// Called every frame
void AImGuiActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

///											///
///					IMGUI					///
///											///


void AImGuiActor::HelpMarker(const char* desc)
{
	ImGui::TextDisabled(u8"(帮助)");
	if (ImGui::BeginItemTooltip())
	{
		ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
		ImGui::TextUnformatted(desc);
		ImGui::PopTextWrapPos();
		ImGui::EndTooltip();
	}
}




void AImGuiActor::ImGui_Tick()
{
#if WITH_IMGUI
	//更改字体
	//ImGuiContextManager.cpp
	//有些代码写完能跑就不要动了，不然MSVC又要报错了
	
	if (imgui_show_demo_window)		ImGui::ShowDemoWindow();
	if (imgui_show_style_window)	ImGui::ShowStyleEditor();
	if (imgui_show_mydemo_window)	ShowMyDemoWindow();
	if (imgui_show_styleEdit_window) ShowMyStyleWindow();

	ImGui::GetIO().Fonts->Fonts[3];
	
	if (ImGui::Begin(u8"梦月IMGUI", &bShowWindow, ImGuiWindowFlags_MenuBar))
	{
		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("MENU"))
			{
				ImGui::MenuItem("DEMO WINDOW", "demo", &imgui_show_demo_window);
				ImGui::MenuItem("STYLE WINDOW", "style", &imgui_show_style_window);
				ImGui::MenuItem("MYWINDOW", "mywindow", &imgui_show_mydemo_window);
				
				ImGui::EndMenu();
			}

			ImGui::EndMenuBar();
		}
		ImGui::Text(u8"中文测试");
		ImGui::Text(u8"Abc中文");
		if (ImGui::Button(u8"样式编辑器"))
		{
			imgui_show_styleEdit_window = !imgui_show_styleEdit_window; 
		}

		ImGui::End();
	}
#endif
}



void AImGuiActor::ImGuiBeginPlay()
{
#if WITH_IMGUI
	ImGuiIO IO = ImGui::GetIO();
	

	// STYLE //
	
	ImGuiStyle* pStyle = &ImGui::GetStyle();
	ImVec4* colors = pStyle->Colors;

	// COLOR //

	colors[ImGuiCol_Text]                   = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
    colors[ImGuiCol_TextDisabled]           = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
    colors[ImGuiCol_WindowBg]               = ImVec4(0.03f, 0.03f, 0.03f, 0.8f);
    colors[ImGuiCol_ChildBg]                = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_PopupBg]                = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
    colors[ImGuiCol_Border]                 = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
    colors[ImGuiCol_BorderShadow]           = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_FrameBg]                = ImVec4(0.16f, 0.29f, 0.48f, 0.54f);
    colors[ImGuiCol_FrameBgHovered]         = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
    colors[ImGuiCol_FrameBgActive]          = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
    colors[ImGuiCol_TitleBg]                = ImVec4(0.04f, 0.04f, 0.04f, 1.00f);
    colors[ImGuiCol_TitleBgActive]          = ImVec4(0.16f, 0.29f, 0.48f, 1.00f);
    colors[ImGuiCol_TitleBgCollapsed]       = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
    colors[ImGuiCol_MenuBarBg]              = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
    colors[ImGuiCol_ScrollbarBg]            = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
    colors[ImGuiCol_ScrollbarGrab]          = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabHovered]   = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabActive]    = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
    colors[ImGuiCol_CheckMark]              = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_SliderGrab]             = ImVec4(0.24f, 0.52f, 0.88f, 1.00f);
    colors[ImGuiCol_SliderGrabActive]       = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_Button]                 = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
    colors[ImGuiCol_ButtonHovered]          = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_ButtonActive]           = ImVec4(0.06f, 0.53f, 0.98f, 1.00f);
    colors[ImGuiCol_Header]                 = ImVec4(0.26f, 0.59f, 0.98f, 0.31f);
    colors[ImGuiCol_HeaderHovered]          = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
    colors[ImGuiCol_HeaderActive]           = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_Separator]              = colors[ImGuiCol_Border];
    colors[ImGuiCol_SeparatorHovered]       = ImVec4(0.10f, 0.40f, 0.75f, 0.78f);
    colors[ImGuiCol_SeparatorActive]        = ImVec4(0.10f, 0.40f, 0.75f, 1.00f);
    colors[ImGuiCol_ResizeGrip]             = ImVec4(0.26f, 0.59f, 0.98f, 0.20f);
    colors[ImGuiCol_ResizeGripHovered]      = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
    colors[ImGuiCol_ResizeGripActive]       = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
    colors[ImGuiCol_Tab]                    = ImLerp(colors[ImGuiCol_Header],       colors[ImGuiCol_TitleBgActive], 0.80f);
    colors[ImGuiCol_TabHovered]             = colors[ImGuiCol_HeaderHovered];
    colors[ImGuiCol_TabActive]              = ImLerp(colors[ImGuiCol_HeaderActive], colors[ImGuiCol_TitleBgActive], 0.60f);
    colors[ImGuiCol_TabUnfocused]           = ImLerp(colors[ImGuiCol_Tab],          colors[ImGuiCol_TitleBg], 0.80f);
    colors[ImGuiCol_TabUnfocusedActive]     = ImLerp(colors[ImGuiCol_TabActive],    colors[ImGuiCol_TitleBg], 0.40f);
    colors[ImGuiCol_PlotLines]              = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
    colors[ImGuiCol_PlotLinesHovered]       = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
    colors[ImGuiCol_PlotHistogram]          = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
    colors[ImGuiCol_PlotHistogramHovered]   = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
    colors[ImGuiCol_TableHeaderBg]          = ImVec4(0.19f, 0.19f, 0.20f, 1.00f);
    colors[ImGuiCol_TableBorderStrong]      = ImVec4(0.31f, 0.31f, 0.35f, 1.00f);   // Prefer using Alpha=1.0 here
    colors[ImGuiCol_TableBorderLight]       = ImVec4(0.23f, 0.23f, 0.25f, 1.00f);   // Prefer using Alpha=1.0 here
    colors[ImGuiCol_TableRowBg]             = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_TableRowBgAlt]          = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
    colors[ImGuiCol_TextSelectedBg]         = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
    colors[ImGuiCol_DragDropTarget]         = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
    colors[ImGuiCol_NavHighlight]           = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_NavWindowingHighlight]  = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
    colors[ImGuiCol_NavWindowingDimBg]      = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
    colors[ImGuiCol_ModalWindowDimBg]       = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
	
	// MAIN //
	pStyle->FrameRounding = 7.0f;
	pStyle->WindowPadding = ImVec2(12.0f,12.0f);
	pStyle->FramePadding = ImVec2(16.0f, 3.0f);
	pStyle->CellPadding = ImVec2(2.0f,6.0f);
	pStyle->ItemInnerSpacing = ImVec2(8.0f,4.0f);
	pStyle->TouchExtraPadding = ImVec2(0.0f,0.0f);
	pStyle->IndentSpacing = 30.0f;
	pStyle->ScrollbarSize = 14.0f;
	pStyle->GrabMinSize = 8.0f;

	// BORDERS //
	pStyle->WindowBorderSize = 1.0f;
	pStyle->ChildBorderSize = 1.0f;
	pStyle->PopupBorderSize = 1.0f;
	pStyle->FrameBorderSize = 0.0f;
	pStyle->TabBorderSize = 0.0f;

	// ROUNDING //
	pStyle->WindowRounding = 8.0f;
	pStyle->ChildRounding = 7.0f;
	pStyle->FrameRounding = 3.0f;
	pStyle->PopupRounding = 0.0f;
	pStyle->ScrollbarRounding = 7.0f;
	pStyle->GrabRounding = 7.0f;
	pStyle->TabRounding = 4.0f;

	// WIDGETS //
	pStyle->WindowTitleAlign = ImVec2(0.9f, 0.5f);
	pStyle->WindowMenuButtonPosition = ImGuiDir_Left;
	pStyle->ColorButtonPosition = ImGuiDir_Left;
	pStyle->ButtonTextAlign = ImVec2(0.5f,0.0f);
	pStyle->SelectableTextAlign = ImVec2(0.0f, 0.0f);
	pStyle->SeparatorTextBorderSize = 4.0f;
	pStyle->SeparatorTextAlign = ImVec2(0.5f,0.5f);
	pStyle->SeparatorTextPadding = ImVec2(8.0f, 8.0f);
	pStyle->LogSliderDeadzone = 5.0f;


	UE_LOG(LogTemp, Log, TEXT("IMGUI STYLE LOAD OK"));

	
#else
	UE_LOG(LogTemp, Log, TEXT("IMGUI STYLE LOAD NO"));
#endif
}
void AImGuiActor::ShowMyDemoWindow()
{
#if WITH_IMGUI
	if (ImGui::Begin("MyWindow"))
	{

		ImGui::End();
	}
#endif
}

void AImGuiActor::ShowFontSelect(const char* label)
{
	ImGuiIO& io = ImGui::GetIO();
	ImFont* font_current = ImGui::GetFont();
	if (ImGui::BeginCombo(label, font_current->GetDebugName()))
	{
		for (int n = 0; n < io.Fonts->Fonts.Size; n++)
		{
			ImFont* font = io.Fonts->Fonts[n];
			ImGui::PushID((void*)font);
			if (ImGui::Selectable(font->GetDebugName(), font == font_current))
				io.FontDefault = font;
			ImGui::PopID();
		}
		ImGui::EndCombo();
	}
}


void AImGuiActor::ShowMyStyleWindow()
{
#if WITH_IMGUI
	if (ImGui::Begin(u8"样式编辑器"))
	{
		ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.50f);
		
		ImGuiStyle& style = ImGui::GetStyle();

		// 字体选择
		AImGuiActor::ShowFontSelect("Fonts##Selector");

		// Rounding
		{ bool border = (style.WindowBorderSize > 0.0f); if (ImGui::Checkbox("WindowBorder", &border)) { style.WindowBorderSize = border ? 1.0f : 0.0f; } }
		ImGui::SameLine();
		{ bool border = (style.FrameBorderSize > 0.0f);  if (ImGui::Checkbox("FrameBorder",  &border)) { style.FrameBorderSize  = border ? 1.0f : 0.0f; } }
		ImGui::SameLine();
		{ bool border = (style.PopupBorderSize > 0.0f);  if (ImGui::Checkbox("PopupBorder",  &border)) { style.PopupBorderSize  = border ? 1.0f : 0.0f; } }

		if (ImGui::BeginTabBar("##tabs", ImGuiTabBarFlags_None))
		{
			if (ImGui::BeginTabItem("Sizes"))
			{
				ImGui::SeparatorText("Main");
				ImGui::SliderFloat2(u8"窗口边距", (float *)&style.WindowPadding, 0.0f, 20.0f, "%.0f");

				ImGui::EndTabItem();
			}
			ImGui::EndTabBar();
		}

		ImGui::PopItemWidth();
		ImGui::End();
	}
#endif
}


