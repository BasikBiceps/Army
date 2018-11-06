#pragma once
#include "SpellCaster.h"

enum {
	HEALTH_POINTS_WIZARD = 80,
	PHYS_DAMAGE_WIZARD = 10,
	MANA_WIZARD = 150,
};

class Wizard :
	public SpellCaster
{
public:
	Wizard();
	Wizard(State& state, MagicAttack& magAttack, Spellbook& book);
	~Wizard();
	
	void physicAttack(Unit& attacked) override;
	void magicAttack(Unit& attacked, Spells spellNumber) override;

};


