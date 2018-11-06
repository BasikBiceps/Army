#pragma once
#include "SpellCaster.h"

enum {
	HEALTH_POINTS_HEALER = 70,
	PHYS_DAMAGE_HEALER = 10,
	MANA_HEALER = 150,
};

class Healer :
	public SpellCaster
{
public:
	Healer();
	Healer(State& state, MagicAttack& magAttack, Spellbook& book);
	~Healer();

	void physicAttack(Unit& attacked) override;
	void magicAttack(Unit& attacked, Spells spellNumber) override;
};


