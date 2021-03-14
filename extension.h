#ifndef _INCLUDE_SURVIVOR_LEGS_BATTLE_STATIONS_FIX_EXTENSION_PROPER_H_
#define _INCLUDE_SURVIVOR_LEGS_BATTLE_STATIONS_FIX_EXTENSION_PROPER_H_
 
#include "smsdk_ext.h"

#include <ai_activity.h>
#include <shareddefs.h>

class CDetour;
class AI_Response;
class CBaseCombatCharacter;
class CNavArea;

class CAI_Concept
{
public:
	CAI_Concept(const char *concept);
};

// Misc useful
inline bool FStrEq(const char *sz1, const char *sz2)
{
	return(stricmp(sz1, sz2) == 0);
}

extern CGlobalVars *gpGlobals;

#include <NextBot/NextBotBehavior.h>

class CSurvivorBattleStationsFix : public SDKExtension
{
public:
	/**
	 * @brief This is called after the initial loading sequence has been processed.
	 *
	 * @param error		Error message buffer.
	 * @param maxlen	Size of error message buffer.
	 * @param late		Whether or not the module was loaded after map load.
	 * @return			True to succeed loading, false to fail.
	 */
	virtual bool SDK_OnLoad(char *error, size_t maxlen, bool late);

	/**
	 * @brief This is called right before the extension is unloaded.
	 */
	virtual void SDK_OnUnload();

	/**
	 * @brief This is called once all known extensions have been loaded.
	 * Note: It is is a good idea to add natives here, if any are provided.
	 */
	// virtual void SDK_OnAllLoaded();
#ifdef SMEXT_CONF_METAMOD
	/**
	 * @brief Called when Metamod is attached, before the extension version is called.
	 *
	 * @param error			Error buffer.
	 * @param maxlen		Maximum size of error buffer.
	 * @param late			Whether or not Metamod considers this a late load.
	 * @return				True to succeed, false to fail.
	 */
	// virtual bool SDK_OnMetamodLoad(ISmmAPI *ismm, char *error, size_t maxlen, bool late);
#endif
private:
	CDetour *m_pDetour_SurvivorLegsStayClose_Update = NULL;
};

#endif // _INCLUDE_SURVIVOR_LEGS_BATTLE_STATIONS_FIX_EXTENSION_PROPER_H_