/**
 * Canary - A free and open-source MMORPG server emulator
 * Copyright (©) 2019-2023 OpenTibiaBR <opentibiabr@outlook.com>
 * Repository: https://github.com/opentibiabr/canary
 * License: https://github.com/opentibiabr/canary/blob/main/LICENSE
 * Contributors: https://github.com/opentibiabr/canary/graphs/contributors
 * Website: https://docs.opentibiabr.com/
 */

#include <gtest/gtest.h>
#include "creatures/combat/combat.hpp"

/**
 * @class CombatTest
 * @brief Test suite for Combat system functionality
 *
 * Tests damage calculations, type conversions, and combat mechanics
 */
class CombatTest : public ::testing::Test {
protected:
	void SetUp() override {
	}

	void TearDown() override {
	}
};

/**
 * @brief Test ConditionType to DamageType conversion
 */
TEST_F(CombatTest, ConditionToDamageTypeConversion) {
	EXPECT_EQ(COMBAT_FIREDAMAGE, Combat::ConditionToDamageType(CONDITION_FIRE));
	EXPECT_EQ(COMBAT_ENERGYDAMAGE, Combat::ConditionToDamageType(CONDITION_ENERGY));
	EXPECT_EQ(COMBAT_PHYSICALDAMAGE, Combat::ConditionToDamageType(CONDITION_BLEEDING));
	EXPECT_EQ(COMBAT_DROWNDAMAGE, Combat::ConditionToDamageType(CONDITION_DROWN));
	EXPECT_EQ(COMBAT_EARTHDAMAGE, Combat::ConditionToDamageType(CONDITION_POISON));
	EXPECT_EQ(COMBAT_ICEDAMAGE, Combat::ConditionToDamageType(CONDITION_FREEZING));
	EXPECT_EQ(COMBAT_HOLYDAMAGE, Combat::ConditionToDamageType(CONDITION_DAZZLED));
	EXPECT_EQ(COMBAT_DEATHDAMAGE, Combat::ConditionToDamageType(CONDITION_CURSED));
}

/**
 * @brief Test ConditionType to DamageType conversion returns COMBAT_NONE for invalid types
 */
TEST_F(CombatTest, ConditionToDamageTypeInvalid) {
	EXPECT_EQ(COMBAT_NONE, Combat::ConditionToDamageType(CONDITION_NONE));
	EXPECT_EQ(COMBAT_NONE, Combat::ConditionToDamageType(CONDITION_HASTE));
	EXPECT_EQ(COMBAT_NONE, Combat::ConditionToDamageType(CONDITION_PARALYZE));
}

/**
 * @brief Test DamageType to ConditionType conversion
 */
TEST_F(CombatTest, DamageToConditionTypeConversion) {
	EXPECT_EQ(CONDITION_FIRE, Combat::DamageToConditionType(COMBAT_FIREDAMAGE));
	EXPECT_EQ(CONDITION_ENERGY, Combat::DamageToConditionType(COMBAT_ENERGYDAMAGE));
	EXPECT_EQ(CONDITION_DROWN, Combat::DamageToConditionType(COMBAT_DROWNDAMAGE));
	EXPECT_EQ(CONDITION_POISON, Combat::DamageToConditionType(COMBAT_EARTHDAMAGE));
	EXPECT_EQ(CONDITION_FREEZING, Combat::DamageToConditionType(COMBAT_ICEDAMAGE));
	EXPECT_EQ(CONDITION_DAZZLED, Combat::DamageToConditionType(COMBAT_HOLYDAMAGE));
	EXPECT_EQ(CONDITION_CURSED, Combat::DamageToConditionType(COMBAT_DEATHDAMAGE));
	EXPECT_EQ(CONDITION_BLEEDING, Combat::DamageToConditionType(COMBAT_PHYSICALDAMAGE));
}

/**
 * @brief Test DamageType to ConditionType conversion returns CONDITION_NONE for invalid types
 */
TEST_F(CombatTest, DamageToConditionTypeInvalid) {
	EXPECT_EQ(CONDITION_NONE, Combat::DamageToConditionType(COMBAT_NONE));
	EXPECT_EQ(CONDITION_NONE, Combat::DamageToConditionType(COMBAT_HEALING));
	EXPECT_EQ(CONDITION_NONE, Combat::DamageToConditionType(COMBAT_UNDEFINEDDAMAGE));
}

/**
 * @brief Test bidirectional conversion consistency
 */
