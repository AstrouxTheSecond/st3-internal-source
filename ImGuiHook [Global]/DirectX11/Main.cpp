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

	if (Variables::Hacks::RPCDisabler)
		return;

	if (Variables::Hacks::AttackDisabler)
	{
		//if (std::string("Attack").contains(methodNameReadable))
			//return;

		if (std::string("DLAAABADJJP").contains(methodNameReadable) && target == 1)
			return;

		//if (std::string("JLOHDDECPCL").contains(methodNameReadable)) // RangedAttack Obfuscated 
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

	return Hooks::SetString_org(key, value, method);
}

bool __stdcall Hooks::get_isMasterClient(DWORD* method)
{
	if (Variables::Hacks::ForceMaster)
		return true;

	return Hooks::get_isMasterClient_org(method);
}

void __stdcall Hooks::KickPlayerMaster(DWORD* __this, DWORD* player, DWORD* method)
{
	return;
	//return Hooks::LeaveRoom2_org(__this, player, method);
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

			ImGuiStyle* style = &ImGui::GetStyle();

			style->WindowPadding = ImVec2(15, 15);
			style->WindowRounding = 5.0f;
			style->FramePadding = ImVec2(5, 5);
			style->FrameRounding = 4.0f;
			style->ItemSpacing = ImVec2(12, 8);
			style->ItemInnerSpacing = ImVec2(8, 6);
			style->IndentSpacing = 25.0f;
			style->ScrollbarSize = 15.0f;
			style->ScrollbarRounding = 9.0f;
			style->GrabMinSize = 5.0f;
			style->GrabRounding = 3.0f;

			style->Colors[ImGuiCol_Text] = ImVec4(0.80f, 0.80f, 0.83f, 1.00f);
			style->Colors[ImGuiCol_TextDisabled] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
			style->Colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
			style->Colors[ImGuiCol_PopupBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
			style->Colors[ImGuiCol_Border] = Variables::Hacks::Border_color;
			style->Colors[ImGuiCol_BorderShadow] = ImVec4(0.92f, 0.91f, 0.88f, 0.00f);
			style->Colors[ImGuiCol_FrameBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
			style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
			style->Colors[ImGuiCol_FrameBgActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
			style->Colors[ImGuiCol_TitleBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
			style->Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.00f, 0.98f, 0.95f, 0.75f);
			style->Colors[ImGuiCol_TitleBgActive] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
			style->Colors[ImGuiCol_MenuBarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
			style->Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
			style->Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
			style->Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
			style->Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
			style->Colors[ImGuiCol_CheckMark] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
			style->Colors[ImGuiCol_SliderGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
			style->Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
			style->Colors[ImGuiCol_Button] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
			style->Colors[ImGuiCol_ButtonHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
			style->Colors[ImGuiCol_ButtonActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
			style->Colors[ImGuiCol_Header] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
			style->Colors[ImGuiCol_HeaderHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
			style->Colors[ImGuiCol_HeaderActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
			style->Colors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
			style->Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
			style->Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
			style->Colors[ImGuiCol_PlotLines] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
			style->Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
			style->Colors[ImGuiCol_PlotHistogram] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
			style->Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
			style->Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.25f, 1.00f, 0.00f, 0.43f);

			ImGui_Initialised = true;
		}
	}
	if (GetAsyncKeyState(VK_INSERT) & 1) ShowMenu = !ShowMenu;
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	ImGui::GetIO().MouseDrawCursor = ShowMenu;

	if (Variables::Hacks::DebugMenu)
	{
		//ImGui::SetNextWindowSize({ 200, 100 });
		ImGui::Begin("Status Menu", NULL, (ImGuiWindowFlags_NoCollapse, ImGuiWindowFlags_NoTitleBar));
		ImGui::Text("Application Info:");
		ImGui::Text("FPS %0f", ImGui::GetIO().Framerate);
		ImGui::Text("GetMaxFPS = %i", Functions::UnityEngine::Application::GetMaxFPS());
		ImGui::Text("GetLevelIndex = %i", Functions::UnityEngine::Application::GetLevelIndex());
		ImGui::Separator();
		ImGui::Text("Time Info:");
		ImGui::Text("GetTime = %.1f", Functions::UnityEngine::Time::GetTime());
		ImGui::Text("GetTimescale = %.1f", Functions::UnityEngine::Time::GetTimescale());
		ImGui::Text("GetDeltaTime = %.1f", Functions::UnityEngine::Time::GetDeltaTime());
		ImGui::Text("GetFrameCount = %i", Functions::UnityEngine::Time::GetFrameCount());
		ImGui::Text("GetTimeSinceLevelLoad = %.1f", Functions::UnityEngine::Time::GetTimeSinceLevelLoad());
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

	if (ShowMenu == true)
	{
		//ImGui::ShowStyleEditor();
		//ImGui::ShowDemoWindow();
		//ImGui::SetNextWindowPos({0, 0});
		ImGui::SetNextWindowSize({ 800, 500 });
		ImGui::Begin("astrohook (2.46)", NULL, ImGuiWindowFlags_NoCollapse);


		ImGui::SameLine();
		if (ImGui::Button("   Visuals   "))
			switchTabs = 0;

		ImGui::SameLine();
		if (ImGui::Button("   Misc   "))
			switchTabs = 1;

		//ImGui::SameLine();
		//if (ImGui::Button("   Scripting   "))
		//	switchTabs = 2;

		if (Functions::UnityEngine::Application::GetLevelIndex() > 0)
		{
			switch (switchTabs) {
			case 0:
				if (ImGui::CollapsingHeader("World"))
				{
					ImGui::Checkbox("FOV Changer", &Variables::Hacks::FOVChanger);
					if (Variables::Hacks::FOVChanger)
						ImGui::SliderFloat("Custom FOV", &Variables::Hacks::FOV, -180.f, 180.f);
					ImGui::Checkbox("Disable Fog", &Variables::Hacks::FogDisabler);
				}
				break;
			case 1:
				if (ImGui::CollapsingHeader("General"))
				{
					ImGui::Checkbox("Infinite Toast", &Variables::Hacks::INFToast);
					ImGui::Checkbox("Infinite Custard", &Variables::Hacks::INFCustard);
					ImGui::SameLine();
					HelpMarker("Quite buggy but it in theory should work.");
					ImGui::Checkbox("Clientside-Master", &Variables::Hacks::ForceMaster);
					ImGui::Checkbox("Hat Spoofer", &Variables::Hacks::HatSpoofer);
					ImGui::SameLine();
					HelpMarker("I recommend activating this before you enter the menu to ensure it works.");
					if (Variables::Hacks::HatSpoofer)
					{
						ImGui::SliderInt("HatID", &Variables::Hacks::HatID, 0, 100);
						ImGui::SliderInt("HatList", &Variables::Hacks::HatList, 0, 100);
					}
					//ImGui::Separator();
					//ImGui::Checkbox("Server Region Spoofer", &Variables::Hacks::ServerRegionSpoofer);
					//ImGui::SameLine();
					//HelpMarker("Spoofs the server region.");
					//if (Variables::Hacks::ServerRegionSpoofer)       ----------- ITS PATCHED!!!!!!!!!!!!!!!!!!!!!!!
					//{
					//	ImGui::SliderInt("Region", &Variables::Hacks::ServerRegion, -1, 10);
					//} 
					ImGui::Separator();
					ImGui::SliderFloat("Timescale Amount", &Variables::Hacks::TimescaleAmount, 0.f, 20.f);
					ImGui::Combo("Timescale Type", &Variables::Hacks::Timescale_type, Variables::Hacks::Timescale_types, IM_ARRAYSIZE(Variables::Hacks::Timescale_types));
					if (Variables::Hacks::Timescale_type == 0)
						if (ImGui::Button("Set Timescale"))
							Functions::UnityEngine::Time::SetTimescale(Variables::Hacks::TimescaleAmount);
					ImGui::Separator();
					ImGui::SliderInt("Level ID", &Variables::Hacks::LevelID, 0, 42);
					ImGui::SameLine();
					HelpMarker("11 = Blue Room");
					if (ImGui::Button("Load Level"))
					{
						ShowMenu = false;
						if (!Variables::Hacks::LoadLevelServerside)
							Functions::UnityEngine::Application::LoadLevel(Variables::Hacks::LevelID);
						else
							Functions::PhotonPlayer::LoadLevel(Variables::Hacks::LevelID);
					}
					ImGui::Checkbox("Load Via Photon", &Variables::Hacks::LoadLevelServerside);
					ImGui::SameLine();
					HelpMarker("Loads the level via Photon. (useless for now ig)");
					if (ImGui::Button("Join Random Room (use on serverlist)"))
						Functions::PhotonNetwork::JoinRandomRoom();
					if (ImGui::CollapsingHeader("Room Options"))
					{
						if (Functions::PhotonNetwork::get_inRoom())
						{
							ImGui::SliderFloat("Max Players", &Variables::Hacks::FOV, 0.f, 30.f);
							if (ImGui::Button("Set Max Players"))
								Functions::Room::SetMaxPlayers(Functions::PhotonNetwork::get_room(), Variables::Hacks::MaxPlayers);
							if (ImGui::Button("Show Room"))
								Functions::Room::SetVisible(Functions::PhotonNetwork::get_room(), true);
							if (ImGui::Button("Hide Room"))
								Functions::Room::SetVisible(Functions::PhotonNetwork::get_room(), false);
							if (ImGui::Button("Open Room"))
								Functions::Room::SetVisible(Functions::PhotonNetwork::get_room(), true);
							if (ImGui::Button("Close Room"))
								Functions::Room::SetVisible(Functions::PhotonNetwork::get_room(), false);
							if (ImGui::Button("Crash Server (SetMasterClient)"))
								Functions::PhotonNetwork::SetMasterClient(Functions::PhotonNetwork::get_player());
							if (ImGui::Button("Crash Server #2 (CloseConnection)"))
								Functions::PhotonNetwork::CloseConnection(Functions::PhotonNetwork::get_player());
						}
						else
						{
							ImGui::Text("Consider joining a room...");
						}
					}
				}
				if (ImGui::CollapsingHeader("Other"))
				{
					ImGui::Checkbox("Disable Photon RPC", &Variables::Hacks::RPCDisabler);
					ImGui::SameLine();
					HelpMarker("This only disables one of the RPC functions ill add them all later.");
					ImGui::Checkbox("Debug Menu", &Variables::Hacks::DebugMenu);
					ImGui::ColorEdit4("Menu Border Color##1", (float*)&Variables::Hacks::Border_color);
					ImGui::Checkbox("Watermark", &Variables::Hacks::Watermark);
					ImGui::SameLine();
					ImGui::ColorEdit4("Watermark Color##1", (float*)&Variables::Hacks::Watermark_color);
					ImGui::Checkbox("Crosshair ", &Variables::Hacks::Crosshair);
					ImGui::SameLine();
					ImGui::ColorEdit4("Crosshair Color##1", (float*)&Variables::Hacks::Crosshair_color);
					ImGui::Combo("Crosshair Type", &Variables::Hacks::Crosshair_type, Variables::Hacks::Crosshair_types, IM_ARRAYSIZE(Variables::Hacks::Crosshair_types));
					if (Variables::Hacks::Crosshair_type == 0)
						ImGui::SliderFloat("Circle Segments", &Variables::Hacks::Crosshair_segments, 1.f, 100.f);
					else
						ImGui::SliderFloat("Square Rounding", &Variables::Hacks::Crosshair_rounding, 0.f, 12.f);
				}
				if (ImGui::CollapsingHeader("Credits"))
				{
					ImGui::Text("Created by: Astroux#4200");
					ImGui::Text("This cheat is extremely unstable, it will probably crash a couple times.");
				}
				break;
				//case 2:
				//	if (ImGui::CollapsingHeader("LUA"))
				//	{
				//		ImGui::InputTextMultiline("LUA Input", Variables::Hacks::ScriptInput, IM_ARRAYSIZE(Variables::Hacks::ScriptInput));
				//		if (ImGui::Button("Compile & Execute"))
				//		{
				//			PyRun_SimpleString(Variables::Hacks::ScriptInput);
				//		}
				//	}
				//	break;
			}
			ImGui::End();
		}
		else
		{
			ImGui::Text("Click 'Play' before you config the cheat.");
		}
	}

	auto draw_list = ImGui::GetBackgroundDrawList();
	auto yOffset = 0;

	if (Variables::Hacks::Watermark)
	{
		draw_list->AddRectFilled(ImVec2(6, 4 + yOffset), ImVec2((4 * 2) + ImGui::CalcTextSize("astrohook - Astroux#4200").x + 6, 6 + yOffset), ImGui::GetColorU32(Variables::Hacks::Watermark_color));
		draw_list->AddRectFilled(ImVec2(6, 6 + yOffset), ImVec2((4 * 2) + ImGui::CalcTextSize("astrohook - Astroux#4200").x + 6, 25 + yOffset), ImColor(0.2117647081613541f, 0.2235294133424759f, 0.2470588237047195f, 0.3f));
		draw_list->AddText(ImVec2(10, 8 + yOffset), ImColor(255, 255, 255, 255), "astrohook - Astroux#4200");
		draw_list->AddText(ImVec2(Process::WindowWidth, Process::WindowHeight), ImColor(255, 255, 255, 255), "astrohook - Astroux#4200");
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

	if (Variables::Hacks::Timescale_type == 1)
	{
		if (GetAsyncKeyState(VK_XBUTTON2))
			Functions::UnityEngine::Time::SetTimescale(Variables::Hacks::TimescaleAmount);
		else
			Functions::UnityEngine::Time::SetTimescale(1.000f);
	}

	Functions::UnityEngine::RenderSettings::SetFog(!Variables::Hacks::FogDisabler);
	//Functions::UnityEngine::Application::SetMaxFPS(10000);

	ImGuiStyle* style = &ImGui::GetStyle();
	style->Colors[ImGuiCol_Border] = Variables::Hacks::Border_color;

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
	MH_CreateHook(reinterpret_cast<LPVOID*>(ST3::Modules::GameAssembly + ST3::Offsets::RoomMultiplayerMenu::KickPlayerMaster), &Hooks::KickPlayerMaster, (LPVOID*)&Hooks::KickPlayerMaster_org);
	MH_CreateHook(reinterpret_cast<LPVOID*>(ST3::Modules::GameAssembly + ST3::Offsets::PhotonNetwork::get_isMasterClient), &Hooks::get_isMasterClient, (LPVOID*)&Hooks::get_isMasterClient_org);
	MH_CreateHook(reinterpret_cast<LPVOID*>(ST3::Modules::GameAssembly + ST3::Offsets::PhotonView::RPC), &Hooks::PhotonRPC, (LPVOID*)&Hooks::PhotonRPC_org);
	MH_CreateHook(reinterpret_cast<LPVOID*>(ST3::Modules::GameAssembly + ST3::Offsets::CodeStage::SetInt), &Hooks::SetInt, (LPVOID*)&Hooks::SetInt_org);
	MH_CreateHook(reinterpret_cast<LPVOID*>(ST3::Modules::GameAssembly + ST3::Offsets::CodeStage::GetInt), &Hooks::GetInt, (LPVOID*)&Hooks::GetInt_org);
	MH_CreateHook(reinterpret_cast<LPVOID*>(ST3::Modules::GameAssembly + ST3::Offsets::CodeStage::SetString), &Hooks::SetString, (LPVOID*)&Hooks::SetString_org);
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