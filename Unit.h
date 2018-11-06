#pragma once
#include "Observable.h"
#include "State.h"
#include "Attack.h"
#include <iostream> 

class UnitCanNotTransformException {};

class Unit : public Observable
{
public:

	Unit();
	Unit(State& state, Attack& attack);
	virtual ~Unit();

	State & getState();
	Attack & getAttack();

	void setState(State &state);
	void setAttack(Attack &attack);

	virtual void transform();
	virtual void physicAttack(Unit& attacked) = 0;

	friend std::ostream& operator << (std::ostream& os, Unit& unit);

private:
	State* state;
	Attack* attack;
};


