#ifndef FIGHTER_HPP_
#define FIGHTER_HPP_
#include "type_difinition.h"
#include "FighterTemplate.h"
#include <string>

namespace AIGame {

// status of fighter
enum /* class */ FightingStatus {idle, attack, forward, backward, flee, dead};

/**
 * this is The class for fighter. It's the instance of a FighterTemplate.
 *		which appears as individual object.
 * AI profile is not presented here.
 */
class Fighter {
public:
	/**
	 * Initialize fighter from template. With a given name
	 *
	 * @param baseType
	 *		the template of the fighter
	 * @param Name
	 *		name of the fighter
	 * 
	 */
	Fighter(const FighterTemplate* baseType, const std::string& Name)
		:base_type(baseType), name(Name),
		hp(baseType->hp), phy_att(baseType->phy_att), phy_def(baseType->phy_def),
		mag_att(baseType->mag_att), mag_def(baseType->mag_def),
		range(baseType->range), freq(baseType->freq),
		attack_type(baseType->attack_type),
		fighting_status(idle), target(0), skill_point(0), exp(0)
	{
	}

	/**
	 * Initialize fighter from saved files. Every attribute shall be the same
	 *
	 * @param
	 *		all necessary variables
	 * 
	 */
	Fighter(const FighterTemplate* baseType, const std::string& Name,
		hp_type hp, hp_type phy_att, hp_type phy_def,
		hp_type mag_att, hp_type mag_def, length_unit range, tick_unit freq,
		AttackType attack_type, FightingStatus fighting_status, Fighter* target, 
		unsigned skill_point, exp_type exp
	)
		:base_type(baseType), name(Name),
		hp(hp), phy_att(phy_att), phy_def(phy_def), 
		mag_att(mag_att), mag_def(mag_def), range(range), freq(freq),
		attack_type(baseType->attack_type), fighting_status(idle), 
		target(target), skill_point(skill_point), exp(exp)
	{
	}
// getters
public:
	hp_type getPhysicalAttack() const { return phy_att; }
	hp_type getPhysicalDefence() const { return phy_def; }
	hp_type getMagicAttack() const { return mag_att; }
	hp_type getMagicDefence() const { return mag_def; }
	length_unit getRange() const { return range; }
	hp_type getHp() const { return hp; }
	tick_unit getFrequency() const { return freq; }
	const FighterTemplate* getBaseType() const { return base_type; }
	exp_type getExperience() const { return exp; }
	const Fighter* getTarget() const { return target; } // might need a non-const version
	FightingStatus getFightingStatus() const { return fighting_status; }
	unsigned getSkillPoint() const { return skill_point; }
// attribute increase/decrease methods
public:
	/**
	 * increase/decrease attribute point.
	 * @param attribute_type value
	 *		the value to increase. Could be negtive
	 */
	// phy_att
	void increasePhysicalAttack(hp_type value) { phy_att += value; }
	void decreasePhysicalAttack(hp_type value) { phy_att -= value; }
	// phy_def
	void decreasePhysicalDefence(hp_type value) { phy_def -= value; }
	void increasePhysicalDefence(hp_type value) { phy_att += value; }
	// mag_att
	void increaseMagicAttack(hp_type value) { mag_att += value; }
	void decreaseMagicAttack(hp_type value) { mag_att -= value; }
	// mag_def
	void decreaseMagicDefence(hp_type value) { mag_def -= value; }
	void increaseMagicDefence(hp_type value) { mag_def += value; }
	// range
	void increaseRange(length_unit length) { range += length; if (range < 0) range = 0; }
	// implementation shall not be increaseRange(-length), for range length_unit might be an unsigned type
	void decreaseRange(length_unit length) { range -= length; if (range < 0) range = 0; }
	// freq
	void increaseFrequency(tick_unit tick) { freq += tick; if (freq <= 0) freq = 1; }
	void decreaseFrequency(tick_unit tick) { freq -= tick; if (freq <= 0) freq = 1; }
	// hp
	void increaseHp(hp_type value) { hp += value; if (hp <= 0) {hp = 0; modifyStatus(dead);} }
	void decreaseHp(hp_type value) { hp += value; if (hp <= 0) {hp = 0; modifyStatus(dead);} }

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
	void modifyTarget(Fighter* new_target) { target = new_target; }
	void clearTarget(void) { target = nullptr; }
// value directly inherited from Fighter Template
private:
	const FighterTemplate* base_type; // template of the fighter
	std::string   name; // name of the fighter
	hp_type       hp; // hit point
	hp_type       phy_att; // physical attack point
	hp_type       phy_def; // physical defence point
	hp_type       mag_att; // magic attack point
	hp_type       mag_def; // magic defence point
	length_unit   range; // range of attack. 0 for close combat only unit
	tick_unit     freq;  // frequency of attack.
	// can not be modified
	const AttackType attack_type;
private:
	FightingStatus fighting_status;
	Fighter* target; // the enemy I current aimed
	exp_type exp; // experience
	unsigned skill_point; // skill points gained when level up
private:
	Fighter(const Fighter&);
}; // Fighter

} // AIGame
#endif // FIGHTER_HPP_