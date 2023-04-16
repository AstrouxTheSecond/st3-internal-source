#pragma once

#include "Offsets.hpp"
#include "Structs.hpp"
#include <wtypes.h>
#include <cstdint>

namespace Functions
{
	typedef System_String_o* (*createString)(System_String_o* __this, int8_t* value, int32_t startIndex, int32_t length);
	LPVOID createStringAddress = reinterpret_cast<LPVOID>(ST3::Modules::GameAssembly + ST3::Offsets::System::String::CreateString);
	createString CreateString = (createString)createStringAddress;
	System_String_o* sysstr = CreateString(NULL, (int8_t*)"4", 0, strlen("4"));

	namespace UnityEngine 
	{
		namespace Screen 
		{
			void SetLockCursor(bool locked)
			{
				((void(*)(bool))(ST3::Modules::GameAssembly + ST3::Offsets::UnityEngine::Screen::set_lockCursor))(locked);
			}

			bool GetLockCursor()
			{
				return ((bool(*)())(ST3::Modules::GameAssembly + ST3::Offsets::UnityEngine::Screen::get_lockCursor))();
			}
		}
		namespace Time 
		{
			float GetTime()
			{
				return ((float(*)())(ST3::Modules::GameAssembly + ST3::Offsets::UnityEngine::Time::get_time))();
			}

			float GetDeltaTime()
			{
				return ((float(*)())(ST3::Modules::GameAssembly + ST3::Offsets::UnityEngine::Time::get_deltaTime))();
			}

			float GetTimeSinceLevelLoad()
			{
				return ((float(*)())(ST3::Modules::GameAssembly + ST3::Offsets::UnityEngine::Time::get_timeSinceLevelLoad))();
			}

			void SetTimescale(float amount)
			{
				((void(*)(float))(ST3::Modules::GameAssembly + ST3::Offsets::UnityEngine::Time::set_timeScale))(amount);
			}

			float GetTimescale()
			{
				return ((float(*)())(ST3::Modules::GameAssembly + ST3::Offsets::UnityEngine::Time::get_timeScale))();
			}

			int32_t GetFrameCount()
			{
				return ((int32_t(*)())(ST3::Modules::GameAssembly + ST3::Offsets::UnityEngine::Time::get_frameCount))();
			}
		}
		namespace QualitySettings
		{
			void SetQualityLevel(int32_t level)
			{
				((void(*)(bool))(ST3::Modules::GameAssembly + ST3::Offsets::UnityEngine::RenderSettings::set_fog))(level);
			}

			int32_t GetQualityLevel()
			{
				return ((int32_t(*)())(ST3::Modules::GameAssembly + ST3::Offsets::UnityEngine::QualitySettings::GetQualityLevel))();
			}
		}
		namespace Camera
		{
			DWORD* get_main()
			{
				return ((DWORD*(*)())(ST3::Modules::GameAssembly + ST3::Offsets::UnityEngine::Camera::get_main))();
			}

			DWORD* get_current()
			{
				return ((DWORD*(*)())(ST3::Modules::GameAssembly + ST3::Offsets::UnityEngine::Camera::get_current))();
			}
		}
		namespace RenderSettings 
		{
			void SetFog(bool value)
			{
				((void(*)(bool))(ST3::Modules::GameAssembly + ST3::Offsets::UnityEngine::RenderSettings::set_fog))(value);
			}

			bool GetFog()
			{
				return ((bool(*)())(ST3::Modules::GameAssembly + ST3::Offsets::UnityEngine::RenderSettings::get_fog))();
			}

			void SetAmbientMode(int32_t value)
			{
				((void(*)(int32_t))(ST3::Modules::GameAssembly + ST3::Offsets::UnityEngine::RenderSettings::set_ambientMode))(value);
			}

			int32_t GetAmbientMode()
			{
				return ((int32_t(*)())(ST3::Modules::GameAssembly + ST3::Offsets::UnityEngine::RenderSettings::get_ambientMode))();
			}

		}
		namespace Application 
		{
			void LoadLevel(int32_t index)
			{
				((void(*)(int32_t))(ST3::Modules::GameAssembly + ST3::Offsets::UnityEngine::Application::LoadLevel))(index);
			}

			void SetMaxFPS(int32_t value)
			{
				((void(*)(int32_t))(ST3::Modules::GameAssembly + ST3::Offsets::UnityEngine::Application::set_targetFrameRate))(value);
			}

