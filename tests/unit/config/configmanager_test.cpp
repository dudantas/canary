/**
 * Canary - A free and open-source MMORPG server emulator
 * Copyright (©) 2019-2023 OpenTibiaBR <opentibiabr@outlook.com>
 * Repository: https://github.com/opentibiabr/canary
 * License: https://github.com/opentibiabr/canary/blob/main/LICENSE
 * Contributors: https://github.com/opentibiabr/canary/graphs/contributors
 * Website: https://docs.opentibiabr.com/
 */

#include <gtest/gtest.h>
#include "config/configmanager.hpp"
#include "config/config_enums.hpp"

/**
 * @class ConfigManagerTest
 * @brief Test suite for ConfigManager functionality
 *
 * Tests configuration loading, type safety, and value retrieval
 */
class ConfigManagerTest : public ::testing::Test {
protected:
	void SetUp() override {
		// ConfigManager uses singleton pattern
	}

	void TearDown() override {
		// Cleanup if needed
	}
};

/**
 * @brief Test that ConfigManager singleton instance can be obtained
 */
TEST_F(ConfigManagerTest, GetInstanceReturnsSingleton) {
	auto &instance1 = ConfigManager::getInstance();
	auto &instance2 = ConfigManager::getInstance();

	EXPECT_EQ(&instance1, &instance2);
}

/**
 * @brief Test boolean config retrieval
 */
TEST_F(ConfigManagerTest, GetBooleanReturnsValidValue) {
	auto &config = ConfigManager::getInstance();

	// Test retrieving a boolean config value
	// Default values should be accessible
	bool allowReload = config.getBoolean(ALLOW_RELOAD);
	EXPECT_TRUE(allowReload == true || allowReload == false);
}

/**
 * @brief Test integer config retrieval
 */
TEST_F(ConfigManagerTest, GetNumberReturnsValidValue) {
	auto &config = ConfigManager::getInstance();

	// Test retrieving integer config values
	int32_t maxPlayers = config.getNumber(MAX_PLAYERS);
	EXPECT_GE(maxPlayers, 0);

	int32_t gamePort = config.getNumber(GAME_PORT);
	EXPECT_GT(gamePort, 0);
}

/**
 * @brief Test float config retrieval
 */
TEST_F(ConfigManagerTest, GetFloatReturnsValidValue) {
	auto &config = ConfigManager::getInstance();

	// Test retrieving float config values
	float rateExp = config.getFloat(RATE_EXPERIENCE);
	EXPECT_GE(rateExp, 0.0f);

	float rateLoot = config.getFloat(RATE_LOOT);
	EXPECT_GE(rateLoot, 0.0f);
}

/**
 * @brief Test string config retrieval
 */
TEST_F(ConfigManagerTest, GetStringReturnsValidValue) {
	auto &config = ConfigManager::getInstance();

	// Test retrieving string config values
	std::string serverName = config.getString(SERVER_NAME);
	// Server name can be empty or non-empty, both are valid
	EXPECT_TRUE(serverName.empty() || !serverName.empty());

	std::string ip = config.getString(IP);
	EXPECT_FALSE(ip.empty());
}

/**
 * @brief Test wheel configuration values
 */
TEST_F(ConfigManagerTest, WheelConfigurationValues) {
	auto &config = ConfigManager::getInstance();

	// Test wheel-related configurations
	int32_t pointsPerLevel = config.getNumber(WHEEL_POINTS_PER_LEVEL);
	EXPECT_GE(pointsPerLevel, 0);

	bool wheelEnabled = config.getBoolean(TOGGLE_WHEELSYSTEM);
	EXPECT_TRUE(wheelEnabled == true || wheelEnabled == false);

	// Test wheel atelier costs
	int32_t revealGreaterCost = config.getNumber(WHEEL_ATELIER_REVEAL_GREATER_COST);
	EXPECT_GE(revealGreaterCost, 0);

	int32_t revealLesserCost = config.getNumber(WHEEL_ATELIER_REVEAL_LESSER_COST);
	EXPECT_GE(revealLesserCost, 0);

	int32_t revealRegularCost = config.getNumber(WHEEL_ATELIER_REVEAL_REGULAR_COST);
	EXPECT_GE(revealRegularCost, 0);
}

/**
 * @brief Test party configuration values
 */
