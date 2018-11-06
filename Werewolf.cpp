#include "stdafx.h"
#include "Werewolf.h"
#include "WerewolfAttack.h"

Werewolf::Werewolf() : Unit(*(new State("Werewolf", HEALTH_POINTS_WEREWOLF, PHYS_DAMAGE_WEREWOLF, MANA_WEREWOLF, 1)), *(new WerewolfAttack())) {}

Werewolf::Werewolf(State & state, WerewolfAttack & attack) : Unit(state, attack) {}

Werewolf::~Werewolf() {}

void Werewolf::physicAttack(Unit & attacked)
{
	this->getAttack().attack(*this, attacked);
	attacked.getAttack().counterAttack(*this, attacked);
}
