#ifndef ITEM_STORE_HPP
#define ITEM_STORE_HPP
#include "type_difinition.hpp"
#include "Equipment.hpp"
#include "Instrument.hpp"
#include "util/unique_container.hpp"
#include <tuple>

namespace AIGame {

template <typename T>
class ItemStore {
	typedef std::tuple<T, int> item_amount_type;
	typedef std::list<item_amount_type> item_list_type;
public:
	ItemStore() {}
	/**
	 * add item to store
	 * Items are distincted by their id
	 */
	void add(const T& equip, int amount) {
		if (amount == 0) return;
		
		auto iter = find(equip);

		if (iter != items.end()) { // found
			std::get<1>(*iter) += amount;
		} else {
			equips.push_back(item_amount_type(equip, amount));
		}
	}

	/**
	 * remove item from store
	 * if amount of item becomes zero, the item is removed
	 *
	 * @return
	 *		true if selled successfully, otherwise(not enough item) return false
	 */
	bool sell(const T& equip, int amount) {
		if (amount == 0) return true;

		auto iter = find(equip);
		if (iter != items.end()) { // found
			int& amt = std::get<1>(*iter);
			if (amt - amount < 0) return false; // not enough item
			else {
				amt -= amount;
				if (amt == 0) // all items sold out
					equips.erase(iter); // remove it
			}
		}

		return true;
	}

	const item_list_type& list(void) const { return equips; }
private:
	item_list_type::iterator find(const T& equip) {
		return std::find_if(items.begin(), items.end(), 
			[&](item_amount_type& i) {
				return id_is_equal(std::get<0>(i), equip);
			}
		);
	}
private:
	item_list_type items;
};

typedef ItemStore<Equipment> EquipmentStore;
typedef ItemStore<Instrument> InstrumentStore;
} // AIGame

#endif // ITEM_STORE_HPP