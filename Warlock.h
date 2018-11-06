#pragma once
#include "SpellCaster.h"
#include <list>
#include <iterator>
#include "Demon.h"

enum {
	HEALTH_POINTS_WARLOCK = 80,
	PHYS_DAMAGE_WARLOCK = 10,
	MANA_WARLOCK = 150,
};

class Warlock :
	public SpellCaster
{
public:
	Warlock();
	Warlock(State& state, MagicAttack& magAttack, Spellbook& book);
	~Warlock();
	
	void physicAttack(Unit& attacked) override;
	void magicAttack(Unit& attacked, Spells spellNumber) override;

	void addDemon(Demon& demon);
	void removeDemon(Demon& demon);
	void attackWithDemons(Unit& attacked);

private:
	std::list<Demon*> demons;
};
