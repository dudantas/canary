/**
 * Canary - A free and open-source MMORPG server emulator
 * Copyright (©) 2019-2022 OpenTibiaBR <opentibiabr@outlook.com>
 * Repository: https://github.com/opentibiabr/canary
 * License: https://github.com/opentibiabr/canary/blob/main/LICENSE
 * Contributors: https://github.com/opentibiabr/canary/graphs/contributors
 * Website: https://docs.opentibiabr.com/
 */

#ifndef SRC_LUA_CREATURE_TALKACTION_H_
#define SRC_LUA_CREATURE_TALKACTION_H_

#include "creatures/players/account/account.hpp"
#include "lua/global/baseevents.h"
#include "utils/utils_definitions.hpp"
#include "declarations.hpp"
#include "lua/scripts/luascript.h"
#include "lua/scripts/scripts.h"

class TalkAction;
using TalkAction_ptr = std::unique_ptr<TalkAction>;

class TalkAction : public Script {
	public:
		using Script::Script;

		const std::string &getWords() const {
			return words;
		}
		const std::string &getName() const {
			return name;
		}
		void setName(std::string newName) {
			name.append(newName);
		}
		const std::vector<std::string> &getWordsMap() const {
			return wordsMap;
		}
		void setWords(std::string word) {
			words = word;
			wordsMap.push_back(word);
		}
		std::string getSeparator() const {
			return separator;
		}
		void setSeparator(std::string sep) {
			separator = sep;
		}

		// scripting
		bool executeSay(Player* player, const std::string &words, const std::string &param, SpeakClasses type) const;
		//

		void setGroupType(account::GroupType newGroupType) {
			m_groupType = newGroupType;
		}

		const account::GroupType& getGroupType() const {
			return m_groupType;
		}

	private:
		std::string getScriptTypeName() const override {
			return "onSay";
		}

		std::string words;
		std::string name;
		std::vector<std::string> wordsMap;
		std::string separator = "\"";
		account::GroupType m_groupType;
};

class TalkActions final : public Scripts {
	public:
		TalkActions();
		~TalkActions();

		// non-copyable
		TalkActions(const TalkActions &) = delete;
		TalkActions &operator=(const TalkActions &) = delete;

		static TalkActions &getInstance() {
			// Guaranteed to be destroyed
			static TalkActions instance;
			// Instantiated on first use
			return instance;
		}

		TalkActionResult_t playerSaySpell(Player* player, SpeakClasses type, const std::string &words) const;

		bool registerLuaEvent(TalkAction* event);
		void clear();

		const std::map<std::string, TalkAction> &getTalkActionsMap() const {
			return talkActions;
		};

	private:
		std::map<std::string, TalkAction> talkActions;
};

constexpr auto g_talkActions = &TalkActions::getInstance;

#endif // SRC_LUA_CREATURE_TALKACTION_H_
