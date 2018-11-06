#pragma once
#include "Unit.h"

class VampireAttack;

enum {
	HEALTH_POINTS_VAMPIRE = 180,
	PHYS_DAMAGE_VAMPIRE = 30,
	MANA_VAMPIRE = 0,
};

class Vampire :
	public Unit
{
public:

	Vampire();
	Vampire(State& state, VampireAttack& attack);

	~Vampire();

	void physicAttack(Unit& attacked) override;
	
};

