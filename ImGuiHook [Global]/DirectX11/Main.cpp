#include "DirectX11.h"
#include "Main.hpp"
#include <string>

bool ShowMenu = false;
bool ImGui_Initialised = false;

int switchTabs = 0;

void __stdcall Hooks::CheckCheatEngine(DWORD* __this, DWORD* method)
{
	return;
}

void __stdcall Hooks::OnSpeedhackDetected(DWORD* __this, DWORD* method)
{
	return;
}

void __stdcall Hooks::OnInjectionDetected(DWORD* __this, DWORD* method)
{
	return;
}

void __stdcall Hooks::OnObscuredCheatingDetected(DWORD* __this, DWORD* method)
{
	return;
}

void __stdcall Hooks::OnLevelWasLoaded(DWORD* __this, int32_t level, DWORD* method)
{
	return;
}

bool __stdcall Hooks::LeaveRoom(DWORD* method)
{
	if (Variables::Hacks::AntiDisconnect)
		return false;

	return Hooks::LeaveRoom_org(method);
}

void __stdcall Hooks::Disconnect(DWORD* method)
{
	if (Variables::Hacks::AntiDisconnect && Functions::UnityEngine::Application::GetLevelIndex() > 1)
		return;

	return Hooks::Disconnect_org(method);
}

float __stdcall Hooks::get_fieldOfView(DWORD* __this, DWORD* method)
{
	if (Variables::Hacks::FOVChanger)
		return Variables::Hacks::FOV;
	else
		return Hooks::get_fieldOfView_org(__this, method);
}

DWORD* __stdcall Hooks::LoadLevelAsync(const wchar_t* levelName, DWORD* method)
{
	return Hooks::LoadLevelAsync_org(levelName, method);
}

void __stdcall Hooks::PhotonRPC(DWORD* __this, const char* methodName, int32_t target, DWORD* parameters, DWORD* method)
{
	char methodNameReadable[256];
	wcstombs(methodNameReadable, (wchar_t*)methodName + 0xA, sizeof(methodNameReadable));

	if (Variables::Hacks::RPCDisabler_type == 2)
	{
		if (GetAsyncKeyState(VK_XBUTTON1))
			return;
	}
	else if (Variables::Hacks::RPCDisabler_type == 1)
		return;

	if (Variables::Hacks::AttackDisabler)
	{
		//if (std::string("Attack").contains(methodNameReadable))
			//return;

		if (std::string("KOFOOHFOGHL").contains(methodNameReadable) && target == 1)
			return;
		
		//if (std::string("FJNHCPGAHEA").contains(methodNameReadable)) // RangedAttack Obfuscated 
			//return;
	}

	if (Variables::Hacks::AntiNewbornGrenade)
		if (std::string("PBDAEEMLABH").contains(methodNameReadable))
			return;

	return PhotonRPC_org(__this, methodName, target, parameters, method);
}

void __stdcall Hooks::SetInt(const char* key, int32_t amount, DWORD* method)
{
	char setIntReadable[256];
	wcstombs(setIntReadable, (wchar_t*)key + 0xA, sizeof(setIntReadable));

	if (Variables::Hacks::INFToast)
	{
		if (std::string("Toast").contains(setIntReadable))
			return Hooks::SetInt_org(key, (int32_t)69420, method);
	}

	if (Variables::Hacks::INFCustard)
	{
		if (std::string("Custards").contains(setIntReadable))
			return Hooks::SetInt_org(key, (int32_t)69420, method);
	}

	if (Variables::Hacks::ServerRegionSpoofer)
		if (std::string("ServerRegion").contains(setIntReadable))
			return Hooks::SetInt_org(key, (int32_t)Variables::Hacks::ServerRegion, method);

	if (Variables::Hacks::HatSpoofer)
	{
		if (std::string("HatID").contains(setIntReadable))
			return Hooks::SetInt_org(key, (int32_t)Variables::Hacks::HatID, method);
		if (std::string("HatList").contains(setIntReadable))
			return Hooks::SetInt_org(key, (int32_t)Variables::Hacks::HatList, method);
	}

	return Hooks::SetInt_org(key, amount, method);
}

int32_t __stdcall Hooks::GetInt(const char* key, int32_t defaultValue, DWORD* method)
{
	char getIntReadable[256];
	wcstombs(getIntReadable, (wchar_t*)key + 0xA, sizeof(getIntReadable));

	if (Variables::Hacks::INFToast)
	{
		if (std::string("Toast").contains(getIntReadable))
			return Hooks::GetInt_org(key, (int32_t)69420, method);
	}

	if (Variables::Hacks::INFCustard)
	{
		if (std::string("Custards").contains(getIntReadable))
			return Hooks::GetInt_org(key, (int32_t)69420, method);
	}

	if (Variables::Hacks::ServerRegionSpoofer)
		if (std::string("ServerRegion").contains(getIntReadable))
			return Hooks::GetInt_org(key, (int32_t)Variables::Hacks::ServerRegion, method);

	if (Variables::Hacks::HatSpoofer)
	{
		if (std::string("HatID").contains(getIntReadable))
			return Hooks::GetInt_org(key, (int32_t)Variables::Hacks::HatID, method);
		if (std::string("HatList").contains(getIntReadable))
			return Hooks::GetInt_org(key, (int32_t)Variables::Hacks::HatList, method);
	}

	return Hooks::GetInt_org(key, defaultValue, method);
}

