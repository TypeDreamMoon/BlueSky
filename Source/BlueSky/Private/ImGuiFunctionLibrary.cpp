// Fill out your copyright notice in the Description page of Project Settings.


#include "ImGuiFunctionLibrary.h"

void UImGuiFunctionLibrary::AddFont(FString FilePath, int size, bool Activate)
{
	ImGuiIO& io = ImGui::GetIO();

	const char* FileName = TCHAR_TO_ANSI(*FilePath);
	const char* FontName;
	for (FontName = FileName + strlen(FileName); FontName > FileName && FontName[-1] != '/' && FontName[-1] != '\\'; FontName--){}

	FString FontToAdd = ANSI_TO_TCHAR(FontName);
	FontToAdd.Append(",").Append(FString::FromInt(size)).Append("px");

	for (ImFont* Font: io.Fonts->Fonts)
	{
		FString FontToComarpe = ANSI_TO_TCHAR(Font->GetDebugName());
		if (FontToAdd.Equals(FontToComarpe))
		{
			UE_LOG(LogTemp, Log, TEXT("Duplicate Font Added Skipping"))
			return;
		}
	}
	ImFont* ImFont = io.Fonts->AddFontFromFileTTF(FileName, size);

	if (!ImFont)
	{
		UE_LOG(LogTemp, Error, TEXT("Font is NULL"))
		return;
	}
	if (Activate)
	{
		io.FontDefault = ImFont;
	}
}
