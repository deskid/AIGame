#include "Combat.h"

namespace AIGame {
	/**
	 * attacker attacks defender, cost his blood
	 */
	void fight(Fighter* attacker, Fighter* defender) {
		hp_type phy_damage = attacker->getPhysicalAttack() 
			- defender->getPhysicalDefence();
		hp_type mag_damage = attacker->getMagicAttack()
			- defender->getMagicDefence();
		defender->decreaseHp(phy_damage+mag_damage);
		if (defender->getStatus() == FightingStatus::dead) {
			// do something
		}
		// ui call
	}
}