void __stdcall Hooks::SetString(const char* key, const char* value, DWORD* method)
{
	char setStringReadable[256];
	wcstombs(setStringReadable, (wchar_t*)key + 0xA, sizeof(setStringReadable));

	if (std::string("ZWName0001").contains(setStringReadable)) // zeoworks username
		return Hooks::SetString_org(key, value, method);

	if (std::string("ZWPass0001").contains(setStringReadable)) // zeoworks password
		return Hooks::SetString_org(key, value, method);

	if (std::string("ZWID0001").contains(setStringReadable)) // zeoworks id
		return Hooks::SetString_org(key, value, method);

	if (std::string("PlayerType0001").contains(setStringReadable)) // zeoworks player type
		return Hooks::SetString_org(key, value, method);

	if (std::string("PlayerNames").contains(setStringReadable)) // playerlist
		return Hooks::SetString_org(key, value, method);

	return Hooks::SetString_org(key, value, method);
}

void __stdcall Hooks::GetString(const char* key, const char* defaultValue, DWORD* method)
{
	char getStringReadable[256];
	wcstombs(getStringReadable, (wchar_t*)key + 0xA, sizeof(getStringReadable));

	if (std::string("PlayerNames").contains(getStringReadable)) // playerlist
		return Hooks::GetString_org(key, defaultValue, method);

	return Hooks::GetString_org(key, defaultValue, method);
}

bool __stdcall Hooks::get_isMasterClient(DWORD* method)
{
	if (Variables::Hacks::ForceMaster)
		return true;

	return Hooks::get_isMasterClient_org(method);
}

static void HelpMarker(const char* desc)
{
	ImGui::TextDisabled(" (?)");
	if (ImGui::IsItemHovered())
	{
		ImGui::BeginTooltip();
		ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
		ImGui::TextUnformatted(desc);
		ImGui::PopTextWrapPos();
		ImGui::EndTooltip();
	}
}

namespace Process {
	DWORD ID;
	HANDLE Handle;
	HWND Hwnd;
	HMODULE Module;
	WNDPROC WndProc;
	int WindowWidth;
	int WindowHeight;
	LPCSTR Title;
	LPCSTR ClassName;
	LPCSTR Path;
}

namespace DirectX11Interface {
	ID3D11Device* Device;
	ID3D11DeviceContext* DeviceContext;
	ID3D11RenderTargetView* RenderTargetView;
}

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT APIENTRY WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	if (ShowMenu) {
		ImGui_ImplWin32_WndProcHandler(hwnd, uMsg, wParam, lParam);
		return true;
	}
	return CallWindowProc(Process::WndProc, hwnd, uMsg, wParam, lParam);
}

