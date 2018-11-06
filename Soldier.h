#pragma once
#include "Unit.h"

class PhysAttack;

enum {
	HEALTH_POINTS_SOLDIER = 100,
	PHYS_DAMAGE_SOLDIER = 20,
	MANA_SOLDIER = 0,
};

class Soldier :
	public Unit
{
public:
	Soldier();
	Soldier(State& state, PhysAttack& physAttack);
	~Soldier();

	void physicAttack(Unit& attacked) override;
};

