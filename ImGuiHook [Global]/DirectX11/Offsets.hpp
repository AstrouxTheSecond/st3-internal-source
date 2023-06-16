#pragma once

// V2.48

namespace ST3
{
	namespace Modules
	{
		uintptr_t ModuleBase;
		uintptr_t GameAssembly;
		HMODULE GameAssemblyHandle;
		uintptr_t UnityPlayer;
	}
	namespace Offsets
	{
		namespace AntiCheat
		{
			uintptr_t CheckCheatEngine = 27124272;
			uintptr_t OnSpeedhackDetected = 27124464;
			uintptr_t OnInjectionDetected = 27124304;
			uintptr_t OnObscuredCheatingDetected = 27124384;
			uintptr_t OnLevelWasLoaded = 27124272;
		}
		namespace KickButton
		{
			uintptr_t SendKick = 23118320; // idfk /shrug
		}
		namespace PhotonNetwork
		{
			uintptr_t Disconnect = 10225296;
			uintptr_t CreateRoom = 10223856;
			uintptr_t get_player = 10255600;
			uintptr_t get_room = 10255760;
			uintptr_t get_masterClient = 10254560;
			uintptr_t get_playerList = 10255312;
			uintptr_t GetRoomList = 10227088;
			uintptr_t GetPing = 10226976;
			uintptr_t get_isMasterClient = 10253872;
			uintptr_t get_inRoom = 10253680;
			uintptr_t JoinRandomRoom = 10230096;
			uintptr_t LeaveRoom = 10231200;
			uintptr_t LeaveLobby = 10230992;
			uintptr_t CloseConnection = 10217248;
			uintptr_t SetMasterClient = 10243184;
			uintptr_t get_ServerAddress = 10250320;
			uintptr_t get_gameVersion = 10253584;
			uintptr_t get_Server = 10250928;
			uintptr_t DestroyAll = 10223968;
			uintptr_t DestroyPlayerObjects = 10224576;
			uintptr_t RemoveRPCs = 10310144;
		}
		namespace PhotonView
		{
			uintptr_t get_viewID = 6801856;
			uintptr_t set_viewID = 10297504;
			uintptr_t get_isSceneView = 10297200;
			uintptr_t get_owner = 10297312;
			uintptr_t get_OwnerActorNr = 4937792;
			uintptr_t get_isOwnerActive = 10297056;
			uintptr_t get_CreatorActorNr = 10296512;
			uintptr_t get_isMine = 10296752;
			uintptr_t RPC = 10292784;
			uintptr_t RPCSecure = 10293264;
			uintptr_t PlayerRPC = 10292640;
			uintptr_t PlayerRPCSecure = 10293120;
			uintptr_t OnMasterClientSwitched = 10292464;
			uintptr_t SerializeView = 10294992;
		}
		namespace PhotonPlayer
		{
			uintptr_t get_ID = 3050656;
			uintptr_t get_NickName = 2350160;
			uintptr_t set_NickName = 10265952;
			uintptr_t get_UserId = 3211216;
			uintptr_t set_UserId = 3212288;
			uintptr_t get_isMasterClient = 10265920;
			uintptr_t get_isLocal = 4955072;
			uintptr_t LoadLevel = 10231728;
			uintptr_t WebRpc = 10247072;
		}
		namespace Room
		{
			uintptr_t get_open = 6501792;
			uintptr_t set_open = 28306128;
			uintptr_t get_visible = 680680;
			uintptr_t set_visible = 28306144;
			uintptr_t get_maxPlayers = 3051696;
			uintptr_t set_maxPlayers = 28306112;
			uintptr_t get_playerCount = 28304496;
			uintptr_t get_masterClientId = 8159664;
			uintptr_t set_masterClientId = 8159680;
		}
		namespace RoomInfo
		{
			uintptr_t get_serverSideMasterClient = 3050688;
			uintptr_t set_serverSideMasterClient = 3051232;
			uintptr_t get_PlayerCount = 3210784;
			uintptr_t set_PlayerCount = 3211792;
		}
		namespace RoomMultiplayerMenu
		{
			uintptr_t OnMasterClientSwitched = 4857984;
			uintptr_t KickPlayerMaster = 4802832;  // kick function - not even sure if this is the func lol
			uintptr_t RespawnPlayer2 = 4869152;
			uintptr_t SpawnPlayer = 4869728;
			uintptr_t LeaveRoom2 = 4821568;
		}
		namespace CodeStage
		{
			uintptr_t SetInt = 28241184;
			uintptr_t SetBool = 28239456;
			uintptr_t SetFloat = 28240928;
			uintptr_t SetString = 28242960;
			uintptr_t GetInt = 28229104;
			uintptr_t GetBool = 28225424;
			uintptr_t GetFloat = 28228592
			uintptr_t GetString = 28231952;
		}
		namespace PlayerDamage
		{
			uintptr_t Awake = 11040512;
			uintptr_t Update = 11064656;
			uintptr_t DoDamage = 11055872;
		}
		namespace ShopSystem
		{
			uintptr_t HealPlayer = 5029952; // keeps crashing /shrug
		}
		namespace Volume
		{
			uintptr_t ForceOtherPlayers = 11623968; // crashes aswell /shrug
		}
		namespace WeaponAnimation
		{
			uintptr_t Update = 22585280;
		}
		namespace WeaponCrosshair
		{
			uintptr_t Update = 7822416;
		}
		namespace WeaponSync
		{
			uintptr_t syncShotgun = 6035472;
		}
		namespace UnityEngine
		{
			namespace Screen
			{
				uintptr_t get_width = 14679616;
				uintptr_t get_height = 14679488;
				uintptr_t get_dpi = 14679392;
				uintptr_t get_fullScreenMode = 14679440;
				uintptr_t set_fullScreenMode = 14679664;
				uintptr_t SetResolution = 14679168;
				uintptr_t get_lockCursor = 14679536;
				uintptr_t set_lockCursor = 14679728;
			}
			namespace QualitySettings
			{
				uintptr_t GetQualityLevel = 14821632;
				uintptr_t SetQualityLevel = 14821744;
				uintptr_t set_shadowDistance = 14822400;
				uintptr_t get_anisotropicFiltering = 14821856;
				uintptr_t set_anisotropicFiltering = 14822144;
			}
			namespace RenderSettings
			{
				uintptr_t set_fog = 14846560;
				uintptr_t get_fog = 14846128;
				uintptr_t get_fogStartDistance = 14846080;
				uintptr_t get_fogEndDistance = 14845984;
				uintptr_t get_fogMode = 14846032;
				uintptr_t get_fogColor = 14845872;
				uintptr_t set_fogColor = 14846432;
				uintptr_t set_fogColorInjected = 15671056;
				uintptr_t get_fogDensity = 14845936;
				uintptr_t set_fogDensity = 14846496;
				uintptr_t get_ambientMode = 14845632;
				uintptr_t set_ambientMode = 14846176;
			}
			namespace Camera
			{
				uintptr_t get_main = 14880784;
				uintptr_t get_current = 14880416;
				uintptr_t get_fieldOfView = 14880720;
				uintptr_t set_fieldOfView = 14882832;
				uintptr_t get_allowHDR = 14879872;
				uintptr_t set_allowHDR = 14882016;
				uintptr_t get_depth = 14880528;
				uintptr_t set_depth = 14882672;
				uintptr_t get_aspect = 14880000;
				uintptr_t set_aspect = 14882176;
				uintptr_t get_cameraType = 14880224;
				uintptr_t set_cameraType = 14882416;
			}
			namespace Time
			{
				uintptr_t get_time = 14710640;
				uintptr_t get_timeSinceLevelLoad = 14710592;
				uintptr_t get_deltaTime = 14710304;
				uintptr_t get_timeScale = 14710544;
				uintptr_t set_timeScale = 14710848;
				uintptr_t get_frameCount = 14710400;
			}
			namespace SystemInfo
			{
				uintptr_t get_deviceUniqueIdentifier = 14695712; // used for hwid shit which is not used in st3 /shrug
			}
			namespace Object
			{
				uintptr_t Destroy = 14796256;
			}
			namespace Application
			{
				uintptr_t Quit = 14861648;
				uintptr_t LoadLevel = 14861392;
				uintptr_t LoadLevelName = 14861488;
				uintptr_t LoadLevelAsync = 14861296;
				uintptr_t get_loadedLevel = 14862384;
				uintptr_t get_loadedLevelName = 14862288;
				uintptr_t get_targetFrameRate = 14862576;
				uintptr_t set_targetFrameRate = 14862976;
			}
		}
		namespace System
		{
			namespace String
			{
				uintptr_t CreateString = 12604640;
			}
		}
	}
}
