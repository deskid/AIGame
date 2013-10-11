#ifndef FIGHTER_TEMPLATE_H_
#define FIGHTER_TEMPLATE_H_
#include "type_difinition.h"
#include <string>
#include <vector>

namespace AIGame {

enum /* class */ AttackType {normal, explode, penetrate, beatback};

/**
 * this is The template of fighter, which appears as individual object.
 * every fighter shall be a instance of one of the templates.
 */
struct FighterTemplate {
	unsigned      id; // id of template. MUST NOT DUPLICATE. 0~10 are preserved
	std::string   name; // name of the figther template
	hp_type       hp; // hit point
	hp_type       phy_att; // physical attack point
	hp_type       phy_def; // physical defence point
	hp_type       mag_att; // magic attack point
	hp_type       mag_def; // magic defence point
	length_unit   range; // range of attack. 0 for close combat only unit
	tick_unit     freq;  // frequency of attack.
	AttackType    attack_type; // type of attack
	unsigned      upgrade_id[4]; // fighter template(s) avaliable for upgrade. at most 4.
}; // Fighter Template

} // AIGame
#endif // FIGHTER_TEMPLATE_H_