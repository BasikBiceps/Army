#pragma once

#include <map>
#include "Spell.h"
#include "SpellEnum.h"

class Spellbook
{
public:
	Spellbook();
	~Spellbook();
	
	Spell& addSpell(Spell& spell, Spells key);
	void removeSpell(Spells key);
	Spell& getSpell(Spells key);

private:

	std::map<Spells, Spell&> list;
};

