#pragma once
#include "Unit.h"
#include "MagicAttack.h"
#include "Spellbook.h"

class PhysAttack;

class SpellCaster : public Unit
{
public:
	SpellCaster();
	SpellCaster(State& state, MagicAttack & magAttack, Spellbook& book);
	~SpellCaster();

	Spellbook* readBook();

	virtual void magicAttack(Unit& attacked, Spells spell) = 0;

private:

	Spellbook* book;

};
