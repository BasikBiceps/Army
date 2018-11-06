#include "stdafx.h"
#include "VampireAttack.h"
#include "Unit.h"
#include <stdlib.h>
#include <time.h>
#include <typeinfo>
#include "Werewolf.h"

VampireAttack::VampireAttack() {}

VampireAttack::~VampireAttack() {}

void VampireAttack::attack(Unit & attacker, Unit & attacked)
{
	if (!attacker.getState().ensureIsAlive() || !attacked.getState().ensureIsAlive()) {
		throw UnitIsDeadException();
	}

	takeDamage(attacked, attacker.getState().getPhysDamage());
	if (attacked.getState().ensureIsAlive() && typeid(attacked) != typeid(Werewolf)) {
		srand(time(NULL));
		if (rand() % 4 == 2) {
			delete &attacked.getAttack();
			attacked.setAttack(*(new VampireAttack()));
			attacked.getState().setHealthPointLimit(attacker.getState().getHealthPointLimit());
			attacked.getState().setMagicResist(attacker.getState().getMagicResist());
			attacked.getState().setManaLimit(attacker.getState().getManaLimit());
			attacked.getState().setPhysDamageLimit(attacker.getState().getPhysDamageLimit());
			attacked.getState().setPhysDamage(attacker.getState().getPhysDamage());
		}
	}

}

void VampireAttack::counterAttack(Unit & attacker, Unit & attacked)
{
	if (!attacker.getState().ensureIsAlive() || !attacked.getState().ensureIsAlive()) {
		throw UnitIsDeadException();
	}
	takeDamage(attacker, attacked.getState().getPhysDamage() / 2);
}

void VampireAttack::takeDamage(Unit & attacked, int damage)
{
	attacked.getState().setHealthPoint(attacked.getState().getHealthPoint() - damage);

	if (attacked.getState().getHealthPoint() <= 0) {
		attacked.getState().setHealthPoint(0);
		attacked.notifyObservers();
	}
}

