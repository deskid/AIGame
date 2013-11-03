#ifndef POOL_HPP
#define POOL_HPP

#include "util/unique_container.hpp"
#include "Equipment.hpp"
#include "Instrument.hpp"
#include "Quest.hpp"
#include <list>

namespace AIGame {
	typedef util::unique_container<EquipmentPrototype, std::list> EquipmentPool;
	typedef util::unique_container<InstrumentPrototype, std::list> InstrumentPool;
	typedef util::unique_container<Quest, std::list> QuestPool;
} // AIGame

#endif // POOL_HPP