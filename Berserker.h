#pragma once
#include "Unit.h"

class PhysAttack;

enum {
	HEALTH_POINTS_BERSERK = 150,
	PHYS_DAMAGE_BERSERK = 35,
	MANA_BERSERK = 0,
};

class Berserker : public Unit
{
public:
	Berserker();
	Berserker(State& state, PhysAttack& physAttack);
	~Berserker();

	void physicAttack(Unit& attacked) override;
};


