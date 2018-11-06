#pragma once
#include "Spell.h"

enum {
	ATTACK_NEED_MANA = 20,
	ATTACK_POWER = 30
};

class AttackSpell :
	public Spell
{
public:
	AttackSpell();
	AttackSpell(int needMana, int power);
	~AttackSpell();

	void cast(Unit& unit) override;
};