			int32_t GetMaxFPS()
			{
				return ((int32_t(*)())(ST3::Modules::GameAssembly + ST3::Offsets::UnityEngine::Application::get_targetFrameRate))();
			}

			int32_t GetLevelIndex()
			{
				return ((int32_t(*)())(ST3::Modules::GameAssembly + ST3::Offsets::UnityEngine::Application::get_loadedLevel))();
			}
		}
	}
	namespace PhotonPlayer
	{
		void LoadLevel(int32_t index) // loading it via photon /shrug
		{
			((void(*)(int32_t))(ST3::Modules::GameAssembly + ST3::Offsets::PhotonPlayer::LoadLevel))(index);
		}
	}
	namespace PhotonNetwork
	{
		bool JoinRandomRoom()
		{
			((bool(*)())(ST3::Modules::GameAssembly + ST3::Offsets::PhotonNetwork::JoinRandomRoom))();
			return true;
		}

		void Disconnect()
		{
			((void(*)())(ST3::Modules::GameAssembly + ST3::Offsets::PhotonNetwork::Disconnect))();
		}

		bool get_inRoom()
		{
			return ((bool(*)())(ST3::Modules::GameAssembly + ST3::Offsets::PhotonNetwork::get_inRoom))();
		}

		DWORD* get_player()
		{
			return ((DWORD*(*)())(ST3::Modules::GameAssembly + ST3::Offsets::PhotonNetwork::get_player))();
		}

		DWORD* get_room()
		{
			return ((DWORD*(*)())(ST3::Modules::GameAssembly + ST3::Offsets::PhotonNetwork::get_room))();
		}

		int32_t* get_Server()
		{
			return ((int32_t*(*)())(ST3::Modules::GameAssembly + ST3::Offsets::PhotonNetwork::get_player))();
		}

		bool SetMasterClient(DWORD* PhotonPlayer_o)
		{
			((bool(*)(DWORD*))(ST3::Modules::GameAssembly + ST3::Offsets::PhotonNetwork::SetMasterClient))(PhotonPlayer_o);
			return true;
		}

		bool CloseConnection(DWORD* PhotonPlayer_o)
		{
			((bool(*)(DWORD*))(ST3::Modules::GameAssembly + ST3::Offsets::PhotonNetwork::SetMasterClient))(PhotonPlayer_o);
			return true;
		}

		void SetMaxPlayers(DWORD* Room_o, int32_t max)
		{
			((void(*)(DWORD*, int32_t))(ST3::Modules::GameAssembly + ST3::Offsets::Room::set_maxPlayers))(Room_o, max);
		}
	}
	namespace Room
	{
		void SetVisible(DWORD* Room_o, bool visible)
		{
			((void(*)(DWORD*, int32_t))(ST3::Modules::GameAssembly + ST3::Offsets::Room::set_visible))(Room_o, visible);
		}

		void SetOpen(DWORD* Room_o, bool open)
		{
			((void(*)(DWORD*, int32_t))(ST3::Modules::GameAssembly + ST3::Offsets::Room::set_open))(Room_o, open);
		}

		void SetMaxPlayers(DWORD* Room_o, int32_t max)
		{
			((void(*)(DWORD*, int32_t))(ST3::Modules::GameAssembly + ST3::Offsets::Room::set_maxPlayers))(Room_o, max);
		}

		void SetMasterClientID(DWORD* Room_o, int32_t id)
		{
			((void(*)(DWORD*, int32_t))(ST3::Modules::GameAssembly + ST3::Offsets::Room::set_masterClientId))(Room_o, id);
		}

		bool GetVisible(DWORD* Room_o)
		{
			return ((bool(*)(DWORD*))(ST3::Modules::GameAssembly + ST3::Offsets::Room::get_visible))(Room_o);
		}

		bool GetOpen(DWORD* Room_o)
		{
			return ((bool(*)(DWORD*))(ST3::Modules::GameAssembly + ST3::Offsets::Room::get_open))(Room_o);
		}

		int32_t GetMaxPlayers(DWORD* Room_o)
		{
			return ((int32_t(*)(DWORD*))(ST3::Modules::GameAssembly + ST3::Offsets::Room::get_maxPlayers))(Room_o);
		}
	}
}