#pragma once
#include "Unit.h"

class WerewolfAttack;

enum {
	HEALTH_POINTS_WEREWOLF = 200,
	PHYS_DAMAGE_WEREWOLF = 40,
	MANA_WEREWOLF = 0,
};

class Werewolf :
	public Unit
{
public:
	Werewolf();
	Werewolf(State& state, WerewolfAttack& attack);
	~Werewolf();
	
	void physicAttack(Unit& attacked) override;
	
};




