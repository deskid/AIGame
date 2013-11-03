#ifndef FACTION_HPP_
#define FACTION_HPP_

#include "Quest.hpp"
#include "Fighter.hpp"
#include "Equipment.hpp"
#include "Instrument.hpp"
#include "util/unique_container.hpp"
#include "Pools.hpp"
#include "ItemStore.hpp"
#include <string>
#include <list>
#include <tuple>
#include <memory>

namespace AIGame {

class Faction : public id_object {
public:
	typedef util::unique_container<Quest, std::list> QuestListType;
	typedef QuestListType::iterator QuestIterator;
	typedef QuestListType::const_iterator ConstQuestIterator;
	typedef util::unique_container<Fighter, std::list> FighterListType;
	typedef FighterListType::iterator FighterIterator;
	typedef FighterListType::const_iterator ConstFighterIterator;
	typedef EquipmentStore EquipmentListType;
	typedef InstrumentStore InstrumentListType;
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
	// Quest related functions
	/**
	 * add quest to avaliable quest list
	 * @param
	 */
	void addQuest(Quest* q) {
		auto iter = findQuestById(q);
		if (iter != quests.end()) { // not found
			quests.insert(q);
		} else { // found
			// do nothing
		}
	}
	/**
	 * take a quest from quest pool
	 * quest is indicated by the second parameter
	 * quest shall be in QuestPool
	 */
	void addQuestFromPool(QuestPool& quest_pool, QuestPool::iterator quest) {
		auto iter = findQuestById(quest.get());

		if (iter != quests.end()) {
			quest_pool.giveOwnship(iter, quests);
		}
	}
	/**
	 * set ative quest
	 */
	void setActiveQuest(QuestIterator iter) {
		running_quest = iter.get();
	}

	void removeQuest(QuestIterator iter) {
		quests.erase(iter);
	}
	
	const QuestListType& Quests() const {
		return quests;
	}

	QuestListType& Quests() {
		return quests;
	}
	// Equipment related functions
	void addEquip(const Equipment& equip, int amount = 1) {
		equips.add(equip, amount);
	}

	/**
	 * equip a equipment to fighter, if failed, return false
	 */
	bool equipFighter(const Equipment& equip, FighterIterator iter) {
		if (! iter->hasEquipSlot() ) return false;

		iter->addEquipment(equip);
		equips.remove(equip, 1);
		return true;
	}
	/**
	 * recycle an equipment from a fighter, if fighter does not have such equipment,
	 * return false
	 */
	bool recycleEquip(const Equipment& equip, FighterIterator iter) {
		if (iter->hasEquip(equip)) {
			iter->removeEquipment(equip->getId());
			equips.add(equip, 1);
			return true;
		}

		return false;
	}
	/**
	 * remove equips from equip storage. if no equip exist, return false
	 */
	bool removeEquip(const Equipment& equip, int amount = 1) {
		equips.remove(equip, 1);
	}
	// fighter related
	void addFighter(Fighter* fighter) {
		fighters.insert(fighter);
	}

	void removeFighter(FighterListType::iterator fighter) {
		fighters.erase(fighter);
	}

	FighterListType& getFighters() {
		return fighters;
	}

	const FighterListType& getFighters() const {
		return fighters;
	}
private:
	QuestIterator findQuestById(const Quest* what) {
		return std::find_if(quests.begin(), quests.end(), [&](const Quest& iter) {
			return iter.getId() == what->getId();
		});
	}
private:
	std::string        name; // name of the faction
	Quest*             running_quest; // quest current running
	money_type         money; // money owned
	FighterListType    fighters; // fighters owned
	EquipmentListType  equips; // equips owned
	InstrumentListType instruments; // instruments owned
	QuestListType      quests; // quests that could be taken
}; // Faction

} // AIGame

#endif // FACTION_HPP_