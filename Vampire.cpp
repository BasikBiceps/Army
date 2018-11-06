#include "stdafx.h"
#include "Vampire.h"
#include "VampireAttack.h"


Vampire::Vampire() : Unit(*(new State("Vampire", HEALTH_POINTS_VAMPIRE, PHYS_DAMAGE_VAMPIRE, MANA_VAMPIRE, 1)), *(new VampireAttack())) {}

Vampire::Vampire(State & state, VampireAttack & attack) : Unit(state, attack) {}

Vampire::~Vampire() {}

void Vampire::physicAttack(Unit & attacked)
{
	this->getAttack().attack(*this, attacked);
	attacked.getAttack().counterAttack(*this, attacked);
}
