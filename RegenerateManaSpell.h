#pragma once
#include "Spell.h"

enum {
	REGENERATE_MANA_NEED_MANA = 20,
	REGENERATE_MANA_POWER = 30
};

class RegenerateManaSpell :
	public Spell
{
public:
	RegenerateManaSpell();
	RegenerateManaSpell(int needMana, int power);
	~RegenerateManaSpell();

	void cast(Unit& unit) override;
};


