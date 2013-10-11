#ifndef EQUIPMENT_HPP_
#define EQUIPMENT_HPP_

#include "FighterAttribute.hpp"
#include <string>

namespace AIGame {

/**
 * this is the class defines equipments
 * an equipment is an item hold by Fighter to enhance there attributes
 */
struct Equipment {
	id_type id; // id of equipment. auto assigned
	std::string name; // name of the equipment
	FighterAttribute attr; // modification made by Equipment to attributes
}; // Equipments
} // AIGame
#endif // EQUIPMENT_HPP_