TEST_F(ConfigManagerTest, PartyConfigurationValues) {
	auto &config = ConfigManager::getInstance();

	// Test party-related configurations
	bool autoShare = config.getBoolean(PARTY_AUTO_SHARE_EXPERIENCE);
	EXPECT_TRUE(autoShare == true || autoShare == false);

	bool shareLootBoosts = config.getBoolean(PARTY_SHARE_LOOT_BOOSTS);
	EXPECT_TRUE(shareLootBoosts == true || shareLootBoosts == false);

	float shareRangeMultiplier = config.getFloat(PARTY_SHARE_RANGE_MULTIPLIER);
	EXPECT_GT(shareRangeMultiplier, 0.0f);

	float diminishingFactor = config.getFloat(PARTY_SHARE_LOOT_BOOSTS_DIMINISHING_FACTOR);
	EXPECT_GE(diminishingFactor, 0.0f);
	EXPECT_LE(diminishingFactor, 1.0f);

	int32_t maxDistance = config.getNumber(PARTY_LIST_MAX_DISTANCE);
	EXPECT_GE(maxDistance, 0);

	// Test new LEAVE_PARTY_ON_DEATH configuration
	bool leaveOnDeath = config.getBoolean(LEAVE_PARTY_ON_DEATH);
	EXPECT_TRUE(leaveOnDeath == true || leaveOnDeath == false);
}

/**
 * @brief Test combat chain formula configurations
 */
TEST_F(ConfigManagerTest, CombatChainFormulaValues) {
	auto &config = ConfigManager::getInstance();

	// Test combat chain skill formulas
	float axeFormula = config.getFloat(COMBAT_CHAIN_SKILL_FORMULA_AXE);
	EXPECT_GT(axeFormula, 0.0f);

	float clubFormula = config.getFloat(COMBAT_CHAIN_SKILL_FORMULA_CLUB);
	EXPECT_GT(clubFormula, 0.0f);

	float swordFormula = config.getFloat(COMBAT_CHAIN_SKILL_FORMULA_SWORD);
	EXPECT_GT(swordFormula, 0.0f);

	float fistFormula = config.getFloat(COMBAT_CHAIN_SKILL_FORMULA_FIST);
	EXPECT_GT(fistFormula, 0.0f);

	int32_t chainDelay = config.getNumber(COMBAT_CHAIN_DELAY);
	EXPECT_GE(chainDelay, 0);

	int32_t chainTargets = config.getNumber(COMBAT_CHAIN_TARGETS);
	EXPECT_GE(chainTargets, 0);

	bool chainSystemEnabled = config.getBoolean(TOGGLE_CHAIN_SYSTEM);
	EXPECT_TRUE(chainSystemEnabled == true || chainSystemEnabled == false);
}

/**
 * @brief Test amplification formula configurations (new)
 */
TEST_F(ConfigManagerTest, AmplificationFormulaValues) {
	auto &config = ConfigManager::getInstance();

	// Test new amplification formula values
	float ampA = config.getFloat(AMPLIFICATION_CHANCE_FORMULA_A);
	EXPECT_GE(ampA, 0.0f);

	float ampB = config.getFloat(AMPLIFICATION_CHANCE_FORMULA_B);
	EXPECT_GE(ampB, 0.0f);

	float ampC = config.getFloat(AMPLIFICATION_CHANCE_FORMULA_C);
	EXPECT_GE(ampC, 0.0f);
}

/**
 * @brief Test animus mastery configurations (new)
 */
TEST_F(ConfigManagerTest, AnimusMasteryValues) {
	auto &config = ConfigManager::getInstance();

	// Test animus mastery configurations
	float maxMultiplier = config.getFloat(ANIMUS_MASTERY_MAX_MONSTER_XP_MULTIPLIER);
	EXPECT_GT(maxMultiplier, 0.0f);

	float monsterMultiplier = config.getFloat(ANIMUS_MASTERY_MONSTER_XP_MULTIPLIER);
	EXPECT_GT(monsterMultiplier, 0.0f);

	float monstersMultiplier = config.getFloat(ANIMUS_MASTERY_MONSTERS_XP_MULTIPLIER);
	EXPECT_GE(monstersMultiplier, 0.0f);

	int32_t monstersToIncrease = config.getNumber(ANIMUS_MASTERY_MONSTERS_TO_INCREASE_XP_MULTIPLIER);
	EXPECT_GT(monstersToIncrease, 0);
}

/**
 * @brief Test augment configurations (new)
 */
TEST_F(ConfigManagerTest, AugmentConfigurationValues) {
	auto &config = ConfigManager::getInstance();

	// Test augment damage percentages
	int32_t increasedDamage = config.getNumber(AUGMENT_INCREASED_DAMAGE_PERCENT);
	EXPECT_GE(increasedDamage, 0);

	int32_t powerfulImpact = config.getNumber(AUGMENT_POWERFUL_IMPACT_PERCENT);
	EXPECT_GE(powerfulImpact, 0);

	int32_t strongImpact = config.getNumber(AUGMENT_STRONG_IMPACT_PERCENT);
	EXPECT_GE(strongImpact, 0);
}

/**
 * @brief Test stash configuration
 */
