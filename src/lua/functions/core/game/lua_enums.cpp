/**
 * Canary - A free and open-source MMORPG server emulator
 * Copyright (©) 2019-2022 OpenTibiaBR <opentibiabr@outlook.com>
 * Repository: https://github.com/opentibiabr/canary
 * License: https://github.com/opentibiabr/canary/blob/main/LICENSE
 * Contributors: https://github.com/opentibiabr/canary/graphs/contributors
 * Website: https://docs.opentibiabr.org/
*/

#include "pch.hpp"

#include "config/configmanager.h"

#include "lua/functions/core/game/lua_enums.hpp"

#include "creatures/players/account/account.hpp"
#include "creatures/creature.h"
#include "lua/creature/creatureevent.h"
#include "declarations.hpp"
#include "game/functions/game_reload.hpp"
#include "game/game.h"

#define registerMagicEnum(luaState, enumClassType) { \
	auto number = magic_enum::enum_integer(enumClassType); \
	auto name = magic_enum::enum_name(enumClassType).data(); \
	SPDLOG_INFO("NAME {}", name);\
	registerGlobalVariable(luaState, name, number); \
} void(0)

#define registerEnum(L, value) { \
	std::string enumName = #value; \
	registerGlobalVariable(L, enumName.substr(enumName.find_last_of(':') + 1), value); \
} void(0)

void LuaEnums::init(lua_State* L) {
	initOthersEnums(L);
	initAccountEnums(L);
	initDailyRewardEnums(L);
	initBugCategoryEnums(L);
	initReportTypeEnums(L);
	initCallbackParamEnums(L);
	initCombatEnums(L);
	initCombatParamEnums(L);
	initCombatFormulaEnums(L);
	initDirectionEnums(L);
	initFactionEnums(L);
	initConditionEnums(L);
	initConditionIdEnums(L);
	initConditionParamEnums(L);
	initConstMeEnums(L);
	initConstAniEnums(L);
	initConstPropEnums(L);
	initConstSlotEnums(L);
	initCreatureEventEnums(L);
	initGameStateEnums(L);
	initMessageEnums(L);
	initCreatureTypeEnums(L);
	initClientOsEnums(L);
	initFightModeEnums(L);
	initItemAttributeEnums(L);
	initItemTypeEnums(L);
	initItemIdEnums(L);
	initPlayerFlagEnums(L);
	initReportReasonEnums(L);
	initSkillEnums(L);
	initSkullEnums(L);
	initTalkTypeEnums(L);
	initBestiaryEnums(L);
	initTextColorEnums(L);
	initTileStateEnums(L);
	initSpeechBubbleEnums(L);
	initMapMarkEnums(L);
	initReturnValueEnums(L);
	initReloadTypeEnums(L);
	initCreaturesEventEnums(L);
	initForgeEnums(L);
	initWebhookEnums(L);
}

void LuaEnums::initOthersEnums(lua_State* L) {
	// World types enum
	for (auto value : magic_enum::enum_values<WorldType_t>()) {
		registerMagicEnum(L, value);
	}
	// Ammo enum
	for (auto value : magic_enum::enum_values<Ammo_t>()) {
		registerMagicEnum(L, value);
	}
	// Charm enum
	for (auto value : magic_enum::enum_values<charm_t>()) {
		registerMagicEnum(L, value);
	}
	// CylinderFalgs enum
	for (auto value : magic_enum::enum_values<CylinderFlags_t>()) {
		registerMagicEnum(L, value);
	}
	// AccessList enum
	// Use with house:getAccessList, house:setAccessList
	for (auto value : magic_enum::enum_values<AccessList_t>()) {
		registerMagicEnum(L, value);
	}
	// LightState enum
	for (auto value : magic_enum::enum_values<LightState_t>()) {
		registerMagicEnum(L, value);
	}
	// Combat enum
	for (auto value : magic_enum::enum_values<CombatOrigin>()) {
		registerMagicEnum(L, value);
	}
	// PlayerSex enum
	for (auto value : magic_enum::enum_values<PlayerSex_t>()) {
		registerMagicEnum(L, value);
	}
	// RespawnPeriod enum
	for (auto value : magic_enum::enum_values<RespawnPeriod_t>()) {
		registerMagicEnum(L, value);
	}
	// SlotPosition enum
	for (auto value : magic_enum::enum_values<SlotPositionBits>()) {
		registerMagicEnum(L, value);
	}
	// SpellType enum
	for (auto value : magic_enum::enum_values<SpellType_t>()) {
		registerMagicEnum(L, value);
	}
	// Vocation enum
	for (auto value : magic_enum::enum_values<Vocation_t>()) {
		registerMagicEnum(L, value);
	}
	// ZoneType enum
	for (auto value : magic_enum::enum_values<ZoneType_t>()) {
		registerMagicEnum(L, value);
	}
	// Weapon enum
	for (auto value : magic_enum::enum_values<WeaponType_t>()) {
		registerMagicEnum(L, value);
	}

	// Constants
	registerEnum(L, STORAGEVALUE_EMOTE);
	registerEnum(L, MAX_LOOTCHANCE);
}

