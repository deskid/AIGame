#ifndef EQUIPMENT_HPP_
#define EQUIPMENT_HPP_

#include "FighterAttribute.hpp"
#include "util/ProtoInstance.hpp"
#include <string>

namespace AIGame {

/**
 * this is the class defines equipments
 * an equipment is an item hold by Fighter to enhance there fighting attributes
 * <strong>this is a special class. Which holds all different equips in a pool,
 *         and users only get the pointer to pool, not holding a resource itself!
 * </strong>
 */
struct EquipmentPrototype {
	std::string name; // name of the equipment
	FightingAttribute attr; // modification made by Equipment to attributes
}; // Equipments

using Equipment = ProtoInstance<EquipmentPrototype>;

} // AIGame
#endif // EQUIPMENT_HPP_