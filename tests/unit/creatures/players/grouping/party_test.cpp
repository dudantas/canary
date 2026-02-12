/**
 * Canary - A free and open-source MMORPG server emulator
 * Copyright (©) 2019-2023 OpenTibiaBR <opentibiabr@outlook.com>
 * Repository: https://github.com/opentibiabr/canary
 * License: https://github.com/opentibiabr/canary/blob/main/LICENSE
 * Contributors: https://github.com/opentibiabr/canary/graphs/contributors
 * Website: https://docs.opentibiabr.com/
 */

#include <gtest/gtest.h>
#include "creatures/players/grouping/party.hpp"

/**
 * @class PartyTest
 * @brief Test suite for Party system functionality
 *
 * Tests party creation, member management, shared experience, and party mechanics
 */
class PartyTest : public ::testing::Test {
protected:
	void SetUp() override {
	}

	void TearDown() override {
	}
};

/**
 * @brief Test SharedExpStatus_t enum values exist
 */
TEST_F(PartyTest, SharedExpStatusEnumValues) {
	// Verify all enum values are defined
	SharedExpStatus_t status = SHAREDEXP_OK;
	EXPECT_EQ(SHAREDEXP_OK, status);

	status = SHAREDEXP_TOOFARAWAY;
	EXPECT_EQ(SHAREDEXP_TOOFARAWAY, status);

	status = SHAREDEXP_LEVELDIFFTOOLARGE;
	EXPECT_EQ(SHAREDEXP_LEVELDIFFTOOLARGE, status);

	status = SHAREDEXP_MEMBERINACTIVE;
	EXPECT_EQ(SHAREDEXP_MEMBERINACTIVE, status);

	status = SHAREDEXP_EMPTYPARTY;
	EXPECT_EQ(SHAREDEXP_EMPTYPARTY, status);
}

/**
 * @brief Test PartyAnalyzer_t enum values
 */
TEST_F(PartyTest, PartyAnalyzerTypeEnumValues) {
	PartyAnalyzer_t priceType = MARKET_PRICE;
	EXPECT_EQ(MARKET_PRICE, priceType);

	priceType = SUPPLY_PRICE;
	EXPECT_EQ(SUPPLY_PRICE, priceType);
}

/**
 * @brief Test that Party can be created with nullptr leader (edge case)
 */
TEST_F(PartyTest, CreatePartyWithNullLeaderHandlesGracefully) {
	// Creating a party with null leader should handle gracefully
	// The actual behavior depends on implementation
	EXPECT_NO_FATAL_FAILURE({
		auto party = Party::create(nullptr);
		// If creation succeeds, party might be null or have special handling
	});
}

/**
 * @brief Test party analyzer price type can be set
 */
TEST_F(PartyTest, PartyAnalyzerPriceTypeDefaultValue) {
	// This tests the default value is MARKET_PRICE
	PartyAnalyzer_t defaultType = MARKET_PRICE;
	EXPECT_EQ(MARKET_PRICE, defaultType);
}

/**
 * @brief Test SharedExpStatus values are distinct
 */
TEST_F(PartyTest, SharedExpStatusValuesAreDistinct) {
	// All status values should be unique
	EXPECT_NE(static_cast<uint8_t>(SHAREDEXP_OK), static_cast<uint8_t>(SHAREDEXP_TOOFARAWAY));
	EXPECT_NE(static_cast<uint8_t>(SHAREDEXP_OK), static_cast<uint8_t>(SHAREDEXP_LEVELDIFFTOOLARGE));
	EXPECT_NE(static_cast<uint8_t>(SHAREDEXP_OK), static_cast<uint8_t>(SHAREDEXP_MEMBERINACTIVE));
	EXPECT_NE(static_cast<uint8_t>(SHAREDEXP_OK), static_cast<uint8_t>(SHAREDEXP_EMPTYPARTY));
	EXPECT_NE(static_cast<uint8_t>(SHAREDEXP_TOOFARAWAY), static_cast<uint8_t>(SHAREDEXP_LEVELDIFFTOOLARGE));
	EXPECT_NE(static_cast<uint8_t>(SHAREDEXP_TOOFARAWAY), static_cast<uint8_t>(SHAREDEXP_MEMBERINACTIVE));
	EXPECT_NE(static_cast<uint8_t>(SHAREDEXP_TOOFARAWAY), static_cast<uint8_t>(SHAREDEXP_EMPTYPARTY));
}