void LuaEnums::initAccountEnums(lua_State* L) {
	for (auto value : magic_enum::enum_values<account::AccountType>()) {
		registerMagicEnum(L, value);
	}
	for (auto value : magic_enum::enum_values<account::GroupType>()) {
		registerMagicEnum(L, value);
	}
	for (auto value : magic_enum::enum_values<account::Errors>()) {
		registerMagicEnum(L, value);
	}
	for (auto value : magic_enum::enum_values<account::CoinTransactionType>()) {
		registerMagicEnum(L, value);
	}
}

void LuaEnums::initDailyRewardEnums(lua_State* L) {
	for (auto value : magic_enum::enum_values<DailyRewardStatus>()) {
		registerMagicEnum(L, value);
	}
}

void LuaEnums::initBugCategoryEnums(lua_State* L) {
	for (auto value : magic_enum::enum_values<BugReportType_t>()) {
		registerMagicEnum(L, value);
	}
}

void LuaEnums::initReportTypeEnums(lua_State* L) {
	for (auto value : magic_enum::enum_values<RuleViolationType_t>()) {
		registerMagicEnum(L, value);
	}
}

void LuaEnums::initCallbackParamEnums(lua_State* L) {
	for (auto value : magic_enum::enum_values<CallBackParam_t>()) {
		registerMagicEnum(L, value);
	}
}

void LuaEnums::initCombatEnums(lua_State* L) {
	for (auto value : magic_enum::enum_values<CombatType_t>()) {
		registerMagicEnum(L, value);
	}
}

void LuaEnums::initCombatParamEnums(lua_State* L) {
	for (auto value : magic_enum::enum_values<CombatParam_t>()) {
		registerMagicEnum(L, value);
	}
}

void LuaEnums::initCombatFormulaEnums(lua_State* L) {
	for (auto value : magic_enum::enum_values<formulaType_t>()) {
		registerMagicEnum(L, value);
	}
}

void LuaEnums::initDirectionEnums(lua_State* L) {
	for (auto value : magic_enum::enum_values<Direction>()) {
		registerMagicEnum(L, value);
	}
}

void LuaEnums::initFactionEnums(lua_State* L) {
	for (auto value : magic_enum::enum_values<Faction_t>()) {
		registerMagicEnum(L, value);
	}
}

void LuaEnums::initConditionEnums(lua_State* L) {
	for (auto value : magic_enum::enum_values<ConditionType_t>()) {
		registerMagicEnum(L, value);
	}
}

void LuaEnums::initConditionIdEnums(lua_State* L) {
	for (auto value : magic_enum::enum_values<ConditionId_t>()) {
		registerMagicEnum(L, value);
	}
}

void LuaEnums::initConditionParamEnums(lua_State* L) {
	for (auto value : magic_enum::enum_values<ConditionParam_t>()) {
		registerMagicEnum(L, value);
	}
}

void LuaEnums::initConstMeEnums(lua_State* L) {
	for (auto value : magic_enum::enum_values<MagicEffectClasses>()) {
		registerMagicEnum(L, value);
	}
}

void LuaEnums::initConstAniEnums(lua_State* L) {
	for (auto value : magic_enum::enum_values<ShootType_t>()) {
		registerMagicEnum(L, value);
	}
}

void LuaEnums::initConstPropEnums(lua_State* L) {
	for (auto value : magic_enum::enum_values<ItemProperty>()) {
		registerMagicEnum(L, value);
	}
}

void LuaEnums::initConstSlotEnums(lua_State* L) {
	for (auto value : magic_enum::enum_values<Slots_t>()) {
		registerMagicEnum(L, value);
	}
}

void LuaEnums::initCreatureEventEnums(lua_State* L) {
	for (auto value : magic_enum::enum_values<CreatureEventType_t>()) {
		registerMagicEnum(L, value);
	}
}

void LuaEnums::initGameStateEnums(lua_State* L) {
	for (auto value : magic_enum::enum_values<GameState_t>()) {
		registerMagicEnum(L, value);
	}
}

void LuaEnums::initMessageEnums(lua_State* L) {
	for (auto value : magic_enum::enum_values<MessageClasses>()) {
		registerMagicEnum(L, value);
	}
}

