#ifndef QUEST_HPP_
#define QUEST_HPP_
#include <vector>
#include <string>
#include "type_difinition.hpp"
#include "Equipment.hpp"
#include "Instrument.hpp"

namespace AIGame {

// predefined
class Faction;
class Fighter;
struct FighterPrototype;

enum class QuestStatus {
	unassigned, // not visible to player.
	in_poll, // in Task List
	ready, // the task is taken, but still not happening.
	running, // the task is running. In combat!
	succeed, // task succeed
	failed // task failed
};

enum class QuestType {
	main_quest,
	side_quest
};

/**
 * rewards to be gained after combat
 */
struct Reward {
	std::vector<FighterPrototype> unlock_fighter; // unlock fighter in store
	std::vector<EquipmentPrototype> unlock_equipment; // unlock equipment in store
	std::vector<InstrumentPrototype> unlock_instrument; // unlock instruments in store
	money_type gold;
};

struct Quest : public id_object {
	typedef std::vector<Fighter*> FighterListType;
	std::string            name; // quest name
	QuestStatus            status; // status of quest
	QuestType              type; // type of quest
	Faction*               enemy; // target faction
	FighterListType        fighters; // enemey fighters
	Reward                 reward;
};

}

#endif // QUEST_HPP