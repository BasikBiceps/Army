#include "stdafx.h"
#include "RegenerateManaSpell.h"
#include "Unit.h"

RegenerateManaSpell::RegenerateManaSpell() : Spell(REGENERATE_MANA_NEED_MANA, REGENERATE_MANA_POWER) {}

RegenerateManaSpell::RegenerateManaSpell(int needMana, int power) : Spell(needMana, power) {}

RegenerateManaSpell::~RegenerateManaSpell() = default;

void RegenerateManaSpell::cast(Unit & unit)
{
	unit.getState().setMana(unit.getState().getMana() + unit.getState().getMagicResist() * getPower());

	if (unit.getState().getMana() > unit.getState().getManaLimit()) {
		unit.getState().setMana(unit.getState().getManaLimit());
	}
}
