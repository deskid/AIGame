#ifndef WORLD_HPP
#define WORLD_HPP

#include "base\Fighter.hpp"
#include "base\Instrument.hpp"
#include "base\Quest.hpp"
#include "base\Faction.hpp"
#include "util\unique_container.hpp"
#include <list>

namespace AIGame {

class World {
public:
	typedef util::unique_container<FighterPrototype, std::list> FighterProtoList;
	typedef util::unique_container<EquipmentPrototype, std::list> EquipProtoList;
	typedef util::unique_container<InstrumentPrototype, std::list> InstrumentProtoList;
	typedef util::unique_container<Faction, std::list> FactionList;
	typedef util::unique_container<Quest, std::list> QuestList;
public:
	// currently do nothing
	World() {}
	// do nothing
	~World() {}
public:
	
private:
	// what a world has?
	FighterProtoList    protoFightersLocked; // locked fighters
	FighterProtoList    protoFighters; // available fighter
	EquipProtoList      protoEquipsLocked; // locked equipments
	EquipProtoList      protoEquips; // equipments avaliable
	InstrumentProtoList protoInstruments; // instrument avaliable
	QuestList           quests; // locked quests, or, quest list
	FactionList         factions;
	EquipmentStore      equipStore;
	InstrumentStore     instrumentStore;
	FighterStore        fighterStore;
};
} // AIGame

#endif // WORLD_HPP