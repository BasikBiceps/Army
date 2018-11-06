#pragma once
#include "SpellCaster.h"

enum {
	HEALTH_POINTS_PRIEST = 70,
	PHYS_DAMAGE_PRIEST = 10,
	MANA_PRIEST = 150,
};

class Priest :
	public SpellCaster
{
public:
	Priest();
	Priest(State& state, MagicAttack& magAttack, Spellbook& book);
	~Priest();

	void physicAttack(Unit& attacked) override;
	void magicAttack(Unit& attacked, Spells spellNumber) override;
};



