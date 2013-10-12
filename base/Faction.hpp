#ifndef FACTION_HPP_
#define FACTION_HPP_

#include "Quest.hpp"
#include "Fighter.hpp"
#include "Equipment.hpp"
#include <string>
#include <list>
#include <memory>

namespace AIGame {

class Faction {
public:
	typedef std::list<std::unique_ptr<Quest>> QuestListType;
	typedef std::list<std::unique_ptr<Fighter>> FighterListType;
	typedef std::list<Equipment*> EquipmentListType;
private:
	std::string       name; // name of the faction
	QuestListType     avaliable_quests;
	Quest*            running_quest;
	money_type        money;
	FighterListType   fighters;
	EquipmentListType equips;
}; // Faction

} // AIGame

#endif // FACTION_HPP_