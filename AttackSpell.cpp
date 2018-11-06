#include "stdafx.h"
#include "AttackSpell.h"
#include "Unit.h"

AttackSpell::AttackSpell() : Spell(ATTACK_NEED_MANA, ATTACK_POWER) {}

AttackSpell::AttackSpell(int needMana, int power) : Spell(needMana, power) {}

AttackSpell::~AttackSpell() {}

void AttackSpell::cast(Unit & unit)
{
	unit.getState().setHealthPoint(unit.getState().getHealthPoint() - getPower() * unit.getState().getMagicResist());
	if (!unit.getState().ensureIsAlive()) {
		unit.getState().setHealthPoint(0);
		unit.notifyObservers();
	}
}
