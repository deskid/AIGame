#ifndef FIGHTER_ATTRIBUTE_HPP_
#define FIGHTER_ATTRIBUTE_HPP_
#include "type_difinition.hpp"

namespace AIGame {

/**
 * this is the attributes of a Fighter in a combat
 */
struct FighterAttribute {
	hp_type       hp; // hit point
	hp_type       phy_att; // physical attack point
	hp_type       phy_def; // physical defence point
	hp_type       mag_att; // magic attack point
	hp_type       mag_def; // magic defence point
	length_unit   range; // range of attack. 0 for close combat only unit
}; // FighterAttribute

/**
 * This is the attributes of a Fighter in daily life
 */
struct LivingAttribute {
	tick_unit     freq;  // frequency of attack.
	money_type    salary; // salary per period unit
	hp_type       hp_recovery_rate;
	exp_type      exp_increase_rate;

};

} // AIGame

#endif // FIGHTER_ATTRIBUTE_HPP_
