#include "Unit.h"
#include "PhysAttack.h"
#include <typeinfo>
#include <string>
#include "WerewolfAttack.h"
#include "VampireAttack.h"
#include "Werewolf.h"

#define INCREASE 1.5

Unit::Unit() {
	state = new State();
	attack = new PhysAttack();
}

Unit::Unit(State & state, Attack & attack) : state(&state), attack(&attack) {}

Unit::~Unit() {
	delete state;
	delete attack;
}

State &Unit::getState() {
	return *state;
}

Attack &Unit::getAttack() {
	return *attack;
}

void Unit::setState(State &state) {
	Unit::state = &state;
}

void Unit::setAttack(Attack &attack) {
	Unit::attack = &attack;
}

void Unit::transform()
{
	if (typeid(getAttack()) != typeid(WerewolfAttack)) {
		throw UnitCanNotTransformException();
	}

	if (!getState().isTransformed()) {
		getState().setTransformed(true);
		getState().setHealthPointLimit(getState().getHealthPointLimit() * INCREASE);
		getState().setHealthPoint(getState().getHealthPoint() * INCREASE);
		getState().setPhysDamageLimit(getState().getPhysDamageLimit() * INCREASE);
		getState().setPhysDamage(getState().getPhysDamage() * INCREASE);
		getState().setMagicResist(getState().getMagicResist() * INCREASE);
	}
	else {
		getState().setTransformed(false);
		getState().setHealthPointLimit(getState().getHealthPointLimit() / INCREASE);
		getState().setHealthPoint(getState().getHealthPoint() / INCREASE);
		getState().setPhysDamageLimit(getState().getPhysDamageLimit() / INCREASE);
		getState().setPhysDamage(getState().getPhysDamage() / INCREASE);
		getState().setMagicResist(getState().getMagicResist() / INCREASE);
	}
}

std::ostream & operator<<(std::ostream & os, Unit & unit)
{
	if (typeid(unit.getAttack()) == typeid(WerewolfAttack)) {
		os << "Type: class Werewolf" << std::endl;
		os << "isTransformed: " << unit.getState().isTransformed() << std::endl;
	}
	else if (typeid(unit.getAttack()) == typeid(VampireAttack)) {
		os << "Type: class Vampire" << std::endl;
	}
	else {
		os << "Type: " << typeid(unit).name() << std::endl;
	}

	os << "Name: " << unit.getState().getName() << std::endl;
	os << "Health points: " << unit.getState().getHealthPoint() << std::endl;
	os << "Damage: " << unit.getState().getPhysDamage() << std::endl;

	return os;
}
