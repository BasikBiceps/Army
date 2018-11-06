#include "stdafx.h"
#include "MagicAttack.h"
#include "Unit.h"
#include "AttackSpell.h"


MagicAttack::MagicAttack() {}

MagicAttack::~MagicAttack() {}

void MagicAttack::attack(Unit & attacker, Unit & attacked)
{
	AttackSpell spell;
	attack(attacker, attacked, spell);
}

void MagicAttack::counterAttack(Unit & attacker, Unit & attacked)
{
	AttackSpell spell;

	counterAttack(attacker, attacked, spell);
}

void MagicAttack::takeDamage(Unit & attacked, int damage)
{
	attacked.getState().setHealthPoint(attacked.getState().getHealthPoint() - damage);

	if (attacked.getState().getHealthPoint() <= 0) {
		attacked.getState().setHealthPoint(0);
		attacked.notifyObservers();
	}
}

void MagicAttack::attack(Unit & attacker, Unit & attacked, Spell & spell)
{
	if (attacker.getState().getHealthPoint() < 0 || attacked.getState().getHealthPoint() < 0) {
		throw UnitIsDeadException();
	}
	if (attacker.getState().getMana() < spell.getNeedMana()) {
		throw NotEnoughManaException();
	}
	attacker.getState().setMana(attacker.getState().getMana() - spell.getNeedMana());
	takeDamage(attacked, spell);
}

void MagicAttack::counterAttack(Unit & attacker, Unit & attacked, Spell & spell)
{
	if (attacker.getState().getHealthPoint() < 0 || attacked.getState().getHealthPoint() < 0) {
		throw UnitIsDeadException();
	}
	if (attacker.getState().getMana() < spell.getNeedMana()) {
		throw NotEnoughManaException();
	}
	attacker.getState().setMana(attacker.getState().getMana() - spell.getNeedMana());
	spell.setPower(spell.getPower()/2);
	takeDamage(attacked, spell);
}

void MagicAttack::takeDamage(Unit & attacked, Spell & spell)
{
	spell.cast(attacked);
}
