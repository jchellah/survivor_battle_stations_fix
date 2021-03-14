#ifndef _INCLUDE_SOURCEMOD_EXTENSION_CONFIG_H_
#define _INCLUDE_SOURCEMOD_EXTENSION_CONFIG_H_

#define GAMEDATA_FILE			"survivor_battle_stations_fix"

#define SMEXT_CONF_NAME			"[L4D/2] Survivor Battle Stations Fix"
#define SMEXT_CONF_DESCRIPTION	"Fixes an issue related to bots giving up battle station for covering a friend in combat"
#define SMEXT_CONF_VERSION		"1.0.0"
#define SMEXT_CONF_AUTHOR		"Jay"
#define SMEXT_CONF_URL			"https://github.com/jaychellah/survivor_battle_stations_fix"
#define SMEXT_CONF_LOGTAG		"L4D2-SBSF"
#define SMEXT_CONF_LICENSE		"MIT"
#define SMEXT_CONF_DATESTRING	__DATE__

#define SMEXT_LINK(name) SDKExtension *g_pExtensionIface = name;

#define SMEXT_CONF_METAMOD		

#define SMEXT_ENABLE_GAMECONF

#endif // _INCLUDE_SOURCEMOD_EXTENSION_CONFIG_H_