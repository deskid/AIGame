#ifndef EQUIPMENT_HPP_
#define EQUIPMENT_HPP_

#include "FighterAttribute.hpp"
#include "util/ProtoInstance.hpp"
#include "id_object.hpp"
#include <string>

namespace AIGame {

/**
 * this is the class defines equipments
 * an equipment is an item hold by Fighter to enhance there fighting attributes
 * <strong>this is a special class. Which holds all different equips in a pool,
 *         and users only get the pointer to pool, not holding a resource itself!
 * </strong>
 *
 * DO NOT MIX EquipmentPrototype UP with Equipment!
 */
struct EquipmentPrototype : public id_object {
	std::string name; // name of the equipment
	FightingAttribute attr; // modification made by Equipment to attributes
	money_type  cost; // cost of equipment
public:
	EquipmentPrototype(const std::string& name, const FightingAttribute& attr, money_type cost)
		:name(name), attr(attr), cost(cost) {}
}; // Equipments

typedef ProtoInstance<EquipmentPrototype> Equipment ;

} // AIGame
#endif // EQUIPMENT_HPP_