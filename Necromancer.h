#pragma once
#include "SpellCaster.h"

class Observable;

enum {
	HEALTH_POINTS_NECROMANCER = 80,
	PHYS_DAMAGE_NECROMANCER = 10,
	MANA_NECROMANCER = 150,
};

class Necromancer :
	public SpellCaster, public Observer
{
public:
	Necromancer();
	Necromancer(State& state, MagicAttack& magAttack, Spellbook& book);
	~Necromancer();

	void physicAttack(Unit& attacked) override;
	void magicAttack(Unit& attacked, Spells spellNumber) override;
	void handleEvent(Observable& obsble) override;
};