TEST_F(CombatTest, BidirectionalConversionConsistency) {
	// Fire
	auto fireCondition = Combat::DamageToConditionType(COMBAT_FIREDAMAGE);
	EXPECT_EQ(COMBAT_FIREDAMAGE, Combat::ConditionToDamageType(fireCondition));

	// Energy
	auto energyCondition = Combat::DamageToConditionType(COMBAT_ENERGYDAMAGE);
	EXPECT_EQ(COMBAT_ENERGYDAMAGE, Combat::ConditionToDamageType(energyCondition));

	// Physical/Bleeding
	auto physicalCondition = Combat::DamageToConditionType(COMBAT_PHYSICALDAMAGE);
	EXPECT_EQ(COMBAT_PHYSICALDAMAGE, Combat::ConditionToDamageType(physicalCondition));

	// Ice
	auto iceCondition = Combat::DamageToConditionType(COMBAT_ICEDAMAGE);
	EXPECT_EQ(COMBAT_ICEDAMAGE, Combat::ConditionToDamageType(iceCondition));

	// Holy
	auto holyCondition = Combat::DamageToConditionType(COMBAT_HOLYDAMAGE);
	EXPECT_EQ(COMBAT_HOLYDAMAGE, Combat::ConditionToDamageType(holyCondition));

	// Death
	auto deathCondition = Combat::DamageToConditionType(COMBAT_DEATHDAMAGE);
	EXPECT_EQ(COMBAT_DEATHDAMAGE, Combat::ConditionToDamageType(deathCondition));
}

/**
 * @brief Test MatrixArea construction with valid dimensions
 */
TEST_F(CombatTest, MatrixAreaConstruction) {
	MatrixArea area(3, 3);
	EXPECT_EQ(3u, area.getRows());
	EXPECT_EQ(3u, area.getCols());
}

/**
 * @brief Test MatrixArea construction with different dimensions
 */
TEST_F(CombatTest, MatrixAreaConstructionVariousSizes) {
	MatrixArea area1(1, 1);
	EXPECT_EQ(1u, area1.getRows());
	EXPECT_EQ(1u, area1.getCols());

	MatrixArea area2(5, 7);
	EXPECT_EQ(5u, area2.getRows());
	EXPECT_EQ(7u, area2.getCols());

	MatrixArea area3(10, 10);
	EXPECT_EQ(10u, area3.getRows());
	EXPECT_EQ(10u, area3.getCols());
}

/**
 * @brief Test MatrixArea value setting and getting
 */
TEST_F(CombatTest, MatrixAreaValueOperations) {
	MatrixArea area(3, 3);

	// Set values
	area.setValue(0, 0, true);
	area.setValue(1, 1, true);
	area.setValue(2, 2, false);

	// Get values
	EXPECT_TRUE(area.getValue(0, 0));
	EXPECT_TRUE(area.getValue(1, 1));
	EXPECT_FALSE(area.getValue(2, 2));
}

/**
 * @brief Test MatrixArea center position
 */
TEST_F(CombatTest, MatrixAreaCenterPosition) {
	MatrixArea area(5, 5);

	// Set center
	area.setCenter(2, 2);

	// Get center
	uint32_t centerY, centerX;
	area.getCenter(centerY, centerX);

	EXPECT_EQ(2u, centerY);
	EXPECT_EQ(2u, centerX);
}

/**
 * @brief Test MatrixArea copy construction
 */
TEST_F(CombatTest, MatrixAreaCopyConstruction) {
	MatrixArea original(3, 3);
	original.setValue(0, 0, true);
	original.setValue(1, 1, true);
	original.setCenter(1, 1);

	MatrixArea copy(original);

	EXPECT_EQ(original.getRows(), copy.getRows());
	EXPECT_EQ(original.getCols(), copy.getCols());
	EXPECT_TRUE(copy.getValue(0, 0));
	EXPECT_TRUE(copy.getValue(1, 1));

	uint32_t origY, origX, copyY, copyX;
	original.getCenter(origY, origX);
	copy.getCenter(copyY, copyX);

	EXPECT_EQ(origY, copyY);
	EXPECT_EQ(origX, copyX);
}

/**
 * @brief Test MatrixArea clone
 */
TEST_F(CombatTest, MatrixAreaClone) {
	MatrixArea original(3, 3);
	original.setValue(0, 0, true);
	original.setValue(2, 2, true);
	original.setCenter(1, 1);

	auto cloned = original.clone();

	ASSERT_NE(nullptr, cloned);
	EXPECT_EQ(original.getRows(), cloned->getRows());
	EXPECT_EQ(original.getCols(), cloned->getCols());
	EXPECT_TRUE(cloned->getValue(0, 0));
	EXPECT_TRUE(cloned->getValue(2, 2));

	uint32_t origY, origX, cloneY, cloneX;
	original.getCenter(origY, origX);
	cloned->getCenter(cloneY, cloneX);

	EXPECT_EQ(origY, cloneY);
	EXPECT_EQ(origX, cloneX);
}

/**
 * @brief Test MatrixArea array operator
 */
TEST_F(CombatTest, MatrixAreaArrayOperator) {
	MatrixArea area(3, 3);

	// Using array operator to set values
	area[0][0] = true;
	area[1][1] = true;
	area[2][2] = false;

	// Using array operator to read values
	EXPECT_TRUE(area[0][0]);
	EXPECT_TRUE(area[1][1]);
	EXPECT_FALSE(area[2][2]);
}

/**
 * @brief Test CombatParams default initialization
 */
