/**
 * Canary - A free and open-source MMORPG server emulator
 * Copyright (©) 2019-2022 OpenTibiaBR <opentibiabr@outlook.com>
 * Repository: https://github.com/opentibiabr/canary
 * License: https://github.com/opentibiabr/canary/blob/main/LICENSE
 * Contributors: https://github.com/opentibiabr/canary/graphs/contributors
 * Website: https://docs.opentibiabr.com/
 */

#include "pch.hpp"

#include "creatures/monsters/monsters.h"
#include "lua/functions/creatures/monster/loot_functions.hpp"

int LootFunctions::luaCreateLoot(lua_State* L) {
	// Loot() will create a new loot item
	Loot* loot = new Loot();
	if (loot) {
		pushUserdata<Loot>(L, loot);
		setMetatable(L, -1, "Loot");
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int LootFunctions::luaDeleteLoot(lua_State* L) {
	// loot:delete() loot:__gc()
	Loot** lootPtr = getRawUserdata<Loot>(L, 1);
	if (lootPtr && *lootPtr) {
		delete *lootPtr;
		*lootPtr = nullptr;
	}
	return 0;
}

int LootFunctions::luaLootSetId(lua_State* L) {
	// loot:setId(id)
	Loot* loot = getUserdata<Loot>(L, 1);
	if (loot) {
		if (isNumber(L, 2)) {
			loot->lootBlock.id = getNumber<uint16_t>(L, 2);
			pushBoolean(L, true);
		} else {
			g_logger().warn("[LootFunctions::luaLootSetId] - "
							"Unknown loot item loot, int value expected");
			lua_pushnil(L);
		}
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int LootFunctions::luaLootSetIdFromName(lua_State* L) {
	// loot:setIdFromName(name)
	Loot* loot = getUserdata<Loot>(L, 1);
	if (loot && isString(L, 2)) {
		auto name = getString(L, 2);
		auto ids = Item::items.nameToItems.equal_range(asLowerCaseString(name));

		if (ids.first == Item::items.nameToItems.cend()) {
			g_logger().warn("[LootFunctions::luaLootSetIdFromName] - "
							"Unknown loot item {}",
							name);
			lua_pushnil(L);
			return 1;
		}

		if (std::next(ids.first) != ids.second) {
			g_logger().warn("[LootFunctions::luaLootSetIdFromName] - "
							"Non-unique loot item {}",
							name);
			lua_pushnil(L);
			return 1;
		}

		loot->lootBlock.id = ids.first->second;
		pushBoolean(L, true);
	} else {
		g_logger().warn("[LootFunctions::luaLootSetIdFromName] - "
						"Unknown loot item loot, string value expected");
		lua_pushnil(L);
	}
	return 1;
}

int LootFunctions::luaLootSetSubType(lua_State* L) {
	// loot:setSubType(type)
	Loot* loot = getUserdata<Loot>(L, 1);
	if (loot) {
		loot->lootBlock.subType = getNumber<uint16_t>(L, 2);
		pushBoolean(L, true);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int LootFunctions::luaLootSetChance(lua_State* L) {
	// loot:setChance(chance)
	Loot* loot = getUserdata<Loot>(L, 1);
	if (loot) {
		loot->lootBlock.chance = getNumber<uint32_t>(L, 2);
		pushBoolean(L, true);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int LootFunctions::luaLootSetMinCount(lua_State* L) {
	// loot:setMinCount(min)
	Loot* loot = getUserdata<Loot>(L, 1);
	if (loot) {
		loot->lootBlock.countmin = getNumber<uint32_t>(L, 2);
		pushBoolean(L, true);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int LootFunctions::luaLootSetMaxCount(lua_State* L) {
	// loot:setMaxCount(max)
	Loot* loot = getUserdata<Loot>(L, 1);
	if (loot) {
		loot->lootBlock.countmax = getNumber<uint32_t>(L, 2);
		pushBoolean(L, true);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int LootFunctions::luaLootSetActionId(lua_State* L) {
	// loot:setActionId(actionid)
	Loot* loot = getUserdata<Loot>(L, 1);
	if (loot) {
		loot->lootBlock.actionId = getNumber<uint32_t>(L, 2);
		pushBoolean(L, true);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int LootFunctions::luaLootSetText(lua_State* L) {
	// loot:setText(text)
	Loot* loot = getUserdata<Loot>(L, 1);
	if (loot) {
		loot->lootBlock.text = getString(L, 2);
		pushBoolean(L, true);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int LootFunctions::luaLootSetNameItem(lua_State* L) {
	// loot:setNameItem(name)
	Loot* loot = getUserdata<Loot>(L, 1);
	if (loot) {
		loot->lootBlock.name = getString(L, 2);
		pushBoolean(L, true);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int LootFunctions::luaLootSetArticle(lua_State* L) {
	// loot:setArticle(article)
	Loot* loot = getUserdata<Loot>(L, 1);
	if (loot) {
		loot->lootBlock.article = getString(L, 2);
		pushBoolean(L, true);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int LootFunctions::luaLootSetAttack(lua_State* L) {
	// loot:setAttack(attack)
	Loot* loot = getUserdata<Loot>(L, 1);
	if (loot) {
		loot->lootBlock.attack = getNumber<uint32_t>(L, 2);
		pushBoolean(L, true);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int LootFunctions::luaLootSetDefense(lua_State* L) {
	// loot:setDefense(defense)
	Loot* loot = getUserdata<Loot>(L, 1);
	if (loot) {
		loot->lootBlock.defense = getNumber<uint32_t>(L, 2);
		pushBoolean(L, true);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int LootFunctions::luaLootSetExtraDefense(lua_State* L) {
	// loot:setExtraDefense(defense)
	Loot* loot = getUserdata<Loot>(L, 1);
	if (loot) {
		loot->lootBlock.extraDefense = getNumber<uint32_t>(L, 2);
		pushBoolean(L, true);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int LootFunctions::luaLootSetArmor(lua_State* L) {
	// loot:setArmor(armor)
	Loot* loot = getUserdata<Loot>(L, 1);
	if (loot) {
		loot->lootBlock.armor = getNumber<uint32_t>(L, 2);
		pushBoolean(L, true);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int LootFunctions::luaLootSetShootRange(lua_State* L) {
	// loot:setShootRange(range)
	Loot* loot = getUserdata<Loot>(L, 1);
	if (loot) {
		loot->lootBlock.shootRange = getNumber<uint32_t>(L, 2);
		pushBoolean(L, true);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int LootFunctions::luaLootSetHitChance(lua_State* L) {
	// loot:setHitChance(chance)
	Loot* loot = getUserdata<Loot>(L, 1);
	if (loot) {
		loot->lootBlock.hitChance = getNumber<uint32_t>(L, 2);
		pushBoolean(L, true);
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int LootFunctions::luaLootSetUnique(lua_State* L) {
	// loot:setUnique(bool)
	Loot* loot = getUserdata<Loot>(L, 1);
	if (loot) {
		if (lua_gettop(L) == 1) {
			pushBoolean(L, loot->lootBlock.unique);
		} else {
			loot->lootBlock.unique = getBoolean(L, 2);
			pushBoolean(L, true);
		}
	} else {
		lua_pushnil(L);
	}
	return 1;
}

int LootFunctions::luaLootAddChildLoot(lua_State* L) {
	// loot:addChildLoot(loot)
	Loot* loot = getUserdata<Loot>(L, 1);
	if (loot) {
		loot->lootBlock.childLoot.push_back(getUserdata<Loot>(L, 2)->lootBlock);
	} else {
		lua_pushnil(L);
	}
	return 1;
}
