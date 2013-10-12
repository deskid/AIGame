#ifndef FIGHTER_HPP_
#define FIGHTER_HPP_
#include "type_difinition.hpp"
#include "FighterTemplate.hpp"
#include <string>
#include <array>
#include <memory>

namespace AIGame {

// status of fighter
enum /* class */ FightingStatus {idle, attack, forward, backward, flee, dead};

struct Equipment;
struct FighterTemplate;

/**
 * this is The class for fighter. It's the instance of a FighterTemplate.
 *		which appears as individual object.
 * AI profile is not presented here.
 */
class Fighter {
public:
	static const int MAX_EQUIPMENTS = 4; // maximum equipments available
	typedef std::array<std::unique_ptr<Equipment>, MAX_EQUIPMENTS> EquipmentsType;
public:
	/**
	 * Initialize fighter from template. With a given name
	 *
	 * @param baseType
	 *		the template of the fighter
	 * @param Name
	 *		name of the fighter
	 */
	Fighter(const FighterTemplate* baseType, const std::string& Name)
		:base_type(baseType), name(Name),
		attr(baseType->attr), attack_type(baseType->attack_type),
		fighting_status(idle), target(0), skill_point(0), exp(0)
	{
	}

	/**
	 * Initialize fighter from saved files. Every attribute shall be the same
	 * TODO some value not initialized
	 * 
	 * @param
	 *		all necessary variables
	 */
	Fighter(const FighterTemplate* baseType, const std::string& Name,
		hp_type hp, hp_type phy_att, hp_type phy_def,
		hp_type mag_att, hp_type mag_def, length_unit range, tick_unit freq,
		AttackType attack_type, FightingStatus fighting_status, Fighter* target, 
		unsigned skill_point, exp_type exp
	)
		:base_type(baseType), name(Name),
		attack_type(baseType->attack_type), fighting_status(idle), 
		target(target), skill_point(skill_point), exp(exp)
	{
		attr.hp      = hp;
		attr.phy_att = phy_att;
		attr.phy_def = phy_def;
		attr.mag_att = mag_att;
		attr.mag_def = mag_def;
		attr.range   = range;
		attr.freq    = freq;
	}
// getters
public:
	hp_type getPhysicalAttack() const { return attr.phy_att; }
	hp_type getPhysicalDefence() const { return attr.phy_def; }
	hp_type getMagicAttack() const { return attr.mag_att; }
	hp_type getMagicDefence() const { return attr.mag_def; }
	length_unit getRange() const { return attr.range; }
	hp_type getHp() const { return attr.hp; }
	tick_unit getFrequency() const { return attr.freq; }
	const FighterTemplate* getBaseType() const { return base_type; }
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
	void increasePhysicalAttack(hp_type value) { attr.phy_att += value; }
	void decreasePhysicalAttack(hp_type value) { attr.phy_att -= value; }
	// phy_def
	void decreasePhysicalDefence(hp_type value) { attr.phy_def -= value; }
	void increasePhysicalDefence(hp_type value) { attr.phy_att += value; }
	// mag_att
	void increaseMagicAttack(hp_type value) { attr.mag_att += value; }
	void decreaseMagicAttack(hp_type value) { attr.mag_att -= value; }
	// mag_def
	void decreaseMagicDefence(hp_type value) { attr.mag_def -= value; }
	void increaseMagicDefence(hp_type value) { attr.mag_def += value; }
	// range
	void increaseRange(length_unit length) {
		attr.range += length; if (attr.range < 0) attr.range = 0;
	}
	// implementation shall not be increaseRange(-length), for range length_unit might be an unsigned type
	void decreaseRange(length_unit length) {
		attr.range -= length; if (attr.range < 0) attr.range = 0;
	}
	// freq
	void increaseFrequency(tick_unit tick) {
		attr.freq += tick; if (attr.freq <= 0) attr.freq = 1;
	}
	void decreaseFrequency(tick_unit tick) {
		attr.freq -= tick; if (attr.freq <= 0) attr.freq = 1;
	}
	// hp
	void increaseHp(hp_type value) { 
		attr.hp += value; if (attr.hp <= 0) {attr.hp = 0; modifyStatus(dead);}
	}

	void decreaseHp(hp_type value) {
		attr.hp += value; if (attr.hp <= 0) {attr.hp = 0; modifyStatus(dead);}
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
	bool addEquipment(Equipment* equip) {
		for (auto& e : equips) {
			if (e != nullptr) { // slot avaliable, insert
				e = equip;
				return true;
			}
			return false;
		}
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
// value directly inherited from Fighter Template
private:
	const FighterTemplate* base_type; // template of the fighter
	std::string            name; // name of the fighter
	FighterAttribute       attr;
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