HRESULT APIENTRY MJPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags) {
	if (!ImGui_Initialised) {
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&DirectX11Interface::Device))) {
			ImGui::CreateContext();

			ImGuiIO& io = ImGui::GetIO(); (void)io;
			ImGui::GetIO().WantCaptureMouse || ImGui::GetIO().WantTextInput || ImGui::GetIO().WantCaptureKeyboard;
			io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

			DirectX11Interface::Device->GetImmediateContext(&DirectX11Interface::DeviceContext);

			DXGI_SWAP_CHAIN_DESC Desc;
			pSwapChain->GetDesc(&Desc);
			WindowHwnd = Desc.OutputWindow;

			ID3D11Texture2D* BackBuffer;
			pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&BackBuffer);
			DirectX11Interface::Device->CreateRenderTargetView(BackBuffer, NULL, &DirectX11Interface::RenderTargetView);
			BackBuffer->Release();

			ImGui_ImplWin32_Init(WindowHwnd);
			ImGui_ImplDX11_Init(DirectX11Interface::Device, DirectX11Interface::DeviceContext);
			ImGui_ImplDX11_CreateDeviceObjects();
			ImGui::GetIO().ImeWindowHandle = Process::Hwnd;
			Process::WndProc = (WNDPROC)SetWindowLongPtr(Process::Hwnd, GWLP_WNDPROC, (__int3264)(LONG_PTR)WndProc);

			auto& style = ImGui::GetStyle();
			io.IniFilename = "inferno_imgui.ini";

			//Variables::Fonts::font_1 = ImGui::GetIO().Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\verdana.ttf", 15.0f, NULL, ImGui::GetIO().Fonts->GetGlyphRangesCyrillic());
			//Variables::Fonts::font_2 = ImGui::GetIO().Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\verdana.ttf", 62.0f, NULL, ImGui::GetIO().Fonts->GetGlyphRangesCyrillic());

			static int hue = 140;

			ImVec4 col_text = ImColor::HSV(hue / 255.f, 20.f / 255.f, 235.f / 255.f);
			ImVec4 col_main = ImColor(9, 82, 128);
			ImVec4 col_back = ImColor(31, 44, 54);
			ImVec4 col_area = ImColor(4, 32, 41);

			style.Colors[ImGuiCol_Text] = ImVec4(0.98f, 0.98f, 0.98f, 1.00f);
			style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.30f, 0.30f, 0.30f, 1.00f);
			style.Colors[ImGuiCol_WindowBg] = ImVec4(0.1f, 0.1f, 0.1f, 0.95f);
			style.Colors[ImGuiCol_Border] = ImVec4(0.27f, 0.27f, .27f, 1.00f);
			style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
			style.Colors[ImGuiCol_FrameBg] = ImVec4(0.09f, .09f, .09f, 1.f);
			style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.13, 0.13, 0.13, 1.f);
			style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.11, 0.11, 0.11, 1.f);
			style.Colors[ImGuiCol_TitleBg] = ImVec4(.78f, 0.f, 0.f, .7f);
			style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(.78f, 0.f, 0.f, .7f);
			style.Colors[ImGuiCol_TitleBgActive] = ImVec4(.78f, 0.f, 0.f, .7f);
			style.Colors[ImGuiCol_MenuBarBg] = ImVec4(.78f, 0.f, 0.f, .7f);
			style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.1f, 0.1f, 0.1f, 0.95f);
			style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(.78f, 0.f, 0.f, 1.f);
			style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(.78f, 0.f, 0.f, 1.f);
			style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(.78f, 0.f, 0.f, 1.f);
			style.Colors[ImGuiCol_CheckMark] = ImVec4(.78f, 0.f, 0.f, 1.f);
			style.Colors[ImGuiCol_SliderGrab] = ImVec4(.78f, 0.f, 0.f, 1.f);
			style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(.78f, 0.f, 0.f, 1.f);
			style.Colors[ImGuiCol_Button] = ImVec4(0.12, 0.12, 0.12, 1.f);
			style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.21f, 0.21f, 0.21f, 1.00f);
			style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.12, 0.12, 0.12, 1.f);
			style.Colors[ImGuiCol_Header] = ImVec4(.78f, 0.f, 0.f, .7f);
			style.Colors[ImGuiCol_HeaderHovered] = ImVec4(.78f, 0.f, 0.f, .8f);
			style.Colors[ImGuiCol_HeaderActive] = ImVec4(.78f, 0.f, 0.f, .87f);
			style.Colors[ImGuiCol_ResizeGrip] = ImVec4(col_main.x, col_main.y, col_main.z, 0.20f);
			style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(col_main.x, col_main.y, col_main.z, 0.78f);
			style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(col_main.x, col_main.y, col_main.z, 1.00f);
			style.Colors[ImGuiCol_PlotLines] = ImVec4(col_text.x, col_text.y, col_text.z, 0.63f);
			style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(col_main.x, col_main.y, col_main.z, 1.00f);
			style.Colors[ImGuiCol_PlotHistogram] = ImVec4(col_text.x, col_text.y, col_text.z, 0.63f);
			style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(col_main.x, col_main.y, col_main.z, 1.00f);
			style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(col_main.x, col_main.y, col_main.z, 0.43f);
			style.Colors[ImGuiCol_PopupBg] = ImVec4(0.78f, 0.00f, 0.00f, 0.70f);

			//style.Alpha = 0.0f;
			style.WindowPadding = ImVec2(8, 8);
			style.WindowMinSize = ImVec2(32, 32);
			style.WindowRounding = 0.5f;
			style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
			style.FramePadding = ImVec2(4, 2);
			style.FrameRounding = 0.0f;
			style.ItemSpacing = ImVec2(8, 4);
			style.ItemInnerSpacing = ImVec2(4, 4);
			style.TouchExtraPadding = ImVec2(0, 0);
			style.IndentSpacing = 21.0f;
			style.ColumnsMinSpacing = 3.0f;
			style.ScrollbarSize = 12.0f;
			style.ScrollbarRounding = 0.0f;
			style.GrabMinSize = 0.1f;
			style.GrabRounding = 0.0f;
			style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
			style.DisplayWindowPadding = ImVec2(22, 22);
			style.DisplaySafeAreaPadding = ImVec2(4, 4);
			style.AntiAliasedLines = true;
			style.CurveTessellationTol = 1.25f;

			//Variables::Hacks::QualityLevel = Functions::UnityEngine::QualitySettings::GetQualityLevel(); - PERFORMANCE/UNUSED
			ImGui_Initialised = true;
		}
	}
	if (GetAsyncKeyState(VK_INSERT) & 1 && Functions::UnityEngine::Application::GetLevelIndex() > 0) ShowMenu = !ShowMenu;
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	ImGui::GetIO().MouseDrawCursor = ShowMenu;

	if (Variables::Hacks::DebugMenu)
	{
		//ImGui::SetNextWindowSize({ 200, 100 });
		ImGui::Begin("Status Menu", NULL, (ImGuiWindowFlags_NoCollapse, ImGuiWindowFlags_NoTitleBar));
		ImGui::Text("FPS %.0f", ImGui::GetIO().Framerate);
		ImGui::Text("GetMaxFPS = %i", Functions::UnityEngine::Application::GetMaxFPS());
		ImGui::Text("GetLevelIndex = %i", Functions::UnityEngine::Application::GetLevelIndex());
		ImGui::Separator();
		ImGui::Text("Time Info:");
		ImGui::Text("GetTime = %.1f", Functions::UnityEngine::Time::GetTime());
		ImGui::Text("GetTimescale = %.1f", Functions::UnityEngine::Time::GetTimescale());
		ImGui::Text("GetDeltaTime = %.1f", Functions::UnityEngine::Time::GetDeltaTime());
		ImGui::Text("GetFrameCount = %i", Functions::UnityEngine::Time::GetFrameCount());
		ImGui::Text("GetTimeSinceLevelLoad = %.1f", Functions::UnityEngine::Time::GetTimeSinceLevelLoad());
		//ImGui::Text("Test = %.0f", *(float*)(ST3::Modules::GameAssembly + ST3::Offsets::FPSController::FPScontroller_FPScontrollerMovement_c + ST3::Offsets::FPSController::FPScontrollerMovement::gravity));
		if (Functions::PhotonNetwork::get_inRoom())
		{
			ImGui::Separator();
			ImGui::Text("Room Info:");
			ImGui::Text("GetVisible = %d", Functions::Room::GetVisible(Functions::PhotonNetwork::get_room()));
			ImGui::Text("GetOpen = %d", Functions::Room::GetOpen(Functions::PhotonNetwork::get_room()));
			ImGui::Text("GetMaxPlayers = %i", Functions::Room::GetMaxPlayers(Functions::PhotonNetwork::get_room()));
		}
		ImGui::End();
	}

	if (ShowMenu == true && Functions::UnityEngine::Application::GetLevelIndex() > 0)
	{
		ImGui::SetNextWindowSize({ 800, 550 });
		//ImGui::PushFont(Variables::Fonts::font_2);
		ImGui::Begin("Inferno.cc", NULL, ImGuiWindowFlags_NoCollapse);

		ImGui::SameLine();
		if (ImGui::Button("Visuals", ImVec2(150, 25)))
			switchTabs = 0;

		ImGui::SameLine();
		if (ImGui::Button("Misc", ImVec2(150, 25)))
			switchTabs = 1;

		if (Functions::PhotonNetwork::get_inRoom())
		{
			ImGui::SameLine();
			if (ImGui::Button("Room Settings", ImVec2(150, 25)))
				switchTabs = 2;
			//ImGui::SameLine();
			//if (ImGui::Button("Playerlist", ImVec2(150, 25)))
			//	switchTabs = 3;
		}

		//ImGui::PopFont();
		//ImGui::PushFont(Variables::Fonts::font_1);

		switch (switchTabs) {
		case 0:
			if (ImGui::CollapsingHeader("World"))
			{
				ImGui::Checkbox("FOV Changer", &Variables::Hacks::FOVChanger);
				if (Variables::Hacks::FOVChanger)
					ImGui::SliderInt("Custom FOV", &Variables::Hacks::FOV, -180.f, 180.f);
				ImGui::Checkbox("Disable Fog", &Variables::Hacks::FogDisabler);
				ImGui::SliderInt("Ambient Mode", &Variables::Hacks::AmbientMode, 0.f, 1.f);
				//ImGui::SliderInt("Quality Level", &Variables::Hacks::QualityLevel, 0.f, 6.f);
				//ImGui::SameLine();
				//if (ImGui::Button("Set Quality Level"))
				//	Functions::UnityEngine::QualitySettings::SetQualityLevel(Variables::Hacks::QualityLevel);
			}
			if (ImGui::CollapsingHeader("Other"))
			{
				ImGui::Checkbox("Crosshair ", &Variables::Hacks::Crosshair);
				ImGui::SameLine();
				ImGui::ColorEdit4("Crosshair Color##1", (float*)&Variables::Hacks::Crosshair_color);
				ImGui::Combo("Crosshair Type", &Variables::Hacks::Crosshair_type, Variables::Hacks::Crosshair_types, IM_ARRAYSIZE(Variables::Hacks::Crosshair_types));
				if (Variables::Hacks::Crosshair_type == 0)
					ImGui::SliderInt("Circle Segments", &Variables::Hacks::Crosshair_segments, 1.f, 10.f);
				else
					ImGui::SliderInt("Square Rounding", &Variables::Hacks::Crosshair_rounding, 0.f, 12.f);
				ImGui::Checkbox("Keybind Text", &Variables::Hacks::KeybindText);
			}
			break;
		case 1:
			if (ImGui::CollapsingHeader("General"))
			{
				ImGui::Checkbox("Infinite Toast", &Variables::Hacks::INFToast);
				ImGui::Checkbox("Infinite Custard", &Variables::Hacks::INFCustard);
				ImGui::SameLine();
				HelpMarker("Quite buggy but it in theory should work.");
				ImGui::Checkbox("Anti-Disconnect", &Variables::Hacks::AntiDisconnect);
				ImGui::SameLine();
				HelpMarker("Disables server disconnecting/leaving. (ghetto antikick)");
				ImGui::Checkbox("Clientside-Master", &Variables::Hacks::ForceMaster);
				ImGui::Checkbox("Hat Spoofer (buggy)", &Variables::Hacks::HatSpoofer);
				if (Variables::Hacks::HatSpoofer)
				{
					ImGui::SliderInt("HatID", &Variables::Hacks::HatID, 0, 100);
					ImGui::SliderInt("HatList", &Variables::Hacks::HatList, 0, 100);
				}
				ImGui::Separator();
				ImGui::Checkbox("Server Region Spoofer", &Variables::Hacks::ServerRegionSpoofer);
				ImGui::SameLine();
				HelpMarker("Spoofs the server region.");
				if (Variables::Hacks::ServerRegionSpoofer) // it might of been the server bug that made me think it was patched /shrug
					ImGui::SliderInt("Region", &Variables::Hacks::ServerRegion, 0, 10);
				ImGui::Separator();
				//ImGui::SliderFloat("Timescale Amount", &Variables::Hacks::TimescaleAmount, 0.f, 20.f);
				ImGui::Combo("Speedhack", &Variables::Hacks::Timescale_type, Variables::Hacks::Timescale_types, IM_ARRAYSIZE(Variables::Hacks::Timescale_types));
				ImGui::SliderInt("Speedhack Amount", &Variables::Hacks::TimescaleAmount, 1.f, 20.f);
				ImGui::Separator();
				ImGui::SliderInt("Level ID", &Variables::Hacks::LevelID, 0, 42);
				ImGui::SameLine();
				HelpMarker("11 = Blue Room");
				if (ImGui::Button("Load Level"))
				{
					if (!Variables::Hacks::LoadLevelServerside)
						Functions::UnityEngine::Application::LoadLevel(Variables::Hacks::LevelID);
					else
						Functions::PhotonPlayer::LoadLevel(Variables::Hacks::LevelID);
				}
				if (ImGui::Button("Reload Level"))
				{
					if (!Variables::Hacks::LoadLevelServerside)
						Functions::UnityEngine::Application::LoadLevel(Functions::UnityEngine::Application::GetLevelIndex());
					else
						Functions::PhotonPlayer::LoadLevel(Functions::UnityEngine::Application::GetLevelIndex());
				}
				ImGui::SameLine();
				HelpMarker("This fucks up survival, useful for trolling.");
				ImGui::Checkbox("Load Via Photon", &Variables::Hacks::LoadLevelServerside);
				ImGui::SameLine();
				HelpMarker("Loads the level via Photon. (useless for now ig)");
				ImGui::Separator();
				if (ImGui::Button("Join Random Room"))
					Functions::PhotonNetwork::JoinRandomRoom();
				ImGui::SameLine();
				HelpMarker("Warning: use only on the serverlist or it crashes.");
				ImGui::Checkbox("Auto-Room-Crasher", &Variables::Hacks::AutoCrash);
				ImGui::SameLine();
				HelpMarker("Automatically crashes a room. (can crash)");
			}
			if (ImGui::CollapsingHeader("Other"))
			{
				ImGui::Combo("RPC Disabler", &Variables::Hacks::RPCDisabler_type, Variables::Hacks::RPCDisabler_types, IM_ARRAYSIZE(Variables::Hacks::RPCDisabler_types));
				ImGui::Checkbox("Debug Menu", &Variables::Hacks::DebugMenu);
				ImGui::Checkbox("Watermark", &Variables::Hacks::Watermark);
				ImGui::SameLine();
				ImGui::ColorEdit4("Watermark Color##1", (float*)&Variables::Hacks::Watermark_color);
				ImGui::Checkbox("Experimental Menu Cursor Support (buggy)", &Variables::Hacks::ExperimentalMenuCursorSupport);
			}
			if (ImGui::CollapsingHeader("Credits"))
			{
				ImGui::Text("Created by: Astroux#4200");
				ImGui::Text("This cheat is extremely unstable, it will probably crash a couple times.");
			}
			break;
		case 2:
			//ImGui::SliderFloat("Max Players", &Variables::Hacks::MaxPlayers, 0.f, 30.f);
			ImGui::SliderInt("Max Players", &Variables::Hacks::MaxPlayers, 0.f, 12.f);
			if (ImGui::Button("Set Max Players"))
				Functions::Room::SetMaxPlayers(Functions::PhotonNetwork::get_room(), Variables::Hacks::MaxPlayers);
			if (ImGui::Button("Show Room"))
				Functions::Room::SetVisible(Functions::PhotonNetwork::get_room(), true);
			if (ImGui::Button("Hide Room"))
				Functions::Room::SetVisible(Functions::PhotonNetwork::get_room(), false);
			if (ImGui::Button("Open Room"))
				Functions::Room::SetOpen(Functions::PhotonNetwork::get_room(), true);
			if (ImGui::Button("Close Room"))
				Functions::Room::SetOpen(Functions::PhotonNetwork::get_room(), false);
			if (ImGui::Button("Crash Server (SetMasterClient)"))
			{
				Variables::Hacks::AntiDisconnect = false;
				Functions::PhotonNetwork::SetMasterClient(Functions::PhotonNetwork::get_player());
			}
			if (ImGui::Button("Crash Server #2 (CloseConnection)"))
			{
				Variables::Hacks::AntiDisconnect = false;
				Functions::PhotonNetwork::CloseConnection(Functions::PhotonNetwork::get_player());
			}
			break;
		case 3:
			break;
		}
		//ImGui::PopFont();
		ImGui::End();
	}

	auto draw_list = ImGui::GetBackgroundDrawList();
	auto yOffset = 0;

	if (Variables::Hacks::Watermark && Functions::UnityEngine::Application::GetLevelIndex() > 0)
	{
		draw_list->AddRectFilled(ImVec2(6, 4), ImVec2((4 * 2) + ImGui::CalcTextSize("Inferno.cc").x + 6, 6), ImGui::GetColorU32(Variables::Hacks::Watermark_color));
		draw_list->AddRectFilled(ImVec2(6, 6), ImVec2((4 * 2) + ImGui::CalcTextSize("Inferno.cc").x + 6, 25), ImColor(0.2117647081613541f, 0.2235294133424759f, 0.2470588237047195f, 0.3f));
		draw_list->AddText(ImVec2(10, 8), ImColor(255, 255, 255, 255), "Inferno.cc");
	}

	if (Variables::Hacks::Crosshair)
	{
		switch (Variables::Hacks::Crosshair_type) {
		case 0:
			draw_list->AddCircle(ImVec2(Process::WindowWidth / 2, Process::WindowHeight / 2), 6, ImGui::GetColorU32(Variables::Hacks::Crosshair_color), Variables::Hacks::Crosshair_segments, 0.0f);
			break;
		case 1:
			draw_list->AddRectFilled(ImVec2(Process::WindowWidth / 2 - 5, Process::WindowHeight / 2 - 5), ImVec2(Process::WindowWidth / 2 + 5, Process::WindowHeight / 2 + 5), ImGui::GetColorU32(Variables::Hacks::Crosshair_color), Variables::Hacks::Crosshair_rounding);
			break;
		}
	}

	if (Variables::Hacks::KeybindText)
	{
		if (Variables::Hacks::RPCDisabler_type == 2)
		{
			if (GetAsyncKeyState(VK_XBUTTON1))
				draw_list->AddText(ImVec2(Process::WindowWidth / 2 + 30, Process::WindowHeight / 2 - 5), ImColor(0, 255, 0, 255), "DISABLE RPC (Keybind)");
			else
				draw_list->AddText(ImVec2(Process::WindowWidth / 2 + 30, Process::WindowHeight / 2 - 5), ImColor(255, 0, 0, 255), "DISABLE RPC (Keybind)");
		}
		else if (Variables::Hacks::RPCDisabler_type == 1)
		{
			draw_list->AddText(ImVec2(Process::WindowWidth / 2 + 30, Process::WindowHeight / 2 - 5), ImColor(0, 255, 0, 255), "DISABLE RPC (Always On)");
		}
		if (Variables::Hacks::Timescale_type == 3)
		{
			if (GetAsyncKeyState(VK_LSHIFT))
				draw_list->AddText(ImVec2(Process::WindowWidth / 2 + 30, Process::WindowHeight / 2 + 10), ImColor(0, 255, 0, 255), "SPEEDHACK (Keybind)");
			else
				draw_list->AddText(ImVec2(Process::WindowWidth / 2 + 30, Process::WindowHeight / 2 + 10), ImColor(255, 0, 0, 255), "SPEEDHACK (Keybind)");
		}
		if (Variables::Hacks::Timescale_type == 2)
		{
			if (GetAsyncKeyState(VK_XBUTTON2))
				draw_list->AddText(ImVec2(Process::WindowWidth / 2 + 30, Process::WindowHeight / 2 + 10), ImColor(0, 255, 0, 255), "SPEEDHACK (Keybind)");
			else
				draw_list->AddText(ImVec2(Process::WindowWidth / 2 + 30, Process::WindowHeight / 2 + 10), ImColor(255, 0, 0, 255), "SPEEDHACK (Keybind)");
		}
		else if (Variables::Hacks::Timescale_type == 1)
		{
			draw_list->AddText(ImVec2(Process::WindowWidth / 2 + 30, Process::WindowHeight / 2 + 10), ImColor(0, 255, 0, 255), "SPEEDHACK (Always On)");
		}
	}

	if (Functions::UnityEngine::Application::GetLevelIndex() == 0)
	{
		draw_list->AddText(ImVec2(10, 8), ImColor(199, 0, 0, 255), "Inferno.cc Loaded - Click 'Play'");
		draw_list->AddText(ImVec2(10, 20), ImColor(199, 0, 0, 255), "Note: The key to open the menu is 'Insert'");
	}

	if (Functions::UnityEngine::Application::GetLevelIndex() > 0)
		if (!Functions::PhotonNetwork::get_inRoom() && switchTabs >= 2) // make the tab revert if you disconnect from the room
			switchTabs = 1;

	if (Variables::Hacks::AutoCrash && Functions::PhotonNetwork::get_inRoom() && Functions::UnityEngine::Time::GetTimeSinceLevelLoad() > 5.f) // we need the time since load check to prevent game crashes (in theory)
	{
		draw_list->AddText(ImVec2(Process::WindowWidth / 2 - 55, Process::WindowHeight / 2 - 50), ImColor(255, 255, 255, 255), "CRASHING SERVER...");
		Variables::Hacks::AntiDisconnect = false;
		Functions::PhotonNetwork::SetMasterClient(Functions::PhotonNetwork::get_player());
	}

	if (Variables::Hacks::Timescale_type == 3)
	{
		if (GetAsyncKeyState(VK_LSHIFT))
			Functions::UnityEngine::Time::SetTimescale(Variables::Hacks::TimescaleAmount);
		else
			Functions::UnityEngine::Time::SetTimescale(1.000f);
	}
	else if (Variables::Hacks::Timescale_type == 2)
	{
		if (GetAsyncKeyState(VK_XBUTTON2))
			Functions::UnityEngine::Time::SetTimescale(Variables::Hacks::TimescaleAmount);
		else
			Functions::UnityEngine::Time::SetTimescale(1.000f);
	}
	else if (Variables::Hacks::Timescale_type == 1)
	{
		Functions::UnityEngine::Time::SetTimescale(Variables::Hacks::TimescaleAmount);
	}
	else
	{
		Functions::UnityEngine::Time::SetTimescale(1.000f);
	}

	//*(float*)(ST3::Modules::GameAssembly + ST3::Offsets::FPSController::FPScontroller_FPScontrollerMovement_c + ST3::Offsets::FPSController::FPScontrollerMovement::gravity) = 0.f;

	if (Variables::Hacks::ExperimentalMenuCursorSupport)
		Functions::UnityEngine::Screen::SetLockCursor(ShowMenu);

	Functions::UnityEngine::RenderSettings::SetFog(!Variables::Hacks::FogDisabler);
	Functions::UnityEngine::RenderSettings::SetAmbientMode(Variables::Hacks::AmbientMode);
	//Functions::UnityEngine::Application::SetMaxFPS(10000);

	ImGui::EndFrame();
	ImGui::Render();

	DirectX11Interface::DeviceContext->OMSetRenderTargets(1, &DirectX11Interface::RenderTargetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	return oIDXGISwapChainPresent(pSwapChain, SyncInterval, Flags);
}

