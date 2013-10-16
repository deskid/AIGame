#ifndef QUEST_HPP_
#define QUEST_HPP_
#include <vector>
#include <string>

namespace AIGame {

// predefined
class Faction;
class Fighter;
class Equipment;
class Instrument;

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

struct Reward {
	std::vector<FighterPrototype*> unlock_fighter; // unlock fighter in store
	std::vector<Equipment*> unlock_equipment; // unlock equipment in store
	std::vector<Instrument*> unlock_instrument; // unlock instruments in store
	money_type gold;
};

struct Quest {
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