void LuaEnums::initCreatureTypeEnums(lua_State* L) {
	for (auto value : magic_enum::enum_values<CreatureType_t>()) {
		registerMagicEnum(L, value);
	}
}

void LuaEnums::initClientOsEnums(lua_State* L) {
	for (auto value : magic_enum::enum_values<OperatingSystem_t>()) {
		registerMagicEnum(L, value);
	}
}

void LuaEnums::initFightModeEnums(lua_State* L) {
	for (auto value : magic_enum::enum_values<FightMode_t>()) {
		registerMagicEnum(L, value);
	}
}

void LuaEnums::initItemAttributeEnums(lua_State* L) {
	for (auto value : magic_enum::enum_values<ItemAttrTypes>()) {
		registerMagicEnum(L, value);
	}
}

void LuaEnums::initItemTypeEnums(lua_State* L) {
	for (auto value : magic_enum::enum_values<ItemTypes_t>()) {
		registerMagicEnum(L, value);
	}
}

void LuaEnums::initItemIdEnums(lua_State* L) {
	for (auto value : magic_enum::enum_values<item_t>()) {
		registerMagicEnum(L, value);
	}
}

void LuaEnums::initPlayerFlagEnums(lua_State* L) {
	for (auto value : magic_enum::enum_values<PlayerFlags_t>()) {
		registerMagicEnum(L, value);
	}
}

void LuaEnums::initReportReasonEnums(lua_State* L) {
	for (auto value : magic_enum::enum_values<RuleViolationReasons_t>()) {
		registerMagicEnum(L, value);
	}
}

void LuaEnums::initSkillEnums(lua_State* L) {
	for (auto value : magic_enum::enum_values<skills_t>()) {
		registerMagicEnum(L, value);
	}
}

void LuaEnums::initSkullEnums(lua_State* L) {
	for (auto value : magic_enum::enum_values<Skulls_t>()) {
		registerMagicEnum(L, value);
	}
}

void LuaEnums::initTalkTypeEnums(lua_State* L) {
	for (auto value : magic_enum::enum_values<SpeakClasses>()) {
		registerMagicEnum(L, value);
	}
}

void LuaEnums::initBestiaryEnums(lua_State* L) {
	for (auto value : magic_enum::enum_values<BestiaryType_t>()) {
		registerMagicEnum(L, value);
	}
}

void LuaEnums::initTextColorEnums(lua_State* L) {
	for (auto value : magic_enum::enum_values<TextColor_t>()) {
		registerMagicEnum(L, value);
	}
}

void LuaEnums::initTileStateEnums(lua_State* L) {
	for (auto value : magic_enum::enum_values<TileFlags_t>()) {
		registerMagicEnum(L, value);
	}
}

// Use with npc:setSpeechBubble
void LuaEnums::initSpeechBubbleEnums(lua_State* L) {
	for (auto value : magic_enum::enum_values<SpeechBubble_t>()) {
		registerMagicEnum(L, value);
	}
}

// Use with player:addMapMark
void LuaEnums::initMapMarkEnums(lua_State* L) {
	for (auto value : magic_enum::enum_values<MapMark_t>()) {
		registerMagicEnum(L, value);
	}
}

// Use with Game.getReturnMessage
void LuaEnums::initReturnValueEnums(lua_State* L) {
	for (auto value : magic_enum::enum_values<ReturnValue>()) {
		registerMagicEnum(L, value);
	}
}

// Reload
void LuaEnums::initReloadTypeEnums(lua_State* L) {
	for (auto value : magic_enum::enum_values<Reload_t>()) {
		registerMagicEnum(L, value);
	}
}

void LuaEnums::initCreaturesEventEnums(lua_State* L) {
	// Monsters
	for (auto value : magic_enum::enum_values<MonstersEvent_t>()) {
		registerMagicEnum(L, value);
	}
	// Npcs
	for (auto value : magic_enum::enum_values<NpcsEvent_t>()) {
		registerMagicEnum(L, value);
	}
}

void LuaEnums::initForgeEnums(lua_State* L) {
	for (auto value : magic_enum::enum_values<ForgeClassifications_t>()) {
		registerMagicEnum(L, value);
	}
}

// Webhook default colors
void LuaEnums::initWebhookEnums(lua_State* L) {
	// Webhook cannot be registered by magic enum because it is hexadecimal
	registerEnum(L, WEBHOOK_COLOR_ONLINE);
	registerEnum(L, WEBHOOK_COLOR_OFFLINE);
	registerEnum(L, WEBHOOK_COLOR_WARNING);
	registerEnum(L, WEBHOOK_COLOR_RAID);
}
