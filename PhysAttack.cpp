#include "Unit.h"
#include "PhysAttack.h"

PhysAttack::PhysAttack() {}

PhysAttack::~PhysAttack() {}

void PhysAttack::attack(Unit & attacker, Unit & attacked)
{
	if (!attacker.getState().ensureIsAlive() || !attacked.getState().ensureIsAlive()) {
		throw UnitIsDeadException();
	}
	takeDamage(attacked, attacker.getState().getPhysDamage());
}

void PhysAttack::counterAttack(Unit & attacker, Unit & attacked)
{
	if (!attacker.getState().ensureIsAlive() || !attacked.getState().ensureIsAlive()) {
		throw UnitIsDeadException();
	}
	takeDamage(attacker, attacked.getState().getPhysDamage()/2);
}

void PhysAttack::takeDamage(Unit & attacked, int damage)
{
	attacked.getState().setHealthPoint(attacked.getState().getHealthPoint() - damage);

	if (attacked.getState().getHealthPoint() <= 0) {
		attacked.getState().setHealthPoint(0);
		attacked.notifyObservers();
	}
}
