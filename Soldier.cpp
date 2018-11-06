#include "stdafx.h"
#include "Soldier.h"
#include "PhysAttack.h"


Soldier::Soldier() : Unit(*(new State("Soldier", HEALTH_POINTS_SOLDIER, PHYS_DAMAGE_SOLDIER, MANA_SOLDIER, 1)), *(new PhysAttack())) {}

Soldier::Soldier(State & state, PhysAttack & physAttack) : Unit(state, physAttack) {}

Soldier::~Soldier() {}

void Soldier::physicAttack(Unit & attacked)
{
	this->getAttack().attack(*this, attacked);
	attacked.getAttack().counterAttack(*this, attacked);
}
