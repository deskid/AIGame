#ifndef FIGHTER_ATTRIBUTE_HPP_
#define FIGHTER_ATTRIBUTE_HPP_
#include "type_difinition.hpp"

namespace AIGame {

/**
 * this is the attributes of a Fighter
 */
struct FighterAttribute {
	hp_type       hp; // hit point
	hp_type       phy_att; // physical attack point
	hp_type       phy_def; // physical defence point
	hp_type       mag_att; // magic attack point
	hp_type       mag_def; // magic defence point
	length_unit   range; // range of attack. 0 for close combat only unit
	tick_unit     freq;  // frequency of attack.
}; // FighterAttribute

} // AIGame

#endif // FIGHTER_ATTRIBUTE_HPP_