void APIENTRY MJDrawIndexed(ID3D11DeviceContext* pContext, UINT IndexCount, UINT StartIndexLocation, INT BaseVertexLocation) {}
DWORD WINAPI MainThread(LPVOID lpParameter)
{
	ST3::Modules::ModuleBase = (uintptr_t)GetModuleHandle(NULL);
	ST3::Modules::GameAssembly = (uintptr_t)GetModuleHandle("GameAssembly.dll");
	ST3::Modules::GameAssemblyHandle = GetModuleHandle("GameAssembly.dll");
	ST3::Modules::UnityPlayer = (uintptr_t)GetModuleHandle("UnityPlayer.dll");

	bool WindowFocus = false;
	while (WindowFocus == false) {
		DWORD ForegroundWindowProcessID;
		GetWindowThreadProcessId(GetForegroundWindow(), &ForegroundWindowProcessID);
		if (GetCurrentProcessId() == ForegroundWindowProcessID) {

			Process::ID = GetCurrentProcessId();
			Process::Handle = GetCurrentProcess();
			Process::Hwnd = GetForegroundWindow();

			RECT TempRect;
			GetWindowRect(Process::Hwnd, &TempRect);
			Process::WindowWidth = TempRect.right - TempRect.left;
			Process::WindowHeight = TempRect.bottom - TempRect.top;

			char TempTitle[MAX_PATH];
			GetWindowText(Process::Hwnd, TempTitle, sizeof(TempTitle));
			Process::Title = TempTitle;

			char TempClassName[MAX_PATH];
			GetClassName(Process::Hwnd, TempClassName, sizeof(TempClassName));
			Process::ClassName = TempClassName;

			char TempPath[MAX_PATH];
			GetModuleFileNameEx(Process::Handle, NULL, TempPath, sizeof(TempPath));
			Process::Path = TempPath;

			WindowFocus = true;
		}
	}
	bool InitHook = false;
	while (InitHook == false) {
		if (DirectX11::Init() == true) {
			CreateHook(8, (void**)&oIDXGISwapChainPresent, MJPresent);
			CreateHook(12, (void**)&oID3D11DrawIndexed, MJDrawIndexed);
			InitHook = true;
		}
	}

	MH_CreateHook(reinterpret_cast<LPVOID*>(ST3::Modules::GameAssembly + ST3::Offsets::AntiCheat::CheckCheatEngine), &Hooks::CheckCheatEngine, (LPVOID*)&Hooks::CheckCheatEngine_org);
	MH_CreateHook(reinterpret_cast<LPVOID*>(ST3::Modules::GameAssembly + ST3::Offsets::AntiCheat::OnSpeedhackDetected), &Hooks::OnSpeedhackDetected, (LPVOID*)&Hooks::OnSpeedhackDetected_org);
	MH_CreateHook(reinterpret_cast<LPVOID*>(ST3::Modules::GameAssembly + ST3::Offsets::AntiCheat::OnInjectionDetected), &Hooks::OnInjectionDetected, (LPVOID*)&Hooks::OnInjectionDetected_org);
	MH_CreateHook(reinterpret_cast<LPVOID*>(ST3::Modules::GameAssembly + ST3::Offsets::AntiCheat::OnObscuredCheatingDetected), &Hooks::OnObscuredCheatingDetected, (LPVOID*)&Hooks::OnObscuredCheatingDetected_org);
	MH_CreateHook(reinterpret_cast<LPVOID*>(ST3::Modules::GameAssembly + ST3::Offsets::AntiCheat::OnLevelWasLoaded), &Hooks::OnLevelWasLoaded, (LPVOID*)&Hooks::OnLevelWasLoaded_org);
	MH_CreateHook(reinterpret_cast<LPVOID*>(ST3::Modules::GameAssembly + ST3::Offsets::PhotonNetwork::Disconnect), &Hooks::Disconnect, (LPVOID*)&Hooks::Disconnect_org);
	MH_CreateHook(reinterpret_cast<LPVOID*>(ST3::Modules::GameAssembly + ST3::Offsets::PhotonNetwork::LeaveRoom), &Hooks::LeaveRoom, (LPVOID*)&Hooks::LeaveRoom_org);
	MH_CreateHook(reinterpret_cast<LPVOID*>(ST3::Modules::GameAssembly + ST3::Offsets::PhotonNetwork::get_isMasterClient), &Hooks::get_isMasterClient, (LPVOID*)&Hooks::get_isMasterClient_org);
	MH_CreateHook(reinterpret_cast<LPVOID*>(ST3::Modules::GameAssembly + ST3::Offsets::PhotonView::RPC), &Hooks::PhotonRPC, (LPVOID*)&Hooks::PhotonRPC_org);
	MH_CreateHook(reinterpret_cast<LPVOID*>(ST3::Modules::GameAssembly + ST3::Offsets::CodeStage::SetInt), &Hooks::SetInt, (LPVOID*)&Hooks::SetInt_org);
	MH_CreateHook(reinterpret_cast<LPVOID*>(ST3::Modules::GameAssembly + ST3::Offsets::CodeStage::GetInt), &Hooks::GetInt, (LPVOID*)&Hooks::GetInt_org);
	MH_CreateHook(reinterpret_cast<LPVOID*>(ST3::Modules::GameAssembly + ST3::Offsets::CodeStage::SetString), &Hooks::SetString, (LPVOID*)&Hooks::SetString_org);
	MH_CreateHook(reinterpret_cast<LPVOID*>(ST3::Modules::GameAssembly + ST3::Offsets::CodeStage::GetString), &Hooks::GetString, (LPVOID*)&Hooks::GetString_org);
	MH_CreateHook(reinterpret_cast<LPVOID*>(ST3::Modules::GameAssembly + ST3::Offsets::UnityEngine::Camera::get_fieldOfView), &Hooks::get_fieldOfView, (LPVOID*)&Hooks::get_fieldOfView_org);
	MH_CreateHook(reinterpret_cast<LPVOID*>(ST3::Modules::GameAssembly + ST3::Offsets::UnityEngine::Application::LoadLevelAsync), &Hooks::LoadLevelAsync, (LPVOID*)&Hooks::LoadLevelAsync_org);

	MH_EnableHook(MH_ALL_HOOKS);

	return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved) {
	switch (dwReason) {
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hModule);
		if (ChecktDirectXVersion(DirectXVersion.D3D11) == true) {
			Process::Module = hModule;
			CreateThread(0, 0, MainThread, 0, 0, 0);
		}
		break;
	case DLL_PROCESS_DETACH:
		FreeLibraryAndExitThread(hModule, TRUE);
		DisableAll();
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	default:
		break;
	}
	return TRUE;
}