#include "stdafx.h"
#include "Berserker.h"
#include "PhysAttack.h"

Berserker::Berserker() : Unit(*(new State("Berserker", HEALTH_POINTS_BERSERK, PHYS_DAMAGE_BERSERK, MANA_BERSERK, 0)), *(new PhysAttack())) {}

Berserker::Berserker(State & state, PhysAttack & physAttack) : Unit(state, physAttack) {}

Berserker::~Berserker() {}

void Berserker::physicAttack(Unit & attacked)
{
	this->getAttack().attack(*this, attacked);
	attacked.getAttack().counterAttack(*this, attacked);
}
