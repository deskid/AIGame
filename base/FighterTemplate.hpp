#ifndef FIGHTER_TEMPLATE_HPP_
#define FIGHTER_TEMPLATE_HPP_
#include "type_difinition.hpp"
#include "FighterAttribute.hpp"
#include <string>
#include <array>

namespace AIGame {

enum /* class */ AttackType {normal, explode, penetrate, beatback};

/**
 * this is The template of fighter, which appears as individual object.
 * every fighter shall be a instance of one of the templates.
 */
struct FighterTemplate { 
	static const int MAX_UPGRADES = 4; // maximum number of upgrades available
	typedef std::array<FighterTemplate*, MAX_UPGRADES> UpgradesType;
	std::string       name; // name of the figther template
	FighterAttribute  attr; // attributes
	AttackType        attack_type; // type of attack
	UpgradesType      upgrades; // fighter template(s) avaliable for upgrade. at most 4.
}; // Fighter Template

} // AIGame
#endif // FIGHTER_TEMPLATE_HPP_