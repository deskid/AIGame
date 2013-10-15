#ifndef INSTRUMENT_HPP_
#define INSTRUMENT_HPP_
#include "FighterAttribute.hpp"
#include <string>

namespace AIGame {

/**
 * this is the class defines instrument
 * an instrument is an item hold by Fighter to enhance there living attributes
 * <strong>this is a special class. Which holds all different equips in a pool,
 *         and users only get the pointer to pool, not holding a resource itself!
 * </strong>
 */
struct Instrument {
	std::string name; // name of the instrument
	LivingAttribute attr; // modification made by Instrument to attributes
}; // Instrument

} // AIGame

#endif // INSTRUMENT