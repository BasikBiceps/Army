#include "stdafx.h"
#include "Rogue.h"
#include "PhysAttack.h"

Rogue::Rogue() : Unit(*(new State("Rogue", HEALTH_POINTS_ROGUE, PHYS_DAMAGE_ROGUE, MANA_ROGUE, 1)), *(new PhysAttack())) {}

Rogue::Rogue(State & state, PhysAttack & physAttack) : Unit(state, physAttack) {}

Rogue::~Rogue() {}

void Rogue::physicAttack(Unit & attacked)
{
	this->getAttack().attack(*this, attacked);
}