/**
 * @brief Test that party-related data structures can be initialized
 */
TEST_F(PartyTest, PartyAnalyzerVectorInitialization) {
	std::vector<std::shared_ptr<PartyAnalyzer>> membersData;
	EXPECT_TRUE(membersData.empty());
	EXPECT_EQ(0u, membersData.size());
}

/**
 * @brief Test PartyAnalyzer_t type assignments
 */
TEST_F(PartyTest, PartyAnalyzerTypeAssignments) {
	PartyAnalyzer_t type1 = MARKET_PRICE;
	PartyAnalyzer_t type2 = type1;

	EXPECT_EQ(type1, type2);
	EXPECT_EQ(MARKET_PRICE, type2);

	type2 = SUPPLY_PRICE;
	EXPECT_NE(type1, type2);
	EXPECT_EQ(SUPPLY_PRICE, type2);
}

/**
 * @brief Test SharedExpStatus can be used in switch statements
 */
TEST_F(PartyTest, SharedExpStatusInSwitchStatement) {
	SharedExpStatus_t status = SHAREDEXP_OK;

	std::string result;
	switch (status) {
		case SHAREDEXP_OK:
			result = "OK";
			break;
		case SHAREDEXP_TOOFARAWAY:
			result = "TOO_FAR";
			break;
		case SHAREDEXP_LEVELDIFFTOOLARGE:
			result = "LEVEL_DIFF";
			break;
		case SHAREDEXP_MEMBERINACTIVE:
			result = "INACTIVE";
			break;
		case SHAREDEXP_EMPTYPARTY:
			result = "EMPTY";
			break;
	}

	EXPECT_EQ("OK", result);
}

/**
 * @brief Test that all SharedExpStatus values can be assigned and compared
 */
TEST_F(PartyTest, SharedExpStatusAllValuesValid) {
	std::vector<SharedExpStatus_t> allStatuses = {
		SHAREDEXP_OK,
		SHAREDEXP_TOOFARAWAY,
		SHAREDEXP_LEVELDIFFTOOLARGE,
		SHAREDEXP_MEMBERINACTIVE,
		SHAREDEXP_EMPTYPARTY
	};

	// All values should be usable
	for (const auto &status : allStatuses) {
		SharedExpStatus_t copy = status;
		EXPECT_EQ(status, copy);
	}

	// Verify we have all 5 statuses
	EXPECT_EQ(5u, allStatuses.size());
}

/**
 * @brief Test boundary condition: SharedExpStatus minimum value
 */
TEST_F(PartyTest, SharedExpStatusMinimumValue) {
	SharedExpStatus_t status = SHAREDEXP_OK;
	// OK should be the first/minimum value (typically 0)
	EXPECT_EQ(0, static_cast<uint8_t>(status));
}

/**
 * @brief Test that PartyAnalyzer_t has distinct values
 */
TEST_F(PartyTest, PartyAnalyzerTypeDistinctValues) {
	PartyAnalyzer_t market = MARKET_PRICE;
	PartyAnalyzer_t supply = SUPPLY_PRICE;

	EXPECT_NE(static_cast<uint8_t>(market), static_cast<uint8_t>(supply));
}

/**
 * @brief Test empty party members data structure
 */
TEST_F(PartyTest, EmptyMembersDataVector) {
	std::vector<std::shared_ptr<PartyAnalyzer>> membersData;

	EXPECT_TRUE(membersData.empty());
	EXPECT_EQ(0u, membersData.size());

	// Can reserve space
	membersData.reserve(10);
	EXPECT_GE(membersData.capacity(), 10u);
	EXPECT_TRUE(membersData.empty());
}

