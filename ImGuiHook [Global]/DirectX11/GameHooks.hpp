#pragma once

#include <windows.h>
#include <cstdint>

#include "Main.hpp"

namespace Hooks
{
	void(__fastcall* CheckCheatEngine_org)(DWORD*, DWORD*);
	void __stdcall CheckCheatEngine(DWORD* __this, DWORD* method);

	void(__fastcall* OnSpeedhackDetected_org)(DWORD*, DWORD*);
	void __stdcall OnSpeedhackDetected(DWORD* __this, DWORD* method);

	void(__fastcall* OnInjectionDetected_org)(DWORD*, DWORD*);
	void __stdcall OnInjectionDetected(DWORD* __this, DWORD* method);

	void(__fastcall* OnObscuredCheatingDetected_org)(DWORD*, DWORD*);
	void __stdcall OnObscuredCheatingDetected(DWORD* __this, DWORD* method);

	void(__fastcall* OnLevelWasLoaded_org)(DWORD*, int32_t, DWORD*);
	void __stdcall OnLevelWasLoaded(DWORD* __this, int32_t level, DWORD* method);

	bool(__fastcall* LeaveRoom_org)(DWORD*); 
	bool __stdcall LeaveRoom(DWORD* method);

	void(__fastcall* Disconnect_org)(DWORD*);
	void __stdcall Disconnect(DWORD* method);

	bool(__fastcall* get_isMasterClient_org)(DWORD*);
	bool __stdcall get_isMasterClient(DWORD* method);

	float(__fastcall* get_fieldOfView_org)(DWORD*, DWORD*);
	float __stdcall get_fieldOfView(DWORD* __this, DWORD* method);

	void(__fastcall* PhotonRPC_org)(DWORD*, const char*, int32_t, DWORD*, DWORD*);
	void __stdcall PhotonRPC(DWORD* __this, const char* methodName, int32_t target, DWORD* parameters, DWORD* method);

	void(__fastcall* SetInt_org)(const char*, int32_t, DWORD*);
	void __stdcall SetInt(const char* key, int32_t amount, DWORD* method);

	int32_t(__fastcall* GetInt_org)(const char*, int32_t, DWORD*);
	int32_t __stdcall GetInt(const char* key, int32_t defaultValue, DWORD* method);

	void(__fastcall* SetString_org)(const char*, const char*, DWORD*);
	void __stdcall SetString(const char* key, const char* value, DWORD* method);

	void(__fastcall* GetString_org)(const char*, const char*, DWORD*);
	void __stdcall GetString(const char* key, const char* defaultValue, DWORD* method);

	DWORD* (__fastcall* LoadLevelAsync_org)(const wchar_t*, DWORD*);
	DWORD* __stdcall LoadLevelAsync(const wchar_t* levelName, DWORD* method);
}
