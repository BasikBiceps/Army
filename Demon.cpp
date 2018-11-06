#include "stdafx.h"
#include "Demon.h"
#include "PhysAttack.h"

Demon::Demon() : Soldier(*(new State("Demon", HEALTH_POINTS_SOLDIER, PHYS_DAMAGE_SOLDIER, MANA_SOLDIER, 1)), *(new PhysAttack())) {}

Demon::Demon(State & state, PhysAttack & physAttack) : Soldier(state, physAttack) {}

Demon::~Demon() {}