TEST_F(CombatTest, CombatParamsDefaultValues) {
	CombatParams params;

	EXPECT_EQ(0, params.itemId);
	EXPECT_EQ(CONDITION_NONE, params.dispelType);
	EXPECT_EQ(COMBAT_NONE, params.combatType);
	EXPECT_EQ(ORIGIN_SPELL, params.origin);
	EXPECT_EQ(CONST_ME_NONE, params.impactEffect);
	EXPECT_EQ(SoundEffect_t::SILENCE, params.soundImpactEffect);
	EXPECT_EQ(CONST_ANI_NONE, params.distanceEffect);
	EXPECT_EQ(SoundEffect_t::SILENCE, params.soundCastEffect);
	EXPECT_FALSE(params.blockedByArmor);
	EXPECT_FALSE(params.blockedByShield);
	EXPECT_FALSE(params.targetCasterOrTopMost);
	EXPECT_TRUE(params.aggressive);
	EXPECT_FALSE(params.useCharges);
	EXPECT_EQ(CONST_ME_NONE, params.chainEffect);
}

/**
 * @brief Test CombatParams with custom values
 */
TEST_F(CombatTest, CombatParamsCustomValues) {
	CombatParams params;

	params.combatType = COMBAT_FIREDAMAGE;
	params.origin = ORIGIN_MELEE;
	params.blockedByArmor = true;
	params.blockedByShield = true;
	params.aggressive = false;

	EXPECT_EQ(COMBAT_FIREDAMAGE, params.combatType);
	EXPECT_EQ(ORIGIN_MELEE, params.origin);
	EXPECT_TRUE(params.blockedByArmor);
	EXPECT_TRUE(params.blockedByShield);
	EXPECT_FALSE(params.aggressive);
}

/**
 * @brief Test ChainCallback construction
 */
TEST_F(CombatTest, ChainCallbackConstruction) {
	ChainCallback callback(5, 3, true);

	uint8_t targets = 0;
	uint8_t distance = 0;
	bool backtrack = false;

	callback.getChainValues(nullptr, targets, distance, backtrack);

	EXPECT_EQ(5, targets);
	EXPECT_EQ(3, distance);
	EXPECT_TRUE(backtrack);
}

/**
 * @brief Test ChainCallback with different parameters
 */
TEST_F(CombatTest, ChainCallbackDifferentParameters) {
	ChainCallback callback1(3, 2, false);
	uint8_t targets1 = 0, distance1 = 0;
	bool backtrack1 = true;
	callback1.getChainValues(nullptr, targets1, distance1, backtrack1);
	EXPECT_EQ(3, targets1);
	EXPECT_EQ(2, distance1);
	EXPECT_FALSE(backtrack1);

	ChainCallback callback2(10, 5, true);
	uint8_t targets2 = 0, distance2 = 0;
	bool backtrack2 = false;
	callback2.getChainValues(nullptr, targets2, distance2, backtrack2);
	EXPECT_EQ(10, targets2);
	EXPECT_EQ(5, distance2);
	EXPECT_TRUE(backtrack2);
}

/**
 * @brief Test ValueCallback construction
 */
TEST_F(CombatTest, ValueCallbackConstruction) {
	ValueCallback callback(COMBAT_FORMULA_DAMAGE);
	// Constructor should complete without error
	EXPECT_NO_FATAL_FAILURE({
		ValueCallback cb(COMBAT_FORMULA_LEVELMAGIC);
	});

	EXPECT_NO_FATAL_FAILURE({
		ValueCallback cb(COMBAT_FORMULA_SKILL);
	});
}

/**
 * @brief Test edge case: MatrixArea with boundary values
 */
TEST_F(CombatTest, MatrixAreaBoundaryValues) {
	MatrixArea area(3, 3);

	// Set edge values
	area.setValue(0, 0, true);
	area.setValue(0, 2, true);
	area.setValue(2, 0, true);
	area.setValue(2, 2, true);

	// Verify edge values
	EXPECT_TRUE(area.getValue(0, 0));
	EXPECT_TRUE(area.getValue(0, 2));
	EXPECT_TRUE(area.getValue(2, 0));
	EXPECT_TRUE(area.getValue(2, 2));
}

/**
 * @brief Test negative case: conversion with all elemental damage types
 */
TEST_F(CombatTest, AllElementalDamageTypeConversions) {
	// Test all elemental damage types can be converted
	auto fireCondition = Combat::DamageToConditionType(COMBAT_FIREDAMAGE);
	auto energyCondition = Combat::DamageToConditionType(COMBAT_ENERGYDAMAGE);
	auto earthCondition = Combat::DamageToConditionType(COMBAT_EARTHDAMAGE);
	auto iceCondition = Combat::DamageToConditionType(COMBAT_ICEDAMAGE);
	auto holyCondition = Combat::DamageToConditionType(COMBAT_HOLYDAMAGE);
	auto deathCondition = Combat::DamageToConditionType(COMBAT_DEATHDAMAGE);

	EXPECT_NE(CONDITION_NONE, fireCondition);
	EXPECT_NE(CONDITION_NONE, energyCondition);
	EXPECT_NE(CONDITION_NONE, earthCondition);
	EXPECT_NE(CONDITION_NONE, iceCondition);
	EXPECT_NE(CONDITION_NONE, holyCondition);
	EXPECT_NE(CONDITION_NONE, deathCondition);
}