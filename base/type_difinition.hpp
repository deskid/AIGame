/**
 * This is the header for type difinitions.
 * since it will be included in many headers, DONT modify this unless necessary
 */
#ifndef TYPE_DIFINITION_HPP_
#define TYPE_DIFINITION_HPP_

namespace AIGame {

typedef unsigned id_type; // type of id used by the framework
const unsigned not_assigned = 0; // id not assigned
typedef int hp_type; // hit point type
typedef int length_unit; // unit of length in combat.
typedef unsigned tick_unit; // unit of tick in combat
typedef unsigned exp_type; // experience type
} // AIGame

#endif // TYPE_DIFINITION_HPP_