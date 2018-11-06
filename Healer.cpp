#include "stdafx.h"
#include "Healer.h"
#include "RegenerateHpSpell.h"
#include "RegenerateManaSpell.h"
#include "AttackSpell.h"
#include "Vampire.h"
#include "Necromancer.h"



Healer::Healer() : SpellCaster(*(new State("Healer", HEALTH_POINTS_HEALER, PHYS_DAMAGE_HEALER, MANA_HEALER, 0.5)), *(new MagicAttack()), *(new Spellbook())) {}

Healer::Healer(State & state, MagicAttack & magAttack, Spellbook & book) : SpellCaster(state, magAttack, book) {}

Healer::~Healer() {}

void Healer::physicAttack(Unit & attacked)
{
	this->getAttack().attack(*this, attacked);
	attacked.getAttack().counterAttack(*this, attacked);
}

void Healer::magicAttack(Unit & attacked, Spells spellNumber)
{
	Spell& spell = readBook()->getSpell(spellNumber);

	MagicAttack& magAttack = dynamic_cast<MagicAttack&>(getAttack());

	if (typeid(spell) == typeid(AttackSpell())) {
		spell.setPower(spell.getPower() / 2);

		magAttack.attack(*this, attacked, spell);
		attacked.getAttack().counterAttack(*this, attacked);

		return;
	}
	
	if (typeid(attacked) == typeid(Vampire) || typeid(attacked) == typeid(Necromancer)) {
		magAttack.attack(*this, attacked, spell);
		attacked.getAttack().counterAttack(*this, attacked);

		return;
	}

	magAttack.attack(*this, attacked, spell);
}
