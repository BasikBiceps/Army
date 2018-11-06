#include "stdafx.h"
#include "RegenerateHpSpell.h"
#include "Unit.h"
#include "Vampire.h"
#include "Necromancer.h"
#include <typeinfo>

RegenerateHpSpell::RegenerateHpSpell() : Spell(REGENERATE_HP_NEED_MANA, REGENERATE_HP_POWER) {}

RegenerateHpSpell::RegenerateHpSpell(int needMana, int power) : Spell(needMana, power) {}

RegenerateHpSpell::~RegenerateHpSpell() {}

void RegenerateHpSpell::cast(Unit & unit)
{
	if (typeid(unit) == typeid(Vampire) || typeid(unit) == typeid(Necromancer)) {
		unit.getState().setHealthPoint(unit.getState().getHealthPoint() - getPower() * unit.getState().getMagicResist());
	}
	else {
		unit.getState().setHealthPoint(unit.getState().getHealthPoint() + getPower() * unit.getState().getMagicResist());
	}

	if (unit.getState().getHealthPoint() > unit.getState().getHealthPointLimit()) {
		unit.getState().setHealthPoint(unit.getState().getHealthPointLimit());
	}
	if (unit.getState().getHealthPoint() < 0) {
		unit.getState().setHealthPoint(0);
		unit.notifyObservers();
	}
}
