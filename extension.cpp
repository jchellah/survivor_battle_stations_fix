#include "extension.h"
#include "CDetour/detours.h"

CSurvivorBattleStationsFix g_SurvivorLegsBattleStationsFix;

SMEXT_LINK(&g_SurvivorLegsBattleStationsFix);

DETOUR_DECL_MEMBER2(DetourFunc_SurvivorLegsStayClose_Update, ActionResult<CBaseEntity>, CBaseEntity *, pBot, float, flInterval)
{
	Action<CBaseEntity> *pAction = reinterpret_cast<Action<CBaseEntity> *>(this);
	Action<CBaseEntity> *pChild = pAction->GetActiveChildAction();

	if (pChild && pChild->IsNamed("SurvivorLegsBattleStations"))
	{
		ActionResult<CBaseEntity> invocationResult = DETOUR_MEMBER_CALL(DetourFunc_SurvivorLegsStayClose_Update)(pBot, flInterval);

		if (invocationResult.IsRequestingChange() && invocationResult.m_action->IsNamed("SurvivorLegsCoverFriendInCombat"))
		{
			delete invocationResult.m_action;

			return pAction->Continue();
		}

		return invocationResult;
	}

	return DETOUR_MEMBER_CALL(DetourFunc_SurvivorLegsStayClose_Update)(pBot, flInterval);
}

bool CSurvivorBattleStationsFix::SDK_OnLoad(char *error, size_t maxlen, bool late)
{
	IGameConfig *pGameConfig = NULL;

	if (!gameconfs->LoadGameConfigFile(GAMEDATA_FILE, &pGameConfig, error, sizeof(error))) 
	{
		ke::SafeStrcpy(error, maxlen, "Unable to load gamedata file \"" GAMEDATA_FILE ".txt\"");

		return false;
	}

	CDetourManager::Init(smutils->GetScriptingEngine(), pGameConfig);

	m_pDetour_SurvivorLegsStayClose_Update = DETOUR_CREATE_MEMBER(DetourFunc_SurvivorLegsStayClose_Update, "SurvivorLegsStayClose::Update");

	if (m_pDetour_SurvivorLegsStayClose_Update)
	{
		m_pDetour_SurvivorLegsStayClose_Update->EnableDetour();
	}
	else
	{
		ke::SafeStrcpy(error, maxlen, "Failed to initialize detour SurvivorLegsStayClose::Update");

		gameconfs->CloseGameConfigFile(pGameConfig);

		return false;
	}

	gameconfs->CloseGameConfigFile(pGameConfig);
	
	return true;
}

void CSurvivorBattleStationsFix::SDK_OnUnload()
{
	if (m_pDetour_SurvivorLegsStayClose_Update)
	{
		m_pDetour_SurvivorLegsStayClose_Update->Destroy();
	}
}