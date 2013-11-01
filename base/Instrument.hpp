#ifndef INSTRUMENT_HPP_
#define INSTRUMENT_HPP_
#include "FighterAttribute.hpp"
#include "util/ProtoInstance.hpp"
#include <string>

namespace AIGame {

/**
 * this is the class defines instrument
 * an instrument is an item hold by Fighter to enhance there living attributes
 * <strong>this is a special class. Which holds all different equips in a pool,
 *         and users only get the pointer to pool, not holding a resource itself!
 * </strong>
 *
 * DO NOT MIX InstrumentPrototype UP WITH Instrument!
 */
struct InstrumentPrototype : public id_object {
	std::string name; // name of the instrument
	LivingAttribute attr; // modification made by Instrument to attributes
	
	money_type cost;

	InstrumentPrototype(const std::string& name, const LivingAttribute& attr, money_type cost)
		:name(name), attr(attr), cost(cost) {}
}; // Instrument

typedef ProtoInstance<InstrumentPrototype> Instrument;

} // AIGame

#endif // INSTRUMENT