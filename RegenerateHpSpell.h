#pragma once
#include "Spell.h"

enum {
	REGENERATE_HP_NEED_MANA = 20,
	REGENERATE_HP_POWER = 30
};

class RegenerateHpSpell :
	public Spell
{
public:
	RegenerateHpSpell();
	RegenerateHpSpell(int needMana, int power);
	~RegenerateHpSpell();

	void cast(Unit& unit) override;
};
