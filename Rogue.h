#pragma once
#include "Unit.h"

class PhysAttack;

enum {
	HEALTH_POINTS_ROGUE = 110,
	PHYS_DAMAGE_ROGUE = 25,
	MANA_ROGUE = 0,
};

class Rogue :
	public Unit
{
public:
	Rogue();
	Rogue(State& state, PhysAttack& physAttack);
	~Rogue();

	void physicAttack(Unit& attacked) override;
};

