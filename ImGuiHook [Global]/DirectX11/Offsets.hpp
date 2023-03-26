#pragma once

// V2.46

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
			uintptr_t CheckCheatEngine = 22763136;
			uintptr_t OnSpeedhackDetected = 22763328;
			uintptr_t OnInjectionDetected = 22763168;
			uintptr_t OnObscuredCheatingDetected = 22763248;
			uintptr_t OnLevelWasLoaded = 22763136;
		}
		namespace KickButton
		{
			uintptr_t SendKick = 20001088; // idfk /shrug
		}
		namespace PhotonNetwork
		{
			uintptr_t Disconnect = 10293392;
			uintptr_t CreateRoom = 10291952;
			uintptr_t get_player = 10323696;
			uintptr_t get_room = 10323856;
			uintptr_t get_masterClient = 10322656;
			uintptr_t get_playerList = 10323408;
			uintptr_t GetRoomList = 10295184;
			uintptr_t GetPing = 10295072;
			uintptr_t get_isMasterClient = 10321968;
			uintptr_t get_inRoom = 10321776;
			uintptr_t JoinRandomRoom = 10298192;
			uintptr_t LeaveRoom = 10299296;
			uintptr_t LeaveLobby = 10299088;
			uintptr_t CloseConnection = 10285344;
			uintptr_t SetMasterClient = 10311280;
			uintptr_t get_ServerAddress = 10318416;
			uintptr_t get_gameVersion = 10321680;
			uintptr_t get_Server = 10319024;
			uintptr_t DestroyAll = 10292064;
			uintptr_t DestroyPlayerObjects = 10292672;
			uintptr_t RemoveRPCs = 10310144;
		}
		namespace PhotonView
		{
			uintptr_t get_viewID = 10365568;
			uintptr_t set_viewID = 10365584;
			uintptr_t get_isSceneView = 10365264;
			uintptr_t get_owner = 10365376;
			uintptr_t get_OwnerActorNr = 3374832;
			uintptr_t get_isOwnerActive = 10365120;
			uintptr_t get_CreatorActorNr = 10364576;
			uintptr_t get_isMine = 10364816;
			uintptr_t RPC = 10360848;
			uintptr_t RPCSecure = 10361328;
			uintptr_t PlayerRPC = 10360704;
			uintptr_t PlayerRPCSecure = 10361184;
			uintptr_t OnMasterClientSwitched = 10360528;
			uintptr_t SerializeView = 10363056;
		}
		namespace PhotonPlayer
		{
			uintptr_t get_ID = 3374752;
			uintptr_t get_NickName = 2144016;
			uintptr_t set_NickName = 10334048;
			uintptr_t get_UserId = 2952864;
			uintptr_t set_UserId = 2952656;
			uintptr_t get_isMasterClient = 10333888;
			uintptr_t get_isLocal = 3392208;
			uintptr_t LoadLevel = 10299824;
			uintptr_t WebRpc = 10315168;
		}
		namespace Room
		{
			uintptr_t get_open = 5501072;
			uintptr_t set_open = 28811840;
			uintptr_t get_visible = 8637456;
			uintptr_t set_visible = 28811856;
			uintptr_t get_maxPlayers = 4031568;
			uintptr_t set_maxPlayers = 28811824;
			uintptr_t get_playerCount = 28810208;
			uintptr_t get_masterClientId = 7556720;
			uintptr_t set_masterClientId = 7556736;
		}
		namespace RoomInfo
		{
			uintptr_t get_serverSideMasterClient = 9720976;
			uintptr_t set_serverSideMasterClient = 9721216;
			uintptr_t get_PlayerCount = 6623552;
			uintptr_t set_PlayerCount = 5938672;
		}
		namespace RoomMultiplayerMenu
		{
			uintptr_t OnMasterClientSwitched = 4748800;
			uintptr_t KickPlayerMaster = 4691168;  // kick function - not even sure if this is the func lol
			uintptr_t RespawnPlayer2 = 4753968;
			uintptr_t SpawnPlayer = 4754544;
			uintptr_t LeaveRoom2 = 4703216;
		}
		namespace CodeStage
		{
			uintptr_t SetInt = 28697632;
			uintptr_t SetBool = 28695904;
			uintptr_t SetFloat = 28697376;
			uintptr_t SetString = 28699408;
			uintptr_t GetInt = 28685552;
			uintptr_t GetBool = 28681872;
			uintptr_t GetFloat = 28685040;
			uintptr_t GetString = 28688400;
		}
		namespace PlayerDamage
		{
			uintptr_t Awake = 3179664;
			uintptr_t Update = 3193568;
		}
		namespace ShopSystem
		{
			uintptr_t HealPlayer = 5029952; // keeps crashing /shrug
		}
		namespace Volume
		{
			uintptr_t ForceOtherPlayers = 3533216; // crashes aswell /shrug
		}
		namespace FPSController
		{
			uintptr_t FPScontrollerMovement_TypeInfo = 36606312;
			namespace FPScontrollerMovement
			{
				uintptr_t WalkSpeed = 0x1C;
				uintptr_t RunSpeed = 0x20;
				uintptr_t canCrouch = 0x24;
				uintptr_t CrouchSpeed = 0x28;
				uintptr_t crouchHeight = 0x2C;
				uintptr_t gravity = 0x50;
				uintptr_t enableGravity = 0x58;
			}
		}
		namespace UnityEngine
		{
			namespace RenderSettings
			{
				uintptr_t set_fog = 15671808;
				uintptr_t get_fog = 15671376;
				uintptr_t get_fogStartDistance = 15671328;
				uintptr_t get_fogEndDistance = 15671232;
				uintptr_t get_fogMode = 15671280;
				uintptr_t get_fogColor = 15671120;
				uintptr_t set_fogColor = 15671680;
				uintptr_t set_fogColorInjected = 15671056;
				uintptr_t get_fogDensity = 15671184;
				uintptr_t set_fogDensity = 15671744;
				uintptr_t get_ambientMode = 15670880;
				uintptr_t set_ambientMode = 15671424;
			}
			namespace Camera
			{
				uintptr_t get_fieldOfView = 15705968;
				uintptr_t set_fieldOfView = 15708080;
				uintptr_t get_allowHDR = 15705120;
				uintptr_t set_allowHDR = 15707264;
				uintptr_t get_depth = 15705776;
				uintptr_t set_depth = 15707920;
				uintptr_t get_aspect = 15705248;
				uintptr_t set_aspect = 15707424;
				uintptr_t get_cameraType = 15705472;
				uintptr_t set_cameraType = 15707664;
			}
			namespace Time
			{
				uintptr_t get_time = 15535952;
				uintptr_t get_timeSinceLevelLoad = 15535904;
				uintptr_t get_deltaTime = 15535616;
				uintptr_t get_timeScale = 15535856;
				uintptr_t set_timeScale = 15536160;
				uintptr_t get_frameCount = 15535712;
			}
			namespace SystemInfo
			{
				uintptr_t get_deviceUniqueIdentifier = 15521024; // used for hwid shit which is not used in st3 /shrug
			}
			namespace Object
			{
				uintptr_t Destroy = 15621504;
			}
			namespace Application
			{
				uintptr_t Quit = 15686960;
				uintptr_t LoadLevel = 15686640;
				uintptr_t LoadLevelName = 15686736;
				uintptr_t LoadLevelAsync = 15686544;
				uintptr_t get_loadedLevel = 15687632;
				uintptr_t get_loadedLevelName = 15687536;
				uintptr_t get_targetFrameRate = 15687824;
				uintptr_t set_targetFrameRate = 15688224;
			}
		}
	}
}