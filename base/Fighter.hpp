#ifndef FIGHTER_HPP_
#define FIGHTER_HPP_
#include "type_difinition.hpp"
#include "FighterPrototype.hpp"
#include "Equipment.hpp"
#include <string>
#include <array>
#include <memory>

namespace AIGame {

// status of fighter
enum /* class */ FightingStatus {idle, attack, forward, backward, flee, dead};

struct FighterPrototype;

/**
 * this is The class for fighter. It's the instance of a FighterPrototype.
 *		which appears as individual object.
 * AI profile is not presented here.
 */
class Fighter {
public:
	static const int MAX_EQUIPMENTS = 4; // maximum equipments available
	typedef std::shared_ptr<Equipment> EquipType;
	typedef std::array<EquipType, MAX_EQUIPMENTS> EquipmentsType;
public:
	/**
	 * Initialize fighter from template. With a given name
	 *
	 * @param baseType
	 *		the template of the fighter
	 * @param Name
	 *		name of the fighter
	 */
	Fighter(const FighterPrototype* baseType, const std::string& Name)
		:base_type(baseType), name(Name),
		fighting_attr(baseType->fighting_attr), living_attr(baseType->living_attr),
		attack_type(baseType->attack_type),
		fighting_status(idle), target(0), skill_point(0), exp(0)
	{
	}

	/**
	 * do not call this unless loading from file!
	 */
	Fighter() :base_type(nullptr), attack_type(normal) {
		// defaul
	}

// getters
public:
	hp_type getPhysicalAttack() const { return fighting_attr.phy_att; }
	hp_type getPhysicalDefence() const { return fighting_attr.phy_def; }
	hp_type getMagicAttack() const { return fighting_attr.mag_att; }
	hp_type getMagicDefence() const { return fighting_attr.mag_def; }
	length_unit getRange() const { return fighting_attr.range; }
	hp_type getHp() const { return fighting_attr.hp; }
	tick_unit getFrequency() const { return fighting_attr.freq; }
	const FighterPrototype* getBaseType() const { return base_type; }
	exp_type getExperience() const { return exp; }
	const Fighter* getTarget() const { return target; } // might need a non-const version
	FightingStatus getFightingStatus() const { return fighting_status; }
	unsigned getSkillPoint() const { return skill_point; }
	const EquipmentsType getEquipments() const { return equips; }
// attribute increase/decrease methods
public:
	/**
	 * increase/decrease attribute point.
	 * @param attribute_type value
	 *		the value to increase. Could be negtive
	 */
	// phy_att
	void increasePhysicalAttack(hp_type value) { fighting_attr.phy_att += value; }
	void decreasePhysicalAttack(hp_type value) { fighting_attr.phy_att -= value; }
	// phy_def
	void decreasePhysicalDefence(hp_type value) { fighting_attr.phy_def -= value; }
	void increasePhysicalDefence(hp_type value) { fighting_attr.phy_att += value; }
	// mag_att
	void increaseMagicAttack(hp_type value) { fighting_attr.mag_att += value; }
	void decreaseMagicAttack(hp_type value) { fighting_attr.mag_att -= value; }
	// mag_def
	void decreaseMagicDefence(hp_type value) { fighting_attr.mag_def -= value; }
	void increaseMagicDefence(hp_type value) { fighting_attr.mag_def += value; }
	// range
	void increaseRange(length_unit length) {
		fighting_attr.range += length;
		if (fighting_attr.range < 0) fighting_attr.range = 0;
	}
	// implementation shall not be increaseRange(-length), for range length_unit might be an unsigned type
	void decreaseRange(length_unit length) {
		fighting_attr.range -= length; 
		if (fighting_attr.range < 0) fighting_attr.range = 0;
	}
	// freq
	void increaseFrequency(tick_unit tick) {
		fighting_attr.freq += tick; 
		if (fighting_attr.freq <= 0) fighting_attr.freq = 1;
	}
	void decreaseFrequency(tick_unit tick) {
		fighting_attr.freq -= tick;
		if (fighting_attr.freq <= 0) fighting_attr.freq = 1;
	}
	// hp
	void increaseHp(hp_type value) { 
		fighting_attr.hp += value; 
		if (fighting_attr.hp <= 0) {
			fighting_attr.hp = 0; 
			modifyStatus(dead);
		}
	}

	void decreaseHp(hp_type value) {
		fighting_attr.hp += value; 
		if (fighting_attr.hp <= 0) {
			fighting_attr.hp =
				0; modifyStatus(dead);
		}
	}

	////////////////
	// level up rule not presented here
	void increaseExperience(exp_type value) { exp += value; }
	void decreaseExperience(exp_type value) { exp -= value; }
	void increaseSkillPoint(unsigned point) { skill_point += point; }
	void decreaseSkillPoint(unsigned point) { skill_point -= point; }
// attribute modification methods
public:
	// modify
	void modifyStatus(FightingStatus new_status) { fighting_status = new_status; }
	// set a new target for fighter
	void modifyTarget(Fighter* new_target) { target = new_target; }
	// clear the target for fighter
	void clearTarget(void) { target = nullptr; }
	/**
	 * add equipment to Fighter.
	 * @param equip
	 *		Equipment to add
	 * @return
	 *		false if add failed
	 */
	bool addEquipment(Equipment equip) {
		for (auto& e : equips) {
			if (e != nullptr) { // slot avaliable, insert
				e = std::make_shared<Equipment>(equip);
				return true;
			}
		}

		return false;
	}
	/**
	 * remove an Equipment
	 * if index out of range, return false. If it's originally empty, return false
	 * @param
	 *		id to remove
	 * @return
	 *		true if removed, false if not.
	 */
	bool removeEquipment(int id) {
		// lazy evaluaion
		if (id < 0 || id >= MAX_EQUIPMENTS || equips[id] == nullptr) return false;
		equips[id] = nullptr;
		return false;
	}
	void clearEquipment(void) {
		for (auto& e : equips) e = nullptr;
	}
	/**
	 * return true if the fighter could apply more equips
	 * otherwise return false
	 */
	bool hasEquipSlot() const {
		for (auto& e : equips) {
			if (e != nullptr) { // slot avaliable, insert
				return true;
			}
		}

		return false;
	}
	bool hasEquip(const Equipment& equip) const {
		return std::find_if(equips.begin(), equips.end(), 
			[&](const EquipType& iter) {
				return (*iter)->getId() == equip->getId();
		}) != equips.end();
	}
	const EquipmentsType& getEquips() const {
		return equips;
	}

	EquipmentsType& getEquips() {
		return equips;
	}
// value directly inherited from Fighter Template
private:
	const FighterPrototype*base_type; // template of the fighter
	std::string            name; // name of the fighter
	FightingAttribute      fighting_attr;
	LivingAttribute        living_attr;
	// can not be modified
	const AttackType       attack_type; // type of bullet
private:
	// combat attributes
	FightingStatus         fighting_status; // status of fighter, in combat
	Fighter*               target; // the enemy I current aimed
	exp_type               exp; // experience
	unsigned               skill_point; // skill points gained when level up
	EquipmentsType         equips; // equipments; TODO modifier
	id_type                id; // id, auto assigned; TODO
private:
	Fighter(const Fighter&); // = delete;
	Fighter& operator=(const Fighter&); // = delete ;
}; // Fighter

} // AIGame
#endif // FIGHTER_HPP_