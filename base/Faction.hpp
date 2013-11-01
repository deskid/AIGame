#ifndef FACTION_HPP_
#define FACTION_HPP_

#include "Quest.hpp"
#include "Fighter.hpp"
#include "Equipment.hpp"
#include "Instrument.hpp"
#include "util/unique_container.hpp"
#include <string>
#include <list>
#include <tuple>
#include <memory>

namespace AIGame {

class Faction : public id_object {
public:
	typedef util::unique_container<Quest, std::list> QuestListType;
	typedef util::unique_container<Fighter, std::list> FighterListType;
	typedef std::tuple<Equipment, int> EquipmentType;
	typedef std::list<EquipmentType> EquipmentListType;
	typedef std::tuple<Instrument, int> InstrumentType;
	typedef std::list<InstrumentType> InstrumentListType;
public:
	/**
	 * ctor: init faction with name and money
	 */
	Faction(const std::string& name, money_type initial_money)
		:name(name), money(initial_money) {
			running_quest = nullptr;
			// left all others empty
	}
	// do nothing
	~Faction() {}

private:
	std::string        name; // name of the faction
	Quest*             running_quest; // quest current running
	money_type         money; // money owned
	FighterListType    fighters; // fighters owned
	EquipmentListType  equips; // equips owned
	InstrumentListType instruments; // instruments owned
	QuestListType      avaliable_quests; // quests that could be taken
}; // Faction

} // AIGame

#endif // FACTION_HPP_