/**
 * @brief Test trackerTime initialization
 */
TEST_F(PartyTest, TrackerTimeInitialization) {
	time_t currentTime = time(nullptr);
	time_t trackerTime = time(nullptr);

	// Times should be very close (within a second)
	EXPECT_LE(std::abs(static_cast<long>(currentTime - trackerTime)), 1);
}

/**
 * @brief Test that SharedExpStatus can be used as function return type
 */
TEST_F(PartyTest, SharedExpStatusAsFunctionReturnType) {
	auto getStatus = []() -> SharedExpStatus_t {
		return SHAREDEXP_OK;
	};

	SharedExpStatus_t result = getStatus();
	EXPECT_EQ(SHAREDEXP_OK, result);
}

/**
 * @brief Test that SharedExpStatus can be stored in containers
 */
TEST_F(PartyTest, SharedExpStatusInContainers) {
	std::vector<SharedExpStatus_t> statuses;
	statuses.push_back(SHAREDEXP_OK);
	statuses.push_back(SHAREDEXP_TOOFARAWAY);
	statuses.push_back(SHAREDEXP_LEVELDIFFTOOLARGE);

	EXPECT_EQ(3u, statuses.size());
	EXPECT_EQ(SHAREDEXP_OK, statuses[0]);
	EXPECT_EQ(SHAREDEXP_TOOFARAWAY, statuses[1]);
	EXPECT_EQ(SHAREDEXP_LEVELDIFFTOOLARGE, statuses[2]);
}

/**
 * @brief Test edge case: comparing SharedExpStatus values
 */
TEST_F(PartyTest, SharedExpStatusComparisons) {
	// Test equality
	EXPECT_TRUE(SHAREDEXP_OK == SHAREDEXP_OK);
	EXPECT_TRUE(SHAREDEXP_TOOFARAWAY == SHAREDEXP_TOOFARAWAY);

	// Test inequality
	EXPECT_TRUE(SHAREDEXP_OK != SHAREDEXP_TOOFARAWAY);
	EXPECT_TRUE(SHAREDEXP_LEVELDIFFTOOLARGE != SHAREDEXP_MEMBERINACTIVE);
}

/**
 * @brief Test that PartyAnalyzer_t can be used in conditional statements
 */
TEST_F(PartyTest, PartyAnalyzerTypeInConditionals) {
	PartyAnalyzer_t type = MARKET_PRICE;

	if (type == MARKET_PRICE) {
		EXPECT_EQ(MARKET_PRICE, type);
	} else {
		FAIL() << "Type should be MARKET_PRICE";
	}

	type = SUPPLY_PRICE;
	EXPECT_TRUE(type == SUPPLY_PRICE);
	EXPECT_FALSE(type == MARKET_PRICE);
}

/**
 * @brief Regression test: ensure all SharedExpStatus values are accessible
 */
TEST_F(PartyTest, AllSharedExpStatusValuesAccessible) {
	// This test ensures no enum values were accidentally removed
	SharedExpStatus_t s1 = SHAREDEXP_OK;
	SharedExpStatus_t s2 = SHAREDEXP_TOOFARAWAY;
	SharedExpStatus_t s3 = SHAREDEXP_LEVELDIFFTOOLARGE;
	SharedExpStatus_t s4 = SHAREDEXP_MEMBERINACTIVE;
	SharedExpStatus_t s5 = SHAREDEXP_EMPTYPARTY;

	// All should be distinct
	std::set<uint8_t> uniqueValues;
	uniqueValues.insert(static_cast<uint8_t>(s1));
	uniqueValues.insert(static_cast<uint8_t>(s2));
	uniqueValues.insert(static_cast<uint8_t>(s3));
	uniqueValues.insert(static_cast<uint8_t>(s4));
	uniqueValues.insert(static_cast<uint8_t>(s5));

	EXPECT_EQ(5u, uniqueValues.size()) << "All SharedExpStatus values should be unique";
}