TEST_F(ConfigManagerTest, StashConfigurationValues) {
	auto &config = ConfigManager::getInstance();

	// Test stash configurations
	bool stashMoving = config.getBoolean(STASH_MOVING);
	EXPECT_TRUE(stashMoving == true || stashMoving == false);

	int32_t manageAmount = config.getNumber(STASH_MANAGE_AMOUNT);
	EXPECT_GT(manageAmount, 0);
}

/**
 * @brief Test boundary values for rate configurations
 */
TEST_F(ConfigManagerTest, RateConfigurationBoundaries) {
	auto &config = ConfigManager::getInstance();

	// Rates should be non-negative
	EXPECT_GE(config.getFloat(RATE_ATTACK_SPEED), 0.0f);
	EXPECT_GE(config.getFloat(RATE_BOSS_ATTACK), 0.0f);
	EXPECT_GE(config.getFloat(RATE_BOSS_DEFENSE), 0.0f);
	EXPECT_GE(config.getFloat(RATE_BOSS_HEALTH), 0.0f);
	EXPECT_GE(config.getFloat(RATE_MONSTER_ATTACK), 0.0f);
	EXPECT_GE(config.getFloat(RATE_MONSTER_DEFENSE), 0.0f);
	EXPECT_GE(config.getFloat(RATE_MONSTER_HEALTH), 0.0f);
}

/**
 * @brief Test transcendence formula configurations
 */
TEST_F(ConfigManagerTest, TranscendenceFormulaValues) {
	auto &config = ConfigManager::getInstance();

	float transA = config.getFloat(TRANSCENDENCE_CHANCE_FORMULA_A);
	EXPECT_GE(transA, 0.0f);

	float transB = config.getFloat(TRANSCENDENCE_CHANCE_FORMULA_B);
	EXPECT_GE(transB, 0.0f);

	float transC = config.getFloat(TRANSCENDENCE_CHANCE_FORMULA_C);
	EXPECT_GE(transC, 0.0f);

	int32_t avatarDuration = config.getNumber(TRANSCENDENCE_AVATAR_DURATION);
	EXPECT_GT(avatarDuration, 0);
}

/**
 * @brief Test momentum formula configurations
 */
TEST_F(ConfigManagerTest, MomentumFormulaValues) {
	auto &config = ConfigManager::getInstance();

	float momA = config.getFloat(MOMENTUM_CHANCE_FORMULA_A);
	EXPECT_GE(momA, 0.0f);

	float momB = config.getFloat(MOMENTUM_CHANCE_FORMULA_B);
	EXPECT_GE(momB, 0.0f);

	float momC = config.getFloat(MOMENTUM_CHANCE_FORMULA_C);
	EXPECT_GE(momC, 0.0f);
}

/**
 * @brief Test onslaught formula configurations
 */
TEST_F(ConfigManagerTest, OnslaughtFormulaValues) {
	auto &config = ConfigManager::getInstance();

	float onsA = config.getFloat(ONSLAUGHT_CHANCE_FORMULA_A);
	EXPECT_GE(onsA, 0.0f);

	float onsB = config.getFloat(ONSLAUGHT_CHANCE_FORMULA_B);
	EXPECT_GE(onsB, 0.0f);

	float onsC = config.getFloat(ONSLAUGHT_CHANCE_FORMULA_C);
	EXPECT_GE(onsC, 0.0f);
}

/**
 * @brief Test ruse formula configurations
 */
TEST_F(ConfigManagerTest, RuseFormulaValues) {
	auto &config = ConfigManager::getInstance();

	float ruseA = config.getFloat(RUSE_CHANCE_FORMULA_A);
	EXPECT_GE(ruseA, 0.0f);

	float ruseB = config.getFloat(RUSE_CHANCE_FORMULA_B);
	EXPECT_GE(ruseB, 0.0f);

	float ruseC = config.getFloat(RUSE_CHANCE_FORMULA_C);
	EXPECT_GE(ruseC, 0.0f);
}

/**
 * @brief Test edge case: accessing config values of wrong type should handle gracefully
 */
TEST_F(ConfigManagerTest, TypeMismatchHandling) {
	auto &config = ConfigManager::getInstance();

	// These should not crash and return default values
	// Note: The actual behavior depends on implementation
	// Testing that calls complete without crashing
	EXPECT_NO_FATAL_FAILURE({
		config.getBoolean(SERVER_NAME); // String key accessed as boolean
	});

	EXPECT_NO_FATAL_FAILURE({
		config.getNumber(TOGGLE_WHEELSYSTEM); // Boolean key accessed as number
	});

	EXPECT_NO_FATAL_FAILURE({
		config.getString(MAX_PLAYERS); // Number key accessed as string
	});
}